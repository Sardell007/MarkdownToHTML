all: output unittest

parsor.tab.c: parsor.y Node.hpp log.h
		bison -d -t parsor.y

parsor.tab.h: parsor.y Node.hpp log.h
		bison -d -t parsor.y

lex.yy.c: lexer.l parsor.tab.h log.h
		flex lexer.l

output: main.cpp parsor.tab.c parsor.tab.h lex.yy.c log.h
		g++ -Wno-register main.cpp parsor.tab.c lex.yy.c -o output

unittest: unittest.cpp parsor.tab.c parsor.tab.h lex.yy.c util.h log.h
		g++ -Os -g -Wno-register unittest.cpp parsor.tab.c lex.yy.c -o unittest -lgtest

clean:
		rm lex.yy.c parsor.tab.c parsor.tab.h output unittest