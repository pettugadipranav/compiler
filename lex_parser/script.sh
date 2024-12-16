#! /bin/bash
flex lexer.l
yacc parser.y -d -v
gcc y.tab.c -ll 2> error.log  # Redirect stderr to error.log
./a.out < "$1" > "log.txt"
echo "Syntactically correct!"
