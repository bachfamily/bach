/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Skeleton implementation for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

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

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 1




/* Substitute the variable and function names.  */
#define yyparse bisonparserV3_parse
#define yylex   bisonparserV3_lex
#define yyerror bisonparserV3_error
#define yydebug bisonparserV3_debug

/* First part of user prologue.  */
#line 1 "bisonparserV3.y"

    /*
     *  bisonparserV3.y
     *
     * Copyright (C) 2010-2022 Andrea Agostini and Daniele Ghisi
     *
     * This program is free software: you can redistribute it and/or modify it
     * under the terms of the GNU General Public License
     * as published by the Free Software Foundation,
     * either version 3 of the License, or (at your option) any later version.
     * This program is distributed in the hope that it will be useful,
     * but WITHOUT ANY WARRANTY; without even the implied warranty of
     * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
     * See the GNU General Public License for more details.
     * You should have received a copy of the GNU General Public License
     * along with this program.
     * If not, see <https://www.gnu.org/licenses/>.
     *
     */
#line 28 "bisonparserV3.y"

    #ifdef CONFIGURATION_Development
    #define code_dev_post post // UNCOMMENT THIS TO TURN ON VERBOSE PARSING
    #endif
    
    #ifndef code_dev_post
    #define code_dev_post(...) ((void) 0)
    #else
    #define YYDEBUG 1
    #endif
    
    //#define BACH_MAX
    #ifdef BACH_MAX
    #include "foundation/llllobj.h"
    #include "ext_common.h"
    #include "ext_globalsymbol.h"
    #else
    #include <stdio.h>
    #define code_dev_post printf
    #endif
    
    #include "bell/bach_codableobj.hpp"
    #include "bell/ast.hpp"
    #include "bellparser_commons.h"

    extern t_bach *bach;


    

#line 113 "bisonparserV3.tab.c"

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

#include "bisonparserV3.tab.h"

/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LONG_LITERAL = 3,               /* LONG_LITERAL  */
  YYSYMBOL_INLET = 4,                      /* INLET  */
  YYSYMBOL_INTINLET = 5,                   /* INTINLET  */
  YYSYMBOL_RATINLET = 6,                   /* RATINLET  */
  YYSYMBOL_FLOATINLET = 7,                 /* FLOATINLET  */
  YYSYMBOL_PITCHINLET = 8,                 /* PITCHINLET  */
  YYSYMBOL_OUTLET = 9,                     /* OUTLET  */
  YYSYMBOL_DIRINLET = 10,                  /* DIRINLET  */
  YYSYMBOL_DIROUTLET = 11,                 /* DIROUTLET  */
  YYSYMBOL_RAT_LITERAL = 12,               /* RAT_LITERAL  */
  YYSYMBOL_DOUBLE_LITERAL = 13,            /* DOUBLE_LITERAL  */
  YYSYMBOL_PITCH_LITERAL = 14,             /* PITCH_LITERAL  */
  YYSYMBOL_SYMBOL_LITERAL = 15,            /* SYMBOL_LITERAL  */
  YYSYMBOL_GLOBALVAR = 16,                 /* GLOBALVAR  */
  YYSYMBOL_PATCHERVAR = 17,                /* PATCHERVAR  */
  YYSYMBOL_LOCALVAR = 18,                  /* LOCALVAR  */
  YYSYMBOL_NAMEDPARAM = 19,                /* NAMEDPARAM  */
  YYSYMBOL_BIF = 20,                       /* BIF  */
  YYSYMBOL_OF = 21,                        /* OF  */
  YYSYMBOL_MAXFUNCTION = 22,               /* MAXFUNCTION  */
  YYSYMBOL_NULLIFY = 23,                   /* NULLIFY  */
  YYSYMBOL_IF_KW = 24,                     /* IF_KW  */
  YYSYMBOL_THEN_KW = 25,                   /* THEN_KW  */
  YYSYMBOL_ELSE_KW = 26,                   /* ELSE_KW  */
  YYSYMBOL_WHILE_KW = 27,                  /* WHILE_KW  */
  YYSYMBOL_DO_KW = 28,                     /* DO_KW  */
  YYSYMBOL_FOR_KW = 29,                    /* FOR_KW  */
  YYSYMBOL_IN_KW = 30,                     /* IN_KW  */
  YYSYMBOL_COLLECT_KW = 31,                /* COLLECT_KW  */
  YYSYMBOL_ASSIGN = 32,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 33,                      /* PLUS  */
  YYSYMBOL_MINUS = 34,                     /* MINUS  */
  YYSYMBOL_TIMES = 35,                     /* TIMES  */
  YYSYMBOL_DIV = 36,                       /* DIV  */
  YYSYMBOL_DIVDIV = 37,                    /* DIVDIV  */
  YYSYMBOL_APLUS = 38,                     /* APLUS  */
  YYSYMBOL_LOGOR = 39,                     /* LOGOR  */
  YYSYMBOL_LOGAND = 40,                    /* LOGAND  */
  YYSYMBOL_LOGOREXT = 41,                  /* LOGOREXT  */
  YYSYMBOL_LOGANDEXT = 42,                 /* LOGANDEXT  */
  YYSYMBOL_EQUAL = 43,                     /* EQUAL  */
  YYSYMBOL_LT = 44,                        /* LT  */
  YYSYMBOL_GT = 45,                        /* GT  */
  YYSYMBOL_LEQ = 46,                       /* LEQ  */
  YYSYMBOL_GEQ = 47,                       /* GEQ  */
  YYSYMBOL_NEQ = 48,                       /* NEQ  */
  YYSYMBOL_OPEN = 49,                      /* OPEN  */
  YYSYMBOL_CLOSEDROUND = 50,               /* CLOSEDROUND  */
  YYSYMBOL_FUNDEF = 51,                    /* FUNDEF  */
  YYSYMBOL_PUSH = 52,                      /* PUSH  */
  YYSYMBOL_POP = 53,                       /* POP  */
  YYSYMBOL_STARTPARAMS = 54,               /* STARTPARAMS  */
  YYSYMBOL_COMMA = 55,                     /* COMMA  */
  YYSYMBOL_ELLIPSIS = 56,                  /* ELLIPSIS  */
  YYSYMBOL_BACHNULL = 57,                  /* BACHNULL  */
  YYSYMBOL_BACHNIL = 58,                   /* BACHNIL  */
  YYSYMBOL_ARGCOUNT = 59,                  /* ARGCOUNT  */
  YYSYMBOL_EOL = 60,                       /* EOL  */
  YYSYMBOL_UNRECOGNIZED = 61,              /* UNRECOGNIZED  */
  YYSYMBOL_LIFT = 62,                      /* LIFT  */
  YYSYMBOL_AMINUS = 63,                    /* AMINUS  */
  YYSYMBOL_ATIMES = 64,                    /* ATIMES  */
  YYSYMBOL_APOWOP = 65,                    /* APOWOP  */
  YYSYMBOL_ADIV = 66,                      /* ADIV  */
  YYSYMBOL_ADIVDIV = 67,                   /* ADIVDIV  */
  YYSYMBOL_AREM = 68,                      /* AREM  */
  YYSYMBOL_ABITAND = 69,                   /* ABITAND  */
  YYSYMBOL_ABITXOR = 70,                   /* ABITXOR  */
  YYSYMBOL_ABITOR = 71,                    /* ABITOR  */
  YYSYMBOL_ALSHIFT = 72,                   /* ALSHIFT  */
  YYSYMBOL_ARSHIFT = 73,                   /* ARSHIFT  */
  YYSYMBOL_ALOGAND = 74,                   /* ALOGAND  */
  YYSYMBOL_ALOGANDEXT = 75,                /* ALOGANDEXT  */
  YYSYMBOL_ALOGXOR = 76,                   /* ALOGXOR  */
  YYSYMBOL_ALOGOR = 77,                    /* ALOGOR  */
  YYSYMBOL_ALOGOREXT = 78,                 /* ALOGOREXT  */
  YYSYMBOL_ANTHOP = 79,                    /* ANTHOP  */
  YYSYMBOL_AAPPLY = 80,                    /* AAPPLY  */
  YYSYMBOL_ACONCAT = 81,                   /* ACONCAT  */
  YYSYMBOL_ARCONCAT = 82,                  /* ARCONCAT  */
  YYSYMBOL_CONCAT = 83,                    /* CONCAT  */
  YYSYMBOL_LOGXOR = 84,                    /* LOGXOR  */
  YYSYMBOL_BITOR = 85,                     /* BITOR  */
  YYSYMBOL_BITXOR = 86,                    /* BITXOR  */
  YYSYMBOL_BITAND = 87,                    /* BITAND  */
  YYSYMBOL_REPEAT = 88,                    /* REPEAT  */
  YYSYMBOL_RANGE = 89,                     /* RANGE  */
  YYSYMBOL_LSHIFT = 90,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 91,                    /* RSHIFT  */
  YYSYMBOL_REM = 92,                       /* REM  */
  YYSYMBOL_UPLUS = 93,                     /* UPLUS  */
  YYSYMBOL_UMINUS = 94,                    /* UMINUS  */
  YYSYMBOL_POWOP = 95,                     /* POWOP  */
  YYSYMBOL_NTHOP = 96,                     /* NTHOP  */
  YYSYMBOL_PICKOP = 97,                    /* PICKOP  */
  YYSYMBOL_APPLY = 98,                     /* APPLY  */
  YYSYMBOL_ACCESS_UNWRAP = 99,             /* ACCESS_UNWRAP  */
  YYSYMBOL_LVALUESTEPPARAMS = 100,         /* LVALUESTEPPARAMS  */
  YYSYMBOL_AS_KW = 101,                    /* AS_KW  */
  YYSYMBOL_WITH_KW = 102,                  /* WITH_KW  */
  YYSYMBOL_LOGNOT = 103,                   /* LOGNOT  */
  YYSYMBOL_BITNOT = 104,                   /* BITNOT  */
  YYSYMBOL_KEEP = 105,                     /* KEEP  */
  YYSYMBOL_UNKEEP = 106,                   /* UNKEEP  */
  YYSYMBOL_INIT = 107,                     /* INIT  */
  YYSYMBOL_YYACCEPT = 108,                 /* $accept  */
  YYSYMBOL_program = 109,                  /* program  */
  YYSYMBOL_funarg = 110,                   /* funarg  */
  YYSYMBOL_111_1 = 111,                    /* $@1  */
  YYSYMBOL_funargList = 112,               /* funargList  */
  YYSYMBOL_113_2 = 113,                    /* $@2  */
  YYSYMBOL_liftedargList = 114,            /* liftedargList  */
  YYSYMBOL_fundef = 115,                   /* fundef  */
  YYSYMBOL_116_3 = 116,                    /* $@3  */
  YYSYMBOL_117_4 = 117,                    /* $@4  */
  YYSYMBOL_118_5 = 118,                    /* $@5  */
  YYSYMBOL_119_6 = 119,                    /* $@6  */
  YYSYMBOL_listVector = 120,               /* listVector  */
  YYSYMBOL_list = 121,                     /* list  */
  YYSYMBOL_sequence = 122,                 /* sequence  */
  YYSYMBOL_nullified = 123,                /* nullified  */
  YYSYMBOL_nullifiedSequence = 124,        /* nullifiedSequence  */
  YYSYMBOL_whileloop = 125,                /* whileloop  */
  YYSYMBOL_forarg = 126,                   /* forarg  */
  YYSYMBOL_forargList = 127,               /* forargList  */
  YYSYMBOL_forloop = 128,                  /* forloop  */
  YYSYMBOL_argsByPositionList = 129,       /* argsByPositionList  */
  YYSYMBOL_argsByNameList = 130,           /* argsByNameList  */
  YYSYMBOL_argByName = 131,                /* argByName  */
  YYSYMBOL_itemOrVar = 132,                /* itemOrVar  */
  YYSYMBOL_simpleFuncall = 133,            /* simpleFuncall  */
  YYSYMBOL_sign = 134,                     /* sign  */
  YYSYMBOL_lvalueSpecsItem = 135,          /* lvalueSpecsItem  */
  YYSYMBOL_dataflowHead = 136,             /* dataflowHead  */
  YYSYMBOL_dataflowFuncall = 137,          /* dataflowFuncall  */
  YYSYMBOL_funcall = 138,                  /* funcall  */
  YYSYMBOL_var = 139,                      /* var  */
  YYSYMBOL_localVar = 140,                 /* localVar  */
  YYSYMBOL_globalVar = 141,                /* globalVar  */
  YYSYMBOL_patcherVar = 142,               /* patcherVar  */
  YYSYMBOL_lvalueSpecsUFinal = 143,        /* lvalueSpecsUFinal  */
  YYSYMBOL_lvalueSpecsFinal = 144,         /* lvalueSpecsFinal  */
  YYSYMBOL_lvalue = 145,                   /* lvalue  */
  YYSYMBOL_fakeLvalueHead = 146,           /* fakeLvalueHead  */
  YYSYMBOL_fakeLvalue = 147,               /* fakeLvalue  */
  YYSYMBOL_lvalueSpecsNonFinalized = 148,  /* lvalueSpecsNonFinalized  */
  YYSYMBOL_lvalueSpecs = 149,              /* lvalueSpecs  */
  YYSYMBOL_listEnd = 150,                  /* listEnd  */
  YYSYMBOL_expr = 151,                     /* expr  */
  YYSYMBOL_item = 152,                     /* item  */
  YYSYMBOL_assignment = 153,               /* assignment  */
  YYSYMBOL_conditional = 154               /* conditional  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;

/* Second part of user prologue.  */
#line 161 "bisonparserV3.y"

    #include "bisonparserV3_tab_nolines.h"
    
    #define YY_HEADER_EXPORT_START_CONDITIONS
    #define YY_NO_UNISTD_H
    
    #include "bisonparserV3_lex_nolines.h"
    

    
    int yylex(YYSTYPE *yylval_param, yyscan_t myscanner, struct _parseParams
    *params);
    
    int yyerror(yyscan_t myscanner,
    t_parseParams *params,
    const char *s);
    
    
    YY_BUFFER_STATE bisonparserV3_scan_string(yyscan_t myscanner, const char *buf);
    void bisonparserV3_flush_and_delete_buffer(yyscan_t myscanner, YY_BUFFER_STATE bp);



#line 332 "bisonparserV3.tab.c"


#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#ifdef __cplusplus
  typedef bool yybool;
# define yytrue true
# define yyfalse false
#else
  /* When we move to stdbool, get rid of the various casts to yybool.  */
  typedef signed char yybool;
# define yytrue 1
# define yyfalse 0
#endif

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify Clang and ICC.  */
# define YYLONGJMP(Env, Val)                    \
 do {                                           \
   longjmp (Env, Val);                          \
   YY_ASSERT (0);                               \
 } while (yyfalse)
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

/* The _Noreturn keyword of C11.  */
#ifndef _Noreturn
# if (defined __cplusplus \
      && ((201103 <= __cplusplus && !(__GNUC__ == 4 && __GNUC_MINOR__ == 7)) \
          || (defined _MSC_VER && 1900 <= _MSC_VER)))
#  define _Noreturn [[noreturn]]
# elif ((!defined __cplusplus || defined __clang__) \
        && (201112 <= (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0) \
            || (!defined __STRICT_ANSI__ \
                && (4 < __GNUC__ + (7 <= __GNUC_MINOR__) \
                    || (defined __apple_build_version__ \
                        ? 6000000 <= __apple_build_version__ \
                        : 3 < __clang_major__ + (5 <= __clang_minor__))))))
   /* _Noreturn works as-is.  */
# elif (2 < __GNUC__ + (8 <= __GNUC_MINOR__) || defined __clang__ \
        || 0x5110 <= __SUNPRO_C)
#  define _Noreturn __attribute__ ((__noreturn__))
# elif 1200 <= (defined _MSC_VER ? _MSC_VER : 0)
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  86
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   7937

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  217
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  375
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 8
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   362

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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   203,   203,   208,   214,   220,   230,   233,   233,   243,
     252,   252,   260,   268,   275,   285,   285,   302,   302,   321,
     321,   341,   341,   367,   372,   380,   387,   388,   395,   398,
     403,   408,   412,   420,   424,   432,   437,   447,   453,   462,
     467,   472,   477,   482,   487,   492,   497,   502,   507,   516,
     522,   531,   536,   541,   550,   558,   559,   564,   567,   570,
     573,   576,   579,   582,   585,   588,   591,   598,   601,   604,
     607,   614,   615,   626,   627,   628,   634,   638,   647,   648,
     653,   654,   655,   660,   665,   670,   679,   689,   700,   701,
     702,   703,   704,   709,   710,   722,   725,   733,   734,   740,
     748,   754,   759,   765,   775,   781,   786,   792,   797,   802,
     803,   804,   805,   806,   812,   813,   814,   815,   816,   823,
     828,   835,   839,   843,   847,   851,   855,   859,   863,   867,
     871,   875,   879,   883,   887,   891,   895,   899,   903,   907,
     911,   915,   919,   923,   927,   931,   935,   939,   943,   952,
     956,   960,   964,   968,   972,   976,   981,   987,   993,   999,
    1005,  1011,  1017,  1026,  1030,  1033,  1037,  1043,  1048,  1053,
    1064,  1069,  1075,  1081,  1087,  1093,  1099,  1105,  1111,  1117,
    1123,  1129,  1135,  1141,  1147,  1153,  1159,  1165,  1171,  1177,
    1183,  1189,  1196,  1199,  1202,  1205,  1208,  1211,  1214,  1217,
    1220,  1223,  1226,  1229,  1232,  1235,  1238,  1241,  1244,  1247,
    1250,  1253,  1257,  1267,  1272,  1286,  1301,  1305
};
#endif

#define YYPACT_NINF (-216)
#define YYTABLE_NINF (-99)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     492,  -216,  -216,  -216,  -216,  -216,  -216,   -25,  -216,    -3,
    -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
    -216,  1152,  1212,    52,   672,  -216,   732,  -216,  -216,  -216,
      55,  -216,  -216,  1272,  1332,    75,   103,   152,   124,     1,
     -10,   -17,  -216,   792,   160,   165,   173,   852,  -216,  -216,
     151,   -53,  1392,   109,   110,   -43,   387,  -216,  -216,  -216,
    7834,    24,  7855,  -216,   249,   -31,  -216,  -216,  1452,  1512,
     185,   -11,    -2,  -216,   159,  -216,   161,  1572,  -216,   167,
    -216,  -216,  -216,  -216,  -216,   186,  -216,  -216,   -10,     3,
     187,  -216,  -216,  -216,   206,  7595,  -216,  -216,  -216,   160,
     173,   552,   612,   912,   972,  7611,  7568,  7568,  7092,  7152,
      58,   101,  1632,  1692,  1752,  1812,  1872,  1932,  1992,  2052,
    2112,  2172,  2232,  2292,  2352,  2412,  2472,  2532,  2592,  2652,
    2712,  7568,  2772,  2832,   104,  2892,  2952,  3012,  3072,  3132,
    3192,  3252,  3312,  3372,  3432,  3492,  3552,  3612,  3672,  3732,
    3792,  3852,  3912,  7568,  3972,  4032,  4092,  4152,  4212,  4272,
    4332,  4392,  4452,  4512,  4572,  4632,  4692,  4752,  4812,  4872,
    4932,  4992,  5052,  5112,  5172,  5232,  5292,  5352,  5412,  5472,
    5532,  5592,  -216,  -216,  5652,  5712,  5772,   193,  5832,  5892,
    5952,    52,  6012,   210,  -216,  -216,  -216,  6072,  6132,  -216,
    -216,  -216,  6192,  -216,  6252,  -216,  -216,   -15,   -14,  -216,
    -216,   143,   162,   178,  -216,  -216,   178,  -216,  -216,  -216,
     151,  7212,  -216,  -216,   135,  -216,  -216,   136,  -216,  -216,
    -216,  7272,  7332,  7452,  7452,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,   228,   228,
     106,   106,   106,  7676,  7708,  7676,  7708,  7279,  7159,  7159,
    7159,  7159,  7279,  7692,  7447,  7773,  7789,  7516,   497,   615,
     615,   106,   106,  -216,   209,  -216,  -216,  6312,  -216,  -216,
    -216,  -216,    33,   158,  -216,  -216,  6372,  6432,  -216,  -216,
    -216,  1032,   166,  -216,   210,  -216,  -216,  1092,   172,  -216,
    -216,  -216,   151,  -216,  7392,  -216,  -216,  -216,  7510,  -216,
    -216,  6492,  -216,  6552,  6612,   210,  6672,  6732,  6792,  -216,
    -216,  -216,   175,  -216,  -216,   176,  -216,  -216,  -216,  -216,
    -216,    41,  -216,  -216,    40,  -216,  -216,  6852,  6912,  6972,
    7032,  -216,  -216,  -216,  -216
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,   149,   157,   158,   159,   160,   161,     0,   162,     0,
     150,   151,   152,   153,    86,    87,    83,     3,   167,   168,
     169,    10,    10,     0,    10,    17,    10,   154,   156,   155,
       0,    67,    68,    10,    10,     0,     0,     0,     0,     0,
       0,     0,   113,    25,    26,     4,    30,    27,   110,   111,
       0,    78,    10,     0,    79,   116,    95,    81,    80,    82,
     118,     0,   119,   117,    23,   114,   109,   112,    10,    10,
       0,     0,     0,    37,     0,   164,     0,    10,   166,     0,
      13,   121,   122,    84,    85,     0,     1,    15,     0,     0,
       6,     9,    11,    21,     0,    24,    28,     5,    29,    32,
      31,    10,    10,    67,    68,   120,     0,     0,    10,    10,
     108,    96,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,     0,    10,    10,    99,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,     0,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,   214,   215,    10,    10,    10,     0,    10,    10,
      10,     0,    10,     0,   163,    18,   165,    10,    10,    12,
      19,     7,    10,    14,    10,    57,    49,     0,     0,    51,
      62,     0,     0,    76,    56,    55,    77,    91,    89,    90,
      71,    10,   100,    92,    56,    93,   104,    55,    88,   102,
     106,    10,    10,     0,     0,   171,   177,   178,   173,   172,
     175,   174,   176,   184,   185,   186,   187,   188,   179,   180,
     181,   182,   183,   191,   212,   189,   190,   192,   198,   199,
     194,   193,   196,   195,   197,   205,   206,   207,   208,   209,
     200,   201,   202,   203,   204,   213,   210,   211,   123,   124,
     125,   126,   127,   141,   142,   144,   145,   135,   137,   138,
     139,   140,   136,   143,   132,   131,   130,   148,   147,   133,
     134,   128,   129,   146,   216,    33,    34,    10,    35,    39,
      44,    38,     0,     0,   170,    16,    10,    10,    22,    54,
      58,    10,     0,    59,     0,    53,    63,    10,     0,    64,
      69,    70,    72,    94,    10,   105,   107,    71,     0,   101,
     103,    10,    36,    10,    10,     0,    10,    10,    10,    20,
       8,    50,     0,    61,    52,     0,    66,    72,   217,    41,
      46,     0,    40,    45,     0,    60,    65,    10,    10,    10,
      10,    42,    47,    43,    48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -216,  -216,   149,  -216,  -216,  -216,   202,   -98,  -216,  -216,
    -216,  -216,  -216,   -38,     0,   195,  -216,   -66,    54,  -216,
     -60,   145,   -75,  -146,   -76,    43,   -90,   -65,  -216,  -216,
    -106,   -94,  -216,  -216,  -216,  -215,   -52,  -216,  -216,  -216,
    -216,   188,  -216,   205,    22,  -216,   -58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    38,    92,   317,    39,    40,    41,    42,   198,    77,
     316,   202,    43,    44,   206,    46,    47,    48,    73,    74,
      49,   207,   208,   209,    50,    51,    52,   222,    53,    54,
      55,    56,    57,    58,    59,   225,   226,    60,    61,    62,
     110,   111,    63,    64,    65,    66,    67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,   102,   223,   223,   204,   204,   333,    68,    90,    99,
     217,   217,   214,   214,   224,   224,   187,   185,   221,   221,
     186,    70,    71,   -55,    76,   254,    79,   212,   188,    69,
     182,   183,   220,   220,    93,   320,   323,   224,    94,   195,
     321,   324,   218,   218,   229,   -74,    91,   275,   219,   219,
     228,   228,    87,   -98,   200,   -98,    88,   230,    94,   224,
     204,   343,   325,    30,   344,   -97,   325,   -73,   369,   367,
      72,   370,   368,    80,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,    83,   255,   256,   324,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   223,   276,   277,   313,   333,
     108,    84,   109,   217,    86,   223,   223,   224,   215,   215,
     227,   227,   322,   217,   217,   345,   328,   224,   224,   214,
     214,   334,   334,   338,   338,   332,   304,   305,   306,   213,
     216,   309,   310,   227,   231,   218,   232,   337,   337,   314,
     315,   219,   204,   228,   318,   218,   218,   325,   339,   340,
      85,   219,   219,   228,   228,   227,   325,   204,   354,   335,
     336,   204,   325,    96,    97,   204,   346,   189,   308,   347,
     190,   204,   312,   326,   204,   204,    98,   233,   327,   234,
     233,   180,   234,   181,   319,   101,   325,   106,   107,   325,
     184,   194,   329,   324,   191,   325,   353,   324,   197,   201,
     196,   324,   356,   307,   203,   365,   366,   324,   223,   204,
     324,   324,   102,   -56,   -55,   341,   217,   199,    81,    82,
     224,    89,   100,   227,   214,   311,   352,   211,    95,   134,
       0,     0,   355,   227,   227,   215,   215,   105,     0,   348,
     192,   193,   357,   158,   159,   160,     0,     0,   218,     0,
     361,     0,     0,     0,   219,     0,   228,     0,   349,   350,
       0,     0,   156,   157,   158,   159,   160,     0,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,     0,     0,
       0,     0,     0,   358,     0,   359,   360,   342,   362,   363,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     179,   351,     0,   180,     0,   181,     0,   351,     0,   371,
     372,   373,   374,   171,   172,   173,   174,   175,   176,   177,
     178,   179,     0,     0,   180,     0,   181,     0,   364,     0,
       0,     0,     0,     0,     0,     0,   227,     0,     0,     0,
     215,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   -95,     0,     0,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,     0,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -56,   -95,   -95,   -95,   -95,   -95,     0,     0,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
       0,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   108,   -95,   109,     0,     0,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,     0,     0,     0,     0,     0,
     156,   157,   158,   159,   160,     0,     0,     0,     0,     0,
       0,    24,     0,    25,    26,     0,     0,     0,   -10,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,   204,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,   177,   178,   179,
       0,     0,   180,     0,   181,    33,    34,    35,    36,    37,
       0,    24,   205,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,   204,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,   156,   157,
     158,   159,   160,     0,     0,    33,    34,    35,    36,    37,
       0,    24,   210,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,   179,     0,     0,
     180,     0,   181,     0,     0,    33,    34,    35,    36,    37,
       0,    24,    75,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,    78,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,   -10,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,   -10,    27,
      28,    29,     0,     0,    30,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,     0,   -67,   -67,   -67,     0,   -67,     0,     0,   -67,
       0,   -67,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,   -67,     0,   -67,   -67,     0,     0,     0,   -67,   -67,
     -67,   -67,     0,     0,   -67,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,     0,   -68,   -68,   -68,     0,   -68,     0,     0,   -68,
       0,   -68,     0,     0,     0,   -67,   -67,     0,     0,     0,
       0,     0,     0,     0,     0,   -67,   -67,   -67,   -67,   -67,
       0,   -68,     0,   -68,   -68,     0,     0,     0,   -68,   -68,
     -68,   -68,     0,     0,   -68,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,   204,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,   -68,   -68,     0,     0,     0,
       0,     0,     0,     0,     0,   -68,   -68,   -68,   -68,   -68,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,   204,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,   103,   104,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     0,     8,     0,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     0,     8,     0,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,   156,   157,   158,   159,   160,    35,    36,     0,
       0,    24,   165,    25,    26,     0,     0,   170,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     0,     8,     0,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,   175,   176,   177,
     178,   179,     0,     0,   180,     0,   181,    35,    36,     0,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     0,     8,     0,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,   330,   331,     0,     0,     0,
       0,     0,   156,   157,   158,   159,   160,    35,    36,     0,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     0,     8,     0,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,   175,   176,   177,
     178,   179,     0,     0,   180,     0,   181,    35,    36,     0,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     0,     8,     0,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,    23,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    35,    36,     0,
       0,    24,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     0,    30,     1,     2,     3,     4,     5,
       6,     0,     8,     0,    10,    11,    12,    13,    14,    15,
      16,     0,    18,    19,    20,     0,     0,     0,     0,     0,
     156,   157,   158,   159,   160,   330,   331,     0,     0,     0,
     165,   166,   167,   168,   169,   170,     0,    35,    36,     0,
       0,    24,     0,     0,    26,     0,     0,     0,     0,    27,
      28,    29,     0,     1,     2,     3,     4,     5,     6,     0,
       8,     0,    10,    11,    12,    13,    14,    15,    16,     0,
      18,    19,    20,   173,   174,   175,   176,   177,   178,   179,
       0,     0,   180,     0,   181,    31,    32,     0,     0,   156,
     157,   158,   159,   160,     0,     0,     0,    35,    36,    24,
       0,     0,    26,     0,     0,     0,     0,    27,    28,    29,
       0,     1,     2,     3,     4,     5,     6,     0,     8,     0,
      10,    11,    12,    13,    14,    15,    16,     0,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   330,   331,   176,   177,   178,   179,     0,
       0,   180,     0,   181,     0,    35,    36,    24,     0,     0,
      26,     0,     0,     0,     0,    27,    28,    29,   156,   157,
     158,   159,   160,     0,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   156,   157,   158,   159,   160,     0,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,    36,     0,     0,     0,     0,   171,
     172,   173,   174,   175,   176,   177,   178,   179,     0,     0,
     180,     0,   181,     0,     0,   171,   172,   173,   174,   175,
     176,   177,   178,   179,     0,     0,   180,     0,   181,   156,
     157,   158,   159,   160,     0,     0,   162,     0,   164,   165,
     166,   167,   168,   169,   170,   156,   157,   158,   159,   160,
       0,     0,   162,     0,   164,   165,   166,   167,   168,   169,
     170,   156,   157,   158,   159,   160,     0,     0,     0,     0,
       0,   165,   166,   167,   168,   169,   170,     0,     0,     0,
     171,   172,   173,   174,   175,   176,   177,   178,   179,     0,
       0,   180,     0,   181,     0,     0,     0,   172,   173,   174,
     175,   176,   177,   178,   179,     0,     0,   180,     0,   181,
       0,     0,     0,   172,   173,   174,   175,   176,   177,   178,
     179,     0,     0,   180,     0,   181,   156,   157,   158,   159,
     160,     0,     0,     0,     0,     0,   165,   166,   167,   168,
     169,   170,   156,   157,   158,   159,   160,     0,     0,     0,
       0,     0,   165,   166,   167,   168,   169,   170,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     174,   175,   176,   177,   178,   179,   112,     0,   180,     0,
     181,     0,   113,     0,     0,     0,     0,   175,   176,   177,
     178,   179,     0,     0,   180,     0,   181,   135,     0,     0,
       0,     0,     0,   136,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,     0,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,   153,   154,   155
};

static const yytype_int16 yycheck[] =
{
       0,    54,   108,   109,    19,    19,   221,    32,    18,    47,
     108,   109,   106,   107,   108,   109,    18,    28,   108,   109,
      31,    21,    22,    54,    24,   131,    26,   102,    30,    32,
      68,    69,   108,   109,    51,    50,    50,   131,    55,    77,
      55,    55,   108,   109,   109,    98,    56,   153,   108,   109,
     108,   109,    51,    96,    51,    98,    55,   109,    55,   153,
      19,    28,   208,    62,    31,    96,   212,    98,    28,    28,
      18,    31,    31,    18,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    18,   132,   133,    55,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   221,   154,   155,   193,   334,
      96,    18,    98,   221,     0,   231,   232,   221,   106,   107,
     108,   109,   207,   231,   232,   102,   211,   231,   232,   233,
     234,   231,   232,   233,   234,   221,   184,   185,   186,   106,
     107,   189,   190,   131,    96,   221,    98,   233,   234,   197,
     198,   221,    19,   221,   202,   231,   232,   313,   233,   234,
      18,   231,   232,   231,   232,   153,   322,    19,   324,   231,
     232,    19,   328,    23,    19,    19,    28,    28,   188,    31,
      31,    19,   192,    50,    19,    19,    23,    96,    55,    98,
      96,    95,    98,    97,   204,    54,   352,    98,    98,   355,
      25,    50,    50,    55,    55,   361,    50,    55,    32,    32,
      53,    55,    50,    30,    18,    50,    50,    55,   334,    19,
      55,    55,    54,    98,    98,    26,   334,    88,    33,    34,
     334,    39,    47,   221,   338,   191,   321,   102,    43,    61,
      -1,    -1,   327,   231,   232,   233,   234,    52,    -1,   101,
     101,   102,   338,    35,    36,    37,    -1,    -1,   334,    -1,
     345,    -1,    -1,    -1,   334,    -1,   334,    -1,   316,   317,
      -1,    -1,    33,    34,    35,    36,    37,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,   341,    -1,   343,   344,   307,   346,   347,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,   321,    -1,    95,    -1,    97,    -1,   327,    -1,   367,
     368,   369,   370,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    95,    -1,    97,    -1,   348,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   334,    -1,    -1,    -1,
     338,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,     0,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    -1,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    -1,    -1,   101,   102,
     103,   104,   105,   106,   107,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    90,    91,    92,
      -1,    -1,    95,    -1,    97,   103,   104,   105,   106,   107,
      -1,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    33,    34,
      35,    36,    37,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    92,    -1,    -1,
      95,    -1,    97,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    53,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,   105,   106,    -1,
      -1,    49,    43,    51,    52,    -1,    -1,    48,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    88,    89,    90,
      91,    92,    -1,    -1,    95,    -1,    97,   105,   106,    -1,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,   105,   106,    -1,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    88,    89,    90,
      91,    92,    -1,    -1,    95,    -1,    97,   105,   106,    -1,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,
      -1,    49,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    93,    94,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    -1,   105,   106,    -1,
      -1,    49,    -1,    -1,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    12,    13,    14,    15,    16,    17,    18,    -1,
      20,    21,    22,    86,    87,    88,    89,    90,    91,    92,
      -1,    -1,    95,    -1,    97,    93,    94,    -1,    -1,    33,
      34,    35,    36,    37,    -1,    -1,    -1,   105,   106,    49,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    57,    58,    59,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      12,    13,    14,    15,    16,    17,    18,    -1,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    89,    90,    91,    92,    -1,
      -1,    95,    -1,    97,    -1,   105,   106,    49,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    57,    58,    59,    33,    34,
      35,    36,    37,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    33,    34,    35,    36,    37,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    -1,
      95,    -1,    97,    -1,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    -1,    95,    -1,    97,    33,
      34,    35,    36,    37,    -1,    -1,    40,    -1,    42,    43,
      44,    45,    46,    47,    48,    33,    34,    35,    36,    37,
      -1,    -1,    40,    -1,    42,    43,    44,    45,    46,    47,
      48,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      -1,    95,    -1,    97,    -1,    -1,    -1,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    -1,    95,    -1,    97,
      -1,    -1,    -1,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    -1,    95,    -1,    97,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    89,    90,    91,    92,    32,    -1,    95,    -1,
      97,    -1,    38,    -1,    -1,    -1,    -1,    88,    89,    90,
      91,    92,    -1,    -1,    95,    -1,    97,    32,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    -1,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    -1,    80,    81,    82
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    24,    27,    29,    49,    51,    52,    57,    58,    59,
      62,    93,    94,   103,   104,   105,   106,   107,   109,   112,
     113,   114,   115,   120,   121,   122,   123,   124,   125,   128,
     132,   133,   134,   136,   137,   138,   139,   140,   141,   142,
     145,   146,   147,   150,   151,   152,   153,   154,    32,    32,
     122,   122,    18,   126,   127,    50,   122,   117,    53,   122,
      18,   151,   151,    18,    18,    18,     0,    51,    55,   114,
      18,    56,   110,    51,    55,   151,    23,    19,    23,   121,
     123,    54,    54,    93,    94,   151,    98,    98,    96,    98,
     148,   149,    32,    38,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,   149,    32,    38,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    80,    81,    82,    33,    34,    35,    36,
      37,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      95,    97,   121,   121,    25,    28,    31,    18,    30,    28,
      31,    55,   101,   102,    50,   121,    53,    32,   116,   110,
      51,    32,   119,    18,    19,    50,   122,   129,   130,   131,
      50,   129,   130,   133,   139,   152,   133,   115,   125,   128,
     132,   134,   135,   138,   139,   143,   144,   152,   154,   135,
     144,    96,    98,    96,    98,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   138,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   138,   121,   121,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   121,   121,   121,    30,   122,   121,
     121,   126,   122,   130,   121,   121,   118,   111,   121,   122,
      50,    55,   130,    50,    55,   131,    50,    55,   130,    50,
      93,    94,   132,   143,   134,   144,   144,   132,   134,   135,
     135,    26,   122,    28,    31,   102,    28,    31,   101,   121,
     121,   122,   130,    50,   131,   130,    50,   132,   121,   121,
     121,   130,   121,   121,   122,    50,    50,    28,    31,    28,
      31,   121,   121,   121,   121
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   109,   109,   110,   111,   110,   110,
     113,   112,   112,   114,   114,   116,   115,   117,   115,   118,
     115,   119,   115,   120,   120,   121,   122,   122,   123,   123,
     124,   124,   124,   125,   125,   126,   126,   127,   127,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   129,
     129,   130,   130,   130,   131,   132,   132,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   134,   134,   134,
     134,   135,   135,   136,   136,   136,   137,   137,   138,   138,
     139,   139,   139,   140,   140,   140,   141,   142,   143,   143,
     143,   143,   143,   144,   144,   145,   145,   146,   146,   147,
     148,   148,   148,   148,   149,   149,   149,   149,   149,   150,
     150,   150,   150,   150,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   154,   154
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     0,     4,     1,
       0,     2,     3,     2,     3,     0,     4,     0,     3,     0,
       5,     0,     4,     1,     2,     1,     1,     1,     2,     2,
       1,     2,     2,     4,     4,     3,     4,     1,     3,     4,
       6,     6,     8,     8,     4,     6,     6,     8,     8,     1,
       3,     1,     3,     2,     2,     1,     1,     3,     4,     4,
       6,     5,     3,     4,     4,     6,     5,     1,     1,     2,
       2,     1,     2,     1,     1,     1,     3,     3,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     1,     1,     2,
       2,     3,     2,     3,     2,     3,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     3,     2,     1,     1,     1,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     6
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const yytype_int8 yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       0,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const yytype_int8 yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const yytype_int16 yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,     0,     0,     0,     0,
       0,     0,     0,    98,     0,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   441,     0,   443,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   712,     0,   714,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   716,     0,   718,
     762,     0,   764,     0,     0,     0,     0,     0,    96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   882,   884,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   389,   391,   393,   395,   397,     0,   399,   401,
     403,   405,   407,   409,   411,   413,   415,   417,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   419,   421,   423,   425,   427,   429,   431,
     433,   435,     0,     0,   437,     0,   439,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   102,     0,     0,
     104,   106,   108,   110,   112,   114,   116,   118,   120,   122,
     124,   126,   128,   130,   132,   134,   136,   138,   140,   142,
     144,   146,   148,   150,   152,   154,   156,     0,   158,   160,
     162,   164,   166,   168,   170,   172,   174,   176,   178,   180,
     182,   184,   186,   188,   190,   192,   194,   196,   198,   200,
     202,     0,   204,   206,   208,   210,   212,     0,     0,   214,
     216,   218,   220,   222,   224,   226,   228,   230,   232,   234,
     236,   238,   240,   242,   244,   246,   248,   250,   252,   254,
       0,   256,   258,   260,   262,   264,   266,   268,   270,   272,
     274,   276,   278,   280,   283,   285,     0,     0,   289,   291,
     293,   295,   297,   299,   301,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     504,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     506,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,    17,    19,    21,    23,
      25,    27,    29,    31,    33,    35,    37,    39,    41,    43,
      45,     0,    48,    50,    52,     0,    54,     0,     0,    56,
       0,    58,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    60,     0,    62,    64,     0,     0,     0,    66,    68,
      70,    72,     0,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,    78,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    82,    84,    86,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   508,   510,   512,   514,   516,
     518,   520,   522,   524,   526,   528,   530,   532,   534,   536,
     538,     0,   540,   542,   544,     0,   546,     0,     0,   548,
       0,   550,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   552,     0,   554,   556,     0,     0,     0,   558,   560,
     562,   564,     0,     0,   566,   582,   584,   586,   588,   590,
     592,   594,   596,   598,   600,   602,   604,   606,   608,   610,
     612,     0,   614,   616,   618,     0,   620,     0,     0,   622,
       0,   624,     0,     0,     0,   568,   570,     0,     0,     0,
       0,     0,     0,     0,     0,   572,   574,   576,   578,   580,
       0,   626,     0,   628,   630,     0,     0,     0,   632,   634,
     636,   638,     0,     0,   640,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     896,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   642,   644,     0,     0,     0,
       0,     0,     0,     0,     0,   646,   648,   650,   652,   654,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     898,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     446,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     448,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     450,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     720,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     722,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     724,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     726,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     728,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     730,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     732,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     734,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     736,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     738,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     740,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     742,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     744,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     746,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     748,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     750,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     752,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     754,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     756,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     758,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     760,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     766,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     768,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     770,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     772,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     774,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     776,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     778,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     780,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     782,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     784,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     786,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     788,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     790,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     792,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     794,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     796,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     798,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     800,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     802,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     804,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     806,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     808,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     810,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     812,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     814,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     816,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     818,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     820,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     822,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     824,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     826,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     828,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     830,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     832,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     834,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     836,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     838,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     840,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     842,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     844,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     846,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     848,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     850,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     852,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     854,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     856,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     858,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     860,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     862,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     864,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     866,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     868,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     870,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     872,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     874,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     876,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     878,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     890,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     892,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     894,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     902,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     904,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     906,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     908,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     910,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     912,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     914,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     916,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     918,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     920,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     708,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     710,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     880,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     886,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     888,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     900,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   452,   454,
     456,   458,   460,     0,   462,   464,   466,   468,   470,   472,
     474,   476,   478,   480,   656,   658,   660,   662,   664,     0,
     666,   668,   670,   672,   674,   676,   678,   680,   682,   684,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   482,
     484,   486,   488,   490,   492,   494,   496,   498,     0,     0,
     500,     0,   502,     0,     0,   686,   688,   690,   692,   694,
     696,   698,   700,   702,     0,     0,   704,     0,   706,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   303,     0,     0,     0,
       0,     0,   305,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   347,     0,     0,
       0,     0,     0,   349,     0,     0,     0,   307,   309,   311,
     313,   315,   317,   319,   321,   323,   325,   327,   329,   331,
     333,   335,   337,   339,   341,   343,   345,     0,   351,   353,
     355,   357,   359,   361,   363,   365,   367,   369,   371,   373,
     375,   377,   379,   381,     0,   383,   385,   387
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,    10,     0,    10,     0,    10,     0,    10,     0,    10,
       0,    10,     0,    10,     0,    25,     0,    25,     0,    25,
       0,    25,     0,    25,     0,    25,     0,    25,     0,    25,
       0,    25,     0,    25,     0,    25,     0,    25,     0,    25,
       0,    25,     0,    25,     0,    10,    25,     0,    25,     0,
      25,     0,    25,     0,    25,     0,    25,     0,    25,     0,
      25,     0,    25,     0,    25,     0,    25,     0,    25,     0,
      25,     0,    25,     0,    25,     0,    25,     0,    25,     0,
      25,     0,    25,     0,    25,     0,    25,     0,    25,     0,
      10,     0,    78,     0,    10,     0,    79,     0,   116,     0,
     116,     0,   115,     0,   115,     0,   115,     0,   115,     0,
     115,     0,   115,     0,   115,     0,   115,     0,   115,     0,
     115,     0,   115,     0,   115,     0,   115,     0,   115,     0,
     115,     0,   115,     0,   115,     0,   115,     0,   115,     0,
     115,     0,   115,     0,   115,     0,   115,     0,   115,     0,
     115,     0,   115,     0,   115,     0,   115,     0,   115,     0,
     115,     0,   115,     0,   115,     0,   115,     0,   115,     0,
     115,     0,   115,     0,   115,     0,   115,     0,   115,     0,
     115,     0,   115,     0,   115,     0,   115,     0,   115,     0,
     115,     0,   115,     0,   115,     0,   115,     0,   115,     0,
     115,     0,   115,     0,   115,     0,   115,     0,   115,     0,
     115,     0,   115,     0,   115,     0,   115,     0,   115,     0,
     115,     0,   115,     0,   115,     0,   115,     0,   115,     0,
     115,     0,   115,     0,   115,     0,   115,     0,   115,     0,
     115,     0,   115,     0,   115,     0,   115,     0,   115,     0,
     115,     0,   115,     0,   115,     0,   115,     0,   115,     0,
     115,     0,   115,     0,   115,     0,   115,     0,   115,     0,
     115,     0,   115,     0,   115,     0,   115,     0,   115,     0,
      95,   115,     0,   115,     0,    75,    95,   115,     0,   115,
       0,   115,     0,   115,     0,   115,     0,   115,     0,   115,
       0,   115,     0,   118,     0,   118,     0,   118,     0,   118,
       0,   118,     0,   118,     0,   118,     0,   118,     0,   118,
       0,   118,     0,   118,     0,   118,     0,   118,     0,   118,
       0,   118,     0,   118,     0,   118,     0,   118,     0,   118,
       0,   118,     0,   118,     0,   118,     0,   119,     0,   119,
       0,   119,     0,   119,     0,   119,     0,   119,     0,   119,
       0,   119,     0,   119,     0,   119,     0,   119,     0,   119,
       0,   119,     0,   119,     0,   119,     0,   119,     0,   119,
       0,   119,     0,   119,     0,   119,     0,   119,     0,    23,
       0,    23,     0,    23,     0,    23,     0,    23,     0,    23,
       0,    23,     0,    23,     0,    23,     0,    23,     0,    23,
       0,    23,     0,    23,     0,    23,     0,    23,     0,    23,
       0,    23,     0,    23,     0,    23,     0,    23,     0,    23,
       0,    23,     0,    23,     0,    23,     0,    23,     0,    23,
       0,   114,     0,    97,   114,     0,    10,     0,    10,     0,
      10,     0,    24,     0,    24,     0,    24,     0,    24,     0,
      24,     0,    24,     0,    24,     0,    24,     0,    24,     0,
      24,     0,    24,     0,    24,     0,    24,     0,    24,     0,
      24,     0,    24,     0,    24,     0,    24,     0,    24,     0,
      24,     0,    24,     0,    24,     0,    24,     0,    24,     0,
      24,     0,    24,     0,    10,     0,    10,     0,    69,     0,
      69,     0,    69,     0,    69,     0,    69,     0,    69,     0,
      69,     0,    69,     0,    69,     0,    69,     0,    69,     0,
      69,     0,    69,     0,    69,     0,    69,     0,    69,     0,
      69,     0,    69,     0,    69,     0,    69,     0,    69,     0,
      69,     0,    69,     0,    69,     0,    69,     0,    69,     0,
      69,     0,    69,     0,    69,     0,    69,     0,    69,     0,
      69,     0,    69,     0,    69,     0,    69,     0,    69,     0,
      69,     0,    70,     0,    70,     0,    70,     0,    70,     0,
      70,     0,    70,     0,    70,     0,    70,     0,    70,     0,
      70,     0,    70,     0,    70,     0,    70,     0,    70,     0,
      70,     0,    70,     0,    70,     0,    70,     0,    70,     0,
      70,     0,    70,     0,    70,     0,    70,     0,    70,     0,
      70,     0,    70,     0,    70,     0,    70,     0,    70,     0,
      70,     0,    70,     0,    70,     0,    70,     0,    70,     0,
      70,     0,    70,     0,    70,     0,   120,     0,   120,     0,
     120,     0,   120,     0,   120,     0,   120,     0,   120,     0,
     120,     0,   120,     0,   120,     0,   120,     0,   120,     0,
     120,     0,   120,     0,   120,     0,   120,     0,   120,     0,
     120,     0,   120,     0,   120,     0,   120,     0,   120,     0,
     120,     0,   120,     0,   120,     0,   120,     0,    10,     0,
      10,     0,   108,     0,   108,     0,    96,     0,    96,     0,
      10,     0,    10,     0,    10,     0,    10,     0,    10,     0,
      10,     0,    10,     0,    10,     0,    10,     0,    10,     0,
      10,     0,    10,     0,    10,     0,    10,     0,    10,     0,
      10,     0,    10,     0,    10,     0,    10,     0,    10,     0,
      10,     0,    99,     0,    99,     0,    10,     0,    10,     0,
      10,     0,    10,     0,    10,     0,    10,     0,    10,     0,
      10,     0,    10,     0,    10,     0,    10,     0,    10,     0,
      10,     0,    10,     0,    10,     0,    10,     0,    10,     0,
      10,     0,    10,     0,    10,     0,    10,     0,    10,     0,
      10,     0,    10,     0,    10,     0,    10,     0,    10,     0,
      10,     0,    10,     0,    10,     0,    10,     0,    10,     0,
      10,     0,    10,     0,    10,     0,    10,     0,    10,     0,
      10,     0,    10,     0,    10,     0,    10,     0,    10,     0,
      10,     0,    10,     0,    10,     0,    10,     0,    10,     0,
      10,     0,    10,     0,    10,     0,    10,     0,    10,     0,
      10,     0,    10,     0,    10,     0,    10,     0,    10,     0,
      10,     0,    75,     0,    73,     0,    10,     0,    10,     0,
      10,     0,    10,     0,    10,     0,    10,     0,    10,     0,
      10,     0,    10,     0,    10,     0,    10,     0,    10,     0,
      10,     0,    10,     0,    10,     0,    10,     0,    10,     0,
      10,     0
};




#undef yynerrs
#define yynerrs (yystackp->yyerrcnt)
#undef yychar
#define yychar (yystackp->yyrawchar)
#undef yylval
#define yylval (yystackp->yyval)
#undef yylloc
#define yylloc (yystackp->yyloc)
#define bisonparserV3_nerrs yynerrs
#define bisonparserV3_char yychar
#define bisonparserV3_lval yylval
#define bisonparserV3_lloc yylloc

enum { YYENOMEM = -2 };

typedef enum { yyok, yyaccept, yyabort, yyerr, yynomem } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif

/** State numbers. */
typedef int yy_state_t;

/** Rule numbers. */
typedef int yyRuleNum;

/** Item references. */
typedef short yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState
{
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yyval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yy_state_t yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  YYPTRDIFF_T yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  nonterminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yyval;
  } yysemantics;
};

struct yyGLRStateSet
{
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  YYPTRDIFF_T yysize;
  YYPTRDIFF_T yycapacity;
};

struct yySemanticOption
{
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;


  int yyerrcnt;
  int yyrawchar;
  YYSTYPE yyval;

  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  YYPTRDIFF_T yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

_Noreturn static void
yyFail (yyGLRStack* yystackp, void *scanner, struct _parseParams *params, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (scanner, params, yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

_Noreturn static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

/** Accessing symbol of state YYSTATE.  */
static inline yysymbol_kind_t
yy_accessing_symbol (yy_state_t yystate)
{
  return YY_CAST (yysymbol_kind_t, yystos[yystate]);
}

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LONG_LITERAL",
  "INLET", "INTINLET", "RATINLET", "FLOATINLET", "PITCHINLET", "OUTLET",
  "DIRINLET", "DIROUTLET", "RAT_LITERAL", "DOUBLE_LITERAL",
  "PITCH_LITERAL", "SYMBOL_LITERAL", "GLOBALVAR", "PATCHERVAR", "LOCALVAR",
  "NAMEDPARAM", "BIF", "OF", "MAXFUNCTION", "NULLIFY", "IF_KW", "THEN_KW",
  "ELSE_KW", "WHILE_KW", "DO_KW", "FOR_KW", "IN_KW", "COLLECT_KW",
  "ASSIGN", "PLUS", "MINUS", "TIMES", "DIV", "DIVDIV", "APLUS", "LOGOR",
  "LOGAND", "LOGOREXT", "LOGANDEXT", "EQUAL", "LT", "GT", "LEQ", "GEQ",
  "NEQ", "OPEN", "CLOSEDROUND", "FUNDEF", "PUSH", "POP", "STARTPARAMS",
  "COMMA", "ELLIPSIS", "BACHNULL", "BACHNIL", "ARGCOUNT", "EOL",
  "UNRECOGNIZED", "LIFT", "AMINUS", "ATIMES", "APOWOP", "ADIV", "ADIVDIV",
  "AREM", "ABITAND", "ABITXOR", "ABITOR", "ALSHIFT", "ARSHIFT", "ALOGAND",
  "ALOGANDEXT", "ALOGXOR", "ALOGOR", "ALOGOREXT", "ANTHOP", "AAPPLY",
  "ACONCAT", "ARCONCAT", "CONCAT", "LOGXOR", "BITOR", "BITXOR", "BITAND",
  "REPEAT", "RANGE", "LSHIFT", "RSHIFT", "REM", "UPLUS", "UMINUS", "POWOP",
  "NTHOP", "PICKOP", "APPLY", "ACCESS_UNWRAP", "LVALUESTEPPARAMS", "AS_KW",
  "WITH_KW", "LOGNOT", "BITNOT", "KEEP", "UNKEEP", "INIT", "$accept",
  "program", "funarg", "$@1", "funargList", "$@2", "liftedargList",
  "fundef", "$@3", "$@4", "$@5", "$@6", "listVector", "list", "sequence",
  "nullified", "nullifiedSequence", "whileloop", "forarg", "forargList",
  "forloop", "argsByPositionList", "argsByNameList", "argByName",
  "itemOrVar", "simpleFuncall", "sign", "lvalueSpecsItem", "dataflowHead",
  "dataflowFuncall", "funcall", "var", "localVar", "globalVar",
  "patcherVar", "lvalueSpecsUFinal", "lvalueSpecsFinal", "lvalue",
  "fakeLvalueHead", "fakeLvalue", "lvalueSpecsNonFinalized", "lvalueSpecs",
  "listEnd", "expr", "item", "assignment", "conditional", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yysymbol_kind_t
yylhsNonterm (yyRuleNum yyrule)
{
  return YY_CAST (yysymbol_kind_t, yyr1[yyrule]);
}

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YY_FPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_FPRINTF_

# define YY_FPRINTF_(Args)                      \
  do {                                          \
    YYFPRINTF Args;                             \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)

# define YY_DPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_DPRINTF_

# define YY_DPRINTF_(Args)                      \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)





/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *scanner, struct _parseParams *params)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (scanner);
  YY_USE (params);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *scanner, struct _parseParams *params)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, scanner, params);
  YYFPRINTF (yyo, ")");
}

# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YY_FPRINTF ((stderr, "%s ", Title));                            \
        yy_symbol_print (stderr, Kind, Value, scanner, params);        \
        YY_FPRINTF ((stderr, "\n"));                                    \
      }                                                                 \
  } while (0)

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule, void *scanner, struct _parseParams *params);

# define YY_REDUCE_PRINT(Args)          \
  do {                                  \
    if (yydebug)                        \
      yy_reduce_print Args;             \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

static void yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
  YY_ATTRIBUTE_UNUSED;
static void yypdumpstack (yyGLRStack* yystackp)
  YY_ATTRIBUTE_UNUSED;

#else /* !YYDEBUG */

# define YY_DPRINTF(Args) do {} while (yyfalse)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_REDUCE_PRINT(Args)

#endif /* !YYDEBUG */

#ifndef yystrlen
# define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) YY_ATTRIBUTE_UNUSED;
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if YYDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yyval = s->yysemantics.yyval;
      else
        /* The effect of using yyval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}


/** If yychar is empty, fetch the next token.  */
static inline yysymbol_kind_t
yygetToken (int *yycharp, yyGLRStack* yystackp, void *scanner, struct _parseParams *params)
{
  yysymbol_kind_t yytoken;
  YY_USE (scanner);
  YY_USE (params);
  if (*yycharp == YYEMPTY)
    {
      YY_DPRINTF ((stderr, "Reading a token\n"));
      *yycharp = yylex (&yylval, scanner, params);
    }
  if (*yycharp <= YYEOF)
    {
      *yycharp = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YY_DPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (*yycharp);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }
  return yytoken;
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     YY_ATTRIBUTE_UNUSED;
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT, yynomem for YYNOMEM.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyrule, int yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp, YYPTRDIFF_T yyk,
              YYSTYPE* yyvalp, void *scanner, struct _parseParams *params)
{
  const yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
  int yylow = 1;
  YY_USE (yyvalp);
  YY_USE (scanner);
  YY_USE (params);
  YY_USE (yyk);
  YY_USE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYNOMEM
# define YYNOMEM return yynomem
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, (N), yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (scanner, params, YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yyval;
  /* If yyk == -1, we are running a deferred action on a temporary
     stack.  In that case, YY_REDUCE_PRINT must not play with YYFILL,
     so pretend the stack is "normal". */
  YY_REDUCE_PRINT ((yynormal || yyk == -1, yyvsp, yyk, yyrule, scanner, params));
  switch (yyrule)
    {
  case 2: /* program: %empty  */
#line 203 "bisonparserV3.y"
                {
    params->ast = new astConst(llll_get(), params->owner);
    *params->codeac = -1;
    code_dev_post ("parse: empty program\n");
}
#line 4010 "bisonparserV3.tab.c"
    break;

  case 3: /* program: NAMEDPARAM  */
#line 208 "bisonparserV3.y"
             {
    params->ast = new astConst(llll_get(), params->owner);
    *params->codeac = 0;
    code_dev_post ("parse: NAMEDPARAM: empty program\n");
    YYACCEPT;
}
#line 4021 "bisonparserV3.tab.c"
    break;

  case 4: /* program: sequence  */
#line 214 "bisonparserV3.y"
           {
    params->ast = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue);
    *params->codeac = -1;
    code_dev_post("codeac: %ld", *params->codeac);
    code_dev_post ("parse: sequence: program\n");
}
#line 4032 "bisonparserV3.tab.c"
    break;

  case 5: /* program: sequence NAMEDPARAM  */
#line 220 "bisonparserV3.y"
                      {
    params->ast = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeValue);
    code_dev_post("codeac: %ld", *params->codeac);
    code_dev_post ("parse: sequence NAMEDPARAM: program\n");
    YYACCEPT;
}
#line 4043 "bisonparserV3.tab.c"
    break;

  case 6: /* funarg: LOCALVAR  */
#line 230 "bisonparserV3.y"
                 {
    ((*yyvalp).funArgValue) = new funArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue));
}
#line 4051 "bisonparserV3.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 233 "bisonparserV3.y"
                  {
    *++(params->localVariablesStackV) = new std::vector<t_localVar>;
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
}
#line 4060 "bisonparserV3.tab.c"
    break;

  case 8: /* funarg: LOCALVAR ASSIGN $@1 list  */
#line 236 "bisonparserV3.y"
       {
    ((*yyvalp).funArgValue) = new funArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.symValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), *(params->localVariablesStackV));
    delete *(params->localVariablesAuxMapStack);
    *(params->localVariablesAuxMapStack--) = nullptr;
    delete *(params->localVariablesStackV);
    *(params->localVariablesStackV--) = nullptr;
}
#line 4072 "bisonparserV3.tab.c"
    break;

  case 9: /* funarg: ELLIPSIS  */
#line 243 "bisonparserV3.y"
           {
    ((*yyvalp).funArgValue) = new funArg(gensym("<...>"));
}
#line 4080 "bisonparserV3.tab.c"
    break;

  case 10: /* $@2: %empty  */
#line 252 "bisonparserV3.y"
            {
    *++(params->localVariablesStackV) = new std::vector<t_localVar>;
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
}
#line 4089 "bisonparserV3.tab.c"
    break;

  case 11: /* funargList: $@2 funarg  */
#line 255 "bisonparserV3.y"
         {
    auto v = new std::vector<funArg*>;
    v->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.funArgValue));
    ((*yyvalp).funArgVector) = v;
}
#line 4099 "bisonparserV3.tab.c"
    break;

  case 12: /* funargList: funargList COMMA funarg  */
#line 260 "bisonparserV3.y"
                          {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.funArgVector)->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.funArgValue));
    ((*yyvalp).funArgVector) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.funArgVector);
}
#line 4108 "bisonparserV3.tab.c"
    break;

  case 13: /* liftedargList: LIFT LOCALVAR  */
#line 268 "bisonparserV3.y"
                              {
    auto v = new std::vector<t_localVar*>;
    auto l = new t_localVar((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue));
    v->push_back(l);
    ((*yyvalp).localVarVector) = v;
    code_dev_post ("parse: liftedargList (first term)\n");
}
#line 4120 "bisonparserV3.tab.c"
    break;

  case 14: /* liftedargList: liftedargList COMMA LOCALVAR  */
#line 275 "bisonparserV3.y"
                               {
    auto l = new t_localVar((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue));
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.localVarVector)->push_back(l);
    ((*yyvalp).localVarVector) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.localVarVector);
    code_dev_post ("parse: liftedargList (subsequent term)\n");
}
#line 4131 "bisonparserV3.tab.c"
    break;

  case 15: /* $@3: %empty  */
#line 285 "bisonparserV3.y"
                           {
    params->fnDepth++;
    *++(params->liftedVariablesStack) = new std::unordered_set<t_symbol *>;
    *++(params->argumentsStackV) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.funArgVector);
}
#line 4141 "bisonparserV3.tab.c"
    break;

  case 16: /* fundef: funargList FUNDEF $@3 list  */
#line 289 "bisonparserV3.y"
       {
    t_function *fn = new t_userFunction(*(params->argumentsStackV), *(params->localVariablesStackV), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    params->funcs->insert(fn);
    ((*yyvalp).astNodeValue) = new astConst(fn, params->owner);
    *(params->localVariablesStackV--) = nullptr;
    --(params->fnDepth);
    delete *(params->localVariablesAuxMapStack);
    *(params->localVariablesAuxMapStack--) = nullptr;
    delete *(params->liftedVariablesStack);
    *(params->liftedVariablesStack--) = nullptr;
    --(params->argumentsStackV);
    code_dev_post ("parse: user defined function funargList FUNDEF");
}
#line 4159 "bisonparserV3.tab.c"
    break;

  case 17: /* $@4: %empty  */
#line 302 "bisonparserV3.y"
         {
    ++(params->localVariablesStackV);
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
    *++(params->liftedVariablesStack) = new std::unordered_set<t_symbol *>;
    params->fnDepth++;
    *++(params->argumentsStackV) = nullptr;
}
#line 4171 "bisonparserV3.tab.c"
    break;

  case 18: /* fundef: FUNDEF $@4 list  */
#line 308 "bisonparserV3.y"
       {
    t_function *fn = new t_userFunction(*(params->argumentsStackV), *(params->localVariablesStackV), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    params->funcs->insert(fn);
    ((*yyvalp).astNodeValue) = new astConst(fn, params->owner);
    *(params->localVariablesStackV--) = nullptr;;
    --(params->fnDepth);
    delete *(params->localVariablesAuxMapStack);
    *(params->localVariablesAuxMapStack--) = nullptr;
    delete *(params->liftedVariablesStack);
    *(params->liftedVariablesStack--) = nullptr;
    --(params->argumentsStackV);
    code_dev_post ("parse: user defined function FUNDEF");
}
#line 4189 "bisonparserV3.tab.c"
    break;

  case 19: /* $@5: %empty  */
#line 321 "bisonparserV3.y"
                                  {
    params->fnDepth++;
    *++(params->liftedVariablesStack) = new std::unordered_set<t_symbol *>;
    for (auto v : *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.localVarVector)) {
        (*(params->liftedVariablesStack))->insert(v->getName());
    }
    *++(params->argumentsStackV) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.funArgVector);
}
#line 4202 "bisonparserV3.tab.c"
    break;

  case 20: /* fundef: funargList liftedargList FUNDEF $@5 list  */
#line 328 "bisonparserV3.y"
       {
    t_function *fn = new t_userFunction(*(params->argumentsStackV), *(params->localVariablesStackV), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    params->funcs->insert(fn);
    ((*yyvalp).astNodeValue) = new astConst(fn, params->owner);
    *(params->localVariablesStackV--) = nullptr;
    --(params->fnDepth);
    delete *(params->localVariablesAuxMapStack);
    *(params->localVariablesAuxMapStack--) = nullptr;
    delete *(params->liftedVariablesStack);
    *(params->liftedVariablesStack--) = nullptr;
    --(params->argumentsStackV);
    code_dev_post ("parse: user defined function funargList liftedargList");
}
#line 4220 "bisonparserV3.tab.c"
    break;

  case 21: /* $@6: %empty  */
#line 341 "bisonparserV3.y"
                       {
    params->fnDepth++;
    ++(params->localVariablesStackV);
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
    *++(params->liftedVariablesStack) = new std::unordered_set<t_symbol *>;
    *++(params->argumentsStackV) = nullptr;
    for (auto v : *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.localVarVector)) {
        (*(params->liftedVariablesStack))->insert(v->getName());
    }
}
#line 4235 "bisonparserV3.tab.c"
    break;

  case 22: /* fundef: liftedargList FUNDEF $@6 list  */
#line 350 "bisonparserV3.y"
       {
    t_function *fn = new t_userFunction(*++(params->argumentsStackV), *(params->localVariablesStackV), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    params->funcs->insert(fn);
    ((*yyvalp).astNodeValue) = new astConst(fn, params->owner);
    *(params->localVariablesStackV--) = nullptr;;
    --(params->fnDepth);
    delete *(params->localVariablesAuxMapStack);
    *(params->localVariablesAuxMapStack--) = nullptr;
    delete *(params->liftedVariablesStack);
    *(params->liftedVariablesStack--) = nullptr;
    --(params->argumentsStackV);
    code_dev_post ("parse: user defined function liftedargList FUNDEF");
}
#line 4253 "bisonparserV3.tab.c"
    break;

  case 23: /* listVector: expr  */
#line 367 "bisonparserV3.y"
                 {
    auto v = new std::vector<astNode*>;
    v->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    ((*yyvalp).astNodeVector) = v;
}
#line 4263 "bisonparserV3.tab.c"
    break;

  case 24: /* listVector: listVector expr  */
#line 372 "bisonparserV3.y"
                  {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeVector)->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    ((*yyvalp).astNodeVector) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeVector);
}
#line 4272 "bisonparserV3.tab.c"
    break;

  case 25: /* list: listVector  */
#line 380 "bisonparserV3.y"
                 {
    ((*yyvalp).astNodeValue) = new astConcat((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeVector), params->owner);
}
#line 4280 "bisonparserV3.tab.c"
    break;

  case 27: /* sequence: nullifiedSequence  */
#line 388 "bisonparserV3.y"
                    {
    ((*yyvalp).astNodeValue) = new astConcat((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeVector), params->owner);
}
#line 4288 "bisonparserV3.tab.c"
    break;

  case 28: /* nullified: list NULLIFY  */
#line 395 "bisonparserV3.y"
                        {
    ((*yyvalp).astNodeValue) = new astNullify((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeValue), params->owner);
}
#line 4296 "bisonparserV3.tab.c"
    break;

  case 30: /* nullifiedSequence: nullified  */
#line 403 "bisonparserV3.y"
                             {
    auto v = new std::vector<astNode*>;
    v->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    ((*yyvalp).astNodeVector) = v;
}
#line 4306 "bisonparserV3.tab.c"
    break;

  case 31: /* nullifiedSequence: nullifiedSequence nullified  */
#line 408 "bisonparserV3.y"
                              {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeVector)->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    ((*yyvalp).astNodeVector) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeVector);
}
#line 4315 "bisonparserV3.tab.c"
    break;

  case 32: /* nullifiedSequence: nullifiedSequence list  */
#line 412 "bisonparserV3.y"
                         {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeVector)->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    ((*yyvalp).astNodeVector) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeVector);
}
#line 4324 "bisonparserV3.tab.c"
    break;

  case 33: /* whileloop: WHILE_KW sequence DO_KW list  */
#line 420 "bisonparserV3.y"
                                         {
    ((*yyvalp).astNodeValue) = new astWhileLoop<E_LOOP_DO>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: while...do\n");
}
#line 4333 "bisonparserV3.tab.c"
    break;

  case 34: /* whileloop: WHILE_KW sequence COLLECT_KW list  */
#line 424 "bisonparserV3.y"
                                    {
    ((*yyvalp).astNodeValue) = new astWhileLoop<E_LOOP_COLLECT>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: while...collect\n");
}
#line 4342 "bisonparserV3.tab.c"
    break;

  case 35: /* forarg: LOCALVAR IN_KW sequence  */
#line 432 "bisonparserV3.y"
                                 {
    ((*yyvalp).forArgValue) = new forArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.symValue), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    addVariableToScope<e_flexBisonV3>(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.symValue));
    code_dev_post ("parse: for iterator with index");
}
#line 4352 "bisonparserV3.tab.c"
    break;

  case 36: /* forarg: LOCALVAR LOCALVAR IN_KW sequence  */
#line 437 "bisonparserV3.y"
                                   {
    addVariableToScope<e_flexBisonV3>(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.symValue));
    addVariableToScope<e_flexBisonV3>(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.symValue));
    ((*yyvalp).forArgValue) = new forArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.symValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.symValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    code_dev_post ("parse: for iterator with index and address");
}
#line 4363 "bisonparserV3.tab.c"
    break;

  case 37: /* forargList: forarg  */
#line 447 "bisonparserV3.y"
                    {
    auto v = new std::vector<forArg*>;
    v->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.forArgValue));
    ((*yyvalp).forArgVector) = v;
    code_dev_post ("parse: for iterator (first term)\n");
}
#line 4374 "bisonparserV3.tab.c"
    break;

  case 38: /* forargList: forargList COMMA forarg  */
#line 453 "bisonparserV3.y"
                          {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.forArgVector)->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.forArgValue));
    ((*yyvalp).forArgVector) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.forArgVector);
    code_dev_post ("parse: for iterator (subsequent term)\n");
}
#line 4384 "bisonparserV3.tab.c"
    break;

  case 39: /* forloop: FOR_KW forargList DO_KW list  */
#line 463 "bisonparserV3.y"
{
    ((*yyvalp).astNodeValue) = new astForLoop<E_LOOP_DO>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.forArgVector), nullptr, nullptr, nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: FOR_KW forargList DO_KW list\n");
}
#line 4393 "bisonparserV3.tab.c"
    break;

  case 40: /* forloop: FOR_KW forargList WITH_KW argsByNameList DO_KW list  */
#line 468 "bisonparserV3.y"
{
    ((*yyvalp).astNodeValue) = new astForLoop<E_LOOP_DO>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.forArgVector), nullptr, nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.symNodePairVector), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: forargList WITH_KW argsByNameList DO_KW list\n");
}
#line 4402 "bisonparserV3.tab.c"
    break;

  case 41: /* forloop: FOR_KW forargList AS_KW sequence DO_KW list  */
#line 473 "bisonparserV3.y"
{
    ((*yyvalp).astNodeValue) = new astForLoop<E_LOOP_DO>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.forArgVector), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: FOR_KW forargList AS_KW sequence DO_KW list\n");
}
#line 4411 "bisonparserV3.tab.c"
    break;

  case 42: /* forloop: FOR_KW forargList AS_KW sequence WITH_KW argsByNameList DO_KW list  */
#line 478 "bisonparserV3.y"
{
    ((*yyvalp).astNodeValue) = new astForLoop<E_LOOP_DO>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.forArgVector), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.symNodePairVector), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: forargList AS_KW sequence WITH_KW argsByNameList DO_KW list\n");
}
#line 4420 "bisonparserV3.tab.c"
    break;

  case 43: /* forloop: FOR_KW forargList WITH_KW argsByNameList AS_KW sequence DO_KW list  */
#line 483 "bisonparserV3.y"
{
    ((*yyvalp).astNodeValue) = new astForLoop<E_LOOP_DO>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.forArgVector), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.symNodePairVector), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: FOR_KW forargList WITH_KW argsByNameList AS_KW sequence DO_KW list\n");
}
#line 4429 "bisonparserV3.tab.c"
    break;

  case 44: /* forloop: FOR_KW forargList COLLECT_KW list  */
#line 488 "bisonparserV3.y"
{
    ((*yyvalp).astNodeValue) = new astForLoop<E_LOOP_COLLECT>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.forArgVector), nullptr, nullptr, nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: FOR_KW forargList COLLECT_KW list\n");
}
#line 4438 "bisonparserV3.tab.c"
    break;

  case 45: /* forloop: FOR_KW forargList WITH_KW argsByNameList COLLECT_KW list  */
#line 493 "bisonparserV3.y"
{
    ((*yyvalp).astNodeValue) = new astForLoop<E_LOOP_COLLECT>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.forArgVector), nullptr, nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.symNodePairVector), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: forargList WITH_KW argsByNameList COLLECT_KW list\n");
}
#line 4447 "bisonparserV3.tab.c"
    break;

  case 46: /* forloop: FOR_KW forargList AS_KW sequence COLLECT_KW list  */
#line 498 "bisonparserV3.y"
{
    ((*yyvalp).astNodeValue) = new astForLoop<E_LOOP_COLLECT>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.forArgVector), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: FOR_KW forargList AS_KW sequence COLLECT_KW list\n");
}
#line 4456 "bisonparserV3.tab.c"
    break;

  case 47: /* forloop: FOR_KW forargList AS_KW sequence WITH_KW argsByNameList COLLECT_KW list  */
#line 503 "bisonparserV3.y"
{
    ((*yyvalp).astNodeValue) = new astForLoop<E_LOOP_COLLECT>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.forArgVector), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.symNodePairVector), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: forargList AS_KW sequence WITH_KW argsByNameList COLLECT_KW list\n");
}
#line 4465 "bisonparserV3.tab.c"
    break;

  case 48: /* forloop: FOR_KW forargList WITH_KW argsByNameList AS_KW sequence COLLECT_KW list  */
#line 508 "bisonparserV3.y"
{
    ((*yyvalp).astNodeValue) = new astForLoop<E_LOOP_COLLECT>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.forArgVector), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.symNodePairVector), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: FOR_KW forargList WITH_KW argsByNameList AS_KW sequence COLLECT_KW list\n");
}
#line 4474 "bisonparserV3.tab.c"
    break;

  case 49: /* argsByPositionList: sequence  */
#line 516 "bisonparserV3.y"
                              {
    auto v = new std::vector<astNode*>;
    v->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    ((*yyvalp).astNodeVector) = v;
    code_dev_post ("parse: argsByPositionList (first term)\n");
}
#line 4485 "bisonparserV3.tab.c"
    break;

  case 50: /* argsByPositionList: argsByPositionList COMMA sequence  */
#line 522 "bisonparserV3.y"
                                    {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeVector)->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    ((*yyvalp).astNodeVector) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeVector);
    code_dev_post ("parse: argsByPositionList (subsequent term)\n");
}
#line 4495 "bisonparserV3.tab.c"
    break;

  case 51: /* argsByNameList: argByName  */
#line 531 "bisonparserV3.y"
                          {
    auto v = new std::vector<symNodePair*>;
    v->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symNodePairValue));
    ((*yyvalp).symNodePairVector) = v;code_dev_post ("parse: argsByNameList (first term)\n");
}
#line 4505 "bisonparserV3.tab.c"
    break;

  case 52: /* argsByNameList: argsByNameList COMMA argByName  */
#line 536 "bisonparserV3.y"
                                 {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.symNodePairVector)->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symNodePairValue));
    ((*yyvalp).symNodePairVector) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.symNodePairVector);
    code_dev_post ("parse: argsByNameList (subsequent term)\n");
}
#line 4515 "bisonparserV3.tab.c"
    break;

  case 53: /* argsByNameList: argsByNameList argByName  */
#line 541 "bisonparserV3.y"
                           {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.symNodePairVector)->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symNodePairValue));
    ((*yyvalp).symNodePairVector) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.symNodePairVector);
    code_dev_post ("parse: argsByNameList (subsequent term)\n");
}
#line 4525 "bisonparserV3.tab.c"
    break;

  case 54: /* argByName: NAMEDPARAM sequence  */
#line 550 "bisonparserV3.y"
                                {
    ((*yyvalp).symNodePairValue) = new symNodePair((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.symValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    code_dev_post ("parse: named parameter %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.symValue)->s_name);
}
#line 4534 "bisonparserV3.tab.c"
    break;

  case 57: /* simpleFuncall: itemOrVar STARTPARAMS CLOSEDROUND  */
#line 564 "bisonparserV3.y"
                                                  {
    ((*yyvalp).astFunctionCallValue) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (std::vector<astNode*>*) nullptr, (std::vector<symNodePair*>*) nullptr, params->owner);
}
#line 4542 "bisonparserV3.tab.c"
    break;

  case 58: /* simpleFuncall: itemOrVar STARTPARAMS argsByPositionList CLOSEDROUND  */
#line 567 "bisonparserV3.y"
                                                       {
    ((*yyvalp).astFunctionCallValue) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeVector), nullptr, params->owner);
}
#line 4550 "bisonparserV3.tab.c"
    break;

  case 59: /* simpleFuncall: itemOrVar STARTPARAMS argsByNameList CLOSEDROUND  */
#line 570 "bisonparserV3.y"
                                                   {
    ((*yyvalp).astFunctionCallValue) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.astNodeValue), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.symNodePairVector), params->owner);
}
#line 4558 "bisonparserV3.tab.c"
    break;

  case 60: /* simpleFuncall: itemOrVar STARTPARAMS argsByPositionList COMMA argsByNameList CLOSEDROUND  */
#line 573 "bisonparserV3.y"
                                                                            {
    ((*yyvalp).astFunctionCallValue) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.astNodeVector), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.symNodePairVector), params->owner);
}
#line 4566 "bisonparserV3.tab.c"
    break;

  case 61: /* simpleFuncall: itemOrVar STARTPARAMS argsByPositionList argsByNameList CLOSEDROUND  */
#line 576 "bisonparserV3.y"
                                                                      {
    ((*yyvalp).astFunctionCallValue) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeVector), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.symNodePairVector), params->owner);
}
#line 4574 "bisonparserV3.tab.c"
    break;

  case 62: /* simpleFuncall: simpleFuncall STARTPARAMS CLOSEDROUND  */
#line 579 "bisonparserV3.y"
                                        {
    ((*yyvalp).astFunctionCallValue) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astFunctionCallValue), (std::vector<astNode*>*) nullptr, (std::vector<symNodePair*>*) nullptr, params->owner);
}
#line 4582 "bisonparserV3.tab.c"
    break;

  case 63: /* simpleFuncall: simpleFuncall STARTPARAMS argsByPositionList CLOSEDROUND  */
#line 582 "bisonparserV3.y"
                                                           {
    ((*yyvalp).astFunctionCallValue) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.astFunctionCallValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeVector), nullptr, params->owner);
}
#line 4590 "bisonparserV3.tab.c"
    break;

  case 64: /* simpleFuncall: simpleFuncall STARTPARAMS argsByNameList CLOSEDROUND  */
#line 585 "bisonparserV3.y"
                                                       {
    ((*yyvalp).astFunctionCallValue) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.astFunctionCallValue), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.symNodePairVector), params->owner);
}
#line 4598 "bisonparserV3.tab.c"
    break;

  case 65: /* simpleFuncall: simpleFuncall STARTPARAMS argsByPositionList COMMA argsByNameList CLOSEDROUND  */
#line 588 "bisonparserV3.y"
                                                                                {
    ((*yyvalp).astFunctionCallValue) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.astFunctionCallValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.astNodeVector), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.symNodePairVector), params->owner);
}
#line 4606 "bisonparserV3.tab.c"
    break;

  case 66: /* simpleFuncall: simpleFuncall STARTPARAMS argsByPositionList argsByNameList CLOSEDROUND  */
#line 591 "bisonparserV3.y"
                                                                           {
    ((*yyvalp).astFunctionCallValue) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.astFunctionCallValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeVector), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.symNodePairVector), params->owner);
}
#line 4614 "bisonparserV3.tab.c"
    break;

  case 67: /* sign: UPLUS  */
#line 598 "bisonparserV3.y"
             {
    ((*yyvalp).longValue) = 1;
}
#line 4622 "bisonparserV3.tab.c"
    break;

  case 68: /* sign: UMINUS  */
#line 601 "bisonparserV3.y"
         {
    ((*yyvalp).longValue) = -1;
}
#line 4630 "bisonparserV3.tab.c"
    break;

  case 69: /* sign: sign UPLUS  */
#line 604 "bisonparserV3.y"
             {
    ((*yyvalp).longValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.longValue);
}
#line 4638 "bisonparserV3.tab.c"
    break;

  case 70: /* sign: sign UMINUS  */
#line 607 "bisonparserV3.y"
              {
    ((*yyvalp).longValue) = -(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.longValue);
}
#line 4646 "bisonparserV3.tab.c"
    break;

  case 72: /* lvalueSpecsItem: sign itemOrVar  */
#line 615 "bisonparserV3.y"
                 {
    if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.longValue) == -1) {
        ((*yyvalp).astNodeValue) = new astOperatorUMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    } else {
        ((*yyvalp).astNodeValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue);
    }
}
#line 4658 "bisonparserV3.tab.c"
    break;

  case 76: /* dataflowFuncall: dataflowHead APPLY simpleFuncall  */
#line 634 "bisonparserV3.y"
                                 {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astFunctionCallValue)->addDataflowStyleArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue));
    ((*yyvalp).astFunctionCallValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astFunctionCallValue);
}
#line 4667 "bisonparserV3.tab.c"
    break;

  case 77: /* dataflowFuncall: dataflowFuncall APPLY simpleFuncall  */
#line 638 "bisonparserV3.y"
                                      {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astFunctionCallValue)->addDataflowStyleArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astFunctionCallValue));
    ((*yyvalp).astFunctionCallValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astFunctionCallValue);
}
#line 4676 "bisonparserV3.tab.c"
    break;

  case 83: /* localVar: LOCALVAR  */
#line 660 "bisonparserV3.y"
                   {
    ((*yyvalp).astLocalVarValue) = new astLocalVar((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue), params->owner);
    addVariableToScope<e_flexBisonV3>(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue));
    code_dev_post ("parse: Local variable %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue)->s_name);
}
#line 4686 "bisonparserV3.tab.c"
    break;

  case 84: /* localVar: KEEP LOCALVAR  */
#line 665 "bisonparserV3.y"
                {
    ((*yyvalp).astLocalVarValue) = new astKeep((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue), params->owner);
    addVariableToScope<e_flexBisonV3>(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue));
    code_dev_post ("parse: Keep local variable %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue)->s_name);
}
#line 4696 "bisonparserV3.tab.c"
    break;

  case 85: /* localVar: UNKEEP LOCALVAR  */
#line 670 "bisonparserV3.y"
                  {
    ((*yyvalp).astLocalVarValue) = new astUnkeep((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue), params->owner);
    addVariableToScope<e_flexBisonV3>(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue));
    code_dev_post ("parse: Unkeep local variable %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue)->s_name);
}
#line 4706 "bisonparserV3.tab.c"
    break;

  case 86: /* globalVar: GLOBALVAR  */
#line 679 "bisonparserV3.y"
                     {
    astGlobalVar *v = new astGlobalVar(params->gvt, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue), params->owner);
    params->globalVariables->insert(v->getVar());
    ((*yyvalp).astGlobalVarValue) = v;
    code_dev_post ("parse: Global variable %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue)->s_name);
}
#line 4717 "bisonparserV3.tab.c"
    break;

  case 87: /* patcherVar: PATCHERVAR  */
#line 689 "bisonparserV3.y"
                       {
    astPatcherVar *v = new astPatcherVar((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue), params->owner);
    (*params->name2patcherVars)[(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue)].insert(v);
    ((*yyvalp).astPatcherVarValue) = v;
    code_dev_post ("parse: Patcher variable %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue)->s_name);
}
#line 4728 "bisonparserV3.tab.c"
    break;

  case 94: /* lvalueSpecsFinal: sign lvalueSpecsUFinal  */
#line 710 "bisonparserV3.y"
                         {
    if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.longValue) == -1) {
        ((*yyvalp).astNodeValue) = new astOperatorUMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    } else {
        ((*yyvalp).astNodeValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue);
    }
}
#line 4740 "bisonparserV3.tab.c"
    break;

  case 95: /* lvalue: var  */
#line 722 "bisonparserV3.y"
    {
    ((*yyvalp).lvalueValue) = new lvalue((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astVarValue), nullptr);
}
#line 4748 "bisonparserV3.tab.c"
    break;

  case 96: /* lvalue: var lvalueSpecs  */
#line 725 "bisonparserV3.y"
                  {
    ((*yyvalp).lvalueValue) = new lvalue((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astVarValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.lvalueSpecsValue));
}
#line 4756 "bisonparserV3.tab.c"
    break;

  case 99: /* fakeLvalue: fakeLvalueHead lvalueSpecs  */
#line 740 "bisonparserV3.y"
                           {
    ((*yyvalp).fakeLvalueValue) = new fakeLvalue((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.lvalueSpecsValue));
}
#line 4764 "bisonparserV3.tab.c"
    break;

  case 100: /* lvalueSpecsNonFinalized: NTHOP lvalueSpecsItem  */
#line 748 "bisonparserV3.y"
                      {
    auto s = new lvalueSpecs;
    auto step = new lvalueStep(lvalueStep::E_LV_NTH, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    s->addStep(step);
    ((*yyvalp).lvalueSpecsValue) = s;
}
#line 4775 "bisonparserV3.tab.c"
    break;

  case 101: /* lvalueSpecsNonFinalized: lvalueSpecs NTHOP lvalueSpecsItem  */
#line 754 "bisonparserV3.y"
                                    {
    auto step = new lvalueStep(lvalueStep::E_LV_NTH, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueSpecsValue)->addStep(step);
    ((*yyvalp).lvalueSpecsValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueSpecsValue);
}
#line 4785 "bisonparserV3.tab.c"
    break;

  case 102: /* lvalueSpecsNonFinalized: APPLY lvalueSpecsItem  */
#line 759 "bisonparserV3.y"
                        {
    auto s = new lvalueSpecs;
    auto step = new lvalueStep(lvalueStep::E_LV_KEY, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    s->addStep(step);
    ((*yyvalp).lvalueSpecsValue) = s;
}
#line 4796 "bisonparserV3.tab.c"
    break;

  case 103: /* lvalueSpecsNonFinalized: lvalueSpecs APPLY lvalueSpecsItem  */
#line 765 "bisonparserV3.y"
                                    {
    auto step = new lvalueStep(lvalueStep::E_LV_KEY, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueSpecsValue)->addStep(step);
    ((*yyvalp).lvalueSpecsValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueSpecsValue);
}
#line 4806 "bisonparserV3.tab.c"
    break;

  case 104: /* lvalueSpecs: NTHOP lvalueSpecsFinal  */
#line 775 "bisonparserV3.y"
                       {
    auto s = new lvalueSpecs;
    auto step = new lvalueStep(lvalueStep::E_LV_NTH, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    s->addStep(step);
    ((*yyvalp).lvalueSpecsValue) = s;
}
#line 4817 "bisonparserV3.tab.c"
    break;

  case 105: /* lvalueSpecs: lvalueSpecsNonFinalized NTHOP lvalueSpecsFinal  */
#line 781 "bisonparserV3.y"
                                                 {
    auto step = new lvalueStep(lvalueStep::E_LV_NTH, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueSpecsValue)->addStep(step);
    ((*yyvalp).lvalueSpecsValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueSpecsValue);
}
#line 4827 "bisonparserV3.tab.c"
    break;

  case 106: /* lvalueSpecs: APPLY lvalueSpecsFinal  */
#line 786 "bisonparserV3.y"
                         {
    auto s = new lvalueSpecs;
    auto step = new lvalueStep(lvalueStep::E_LV_KEY, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    s->addStep(step);
    ((*yyvalp).lvalueSpecsValue) = s;
}
#line 4838 "bisonparserV3.tab.c"
    break;

  case 107: /* lvalueSpecs: lvalueSpecsNonFinalized APPLY lvalueSpecsFinal  */
#line 792 "bisonparserV3.y"
                                                 {
    auto step = new lvalueStep(lvalueStep::E_LV_KEY, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueSpecsValue)->addStep(step);
    ((*yyvalp).lvalueSpecsValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueSpecsValue);
}
#line 4848 "bisonparserV3.tab.c"
    break;

  case 118: /* expr: lvalue  */
#line 816 "bisonparserV3.y"
         {
    astNode* n = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.lvalueValue)->getVar();
    auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.lvalueValue)->getSpecs();
    if (s)
        n = s->toReadNode(n, params->owner);
    ((*yyvalp).astNodeValue) = n;
}
#line 4860 "bisonparserV3.tab.c"
    break;

  case 119: /* expr: fakeLvalue  */
#line 823 "bisonparserV3.y"
             {
    auto n = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode();
    auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs();
    ((*yyvalp).astNodeValue) = s->toReadNode(n, params->owner);
}
#line 4870 "bisonparserV3.tab.c"
    break;

  case 120: /* expr: sign expr  */
#line 828 "bisonparserV3.y"
            {
    if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.longValue) == -1)
        ((*yyvalp).astNodeValue) = new astOperatorUMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue);
    code_dev_post("parse: U-\n");
}
#line 4882 "bisonparserV3.tab.c"
    break;

  case 121: /* expr: LOGNOT expr  */
#line 835 "bisonparserV3.y"
              {
    ((*yyvalp).astNodeValue) = new astLogNot((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post("parse: !\n");
}
#line 4891 "bisonparserV3.tab.c"
    break;

  case 122: /* expr: BITNOT expr  */
#line 839 "bisonparserV3.y"
              {
    ((*yyvalp).astNodeValue) = new astOperatorBitNot((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post("parse: ~\n");
}
#line 4900 "bisonparserV3.tab.c"
    break;

  case 123: /* expr: expr PLUS expr  */
#line 843 "bisonparserV3.y"
                 {
    ((*yyvalp).astNodeValue) = new astOperatorPlus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: +\n");
}
#line 4909 "bisonparserV3.tab.c"
    break;

  case 124: /* expr: expr MINUS expr  */
#line 847 "bisonparserV3.y"
                  {
    ((*yyvalp).astNodeValue) = new astOperatorMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: -\n");
}
#line 4918 "bisonparserV3.tab.c"
    break;

  case 125: /* expr: expr TIMES expr  */
#line 851 "bisonparserV3.y"
                  {
    ((*yyvalp).astNodeValue) = new astOperatorTimes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: *\n");
}
#line 4927 "bisonparserV3.tab.c"
    break;

  case 126: /* expr: expr DIV expr  */
#line 855 "bisonparserV3.y"
                {
    ((*yyvalp).astNodeValue) = new astOperatorDiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: /\n");
}
#line 4936 "bisonparserV3.tab.c"
    break;

  case 127: /* expr: expr DIVDIV expr  */
#line 859 "bisonparserV3.y"
                   {
    ((*yyvalp).astNodeValue) = new astOperatorDivdiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: //\n");
}
#line 4945 "bisonparserV3.tab.c"
    break;

  case 128: /* expr: expr REM expr  */
#line 863 "bisonparserV3.y"
                {
    ((*yyvalp).astNodeValue) = new astOperatorRemainder((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: %\n");
}
#line 4954 "bisonparserV3.tab.c"
    break;

  case 129: /* expr: expr POWOP expr  */
#line 867 "bisonparserV3.y"
                  {
    ((*yyvalp).astNodeValue) = new astOperatorPow((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: **\n");
}
#line 4963 "bisonparserV3.tab.c"
    break;

  case 130: /* expr: expr BITAND expr  */
#line 871 "bisonparserV3.y"
                   {
    ((*yyvalp).astNodeValue) = new astOperatorBitAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: &\n");
}
#line 4972 "bisonparserV3.tab.c"
    break;

  case 131: /* expr: expr BITXOR expr  */
#line 875 "bisonparserV3.y"
                   {
    ((*yyvalp).astNodeValue) = new astOperatorBitXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: ^\n");
}
#line 4981 "bisonparserV3.tab.c"
    break;

  case 132: /* expr: expr BITOR expr  */
#line 879 "bisonparserV3.y"
                  {
    ((*yyvalp).astNodeValue) = new astOperatorBitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: |\n");
}
#line 4990 "bisonparserV3.tab.c"
    break;

  case 133: /* expr: expr LSHIFT expr  */
#line 883 "bisonparserV3.y"
                   {
    ((*yyvalp).astNodeValue) = new astOperatorBitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: <<\n");
}
#line 4999 "bisonparserV3.tab.c"
    break;

  case 134: /* expr: expr RSHIFT expr  */
#line 887 "bisonparserV3.y"
                   {
    ((*yyvalp).astNodeValue) = new astOperatorBitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: >>\n");
}
#line 5008 "bisonparserV3.tab.c"
    break;

  case 135: /* expr: expr EQUAL expr  */
#line 891 "bisonparserV3.y"
                  {
    ((*yyvalp).astNodeValue) = new astComparatorEq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: ==\n");
}
#line 5017 "bisonparserV3.tab.c"
    break;

  case 136: /* expr: expr NEQ expr  */
#line 895 "bisonparserV3.y"
                {
    ((*yyvalp).astNodeValue) = new astComparatorNeq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: !=\n");
}
#line 5026 "bisonparserV3.tab.c"
    break;

  case 137: /* expr: expr LT expr  */
#line 899 "bisonparserV3.y"
               {
    ((*yyvalp).astNodeValue) = new astComparatorLt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: <\n");
}
#line 5035 "bisonparserV3.tab.c"
    break;

  case 138: /* expr: expr GT expr  */
#line 903 "bisonparserV3.y"
               {
    ((*yyvalp).astNodeValue) = new astComparatorGt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: <\n");
}
#line 5044 "bisonparserV3.tab.c"
    break;

  case 139: /* expr: expr LEQ expr  */
#line 907 "bisonparserV3.y"
                {
    ((*yyvalp).astNodeValue) = new astComparatorLeq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: <=\n");
}
#line 5053 "bisonparserV3.tab.c"
    break;

  case 140: /* expr: expr GEQ expr  */
#line 911 "bisonparserV3.y"
                {
    ((*yyvalp).astNodeValue) = new astComparatorGeq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: >=\n");
}
#line 5062 "bisonparserV3.tab.c"
    break;

  case 141: /* expr: expr LOGOR expr  */
#line 915 "bisonparserV3.y"
                  {
    ((*yyvalp).astNodeValue) = new astSCOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: ||\n");
}
#line 5071 "bisonparserV3.tab.c"
    break;

  case 142: /* expr: expr LOGAND expr  */
#line 919 "bisonparserV3.y"
                   {
    ((*yyvalp).astNodeValue) = new astSCAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: &&\n");
}
#line 5080 "bisonparserV3.tab.c"
    break;

  case 143: /* expr: expr LOGXOR expr  */
#line 923 "bisonparserV3.y"
                   {
    ((*yyvalp).astNodeValue) = new astLogXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: &&\n");
}
#line 5089 "bisonparserV3.tab.c"
    break;

  case 144: /* expr: expr LOGOREXT expr  */
#line 927 "bisonparserV3.y"
                     {
    ((*yyvalp).astNodeValue) = new astSCOrExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: |||\n");
}
#line 5098 "bisonparserV3.tab.c"
    break;

  case 145: /* expr: expr LOGANDEXT expr  */
#line 931 "bisonparserV3.y"
                      {
    ((*yyvalp).astNodeValue) = new astSCAndExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: &&&\n");
}
#line 5107 "bisonparserV3.tab.c"
    break;

  case 146: /* expr: expr PICKOP expr  */
#line 935 "bisonparserV3.y"
                   {
    ((*yyvalp).astNodeValue) = new astPickOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: nthop\n");
}
#line 5116 "bisonparserV3.tab.c"
    break;

  case 147: /* expr: expr RANGE expr  */
#line 939 "bisonparserV3.y"
                  {
    ((*yyvalp).astNodeValue) = new astRangeOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: range\n");
}
#line 5125 "bisonparserV3.tab.c"
    break;

  case 148: /* expr: expr REPEAT expr  */
#line 943 "bisonparserV3.y"
                   {
    ((*yyvalp).astNodeValue) = new astRepeatOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: range\n");
}
#line 5134 "bisonparserV3.tab.c"
    break;

  case 149: /* item: LONG_LITERAL  */
#line 952 "bisonparserV3.y"
             {
    ((*yyvalp).astNodeValue) = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue), params->owner);
    code_dev_post("parse: INT %ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue));
}
#line 5143 "bisonparserV3.tab.c"
    break;

  case 150: /* item: RAT_LITERAL  */
#line 956 "bisonparserV3.y"
              {
    ((*yyvalp).astNodeValue) = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.ratValue), params->owner);
    code_dev_post("parse: RAT_LITERAL %ld/%ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.ratValue).num(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.ratValue).den());
}
#line 5152 "bisonparserV3.tab.c"
    break;

  case 151: /* item: DOUBLE_LITERAL  */
#line 960 "bisonparserV3.y"
                 {
    ((*yyvalp).astNodeValue) = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.doubleValue), params->owner);
    code_dev_post("parse: DOUBLE_LITERAL %lf", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.doubleValue));
}
#line 5161 "bisonparserV3.tab.c"
    break;

  case 152: /* item: PITCH_LITERAL  */
#line 964 "bisonparserV3.y"
                {
    ((*yyvalp).astNodeValue) = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.pitchValue), params->owner);
    code_dev_post("parse: PITCH_LITERAL %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.pitchValue).toSym()->s_name);
}
#line 5170 "bisonparserV3.tab.c"
    break;

  case 153: /* item: SYMBOL_LITERAL  */
#line 968 "bisonparserV3.y"
                 {
    ((*yyvalp).astNodeValue) = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue), params->owner);
    code_dev_post("parse: SYMBOL_LITERAL %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue)->s_name);
}
#line 5179 "bisonparserV3.tab.c"
    break;

  case 154: /* item: BACHNULL  */
#line 972 "bisonparserV3.y"
           {
    ((*yyvalp).astNodeValue) = new astConst(llll_get(), params->owner);
    code_dev_post("parse: NULL");
}
#line 5188 "bisonparserV3.tab.c"
    break;

  case 155: /* item: ARGCOUNT  */
#line 976 "bisonparserV3.y"
           {
    auto fnConst = new astConst((*(params->bifs))["$argcount"], params->owner);
    ((*yyvalp).astNodeValue) = new astFunctionCall(fnConst, params->owner);
    code_dev_post("parse: ARGCOUNT");
}
#line 5198 "bisonparserV3.tab.c"
    break;

  case 156: /* item: BACHNIL  */
#line 981 "bisonparserV3.y"
          {
    t_llll *ll = llll_get();
    llll_appendllll(ll, llll_get());
    ((*yyvalp).astNodeValue) = new astConst(ll, params->owner);
    code_dev_post("parse: NIL");
}
#line 5209 "bisonparserV3.tab.c"
    break;

  case 157: /* item: INLET  */
#line 987 "bisonparserV3.y"
        {
    if (params->dataInlets && params->fnDepth == 0 && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue) > *(params->dataInlets))
        *(params->dataInlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue);
    ((*yyvalp).astNodeValue) = new astInlet((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue), params->owner);
    code_dev_post ("parse: INLET %ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue));
}
#line 5220 "bisonparserV3.tab.c"
    break;

  case 158: /* item: INTINLET  */
#line 993 "bisonparserV3.y"
           {
    if (params->dataInlets && params->fnDepth == 0 && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue) > *(params->dataInlets))
    *(params->dataInlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue);
    ((*yyvalp).astNodeValue) = new astConvInlet<hatom_fn_int>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue), params->owner);
    code_dev_post ("parse: INTINLET %ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue));
}
#line 5231 "bisonparserV3.tab.c"
    break;

  case 159: /* item: RATINLET  */
#line 999 "bisonparserV3.y"
           {
    if (params->dataInlets && params->fnDepth == 0 && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue) > *(params->dataInlets))
    *(params->dataInlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue);
    ((*yyvalp).astNodeValue) = new astConvInlet<hatom_fn_rat>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue), params->owner);
    code_dev_post ("parse: RATINLET %ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue));
}
#line 5242 "bisonparserV3.tab.c"
    break;

  case 160: /* item: FLOATINLET  */
#line 1005 "bisonparserV3.y"
             {
    if (params->dataInlets && params->fnDepth == 0 && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue) > *(params->dataInlets))
    *(params->dataInlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue);
    ((*yyvalp).astNodeValue) = new astConvInlet<hatom_fn_float>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue), params->owner);
    code_dev_post ("parse: FLOATINLET %ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue));
}
#line 5253 "bisonparserV3.tab.c"
    break;

  case 161: /* item: PITCHINLET  */
#line 1011 "bisonparserV3.y"
             {
    if (params->dataInlets && params->fnDepth == 0 && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue) > *(params->dataInlets))
    *(params->dataInlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue);
    ((*yyvalp).astNodeValue) = new astConvInlet<hatom_fn_pitch>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue), params->owner);
    code_dev_post ("parse: PITCHINLET %ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue));
}
#line 5264 "bisonparserV3.tab.c"
    break;

  case 162: /* item: DIRINLET  */
#line 1017 "bisonparserV3.y"
           {
    if (params->directInlets && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue) > *(params->directInlets))
        *(params->directInlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue);
    auto fnConst = new astConst((*(params->ofTable))["directin"], params->owner);
    auto numConst = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue), params->owner);
    auto tempList = new countedList<astNode *>(numConst);
    ((*yyvalp).astNodeValue) = new astFunctionCall(fnConst, tempList, nullptr, params->owner);
    code_dev_post("parse: DIRINLET");
}
#line 5278 "bisonparserV3.tab.c"
    break;

  case 163: /* item: OPEN sequence CLOSEDROUND  */
#line 1026 "bisonparserV3.y"
                            {
    ((*yyvalp).astNodeValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeValue);
    code_dev_post ("parse: []\n");
}
#line 5287 "bisonparserV3.tab.c"
    break;

  case 164: /* item: OPEN CLOSEDROUND  */
#line 1030 "bisonparserV3.y"
                   {
    ((*yyvalp).astNodeValue) = new astConst(llll_get(), params->owner);
}
#line 5295 "bisonparserV3.tab.c"
    break;

  case 165: /* item: PUSH sequence POP  */
#line 1033 "bisonparserV3.y"
                    {
    ((*yyvalp).astNodeValue) = new astWrap((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post("parse: []\n");
}
#line 5304 "bisonparserV3.tab.c"
    break;

  case 166: /* item: PUSH POP  */
#line 1037 "bisonparserV3.y"
           {
    t_llll *ll = llll_get();
    llll_appendllll(ll, llll_get());
    ((*yyvalp).astNodeValue) = new astConst(ll, params->owner);
    code_dev_post("parse: PushPop");
}
#line 5315 "bisonparserV3.tab.c"
    break;

  case 167: /* item: BIF  */
#line 1043 "bisonparserV3.y"
      {
    t_function *fn = (*(params->bifs))[(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue)->s_name];
    ((*yyvalp).astNodeValue) = new astConst(fn, params->owner);
    code_dev_post("parse: bif %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue)->s_name);
}
#line 5325 "bisonparserV3.tab.c"
    break;

  case 168: /* item: OF  */
#line 1048 "bisonparserV3.y"
     {
    t_function *fn = (*(params->ofTable))[(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue)->s_name];
    ((*yyvalp).astNodeValue) = new astConst(fn, params->owner);
    code_dev_post("parse: owned function %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue)->s_name);
}
#line 5335 "bisonparserV3.tab.c"
    break;

  case 169: /* item: MAXFUNCTION  */
#line 1053 "bisonparserV3.y"
              {
    t_function *fn = new t_maxFunction(std::string((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.textValue)));
    params->funcs->insert(fn);
    ((*yyvalp).astNodeValue) = new astConst(fn, params->owner);
    code_dev_post("parse: Max function %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.textValue));
}
#line 5346 "bisonparserV3.tab.c"
    break;

  case 170: /* assignment: INIT LOCALVAR ASSIGN list  */
#line 1064 "bisonparserV3.y"
                          {
    addVariableToScope<e_flexBisonV3>(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.symValue));
    ((*yyvalp).astNodeValue) = new astInit((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.symValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post("parse: INIT LOCALVAR ASSIGN list");
}
#line 5356 "bisonparserV3.tab.c"
    break;

  case 171: /* assignment: lvalue ASSIGN list  */
#line 1069 "bisonparserV3.y"
                     {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astAssign((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astRichAssignment<E_RA_STANDARD>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5367 "bisonparserV3.tab.c"
    break;

  case 172: /* assignment: lvalue APOWOP list  */
#line 1075 "bisonparserV3.y"
                     {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astOperatorAPow((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astOperatorRAPow((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5378 "bisonparserV3.tab.c"
    break;

  case 173: /* assignment: lvalue ATIMES list  */
#line 1081 "bisonparserV3.y"
                     {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astOperatorATimes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astOperatorRATimes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5389 "bisonparserV3.tab.c"
    break;

  case 174: /* assignment: lvalue ADIVDIV list  */
#line 1087 "bisonparserV3.y"
                      {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astOperatorADivdiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astOperatorRADivdiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5400 "bisonparserV3.tab.c"
    break;

  case 175: /* assignment: lvalue ADIV list  */
#line 1093 "bisonparserV3.y"
                   {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astOperatorADiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astOperatorRADiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5411 "bisonparserV3.tab.c"
    break;

  case 176: /* assignment: lvalue AREM list  */
#line 1099 "bisonparserV3.y"
                   {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astOperatorARemainder((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astOperatorRARemainder((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5422 "bisonparserV3.tab.c"
    break;

  case 177: /* assignment: lvalue APLUS list  */
#line 1105 "bisonparserV3.y"
                    {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astOperatorAPlus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astOperatorRAPlus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5433 "bisonparserV3.tab.c"
    break;

  case 178: /* assignment: lvalue AMINUS list  */
#line 1111 "bisonparserV3.y"
                     {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astOperatorAMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astOperatorRAMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5444 "bisonparserV3.tab.c"
    break;

  case 179: /* assignment: lvalue ALOGAND list  */
#line 1117 "bisonparserV3.y"
                      {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astSCAAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astLogRASCAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5455 "bisonparserV3.tab.c"
    break;

  case 180: /* assignment: lvalue ALOGANDEXT list  */
#line 1123 "bisonparserV3.y"
                         {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astSCAAndExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astLogRASCAndExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5466 "bisonparserV3.tab.c"
    break;

  case 181: /* assignment: lvalue ALOGXOR list  */
#line 1129 "bisonparserV3.y"
                      {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astLogAXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astLogRAXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5477 "bisonparserV3.tab.c"
    break;

  case 182: /* assignment: lvalue ALOGOR list  */
#line 1135 "bisonparserV3.y"
                     {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astSCAOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astLogRASCOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5488 "bisonparserV3.tab.c"
    break;

  case 183: /* assignment: lvalue ALOGOREXT list  */
#line 1141 "bisonparserV3.y"
                        {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astSCAOrExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astLogRASCOrExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5499 "bisonparserV3.tab.c"
    break;

  case 184: /* assignment: lvalue ABITAND list  */
#line 1147 "bisonparserV3.y"
                      {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astOperatorABitAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astOperatorRABitAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5510 "bisonparserV3.tab.c"
    break;

  case 185: /* assignment: lvalue ABITXOR list  */
#line 1153 "bisonparserV3.y"
                      {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astOperatorABitXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astOperatorRABitXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5521 "bisonparserV3.tab.c"
    break;

  case 186: /* assignment: lvalue ABITOR list  */
#line 1159 "bisonparserV3.y"
                     {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astOperatorABitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astOperatorRABitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5532 "bisonparserV3.tab.c"
    break;

  case 187: /* assignment: lvalue ALSHIFT list  */
#line 1165 "bisonparserV3.y"
                      {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astOperatorALShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astOperatorRALShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5543 "bisonparserV3.tab.c"
    break;

  case 188: /* assignment: lvalue ARSHIFT list  */
#line 1171 "bisonparserV3.y"
                      {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astOperatorARShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astOperatorRARShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5554 "bisonparserV3.tab.c"
    break;

  case 189: /* assignment: lvalue ACONCAT list  */
#line 1177 "bisonparserV3.y"
                      {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astConcatAssignOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astRAConcat((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5565 "bisonparserV3.tab.c"
    break;

  case 190: /* assignment: lvalue ARCONCAT list  */
#line 1183 "bisonparserV3.y"
                       {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astRevConcatAssignOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astRARConcat((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5576 "bisonparserV3.tab.c"
    break;

  case 191: /* assignment: lvalue ANTHOP list  */
#line 1189 "bisonparserV3.y"
                     {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astNthAssignOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = nullptr;
}
#line 5587 "bisonparserV3.tab.c"
    break;

  case 192: /* assignment: fakeLvalue ASSIGN list  */
#line 1196 "bisonparserV3.y"
                         {
    ((*yyvalp).astNodeValue) = new astRichEdit<E_RA_STANDARD>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 5595 "bisonparserV3.tab.c"
    break;

  case 193: /* assignment: fakeLvalue APOWOP list  */
#line 1199 "bisonparserV3.y"
                         {
    ((*yyvalp).astNodeValue) = new astOperatorREPow((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 5603 "bisonparserV3.tab.c"
    break;

  case 194: /* assignment: fakeLvalue ATIMES list  */
#line 1202 "bisonparserV3.y"
                         {
    ((*yyvalp).astNodeValue) = new astOperatorRETimes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 5611 "bisonparserV3.tab.c"
    break;

  case 195: /* assignment: fakeLvalue ADIVDIV list  */
#line 1205 "bisonparserV3.y"
                          {
    ((*yyvalp).astNodeValue) = new astOperatorREDivdiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 5619 "bisonparserV3.tab.c"
    break;

  case 196: /* assignment: fakeLvalue ADIV list  */
#line 1208 "bisonparserV3.y"
                       {
    ((*yyvalp).astNodeValue) = new astOperatorREDiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 5627 "bisonparserV3.tab.c"
    break;

  case 197: /* assignment: fakeLvalue AREM list  */
#line 1211 "bisonparserV3.y"
                       {
    ((*yyvalp).astNodeValue) = new astOperatorRERemainder((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 5635 "bisonparserV3.tab.c"
    break;

  case 198: /* assignment: fakeLvalue APLUS list  */
#line 1214 "bisonparserV3.y"
                        {
    ((*yyvalp).astNodeValue) = new astOperatorREPlus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 5643 "bisonparserV3.tab.c"
    break;

  case 199: /* assignment: fakeLvalue AMINUS list  */
#line 1217 "bisonparserV3.y"
                         {
    ((*yyvalp).astNodeValue) = new astOperatorREMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 5651 "bisonparserV3.tab.c"
    break;

  case 200: /* assignment: fakeLvalue ALOGAND list  */
#line 1220 "bisonparserV3.y"
                          {
    ((*yyvalp).astNodeValue) = new astLogRESCAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 5659 "bisonparserV3.tab.c"
    break;

  case 201: /* assignment: fakeLvalue ALOGANDEXT list  */
#line 1223 "bisonparserV3.y"
                             {
    ((*yyvalp).astNodeValue) = new astLogRESCAndExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 5667 "bisonparserV3.tab.c"
    break;

  case 202: /* assignment: fakeLvalue ALOGXOR list  */
#line 1226 "bisonparserV3.y"
                          {
    ((*yyvalp).astNodeValue) = new astLogREXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 5675 "bisonparserV3.tab.c"
    break;

  case 203: /* assignment: fakeLvalue ALOGOR list  */
#line 1229 "bisonparserV3.y"
                         {
    ((*yyvalp).astNodeValue) = new astLogRESCOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 5683 "bisonparserV3.tab.c"
    break;

  case 204: /* assignment: fakeLvalue ALOGOREXT list  */
#line 1232 "bisonparserV3.y"
                            {
    ((*yyvalp).astNodeValue) = new astLogRESCOrExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 5691 "bisonparserV3.tab.c"
    break;

  case 205: /* assignment: fakeLvalue ABITAND list  */
#line 1235 "bisonparserV3.y"
                          {
    ((*yyvalp).astNodeValue) = new astOperatorREBitAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 5699 "bisonparserV3.tab.c"
    break;

  case 206: /* assignment: fakeLvalue ABITXOR list  */
#line 1238 "bisonparserV3.y"
                          {
    ((*yyvalp).astNodeValue) = new astOperatorREBitXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 5707 "bisonparserV3.tab.c"
    break;

  case 207: /* assignment: fakeLvalue ABITOR list  */
#line 1241 "bisonparserV3.y"
                         {
    ((*yyvalp).astNodeValue) = new astOperatorREBitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 5715 "bisonparserV3.tab.c"
    break;

  case 208: /* assignment: fakeLvalue ALSHIFT list  */
#line 1244 "bisonparserV3.y"
                          {
    ((*yyvalp).astNodeValue) = new astOperatorRELShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 5723 "bisonparserV3.tab.c"
    break;

  case 209: /* assignment: fakeLvalue ARSHIFT list  */
#line 1247 "bisonparserV3.y"
                          {
    ((*yyvalp).astNodeValue) = new astOperatorRERShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 5731 "bisonparserV3.tab.c"
    break;

  case 210: /* assignment: fakeLvalue ACONCAT list  */
#line 1250 "bisonparserV3.y"
                          {
    ((*yyvalp).astNodeValue) = new astREConcat((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 5739 "bisonparserV3.tab.c"
    break;

  case 211: /* assignment: fakeLvalue ARCONCAT list  */
#line 1253 "bisonparserV3.y"
                           {
    ((*yyvalp).astNodeValue) = new astRERConcat((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 5747 "bisonparserV3.tab.c"
    break;

  case 212: /* assignment: lvalue AAPPLY funcall  */
#line 1257 "bisonparserV3.y"
                        {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s = nullptr) {
        (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astFunctionCallValue)->addDataflowStyleArg(new astConst(params->owner));
        ((*yyvalp).astNodeValue) = new astAssign((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astFunctionCallValue), params->owner);
    } else {
        (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astFunctionCallValue)->addDataflowStyleArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar());
        ((*yyvalp).astNodeValue) = new astRichAccessApplyOp<astRichAssignment<E_RA_SHORTCIRCUIT>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astFunctionCallValue), s, params->owner);
    }
}
#line 5761 "bisonparserV3.tab.c"
    break;

  case 213: /* assignment: fakeLvalue AAPPLY funcall  */
#line 1267 "bisonparserV3.y"
                            {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astFunctionCallValue)->addDataflowStyleArg(new astConst(params->owner));
    ((*yyvalp).astNodeValue) = new astRichAccessApplyOp<astRichEdit<E_RA_SHORTCIRCUIT>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astFunctionCallValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 5770 "bisonparserV3.tab.c"
    break;

  case 214: /* assignment: OUTLET ASSIGN list  */
#line 1272 "bisonparserV3.y"
                     {
    if (params->dataOutlets && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.longValue) > *(params->dataOutlets))
        *(params->dataOutlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.longValue);
    auto fnConst = new astConst((*(params->bifs))["outlet"], params->owner);


    auto numConst = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.longValue), params->owner);
    auto v = new std::vector<astNode*>(2);
    v->push_back(numConst);
    v->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    ((*yyvalp).astNodeValue) = new astFunctionCall(fnConst, v, nullptr, params->owner);
    code_dev_post("parse: OUTLET ASSIGN list");
}
#line 5788 "bisonparserV3.tab.c"
    break;

  case 215: /* assignment: DIROUTLET ASSIGN list  */
#line 1286 "bisonparserV3.y"
                        {
    if (params->directOutlets && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.longValue) > *(params->directOutlets))
        *(params->directOutlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.longValue);
    auto fnConst = new astConst((*(params->ofTable))["directout"], params->owner);
    auto v = new std::vector<astNode*>(2);
    v->push_back(new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.longValue), params->owner));
    v->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    ((*yyvalp).astNodeValue) = new astFunctionCall(fnConst, v, nullptr, params->owner);
    code_dev_post("parse: DIROUTLET ASSIGN list");
}
#line 5803 "bisonparserV3.tab.c"
    break;

  case 216: /* conditional: IF_KW sequence THEN_KW list  */
#line 1301 "bisonparserV3.y"
                                          {
    ((*yyvalp).astNodeValue) = new astIfThenElse((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), nullptr, params->owner);
    code_dev_post ("parse: if then\n");
}
#line 5812 "bisonparserV3.tab.c"
    break;

  case 217: /* conditional: IF_KW sequence THEN_KW list ELSE_KW list  */
#line 1305 "bisonparserV3.y"
                                           {
    // ask JLG: this causes 26 r/r conflicts.
    // Putting
    // IF_KW sequence THEN_KW valueOrAssignment ELSE_KW valueOrAssignment
    // would silence the conflicts, but doesn't work the same.
    // The current version parses
    //  if 1==1 then $a := 1 ; $b := 2 else $a := 3 ; $a
    // as
    //  if 1==1 then [$a := 1 ; $b := 2] else $a := 3 ; $a
    // thus returning 1
    // The "fixed" version, on the other hand, only considers
    //  if 1==1 then $a := 1 ; $b := 2
    // and discards what follows, thus resulting in 2.
    // On the other hand, I don't want to be forced to write
    // IF_KW sequence THEN_KW sequence
    // in the previous rule.
    // How do I solve this?
    
    ((*yyvalp).astNodeValue) = new astIfThenElse((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: if then else\n");
}
#line 5838 "bisonparserV3.tab.c"
    break;


#line 5842 "bisonparserV3.tab.c"

      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yylhsNonterm (yyrule), yyvalp, yylocp);

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYNOMEM
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YY_USE (yy0);
  YY_USE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, void *scanner, struct _parseParams *params)
{
  YY_USE (yyvaluep);
  YY_USE (scanner);
  YY_USE (params);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys, void *scanner, struct _parseParams *params)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yy_accessing_symbol (yys->yylrState),
                &yys->yysemantics.yyval, scanner, params);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YY_FPRINTF ((stderr, "%s unresolved", yymsg));
          else
            YY_FPRINTF ((stderr, "%s incomplete", yymsg));
          YY_SYMBOL_PRINT ("", yy_accessing_symbol (yys->yylrState), YY_NULLPTR, &yys->yyloc);
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh, scanner, params);
        }
    }
}

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yy_state_t yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yy_state_t yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yyn) \
  0

/** The action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static inline int
yygetLRActions (yy_state_t yystate, yysymbol_kind_t yytoken, const short** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yytoken == YYSYMBOL_YYerror)
    {
      // This is the error token.
      *yyconflicts = yyconfl;
      return 0;
    }
  else if (yyisDefaultedState (yystate)
           || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyconflicts = yyconfl;
      return -yydefact[yystate];
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return yytable[yyindex];
    }
  else
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return 0;
    }
}

/** Compute post-reduction state.
 * \param yystate   the current state
 * \param yysym     the nonterminal to push on the stack
 */
static inline yy_state_t
yyLRgotoState (yy_state_t yystate, yysymbol_kind_t yysym)
{
  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yysym - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  YY_ASSERT (!yynewOption->yyisState);
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates
    = YY_CAST (yyGLRState**,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yystates[0]));
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULLPTR;
  yyset->yylookaheadNeeds
    = YY_CAST (yybool*,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yylookaheadNeeds[0]));
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  memset (yyset->yylookaheadNeeds,
          0,
          YY_CAST (YYSIZE_T, yyset->yycapacity) * sizeof yyset->yylookaheadNeeds[0]);
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, YYPTRDIFF_T yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yysize)
                         * sizeof yystackp->yynextFree[0]));
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS, YYTOITEMS, YYX, YYTYPE)                   \
  &((YYTOITEMS)                                                         \
    - ((YYFROMITEMS) - YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX))))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  YYPTRDIFF_T yynewSize;
  YYPTRDIFF_T yyn;
  YYPTRDIFF_T yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yynewSize)
                         * sizeof yynewItems[0]));
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*YY_REINTERPRET_CAST (yybool *, yyp0))
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULLPTR)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULLPTR)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULLPTR)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULLPTR)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                      yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YY_DPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULLPTR;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  YYPTRDIFF_T yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
        {
          if (yyi == yyj)
            YY_DPRINTF ((stderr, "Removing dead stacks.\n"));
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            YY_DPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
                        YY_CAST (long, yyi), YY_CAST (long, yyj)));
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static inline void
yyglrShift (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
            YYPTRDIFF_T yyposn,
            YYSTYPE* yyvalp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyval = *yyvalp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
                 YYPTRDIFF_T yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
  YY_ASSERT (yynewState->yyisState);

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if YYDEBUG

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule, void *scanner, struct _parseParams *params)
{
  int yynrhs = yyrhsLength (yyrule);
  int yyi;
  YY_FPRINTF ((stderr, "Reducing stack %ld by rule %d (line %d):\n",
               YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YY_FPRINTF ((stderr, "   $%d = ", yyi + 1));
      yy_symbol_print (stderr,
                       yy_accessing_symbol (yyvsp[yyi - yynrhs + 1].yystate.yylrState),
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yyval                       , scanner, params);
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YY_FPRINTF ((stderr, " (unresolved)"));
      YY_FPRINTF ((stderr, "\n"));
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp, void *scanner, struct _parseParams *params)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs
        = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yytops.yystates[yyk]);
      YY_ASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp, yyk,
                           yyvalp, scanner, params);
    }
  else
    {
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yyGLRState* yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      int yyi;
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyk, yyvalp, scanner, params);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
             yybool yyforceEval, void *scanner, struct _parseParams *params)
{
  YYPTRDIFF_T yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yyval;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yyval, scanner, params);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        YY_DPRINTF ((stderr,
                     "Parse on stack %ld rejected by rule %d (line %d).\n",
                     YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
      if (yyflag != yyok)
        return yyflag;
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yyval);
    }
  else
    {
      YYPTRDIFF_T yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yy_state_t yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YY_DPRINTF ((stderr,
                   "Reduced stack %ld by rule %d (line %d); action deferred.  "
                   "Now in state %d.\n",
                   YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule],
                   yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YY_DPRINTF ((stderr, "Merging stack %ld into stack %ld.\n",
                                 YY_CAST (long, yyk), YY_CAST (long, yyi)));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static YYPTRDIFF_T
yysplitStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      YY_ASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yycapacity <= yystackp->yytops.yysize)
    {
      YYPTRDIFF_T state_size = YYSIZEOF (yystackp->yytops.yystates[0]);
      YYPTRDIFF_T half_max_capacity = YYSIZE_MAXIMUM / 2 / state_size;
      if (half_max_capacity < yystackp->yytops.yycapacity)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      {
        yyGLRState** yynewStates
          = YY_CAST (yyGLRState**,
                     YYREALLOC (yystackp->yytops.yystates,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewStates[0])));
        if (yynewStates == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yystates = yynewStates;
      }

      {
        yybool* yynewLookaheadNeeds
          = YY_CAST (yybool*,
                     YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewLookaheadNeeds[0])));
        if (yynewLookaheadNeeds == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
      }
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize - 1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       0 < yyn;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yyval = yys0->yysemantics.yyval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yyval = yys1->yysemantics.yyval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                break;
              else if (*yyz0p == YY_NULLPTR)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp, void *scanner, struct _parseParams *params);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp, void *scanner, struct _parseParams *params)
{
  if (0 < yyn)
    {
      YY_ASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp, scanner, params));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp, scanner, params));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp, void *scanner, struct _parseParams *params)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp, scanner, params);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys, scanner, params);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, -1, yyvalp, scanner, params);
    yychar = yychar_current;
    yylval = yylval_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULLPTR)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, empty>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1));
  else
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, tokens %ld .. %ld>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1, YY_CAST (long, yys->yyposn + 1),
                 YY_CAST (long, yyx->yystate->yyposn)));
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YY_FPRINTF ((stderr, "%*s%s <empty>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState))));
          else
            YY_FPRINTF ((stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState)),
                         YY_CAST (long, yystates[yyi-1]->yyposn + 1),
                         YY_CAST (long, yystates[yyi]->yyposn)));
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1, void *scanner, struct _parseParams *params)
{
  YY_USE (yyx0);
  YY_USE (yyx1);

#if YYDEBUG
  YY_FPRINTF ((stderr, "Ambiguity detected.\n"));
  YY_FPRINTF ((stderr, "Option 1,\n"));
  yyreportTree (yyx0, 2);
  YY_FPRINTF ((stderr, "\nOption 2,\n"));
  yyreportTree (yyx1, 2);
  YY_FPRINTF ((stderr, "\n"));
#endif

  yyerror (scanner, params, YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp, void *scanner, struct _parseParams *params)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yyval;
  YYRESULTTAG yyflag;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              return yyreportAmbiguity (yybest, yyp, scanner, params);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YY_ASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yyval, scanner, params);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yyval_other;
                yyflag = yyresolveAction (yyp, yystackp, &yyval_other, scanner, params);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yy_accessing_symbol (yys->yylrState),
                                &yyval, scanner, params);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yyval, &yyval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yyval, scanner, params);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yyval = yyval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULLPTR;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp, void *scanner, struct _parseParams *params)
{
  if (yystackp->yysplitPoint != YY_NULLPTR)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             , scanner, params));
    }
  return yyok;
}

/** Called when returning to deterministic operation to clean up the extra
 * stacks. */
static void
yycompressStack (yyGLRStack* yystackp)
{
  /* yyr is the state after the split point.  */
  yyGLRState *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  {
    yyGLRState *yyp, *yyq;
    for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
         yyp != yystackp->yysplitPoint;
         yyr = yyp, yyp = yyq, yyq = yyp->yypred)
      yyp->yypred = yyr;
  }

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;

  while (yyr != YY_NULLPTR)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk,
                   YYPTRDIFF_T yyposn, void *scanner, struct _parseParams *params)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    {
      yy_state_t yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YY_DPRINTF ((stderr, "Stack %ld Entering state %d\n",
                   YY_CAST (long, yyk), yystate));

      YY_ASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule], scanner, params);
          if (yyflag == yyerr)
            {
              YY_DPRINTF ((stderr,
                           "Stack %ld dies "
                           "(predicate failure or explicit user error).\n",
                           YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yysymbol_kind_t yytoken = yygetToken (&yychar, yystackp, scanner, params);
          const short* yyconflicts;
          const int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;

          for (/* nothing */; *yyconflicts; yyconflicts += 1)
            {
              YYRESULTTAG yyflag;
              YYPTRDIFF_T yynewStack = yysplitStack (yystackp, yyk);
              YY_DPRINTF ((stderr, "Splitting off stack %ld from %ld.\n",
                           YY_CAST (long, yynewStack), YY_CAST (long, yyk)));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts], scanner, params);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn, scanner, params));
              else if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yynewStack)));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction], scanner, params);
              if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr,
                               "Stack %ld dies "
                               "(predicate failure or explicit user error).\n",
                               YY_CAST (long, yyk)));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYSTACKP, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  */
static int
yypcontext_expected_tokens (const yyGLRStack* yystackp,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}

static int
yy_syntax_error_arguments (const yyGLRStack* yystackp,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  yysymbol_kind_t yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yystackp,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}



static void
yyreportSyntaxError (yyGLRStack* yystackp, void *scanner, struct _parseParams *params)
{
  if (yystackp->yyerrState != 0)
    return;
  {
  yybool yysize_overflow = yyfalse;
  char* yymsg = YY_NULLPTR;
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount
    = yy_syntax_error_arguments (yystackp, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    yyMemoryExhausted (yystackp);

  switch (yycount)
    {
#define YYCASE_(N, S)                   \
      case N:                           \
        yyformat = S;                   \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysz
          = yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (YYSIZE_MAXIMUM - yysize < yysz)
          yysize_overflow = yytrue;
        else
          yysize += yysz;
      }
  }

  if (!yysize_overflow)
    yymsg = YY_CAST (char *, YYMALLOC (YY_CAST (YYSIZE_T, yysize)));

  if (yymsg)
    {
      char *yyp = yymsg;
      int yyi = 0;
      while ((*yyp = *yyformat))
        {
          if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
            {
              yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
              yyformat += 2;
            }
          else
            {
              ++yyp;
              ++yyformat;
            }
        }
      yyerror (scanner, params, yymsg);
      YYFREE (yymsg);
    }
  else
    {
      yyerror (scanner, params, YY_("syntax error"));
      yyMemoryExhausted (yystackp);
    }
  }
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp, void *scanner, struct _parseParams *params)
{
  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yysymbol_kind_t yytoken;
        int yyj;
        if (yychar == YYEOF)
          yyFail (yystackp, scanner, params, YY_NULLPTR);
        if (yychar != YYEMPTY)
          {
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval, scanner, params);
            yychar = YYEMPTY;
          }
        yytoken = yygetToken (&yychar, yystackp, scanner, params);
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  {
    YYPTRDIFF_T yyk;
    for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
      if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
        break;
    if (yyk >= yystackp->yytops.yysize)
      yyFail (yystackp, scanner, params, YY_NULLPTR);
    for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
      yymarkStackDeleted (yystackp, yyk);
    yyremoveDeletes (yystackp);
    yycompressStack (yystackp);
  }

  /* Pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      int yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYSYMBOL_YYerror;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYSYMBOL_YYerror
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              int yyaction = yytable[yyj];
              YY_SYMBOL_PRINT ("Shifting", yy_accessing_symbol (yyaction),
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yyaction,
                          yys->yyposn, &yylval);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      if (yys->yypred != YY_NULLPTR)
        yydestroyGLRState ("Error: popping", yys, scanner, params);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, scanner, params, YY_NULLPTR);
}

#define YYCHK1(YYE)                             \
  do {                                          \
    switch (YYE) {                              \
    case yyok:     break;                       \
    case yyabort:  goto yyabortlab;             \
    case yyaccept: goto yyacceptlab;            \
    case yyerr:    goto yyuser_error;           \
    case yynomem:  goto yyexhaustedlab;         \
    default:       goto yybuglab;               \
    }                                           \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *scanner, struct _parseParams *params)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  YYPTRDIFF_T yyposn;

  YY_DPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;

  /* User initialization code.  */
#line 191 "bisonparserV3.y"
{
    #ifdef YYDEBUG
    #if YYDEBUG == 1
    yydebug = 1;
    #endif
    #endif
}

#line 7249 "bisonparserV3.tab.c"


  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode. */
      while (yytrue)
        {
          yy_state_t yystate = yystack.yytops.yystates[0]->yylrState;
          YY_DPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyRuleNum yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {
                  yyreportSyntaxError (&yystack, scanner, params);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue, scanner, params));
            }
          else
            {
              yysymbol_kind_t yytoken = yygetToken (&yychar, yystackp, scanner, params);
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
              if (*yyconflicts)
                /* Enter nondeterministic mode.  */
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {
                  /* Issue an error message unless the scanner already
                     did. */
                  if (yychar != YYerror)
                    yyreportSyntaxError (&yystack, scanner, params);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue, scanner, params));
            }
        }

      /* Nondeterministic mode. */
      while (yytrue)
        {
          yysymbol_kind_t yytoken_to_shift;
          YYPTRDIFF_T yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn, scanner, params));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, scanner, params, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack, scanner, params));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yyreportSyntaxError (&yystack, scanner, params);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              yy_state_t yystate = yystack.yytops.yystates[yys]->yylrState;
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken_to_shift,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YY_DPRINTF ((stderr, "On stack %ld, ", YY_CAST (long, yys)));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval);
              YY_DPRINTF ((stderr, "Stack %ld now in state %d\n",
                           YY_CAST (long, yys),
                           yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack, scanner, params));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack, scanner, params);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;

 yybuglab:
  YY_ASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturnlab;

 yyexhaustedlab:
  yyerror (scanner, params, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;

 yyreturnlab:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval, scanner, params);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          YYPTRDIFF_T yysize = yystack.yytops.yysize;
          YYPTRDIFF_T yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                    if (yys->yypred != YY_NULLPTR)
                      yydestroyGLRState ("Cleanup: popping", yys, scanner, params);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if YYDEBUG
/* Print *YYS and its predecessors. */
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YY_FPRINTF ((stderr, " -> "));
    }
  YY_FPRINTF ((stderr, "%d@%ld", yys->yylrState, YY_CAST (long, yys->yyposn)));
}

/* Print YYS (possibly NULL) and its predecessors. */
static void
yypstates (yyGLRState* yys)
{
  if (yys == YY_NULLPTR)
    YY_FPRINTF ((stderr, "<null>"));
  else
    yy_yypstack (yys);
  YY_FPRINTF ((stderr, "\n"));
}

/* Print the stack #YYK.  */
static void
yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

/* Print all the stacks.  */
static void
yypdumpstack (yyGLRStack* yystackp)
{
#define YYINDEX(YYX)                                                    \
  YY_CAST (long,                                                        \
           ((YYX)                                                       \
            ? YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX)) - yystackp->yyitems \
            : -1))

  yyGLRStackItem* yyp;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YY_FPRINTF ((stderr, "%3ld. ",
                   YY_CAST (long, yyp - yystackp->yyitems)));
      if (*YY_REINTERPRET_CAST (yybool *, yyp))
        {
          YY_ASSERT (yyp->yystate.yyisState);
          YY_ASSERT (yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Res: %d, LR State: %d, posn: %ld, pred: %ld",
                       yyp->yystate.yyresolved, yyp->yystate.yylrState,
                       YY_CAST (long, yyp->yystate.yyposn),
                       YYINDEX (yyp->yystate.yypred)));
          if (! yyp->yystate.yyresolved)
            YY_FPRINTF ((stderr, ", firstVal: %ld",
                         YYINDEX (yyp->yystate.yysemantics.yyfirstVal)));
        }
      else
        {
          YY_ASSERT (!yyp->yystate.yyisState);
          YY_ASSERT (!yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Option. rule: %d, state: %ld, next: %ld",
                       yyp->yyoption.yyrule - 1,
                       YYINDEX (yyp->yyoption.yystate),
                       YYINDEX (yyp->yyoption.yynext)));
        }
      YY_FPRINTF ((stderr, "\n"));
    }

  YY_FPRINTF ((stderr, "Tops:"));
  {
    YYPTRDIFF_T yyi;
    for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
      YY_FPRINTF ((stderr, "%ld: %ld; ", YY_CAST (long, yyi),
                   YYINDEX (yystackp->yytops.yystates[yyi])));
    YY_FPRINTF ((stderr, "\n"));
  }
#undef YYINDEX
}
#endif

#undef yylval
#undef yychar
#undef yynerrs

/* Substitute the variable and function names.  */
#define yyparse bisonparserV3_parse
#define yylex   bisonparserV3_lex
#define yyerror bisonparserV3_error
#define yylval  bisonparserV3_lval
#define yychar  bisonparserV3_char
#define yydebug bisonparserV3_debug
#define yynerrs bisonparserV3_nerrs


#line 1329 "bisonparserV3.y"


t_mainFunction *codableobj_parse_buffer_v3(t_codableobj *x, long *codeac, t_atom_long *dataInlets, t_atom_long *dataOutlets, t_atom_long *directInlets, t_atom_long *directOutlets)
{
    yyscan_t myscanner;
    
    t_lexparams lexparams;
    
    bisonparserV3_lex_init_extra(&lexparams, &myscanner);
    bisonparserV3_scan_string(myscanner, x->c_text);
    
    t_parseParams params;
    params.ast = NULL;
    params.fnDepth = 0;
    params.localVariablesStack = params.localVariablesStackBase;
    params.localVariablesStackV = params.localVariablesStackBaseV;
    params.localVariablesStackV[0] = nullptr;
    params.localVariablesAuxMapStack = params.localVariablesAuxMapStackBase;
    params.localVariablesAuxMapStack[0] = new std::unordered_map<t_symbol *, int>;
    params.liftedVariablesStack = params.liftedVariablesStackBase;
    params.argumentsStack = params.argumentsStackBase;
    params.argumentsStackV = params.argumentsStackBaseV;
    params.argumentsStackV[0] = nullptr;
    params.gvt = bach->b_gvt;
    params.bifs = bach->b_bifTable;
    params.codeac = codeac;
    *params.codeac = 0;
    params.dataInlets = dataInlets;
    params.dataOutlets = dataOutlets;
    params.directInlets = directInlets;
    params.directOutlets = directOutlets;
    params.owner = x;
    params.ofTable = x->c_ofTable;
    params.name2patcherVars = new pvMap;
    params.globalVariables = new std::unordered_set<t_globalVariable*>;
    params.funcs = new std::unordered_set<t_function*>;
    
    code_dev_post("--- BUILDING AST!\n");
    bisonparserV3_parse(myscanner, &params);
    
    for (int i = 0; i < 256; i++) {
        if (params.localVariablesAuxMapStack[i] == nullptr)
            break;
        delete params.localVariablesAuxMapStack[i];
    }
    
    bisonparserV3_lex_destroy(myscanner);
    
    code_dev_post("first attribute at %ld", *params.codeac);
    
    if (params.ast) {
        t_mainFunction *mainFunction = new t_mainFunction(
            params.ast,
            params.localVariablesStackBase[0],
            params.globalVariables,
            params.name2patcherVars,
            params.funcs,
            x
        );
        codableobj_clear_included_filewatchers(x);
        codableobj_add_included_filewatchers(x, &lexparams.files);
        return mainFunction;
    } else {
        object_error((t_object *) x, "Syntax errors present — couldn't parse code");
        delete params.name2patcherVars;
        delete params.globalVariables;
        for (t_function* f: *params.funcs)
            f->decrease();
        delete params.funcs;
        return nullptr;
    }
}


