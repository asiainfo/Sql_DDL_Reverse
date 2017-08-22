// cancelDdl.cpp : Defines the entry point for the console application.
//
#include "gen_sql.h"
#include "sql.tab.h"
void printUsage(char *s)
{
	printf("Usage:\n\t%s ddl_file out_file\n", s);
}

int genReverseDDL(const char* file) 
{
	FILE* fp = fopen(file, "wt");
	if ( fp == NULL )
	{
		printf("can not open file:%s\n", file);
		return -1;
	}

	string reverseSql = g_genReverseSql.gen_reverseDDL();
	fputs(reverseSql.c_str(), fp);
	fclose(fp);
	return 0;
}

extern int yyparse();
int main(int argc, char* argv[])
{
	if ( argc < 3 )
	{
		printUsage(argv[0]);
		return -1;
	}

	if ( !g_genReverseSql.open_file(argv[1]) )
		return -1;
	yyparse();
	//g_genReverseSql.debug();
	g_genReverseSql.close_file();
	if ( g_genReverseSql.get_errCount() > 0 ) 
	{
		g_genReverseSql.print_errMsg();
		return -1;
	}

	if ( genReverseDDL(argv[2]) < 0 )
		return -1;
	
	printf("Parse file: %s finished.\nTotal %d reverse sql generated.\n",
		argv[1], g_genReverseSql.get_sqlCount());
	return 0;
}

	
