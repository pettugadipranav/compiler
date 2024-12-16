/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ITER = 258,                    /* ITER  */
    PRINT = 259,                   /* PRINT  */
    UNTIL = 260,                   /* UNTIL  */
    RETURN = 261,                  /* RETURN  */
    REM = 262,                     /* REM  */
    NEQ = 263,                     /* NEQ  */
    OR = 264,                      /* OR  */
    NEG = 265,                     /* NEG  */
    AND = 266,                     /* AND  */
    INT = 267,                     /* INT  */
    CINT = 268,                    /* CINT  */
    DOUBLE = 269,                  /* DOUBLE  */
    CDOUBLE = 270,                 /* CDOUBLE  */
    STR = 271,                     /* STR  */
    STRING = 272,                  /* STRING  */
    BIN = 273,                     /* BIN  */
    REAL = 274,                    /* REAL  */
    IMG = 275,                     /* IMG  */
    POW = 276,                     /* POW  */
    POLAR = 277,                   /* POLAR  */
    CONJUGATE = 278,               /* CONJUGATE  */
    MOD = 279,                     /* MOD  */
    ARG = 280,                     /* ARG  */
    ANGLE = 281,                   /* ANGLE  */
    DIST = 282,                    /* DIST  */
    CPRINT = 283,                  /* CPRINT  */
    ROTATE = 284,                  /* ROTATE  */
    CHOICE = 285,                  /* CHOICE  */
    ALT = 286,                     /* ALT  */
    DEFAULT = 287,                 /* DEFAULT  */
    GET_LINE = 288,                /* GET_LINE  */
    IS_TRIANGLE = 289,             /* IS_TRIANGLE  */
    GET_CENTROID = 290,            /* GET_CENTROID  */
    GET_CIRCUMCENTER = 291,        /* GET_CIRCUMCENTER  */
    GET_ORTHOCENTER = 292,         /* GET_ORTHOCENTER  */
    GET_INCENTER = 293,            /* GET_INCENTER  */
    GET_EXCENTER = 294,            /* GET_EXCENTER  */
    GET_AREA = 295,                /* GET_AREA  */
    GET_PERIMETER = 296,           /* GET_PERIMETER  */
    ID = 297,                      /* ID  */
    SEMICOL = 298,                 /* SEMICOL  */
    COMMA = 299,                   /* COMMA  */
    COLON = 300,                   /* COLON  */
    QUOTE = 301,                   /* QUOTE  */
    GT = 302,                      /* GT  */
    LT = 303,                      /* LT  */
    EQ = 304,                      /* EQ  */
    NE = 305,                      /* NE  */
    INC = 306,                     /* INC  */
    DEC = 307,                     /* DEC  */
    ASSIGN = 308,                  /* ASSIGN  */
    LE = 309,                      /* LE  */
    GE = 310,                      /* GE  */
    INT_NUM = 311,                 /* INT_NUM  */
    DOUBLE_NUM = 312,              /* DOUBLE_NUM  */
    ARITH_OP = 313,                /* ARITH_OP  */
    ACCESS_OP1 = 314,              /* ACCESS_OP1  */
    ACCESS_OP2 = 315,              /* ACCESS_OP2  */
    INN_PROD = 316,                /* INN_PROD  */
    OPEN_CIR_PAR = 317,            /* OPEN_CIR_PAR  */
    CLOSE_CIR_PAR = 318,           /* CLOSE_CIR_PAR  */
    OPEN_CURLY_PAR = 319,          /* OPEN_CURLY_PAR  */
    CLOSE_CURLY_PAR = 320,         /* CLOSE_CURLY_PAR  */
    OPEN_SQUARE_PAR = 321,         /* OPEN_SQUARE_PAR  */
    CLOSE_SQUARE_PAR = 322,        /* CLOSE_SQUARE_PAR  */
    REAL_INC = 323,                /* REAL_INC  */
    IMAG_INC = 324                 /* IMAG_INC  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ITER 258
#define PRINT 259
#define UNTIL 260
#define RETURN 261
#define REM 262
#define NEQ 263
#define OR 264
#define NEG 265
#define AND 266
#define INT 267
#define CINT 268
#define DOUBLE 269
#define CDOUBLE 270
#define STR 271
#define STRING 272
#define BIN 273
#define REAL 274
#define IMG 275
#define POW 276
#define POLAR 277
#define CONJUGATE 278
#define MOD 279
#define ARG 280
#define ANGLE 281
#define DIST 282
#define CPRINT 283
#define ROTATE 284
#define CHOICE 285
#define ALT 286
#define DEFAULT 287
#define GET_LINE 288
#define IS_TRIANGLE 289
#define GET_CENTROID 290
#define GET_CIRCUMCENTER 291
#define GET_ORTHOCENTER 292
#define GET_INCENTER 293
#define GET_EXCENTER 294
#define GET_AREA 295
#define GET_PERIMETER 296
#define ID 297
#define SEMICOL 298
#define COMMA 299
#define COLON 300
#define QUOTE 301
#define GT 302
#define LT 303
#define EQ 304
#define NE 305
#define INC 306
#define DEC 307
#define ASSIGN 308
#define LE 309
#define GE 310
#define INT_NUM 311
#define DOUBLE_NUM 312
#define ARITH_OP 313
#define ACCESS_OP1 314
#define ACCESS_OP2 315
#define INN_PROD 316
#define OPEN_CIR_PAR 317
#define CLOSE_CIR_PAR 318
#define OPEN_CURLY_PAR 319
#define CLOSE_CURLY_PAR 320
#define OPEN_SQUARE_PAR 321
#define CLOSE_SQUARE_PAR 322
#define REAL_INC 323
#define IMAG_INC 324

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
