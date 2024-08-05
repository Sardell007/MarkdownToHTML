/**
 * @file lexer.l
 * @author Chilukamari Shiva Sai Krishna (mcs232499@cse.iitd.ac.in)
 * @brief Lexical analyser to generate tokens to be parsered to Parser
 * @version 0.1
 * @date 2023-08-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */
%{
    #include <string>
    #include "log.h"
    #include "parsor.tab.h"

    #define YY_DECL extern "C" int yylex()
%}

%option noyywrap


/**
 * @brief Lexical Tokens Generation Rules
 * 
 */

%%

#+" "                  { DEBUG_LOG(printf("lex Head %d\n", yyleng - 1);) yylval.num = yyleng - 1; return HEADING;}

^=+$                   { DEBUG_LOG(printf("lex Prev Head1 %d\n", 1);) yylval.num = 1; return PREV_HEADING;}
^-+$                   { DEBUG_LOG(printf("lex Prev Head2 %d\n", 2);) yylval.num = 2; return PREV_HEADING;}

"!["                   { DEBUG_LOG(printf("lex Exclamation \n");) return EXCLAMEBRAK;}

"["|"]"                { DEBUG_LOG(printf("lex Brakets %s\n", yytext);) yylval.sym = yytext[0];return BRACKET;}

"("|")"                { DEBUG_LOG(printf("lex Paranthesis %s\n", yytext);) yylval.sym = yytext[0];return PARANTHESIS;}

^(" "*-){3,}" "*$      { DEBUG_LOG(printf("lex Horizontal Rule -\n");) yylval.sym = '-'; return HORIZONTAL_RULE;}
^(" "*\*){3,}" "*$     { DEBUG_LOG(printf("lex Horizontal Rule *\n");) yylval.sym = '*'; return HORIZONTAL_RULE;}
^(" "*_){3,}" "*$      { DEBUG_LOG(printf("lex Horizontal Rule _\n");) yylval.sym = '_'; return HORIZONTAL_RULE;}

-" "                   { DEBUG_LOG(printf("lex Unorder List -\n");) yylval.sym = '-'; return UNORDERED_LIST;}
\*" "                  { DEBUG_LOG(printf("lex Unorder List *\n");) yylval.sym = '*'; return UNORDERED_LIST;}
\+" "                  { DEBUG_LOG(printf("lex Unorder List +\n");) yylval.sym = '+'; return UNORDERED_LIST;}

\*{3}                  { DEBUG_LOG(printf("lex EMPHSTRONG *\n");) yylval.sym = '*'; return EMPHSTR;}
\_{3}                  { DEBUG_LOG(printf("lex EMPHSTRONG _\n");) yylval.sym = '*'; return EMPHSTR;}

\*{2}                  { DEBUG_LOG(printf("lex STRONG *\n");) yylval.sym = '*'; return STRONG;}
\_{2}                  { DEBUG_LOG(printf("lex STRONG _\n");) yylval.sym = '*'; return STRONG;}

\*                     { DEBUG_LOG(printf("lex EMPH *\n");) yylval.sym = '*'; return EMPHASIS;}
\_                     { DEBUG_LOG(printf("lex EMPH _\n");) yylval.sym = '*'; return EMPHASIS;}

^[0-9]+." "            { yylval.num = std::stoi(std::string(yytext, yyleng-2)); DEBUG_LOG(printf("lex Ordered List \'%s\' %d\n", std::string(yytext, yyleng-2).c_str(), yylval.num);) return ORDERED_LIST;}

" "{2,}\n              { DEBUG_LOG(printf("lex Line Break %d\n", yyleng);) yylval.num = yyleng; return LINE_BRAKE;}

"|"                    { DEBUG_LOG(printf("lex Verticle Bar \n");) return VERTICLE_BAR;}
"-"{3,}                { DEBUG_LOG(printf("lex Horizontal Bar \n");) return HORIZONTAL_BAR;}

" "+                   { DEBUG_LOG(printf("lex Spaces %d\n", yyleng);) yylval.num = yyleng; return SPACE;}

[0-9a-zA-Z/.:-]        { DEBUG_LOG(printf("lex Text '%s' %d  ", yytext, yyleng);) yylval.sym = yytext[0]; return TEXT;}

\n{2,}|(\r\n){2,}      { DEBUG_LOG(printf("lex Endline 2\n");) return END_LINE;}

\n|\r\n                { DEBUG_LOG(printf("lex Endline Single 1\n");) return END_LINE_S;}

.                      { DEBUG_LOG(printf("lex Something Else \"%s\"\n", yytext);) yylval.str = yytext; return UNKNOWN;}

<<EOF>>                { DEBUG_LOG(printf("lex EOF\n");) return E_O_F;}

%%