/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <ctype.h>
char *arr;
int l_no=1;
FILE *parsed_fp;
int ret_no;

#line 80 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ITER = 3,                       /* ITER  */
  YYSYMBOL_PRINT = 4,                      /* PRINT  */
  YYSYMBOL_UNTIL = 5,                      /* UNTIL  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_REM = 7,                        /* REM  */
  YYSYMBOL_NEQ = 8,                        /* NEQ  */
  YYSYMBOL_OR = 9,                         /* OR  */
  YYSYMBOL_NEG = 10,                       /* NEG  */
  YYSYMBOL_AND = 11,                       /* AND  */
  YYSYMBOL_INT = 12,                       /* INT  */
  YYSYMBOL_CINT = 13,                      /* CINT  */
  YYSYMBOL_DOUBLE = 14,                    /* DOUBLE  */
  YYSYMBOL_CDOUBLE = 15,                   /* CDOUBLE  */
  YYSYMBOL_STR = 16,                       /* STR  */
  YYSYMBOL_STRING = 17,                    /* STRING  */
  YYSYMBOL_BIN = 18,                       /* BIN  */
  YYSYMBOL_REAL = 19,                      /* REAL  */
  YYSYMBOL_IMG = 20,                       /* IMG  */
  YYSYMBOL_POW = 21,                       /* POW  */
  YYSYMBOL_POLAR = 22,                     /* POLAR  */
  YYSYMBOL_CONJUGATE = 23,                 /* CONJUGATE  */
  YYSYMBOL_MOD = 24,                       /* MOD  */
  YYSYMBOL_ARG = 25,                       /* ARG  */
  YYSYMBOL_ANGLE = 26,                     /* ANGLE  */
  YYSYMBOL_DIST = 27,                      /* DIST  */
  YYSYMBOL_CPRINT = 28,                    /* CPRINT  */
  YYSYMBOL_ROTATE = 29,                    /* ROTATE  */
  YYSYMBOL_CHOICE = 30,                    /* CHOICE  */
  YYSYMBOL_ALT = 31,                       /* ALT  */
  YYSYMBOL_DEFAULT = 32,                   /* DEFAULT  */
  YYSYMBOL_GET_LINE = 33,                  /* GET_LINE  */
  YYSYMBOL_IS_TRIANGLE = 34,               /* IS_TRIANGLE  */
  YYSYMBOL_GET_CENTROID = 35,              /* GET_CENTROID  */
  YYSYMBOL_GET_CIRCUMCENTER = 36,          /* GET_CIRCUMCENTER  */
  YYSYMBOL_GET_ORTHOCENTER = 37,           /* GET_ORTHOCENTER  */
  YYSYMBOL_GET_INCENTER = 38,              /* GET_INCENTER  */
  YYSYMBOL_GET_EXCENTER = 39,              /* GET_EXCENTER  */
  YYSYMBOL_GET_AREA = 40,                  /* GET_AREA  */
  YYSYMBOL_GET_PERIMETER = 41,             /* GET_PERIMETER  */
  YYSYMBOL_ID = 42,                        /* ID  */
  YYSYMBOL_SEMICOL = 43,                   /* SEMICOL  */
  YYSYMBOL_COMMA = 44,                     /* COMMA  */
  YYSYMBOL_COLON = 45,                     /* COLON  */
  YYSYMBOL_QUOTE = 46,                     /* QUOTE  */
  YYSYMBOL_GT = 47,                        /* GT  */
  YYSYMBOL_LT = 48,                        /* LT  */
  YYSYMBOL_EQ = 49,                        /* EQ  */
  YYSYMBOL_NE = 50,                        /* NE  */
  YYSYMBOL_INC = 51,                       /* INC  */
  YYSYMBOL_DEC = 52,                       /* DEC  */
  YYSYMBOL_ASSIGN = 53,                    /* ASSIGN  */
  YYSYMBOL_LE = 54,                        /* LE  */
  YYSYMBOL_GE = 55,                        /* GE  */
  YYSYMBOL_INT_NUM = 56,                   /* INT_NUM  */
  YYSYMBOL_DOUBLE_NUM = 57,                /* DOUBLE_NUM  */
  YYSYMBOL_ARITH_OP = 58,                  /* ARITH_OP  */
  YYSYMBOL_ACCESS_OP1 = 59,                /* ACCESS_OP1  */
  YYSYMBOL_ACCESS_OP2 = 60,                /* ACCESS_OP2  */
  YYSYMBOL_INN_PROD = 61,                  /* INN_PROD  */
  YYSYMBOL_OPEN_CIR_PAR = 62,              /* OPEN_CIR_PAR  */
  YYSYMBOL_CLOSE_CIR_PAR = 63,             /* CLOSE_CIR_PAR  */
  YYSYMBOL_OPEN_CURLY_PAR = 64,            /* OPEN_CURLY_PAR  */
  YYSYMBOL_CLOSE_CURLY_PAR = 65,           /* CLOSE_CURLY_PAR  */
  YYSYMBOL_OPEN_SQUARE_PAR = 66,           /* OPEN_SQUARE_PAR  */
  YYSYMBOL_CLOSE_SQUARE_PAR = 67,          /* CLOSE_SQUARE_PAR  */
  YYSYMBOL_REAL_INC = 68,                  /* REAL_INC  */
  YYSYMBOL_IMAG_INC = 69,                  /* IMAG_INC  */
  YYSYMBOL_YYACCEPT = 70,                  /* $accept  */
  YYSYMBOL_program = 71,                   /* program  */
  YYSYMBOL_stmts = 72,                     /* stmts  */
  YYSYMBOL_stmt_types = 73,                /* stmt_types  */
  YYSYMBOL_func_stmt = 74,                 /* func_stmt  */
  YYSYMBOL_d_type = 75,                    /* d_type  */
  YYSYMBOL_data_type = 76,                 /* data_type  */
  YYSYMBOL_data_type_arr = 77,             /* data_type_arr  */
  YYSYMBOL_if_stmt = 78,                   /* if_stmt  */
  YYSYMBOL_elif_stmt = 79,                 /* elif_stmt  */
  YYSYMBOL_inc_stmt = 80,                  /* inc_stmt  */
  YYSYMBOL_for_stmt = 81,                  /* for_stmt  */
  YYSYMBOL_while_stmt = 82,                /* while_stmt  */
  YYSYMBOL_decl_stmt = 83,                 /* decl_stmt  */
  YYSYMBOL_void_fn_calls = 84,             /* void_fn_calls  */
  YYSYMBOL_assign_stmt = 85,               /* assign_stmt  */
  YYSYMBOL_return_stmt = 86,               /* return_stmt  */
  YYSYMBOL_predicate = 87,                 /* predicate  */
  YYSYMBOL_exp_rhs = 88,                   /* exp_rhs  */
  YYSYMBOL_fn_call = 89,                   /* fn_call  */
  YYSYMBOL_fn_args = 90,                   /* fn_args  */
  YYSYMBOL_fn_type = 91,                   /* fn_type  */
  YYSYMBOL_iter_fir_stmt = 92,             /* iter_fir_stmt  */
  YYSYMBOL_iter_sec_stmt = 93,             /* iter_sec_stmt  */
  YYSYMBOL_iter_thir_stmt = 94,            /* iter_thir_stmt  */
  YYSYMBOL_iter = 95,                      /* iter  */
  YYSYMBOL_until = 96,                     /* until  */
  YYSYMBOL_inbuilt_fn = 97,                /* inbuilt_fn  */
  YYSYMBOL_real_fn = 98,                   /* real_fn  */
  YYSYMBOL_img_fn = 99,                    /* img_fn  */
  YYSYMBOL_pow_fn = 100,                   /* pow_fn  */
  YYSYMBOL_polar_fn = 101,                 /* polar_fn  */
  YYSYMBOL_conjugate_fn = 102,             /* conjugate_fn  */
  YYSYMBOL_mod_fn = 103,                   /* mod_fn  */
  YYSYMBOL_arg_fn = 104,                   /* arg_fn  */
  YYSYMBOL_angle_fn = 105,                 /* angle_fn  */
  YYSYMBOL_dist_fn = 106,                  /* dist_fn  */
  YYSYMBOL_cprint_fn = 107,                /* cprint_fn  */
  YYSYMBOL_rotate_fn = 108,                /* rotate_fn  */
  YYSYMBOL_get_line_fn = 109,              /* get_line_fn  */
  YYSYMBOL_is_triangle_fn = 110,           /* is_triangle_fn  */
  YYSYMBOL_get_centroid_fn = 111,          /* get_centroid_fn  */
  YYSYMBOL_get_circumcenter_fn = 112,      /* get_circumcenter_fn  */
  YYSYMBOL_get_orthocenter_fn = 113,       /* get_orthocenter_fn  */
  YYSYMBOL_get_incenter_fn = 114,          /* get_incenter_fn  */
  YYSYMBOL_get_excenter_fn = 115,          /* get_excenter_fn  */
  YYSYMBOL_get_area_fn = 116,              /* get_area_fn  */
  YYSYMBOL_get_perimeter_fn = 117,         /* get_perimeter_fn  */
  YYSYMBOL_print_arg = 118,                /* print_arg  */
  YYSYMBOL_print_fn = 119,                 /* print_fn  */
  YYSYMBOL_var_decl = 120,                 /* var_decl  */
  YYSYMBOL_data_types = 121,               /* data_types  */
  YYSYMBOL_real_decl = 122,                /* real_decl  */
  YYSYMBOL_int_part = 123,                 /* int_part  */
  YYSYMBOL_int_id_type = 124,              /* int_id_type  */
  YYSYMBOL_double_part = 125,              /* double_part  */
  YYSYMBOL_double_id_type = 126,           /* double_id_type  */
  YYSYMBOL_comp_decl = 127,                /* comp_decl  */
  YYSYMBOL_cint_part = 128,                /* cint_part  */
  YYSYMBOL_cint_id_type = 129,             /* cint_id_type  */
  YYSYMBOL_cdouble_part = 130,             /* cdouble_part  */
  YYSYMBOL_cdouble_id_type = 131,          /* cdouble_id_type  */
  YYSYMBOL_argument = 132,                 /* argument  */
  YYSYMBOL_argument_list = 133,            /* argument_list  */
  YYSYMBOL_T = 134,                        /* T  */
  YYSYMBOL_L = 135                         /* L  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1063

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  169
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  396

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   324


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   155,   155,   156,   159,   160,   162,   163,   164,   165,
     166,   167,   168,   169,   171,   173,   176,   176,   176,   176,
     178,   179,   183,   184,   188,   189,   191,   192,   193,   194,
     196,   198,   200,   202,   204,   205,   207,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   235,   236,   238,   239,   240,   242,   245,   246,   247,
     248,   250,   251,   253,   254,   255,   259,   261,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   287,
     289,   291,   293,   295,   297,   299,   301,   303,   305,   307,
     309,   311,   313,   315,   317,   319,   321,   323,   325,   327,
     328,   329,   330,   332,   334,   335,   337,   338,   340,   341,
     343,   344,   346,   347,   348,   349,   351,   352,   354,   355,
     356,   357,   359,   360,   362,   363,   365,   366,   367,   368,
     369,   370,   372,   373,   375,   376,   377,   378,   379,   380,
     384,   385,   387,   388,   390,   391,   392,   393,   395,   396
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ITER", "PRINT",
  "UNTIL", "RETURN", "REM", "NEQ", "OR", "NEG", "AND", "INT", "CINT",
  "DOUBLE", "CDOUBLE", "STR", "STRING", "BIN", "REAL", "IMG", "POW",
  "POLAR", "CONJUGATE", "MOD", "ARG", "ANGLE", "DIST", "CPRINT", "ROTATE",
  "CHOICE", "ALT", "DEFAULT", "GET_LINE", "IS_TRIANGLE", "GET_CENTROID",
  "GET_CIRCUMCENTER", "GET_ORTHOCENTER", "GET_INCENTER", "GET_EXCENTER",
  "GET_AREA", "GET_PERIMETER", "ID", "SEMICOL", "COMMA", "COLON", "QUOTE",
  "GT", "LT", "EQ", "NE", "INC", "DEC", "ASSIGN", "LE", "GE", "INT_NUM",
  "DOUBLE_NUM", "ARITH_OP", "ACCESS_OP1", "ACCESS_OP2", "INN_PROD",
  "OPEN_CIR_PAR", "CLOSE_CIR_PAR", "OPEN_CURLY_PAR", "CLOSE_CURLY_PAR",
  "OPEN_SQUARE_PAR", "CLOSE_SQUARE_PAR", "REAL_INC", "IMAG_INC", "$accept",
  "program", "stmts", "stmt_types", "func_stmt", "d_type", "data_type",
  "data_type_arr", "if_stmt", "elif_stmt", "inc_stmt", "for_stmt",
  "while_stmt", "decl_stmt", "void_fn_calls", "assign_stmt", "return_stmt",
  "predicate", "exp_rhs", "fn_call", "fn_args", "fn_type", "iter_fir_stmt",
  "iter_sec_stmt", "iter_thir_stmt", "iter", "until", "inbuilt_fn",
  "real_fn", "img_fn", "pow_fn", "polar_fn", "conjugate_fn", "mod_fn",
  "arg_fn", "angle_fn", "dist_fn", "cprint_fn", "rotate_fn", "get_line_fn",
  "is_triangle_fn", "get_centroid_fn", "get_circumcenter_fn",
  "get_orthocenter_fn", "get_incenter_fn", "get_excenter_fn",
  "get_area_fn", "get_perimeter_fn", "print_arg", "print_fn", "var_decl",
  "data_types", "real_decl", "int_part", "int_id_type", "double_part",
  "double_id_type", "comp_decl", "cint_part", "cint_id_type",
  "cdouble_part", "cdouble_id_type", "argument", "argument_list", "T", "L", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-190)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-72)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -29,   134,    36,   -29,  -190,  -190,  -190,  -190,     2,   -14,
    -190,  -190,    17,    -3,  -190,   194,  -190,  -190,  -190,  -190,
    -190,    19,    44,    51,    31,   194,    64,  -190,  1021,  -190,
      69,    76,    79,    81,   345,   108,   136,   153,   156,   111,
     137,   140,   141,   142,   149,   160,   173,   174,   191,   195,
     196,   198,   203,   204,   205,   208,   209,   212,   216,   217,
      18,   163,  1021,  -190,   175,  -190,  -190,   237,   240,   242,
     243,  -190,   226,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,    77,     4,   345,   345,   110,   -46,   117,   345,  -190,
     951,  -190,    14,  -190,   245,   -51,  -190,   246,   131,  -190,
     247,    12,  -190,   248,   345,   345,   345,   345,   345,   345,
     345,   345,   345,   345,   345,   345,   345,   345,   345,   345,
     345,   345,   345,   345,   345,  -190,  -190,   345,   239,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,   345,    18,
    -190,  -190,  -190,   250,   253,   183,   235,   236,   951,  -190,
    -190,  -190,   345,  -190,  -190,  -190,  -190,    74,   345,   345,
     345,   345,   345,   345,   345,   345,   345,   345,   244,   256,
     108,   257,   259,   136,   345,   129,   260,   153,   129,   268,
     156,   116,   133,   632,   166,   214,   273,   285,   645,   657,
     342,   674,   262,   687,   699,   716,   729,   741,   758,   771,
     783,   800,   951,   270,   813,   266,   345,     4,     4,  -190,
     238,     1,   345,  -190,  -190,   294,    85,     8,   264,   201,
       7,    11,   968,   951,   275,   274,  -190,     9,   277,  -190,
     951,  -190,  -190,   279,   278,  -190,    10,   280,  -190,  -190,
    -190,   345,  -190,  -190,  -190,  -190,   345,   345,  -190,   345,
     282,   345,   345,   345,   345,   345,   345,   345,   345,   345,
     299,   345,  -190,   311,   313,  -190,  -190,  1021,  -190,   366,
     291,  -190,   302,   295,  -190,   296,  -190,   129,   310,  -190,
     384,   401,   419,   825,  1021,   443,   842,   855,   867,   884,
     897,   909,   926,   939,   345,  -190,   318,   323,  -190,   338,
     335,   343,   347,   341,   350,  -190,  -190,  -190,   345,   344,
    -190,   345,   345,   345,   345,   345,   345,   345,   345,   951,
    -190,  -190,   348,  -190,   351,   353,   355,   356,   359,   360,
     461,   377,   478,   496,   520,   538,   555,   573,   597,   615,
     362,  -190,   361,  -190,  -190,   379,  -190,  -190,   374,   405,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  1021,   373,
     376,   345,   380,   381,  -190,  -190,   378,  1021,  -190,   389,
     392,  1021,  -190,   393,   377,  -190
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     3,    16,    17,    18,    19,     0,    21,
       1,     2,     0,     0,    15,   163,    20,   164,   165,   166,
     167,     0,   160,     0,     0,   163,   168,   162,     5,   161,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      66,     0,     5,     8,     0,     9,    10,     0,     0,     0,
       0,    33,     0,    30,    31,    62,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    32,   124,   125,
     169,    70,     0,     0,     0,    49,    50,    51,     0,    48,
      36,    52,   132,   128,   130,   146,   142,   144,   138,   129,
     136,   154,   143,   152,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    29,     0,     0,    26,
      27,    14,     4,    13,     7,    12,     6,    11,    65,     0,
      69,    67,    68,     0,   120,   119,     0,    48,     0,    45,
      53,    54,     0,    55,    56,    57,    58,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    34,     0,    64,     0,    72,     0,     0,   123,
       0,     0,     0,    46,    44,    43,    37,    38,    39,    40,
      42,    41,    47,   133,     0,     0,   131,     0,     0,   145,
     139,   126,   127,     0,     0,   137,     0,     0,   153,    99,
     100,     0,   102,   103,   104,   105,     0,     0,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,    61,    48,     0,   121,   122,     5,    59,     0,
       0,   134,     0,   147,   149,     0,   140,     0,   155,   157,
       0,     0,     0,     0,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    75,     0,    60,     0,
       0,     0,     0,     0,     0,   101,   106,   107,     0,     0,
     110,     0,     0,     0,     0,     0,     0,     0,     0,    35,
      74,    73,     0,    77,     0,   148,     0,     0,   156,     0,
       0,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   135,     0,   150,   141,     0,   158,   109,     0,    22,
     111,   112,   113,   114,   115,   116,   117,   118,     5,     0,
       0,     0,     0,     0,   151,   159,    48,     5,    76,     0,
       0,     5,    23,     0,    25,    24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -190,   442,   -61,  -190,  -190,  -190,  -190,  -190,  -190,    66,
     -99,  -190,  -190,   364,  -190,   -97,  -190,  -100,   -27,   -28,
     180,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,   -38,  -190,
    -190,  -189,  -190,   272,  -190,   281,  -190,  -190,   283,  -190,
     263,  -190,   446,  -190,  -190,  -190
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,    61,    62,     3,     8,     9,    14,    63,   369,
      64,    65,    66,    67,    68,    69,    70,   109,   168,   111,
     225,    72,   163,   284,   342,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,   166,    96,
      97,   253,    98,   113,   114,   119,   120,    99,   116,   117,
     122,   123,    21,    22,    23,    27
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      71,   152,   160,   167,   162,   173,   174,   110,    32,   256,
     178,   191,   179,     1,   104,   192,   178,   178,   179,   179,
     178,   164,   179,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    71,   212,    10,    51,    52,    53,
      54,    55,    56,    57,    58,    59,   105,    12,   180,   181,
     182,   183,    13,   292,   297,   184,   185,   182,   183,   186,
     106,   107,   184,   185,    16,   184,   108,   187,   288,   145,
     146,   147,   293,   298,   198,   165,   188,   169,   199,    15,
     189,   177,    24,   178,   148,   179,   149,   150,    25,    35,
      36,    37,    38,    26,   178,    28,   179,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   323,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   232,   159,
     222,   180,   181,   182,   183,   178,   283,   179,   184,   185,
      30,   224,   186,   181,   182,   183,   100,   233,   101,   184,
     185,   102,   178,   103,   179,   231,     4,     5,     6,     7,
     112,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   170,   171,   180,   181,   182,   183,   250,   175,   176,
     184,   185,   -66,   124,   186,   178,   172,   179,   115,   259,
     180,   181,   182,   183,   194,   251,   252,   184,   185,   285,
     286,   186,   178,   195,   179,   118,   260,   196,   121,   125,
     165,   165,   126,   127,   128,   289,    17,    18,    19,    20,
     178,   129,   179,   180,   181,   182,   183,   340,   153,   341,
     184,   185,   130,   178,   186,   179,   317,   228,   151,   262,
     180,   181,   182,   183,   300,   131,   132,   184,   185,   301,
     302,   186,   303,   329,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   133,   224,   184,   185,   134,   135,    71,
     136,   180,   181,   182,   183,   137,   138,   139,   184,   185,
     140,   141,   186,   178,   142,   179,    71,   263,   143,   144,
     154,   386,   178,   155,   179,   156,   157,   339,   158,   190,
     193,   197,   200,   226,   178,   223,   179,   227,   229,   230,
     244,   350,   287,   178,   352,   353,   354,   355,   356,   357,
     358,   359,   245,   247,   183,   248,   254,   383,   184,   185,
     180,   181,   182,   183,   257,   270,   390,   184,   185,   282,
     393,   186,   180,   181,   182,   183,   264,   280,   290,   184,
     185,   291,   295,   186,   294,   296,   304,   299,   265,    32,
      71,   178,   314,   179,   -71,   104,   316,   319,   320,    71,
     159,   321,   322,    71,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,   178,   324,   179,    51,    52,
      53,    54,    55,    56,    57,    58,    59,   105,   343,   180,
     181,   182,   183,   178,   344,   179,   184,   185,   345,   346,
     186,   106,   107,   347,   348,   268,   349,   108,   368,   351,
     178,   360,   179,   180,   181,   182,   183,   379,   361,   362,
     184,   185,   363,   364,   186,   365,   378,   366,   178,   318,
     179,   180,   181,   182,   183,   380,   381,   382,   184,   185,
     384,   389,   186,   385,   387,    11,   388,   325,   180,   181,
     182,   183,   178,   391,   179,   184,   185,   392,   394,   186,
     395,   315,   246,   258,   326,   161,   180,   181,   182,   183,
     178,    29,   179,   184,   185,     0,   249,   186,   255,     0,
       0,     0,   327,     0,     0,     0,     0,   178,     0,   179,
     180,   181,   182,   183,     0,     0,     0,   184,   185,     0,
       0,   186,     0,     0,     0,   178,   330,   179,   180,   181,
     182,   183,     0,     0,     0,   184,   185,     0,     0,   186,
       0,     0,     0,     0,   367,   180,   181,   182,   183,   178,
       0,   179,   184,   185,     0,     0,   186,     0,     0,     0,
       0,   370,     0,   180,   181,   182,   183,   178,     0,   179,
     184,   185,     0,     0,   186,     0,     0,     0,     0,   371,
       0,     0,     0,     0,   178,     0,   179,   180,   181,   182,
     183,     0,     0,     0,   184,   185,     0,     0,   186,     0,
       0,     0,   178,   372,   179,   180,   181,   182,   183,     0,
       0,     0,   184,   185,     0,     0,   186,     0,     0,     0,
       0,   373,   180,   181,   182,   183,   178,     0,   179,   184,
     185,     0,     0,   186,     0,     0,     0,     0,   374,     0,
     180,   181,   182,   183,   178,     0,   179,   184,   185,     0,
       0,   186,     0,     0,     0,     0,   375,     0,     0,     0,
       0,   178,     0,   179,   180,   181,   182,   183,     0,     0,
       0,   184,   185,     0,   178,   186,   179,     0,     0,     0,
     376,     0,   180,   181,   182,   183,   178,     0,   179,   184,
     185,     0,     0,   186,     0,     0,   261,     0,   377,   180,
     181,   182,   183,   178,     0,   179,   184,   185,     0,   266,
     186,     0,   180,   181,   182,   183,   178,     0,   179,   184,
     185,   267,     0,   186,   180,   181,   182,   183,   178,     0,
     179,   184,   185,     0,     0,   186,     0,     0,   269,     0,
       0,   180,   181,   182,   183,   178,     0,   179,   184,   185,
       0,   271,   186,     0,   180,   181,   182,   183,   178,     0,
     179,   184,   185,   272,     0,   186,   180,   181,   182,   183,
     178,     0,   179,   184,   185,     0,     0,   186,     0,     0,
     273,     0,     0,   180,   181,   182,   183,   178,     0,   179,
     184,   185,     0,   274,   186,     0,   180,   181,   182,   183,
     178,     0,   179,   184,   185,   275,     0,   186,   180,   181,
     182,   183,   178,     0,   179,   184,   185,     0,     0,   186,
       0,     0,   276,     0,     0,   180,   181,   182,   183,   178,
       0,   179,   184,   185,     0,   277,   186,     0,   180,   181,
     182,   183,   178,     0,   179,   184,   185,   278,     0,   186,
     180,   181,   182,   183,   178,     0,   179,   184,   185,     0,
       0,   186,     0,     0,   279,     0,     0,   180,   181,   182,
     183,   178,     0,   179,   184,   185,     0,   281,   186,     0,
     180,   181,   182,   183,   178,     0,   179,   184,   185,   328,
       0,   186,   180,   181,   182,   183,   178,     0,   179,   184,
     185,     0,     0,   186,     0,     0,   331,     0,     0,   180,
     181,   182,   183,   178,     0,   179,   184,   185,     0,   332,
     186,     0,   180,   181,   182,   183,   178,     0,   179,   184,
     185,   333,     0,   186,   180,   181,   182,   183,   178,     0,
     179,   184,   185,     0,     0,   186,     0,     0,   334,     0,
       0,   180,   181,   182,   183,   178,     0,   179,   184,   185,
       0,   335,   186,     0,   180,   181,   182,   183,   178,     0,
     179,   184,   185,   336,     0,   186,   180,   181,   182,   183,
     178,     0,   179,   184,   185,     0,     0,   186,     0,     0,
     337,     0,     0,   180,   181,   182,   183,   178,     0,   179,
     184,   185,     0,   338,   186,     0,   180,   181,   182,   183,
       0,     0,     0,   184,   185,     0,     0,   186,   180,   181,
     182,   183,     0,     0,     0,   184,   185,     0,     0,   186,
       0,     0,     0,     0,     0,   180,   181,   182,   183,     0,
       0,     0,   184,   185,    31,    32,    33,    34,     0,     0,
       0,     0,     0,    35,    36,    37,    38,     0,     0,     0,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,     0,     0,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60
};

static const yytype_int16 yycheck[] =
{
      28,    62,   101,   103,   101,    51,    52,    34,     4,   198,
       9,    62,    11,    42,    10,    66,     9,     9,    11,    11,
       9,    17,    11,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    62,   135,     0,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    45,    47,    48,
      49,    50,    66,    44,    44,    54,    55,    49,    50,    58,
      56,    57,    54,    55,    67,    54,    62,    53,    67,    51,
      52,    53,    63,    63,    62,   102,    62,   104,    66,    62,
      66,   108,    63,     9,    66,    11,    68,    69,    44,    12,
      13,    14,    15,    42,     9,    64,    11,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   297,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    44,    42,
     147,    47,    48,    49,    50,     9,   226,    11,    54,    55,
      66,   158,    58,    48,    49,    50,    67,    63,    62,    54,
      55,    62,     9,    62,    11,   172,    12,    13,    14,    15,
      42,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    51,    52,    47,    48,    49,    50,   194,    51,    52,
      54,    55,    62,    62,    58,     9,    66,    11,    42,    63,
      47,    48,    49,    50,    53,    56,    57,    54,    55,   227,
     228,    58,     9,    62,    11,    42,    63,    66,    42,    62,
     227,   228,    62,    62,    62,   232,    12,    13,    14,    15,
       9,    62,    11,    47,    48,    49,    50,   316,    43,   316,
      54,    55,    62,     9,    58,    11,   287,    44,    65,    63,
      47,    48,    49,    50,   261,    62,    62,    54,    55,   266,
     267,    58,   269,   304,   271,   272,   273,   274,   275,   276,
     277,   278,   279,    62,   281,    54,    55,    62,    62,   287,
      62,    47,    48,    49,    50,    62,    62,    62,    54,    55,
      62,    62,    58,     9,    62,    11,   304,    63,    62,    62,
      43,   381,     9,    43,    11,    43,    43,   314,    62,    44,
      44,    44,    44,    43,     9,    56,    11,    44,    63,    63,
      56,   328,    64,     9,   331,   332,   333,   334,   335,   336,
     337,   338,    56,    56,    50,    56,    56,   378,    54,    55,
      47,    48,    49,    50,    56,    63,   387,    54,    55,    63,
     391,    58,    47,    48,    49,    50,    63,    67,    63,    54,
      55,    67,    63,    58,    67,    67,    64,    67,    63,     4,
     378,     9,    53,    11,    43,    10,    43,    66,    56,   387,
      42,    66,    66,   391,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     9,    66,    11,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    65,    47,
      48,    49,    50,     9,    56,    11,    54,    55,    63,    56,
      58,    56,    57,    56,    63,    63,    56,    62,    31,    65,
       9,    63,    11,    47,    48,    49,    50,    56,    67,    66,
      54,    55,    67,    67,    58,    66,    64,    67,     9,    63,
      11,    47,    48,    49,    50,    56,    62,    32,    54,    55,
      67,    63,    58,    67,    64,     3,    65,    63,    47,    48,
      49,    50,     9,    64,    11,    54,    55,    65,    65,    58,
     394,   281,   190,   200,    63,   101,    47,    48,    49,    50,
       9,    25,    11,    54,    55,    -1,   193,    58,   197,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,     9,    -1,    11,
      47,    48,    49,    50,    -1,    -1,    -1,    54,    55,    -1,
      -1,    58,    -1,    -1,    -1,     9,    63,    11,    47,    48,
      49,    50,    -1,    -1,    -1,    54,    55,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    63,    47,    48,    49,    50,     9,
      -1,    11,    54,    55,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    63,    -1,    47,    48,    49,    50,     9,    -1,    11,
      54,    55,    -1,    -1,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,     9,    -1,    11,    47,    48,    49,
      50,    -1,    -1,    -1,    54,    55,    -1,    -1,    58,    -1,
      -1,    -1,     9,    63,    11,    47,    48,    49,    50,    -1,
      -1,    -1,    54,    55,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    63,    47,    48,    49,    50,     9,    -1,    11,    54,
      55,    -1,    -1,    58,    -1,    -1,    -1,    -1,    63,    -1,
      47,    48,    49,    50,     9,    -1,    11,    54,    55,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,     9,    -1,    11,    47,    48,    49,    50,    -1,    -1,
      -1,    54,    55,    -1,     9,    58,    11,    -1,    -1,    -1,
      63,    -1,    47,    48,    49,    50,     9,    -1,    11,    54,
      55,    -1,    -1,    58,    -1,    -1,    44,    -1,    63,    47,
      48,    49,    50,     9,    -1,    11,    54,    55,    -1,    44,
      58,    -1,    47,    48,    49,    50,     9,    -1,    11,    54,
      55,    44,    -1,    58,    47,    48,    49,    50,     9,    -1,
      11,    54,    55,    -1,    -1,    58,    -1,    -1,    44,    -1,
      -1,    47,    48,    49,    50,     9,    -1,    11,    54,    55,
      -1,    44,    58,    -1,    47,    48,    49,    50,     9,    -1,
      11,    54,    55,    44,    -1,    58,    47,    48,    49,    50,
       9,    -1,    11,    54,    55,    -1,    -1,    58,    -1,    -1,
      44,    -1,    -1,    47,    48,    49,    50,     9,    -1,    11,
      54,    55,    -1,    44,    58,    -1,    47,    48,    49,    50,
       9,    -1,    11,    54,    55,    44,    -1,    58,    47,    48,
      49,    50,     9,    -1,    11,    54,    55,    -1,    -1,    58,
      -1,    -1,    44,    -1,    -1,    47,    48,    49,    50,     9,
      -1,    11,    54,    55,    -1,    44,    58,    -1,    47,    48,
      49,    50,     9,    -1,    11,    54,    55,    44,    -1,    58,
      47,    48,    49,    50,     9,    -1,    11,    54,    55,    -1,
      -1,    58,    -1,    -1,    44,    -1,    -1,    47,    48,    49,
      50,     9,    -1,    11,    54,    55,    -1,    44,    58,    -1,
      47,    48,    49,    50,     9,    -1,    11,    54,    55,    44,
      -1,    58,    47,    48,    49,    50,     9,    -1,    11,    54,
      55,    -1,    -1,    58,    -1,    -1,    44,    -1,    -1,    47,
      48,    49,    50,     9,    -1,    11,    54,    55,    -1,    44,
      58,    -1,    47,    48,    49,    50,     9,    -1,    11,    54,
      55,    44,    -1,    58,    47,    48,    49,    50,     9,    -1,
      11,    54,    55,    -1,    -1,    58,    -1,    -1,    44,    -1,
      -1,    47,    48,    49,    50,     9,    -1,    11,    54,    55,
      -1,    44,    58,    -1,    47,    48,    49,    50,     9,    -1,
      11,    54,    55,    44,    -1,    58,    47,    48,    49,    50,
       9,    -1,    11,    54,    55,    -1,    -1,    58,    -1,    -1,
      44,    -1,    -1,    47,    48,    49,    50,     9,    -1,    11,
      54,    55,    -1,    44,    58,    -1,    47,    48,    49,    50,
      -1,    -1,    -1,    54,    55,    -1,    -1,    58,    47,    48,
      49,    50,    -1,    -1,    -1,    54,    55,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,    -1,
      -1,    -1,    54,    55,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,    12,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    71,    74,    12,    13,    14,    15,    75,    76,
       0,    71,    45,    66,    77,    62,    67,    12,    13,    14,
      15,   132,   133,   134,    63,    44,    42,   135,    64,   132,
      66,     3,     4,     5,     6,    12,    13,    14,    15,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    72,    73,    78,    80,    81,    82,    83,    84,    85,
      86,    89,    91,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   119,   120,   122,   127,
      67,    62,    62,    62,    10,    42,    56,    57,    62,    87,
      88,    89,    42,   123,   124,    42,   128,   129,    42,   125,
     126,    42,   130,   131,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    51,    52,    53,    66,    68,
      69,    65,    72,    43,    43,    43,    43,    43,    62,    42,
      80,    83,    85,    92,    17,    88,   118,    87,    88,    88,
      51,    52,    66,    51,    52,    51,    52,    88,     9,    11,
      47,    48,    49,    50,    54,    55,    58,    53,    62,    66,
      44,    62,    66,    44,    53,    62,    66,    44,    62,    66,
      44,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    87,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    56,    88,    90,    43,    44,    44,    63,
      63,    88,    44,    63,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    56,    56,   123,    56,    56,   128,
      88,    56,    57,   121,    56,   125,   121,    56,   130,    63,
      63,    44,    63,    63,    63,    63,    44,    44,    63,    44,
      63,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      67,    44,    63,    87,    93,   118,   118,    64,    67,    88,
      63,    67,    44,    63,    67,    63,    67,    44,    63,    67,
      88,    88,    88,    88,    64,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    53,    90,    43,    72,    63,    66,
      56,    66,    66,   121,    66,    63,    63,    63,    44,    72,
      63,    44,    44,    44,    44,    44,    44,    44,    44,    88,
      80,    85,    94,    65,    56,    63,    56,    56,    63,    56,
      88,    65,    88,    88,    88,    88,    88,    88,    88,    88,
      63,    67,    66,    67,    67,    66,    67,    63,    31,    79,
      63,    63,    63,    63,    63,    63,    63,    63,    64,    56,
      56,    62,    32,    72,    67,    67,    87,    64,    65,    63,
      72,    64,    65,    72,    65,    79
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    71,    72,    72,    73,    73,    73,    73,
      73,    73,    73,    73,    74,    75,    76,    76,    76,    76,
      77,    77,    78,    78,    79,    79,    80,    80,    80,    80,
      81,    82,    83,    84,    85,    85,    86,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    89,    89,    90,    90,    90,    91,    92,    92,    92,
      92,    93,    93,    94,    94,    94,    95,    96,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     118,   118,   118,   119,   120,   120,   121,   121,   122,   122,
     123,   123,   124,   124,   124,   124,   125,   125,   126,   126,
     126,   126,   127,   127,   128,   128,   129,   129,   129,   129,
     129,   129,   130,   130,   131,   131,   131,   131,   131,   131,
     132,   132,   133,   133,   134,   134,   134,   134,   135,   135
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     2,     2,     1,     1,
       1,     2,     2,     2,     9,     2,     1,     1,     1,     1,
       2,     0,     8,    12,     8,     0,     2,     2,     2,     2,
       1,     1,     1,     1,     3,     6,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     2,     4,
       5,     4,     1,     3,     1,     0,     1,     1,     1,     1,
       0,     1,     0,     1,     1,     0,    11,     7,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     6,     4,     4,     4,     4,     6,     6,     4,     8,
       6,     8,     8,     8,     8,     8,     8,     8,     8,     1,
       1,     3,     3,     4,     1,     1,     1,     1,     2,     2,
       1,     3,     1,     3,     4,     7,     1,     3,     1,     3,
       4,     7,     2,     2,     1,     3,     1,     4,     6,     4,
       7,     9,     1,     3,     1,     4,     6,     4,     7,     9,
       1,     3,     2,     0,     1,     1,     1,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 32: /* decl_stmt: var_decl  */
#line 200 "parser.y"
                     {/*Note above 4 are wrtitten for testing only*/}
#line 1784 "y.tab.c"
    break;

  case 60: /* exp_rhs: OPEN_CIR_PAR exp_rhs COMMA exp_rhs CLOSE_CIR_PAR  */
#line 233 "parser.y"
                                                           {/*This is doubt for a=(3,3) type*/}
#line 1790 "y.tab.c"
    break;


#line 1794 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 399 "parser.y"

#include "lex.yy.c"

void yyerror(char * s)
/* yacc error handler */
{  
 fprintf (parsed_fp, "\ninvalid statement\n");
 fprintf (stderr, "Error: %s ,At line no : %d\n", s,l_no);
 exit(0);
}
  
int main()
{
  ret_no=0;
  arr=(char *)calloc(1000,sizeof(char));
  int t;
//   printf("Enter test case number: ");
  // scanf("%d",&t);
  char input_file[100];
  char token_file[100];
  char parsed_file[100];
  sprintf(input_file,"./input.txt");
  sprintf(token_file,"./out_token.txt");
  sprintf(parsed_file,"./parser.txt");
  yyin = fopen(input_file, "r"); //open input file
  token_fp=fopen(token_file,"w"); //open token file
  parsed_fp=fopen(parsed_file,"w"); //open token file
  if(yyin==NULL||token_fp==NULL||parsed_fp==NULL) 
  {
      printf("Error opening file s\n");
      return 0;
  }
//   fprintf(token_fp,"Name: Yoligi Govinda Rohith\nID: CS21BTECH11062\nInput file: public_test_%d.clike\n",t);
  yyparse();
//   printf("Syntactically correct!\n");
  fclose(token_fp);
  fclose(parsed_fp);
  return 0;
}
