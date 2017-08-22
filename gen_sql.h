//---------------------------------------------------------------------------

#ifndef gen_sqlH
#define gen_sqlH
//---------------------------------------------------------------------------

#include <string>
#include <map>
#include <vector>
#include <stdio.h>

using namespace std;

enum ESqlItemType
{
	ESQL_TABLE,
	ESQL_VIEW,
	ESQL_TABLESPACE,
	ESQL_INDEX,
	ESQL_KEY,
	ESQL_PK,
	ESQL_FK,
	ESQL_CONSTRAINT,
	ESQL_PARTITION,
	ESQL_COLUMN
};

enum ESqlItemCmd
{
	ECREATE,
	EALTER,
	EADD,
	ECHANGE,
	ELOCK,
	EMODIFY,
	EDROP,
	EDISABLE,
	EENABLE,
	ERENAME,
	EDISCARD,
	EREMOVE
};


class SqlItem {
public:
	typedef vector<SqlItem*> SqlItemList;
private:
	string m_sName;
	SqlItem* m_parent;
	int m_iType;
	int m_iCmd;
	SqlItemList m_childList;

	void print(const SqlItem* pItem, int len) const;
public:
	SqlItem(const string& name, int type) : 
	  m_sName(name), m_parent(NULL), m_iType(type),
	  m_iCmd(-1)
	{
		
	}

	SqlItem(const string& name) : 
	m_sName(name), m_parent(NULL), m_iType(-1),
		m_iCmd(-1)
	{

	}

	SqlItem():
	m_sName(""), m_parent(NULL), m_iType(-1),
		m_iCmd(-1)
	{}

	~SqlItem();

	string get_originalCmdStr(int cmd) const;
	string get_itemTypeName(int type) const;

	void print() const;
	void set_cmd(int cmd) {
		m_iCmd = cmd;
	}

	void set_name(const string& name) {
		m_sName = name;
	}

	void set_type(int type) {
		m_iType = type;
	}

	void set_childInfo(int cmd, int type) {
		for(SqlItemList::iterator it = m_childList.begin(); it != m_childList.end(); it++ ) {
			(*it)->set_cmd(cmd);
			(*it)->set_type(type);
		}
	}

	const string get_name() const{
		return m_sName;
	}

	int get_type() const{
		return m_iType;
	}

	int get_cmd() const{
		return m_iCmd;
	}

	SqlItemList get_child() const{
		return m_childList;
	}

	void add_child(SqlItem* pItem) {
		if ( pItem == NULL )
			return;
		m_childList.push_back(pItem);
	}

	void add_childList(SqlItem* pItem) {
		if ( pItem == NULL )
			return;
		SqlItemList list = pItem->get_child();
		for(SqlItemList::iterator it = list.begin();
			it != list.end(); it++ ) {
				m_childList.push_back(*it);
		}
	}

	void set_parent(SqlItem* pItem) {
		if ( pItem == NULL )
			return;
		m_parent = pItem;
	}

	SqlItem* get_parent() const {
		return m_parent;
	}

};

class SqlItemCreator 
{
private:
	typedef map<SqlItem*, bool> SqlItemMap;
	SqlItemMap m_itemMap;

public:
	SqlItemCreator() 
	{
	}

	~SqlItemCreator()
	{
		/*if ( m_itemMap.size() == 0 )
			return;*/
		for ( SqlItemMap::iterator it = m_itemMap.begin();
			it != m_itemMap.end(); it++ ) 
		{
			it->second = false;
			delete it->first;
		}

		m_itemMap.clear();
	}

	void clear()
	{
		for ( SqlItemMap::iterator it = m_itemMap.begin();
			it != m_itemMap.end();) 
		{
			if ( !it->second ) {
				delete it->first;
				m_itemMap.erase(it++);
			} else {
				it ++;
			}
		}
	}

	SqlItem* newItem() 
	{
		SqlItem* item = new SqlItem();
		m_itemMap[item] = false;
		
		return item;
	}

	SqlItem* newItem(const string& name, int type)
	{
		SqlItem* item = new SqlItem(name, type);
		m_itemMap[item] = false;
		return item;
	}

	SqlItem* newItem(const string& name)
	{
		SqlItem* item = new SqlItem(name);
		m_itemMap[item] = false;
		return item;
	}

	void reserveItem( SqlItem* item )
	{
		SqlItemMap::iterator it = m_itemMap.find(item);
		if ( it == m_itemMap.end() )
			return;
		it->second = true;

		reserveItem(item->get_parent());
		SqlItem::SqlItemList itemList = item->get_child();
		for ( SqlItem::SqlItemList::iterator it = itemList.begin(); 
			it != itemList.end(); it++ )
		{
			reserveItem(*it);
		}
	}

	bool isReserve(SqlItem* item)
	{
		/*if ( m_itemMap.size() == 0 )
			return false;*/
		SqlItemMap::iterator it = m_itemMap.find(item);
		if ( it == m_itemMap.end() )
			return false;
		return it->second;
	}
};

extern SqlItemCreator g_itemCreator;

class CLexProcessState
{
private:
	FILE*           m_fp;                   // current processing file
	int             m_iCurrColNo;           // current column number
	int             m_iFileNo;              // current file no
	int             m_iLastColNo;           // last column number
	int             m_iLineNo;              // line number
	string			m_strFilename;			// filename
	void*           m_pBufferState;         // buffer state

public:
	CLexProcessState();

	void*   get_bufferState()   const;
	int     get_currColNo()     const;
	int     get_fileNo()        const;
	int     get_lastColNo()     const;
	int     get_lineNo()        const;
	FILE*   get_fp()            const;
	string  get_filename()      const;

	void    set_bufferState(void* pBufferState);
	void    set_filename(const char* szFilename);
	void    set_fileNo(const int iFileNo);
	void    set_fp(FILE* fp);

	void    inc_columnNo(const int iCount);
	void    inc_lineNo(const int iCount);
};

class CGenReverseSql
{
private:
	vector<string>				    m_lstErrorMsg;
	SqlItem::SqlItemList			m_itemList;
	CLexProcessState				m_lexState;

	void	debug_item(const SqlItem& item, int indent);
	void    gen_item(const SqlItem& item, const char* tail, int indent, string& output);
	void    gen_forCreateIdx(const SqlItem& item, int indent, string& output);

public:	
	CGenReverseSql()  {}
	~CGenReverseSql();
	void    clear();

	bool    open_file(const char* filename);
	void	close_file();
	void    add_errorMsg(const char* szErrorMsg);
	void	add_item(SqlItem* item);
	string  get_reverseCmdStr(int cmd);
	
	
	void    debug();


	void*   get_bufferState()   const { return m_lexState.get_bufferState(); }
	int     get_currColNo()     const { return m_lexState.get_currColNo(); }
	int     get_fileNo()        const { return m_lexState.get_fileNo(); }
	int     get_lastColNo()     const { return m_lexState.get_lastColNo(); }
	int     get_lineNo()        const { return m_lexState.get_lineNo(); }
	FILE*   get_fp()            const { return m_lexState.get_fp(); }
	string  get_filename()      const { return m_lexState.get_filename(); }

	void    set_bufferState(void* pBufferState)  
	        { 
				m_lexState.set_bufferState(pBufferState); 
	        }
	void    set_filename(const char* szFilename) 
	        { 
				m_lexState.set_filename(szFilename); 
	        }
	void    set_fileNo(const int iFileNo)
	        { 
				m_lexState.set_fileNo(iFileNo); 
	        }
	void    set_fp(FILE* fp)
	        { 
				m_lexState.set_fp(fp); 
	        }

	void    inc_columnNo(const int iCount)
	        { 
				m_lexState.inc_columnNo(iCount); 
	        }
	void    inc_lineNo(const int iCount)
	        { 
				m_lexState.inc_lineNo(iCount); 
	        }

	string  gen_reverseDDL();
	void    print_errMsg();
	int     get_errCount() { return m_lstErrorMsg.size(); }
	int     get_sqlCount() { return m_itemList.size(); }

};
extern CGenReverseSql g_genReverseSql;
extern string build_str(const char * szFormat, ...);

#endif
