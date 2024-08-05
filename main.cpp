/**
 * @file main.cpp
 * @author Chilukamari Shiva Sai Krishna (mcs232499@cse.iitd.ac.in)
 * @brief Main program to Convert Markdown file to HTML file
 * @version 0.1
 * @date 2023-08-27
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifdef __cplusplus
extern "C"
{
#endif

#include <cstdio>
#include "log.h"
#include "parsor.tab.h"

extern "C" FILE *yyin;
extern "C" int yylex();
int yyparse(FILE *fp);

/**
 * @brief Main origin funtion
 *
 * @param argc Number of input arguments
 * @param argv Array of arguments
 * @return int 
 */
int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		DEBUG_LOG(printf("Running Lexer on %s\n", argv[1]);)
		yyin = fopen(argv[1], "r");
	}
	
	DEBUG_LOG(printf("\n\nStart Lexer\n\n");)

	FILE *fout;
	if (argc > 2)
	{
		fout = fopen(argv[2], "w");
	}
	else
	{
		fout = fopen("result.html", "w");
	}

	if (fout != NULL)
	{
		yyparse(fout);
		fclose(fout);
	}

	DEBUG_LOG(printf("\n\nEnd Lexer\n\n");)
	return 0;
}

#ifdef __cplusplus
}
#endif