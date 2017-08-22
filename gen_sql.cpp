#include <stdio.h>
#include <stdlib.h>

#include <stdarg.h>
#include "gen_sql.h"
CGenReverseSql g_genReverseSql;
SqlItemCreator g_itemCreator;

string build_str(const char * szFormat, ...)
{
	char buf[1024];
	va_list args;
	va_start(args, szFormat);
	vsnprintf(buf, sizeof(buf), szFormat, args);
	buf[sizeof(buf) - 1] = 0;
	va_end(args);
	return string(buf);
}

SqlItem::~SqlItem() {
	
	// child and parent will delete by SqlItemCreator
	m_childList.clear();
}

string SqlItem::get_originalCmdStr(int cmd) const
{
	string cmd_str[] = {
		"CREATE",
		"ALTER",
		"ADD",
		"CHANGE",
		"LOCK",
		"MODIFY",
		"DROP",
		"DISABLE",
		"ENABLE",
		"RENAME",
		"DISCARD",
		"REMOVE"
	};
	if ( cmd >= sizeof(cmd_str) || cmd < 0 )
		return "invalid command";
	else
		return cmd_str[cmd];

}

string SqlItem::get_itemTypeName(int type) const
{
	string type_name[] = {
		"TABLE",
		"VIEW",
		"TABLESPACE",
		"INDEX",
		"KEY",
		"PRIMARY KEY",
		"FOREIGN KEY",
		"CONSTRAINT",
		"PARTITION",
		"COLUMN"
	};
	if ( type >= sizeof(type_name) || type < 0 )
		return "invalid item type";
	else
		return type_name[type];
}

void SqlItem::print(const SqlItem* item, int indent) const
{
	int len = indent;
	string space(len, ' ');
	printf("%s name=%s, type=%s, cmd=%s\n",
		space.c_str(),
		item->get_name().c_str(),
		get_itemTypeName(item->get_type()).c_str(),
		get_originalCmdStr(item->get_cmd()).c_str()
		);
	printf("%s{\n",space.c_str());
	len += 4;
    SqlItemList childList = item->get_child();
	for ( vector<SqlItem>::size_type i = 0; i < childList.size(); i++ ) {
		print(childList[i], len);
	}
	printf("%s}\n", space.c_str());
}

void SqlItem::print() const {
	print(this,0);
}

CLexProcessState::CLexProcessState() :
m_fp(NULL),
m_iCurrColNo(0),
m_iFileNo(0),
m_iLastColNo(0),
m_iLineNo(0),
m_pBufferState(0)
{
}

void* CLexProcessState::get_bufferState() const
{
	return m_pBufferState;
}

int CLexProcessState::get_currColNo() const
{
	return m_iCurrColNo;
}

string CLexProcessState::get_filename() const
{
	return m_strFilename;
}

int CLexProcessState::get_fileNo() const
{
	return m_iFileNo;
}

FILE* CLexProcessState::get_fp() const
{
	return m_fp;
}

int CLexProcessState::get_lastColNo() const
{
	return m_iLastColNo;
}

int CLexProcessState::get_lineNo() const
{
	return m_iLineNo;
}

void CLexProcessState::inc_columnNo(const int iCount)
{
	m_iLastColNo = m_iCurrColNo;
	m_iCurrColNo += iCount;
}

void CLexProcessState::inc_lineNo(const int iCount)
{
	++m_iLineNo;
	m_iLastColNo = 0;
	m_iCurrColNo = 1;
}

void CLexProcessState::set_bufferState(void* pBufferState)
{
	m_pBufferState = pBufferState;
}

void CLexProcessState::set_filename(const char* szFilename)
{
	m_strFilename = szFilename;
}

void CLexProcessState::set_fileNo(const int iFileNo)
{
	m_iFileNo = iFileNo;
}

void CLexProcessState::set_fp(FILE* fp)
{
	m_fp = fp;
	m_iLineNo = m_iCurrColNo = 1;
	m_iLastColNo = 0;
}

//---------------------------------------------------------------------------
CGenReverseSql::~CGenReverseSql() {
	clear();
}

void CGenReverseSql::clear() {
	/*for(SqlItem::SqlItemList::iterator it = m_itemList.begin(); 
		it != m_itemList.end(); it++) {
			delete *it;
	}*/
	m_itemList.clear();
}

bool CGenReverseSql::open_file(const char* filename) 
{
	extern void lex_prepareBuffer(CLexProcessState&);
	FILE* fp = stdin;
	

	if ( filename != NULL )
	{
		fp = fopen(filename, "rt");
		if ( fp == NULL ) {
			printf("can not open file:%s\n", filename);
			return false;
		}
		m_lexState.set_filename(filename);
//		g_pCurrParser->on_newFile(filename);
	}
	else m_lexState.set_filename("STDIN");

//	m_lexState.set_fileNo(m_cFileNoMgr.add_file(cLexState.get_filename().c_str()));

	m_lexState.set_fp(fp);
	lex_prepareBuffer(m_lexState);

	return true;
}

void CGenReverseSql::close_file() 
{
	extern void lex_destroyBuffer(CLexProcessState&);
	FILE* fp = m_lexState.get_fp();
	if ( fp != stdin )
		fclose(fp);

	lex_destroyBuffer(m_lexState);
}

void CGenReverseSql::add_errorMsg(const char* szErrorMsg)
{
	string errMsg = szErrorMsg;
	m_lstErrorMsg.push_back(errMsg);
}



void CGenReverseSql::add_item(SqlItem* item)
{
	m_itemList.push_back(item);
	g_itemCreator.reserveItem(item);
}

string CGenReverseSql::get_reverseCmdStr(int cmd)
{

	string cmd_str[] = {
		"DROP",		    //ECREATE,
		"ALTER",	    //EALTER,
		"DROP",		    //EADD,
		"CHANGE",	    //ECHANGE,
		"NOT ALLOW",	//ELOCK,	
		"NOT ALLOW",	//EMODIFY,
		"NOT ALLOW",	//EDROP,
		"ENABLE",	    //EDISABLE,
		"DISABLE",	    //EENABLE,
		"NOT ALLOW",	//ERENAME,
		"NOT ALLOW",	//EDISCARD,
		"NOT ALLOW"	    //EREMOVE
	};
	if ( cmd >= sizeof(cmd_str) || cmd < 0 )
		return "invalid command";
	else
		return cmd_str[cmd];
}


void CGenReverseSql::debug_item(const SqlItem& item, int indent) 
{
	int len = indent;
	string space(len, ' ');
	printf("%s %s %s %s \n",
		space.c_str(),
		item.get_originalCmdStr(item.get_cmd()).c_str(),
		item.get_itemTypeName(item.get_type()).c_str(),
		item.get_name().size() == 0 ? "" : item.get_name().c_str()
		);
	len += 4;
	SqlItem::SqlItemList childList = item.get_child();
	for ( vector<SqlItem>::size_type i = 0; i < childList.size(); i++ ) {
		debug_item(*childList[i], len);
	}
}

void CGenReverseSql::debug()
{
	for ( vector<SqlItem>::size_type i = 0; i < m_itemList.size(); i++)
	{
		debug_item(*m_itemList[i], 0);
		printf("\n\n");
	}
}

void CGenReverseSql::gen_forCreateIdx(const SqlItem& item, int indent, string& output)
{
    SqlItem* parent = item.get_parent();
	if ( parent == NULL )
	{
		printf("create index not found table name\n");
		return;
	}

	string space1(indent, ' ');
	string space2(indent + 4, ' ');
	char buf[2048];
#ifdef _MSC_VER
	_snprintf(buf, sizeof(buf), "%sALTER TABLE %s\n%s %s %s %s\n",
#else
	 snprintf(buf, sizeof(buf), "%sALTER TABLE %s\n%s %s %s %s\n",
#endif
		 space1.c_str(),
		 parent->get_name().c_str(),
		 space2.c_str(),
		 get_reverseCmdStr(item.get_cmd()).c_str(),
		 item.get_itemTypeName(item.get_type()).c_str(),
		 item.get_name().size() == 0 ? "" : item.get_name().c_str()
		 );
	 buf[sizeof(buf)-1] = 0;
	 output += buf;
}

void CGenReverseSql::gen_item(const SqlItem& item, 
							  const char* tail, 
							  int indent, 
							  string& output)
{
	if ( item.get_cmd() == ECREATE && 
		item.get_type() == ESQL_INDEX ) 
	{
		gen_forCreateIdx(item, indent, output);
		return;
	}

	int len = indent;
	string space(len, ' ');
	char buf[2048];
#ifdef _MSC_VER
	_snprintf(buf, sizeof(buf), "%s%s %s %s%s",
#else
	snprintf(buf, sizeof(buf), "%s%s %s %s%s",
#endif
		space.c_str(),
		get_reverseCmdStr(item.get_cmd()).c_str(),
		item.get_itemTypeName(item.get_type()).c_str(),
		item.get_name().size() == 0 ? "" : item.get_name().c_str(),
		tail
		);
    buf[sizeof(buf)-1] = 0;
	output += buf;
	len += 4;
	SqlItem::SqlItemList childList = item.get_child();
    vector<SqlItem>::size_type size = childList.size();
	for ( vector<SqlItem>::size_type i = 0; i < size; i++ ) {
		if ( i != (size-1) )
			gen_item(*childList[i], ",\n", len, output);
		else
			gen_item(*childList[i], "\n", len, output);
		
	}
	
}

string CGenReverseSql::gen_reverseDDL()
{
	string output;
	for ( vector<SqlItem>::size_type i = 0; i < m_itemList.size(); i++)
	{
		gen_item(*m_itemList[i], "\n", 0, output);
		output += ";\n";
	}
	return output;
}

void CGenReverseSql::print_errMsg() 
{
	printf("%s has errors.\n", get_filename().c_str());
	for(vector<string>::iterator it = m_lstErrorMsg.begin();
		it != m_lstErrorMsg.end(); ++it )
	{
		printf("%s", it->c_str());
	}
	printf("Total %d errors.\n", m_lstErrorMsg.size());
}