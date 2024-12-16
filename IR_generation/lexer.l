%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.hpp"
FILE *token_fp;
FILE *cpp_fp;
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
/* string \"(.*)+\" */
/* string ["][_/@$^#%&*a-zA-Z0-9\\ ]+["] */
string \"([^\"\\]*(\\.[^\"\\]*)*)\"

%%
"//".* {/*To address comments*/}
"\n" {l_no++;fprintf(cpp_fp,"\n");
    }
{blanks} {////fprintf(cpp_fp,"%s",yytext);
    }


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
    // fprintf(cpp_fp, "for" );
    return ITER;
}
"until" {
    fprintf(token_fp,"reserved keyword: %s\n",yytext);
    // fprintf(cpp_fp, "while");
    return UNTIL;
}
"return" {
    fprintf(token_fp,"reserved keyword: %s\n",yytext);
    //fprintf(cpp_fp,"%s",yytext);
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
    fprintf(cpp_fp, "cout<<");
    return PRINT;
}

"choice" {
 fprintf(token_fp,"reserved keyword: %s\n",yytext);
//  fprintf(cpp_fp, "if");
 return CHOICE;
}

"alt" {
 fprintf(token_fp,"reserved keyword: %s\n",yytext);
//  fprintf(cpp_fp, "else if");
 return ALT;
}

"default" {
 fprintf(token_fp,"reserved keyword: %s\n",yytext);
//  fprintf(cpp_fp, "else");
 return DEFAULT;
}

    [>] {
        fprintf(token_fp, "operator: %s\n", yytext);
        ////fprintf(cpp_fp,"%s",yytext);
        return GT;
    }

    [<] {
        fprintf(token_fp, "operator: %s\n", yytext);
        ////fprintf(cpp_fp,"%s",yytext);
        return LT;
    }

    "eq" {
        fprintf(token_fp, "operator: %s\n", yytext);
        // fprintf(cpp_fp, "==");
        return EQ;
    }

    "neq" {
        fprintf(token_fp, "operator: %s\n", yytext);
        // fprintf(cpp_fp, "!=");
        return NE;
    }

    "++" {
        fprintf(token_fp, "operator: %s\n", yytext);
        // ////fprintf(cpp_fp,"%s",yytext);
        return INC;
    }

    "--" {
        fprintf(token_fp, "operator: %s\n", yytext);
        // ////fprintf(cpp_fp,"%s",yytext);
        return DEC;
    }

    "rem" {
        // ////fprintf(cpp_fp,"%s",yytext);
        fprintf(token_fp, "operator: %s\n", yytext);
        return REM;
    }

    "and" {
        fprintf(token_fp, "operator: %s\n", yytext);
        // fprintf(cpp_fp, "&&");
        return AND;
    }

    "or" {
        fprintf(token_fp, "operator: %s\n", yytext);
        // fprintf(cpp_fp, "||");
        return OR;
    }

    "neg" {
        fprintf(token_fp, "operator: %s\n", yytext);
        // fprintf(cpp_fp, "!");
        return NEG;
    }

    "=" {
        fprintf(token_fp, "operator: %s\n", yytext);
        ////fprintf(cpp_fp,"%s",yytext);
        return ASSIGN;
    }

    "<=" {
        fprintf(token_fp, "operator: %s\n", yytext);
        ////fprintf(cpp_fp,"%s",yytext);
        return LE;
    }

    ">=" {
        fprintf(token_fp, "operator: %s\n", yytext);
        ////fprintf(cpp_fp,"%s",yytext);
        return GE;
    }
    "-" {
        yylval.name = strdup(yytext);
        fprintf(token_fp, "operator: %s\n", yytext);
        //fprintf(cpp_fp,"%s",yytext);
        return MINUS;
    }
{ops} {
    //to identify opearators except pow(_2) opearator
        yylval.name = strdup(yytext);
        fprintf(token_fp, "operator: %s\n", yytext);
        //fprintf(cpp_fp,"%s",yytext);
        return ARITH_OP;
    }


    "." {
        fprintf(token_fp, "special symbol: %s\n", yytext);
        // ////fprintf(cpp_fp,"%s",yytext);
        return ACCESS_OP2;
    }

    [(] {
        fprintf(token_fp, "special symbol: %s\n", yytext);
        ////fprintf(cpp_fp,"%s",yytext);
        return OPEN_CIR_PAR;
    }

    [)] {
        fprintf(token_fp, "special symbol: %s\n", yytext);
        ////fprintf(cpp_fp,"%s",yytext);
        return CLOSE_CIR_PAR;
    }

    [{] {
        fprintf(token_fp, "special symbol: %s\n", yytext);
        ////fprintf(cpp_fp,"%s",yytext);
        return OPEN_CURLY_PAR;
    }

    [}] {
        fprintf(token_fp, "special symbol: %s\n", yytext);
        ////fprintf(cpp_fp,"%s",yytext);
        return CLOSE_CURLY_PAR;
    }

    [[] {
        fprintf(token_fp, "special symbol: %s\n", yytext);
        ////fprintf(cpp_fp,"%s",yytext);
        return OPEN_SQUARE_PAR;
    }

    []] {
        fprintf(token_fp, "special symbol: %s\n", yytext);
        ////fprintf(cpp_fp,"%s",yytext);
        return CLOSE_SQUARE_PAR;
    }


{id} {
    //to print ID's
    // strcpy(yylval.name,(yytext));
    yylval.name = strdup(yytext);
    fprintf(token_fp,"ID: %s\n",yytext);
    return ID;
    }

{int_num} {
    //to print int
    yylval.name = strdup(yytext);
    fprintf(token_fp,"int: %s\n",yytext);
    ////fprintf(cpp_fp,"%s",yytext);
    return INT_NUM;
    }
{double_num} {
    //to print double
    yylval.name = strdup(yytext);
    fprintf(token_fp,"double: %s\n",yytext);
    ////fprintf(cpp_fp,"%s",yytext);
    return DOUBLE_NUM;
    }
{string} {
    yylval.name = strdup(yytext);
    //to print string
    fprintf(token_fp,"string: %s\n",yytext);
    return STRING;
    }

";" {//Punctuations
    fprintf(token_fp,"punctuation: %s\n",yytext);
    // //fprintf(cpp_fp,"%s",yytext);
    return SEMICOL;
    }
"," {
    fprintf(token_fp,"punctuation: %s\n",yytext);
    ////fprintf(cpp_fp,"%s",yytext);
    return COMMA;
    }
":" {
    fprintf(token_fp,"punctuation: %s\n",yytext);
    ////fprintf(cpp_fp,"%s",yytext);
    return COLON;
    }
"\"" {
    fprintf(token_fp,"punctuation: %s\n",yytext);
    ////fprintf(cpp_fp,"%s",yytext);
    return QUOTE;
    }

%%

int yywrap() {
    return 1; // Indicate end of input
}
