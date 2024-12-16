lex : lexer.l
	flex lexer.l
	mv lex.yy.c lex.yy.cpp
parse : lex
	bison -d parser.y
	mv parser.tab.c parser.tab.cpp
	sed -i -e 's/parser.tab.c/parser.tab.cpp/g' parser.tab.cpp
	sed -i -e 's/parser.tab.h/parser.tab.hpp/g' parser.tab.cpp
	mv parser.tab.h parser.tab.hpp
compile : parse 
	g++ lex.yy.cpp parser.tab.cpp  sym_table.cpp
test : compile
	./current.sh 
run : compile
	./testcases/script.sh
clean : 
	rm *.out
	rm -r ./logs
