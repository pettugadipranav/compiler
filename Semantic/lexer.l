%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.hpp"
FILE *token_fp;
FILE *parsed_fp;
int l_no=1;
%}


/*Regular defintions*/
blanks (" ")+
letter [A-Za-z]
digit [0-9]
id {letter}({letter}|{digit}|"_")*
int_num {digit}+
ops [+*/]
double_num {digit}+(\.{digit}+)?
string \"(.*)+\"

%%
"//".* {/*To address comments*/}
"\n" {l_no++;fprintf(parsed_fp,"\n");}
{blanks} {fprintf(parsed_fp,"%s",yytext);}


".r++" {
    fprintf(token_fp,"reserved keyword: %s\n",yytext);
    return REAL_INC;
}
".i++" {
    fprintf(token_fp,"reserved keyword: %s\n",yytext);
    return IMAG_INC;
}
".r--" {
    fprintf(token_fp,"reserved keyword: %s\n",yytext);
    return REAL_INC;
}
".i--" {
    fprintf(token_fp,"reserved keyword: %s\n",yytext);
    return IMAG_INC;
}
"iter" {
    fprintf(token_fp,"reserved keyword: %s\n",yytext);
    return ITER;
}
"until" {
    fprintf(token_fp,"reserved keyword: %s\n",yytext);
    return UNTIL;
}
"return" {
    fprintf(token_fp,"reserved keyword: %s\n",yytext);
    return RETURN;
}
"void" {
    fprintf(token_fp,"reserved keyword: %s\n",yytext);
    return VOID;
}
"int" {
    fprintf(token_fp,"reserved keyword: %s\n",yytext);
    return INT;
}
"cint" {
    fprintf(token_fp,"reserved keyword: %s\n",yytext);
    return CINT;
}
"double" {
    fprintf(token_fp,"reserved keyword: %s\n",yytext);
    return DOUBLE;
}
"cdouble" {
    fprintf(token_fp,"reserved keyword: %s\n",yytext);
    return CDOUBLE;
}
"str" {
    fprintf(token_fp,"reserved keyword: %s\n",yytext);
    return STR;
}
"bin" {
    fprintf(token_fp,"reserved keyword: %s\n",yytext);
    return BIN;
}

"print" {
    fprintf(token_fp,"reserved keyword: %s\n",yytext);
    return PRINT;
}

"choice" {
 fprintf(token_fp,"reserved keyword: %s\n",yytext);
 return CHOICE;
}

"alt" {
 fprintf(token_fp,"reserved keyword: %s\n",yytext);
 return ALT;
}

"default" {
 fprintf(token_fp,"reserved keyword: %s\n",yytext);
 return DEFAULT;
}

    [>] {
        fprintf(parsed_fp, "%s", yytext);
        fprintf(token_fp, "operator: %s\n", yytext);
        return GT;
    }

    [<] {
        fprintf(parsed_fp, "%s", yytext);
        fprintf(token_fp, "operator: %s\n", yytext);
        return LT;
    }

    "eq" {
        fprintf(parsed_fp, "%s", yytext);
        fprintf(token_fp, "operator: %s\n", yytext);
        return EQ;
    }

    "neq" {
        fprintf(parsed_fp, "%s", yytext);
        fprintf(token_fp, "operator: %s\n", yytext);
        return NE;
    }

    "++" {
        fprintf(parsed_fp, "%s", yytext);
        fprintf(token_fp, "operator: %s\n", yytext);
        return INC;
    }

    "--" {
        fprintf(parsed_fp, "%s", yytext);
        fprintf(token_fp, "operator: %s\n", yytext);
        return DEC;
    }

    "rem" {
        fprintf(parsed_fp, "%s", yytext);
        fprintf(token_fp, "operator: %s\n", yytext);
        return REM;
    }

    "and" {
        fprintf(parsed_fp, "%s", yytext);
        fprintf(token_fp, "operator: %s\n", yytext);
        return AND;
    }

    "or" {
        fprintf(parsed_fp, "%s", yytext);
        fprintf(token_fp, "operator: %s\n", yytext);
        return OR;
    }

    "neg" {
        fprintf(parsed_fp, "%s", yytext);
        fprintf(token_fp, "operator: %s\n", yytext);
        return NEG;
    }

    "=" {
        fprintf(parsed_fp, "%s", yytext);
        fprintf(token_fp, "operator: %s\n", yytext);
        return ASSIGN;
    }

    "<=" {
        fprintf(parsed_fp, "%s", yytext);
        fprintf(token_fp, "operator: %s\n", yytext);
        return LE;
    }

    ">=" {
        fprintf(parsed_fp, "%s", yytext);
        fprintf(token_fp, "operator: %s\n", yytext);
        return GE;
    }
    "-" {
        fprintf(parsed_fp, "%s", yytext);
        fprintf(token_fp, "operator: %s\n", yytext);
        return MINUS;
    }
{ops} {
    //to identify opearators except pow(_2) opearator
        fprintf(parsed_fp, "%s", yytext);
        fprintf(token_fp, "operator: %s\n", yytext);
        return ARITH_OP;
    }


    "." {
        fprintf(parsed_fp, "%s", yytext);
        fprintf(token_fp, "special symbol: %s\n", yytext);
        return ACCESS_OP2;
    }

    [(] {
        fprintf(parsed_fp, "%s", yytext);
        fprintf(token_fp, "special symbol: %s\n", yytext);
        return OPEN_CIR_PAR;
    }

    [)] {
        fprintf(parsed_fp, "%s", yytext);
        fprintf(token_fp, "special symbol: %s\n", yytext);
        return CLOSE_CIR_PAR;
    }

    [{] {
        fprintf(parsed_fp, "%s", yytext);
        fprintf(token_fp, "special symbol: %s\n", yytext);
        return OPEN_CURLY_PAR;
    }

    [}] {
        fprintf(parsed_fp, "%s", yytext);
        fprintf(token_fp, "special symbol: %s\n", yytext);
        return CLOSE_CURLY_PAR;
    }

    [[] {
        fprintf(parsed_fp, "%s", yytext);
        fprintf(token_fp, "special symbol: %s\n", yytext);
        return OPEN_SQUARE_PAR;
    }

    []] {
        fprintf(parsed_fp, "%s", yytext);
        fprintf(token_fp, "special symbol: %s\n", yytext);
        return CLOSE_SQUARE_PAR;
    }


{id} {
    //to print ID's
    // strcpy(yylval.name,(yytext));
    yylval.name = strdup(yytext);
    fprintf(token_fp,"ID: %s\n",yytext);
    fprintf(parsed_fp,"%s",yytext);
    return ID;
    }

{int_num} {
    //to print int
    fprintf(token_fp,"int: %s\n",yytext);
    fprintf(parsed_fp,"%s",yytext);
    return INT_NUM;
    }
{double_num} {
    //to print double
    fprintf(token_fp,"double: %s\n",yytext);
    fprintf(parsed_fp,"%s",yytext);
    return DOUBLE_NUM;
    }
{string} {
    //to print string
    fprintf(token_fp,"string: %s\n",yytext);
    fprintf(parsed_fp,"%s",yytext);
    return STRING;
    }

";" {//Punctuations
    fprintf(token_fp,"punctuation: %s\n",yytext);
    fprintf(parsed_fp,"%s",yytext);
    return SEMICOL;
    }
"," {
    fprintf(token_fp,"punctuation: %s\n",yytext);
    fprintf(parsed_fp,"%s",yytext);
    return COMMA;
    }
":" {
    fprintf(token_fp,"punctuation: %s\n",yytext);
    fprintf(parsed_fp,"%s",yytext);
    return COLON;
    }
"\"" {
    fprintf(token_fp,"punctuation: %s\n",yytext);
    fprintf(parsed_fp,"%s",yytext);
    return QUOTE;
    }

%%

int yywrap() {
    return 1; // Indicate end of input
}
