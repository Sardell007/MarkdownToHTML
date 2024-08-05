/**
 * @file parsor.y
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */
%{
    #include <cstdio>
    #include "Node.hpp"

    extern "C" FILE *yyin;
    extern "C" int yyparse(FILE* fp);
    extern "C" int yylex();

    void yyerror(FILE* fp, const char* msg);
%}

%parse-param { FILE* fp }

%union {
    int num;
    char sym;
    char* str;
    struct MNode* node;
}

%token ORDERED_LIST_START EXCLAMEBRAK VERTICLE_BAR HORIZONTAL_BAR END_LINE E_O_F END_LINE_S
%token<num> HEADING PREV_HEADING LINE_BRAKE ORDERED_LIST SPACE
%token<sym> BRACKET PARANTHESIS HORIZONTAL_RULE UNORDERED_LIST EMPHSTR STRONG EMPHASIS TEXT
%token<str> UNKNOWN

%type<node> doc line heading para orderedlist unorderedlist table
%type<node> orderedlistitem unorderedlistitem singletableentry tableentry
%type<node> text image hyperlink
%type<node> textspaceunknown textspaceunknownimagehyperlink alttext imagepath leftrightentry rightentry rightwholeentry horizontal_entry textend2space simpletext  

%start file

%%

file: doc E_O_F {
                    DEBUG_LOG(printf("File E_O_F\n");)
                    struct MNode* n = $1; 
                    DEBUG_LOG(printf("\n\n----------------------\n\n");) 
                    DEBUG_LOG(printTree(n);)
                    DEBUG_LOG(printf("\n\n----------------------\n\n");)
                    struct HNode* htmlNode = convert(n);
                    DEBUG_LOG(printf("\n\n----------------------\n\n");)
                    DEBUG_LOG(printTree(htmlNode);)
                    DEBUG_LOG(printf("\n\n----------------------\n\n");)
                    printHTMLFile(htmlNode, fp);
                    return 1;
                }

doc: line       { DEBUG_LOG(printf("doc 1\n");) $$ = createMNode(M_DOC, {$1}); }
    | doc line  { DEBUG_LOG(printf("doc 2\n");) $$ = createMNode(M_DOC, {$1, $2});} 

line: heading       { DEBUG_LOG(printf("line 1\n");) $$ = createMNode(M_LINE, {$1}); }
    | para          { DEBUG_LOG(printf("line 2\n");) $$ = createMNode(M_LINE, {$1}); }
    | orderedlist   { DEBUG_LOG(printf("line 3\n");) $$ = createMNode(M_LINE, {$1}); }
    | unorderedlist { DEBUG_LOG(printf("line 4\n");) $$ = createMNode(M_LINE, {$1}); }
    | table         { DEBUG_LOG(printf("line 6\n");) $$ = createMNode(M_LINE, {$1}); }
    | endline       { DEBUG_LOG(printf("line 8\n");)  $$ = createMNode(M_LINE, {}); }

heading: HEADING text endline              { DEBUG_LOG(printf("heading 1\n");) $$ = createMNode(M_HEAD, {$2}, $1); }
    | text END_LINE_S PREV_HEADING endline { DEBUG_LOG(printf("heading 2\n");) $$ = createMNode(M_HEAD, {$1}, $3); }

orderedlist: orderedlistitem { DEBUG_LOG(printf("orderedlist 1\n");) $$ = createMNode(M_ORD_LIST, {$1}); }

orderedlistitem: ORDERED_LIST text endline      { DEBUG_LOG(printf("orderedlistitem 1\n");) $$ = createMNode(M_ORD_LIST_ITEM, {$2}); }
    | orderedlistitem ORDERED_LIST text endline { $$ = createMNode(M_ORD_LIST_ITEM, {$1, $3}); }

unorderedlist: unorderedlistitem      { DEBUG_LOG(printf("unorderedlist 1\n");) struct MNode* n = $1; $$ = createMNode(M_UNORDER_LIST, {n}, -1, n->sym); }
    | unorderedlist unorderedlistitem {
                                        DEBUG_LOG(printf("unorderedlist 2\n");) struct MNode* np = $1;
                                        struct MNode* n = $2;
                                        if(np->sym == n->sym) $$ = createMNode(M_UNORDER_LIST, {$1, $2}, -1, n->sym);
                                        else $$ = createMNode(M_UNORDER_LIST, {$1, createMNode(M_UNORDER_LIST, {$2}, -1, n->sym)}, -1, n->sym);
                                      }

unorderedlistitem: UNORDERED_LIST text endline { DEBUG_LOG(printf("unorderedlistitem 1\n");) $$ = createMNode(M_UNORDER_LIST_ITEM, {$2}, -1, $1); }

image: alttext imagepath { DEBUG_LOG(printf("image 1\n");) $$ = createMNode(M_IMG, {$1,$2}); }

alttext: EXCLAMEBRAK textend2space BRACKET { DEBUG_LOG(printf("alttext 1\n");) $$ = createMNode(M_ALTTEXT, {$2}); }

imagepath: PARANTHESIS simpletext SPACE text PARANTHESIS { DEBUG_LOG(printf("imagepath 2\n");) std::string imgp = $2->text; $$ = createMNode(M_IMGPATH, {createMNode(M_IMGPATH, {}, -1, '\n', imgp), $4}); }
    | PARANTHESIS simpletext PARANTHESIS                       { DEBUG_LOG(printf("imagepath 1\n");) std::string imgp = $2->text; $$ = createMNode(M_IMGPATH, {}, -1, '\n',  imgp); }

table: singletableentry END_LINE_S horizontal_entry END_LINE_S tableentry { DEBUG_LOG(printf("table 1\n");) struct MNode* n = $3; $$ = createMNode(M_TABLE, {$1, $5}, n->num); }

singletableentry: rightwholeentry { DEBUG_LOG(printf("singletableentry 1\n");) struct MNode* n = $1; $$ = createMNode(M_TABLE_SINGLE, {n}, n->num); }
    | rightwholeentry SPACE text  { DEBUG_LOG(printf("singletableentry 2\n");)  struct MNode* n = $1; $$ = createMNode(M_TABLE_SINGLE, {n, $3}, n->num+1); }

leftrightentry: VERTICLE_BAR SPACE text SPACE VERTICLE_BAR {DEBUG_LOG(printf("leftrightentry 1\n");) $$ = createMNode(M_TABLE_LR_ENTRY, {$3}, 1); }

rightentry: text SPACE VERTICLE_BAR { DEBUG_LOG(printf("rightentry 1\n");) $$ = createMNode(M_TABLE_R_ENTRY, {$1}, 1); }

rightwholeentry: leftrightentry            { DEBUG_LOG(printf("rightwholeentry 1\n");) struct MNode* n = $1; $$ = createMNode(M_TABLE_RW_ENTRY, {n}, n->num); }
    | rightwholeentry SPACE leftrightentry { DEBUG_LOG(printf("rightwholeentry 3\n");) struct MNode* nr = $1; struct MNode* nl = $3; $$ = createMNode(M_TABLE_RW_ENTRY, {nr,nl}, nr->num + nl->num); }
    | rightwholeentry SPACE rightentry     { DEBUG_LOG(printf("rightwholeentry 4\n");) struct MNode* nr = $1; struct MNode* nl = $3; $$ = createMNode(M_TABLE_RW_ENTRY, {nr,nl}, nr->num + nl->num); }

tableentry: singletableentry endline      { DEBUG_LOG(printf("tableentry 1\n");) struct MNode* n = $1; $$ = createMNode(M_TABLE_ENTRY, {n}, n->num); }
    | tableentry singletableentry endline { DEBUG_LOG(printf("tableentry 2\n");) struct MNode* nt = $1; struct MNode* ns = $2; $$ = createMNode(M_TABLE_ENTRY, {nt,ns}, nt->num + ns->num); }

horizontal_entry: VERTICLE_BAR SPACE HORIZONTAL_BAR SPACE VERTICLE_BAR { DEBUG_LOG(printf("horizontal_entry 1\n");) $$ = createMNode(M_TABLE_HORI, {}, 1); }
    | horizontal_entry SPACE HORIZONTAL_BAR SPACE VERTICLE_BAR         { DEBUG_LOG(printf("horizontal_entry 2\n");) struct MNode* n = $1; $$ = createMNode(M_TABLE_HORI, {n}, n->num+1); }

hyperlink: BRACKET text BRACKET imagepath { DEBUG_LOG(printf("hyperlink 1\n");) $$ = createMNode(M_HYPERLINK, {$2, $4}); }

textspaceunknown: simpletext { DEBUG_LOG(printf("textspaceunknown 1 %s\n", $1->text.c_str());) $$ = createMNode(M_TSU, {}, -1, '\n', $1->text);} 
    | SPACE                  { DEBUG_LOG(printf("textspaceunknown 2\n");) std::string str = ""; for(int i=0;i<$1;i++) str+=std::string(" "); $$ = createMNode(M_TSU, {}, -1, '\n', str); }
    | UNKNOWN                { DEBUG_LOG(printf("textspaceunknown 4\n");) $$ = createMNode(M_TSU, {}, -1, '\n', std::string($1)); }

simpletext: TEXT             { DEBUG_LOG(printf("Res lex1 %c - \n", $1);) std::string str(1, $1); $$ = createMNode(M_ST, {}, -1 , '\n', str); }
    | EMPHSTR    simpletext  { DEBUG_LOG(printf("Res lex3 %c - \n", $1);) const char* str1 = "<em><strong>";  std::string str =  std::string(str1) + $2->text;     DEBUG_LOG(printf("simpletext 3 '%s'\n", str.c_str());)  $$ = createMNode(M_ST, {}, -1 , '\n', str); }
    | STRONG     simpletext  { DEBUG_LOG(printf("Res lex4 %c - \n", $1);) const char* str1 = "<strong>";      std::string str =  std::string(str1) + $2->text;     DEBUG_LOG(printf("simpletext 4 '%s'\n", str.c_str());)  $$ = createMNode(M_ST, {}, -1 , '\n', str); }
    | EMPHASIS   simpletext  { DEBUG_LOG(printf("Res lex5 %c - \n", $1);) const char* str1 = "<em>";          std::string str =  std::string(str1) + $2->text;     DEBUG_LOG(printf("simpletext 5 '%s'\n", str.c_str());)  $$ = createMNode(M_ST, {}, -1 , '\n', str); }
    | simpletext EMPHSTR     { DEBUG_LOG(printf("Res lex6 %c - \n", $2);) const char* str1 = "</em></strong>";  std::string str =  $1->text + std::string(str1);     DEBUG_LOG(printf("simpletext 6 '%s'\n", str.c_str());)  $$ = createMNode(M_ST, {}, -1 , '\n', str); }
    | simpletext STRONG      { DEBUG_LOG(printf("Res lex7 %c - \n", $2);) const char* str1 = "</strong>";      std::string str =  $1->text + std::string(str1);     DEBUG_LOG(printf("simpletext 7 '%s'\n", str.c_str());)  $$ = createMNode(M_ST, {}, -1 , '\n', str); }
    | simpletext EMPHASIS    { DEBUG_LOG(printf("Res lex8 %c - \n", $2);) const char* str1 = "</em>";          std::string str =  $1->text + std::string(str1);     DEBUG_LOG(printf("simpletext 8 '%s'\n", str.c_str());)  $$ = createMNode(M_ST, {}, -1 , '\n', str); }
    | simpletext LINE_BRAKE  { DEBUG_LOG(printf("Res lex9 %c - \n", $2);) const char* str1 = "<br>";          std::string str =  $1->text + std::string(str1);     DEBUG_LOG(printf("simpletext 9 '%s'\n", str.c_str());)  $$ = createMNode(M_ST, {}, -1 , '\n', str); }
    | simpletext TEXT        { DEBUG_LOG(printf("Res lex10 %c - \n", $2);)  std::string str =  $1->text + std::string(1, $2);     DEBUG_LOG(printf("simpletext 10 '%s'\n",  str.c_str());) $$ = createMNode(M_ST, {}, -1 , '\n', str ); }

textspaceunknownimagehyperlink: textspaceunknown { DEBUG_LOG(printf("textspaceunknownimagehyperlink 1\n");) $$ = createMNode(M_TSUIH, {$1}); }
    | image                                      { DEBUG_LOG(printf("textspaceunknownimagehyperlink 2\n");) $$ = createMNode(M_TSUIH, {$1}); }
    | hyperlink                                  { DEBUG_LOG(printf("textspaceunknownimagehyperlink 3\n");) $$ = createMNode(M_TSUIH, {$1}); }

textend2space: textspaceunknown      { DEBUG_LOG(printf("textend2space 1\n");) $$ = createMNode(M_TE2S,{}, -1, '\n', $1->text); }
    | textend2space textspaceunknown { DEBUG_LOG(printf("textend2space 2\n");) $$ = createMNode(M_TE2S,{}, -1, '\n', $1->text + $2->text); }

text: textspaceunknownimagehyperlink      { DEBUG_LOG(printf("text 1\n");) $$ = createMNode(M_TEXT, {$1}); } 
    | text textspaceunknownimagehyperlink { DEBUG_LOG(printf("text 2 '%s'\n", $2->children.back()->text.c_str());) $$ = createMNode(M_TEXT, {$1, $2}); }

para: text endline { DEBUG_LOG(printf("para 1\n");) $$ = createMNode(M_PARA, {$1}, 1); }

endline:         { DEBUG_LOG(printf("endline 1\n");) }
    | END_LINE   { DEBUG_LOG(printf("endline 2\n");) }
    | END_LINE_S { DEBUG_LOG(printf("endline 3\n");) }

%%

/**
 * @brief Lexical Parsing Error Callback
 * 
 * @param fp File pointer erro message to be written into
 * @param msg Error message
 */
void yyerror(FILE* fp, const char* msg){
    printf("Parse ERROR %s\n", msg);
}