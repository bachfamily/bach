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
    //#define code_dev_post post // UNCOMMENT THIS TO TURN ON VERBOSE PARSING
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
  YYSYMBOL_JIPITCHBASE_START = 12,         /* JIPITCHBASE_START  */
  YYSYMBOL_JIPITCHBASE_END = 13,           /* JIPITCHBASE_END  */
  YYSYMBOL_RAT_LITERAL = 14,               /* RAT_LITERAL  */
  YYSYMBOL_DOUBLE_LITERAL = 15,            /* DOUBLE_LITERAL  */
  YYSYMBOL_PITCH_LITERAL = 16,             /* PITCH_LITERAL  */
  YYSYMBOL_SYMBOL_LITERAL = 17,            /* SYMBOL_LITERAL  */
  YYSYMBOL_GLOBALVAR = 18,                 /* GLOBALVAR  */
  YYSYMBOL_PATCHERVAR = 19,                /* PATCHERVAR  */
  YYSYMBOL_LOCALVAR = 20,                  /* LOCALVAR  */
  YYSYMBOL_NAMEDPARAM = 21,                /* NAMEDPARAM  */
  YYSYMBOL_BIF = 22,                       /* BIF  */
  YYSYMBOL_OF = 23,                        /* OF  */
  YYSYMBOL_MAXFUNCTION = 24,               /* MAXFUNCTION  */
  YYSYMBOL_NULLIFY = 25,                   /* NULLIFY  */
  YYSYMBOL_IF_KW = 26,                     /* IF_KW  */
  YYSYMBOL_THEN_KW = 27,                   /* THEN_KW  */
  YYSYMBOL_ELSE_KW = 28,                   /* ELSE_KW  */
  YYSYMBOL_WHILE_KW = 29,                  /* WHILE_KW  */
  YYSYMBOL_DO_KW = 30,                     /* DO_KW  */
  YYSYMBOL_FOR_KW = 31,                    /* FOR_KW  */
  YYSYMBOL_IN_KW = 32,                     /* IN_KW  */
  YYSYMBOL_COLLECT_KW = 33,                /* COLLECT_KW  */
  YYSYMBOL_ASSIGN = 34,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 35,                      /* PLUS  */
  YYSYMBOL_MINUS = 36,                     /* MINUS  */
  YYSYMBOL_TIMES = 37,                     /* TIMES  */
  YYSYMBOL_DIV = 38,                       /* DIV  */
  YYSYMBOL_DIVDIV = 39,                    /* DIVDIV  */
  YYSYMBOL_APLUS = 40,                     /* APLUS  */
  YYSYMBOL_LOGOR = 41,                     /* LOGOR  */
  YYSYMBOL_LOGAND = 42,                    /* LOGAND  */
  YYSYMBOL_LOGOREXT = 43,                  /* LOGOREXT  */
  YYSYMBOL_LOGANDEXT = 44,                 /* LOGANDEXT  */
  YYSYMBOL_EQUAL = 45,                     /* EQUAL  */
  YYSYMBOL_LT = 46,                        /* LT  */
  YYSYMBOL_GT = 47,                        /* GT  */
  YYSYMBOL_LEQ = 48,                       /* LEQ  */
  YYSYMBOL_GEQ = 49,                       /* GEQ  */
  YYSYMBOL_NEQ = 50,                       /* NEQ  */
  YYSYMBOL_OPEN = 51,                      /* OPEN  */
  YYSYMBOL_CLOSEDROUND = 52,               /* CLOSEDROUND  */
  YYSYMBOL_FUNDEF = 53,                    /* FUNDEF  */
  YYSYMBOL_EMPTYFUNARGLIST = 54,           /* EMPTYFUNARGLIST  */
  YYSYMBOL_PUSH = 55,                      /* PUSH  */
  YYSYMBOL_POP = 56,                       /* POP  */
  YYSYMBOL_STARTPARAMS = 57,               /* STARTPARAMS  */
  YYSYMBOL_COMMA = 58,                     /* COMMA  */
  YYSYMBOL_ELLIPSIS = 59,                  /* ELLIPSIS  */
  YYSYMBOL_BACHNULL = 60,                  /* BACHNULL  */
  YYSYMBOL_BACHNIL = 61,                   /* BACHNIL  */
  YYSYMBOL_ARGCOUNT = 62,                  /* ARGCOUNT  */
  YYSYMBOL_EOL = 63,                       /* EOL  */
  YYSYMBOL_UNRECOGNIZED = 64,              /* UNRECOGNIZED  */
  YYSYMBOL_LIFT = 65,                      /* LIFT  */
  YYSYMBOL_AMINUS = 66,                    /* AMINUS  */
  YYSYMBOL_ATIMES = 67,                    /* ATIMES  */
  YYSYMBOL_APOWOP = 68,                    /* APOWOP  */
  YYSYMBOL_ADIV = 69,                      /* ADIV  */
  YYSYMBOL_ADIVDIV = 70,                   /* ADIVDIV  */
  YYSYMBOL_AREM = 71,                      /* AREM  */
  YYSYMBOL_ABITAND = 72,                   /* ABITAND  */
  YYSYMBOL_ABITXOR = 73,                   /* ABITXOR  */
  YYSYMBOL_ABITOR = 74,                    /* ABITOR  */
  YYSYMBOL_ALSHIFT = 75,                   /* ALSHIFT  */
  YYSYMBOL_ARSHIFT = 76,                   /* ARSHIFT  */
  YYSYMBOL_ALOGAND = 77,                   /* ALOGAND  */
  YYSYMBOL_ALOGANDEXT = 78,                /* ALOGANDEXT  */
  YYSYMBOL_ALOGXOR = 79,                   /* ALOGXOR  */
  YYSYMBOL_ALOGOR = 80,                    /* ALOGOR  */
  YYSYMBOL_ALOGOREXT = 81,                 /* ALOGOREXT  */
  YYSYMBOL_ANTHOP = 82,                    /* ANTHOP  */
  YYSYMBOL_AAPPLY = 83,                    /* AAPPLY  */
  YYSYMBOL_ACONCAT = 84,                   /* ACONCAT  */
  YYSYMBOL_ARCONCAT = 85,                  /* ARCONCAT  */
  YYSYMBOL_CONCAT = 86,                    /* CONCAT  */
  YYSYMBOL_LOGXOR = 87,                    /* LOGXOR  */
  YYSYMBOL_BITOR = 88,                     /* BITOR  */
  YYSYMBOL_BITXOR = 89,                    /* BITXOR  */
  YYSYMBOL_BITAND = 90,                    /* BITAND  */
  YYSYMBOL_REPEAT = 91,                    /* REPEAT  */
  YYSYMBOL_RANGE = 92,                     /* RANGE  */
  YYSYMBOL_LSHIFT = 93,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 94,                    /* RSHIFT  */
  YYSYMBOL_R = 95,                         /* R  */
  YYSYMBOL_T = 96,                         /* T  */
  YYSYMBOL_REM = 97,                       /* REM  */
  YYSYMBOL_UPLUS = 98,                     /* UPLUS  */
  YYSYMBOL_UMINUS = 99,                    /* UMINUS  */
  YYSYMBOL_POWOP = 100,                    /* POWOP  */
  YYSYMBOL_NTHOP = 101,                    /* NTHOP  */
  YYSYMBOL_PICKOP = 102,                   /* PICKOP  */
  YYSYMBOL_APPLY = 103,                    /* APPLY  */
  YYSYMBOL_ACCESS_UNWRAP = 104,            /* ACCESS_UNWRAP  */
  YYSYMBOL_LVALUESTEPPARAMS = 105,         /* LVALUESTEPPARAMS  */
  YYSYMBOL_AS_KW = 106,                    /* AS_KW  */
  YYSYMBOL_WITH_KW = 107,                  /* WITH_KW  */
  YYSYMBOL_LOGNOT = 108,                   /* LOGNOT  */
  YYSYMBOL_BITNOT = 109,                   /* BITNOT  */
  YYSYMBOL_KEEP = 110,                     /* KEEP  */
  YYSYMBOL_UNKEEP = 111,                   /* UNKEEP  */
  YYSYMBOL_INIT = 112,                     /* INIT  */
  YYSYMBOL_YYACCEPT = 113,                 /* $accept  */
  YYSYMBOL_program = 114,                  /* program  */
  YYSYMBOL_funarg = 115,                   /* funarg  */
  YYSYMBOL_116_1 = 116,                    /* $@1  */
  YYSYMBOL_funargList = 117,               /* funargList  */
  YYSYMBOL_118_2 = 118,                    /* $@2  */
  YYSYMBOL_liftedargList = 119,            /* liftedargList  */
  YYSYMBOL_fundef = 120,                   /* fundef  */
  YYSYMBOL_121_3 = 121,                    /* $@3  */
  YYSYMBOL_122_4 = 122,                    /* $@4  */
  YYSYMBOL_123_5 = 123,                    /* $@5  */
  YYSYMBOL_124_6 = 124,                    /* $@6  */
  YYSYMBOL_listVector = 125,               /* listVector  */
  YYSYMBOL_list = 126,                     /* list  */
  YYSYMBOL_sequence = 127,                 /* sequence  */
  YYSYMBOL_nullified = 128,                /* nullified  */
  YYSYMBOL_nullifiedSequence = 129,        /* nullifiedSequence  */
  YYSYMBOL_whileloop = 130,                /* whileloop  */
  YYSYMBOL_forarg = 131,                   /* forarg  */
  YYSYMBOL_forargList = 132,               /* forargList  */
  YYSYMBOL_forloop = 133,                  /* forloop  */
  YYSYMBOL_argsByPositionList = 134,       /* argsByPositionList  */
  YYSYMBOL_argsByNameList = 135,           /* argsByNameList  */
  YYSYMBOL_argByName = 136,                /* argByName  */
  YYSYMBOL_itemOrVar = 137,                /* itemOrVar  */
  YYSYMBOL_simpleFuncall = 138,            /* simpleFuncall  */
  YYSYMBOL_sign = 139,                     /* sign  */
  YYSYMBOL_lvalueSpecsItemForDot = 140,    /* lvalueSpecsItemForDot  */
  YYSYMBOL_lvalueSpecsItemForNth = 141,    /* lvalueSpecsItemForNth  */
  YYSYMBOL_dataflowHead = 142,             /* dataflowHead  */
  YYSYMBOL_dataflowFuncall = 143,          /* dataflowFuncall  */
  YYSYMBOL_funcall = 144,                  /* funcall  */
  YYSYMBOL_var = 145,                      /* var  */
  YYSYMBOL_localVar = 146,                 /* localVar  */
  YYSYMBOL_globalVar = 147,                /* globalVar  */
  YYSYMBOL_patcherVar = 148,               /* patcherVar  */
  YYSYMBOL_lvalueSpecsUFinal = 149,        /* lvalueSpecsUFinal  */
  YYSYMBOL_lvalueSpecsFinal = 150,         /* lvalueSpecsFinal  */
  YYSYMBOL_lvalue = 151,                   /* lvalue  */
  YYSYMBOL_fakeLvalueHead = 152,           /* fakeLvalueHead  */
  YYSYMBOL_fakeLvalue = 153,               /* fakeLvalue  */
  YYSYMBOL_lvalueSpecsNonFinalized = 154,  /* lvalueSpecsNonFinalized  */
  YYSYMBOL_lvalueSpecs = 155,              /* lvalueSpecs  */
  YYSYMBOL_listEnd = 156,                  /* listEnd  */
  YYSYMBOL_expr = 157,                     /* expr  */
  YYSYMBOL_commaVector = 158,              /* commaVector  */
  YYSYMBOL_jiPitchBase = 159,              /* jiPitchBase  */
  YYSYMBOL_item = 160,                     /* item  */
  YYSYMBOL_assignment = 161,               /* assignment  */
  YYSYMBOL_conditional = 162               /* conditional  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;

/* Second part of user prologue.  */
#line 164 "bisonparserV3.y"

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



#line 340 "bisonparserV3.tab.c"


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
#define YYFINAL  98
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   8078

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  113
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  258
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  430
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 8
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   367

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
     105,   106,   107,   108,   109,   110,   111,   112
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   206,   206,   211,   217,   223,   233,   236,   236,   246,
     255,   255,   263,   271,   278,   288,   288,   305,   305,   324,
     324,   344,   344,   370,   375,   383,   391,   394,   402,   403,
     406,   414,   417,   422,   427,   435,   439,   447,   452,   462,
     468,   477,   482,   487,   492,   497,   502,   507,   512,   517,
     522,   531,   537,   546,   551,   556,   565,   573,   574,   579,
     582,   585,   588,   591,   594,   597,   600,   603,   606,   613,
     616,   619,   622,   629,   630,   640,   641,   642,   652,   653,
     654,   661,   671,   675,   684,   685,   690,   691,   692,   697,
     702,   707,   716,   726,   737,   738,   739,   740,   746,   747,
     759,   762,   770,   771,   777,   785,   791,   796,   802,   812,
     818,   823,   829,   834,   839,   840,   841,   842,   843,   848,
     849,   850,   857,   869,   872,   875,   878,   881,   885,   889,
     893,   897,   901,   905,   909,   913,   917,   921,   925,   929,
     933,   937,   941,   945,   949,   953,   957,   961,   965,   969,
     973,   977,   981,   985,   989,   993,  1000,  1004,  1008,  1012,
    1016,  1020,  1024,  1028,  1032,  1036,  1040,  1044,  1048,  1052,
    1056,  1060,  1064,  1068,  1072,  1076,  1080,  1084,  1088,  1092,
    1096,  1100,  1104,  1108,  1116,  1122,  1128,  1134,  1143,  1153,
    1157,  1161,  1165,  1169,  1170,  1174,  1178,  1183,  1189,  1195,
    1201,  1207,  1213,  1219,  1228,  1232,  1235,  1239,  1245,  1250,
    1255,  1266,  1271,  1277,  1283,  1289,  1295,  1301,  1307,  1313,
    1319,  1325,  1331,  1337,  1343,  1349,  1355,  1361,  1367,  1373,
    1379,  1385,  1391,  1398,  1401,  1404,  1407,  1410,  1413,  1416,
    1419,  1422,  1425,  1428,  1431,  1434,  1437,  1440,  1443,  1446,
    1449,  1452,  1455,  1459,  1471,  1479,  1493,  1508,  1512
};
#endif

#define YYPACT_NINF (-242)
#define YYTABLE_NINF (-104)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     473,  -242,  -242,  -242,  -242,  -242,  -242,   -13,  -242,     1,
     143,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,
    -242,  -242,  1031,  1093,    16,   659,   -39,   721,  -242,  -242,
    -242,  7413,  7474,  1155,  1217,    33,    51,    56,    43,    -3,
      -7,  -242,   783,    58,    67,    86,   845,  -242,  -242,    73,
     -46,  7107,    57,    76,   -17,   -52,  -242,  -242,  -242,  7656,
     113,  7708,  -242,   305,  -242,   -47,  -242,  -242,  1279,  1341,
    -242,  -242,  -242,   146,     7,   149,   -18,    14,  -242,   -29,
    -242,   132,  -242,   174,   -11,  -242,   139,    97,    98,   118,
     118,  -242,  -242,  -242,  -242,  -242,  -242,   170,  -242,  -242,
      -7,    29,   175,  -242,  -242,  -242,   305,  -242,  -242,  -242,
      58,    86,   535,   597,  -242,  -242,  -242,  7941,  7993,  -242,
     121,  7657,  7657,  7169,  7230,   145,   161,  1403,  1465,  1527,
    1589,  1651,  1713,  1775,  1837,  1899,  1961,  2023,  2085,  2147,
    2209,  2271,  2333,  2395,  2457,  2519,  7657,  2581,  2643,   181,
    2705,  2767,  2829,  2891,  2953,  3015,  3077,  3139,  3201,  3263,
    3325,  3387,  3449,  3511,  3573,  3635,  3697,  3759,  7657,  3821,
    3883,  3945,  4007,  4069,  4131,  4193,  4255,  4317,  4379,  4441,
    4503,  4565,  4627,  4689,  4751,  4813,  4875,  4937,  4999,  5061,
    5123,  5185,  5247,  5309,  -242,  -242,  5371,  5433,  5495,  -242,
    -242,  -242,  -242,   155,  5557,  5619,  5681,   183,  5743,  5805,
    5867,    16,  5929,   192,  -242,  5991,  -242,  -242,   206,  -242,
    6053,  6115,  -242,  -242,  -242,  6177,  -242,  -242,    11,    23,
    -242,  -242,    27,   153,   172,  -242,  -242,   172,  -242,  -242,
    -242,    73,   172,  7291,  -242,  -242,  -242,  -242,  -242,  -242,
    7352,  -242,  -242,   201,   201,  7535,  7535,  -242,  -242,  -242,
    -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,
    -242,  -242,  -242,  -242,  -242,  -242,   188,  -242,  -242,  -242,
    -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,
    -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,   193,
    -242,  -242,  -242,   276,  -242,   276,  -242,   118,  -242,   118,
    -242,   118,  -242,  7759,  -242,  7793,  -242,  7759,  -242,  7793,
    -242,  7893,  -242,  7877,  -242,  7877,  -242,  7877,  -242,  7877,
    -242,  7893,  -242,  7777,  -242,  7861,  -242,  7470,  -242,  7591,
    -242,  7904,  -242,  7176,  -242,   478,  -242,   478,  -242,   118,
    -242,   118,  -242,  -242,  -242,   162,   210,  -242,  -242,  6239,
    -242,  -242,  -242,  -242,   -27,   177,  -242,  6301,  -242,  -242,
    -242,  6363,  6425,  -242,  -242,   907,   254,  -242,   192,  -242,
    -242,   969,   264,  -242,    73,   172,  -242,  -242,   205,  -242,
    -242,  7596,  -242,  7596,  -242,  -242,  6487,  -242,  6549,  6611,
     192,  6673,  6735,  6797,  -242,  -242,  -242,  -242,   269,  -242,
    -242,   272,  -242,  -242,  -242,  -242,   207,  -242,  -242,    35,
    -242,  -242,  6859,  6921,  6983,  7045,  -242,  -242,  -242,  -242
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,   189,   198,   199,   200,   201,   202,     0,   203,     0,
       0,   190,   191,   192,   194,    92,    93,    89,     3,   208,
     209,   210,    10,    10,     0,    10,     0,    10,   195,   197,
     196,    69,    70,    10,    10,     0,     0,     0,     0,     0,
       0,   118,    25,    28,     4,    33,    29,   115,   116,     0,
      84,    10,     0,    85,   120,   100,    87,    86,    88,   121,
       0,   122,    26,    23,   193,   119,   114,   117,    10,    10,
     184,    69,    70,     0,     0,     0,     0,     0,    39,     0,
     205,     0,    17,     0,     0,   207,     0,   121,   122,   124,
     123,   156,   127,   157,   128,    90,    91,     0,     1,    15,
       0,     0,     6,     9,    11,    27,    24,    31,     5,    32,
      30,    34,    10,    10,    71,    72,   103,    80,    81,   155,
      57,     0,     0,    10,    10,   113,   101,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,     0,    10,    10,   104,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,     0,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,   125,   126,    10,    10,    10,   255,
     256,   185,   188,     0,    10,    10,    10,     0,    10,    10,
      10,     0,    10,     0,   204,    10,    13,    21,     0,   206,
      10,    10,    12,    19,     7,    10,    59,    51,     0,     0,
      53,    64,     0,     0,    82,    58,    57,    83,    97,    95,
      96,    73,    76,    10,    75,   105,    98,   109,    94,    73,
      10,   107,   111,    10,    10,     0,     0,   212,   218,   219,
     214,   213,   216,   215,   217,   225,   226,   227,   228,   229,
     220,   221,   222,   223,   224,   232,   253,    80,    81,   230,
     231,   233,   239,   240,   235,   234,   237,   236,   238,   246,
     247,   248,   249,   250,   241,   242,   243,   244,   245,   254,
     251,   252,   158,   129,   159,   130,   160,   131,   161,   132,
     162,   133,   176,   147,   177,   148,   179,   150,   180,   151,
     170,   141,   172,   143,   173,   144,   174,   145,   175,   146,
     171,   142,   178,   149,   167,   138,   166,   137,   165,   136,
     183,   154,   182,   153,   168,   139,   169,   140,   163,   134,
     164,   135,   181,   152,   186,     0,   257,    35,    36,    10,
      37,    41,    46,    40,     0,     0,    18,    10,    14,   211,
      16,    10,    10,    56,    60,    10,     0,    61,     0,    55,
      65,    10,     0,    66,    74,    77,    99,    74,    10,   110,
     112,     0,   106,     0,   108,   187,    10,    38,    10,    10,
       0,    10,    10,    10,    22,    20,     8,    52,     0,    63,
      54,     0,    68,   258,    43,    48,     0,    42,    47,     0,
      62,    67,    10,    10,    10,    10,    44,    49,    45,    50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -242,  -242,   133,  -242,  -242,  -242,   200,   -65,  -242,  -242,
    -242,  -242,  -242,   -38,     0,   197,  -242,   -63,    36,  -242,
     -57,   137,   -80,  -159,   -86,   -82,    18,  -117,    -4,  -242,
    -242,    -6,  -105,  -242,  -242,  -242,  -241,  -100,   112,  -242,
     124,  -242,   221,   277,   245,  -242,  -242,    13,  -242,   -51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    38,   104,   372,    39,    40,    84,    41,   221,   215,
     371,   367,    42,    43,   227,    45,    46,    47,    78,    79,
      48,   228,   229,   230,    49,    50,    51,   244,   245,    52,
      53,    54,    55,    56,    57,    58,   246,   247,    59,    60,
      61,   125,   126,    62,    63,    74,    64,    65,    66,    67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,   209,   386,   398,   210,   -58,   399,   251,   110,   386,
     -57,   113,   205,   102,    82,   206,   235,   235,   235,   235,
     202,    68,    75,    76,   252,    81,    83,    86,    73,   211,
     199,   200,   225,   233,   207,    69,    77,   241,   249,   234,
     237,   242,   217,    98,   225,   116,   208,   218,   225,   123,
      99,   124,   103,    95,  -102,   100,   -78,   -79,   238,   238,
     239,   239,    83,   374,   120,   424,   240,   240,   425,   375,
     379,    96,   248,   248,   379,   377,    97,   212,   213,   380,
     400,   378,   223,   107,  -103,   381,  -103,   218,   108,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   203,   279,
     280,   109,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     112,   300,   301,   365,   236,   236,   236,   236,   235,   394,
     276,   243,   250,    87,    87,   235,    70,   386,   376,   201,
     235,   235,   382,   389,   390,    88,    88,   384,   354,   120,
     121,   385,   299,   117,   387,   395,   356,   357,   358,   241,
     249,   361,   362,   242,   225,   118,   204,   366,   238,   122,
     239,   120,   369,   370,   214,   238,   240,   239,   238,   238,
     239,   239,   248,   240,   216,   219,   240,   240,   225,   248,
     -80,   -81,   248,   248,   220,   383,   379,   401,   360,   224,
     402,   378,   364,   225,   123,   359,   124,   379,   197,   410,
     198,   355,  -102,   379,   -78,   373,   368,    22,   225,   113,
      23,    22,    24,   222,    23,   378,    24,   422,   396,   101,
     423,    71,    72,   111,   114,   115,   253,   363,   254,   379,
     232,   392,   379,    71,    72,    26,   236,   379,   277,    26,
     114,   115,   255,   236,   256,   378,     0,     0,   236,   236,
     278,   388,   388,   391,   393,   225,    89,    90,    92,    94,
     277,   149,   255,   403,   256,   225,   235,   106,   235,  -103,
     225,  -103,   278,   225,  -103,   408,  -103,     0,     0,    71,
      72,   411,     0,   114,   115,   384,   409,   387,     0,   385,
      91,    93,   378,   173,   174,   175,   412,     0,     0,   105,
     416,   420,   378,   238,   421,   239,     0,   378,   119,   404,
     378,   240,     0,   405,   406,     0,     0,   248,     0,     0,
     171,   172,   173,   174,   175,     0,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,     0,     0,   413,   397,
     414,   415,     0,   417,   418,     0,     0,     0,     0,     0,
       0,   194,   195,   196,     0,   407,   197,     0,   198,     0,
       0,   407,     0,     0,   426,   427,   428,   429,     0,     0,
       0,     0,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   419,   236,   197,   236,   198,     0,     0,
       0,     0,     0,     0,     0,     0,   303,   305,   307,   309,
     311,   313,   315,   317,   319,   321,   323,   325,   327,   329,
     331,   333,   335,   337,   339,   341,   343,   345,   347,     0,
       0,   349,   351,   353,     0,     0,     0,     0,   302,   304,
     306,   308,   310,   312,   314,   316,   318,   320,   322,   324,
     326,   328,   330,   332,   334,   336,   338,   340,   342,   344,
     346,     0,     0,   348,   350,   352,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     0,    22,
       0,     0,    23,     0,    24,     0,     0,     0,     0,     0,
       0,     0,     0,   171,   172,   173,   174,   175,     0,     0,
       0,     0,     0,     0,    25,     0,     0,    26,    27,     0,
       0,     0,   -10,    28,    29,    30,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,   225,    19,    20,    21,
       0,    22,     0,     0,    23,     0,    24,     0,     0,     0,
       0,    31,    32,   194,   195,   196,     0,     0,   197,     0,
     198,    33,    34,    35,    36,    37,    25,   226,     0,    26,
      27,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,    16,    17,   225,    19,
      20,    21,     0,    22,     0,     0,    23,     0,    24,     0,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    25,   231,
       0,    26,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
       0,    19,    20,    21,     0,    22,     0,     0,    23,     0,
      24,     0,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      25,    80,     0,    26,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
      16,    17,     0,    19,    20,    21,     0,    22,     0,     0,
      23,     0,    24,     0,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    25,     0,     0,    26,    27,    85,     0,     0,
       0,    28,    29,    30,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,     0,    19,    20,    21,     0,    22,
       0,     0,    23,     0,    24,     0,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    25,     0,     0,    26,    27,     0,
       0,     0,   -10,    28,    29,    30,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,     0,    19,    20,    21,
       0,    22,     0,     0,    23,     0,    24,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    25,     0,     0,    26,
      27,     0,     0,     0,   -10,    28,    29,    30,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,    16,    17,   225,    19,
      20,    21,     0,    22,     0,     0,    23,     0,    24,     0,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    25,     0,
       0,    26,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
     225,    19,    20,    21,     0,    22,     0,     0,    23,     0,
      24,     0,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      25,     0,     0,    26,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
      16,    17,     0,    19,    20,    21,     0,    22,     0,     0,
      23,     0,    24,     0,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    25,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    29,    30,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,     0,    19,    20,    21,     0,    22,
       0,     0,    23,     0,    24,     0,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    25,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,     0,    19,    20,    21,
       0,    22,     0,     0,    23,     0,    24,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    25,     0,     0,    26,
      27,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,    16,    17,     0,    19,
      20,    21,     0,    22,     0,     0,    23,     0,    24,     0,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    25,     0,
       0,    26,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
       0,    19,    20,    21,     0,    22,     0,     0,    23,     0,
      24,     0,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      25,     0,     0,    26,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
      16,    17,     0,    19,    20,    21,     0,    22,     0,     0,
      23,     0,    24,     0,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    25,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    29,    30,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,     0,    19,    20,    21,     0,    22,
       0,     0,    23,     0,    24,     0,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    25,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,     0,    19,    20,    21,
       0,    22,     0,     0,    23,     0,    24,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    25,     0,     0,    26,
      27,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,    16,    17,     0,    19,
      20,    21,     0,    22,     0,     0,    23,     0,    24,     0,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    25,     0,
       0,    26,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
       0,    19,    20,    21,     0,    22,     0,     0,    23,     0,
      24,     0,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      25,     0,     0,    26,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
      16,    17,     0,    19,    20,    21,     0,    22,     0,     0,
      23,     0,    24,     0,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    25,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    29,    30,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,     0,    19,    20,    21,     0,    22,
       0,     0,    23,     0,    24,     0,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    25,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,     0,    19,    20,    21,
       0,    22,     0,     0,    23,     0,    24,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    25,     0,     0,    26,
      27,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,    16,    17,     0,    19,
      20,    21,     0,    22,     0,     0,    23,     0,    24,     0,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    25,     0,
       0,    26,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
       0,    19,    20,    21,     0,    22,     0,     0,    23,     0,
      24,     0,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      25,     0,     0,    26,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
      16,    17,     0,    19,    20,    21,     0,    22,     0,     0,
      23,     0,    24,     0,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    25,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    29,    30,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,     0,    19,    20,    21,     0,    22,
       0,     0,    23,     0,    24,     0,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    25,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,     0,    19,    20,    21,
       0,    22,     0,     0,    23,     0,    24,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    25,     0,     0,    26,
      27,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,    16,    17,     0,    19,
      20,    21,     0,    22,     0,     0,    23,     0,    24,     0,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    25,     0,
       0,    26,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
       0,    19,    20,    21,     0,    22,     0,     0,    23,     0,
      24,     0,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      25,     0,     0,    26,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
      16,    17,     0,    19,    20,    21,     0,    22,     0,     0,
      23,     0,    24,     0,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    25,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    29,    30,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,     0,    19,    20,    21,     0,    22,
       0,     0,    23,     0,    24,     0,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    25,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,     0,    19,    20,    21,
       0,    22,     0,     0,    23,     0,    24,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    25,     0,     0,    26,
      27,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,    16,    17,     0,    19,
      20,    21,     0,    22,     0,     0,    23,     0,    24,     0,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    25,     0,
       0,    26,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
       0,    19,    20,    21,     0,    22,     0,     0,    23,     0,
      24,     0,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      25,     0,     0,    26,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
      16,    17,     0,    19,    20,    21,     0,    22,     0,     0,
      23,     0,    24,     0,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    25,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    29,    30,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,     0,    19,    20,    21,     0,    22,
       0,     0,    23,     0,    24,     0,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    25,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,     0,    19,    20,    21,
       0,    22,     0,     0,    23,     0,    24,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    25,     0,     0,    26,
      27,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,    16,    17,     0,    19,
      20,    21,     0,    22,     0,     0,    23,     0,    24,     0,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    25,     0,
       0,    26,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
       0,    19,    20,    21,     0,    22,     0,     0,    23,     0,
      24,     0,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      25,     0,     0,    26,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
      16,    17,     0,    19,    20,    21,     0,    22,     0,     0,
      23,     0,    24,     0,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    25,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    29,    30,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,     0,    19,    20,    21,     0,    22,
       0,     0,    23,     0,    24,     0,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    25,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,     0,    19,    20,    21,
       0,    22,     0,     0,    23,     0,    24,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    25,     0,     0,    26,
      27,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,    16,    17,     0,    19,
      20,    21,     0,    22,     0,     0,    23,     0,    24,     0,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    25,     0,
       0,    26,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
       0,    19,    20,    21,     0,    22,     0,     0,    23,     0,
      24,     0,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      25,     0,     0,    26,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
      16,    17,     0,    19,    20,    21,     0,    22,     0,     0,
      23,     0,    24,     0,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    25,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    29,    30,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,     0,    19,    20,    21,     0,    22,
       0,     0,    23,     0,    24,     0,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    25,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,     0,    19,    20,    21,
       0,    22,     0,     0,    23,     0,    24,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    25,     0,     0,    26,
      27,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,    16,    17,     0,    19,
      20,    21,     0,    22,     0,     0,    23,     0,    24,     0,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    25,     0,
       0,    26,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
       0,    19,    20,    21,     0,    22,     0,     0,    23,     0,
      24,     0,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      25,     0,     0,    26,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
      16,    17,     0,    19,    20,    21,     0,    22,     0,     0,
      23,     0,    24,     0,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    25,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    29,    30,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,     0,    19,    20,    21,     0,    22,
       0,     0,    23,     0,    24,     0,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    25,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,     0,    19,    20,    21,
       0,    22,     0,     0,    23,     0,    24,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    25,     0,     0,    26,
      27,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,    16,    17,     0,    19,
      20,    21,     0,    22,     0,     0,    23,     0,    24,     0,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    25,     0,
       0,    26,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
       0,    19,    20,    21,     0,    22,     0,     0,    23,     0,
      24,     0,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      25,     0,     0,    26,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
      16,    17,     0,    19,    20,    21,     0,    22,     0,     0,
      23,     0,    24,     0,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    25,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    29,    30,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,     0,    19,    20,    21,     0,    22,
       0,     0,    23,     0,    24,     0,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    25,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,     0,    19,    20,    21,
       0,    22,     0,     0,    23,     0,    24,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    25,     0,     0,    26,
      27,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,    16,    17,     0,    19,
      20,    21,     0,    22,     0,     0,    23,     0,    24,     0,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    25,     0,
       0,    26,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
       0,    19,    20,    21,     0,    22,     0,     0,    23,     0,
      24,     0,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      25,     0,     0,    26,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
      16,    17,     0,    19,    20,    21,     0,    22,     0,     0,
      23,     0,    24,     0,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    25,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    29,    30,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,     0,    19,    20,    21,     0,    22,
       0,     0,    23,     0,    24,     0,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    25,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,     0,    19,    20,    21,
       0,    22,     0,     0,    23,     0,    24,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    25,     0,     0,    26,
      27,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,    16,    17,     0,    19,
      20,    21,     0,    22,     0,     0,    23,     0,    24,     0,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    25,     0,
       0,    26,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
       0,    19,    20,    21,     0,    22,     0,     0,    23,     0,
      24,     0,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      25,     0,     0,    26,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
      16,    17,     0,    19,    20,    21,     0,    22,     0,     0,
      23,     0,    24,     0,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    25,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    29,    30,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,     0,    19,    20,    21,     0,    22,
       0,     0,    23,     0,    24,     0,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    25,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,     0,    19,    20,    21,
       0,    22,     0,     0,    23,     0,    24,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    25,     0,     0,    26,
      27,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,    16,    17,     0,    19,
      20,    21,     0,    22,     0,     0,    23,     0,    24,     0,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    25,     0,
       0,    26,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
       0,    19,    20,    21,     0,    22,     0,     0,    23,     0,
      24,     0,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      25,     0,     0,    26,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
      16,    17,     0,    19,    20,    21,     0,    22,     0,     0,
      23,     0,    24,     0,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    25,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    29,    30,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,     0,    19,    20,    21,     0,    22,
       0,     0,    23,     0,    24,     0,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    25,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,     0,    19,    20,    21,
       0,    22,     0,     0,    23,     0,    24,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    25,     0,     0,    26,
      27,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,    16,    17,     0,    19,
      20,    21,     0,    22,     0,     0,    23,     0,    24,     0,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    25,     0,
       0,    26,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
       0,    19,    20,    21,     0,    22,     0,     0,    23,     0,
      24,     0,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      25,     0,     0,    26,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
      16,    17,     0,    19,    20,    21,     0,    22,     0,     0,
      23,     0,    24,     0,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    25,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    29,    30,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,     0,    19,    20,    21,     0,    22,
       0,     0,    23,     0,    24,     0,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    25,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,     0,    19,    20,    21,
       0,    22,     0,     0,    23,     0,    24,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    25,     0,     0,    26,
      27,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,    16,    17,     0,    19,
      20,    21,     0,    22,     0,     0,    23,     0,    24,     0,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    25,     0,
       0,    26,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
       0,    19,    20,    21,     0,    22,     0,     0,    23,     0,
      24,     0,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      25,     0,     0,    26,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
      16,    17,     0,    19,    20,    21,     0,    22,     0,     0,
      23,     0,    24,     0,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    25,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    29,    30,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,     0,    19,    20,    21,     0,    22,
       0,     0,    23,     0,    24,     0,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    25,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,     0,    19,    20,    21,
       0,    22,     0,     0,    23,     0,    24,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    25,     0,     0,    26,
      27,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,    16,    17,     0,    19,
      20,    21,     0,    22,     0,     0,    23,     0,    24,     0,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    25,     0,
       0,    26,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
       0,    19,    20,    21,     0,    22,     0,     0,    23,     0,
      24,     0,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      25,     0,     0,    26,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
      16,    17,     0,    19,    20,    21,     0,    22,     0,     0,
      23,     0,    24,     0,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    25,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    29,    30,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,     0,    19,    20,    21,     0,    22,
       0,     0,    23,     0,    24,     0,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    25,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,     0,    19,    20,    21,
       0,    22,     0,     0,    23,     0,    24,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    25,     0,     0,    26,
      27,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,    16,    17,     0,    19,
      20,    21,     0,    22,     0,     0,    23,     0,    24,     0,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    25,     0,
       0,    26,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
       0,    19,    20,    21,     0,    22,     0,     0,    23,     0,
      24,     0,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      25,     0,     0,    26,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
      16,    17,     0,    19,    20,    21,     0,    22,     0,     0,
      23,     0,    24,     0,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    25,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    29,    30,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,     0,    19,    20,    21,     0,    22,
       0,     0,    23,     0,    24,     0,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    25,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,     0,    19,    20,    21,
       0,    22,     0,     0,    23,     0,    24,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    25,     0,     0,    26,
      27,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,    16,    17,     0,    19,
      20,    21,     0,    22,     0,     0,    23,     0,    24,     0,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    25,     0,
       0,    26,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
       0,    19,    20,    21,     0,    22,     0,     0,    23,     0,
      24,     0,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      25,     0,     0,    26,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
      16,    17,     0,    19,    20,    21,     0,    22,     0,     0,
      23,     0,    24,     0,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    25,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    29,    30,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,     0,    19,    20,    21,     0,    22,
       0,     0,    23,     0,    24,     0,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    25,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,     0,    19,    20,    21,
       0,    22,     0,     0,    23,     0,    24,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    25,     0,     0,    26,
      27,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,    16,    17,     0,    19,
      20,    21,     0,    22,     0,     0,    23,     0,    24,     0,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    25,     0,
       0,    26,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
       0,    19,    20,    21,     0,    22,     0,     0,    23,     0,
      24,     0,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      25,     0,     0,    26,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
      16,    17,     0,    19,    20,    21,     0,    22,     0,     0,
      23,     0,    24,     0,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    25,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    29,    30,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,     0,    19,    20,    21,     0,    22,
       0,     0,    23,     0,    24,     0,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    25,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,     0,    19,    20,    21,
       0,    22,     0,     0,    23,     0,    24,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    25,     0,     0,    26,
      27,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,    16,    17,     0,    19,
      20,    21,     0,    22,     0,     0,    23,     0,    24,     0,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    25,     0,
       0,    26,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
       0,    19,    20,    21,     0,    22,     0,     0,    23,     0,
      24,     0,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      25,     0,     0,    26,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
      16,    17,     0,    19,    20,    21,     0,    22,     0,     0,
      23,     0,    24,     0,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    25,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    29,    30,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,     0,    19,    20,    21,     0,    22,
       0,     0,    23,     0,    24,     0,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    25,     0,     0,    26,    27,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,     0,    19,    20,    21,
       0,    22,     0,     0,    23,     0,    24,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    25,     0,     0,    26,
      27,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,    16,    17,     0,    19,
      20,    21,     0,    22,     0,     0,    23,     0,    24,     0,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    25,     0,
       0,    26,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,     1,     2,     3,     4,     5,     6,     0,     8,
       0,    10,     0,    11,    12,    13,    14,    15,    16,    17,
       0,    19,    20,    21,     0,    22,     0,     0,    23,     0,
      24,     0,     0,     0,     0,   114,   115,     0,     0,     0,
       0,   171,   172,   173,   174,   175,     0,    35,    36,    37,
      25,     0,     0,    26,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     1,     2,     3,     4,     5,     6,     0,
       8,     0,    10,     0,    11,    12,    13,    14,    15,    16,
      17,     0,    19,    20,    21,     0,    22,     0,     0,    23,
       0,    24,     0,     0,     0,     0,     0,    71,    72,   192,
     193,   194,   195,   196,     0,     0,   197,     0,   198,    35,
      36,    25,     0,     0,    26,    27,     0,     0,     0,     0,
      28,    29,    30,     0,     1,     2,     3,     4,     5,     6,
       0,     8,     0,    10,     0,    11,    12,    13,    14,    15,
      16,    17,     0,    19,    20,    21,     0,    22,     0,     0,
      23,     0,    24,     0,     0,     0,     0,     0,    71,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      35,    36,    25,     0,     0,    26,    27,     0,     0,     0,
       0,    28,    29,    30,     0,     1,     2,     3,     4,     5,
       6,     0,     8,     0,    10,     0,    11,    12,    13,    14,
      15,    16,    17,     0,    19,    20,    21,     0,    22,     0,
       0,    23,     0,    24,     0,     0,     0,     0,     0,   114,
     115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    35,    36,    25,     0,     0,    26,    27,     0,     0,
       0,     0,    28,    29,    30,     0,     1,     2,     3,     4,
       5,     6,     0,     8,     0,    10,     0,    11,    12,    13,
      14,    15,    16,    17,     0,    19,    20,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    35,    36,    25,     0,     0,     0,    27,     0,
       0,     0,     0,    28,    29,    30,     0,     1,     2,     3,
       4,     5,     6,     0,     8,     0,    10,     0,    11,    12,
      13,    14,    15,    16,    17,     0,    19,    20,    21,     0,
       0,     0,     0,     0,     0,   171,   172,   173,   174,   175,
       0,    31,    32,     0,     0,   180,   181,   182,   183,   184,
     185,    33,    34,    35,    36,    25,     0,     0,     0,    27,
       0,     0,     0,     0,    28,    29,    30,     0,     1,     2,
       3,     4,     5,     6,     0,     8,     0,    10,     0,    11,
      12,    13,    14,    15,    16,    17,     0,    19,    20,    21,
     189,   190,   191,   192,   193,   194,   195,   196,     0,     0,
     197,     0,   198,    32,     0,     0,     0,     0,     0,     0,
       0,     0,    33,    34,    35,    36,    25,     0,     0,     0,
      27,     0,     0,     0,     0,    28,    29,    30,     0,     1,
       2,     3,     4,     5,     6,     0,     8,     0,    10,     0,
      11,    12,    13,    14,    15,    16,    17,     0,    19,    20,
      21,     0,     0,     0,     0,     0,   171,   172,   173,   174,
     175,     0,     0,    71,    72,     0,   180,   181,   182,   183,
     184,   185,     0,     0,     0,    35,    36,    25,     0,     0,
       0,    27,     0,     0,     0,     0,    28,    29,    30,     0,
       1,     2,     3,     4,     5,     6,     0,     8,     0,    10,
       0,    11,    12,    13,    14,    15,    16,    17,     0,    19,
      20,    21,   190,   191,   192,   193,   194,   195,   196,     0,
     127,   197,     0,   198,   114,   115,   128,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    35,    36,    25,     0,
       0,     0,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   150,     0,     0,     0,     0,     0,   151,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -80,
       0,     0,     0,     0,     0,     0,     0,    35,    36,     0,
       0,     0,     0,     0,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
       0,   168,   169,   170,   171,   172,   173,   174,   175,     0,
       0,   177,     0,   179,   180,   181,   182,   183,   184,   185,
       0,   -81,   171,   172,   173,   174,   175,     0,     0,   177,
       0,   179,   180,   181,   182,   183,   184,   185,   171,   172,
     173,   174,   175,     0,     0,     0,     0,     0,   180,   181,
     182,   183,   184,   185,     0,     0,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,     0,     0,   197,
       0,   198,     0,     0,     0,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,     0,   197,     0,   198,
       0,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,     0,     0,   197,     0,   198,   171,   172,   173,   174,
     175,     0,     0,     0,     0,     0,   180,   181,   182,   183,
     184,   185,   171,   172,   173,   174,   175,     0,     0,     0,
       0,     0,   180,     0,     0,     0,     0,   185,   171,   172,
     173,   174,   175,     0,     0,     0,     0,     0,     0,   171,
     172,   173,   174,   175,     0,     0,     0,     0,     0,     0,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
       0,   197,     0,   198,     0,     0,     0,     0,   190,   191,
     192,   193,   194,   195,   196,   127,     0,   197,     0,   198,
       0,   128,     0,     0,   190,   191,   192,   193,   194,   195,
     196,     0,     0,   197,     0,   198,   191,   192,   193,   194,
     195,   196,     0,     0,   197,     0,   198,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   150,     0,     0,
       0,     0,     0,   151,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,     0,   168,   169,   170
};

static const yytype_int16 yycheck[] =
{
       0,    30,   243,    30,    33,    57,    33,   124,    46,   250,
      57,    57,    30,    20,    53,    33,   121,   122,   123,   124,
      13,    34,    22,    23,   124,    25,    65,    27,    10,    58,
      68,    69,    21,   113,    20,    34,    20,   123,   124,   121,
     122,   123,    53,     0,    21,    51,    32,    58,    21,   101,
      53,   103,    59,    20,   101,    58,   103,   103,   123,   124,
     123,   124,    65,    52,    51,    30,   123,   124,    33,    58,
     229,    20,   123,   124,   233,    52,    20,   106,   107,    52,
     107,    58,    53,    25,   101,    58,   103,    58,    21,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   101,   147,
     148,    25,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      57,   169,   170,   213,   121,   122,   123,   124,   243,   256,
     146,   123,   124,    31,    32,   250,     3,   388,   228,     3,
     255,   256,   232,   253,   254,    31,    32,   243,     3,   146,
     103,   243,   168,    51,   250,     3,   204,   205,   206,   255,
     256,   209,   210,   255,    21,    51,    27,   215,   243,   103,
     243,   168,   220,   221,    52,   250,   243,   250,   253,   254,
     253,   254,   243,   250,    20,    56,   253,   254,    21,   250,
     103,   103,   253,   254,    34,    52,   365,    30,   208,    34,
      33,    58,   212,    21,   101,    32,   103,   376,   100,   378,
     102,   203,   101,   382,   103,   225,    20,    26,    21,    57,
      29,    26,    31,   100,    29,    58,    31,    30,    28,    39,
      33,    98,    99,    46,    98,    99,   101,   211,   103,   408,
     113,   255,   411,    98,    99,    54,   243,   416,   146,    54,
      98,    99,   101,   250,   103,    58,    -1,    -1,   255,   256,
     146,   253,   254,   255,   256,    21,    31,    32,    33,    34,
     168,    60,   101,   106,   103,    21,   391,    42,   393,   101,
      21,   103,   168,    21,   101,   375,   103,    -1,    -1,    98,
      99,   381,    -1,    98,    99,   391,    52,   393,    -1,   391,
      33,    34,    58,    37,    38,    39,    52,    -1,    -1,    42,
     400,    52,    58,   388,    52,   388,    -1,    58,    51,   367,
      58,   388,    -1,   371,   372,    -1,    -1,   388,    -1,    -1,
      35,    36,    37,    38,    39,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,   396,   359,
     398,   399,    -1,   401,   402,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    96,    97,    -1,   375,   100,    -1,   102,    -1,
      -1,   381,    -1,    -1,   422,   423,   424,   425,    -1,    -1,
      -1,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,   403,   391,   100,   393,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,   196,   197,   198,    -1,    -1,    -1,    -1,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,   196,   197,   198,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    26,
      -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      -1,    98,    99,    95,    96,    97,    -1,    -1,   100,    -1,
     102,   108,   109,   110,   111,   112,    51,    52,    -1,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    26,    -1,    -1,    29,    -1,    31,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    51,    52,
      -1,    54,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    26,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
      51,    52,    -1,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    -1,    26,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,    51,    -1,    -1,    54,    55,    56,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    26,
      -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      -1,    26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    26,    -1,    -1,    29,    -1,    31,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    -1,    26,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    26,
      -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      -1,    26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    26,    -1,    -1,    29,    -1,    31,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    26,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    -1,    26,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    26,
      -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      -1,    26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    26,    -1,    -1,    29,    -1,    31,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    26,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    -1,    26,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    26,
      -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      -1,    26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    26,    -1,    -1,    29,    -1,    31,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    26,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    -1,    26,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    26,
      -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      -1,    26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    26,    -1,    -1,    29,    -1,    31,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    26,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    -1,    26,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    26,
      -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      -1,    26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    26,    -1,    -1,    29,    -1,    31,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    26,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    -1,    26,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    26,
      -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      -1,    26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    26,    -1,    -1,    29,    -1,    31,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    26,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    -1,    26,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    26,
      -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      -1,    26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    26,    -1,    -1,    29,    -1,    31,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    26,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    -1,    26,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    26,
      -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      -1,    26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    26,    -1,    -1,    29,    -1,    31,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    26,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    -1,    26,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    26,
      -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      -1,    26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    26,    -1,    -1,    29,    -1,    31,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    26,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    -1,    26,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    26,
      -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      -1,    26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    26,    -1,    -1,    29,    -1,    31,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    26,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    -1,    26,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    26,
      -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      -1,    26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    26,    -1,    -1,    29,    -1,    31,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    26,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    -1,    26,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    26,
      -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      -1,    26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    26,    -1,    -1,    29,    -1,    31,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    26,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    -1,    26,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    26,
      -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      -1,    26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    26,    -1,    -1,    29,    -1,    31,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    26,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    -1,    26,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    26,
      -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      -1,    26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    26,    -1,    -1,    29,    -1,    31,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    26,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    -1,    26,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    26,
      -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      -1,    26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    26,    -1,    -1,    29,    -1,    31,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    26,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    -1,    26,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    26,
      -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      -1,    26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    26,    -1,    -1,    29,    -1,    31,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    26,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    -1,    26,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    26,
      -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      -1,    26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    26,    -1,    -1,    29,    -1,    31,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    26,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    -1,    26,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    26,
      -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      -1,    26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    26,    -1,    -1,    29,    -1,    31,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    26,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    -1,    26,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    26,
      -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      -1,    26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    26,    -1,    -1,    29,    -1,    31,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    26,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    -1,    26,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    26,
      -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      -1,    26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    26,    -1,    -1,    29,    -1,    31,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    26,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    -1,   110,   111,   112,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    12,    -1,    14,    15,    16,    17,    18,    19,
      20,    -1,    22,    23,    24,    -1,    26,    -1,    -1,    29,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    98,    99,    93,
      94,    95,    96,    97,    -1,    -1,   100,    -1,   102,   110,
     111,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,
      60,    61,    62,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    -1,    26,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    98,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     110,   111,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,    24,    -1,    26,    -1,
      -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   111,    51,    -1,    -1,    54,    55,    -1,    -1,
      -1,    -1,    60,    61,    62,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,    51,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    12,    -1,    14,    15,
      16,    17,    18,    19,    20,    -1,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      -1,    98,    99,    -1,    -1,    45,    46,    47,    48,    49,
      50,   108,   109,   110,   111,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    60,    61,    62,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      90,    91,    92,    93,    94,    95,    96,    97,    -1,    -1,
     100,    -1,   102,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,   109,   110,   111,    51,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    12,    -1,
      14,    15,    16,    17,    18,    19,    20,    -1,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    -1,    -1,    98,    99,    -1,    45,    46,    47,    48,
      49,    50,    -1,    -1,    -1,   110,   111,    51,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    91,    92,    93,    94,    95,    96,    97,    -1,
      34,   100,    -1,   102,    98,    99,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,   111,    51,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    34,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,    -1,
      -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      -1,    83,    84,    85,    35,    36,    37,    38,    39,    -1,
      -1,    42,    -1,    44,    45,    46,    47,    48,    49,    50,
      -1,   103,    35,    36,    37,    38,    39,    -1,    -1,    42,
      -1,    44,    45,    46,    47,    48,    49,    50,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    -1,    -1,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    -1,    -1,   100,
      -1,   102,    -1,    -1,    -1,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    -1,    -1,   100,    -1,   102,
      -1,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    -1,    -1,   100,    -1,   102,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    50,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    -1,
      -1,   100,    -1,   102,    -1,    -1,    -1,    -1,    91,    92,
      93,    94,    95,    96,    97,    34,    -1,   100,    -1,   102,
      -1,    40,    -1,    -1,    91,    92,    93,    94,    95,    96,
      97,    -1,    -1,   100,    -1,   102,    92,    93,    94,    95,
      96,    97,    -1,    -1,   100,    -1,   102,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    34,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    83,    84,    85
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    26,    29,    31,    51,    54,    55,    60,    61,
      62,    98,    99,   108,   109,   110,   111,   112,   114,   117,
     118,   120,   125,   126,   127,   128,   129,   130,   133,   137,
     138,   139,   142,   143,   144,   145,   146,   147,   148,   151,
     152,   153,   156,   157,   159,   160,   161,   162,    34,    34,
       3,    98,    99,   139,   158,   127,   127,    20,   131,   132,
      52,   127,    53,    65,   119,    56,   127,   151,   153,   157,
     157,   156,   157,   156,   157,    20,    20,    20,     0,    53,
      58,   119,    20,    59,   115,   156,   157,    25,    21,    25,
     126,   128,    57,    57,    98,    99,   144,   151,   153,   156,
     160,   103,   103,   101,   103,   154,   155,    34,    40,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,   155,
      34,    40,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    83,    84,
      85,    35,    36,    37,    38,    39,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,   100,   102,   126,
     126,     3,    13,   101,    27,    30,    33,    20,    32,    30,
      33,    58,   106,   107,    52,   122,    20,    53,    58,    56,
      34,   121,   115,    53,    34,    21,    52,   127,   134,   135,
     136,    52,   134,   135,   138,   145,   160,   138,   120,   130,
     133,   137,   138,   139,   140,   141,   149,   150,   162,   137,
     139,   140,   150,   101,   103,   101,   103,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   144,   151,   153,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   144,
     126,   126,   156,   157,   156,   157,   156,   157,   156,   157,
     156,   157,   156,   157,   156,   157,   156,   157,   156,   157,
     156,   157,   156,   157,   156,   157,   156,   157,   156,   157,
     156,   157,   156,   157,   156,   157,   156,   157,   156,   157,
     156,   157,   156,   157,   156,   157,   156,   157,   156,   157,
     156,   157,   156,   157,     3,   139,   126,   126,   126,    32,
     127,   126,   126,   131,   127,   135,   126,   124,    20,   126,
     126,   123,   116,   127,    52,    58,   135,    52,    58,   136,
      52,    58,   135,    52,   137,   138,   149,   137,   139,   150,
     150,   139,   141,   139,   140,     3,    28,   127,    30,    33,
     107,    30,    33,   106,   126,   126,   126,   127,   135,    52,
     136,   135,    52,   126,   126,   126,   135,   126,   126,   127,
      52,    52,    30,    33,    30,    33,   126,   126,   126,   126
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   113,   114,   114,   114,   114,   115,   116,   115,   115,
     118,   117,   117,   119,   119,   121,   120,   122,   120,   123,
     120,   124,   120,   125,   125,   126,   126,   126,   127,   127,
     127,   128,   128,   129,   129,   130,   130,   131,   131,   132,
     132,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   134,   134,   135,   135,   135,   136,   137,   137,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   139,
     139,   139,   139,   140,   140,   141,   141,   141,   142,   142,
     142,   142,   143,   143,   144,   144,   145,   145,   145,   146,
     146,   146,   147,   148,   149,   149,   149,   149,   150,   150,
     151,   151,   152,   152,   153,   154,   154,   154,   154,   155,
     155,   155,   155,   155,   156,   156,   156,   156,   156,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   158,   158,   158,   158,   159,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   162,   162
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     0,     4,     1,
       0,     2,     3,     2,     3,     0,     4,     0,     4,     0,
       5,     0,     5,     1,     2,     1,     1,     2,     1,     1,
       2,     2,     2,     1,     2,     4,     4,     3,     4,     1,
       3,     4,     6,     6,     8,     8,     4,     6,     6,     8,
       8,     1,     3,     1,     3,     2,     2,     1,     1,     3,
       4,     4,     6,     5,     3,     4,     4,     6,     5,     1,
       1,     2,     2,     1,     2,     1,     1,     2,     1,     1,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     2,     1,     1,     2,     2,     3,     2,     3,     2,
       3,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     2,     3,     4,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     3,     2,     1,     1,
       1,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     6
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const yytype_int8 yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     1,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,   194,
       0,   196,     0,     0,   288,     0,   290,   184,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   190,     0,   192,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   188,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     297,   299,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   305,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   311,     0,   313,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   315,     0,   317,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   361,     0,   363,     0,     0,     0,     0,   483,
       0,   485,     0,     0,   487,     0,   489,     0,     0,     0,
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
       0,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   301,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   303,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   107,   109,   111,   113,
     115,   117,   119,   121,   123,   125,     0,   127,   129,   131,
     133,   135,   137,   139,     0,   142,   144,   146,     0,   148,
       0,     0,   150,     0,   152,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   154,     0,     0,   156,   158,     0,
       0,     0,   160,   162,   164,   166,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   182,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   168,   170,     0,     0,     0,     0,     0,     0,     0,
       0,   172,   174,   176,   178,   180,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   499,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   501,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   293,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   295,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   319,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   321,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   323,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   325,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   327,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   329,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   331,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   333,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   335,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   337,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   339,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   341,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   343,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   345,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   347,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   349,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   353,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   355,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   357,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   359,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   365,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   367,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   369,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   371,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   373,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   375,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   377,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   379,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   381,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   383,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   385,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   387,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   389,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   391,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   393,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   395,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   397,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   399,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   401,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   403,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   405,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   407,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   409,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   411,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   413,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   415,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   417,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   419,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   421,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   423,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   425,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   427,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   429,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   431,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   433,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   437,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   441,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   443,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   445,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   447,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   449,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   451,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   453,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   457,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   459,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   461,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   463,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   465,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   467,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   469,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   471,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   473,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   475,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   477,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   491,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   493,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   495,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   497,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   503,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   505,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   507,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   509,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   511,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   513,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   515,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   517,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   519,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   521,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   186,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   307,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     309,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   479,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   481,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    13,    15,    17,
      19,    21,     0,    23,     0,    25,     0,    27,    29,    31,
      33,    35,    37,    39,     0,    41,    43,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,     0,     0,    49,     0,
       0,     0,     0,    51,    53,    55,     0,    57,    59,    61,
      63,    65,    67,     0,    69,     0,    71,     0,    73,    75,
      77,    79,    81,    83,    85,     0,    87,    89,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,     0,     0,     0,    95,
       0,     0,     0,     0,    97,    99,   101,     0,     0,     0,
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
     198,     0,     0,     0,     0,     0,   200,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   202,   204,   206,   208,   210,   212,   214,   216,
     218,   220,   222,   224,   226,   228,   230,   232,   234,   236,
     238,   240,   244,     0,     0,     0,     0,     0,   246,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   242,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   250,   252,   254,   256,   258,
     260,   262,   264,   266,   268,   270,   272,   274,   276,   278,
       0,   280,   282,   284,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   286,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,    10,     0,    10,     0,    10,     0,    10,     0,    10,
       0,    69,     0,    69,     0,    69,     0,    69,     0,    69,
       0,    69,     0,    69,     0,    69,     0,    69,     0,    69,
       0,    69,     0,    69,     0,    69,     0,    69,     0,    69,
       0,    69,     0,    69,     0,    69,     0,    69,     0,    69,
       0,    69,     0,    69,     0,    69,     0,    70,     0,    70,
       0,    70,     0,    70,     0,    70,     0,    70,     0,    70,
       0,    70,     0,    70,     0,    70,     0,    70,     0,    70,
       0,    70,     0,    70,     0,    70,     0,    70,     0,    70,
       0,    70,     0,    70,     0,    70,     0,    70,     0,    70,
       0,    70,     0,    10,     0,    10,     0,    25,     0,    25,
       0,    25,     0,    25,     0,    25,     0,    25,     0,    25,
       0,    25,     0,    25,     0,    25,     0,    25,     0,    25,
       0,    25,     0,    25,     0,    25,     0,    25,     0,    10,
      25,     0,    25,     0,    25,     0,    25,     0,    25,     0,
      25,     0,    25,     0,    25,     0,    25,     0,    25,     0,
      25,     0,    25,     0,    25,     0,    25,     0,    25,     0,
      25,     0,    25,     0,    25,     0,    25,     0,    25,     0,
      25,     0,    10,     0,    84,     0,    10,     0,    85,     0,
     120,     0,   120,     0,   100,     0,   100,     0,   121,     0,
     121,     0,   121,     0,   121,     0,   121,     0,   121,     0,
     121,     0,   121,     0,   121,     0,   121,     0,   121,     0,
     121,     0,   121,     0,   121,     0,   121,     0,   121,     0,
     121,     0,   121,     0,   121,     0,   121,     0,   121,     0,
     121,     0,   121,     0,   122,     0,   122,     0,   122,     0,
     122,     0,   122,     0,   122,     0,   122,     0,   122,     0,
     122,     0,   122,     0,   122,     0,   122,     0,   122,     0,
     122,     0,   122,     0,   122,     0,   122,     0,   122,     0,
     122,     0,   122,     0,   122,     0,   122,     0,   119,     0,
     102,   119,     0,    10,     0,    10,     0,   121,     0,   122,
       0,    10,     0,    10,     0,   102,     0,    10,     0,    10,
       0,   113,     0,   113,     0,   101,     0,   101,     0,    10,
       0,    10,     0,    10,     0,    10,     0,    10,     0,    10,
       0,    10,     0,    10,     0,    10,     0,    10,     0,    10,
       0,    10,     0,    10,     0,    10,     0,    10,     0,    10,
       0,    10,     0,    10,     0,    10,     0,    10,     0,    10,
       0,   104,     0,   104,     0,    10,     0,    10,     0,    10,
       0,    10,     0,    10,     0,    10,     0,    10,     0,    10,
       0,    10,     0,    10,     0,    10,     0,    10,     0,    10,
       0,    10,     0,    10,     0,    10,     0,    10,     0,    10,
       0,    10,     0,    10,     0,    10,     0,    10,     0,    10,
       0,    10,     0,    10,     0,    10,     0,    10,     0,    10,
       0,    10,     0,    10,     0,    10,     0,    10,     0,    10,
       0,    10,     0,    10,     0,    10,     0,    10,     0,    10,
       0,    10,     0,    10,     0,    10,     0,    10,     0,    10,
       0,    10,     0,    10,     0,    10,     0,    10,     0,    10,
       0,    10,     0,    10,     0,    10,     0,    10,     0,    10,
       0,    10,     0,    10,     0,    10,     0,    10,     0,    10,
       0,    10,     0,   253,     0,   253,     0,   254,     0,   254,
       0,    10,     0,    10,     0,    10,     0,    10,     0,    10,
       0,    10,     0,    10,     0,    10,     0,    10,     0,    10,
       0,    10,     0,    10,     0,    10,     0,    10,     0,    10,
       0,    10,     0
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
  "DIRINLET", "DIROUTLET", "JIPITCHBASE_START", "JIPITCHBASE_END",
  "RAT_LITERAL", "DOUBLE_LITERAL", "PITCH_LITERAL", "SYMBOL_LITERAL",
  "GLOBALVAR", "PATCHERVAR", "LOCALVAR", "NAMEDPARAM", "BIF", "OF",
  "MAXFUNCTION", "NULLIFY", "IF_KW", "THEN_KW", "ELSE_KW", "WHILE_KW",
  "DO_KW", "FOR_KW", "IN_KW", "COLLECT_KW", "ASSIGN", "PLUS", "MINUS",
  "TIMES", "DIV", "DIVDIV", "APLUS", "LOGOR", "LOGAND", "LOGOREXT",
  "LOGANDEXT", "EQUAL", "LT", "GT", "LEQ", "GEQ", "NEQ", "OPEN",
  "CLOSEDROUND", "FUNDEF", "EMPTYFUNARGLIST", "PUSH", "POP", "STARTPARAMS",
  "COMMA", "ELLIPSIS", "BACHNULL", "BACHNIL", "ARGCOUNT", "EOL",
  "UNRECOGNIZED", "LIFT", "AMINUS", "ATIMES", "APOWOP", "ADIV", "ADIVDIV",
  "AREM", "ABITAND", "ABITXOR", "ABITOR", "ALSHIFT", "ARSHIFT", "ALOGAND",
  "ALOGANDEXT", "ALOGXOR", "ALOGOR", "ALOGOREXT", "ANTHOP", "AAPPLY",
  "ACONCAT", "ARCONCAT", "CONCAT", "LOGXOR", "BITOR", "BITXOR", "BITAND",
  "REPEAT", "RANGE", "LSHIFT", "RSHIFT", "R", "T", "REM", "UPLUS",
  "UMINUS", "POWOP", "NTHOP", "PICKOP", "APPLY", "ACCESS_UNWRAP",
  "LVALUESTEPPARAMS", "AS_KW", "WITH_KW", "LOGNOT", "BITNOT", "KEEP",
  "UNKEEP", "INIT", "$accept", "program", "funarg", "$@1", "funargList",
  "$@2", "liftedargList", "fundef", "$@3", "$@4", "$@5", "$@6",
  "listVector", "list", "sequence", "nullified", "nullifiedSequence",
  "whileloop", "forarg", "forargList", "forloop", "argsByPositionList",
  "argsByNameList", "argByName", "itemOrVar", "simpleFuncall", "sign",
  "lvalueSpecsItemForDot", "lvalueSpecsItemForNth", "dataflowHead",
  "dataflowFuncall", "funcall", "var", "localVar", "globalVar",
  "patcherVar", "lvalueSpecsUFinal", "lvalueSpecsFinal", "lvalue",
  "fakeLvalueHead", "fakeLvalue", "lvalueSpecsNonFinalized", "lvalueSpecs",
  "listEnd", "expr", "commaVector", "jiPitchBase", "item", "assignment",
  "conditional", YY_NULLPTR
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
#line 206 "bisonparserV3.y"
                {
    params->ast = new astConst(llll_get(), params->owner);
    *params->codeac = -1;
    code_dev_post ("parse: empty program\n");
}
#line 4062 "bisonparserV3.tab.c"
    break;

  case 3: /* program: NAMEDPARAM  */
#line 211 "bisonparserV3.y"
             {
    params->ast = new astConst(llll_get(), params->owner);
    *params->codeac = 0;
    code_dev_post ("parse: NAMEDPARAM: empty program\n");
    YYACCEPT;
}
#line 4073 "bisonparserV3.tab.c"
    break;

  case 4: /* program: sequence  */
#line 217 "bisonparserV3.y"
           {
    params->ast = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue);
    *params->codeac = -1;
    code_dev_post("codeac: %ld", *params->codeac);
    code_dev_post ("parse: sequence: program\n");
}
#line 4084 "bisonparserV3.tab.c"
    break;

  case 5: /* program: sequence NAMEDPARAM  */
#line 223 "bisonparserV3.y"
                      {
    params->ast = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeValue);
    code_dev_post("codeac: %ld", *params->codeac);
    code_dev_post ("parse: sequence NAMEDPARAM: program\n");
    YYACCEPT;
}
#line 4095 "bisonparserV3.tab.c"
    break;

  case 6: /* funarg: LOCALVAR  */
#line 233 "bisonparserV3.y"
                 {
    ((*yyvalp).funArgValue) = new funArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue));
}
#line 4103 "bisonparserV3.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 236 "bisonparserV3.y"
                  {
    *++(params->localVariablesStackV) = new std::vector<t_localVar>;
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
}
#line 4112 "bisonparserV3.tab.c"
    break;

  case 8: /* funarg: LOCALVAR ASSIGN $@1 list  */
#line 239 "bisonparserV3.y"
       {
    ((*yyvalp).funArgValue) = new funArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.symValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), *(params->localVariablesStackV));
    delete *(params->localVariablesAuxMapStack);
    *(params->localVariablesAuxMapStack--) = nullptr;
    delete *(params->localVariablesStackV);
    *(params->localVariablesStackV--) = nullptr;
}
#line 4124 "bisonparserV3.tab.c"
    break;

  case 9: /* funarg: ELLIPSIS  */
#line 246 "bisonparserV3.y"
           {
    ((*yyvalp).funArgValue) = new funArg(gensym("<...>"));
}
#line 4132 "bisonparserV3.tab.c"
    break;

  case 10: /* $@2: %empty  */
#line 255 "bisonparserV3.y"
            {
    *++(params->localVariablesStackV) = new std::vector<t_localVar>;
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
}
#line 4141 "bisonparserV3.tab.c"
    break;

  case 11: /* funargList: $@2 funarg  */
#line 258 "bisonparserV3.y"
         {
    auto v = new std::vector<funArg*>;
    v->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.funArgValue));
    ((*yyvalp).funArgVector) = v;
}
#line 4151 "bisonparserV3.tab.c"
    break;

  case 12: /* funargList: funargList COMMA funarg  */
#line 263 "bisonparserV3.y"
                          {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.funArgVector)->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.funArgValue));
    ((*yyvalp).funArgVector) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.funArgVector);
}
#line 4160 "bisonparserV3.tab.c"
    break;

  case 13: /* liftedargList: LIFT LOCALVAR  */
#line 271 "bisonparserV3.y"
                              {
    auto v = new std::vector<t_localVar*>;
    auto l = new t_localVar((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue));
    v->push_back(l);
    ((*yyvalp).localVarVector) = v;
    code_dev_post ("parse: liftedargList (first term)\n");
}
#line 4172 "bisonparserV3.tab.c"
    break;

  case 14: /* liftedargList: liftedargList COMMA LOCALVAR  */
#line 278 "bisonparserV3.y"
                               {
    auto l = new t_localVar((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue));
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.localVarVector)->push_back(l);
    ((*yyvalp).localVarVector) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.localVarVector);
    code_dev_post ("parse: liftedargList (subsequent term)\n");
}
#line 4183 "bisonparserV3.tab.c"
    break;

  case 15: /* $@3: %empty  */
#line 288 "bisonparserV3.y"
                           {
    params->fnDepth++;
    *++(params->liftedVariablesStack) = new std::unordered_set<t_symbol *>;
    *++(params->argumentsStackV) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.funArgVector);
}
#line 4193 "bisonparserV3.tab.c"
    break;

  case 16: /* fundef: funargList FUNDEF $@3 list  */
#line 292 "bisonparserV3.y"
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
#line 4211 "bisonparserV3.tab.c"
    break;

  case 17: /* $@4: %empty  */
#line 305 "bisonparserV3.y"
                         {
    ++(params->localVariablesStackV);
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
    *++(params->liftedVariablesStack) = new std::unordered_set<t_symbol *>;
    params->fnDepth++;
    *++(params->argumentsStackV) = nullptr;
}
#line 4223 "bisonparserV3.tab.c"
    break;

  case 18: /* fundef: EMPTYFUNARGLIST FUNDEF $@4 list  */
#line 311 "bisonparserV3.y"
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
#line 4241 "bisonparserV3.tab.c"
    break;

  case 19: /* $@5: %empty  */
#line 324 "bisonparserV3.y"
                                  {
    params->fnDepth++;
    *++(params->liftedVariablesStack) = new std::unordered_set<t_symbol *>;
    for (auto v : *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.localVarVector)) {
        (*(params->liftedVariablesStack))->insert(v->getName());
    }
    *++(params->argumentsStackV) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.funArgVector);
}
#line 4254 "bisonparserV3.tab.c"
    break;

  case 20: /* fundef: funargList liftedargList FUNDEF $@5 list  */
#line 331 "bisonparserV3.y"
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
#line 4272 "bisonparserV3.tab.c"
    break;

  case 21: /* $@6: %empty  */
#line 344 "bisonparserV3.y"
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
#line 4287 "bisonparserV3.tab.c"
    break;

  case 22: /* fundef: EMPTYFUNARGLIST liftedargList FUNDEF $@6 list  */
#line 353 "bisonparserV3.y"
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
#line 4305 "bisonparserV3.tab.c"
    break;

  case 23: /* listVector: expr  */
#line 370 "bisonparserV3.y"
                              {
    auto v = new std::vector<astNode*>;
    v->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    ((*yyvalp).astNodeVector) = v;
}
#line 4315 "bisonparserV3.tab.c"
    break;

  case 24: /* listVector: listVector expr  */
#line 375 "bisonparserV3.y"
                               {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeVector)->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    ((*yyvalp).astNodeVector) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeVector);
}
#line 4324 "bisonparserV3.tab.c"
    break;

  case 25: /* list: listVector  */
#line 383 "bisonparserV3.y"
                 {
    if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeVector)->size() == 1) {
        ((*yyvalp).astNodeValue) = (*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeVector))[0];
        delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeVector);
    } else {
        ((*yyvalp).astNodeValue) = new astConcat((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeVector), params->owner);
    }
}
#line 4337 "bisonparserV3.tab.c"
    break;

  case 26: /* list: listEnd  */
#line 391 "bisonparserV3.y"
          {
    
}
#line 4345 "bisonparserV3.tab.c"
    break;

  case 27: /* list: listVector listEnd  */
#line 394 "bisonparserV3.y"
                     {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeVector)->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    ((*yyvalp).astNodeValue) = new astConcat((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeVector), params->owner);
}
#line 4354 "bisonparserV3.tab.c"
    break;

  case 29: /* sequence: nullifiedSequence  */
#line 403 "bisonparserV3.y"
                    {
    ((*yyvalp).astNodeValue) = new astConcat((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeVector), params->owner);
}
#line 4362 "bisonparserV3.tab.c"
    break;

  case 30: /* sequence: nullifiedSequence list  */
#line 406 "bisonparserV3.y"
                         {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeVector)->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    ((*yyvalp).astNodeValue) = new astConcat((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeVector), params->owner);
}
#line 4371 "bisonparserV3.tab.c"
    break;

  case 31: /* nullified: list NULLIFY  */
#line 414 "bisonparserV3.y"
                        {
    ((*yyvalp).astNodeValue) = new astNullify((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeValue), params->owner);
}
#line 4379 "bisonparserV3.tab.c"
    break;

  case 33: /* nullifiedSequence: nullified  */
#line 422 "bisonparserV3.y"
                             {
    auto v = new std::vector<astNode*>;
    v->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    ((*yyvalp).astNodeVector) = v;
}
#line 4389 "bisonparserV3.tab.c"
    break;

  case 34: /* nullifiedSequence: nullifiedSequence nullified  */
#line 427 "bisonparserV3.y"
                              {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeVector)->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    ((*yyvalp).astNodeVector) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeVector);
}
#line 4398 "bisonparserV3.tab.c"
    break;

  case 35: /* whileloop: WHILE_KW sequence DO_KW list  */
#line 435 "bisonparserV3.y"
                                         {
    ((*yyvalp).astNodeValue) = new astWhileLoop<E_LOOP_DO>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: while...do\n");
}
#line 4407 "bisonparserV3.tab.c"
    break;

  case 36: /* whileloop: WHILE_KW sequence COLLECT_KW list  */
#line 439 "bisonparserV3.y"
                                    {
    ((*yyvalp).astNodeValue) = new astWhileLoop<E_LOOP_COLLECT>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: while...collect\n");
}
#line 4416 "bisonparserV3.tab.c"
    break;

  case 37: /* forarg: LOCALVAR IN_KW sequence  */
#line 447 "bisonparserV3.y"
                                 {
    ((*yyvalp).forArgValue) = new forArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.symValue), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    addVariableToScope<e_flexBisonV3>(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.symValue));
    code_dev_post ("parse: for iterator with index");
}
#line 4426 "bisonparserV3.tab.c"
    break;

  case 38: /* forarg: LOCALVAR LOCALVAR IN_KW sequence  */
#line 452 "bisonparserV3.y"
                                   {
    addVariableToScope<e_flexBisonV3>(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.symValue));
    addVariableToScope<e_flexBisonV3>(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.symValue));
    ((*yyvalp).forArgValue) = new forArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.symValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.symValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    code_dev_post ("parse: for iterator with index and address");
}
#line 4437 "bisonparserV3.tab.c"
    break;

  case 39: /* forargList: forarg  */
#line 462 "bisonparserV3.y"
                    {
    auto v = new std::vector<forArg*>;
    v->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.forArgValue));
    ((*yyvalp).forArgVector) = v;
    code_dev_post ("parse: for iterator (first term)\n");
}
#line 4448 "bisonparserV3.tab.c"
    break;

  case 40: /* forargList: forargList COMMA forarg  */
#line 468 "bisonparserV3.y"
                          {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.forArgVector)->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.forArgValue));
    ((*yyvalp).forArgVector) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.forArgVector);
    code_dev_post ("parse: for iterator (subsequent term)\n");
}
#line 4458 "bisonparserV3.tab.c"
    break;

  case 41: /* forloop: FOR_KW forargList DO_KW list  */
#line 478 "bisonparserV3.y"
{
    ((*yyvalp).astNodeValue) = new astForLoop<E_LOOP_DO>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.forArgVector), nullptr, nullptr, nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: FOR_KW forargList DO_KW list\n");
}
#line 4467 "bisonparserV3.tab.c"
    break;

  case 42: /* forloop: FOR_KW forargList WITH_KW argsByNameList DO_KW list  */
#line 483 "bisonparserV3.y"
{
    ((*yyvalp).astNodeValue) = new astForLoop<E_LOOP_DO>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.forArgVector), nullptr, nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.symNodePairVector), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: forargList WITH_KW argsByNameList DO_KW list\n");
}
#line 4476 "bisonparserV3.tab.c"
    break;

  case 43: /* forloop: FOR_KW forargList AS_KW sequence DO_KW list  */
#line 488 "bisonparserV3.y"
{
    ((*yyvalp).astNodeValue) = new astForLoop<E_LOOP_DO>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.forArgVector), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: FOR_KW forargList AS_KW sequence DO_KW list\n");
}
#line 4485 "bisonparserV3.tab.c"
    break;

  case 44: /* forloop: FOR_KW forargList AS_KW sequence WITH_KW argsByNameList DO_KW list  */
#line 493 "bisonparserV3.y"
{
    ((*yyvalp).astNodeValue) = new astForLoop<E_LOOP_DO>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.forArgVector), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.symNodePairVector), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: forargList AS_KW sequence WITH_KW argsByNameList DO_KW list\n");
}
#line 4494 "bisonparserV3.tab.c"
    break;

  case 45: /* forloop: FOR_KW forargList WITH_KW argsByNameList AS_KW sequence DO_KW list  */
#line 498 "bisonparserV3.y"
{
    ((*yyvalp).astNodeValue) = new astForLoop<E_LOOP_DO>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.forArgVector), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.symNodePairVector), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: FOR_KW forargList WITH_KW argsByNameList AS_KW sequence DO_KW list\n");
}
#line 4503 "bisonparserV3.tab.c"
    break;

  case 46: /* forloop: FOR_KW forargList COLLECT_KW list  */
#line 503 "bisonparserV3.y"
{
    ((*yyvalp).astNodeValue) = new astForLoop<E_LOOP_COLLECT>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.forArgVector), nullptr, nullptr, nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: FOR_KW forargList COLLECT_KW list\n");
}
#line 4512 "bisonparserV3.tab.c"
    break;

  case 47: /* forloop: FOR_KW forargList WITH_KW argsByNameList COLLECT_KW list  */
#line 508 "bisonparserV3.y"
{
    ((*yyvalp).astNodeValue) = new astForLoop<E_LOOP_COLLECT>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.forArgVector), nullptr, nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.symNodePairVector), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: forargList WITH_KW argsByNameList COLLECT_KW list\n");
}
#line 4521 "bisonparserV3.tab.c"
    break;

  case 48: /* forloop: FOR_KW forargList AS_KW sequence COLLECT_KW list  */
#line 513 "bisonparserV3.y"
{
    ((*yyvalp).astNodeValue) = new astForLoop<E_LOOP_COLLECT>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.forArgVector), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: FOR_KW forargList AS_KW sequence COLLECT_KW list\n");
}
#line 4530 "bisonparserV3.tab.c"
    break;

  case 49: /* forloop: FOR_KW forargList AS_KW sequence WITH_KW argsByNameList COLLECT_KW list  */
#line 518 "bisonparserV3.y"
{
    ((*yyvalp).astNodeValue) = new astForLoop<E_LOOP_COLLECT>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.forArgVector), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.symNodePairVector), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: forargList AS_KW sequence WITH_KW argsByNameList COLLECT_KW list\n");
}
#line 4539 "bisonparserV3.tab.c"
    break;

  case 50: /* forloop: FOR_KW forargList WITH_KW argsByNameList AS_KW sequence COLLECT_KW list  */
#line 523 "bisonparserV3.y"
{
    ((*yyvalp).astNodeValue) = new astForLoop<E_LOOP_COLLECT>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.forArgVector), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.symNodePairVector), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: FOR_KW forargList WITH_KW argsByNameList AS_KW sequence COLLECT_KW list\n");
}
#line 4548 "bisonparserV3.tab.c"
    break;

  case 51: /* argsByPositionList: sequence  */
#line 531 "bisonparserV3.y"
                              {
    auto v = new std::vector<astNode*>;
    v->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    ((*yyvalp).astNodeVector) = v;
    code_dev_post ("parse: argsByPositionList (first term)\n");
}
#line 4559 "bisonparserV3.tab.c"
    break;

  case 52: /* argsByPositionList: argsByPositionList COMMA sequence  */
#line 537 "bisonparserV3.y"
                                    {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeVector)->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    ((*yyvalp).astNodeVector) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeVector);
    code_dev_post ("parse: argsByPositionList (subsequent term)\n");
}
#line 4569 "bisonparserV3.tab.c"
    break;

  case 53: /* argsByNameList: argByName  */
#line 546 "bisonparserV3.y"
                          {
    auto v = new std::vector<symNodePair*>;
    v->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symNodePairValue));
    ((*yyvalp).symNodePairVector) = v;code_dev_post ("parse: argsByNameList (first term)\n");
}
#line 4579 "bisonparserV3.tab.c"
    break;

  case 54: /* argsByNameList: argsByNameList COMMA argByName  */
#line 551 "bisonparserV3.y"
                                 {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.symNodePairVector)->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symNodePairValue));
    ((*yyvalp).symNodePairVector) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.symNodePairVector);
    code_dev_post ("parse: argsByNameList (subsequent term)\n");
}
#line 4589 "bisonparserV3.tab.c"
    break;

  case 55: /* argsByNameList: argsByNameList argByName  */
#line 556 "bisonparserV3.y"
                           {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.symNodePairVector)->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symNodePairValue));
    ((*yyvalp).symNodePairVector) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.symNodePairVector);
    code_dev_post ("parse: argsByNameList (subsequent term)\n");
}
#line 4599 "bisonparserV3.tab.c"
    break;

  case 56: /* argByName: NAMEDPARAM sequence  */
#line 565 "bisonparserV3.y"
                                {
    ((*yyvalp).symNodePairValue) = new symNodePair((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.symValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    code_dev_post ("parse: named parameter %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.symValue)->s_name);
}
#line 4608 "bisonparserV3.tab.c"
    break;

  case 59: /* simpleFuncall: itemOrVar STARTPARAMS CLOSEDROUND  */
#line 579 "bisonparserV3.y"
                                                  {
    ((*yyvalp).astFunctionCallValue) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (std::vector<astNode*>*) nullptr, (std::vector<symNodePair*>*) nullptr, params->owner);
}
#line 4616 "bisonparserV3.tab.c"
    break;

  case 60: /* simpleFuncall: itemOrVar STARTPARAMS argsByPositionList CLOSEDROUND  */
#line 582 "bisonparserV3.y"
                                                       {
    ((*yyvalp).astFunctionCallValue) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeVector), nullptr, params->owner);
}
#line 4624 "bisonparserV3.tab.c"
    break;

  case 61: /* simpleFuncall: itemOrVar STARTPARAMS argsByNameList CLOSEDROUND  */
#line 585 "bisonparserV3.y"
                                                   {
    ((*yyvalp).astFunctionCallValue) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.astNodeValue), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.symNodePairVector), params->owner);
}
#line 4632 "bisonparserV3.tab.c"
    break;

  case 62: /* simpleFuncall: itemOrVar STARTPARAMS argsByPositionList COMMA argsByNameList CLOSEDROUND  */
#line 588 "bisonparserV3.y"
                                                                            {
    ((*yyvalp).astFunctionCallValue) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.astNodeVector), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.symNodePairVector), params->owner);
}
#line 4640 "bisonparserV3.tab.c"
    break;

  case 63: /* simpleFuncall: itemOrVar STARTPARAMS argsByPositionList argsByNameList CLOSEDROUND  */
#line 591 "bisonparserV3.y"
                                                                      {
    ((*yyvalp).astFunctionCallValue) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeVector), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.symNodePairVector), params->owner);
}
#line 4648 "bisonparserV3.tab.c"
    break;

  case 64: /* simpleFuncall: simpleFuncall STARTPARAMS CLOSEDROUND  */
#line 594 "bisonparserV3.y"
                                        {
    ((*yyvalp).astFunctionCallValue) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astFunctionCallValue), (std::vector<astNode*>*) nullptr, (std::vector<symNodePair*>*) nullptr, params->owner);
}
#line 4656 "bisonparserV3.tab.c"
    break;

  case 65: /* simpleFuncall: simpleFuncall STARTPARAMS argsByPositionList CLOSEDROUND  */
#line 597 "bisonparserV3.y"
                                                           {
    ((*yyvalp).astFunctionCallValue) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.astFunctionCallValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeVector), nullptr, params->owner);
}
#line 4664 "bisonparserV3.tab.c"
    break;

  case 66: /* simpleFuncall: simpleFuncall STARTPARAMS argsByNameList CLOSEDROUND  */
#line 600 "bisonparserV3.y"
                                                       {
    ((*yyvalp).astFunctionCallValue) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.astFunctionCallValue), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.symNodePairVector), params->owner);
}
#line 4672 "bisonparserV3.tab.c"
    break;

  case 67: /* simpleFuncall: simpleFuncall STARTPARAMS argsByPositionList COMMA argsByNameList CLOSEDROUND  */
#line 603 "bisonparserV3.y"
                                                                                {
    ((*yyvalp).astFunctionCallValue) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.astFunctionCallValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.astNodeVector), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.symNodePairVector), params->owner);
}
#line 4680 "bisonparserV3.tab.c"
    break;

  case 68: /* simpleFuncall: simpleFuncall STARTPARAMS argsByPositionList argsByNameList CLOSEDROUND  */
#line 606 "bisonparserV3.y"
                                                                           {
    ((*yyvalp).astFunctionCallValue) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.astFunctionCallValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeVector), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.symNodePairVector), params->owner);
}
#line 4688 "bisonparserV3.tab.c"
    break;

  case 69: /* sign: UPLUS  */
#line 613 "bisonparserV3.y"
             {
    ((*yyvalp).longValue) = 1;
}
#line 4696 "bisonparserV3.tab.c"
    break;

  case 70: /* sign: UMINUS  */
#line 616 "bisonparserV3.y"
         {
    ((*yyvalp).longValue) = -1;
}
#line 4704 "bisonparserV3.tab.c"
    break;

  case 71: /* sign: sign UPLUS  */
#line 619 "bisonparserV3.y"
             {
    ((*yyvalp).longValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.longValue);
}
#line 4712 "bisonparserV3.tab.c"
    break;

  case 72: /* sign: sign UMINUS  */
#line 622 "bisonparserV3.y"
              {
    ((*yyvalp).longValue) = -(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.longValue);
}
#line 4720 "bisonparserV3.tab.c"
    break;

  case 74: /* lvalueSpecsItemForDot: sign itemOrVar  */
#line 630 "bisonparserV3.y"
                 {
    if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.longValue) == -1) {
        ((*yyvalp).astNodeValue) = new astOperatorUMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    } else {
        ((*yyvalp).astNodeValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue);
    }
}
#line 4732 "bisonparserV3.tab.c"
    break;

  case 77: /* lvalueSpecsItemForNth: sign simpleFuncall  */
#line 642 "bisonparserV3.y"
                     {
    if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.longValue) == -1) {
        ((*yyvalp).astNodeValue) = new astOperatorUMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astFunctionCallValue), params->owner);
    } else {
        ((*yyvalp).astNodeValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astFunctionCallValue);
    }
}
#line 4744 "bisonparserV3.tab.c"
    break;

  case 80: /* dataflowHead: lvalue  */
#line 654 "bisonparserV3.y"
         {
    astNode* n = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.lvalueValue)->getVar();
    auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.lvalueValue)->getSpecs();
    if (s)
        n = s->toReadNode(n, params->owner);
    ((*yyvalp).astNodeValue) = n;
}
#line 4756 "bisonparserV3.tab.c"
    break;

  case 81: /* dataflowHead: fakeLvalue  */
#line 661 "bisonparserV3.y"
             {
    auto n = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode();
    auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs();
    ((*yyvalp).astNodeValue) = s->toReadNode(n, params->owner);
}
#line 4766 "bisonparserV3.tab.c"
    break;

  case 82: /* dataflowFuncall: dataflowHead APPLY simpleFuncall  */
#line 671 "bisonparserV3.y"
                                 {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astFunctionCallValue)->addDataflowStyleArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue));
    ((*yyvalp).astFunctionCallValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astFunctionCallValue);
}
#line 4775 "bisonparserV3.tab.c"
    break;

  case 83: /* dataflowFuncall: dataflowFuncall APPLY simpleFuncall  */
#line 675 "bisonparserV3.y"
                                      {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astFunctionCallValue)->addDataflowStyleArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astFunctionCallValue));
    ((*yyvalp).astFunctionCallValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astFunctionCallValue);
}
#line 4784 "bisonparserV3.tab.c"
    break;

  case 89: /* localVar: LOCALVAR  */
#line 697 "bisonparserV3.y"
                   {
    ((*yyvalp).astLocalVarValue) = new astLocalVar((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue), params->owner);
    addVariableToScope<e_flexBisonV3>(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue));
    code_dev_post ("parse: Local variable %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue)->s_name);
}
#line 4794 "bisonparserV3.tab.c"
    break;

  case 90: /* localVar: KEEP LOCALVAR  */
#line 702 "bisonparserV3.y"
                {
    ((*yyvalp).astLocalVarValue) = new astKeep((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue), params->owner);
    addVariableToScope<e_flexBisonV3>(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue));
    code_dev_post ("parse: Keep local variable %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue)->s_name);
}
#line 4804 "bisonparserV3.tab.c"
    break;

  case 91: /* localVar: UNKEEP LOCALVAR  */
#line 707 "bisonparserV3.y"
                  {
    ((*yyvalp).astLocalVarValue) = new astUnkeep((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue), params->owner);
    addVariableToScope<e_flexBisonV3>(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue));
    code_dev_post ("parse: Unkeep local variable %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue)->s_name);
}
#line 4814 "bisonparserV3.tab.c"
    break;

  case 92: /* globalVar: GLOBALVAR  */
#line 716 "bisonparserV3.y"
                     {
    astGlobalVar *v = new astGlobalVar(params->gvt, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue), params->owner);
    params->globalVariables->insert(v->getVar());
    ((*yyvalp).astGlobalVarValue) = v;
    code_dev_post ("parse: Global variable %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue)->s_name);
}
#line 4825 "bisonparserV3.tab.c"
    break;

  case 93: /* patcherVar: PATCHERVAR  */
#line 726 "bisonparserV3.y"
                       {
    astPatcherVar *v = new astPatcherVar((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue), params->owner);
    (*params->name2patcherVars)[(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue)].insert(v);
    ((*yyvalp).astPatcherVarValue) = v;
    code_dev_post ("parse: Patcher variable %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue)->s_name);
}
#line 4836 "bisonparserV3.tab.c"
    break;

  case 99: /* lvalueSpecsFinal: sign lvalueSpecsUFinal  */
#line 747 "bisonparserV3.y"
                         {
    if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.longValue) == -1) {
        ((*yyvalp).astNodeValue) = new astOperatorUMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    } else {
        ((*yyvalp).astNodeValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue);
    }
}
#line 4848 "bisonparserV3.tab.c"
    break;

  case 100: /* lvalue: var  */
#line 759 "bisonparserV3.y"
    {
    ((*yyvalp).lvalueValue) = new lvalue((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astVarValue), nullptr);
}
#line 4856 "bisonparserV3.tab.c"
    break;

  case 101: /* lvalue: var lvalueSpecs  */
#line 762 "bisonparserV3.y"
                  {
    ((*yyvalp).lvalueValue) = new lvalue((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astVarValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.lvalueSpecsValue));
}
#line 4864 "bisonparserV3.tab.c"
    break;

  case 104: /* fakeLvalue: fakeLvalueHead lvalueSpecs  */
#line 777 "bisonparserV3.y"
                           {
    ((*yyvalp).fakeLvalueValue) = new fakeLvalue((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.lvalueSpecsValue));
}
#line 4872 "bisonparserV3.tab.c"
    break;

  case 105: /* lvalueSpecsNonFinalized: NTHOP lvalueSpecsItemForNth  */
#line 785 "bisonparserV3.y"
                            {
    auto s = new lvalueSpecs;
    auto step = new lvalueStep(lvalueStep::E_LV_NTH, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    s->addStep(step);
    ((*yyvalp).lvalueSpecsValue) = s;
}
#line 4883 "bisonparserV3.tab.c"
    break;

  case 106: /* lvalueSpecsNonFinalized: lvalueSpecs NTHOP lvalueSpecsItemForNth  */
#line 791 "bisonparserV3.y"
                                          {
    auto step = new lvalueStep(lvalueStep::E_LV_NTH, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueSpecsValue)->addStep(step);
    ((*yyvalp).lvalueSpecsValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueSpecsValue);
}
#line 4893 "bisonparserV3.tab.c"
    break;

  case 107: /* lvalueSpecsNonFinalized: APPLY lvalueSpecsItemForDot  */
#line 796 "bisonparserV3.y"
                              {
    auto s = new lvalueSpecs;
    auto step = new lvalueStep(lvalueStep::E_LV_KEY, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    s->addStep(step);
    ((*yyvalp).lvalueSpecsValue) = s;
}
#line 4904 "bisonparserV3.tab.c"
    break;

  case 108: /* lvalueSpecsNonFinalized: lvalueSpecs APPLY lvalueSpecsItemForDot  */
#line 802 "bisonparserV3.y"
                                          {
    auto step = new lvalueStep(lvalueStep::E_LV_KEY, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueSpecsValue)->addStep(step);
    ((*yyvalp).lvalueSpecsValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueSpecsValue);
}
#line 4914 "bisonparserV3.tab.c"
    break;

  case 109: /* lvalueSpecs: NTHOP lvalueSpecsFinal  */
#line 812 "bisonparserV3.y"
                       {
    auto s = new lvalueSpecs;
    auto step = new lvalueStep(lvalueStep::E_LV_NTH, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    s->addStep(step);
    ((*yyvalp).lvalueSpecsValue) = s;
}
#line 4925 "bisonparserV3.tab.c"
    break;

  case 110: /* lvalueSpecs: lvalueSpecsNonFinalized NTHOP lvalueSpecsFinal  */
#line 818 "bisonparserV3.y"
                                                 {
    auto step = new lvalueStep(lvalueStep::E_LV_NTH, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueSpecsValue)->addStep(step);
    ((*yyvalp).lvalueSpecsValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueSpecsValue);
}
#line 4935 "bisonparserV3.tab.c"
    break;

  case 111: /* lvalueSpecs: APPLY lvalueSpecsFinal  */
#line 823 "bisonparserV3.y"
                         {
    auto s = new lvalueSpecs;
    auto step = new lvalueStep(lvalueStep::E_LV_KEY, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    s->addStep(step);
    ((*yyvalp).lvalueSpecsValue) = s;
}
#line 4946 "bisonparserV3.tab.c"
    break;

  case 112: /* lvalueSpecs: lvalueSpecsNonFinalized APPLY lvalueSpecsFinal  */
#line 829 "bisonparserV3.y"
                                                 {
    auto step = new lvalueStep(lvalueStep::E_LV_KEY, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueSpecsValue)->addStep(step);
    ((*yyvalp).lvalueSpecsValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueSpecsValue);
}
#line 4956 "bisonparserV3.tab.c"
    break;

  case 121: /* expr: lvalue  */
#line 850 "bisonparserV3.y"
         {
    astNode* n = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.lvalueValue)->getVar();
    auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.lvalueValue)->getSpecs();
    if (s)
        n = s->toReadNode(n, params->owner);
    ((*yyvalp).astNodeValue) = n;
}
#line 4968 "bisonparserV3.tab.c"
    break;

  case 122: /* expr: fakeLvalue  */
#line 857 "bisonparserV3.y"
             {
    auto n = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode();
    auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs();
    ((*yyvalp).astNodeValue) = s->toReadNode(n, params->owner);
}
#line 4978 "bisonparserV3.tab.c"
    break;

  case 123: /* expr: UMINUS expr  */
#line 869 "bisonparserV3.y"
              {
    ((*yyvalp).astNodeValue) = new astOperatorUMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
}
#line 4986 "bisonparserV3.tab.c"
    break;

  case 124: /* expr: UPLUS expr  */
#line 872 "bisonparserV3.y"
             {
    ((*yyvalp).astNodeValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue);
}
#line 4994 "bisonparserV3.tab.c"
    break;

  case 125: /* expr: expr R  */
#line 875 "bisonparserV3.y"
         {
    ((*yyvalp).astNodeValue) = new astOperatorR((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeValue), params->owner);
}
#line 5002 "bisonparserV3.tab.c"
    break;

  case 126: /* expr: expr T  */
#line 878 "bisonparserV3.y"
         {
    ((*yyvalp).astNodeValue) = new astOperatorT((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeValue), params->owner);
}
#line 5010 "bisonparserV3.tab.c"
    break;

  case 127: /* expr: LOGNOT expr  */
#line 881 "bisonparserV3.y"
              {
    ((*yyvalp).astNodeValue) = new astLogNot((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post("parse: !\n");
}
#line 5019 "bisonparserV3.tab.c"
    break;

  case 128: /* expr: BITNOT expr  */
#line 885 "bisonparserV3.y"
              {
    ((*yyvalp).astNodeValue) = new astOperatorBitNot((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post("parse: ~\n");
}
#line 5028 "bisonparserV3.tab.c"
    break;

  case 129: /* expr: expr PLUS expr  */
#line 889 "bisonparserV3.y"
                 {
    ((*yyvalp).astNodeValue) = new astOperatorPlus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: +\n");
}
#line 5037 "bisonparserV3.tab.c"
    break;

  case 130: /* expr: expr MINUS expr  */
#line 893 "bisonparserV3.y"
                  {
    ((*yyvalp).astNodeValue) = new astOperatorMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: -\n");
}
#line 5046 "bisonparserV3.tab.c"
    break;

  case 131: /* expr: expr TIMES expr  */
#line 897 "bisonparserV3.y"
                  {
    ((*yyvalp).astNodeValue) = new astOperatorTimes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: *\n");
}
#line 5055 "bisonparserV3.tab.c"
    break;

  case 132: /* expr: expr DIV expr  */
#line 901 "bisonparserV3.y"
                {
    ((*yyvalp).astNodeValue) = new astOperatorDiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: /\n");
}
#line 5064 "bisonparserV3.tab.c"
    break;

  case 133: /* expr: expr DIVDIV expr  */
#line 905 "bisonparserV3.y"
                   {
    ((*yyvalp).astNodeValue) = new astOperatorDivdiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: //\n");
}
#line 5073 "bisonparserV3.tab.c"
    break;

  case 134: /* expr: expr REM expr  */
#line 909 "bisonparserV3.y"
                {
    ((*yyvalp).astNodeValue) = new astOperatorRemainder((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: %\n");
}
#line 5082 "bisonparserV3.tab.c"
    break;

  case 135: /* expr: expr POWOP expr  */
#line 913 "bisonparserV3.y"
                  {
    ((*yyvalp).astNodeValue) = new astOperatorPow((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: **\n");
}
#line 5091 "bisonparserV3.tab.c"
    break;

  case 136: /* expr: expr BITAND expr  */
#line 917 "bisonparserV3.y"
                   {
    ((*yyvalp).astNodeValue) = new astOperatorBitAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: &\n");
}
#line 5100 "bisonparserV3.tab.c"
    break;

  case 137: /* expr: expr BITXOR expr  */
#line 921 "bisonparserV3.y"
                   {
    ((*yyvalp).astNodeValue) = new astOperatorBitXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: ^\n");
}
#line 5109 "bisonparserV3.tab.c"
    break;

  case 138: /* expr: expr BITOR expr  */
#line 925 "bisonparserV3.y"
                  {
    ((*yyvalp).astNodeValue) = new astOperatorBitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: |\n");
}
#line 5118 "bisonparserV3.tab.c"
    break;

  case 139: /* expr: expr LSHIFT expr  */
#line 929 "bisonparserV3.y"
                   {
    ((*yyvalp).astNodeValue) = new astOperatorBitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: <<\n");
}
#line 5127 "bisonparserV3.tab.c"
    break;

  case 140: /* expr: expr RSHIFT expr  */
#line 933 "bisonparserV3.y"
                   {
    ((*yyvalp).astNodeValue) = new astOperatorBitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: >>\n");
}
#line 5136 "bisonparserV3.tab.c"
    break;

  case 141: /* expr: expr EQUAL expr  */
#line 937 "bisonparserV3.y"
                  {
    ((*yyvalp).astNodeValue) = new astComparatorEq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: ==\n");
}
#line 5145 "bisonparserV3.tab.c"
    break;

  case 142: /* expr: expr NEQ expr  */
#line 941 "bisonparserV3.y"
                {
    ((*yyvalp).astNodeValue) = new astComparatorNeq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: !=\n");
}
#line 5154 "bisonparserV3.tab.c"
    break;

  case 143: /* expr: expr LT expr  */
#line 945 "bisonparserV3.y"
               {
    ((*yyvalp).astNodeValue) = new astComparatorLt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: <\n");
}
#line 5163 "bisonparserV3.tab.c"
    break;

  case 144: /* expr: expr GT expr  */
#line 949 "bisonparserV3.y"
               {
    ((*yyvalp).astNodeValue) = new astComparatorGt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: <\n");
}
#line 5172 "bisonparserV3.tab.c"
    break;

  case 145: /* expr: expr LEQ expr  */
#line 953 "bisonparserV3.y"
                {
    ((*yyvalp).astNodeValue) = new astComparatorLeq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: <=\n");
}
#line 5181 "bisonparserV3.tab.c"
    break;

  case 146: /* expr: expr GEQ expr  */
#line 957 "bisonparserV3.y"
                {
    ((*yyvalp).astNodeValue) = new astComparatorGeq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: >=\n");
}
#line 5190 "bisonparserV3.tab.c"
    break;

  case 147: /* expr: expr LOGOR expr  */
#line 961 "bisonparserV3.y"
                  {
    ((*yyvalp).astNodeValue) = new astSCOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: ||\n");
}
#line 5199 "bisonparserV3.tab.c"
    break;

  case 148: /* expr: expr LOGAND expr  */
#line 965 "bisonparserV3.y"
                   {
    ((*yyvalp).astNodeValue) = new astSCAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: &&\n");
}
#line 5208 "bisonparserV3.tab.c"
    break;

  case 149: /* expr: expr LOGXOR expr  */
#line 969 "bisonparserV3.y"
                   {
    ((*yyvalp).astNodeValue) = new astLogXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: &&\n");
}
#line 5217 "bisonparserV3.tab.c"
    break;

  case 150: /* expr: expr LOGOREXT expr  */
#line 973 "bisonparserV3.y"
                     {
    ((*yyvalp).astNodeValue) = new astSCOrExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: |||\n");
}
#line 5226 "bisonparserV3.tab.c"
    break;

  case 151: /* expr: expr LOGANDEXT expr  */
#line 977 "bisonparserV3.y"
                      {
    ((*yyvalp).astNodeValue) = new astSCAndExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: &&&\n");
}
#line 5235 "bisonparserV3.tab.c"
    break;

  case 152: /* expr: expr PICKOP expr  */
#line 981 "bisonparserV3.y"
                   {
    ((*yyvalp).astNodeValue) = new astPickOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: nthop\n");
}
#line 5244 "bisonparserV3.tab.c"
    break;

  case 153: /* expr: expr RANGE expr  */
#line 985 "bisonparserV3.y"
                  {
    ((*yyvalp).astNodeValue) = new astRangeOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: range\n");
}
#line 5253 "bisonparserV3.tab.c"
    break;

  case 154: /* expr: expr REPEAT expr  */
#line 989 "bisonparserV3.y"
                   {
    ((*yyvalp).astNodeValue) = new astRepeatOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: range\n");
}
#line 5262 "bisonparserV3.tab.c"
    break;

  case 155: /* expr: sign listEnd  */
#line 993 "bisonparserV3.y"
               {
    if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.longValue) == -1)
        ((*yyvalp).astNodeValue) = new astOperatorUMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue);
    code_dev_post("parse: U-\n");
}
#line 5274 "bisonparserV3.tab.c"
    break;

  case 156: /* expr: LOGNOT listEnd  */
#line 1000 "bisonparserV3.y"
                 {
    ((*yyvalp).astNodeValue) = new astLogNot((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post("parse: !\n");
}
#line 5283 "bisonparserV3.tab.c"
    break;

  case 157: /* expr: BITNOT listEnd  */
#line 1004 "bisonparserV3.y"
                 {
    ((*yyvalp).astNodeValue) = new astOperatorBitNot((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post("parse: ~\n");
}
#line 5292 "bisonparserV3.tab.c"
    break;

  case 158: /* expr: expr PLUS listEnd  */
#line 1008 "bisonparserV3.y"
                    {
    ((*yyvalp).astNodeValue) = new astOperatorPlus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: +\n");
}
#line 5301 "bisonparserV3.tab.c"
    break;

  case 159: /* expr: expr MINUS listEnd  */
#line 1012 "bisonparserV3.y"
                     {
    ((*yyvalp).astNodeValue) = new astOperatorMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: -\n");
}
#line 5310 "bisonparserV3.tab.c"
    break;

  case 160: /* expr: expr TIMES listEnd  */
#line 1016 "bisonparserV3.y"
                     {
    ((*yyvalp).astNodeValue) = new astOperatorTimes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: *\n");
}
#line 5319 "bisonparserV3.tab.c"
    break;

  case 161: /* expr: expr DIV listEnd  */
#line 1020 "bisonparserV3.y"
                   {
    ((*yyvalp).astNodeValue) = new astOperatorDiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: /\n");
}
#line 5328 "bisonparserV3.tab.c"
    break;

  case 162: /* expr: expr DIVDIV listEnd  */
#line 1024 "bisonparserV3.y"
                      {
    ((*yyvalp).astNodeValue) = new astOperatorDivdiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: //\n");
}
#line 5337 "bisonparserV3.tab.c"
    break;

  case 163: /* expr: expr REM listEnd  */
#line 1028 "bisonparserV3.y"
                   {
    ((*yyvalp).astNodeValue) = new astOperatorRemainder((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: %\n");
}
#line 5346 "bisonparserV3.tab.c"
    break;

  case 164: /* expr: expr POWOP listEnd  */
#line 1032 "bisonparserV3.y"
                     {
    ((*yyvalp).astNodeValue) = new astOperatorPow((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: **\n");
}
#line 5355 "bisonparserV3.tab.c"
    break;

  case 165: /* expr: expr BITAND listEnd  */
#line 1036 "bisonparserV3.y"
                      {
    ((*yyvalp).astNodeValue) = new astOperatorBitAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: &\n");
}
#line 5364 "bisonparserV3.tab.c"
    break;

  case 166: /* expr: expr BITXOR listEnd  */
#line 1040 "bisonparserV3.y"
                      {
    ((*yyvalp).astNodeValue) = new astOperatorBitXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: ^\n");
}
#line 5373 "bisonparserV3.tab.c"
    break;

  case 167: /* expr: expr BITOR listEnd  */
#line 1044 "bisonparserV3.y"
                     {
    ((*yyvalp).astNodeValue) = new astOperatorBitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: |\n");
}
#line 5382 "bisonparserV3.tab.c"
    break;

  case 168: /* expr: expr LSHIFT listEnd  */
#line 1048 "bisonparserV3.y"
                      {
    ((*yyvalp).astNodeValue) = new astOperatorBitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: <<\n");
}
#line 5391 "bisonparserV3.tab.c"
    break;

  case 169: /* expr: expr RSHIFT listEnd  */
#line 1052 "bisonparserV3.y"
                      {
    ((*yyvalp).astNodeValue) = new astOperatorBitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: >>\n");
}
#line 5400 "bisonparserV3.tab.c"
    break;

  case 170: /* expr: expr EQUAL listEnd  */
#line 1056 "bisonparserV3.y"
                     {
    ((*yyvalp).astNodeValue) = new astComparatorEq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: ==\n");
}
#line 5409 "bisonparserV3.tab.c"
    break;

  case 171: /* expr: expr NEQ listEnd  */
#line 1060 "bisonparserV3.y"
                   {
    ((*yyvalp).astNodeValue) = new astComparatorNeq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: !=\n");
}
#line 5418 "bisonparserV3.tab.c"
    break;

  case 172: /* expr: expr LT listEnd  */
#line 1064 "bisonparserV3.y"
                  {
    ((*yyvalp).astNodeValue) = new astComparatorLt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: <\n");
}
#line 5427 "bisonparserV3.tab.c"
    break;

  case 173: /* expr: expr GT listEnd  */
#line 1068 "bisonparserV3.y"
                  {
    ((*yyvalp).astNodeValue) = new astComparatorGt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: <\n");
}
#line 5436 "bisonparserV3.tab.c"
    break;

  case 174: /* expr: expr LEQ listEnd  */
#line 1072 "bisonparserV3.y"
                   {
    ((*yyvalp).astNodeValue) = new astComparatorLeq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: <=\n");
}
#line 5445 "bisonparserV3.tab.c"
    break;

  case 175: /* expr: expr GEQ listEnd  */
#line 1076 "bisonparserV3.y"
                   {
    ((*yyvalp).astNodeValue) = new astComparatorGeq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: >=\n");
}
#line 5454 "bisonparserV3.tab.c"
    break;

  case 176: /* expr: expr LOGOR listEnd  */
#line 1080 "bisonparserV3.y"
                     {
    ((*yyvalp).astNodeValue) = new astSCOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: ||\n");
}
#line 5463 "bisonparserV3.tab.c"
    break;

  case 177: /* expr: expr LOGAND listEnd  */
#line 1084 "bisonparserV3.y"
                      {
    ((*yyvalp).astNodeValue) = new astSCAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: &&\n");
}
#line 5472 "bisonparserV3.tab.c"
    break;

  case 178: /* expr: expr LOGXOR listEnd  */
#line 1088 "bisonparserV3.y"
                      {
    ((*yyvalp).astNodeValue) = new astLogXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: &&\n");
}
#line 5481 "bisonparserV3.tab.c"
    break;

  case 179: /* expr: expr LOGOREXT listEnd  */
#line 1092 "bisonparserV3.y"
                        {
    ((*yyvalp).astNodeValue) = new astSCOrExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: |||\n");
}
#line 5490 "bisonparserV3.tab.c"
    break;

  case 180: /* expr: expr LOGANDEXT listEnd  */
#line 1096 "bisonparserV3.y"
                         {
    ((*yyvalp).astNodeValue) = new astSCAndExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: &&&\n");
}
#line 5499 "bisonparserV3.tab.c"
    break;

  case 181: /* expr: expr PICKOP listEnd  */
#line 1100 "bisonparserV3.y"
                      {
    ((*yyvalp).astNodeValue) = new astPickOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: nthop\n");
}
#line 5508 "bisonparserV3.tab.c"
    break;

  case 182: /* expr: expr RANGE listEnd  */
#line 1104 "bisonparserV3.y"
                     {
    ((*yyvalp).astNodeValue) = new astRangeOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: range\n");
}
#line 5517 "bisonparserV3.tab.c"
    break;

  case 183: /* expr: expr REPEAT listEnd  */
#line 1108 "bisonparserV3.y"
                      {
    ((*yyvalp).astNodeValue) = new astRepeatOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post ("parse: range\n");
}
#line 5526 "bisonparserV3.tab.c"
    break;

  case 184: /* commaVector: LONG_LITERAL  */
#line 1116 "bisonparserV3.y"
             {
    auto v = new std::vector<int8_t>;
    v->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue));
    ((*yyvalp).int8Vector) = v;
    code_dev_post ("parse: commaVector: LONG_LITERAL\n");
}
#line 5537 "bisonparserV3.tab.c"
    break;

  case 185: /* commaVector: sign LONG_LITERAL  */
#line 1122 "bisonparserV3.y"
                    {
    auto v = new std::vector<int8_t>;
    v->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.longValue) * (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue));
    ((*yyvalp).int8Vector) = v;
    code_dev_post ("parse: commaVector: sign LONG_LITERAL\n");
}
#line 5548 "bisonparserV3.tab.c"
    break;

  case 186: /* commaVector: commaVector NTHOP LONG_LITERAL  */
#line 1128 "bisonparserV3.y"
                                 {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.int8Vector)->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue));
    ((*yyvalp).int8Vector) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.int8Vector);
    code_dev_post ("parse: commaVector NTHOP  LONG_LITERAL\n");

}
#line 5559 "bisonparserV3.tab.c"
    break;

  case 187: /* commaVector: commaVector NTHOP sign LONG_LITERAL  */
#line 1134 "bisonparserV3.y"
                                      {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.int8Vector)->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.longValue) * (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue));
    ((*yyvalp).int8Vector) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.int8Vector);
    code_dev_post ("parse: commaVector NTHOP sign LONG_LITERAL\n");
}
#line 5569 "bisonparserV3.tab.c"
    break;

  case 188: /* jiPitchBase: JIPITCHBASE_START commaVector JIPITCHBASE_END  */
#line 1143 "bisonparserV3.y"
                                              {
    ((*yyvalp).astNodeValue) = new astConst(t_pitch((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.longValue), *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.int8Vector), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue)));
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.int8Vector);
    code_dev_post ("parse: jiPitchBase\n");
}
#line 5579 "bisonparserV3.tab.c"
    break;

  case 189: /* item: LONG_LITERAL  */
#line 1153 "bisonparserV3.y"
             {
    ((*yyvalp).astNodeValue) = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue), params->owner);
    code_dev_post("parse: INT %ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue));
}
#line 5588 "bisonparserV3.tab.c"
    break;

  case 190: /* item: RAT_LITERAL  */
#line 1157 "bisonparserV3.y"
              {
    ((*yyvalp).astNodeValue) = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.ratValue), params->owner);
    code_dev_post("parse: RAT_LITERAL %ld/%ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.ratValue).num(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.ratValue).den());
}
#line 5597 "bisonparserV3.tab.c"
    break;

  case 191: /* item: DOUBLE_LITERAL  */
#line 1161 "bisonparserV3.y"
                 {
    ((*yyvalp).astNodeValue) = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.doubleValue), params->owner);
    code_dev_post("parse: DOUBLE_LITERAL %lf", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.doubleValue));
}
#line 5606 "bisonparserV3.tab.c"
    break;

  case 192: /* item: PITCH_LITERAL  */
#line 1165 "bisonparserV3.y"
                {
    ((*yyvalp).astNodeValue) = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.pitchValue), params->owner);
    code_dev_post("parse: PITCH_LITERAL %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.pitchValue).toSym()->s_name);
}
#line 5615 "bisonparserV3.tab.c"
    break;

  case 194: /* item: SYMBOL_LITERAL  */
#line 1170 "bisonparserV3.y"
                 {
    ((*yyvalp).astNodeValue) = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue), params->owner);
    code_dev_post("parse: SYMBOL_LITERAL %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue)->s_name);
}
#line 5624 "bisonparserV3.tab.c"
    break;

  case 195: /* item: BACHNULL  */
#line 1174 "bisonparserV3.y"
           {
    ((*yyvalp).astNodeValue) = new astConst(llll_get(), params->owner);
    code_dev_post("parse: NULL");
}
#line 5633 "bisonparserV3.tab.c"
    break;

  case 196: /* item: ARGCOUNT  */
#line 1178 "bisonparserV3.y"
           {
    auto fnConst = new astConst((*(params->bifs))["$argcount"], params->owner);
    ((*yyvalp).astNodeValue) = new astFunctionCall(fnConst, params->owner);
    code_dev_post("parse: ARGCOUNT");
}
#line 5643 "bisonparserV3.tab.c"
    break;

  case 197: /* item: BACHNIL  */
#line 1183 "bisonparserV3.y"
          {
    t_llll *ll = llll_get();
    llll_appendllll(ll, llll_get());
    ((*yyvalp).astNodeValue) = new astConst(ll, params->owner);
    code_dev_post("parse: NIL");
}
#line 5654 "bisonparserV3.tab.c"
    break;

  case 198: /* item: INLET  */
#line 1189 "bisonparserV3.y"
        {
    if (params->dataInlets && params->fnDepth == 0 && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue) > *(params->dataInlets))
        *(params->dataInlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue);
    ((*yyvalp).astNodeValue) = new astInlet((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue), params->owner);
    code_dev_post ("parse: INLET %ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue));
}
#line 5665 "bisonparserV3.tab.c"
    break;

  case 199: /* item: INTINLET  */
#line 1195 "bisonparserV3.y"
           {
    if (params->dataInlets && params->fnDepth == 0 && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue) > *(params->dataInlets))
    *(params->dataInlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue);
    ((*yyvalp).astNodeValue) = new astConvInlet<hatom_fn_int>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue), params->owner);
    code_dev_post ("parse: INTINLET %ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue));
}
#line 5676 "bisonparserV3.tab.c"
    break;

  case 200: /* item: RATINLET  */
#line 1201 "bisonparserV3.y"
           {
    if (params->dataInlets && params->fnDepth == 0 && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue) > *(params->dataInlets))
    *(params->dataInlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue);
    ((*yyvalp).astNodeValue) = new astConvInlet<hatom_fn_rat>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue), params->owner);
    code_dev_post ("parse: RATINLET %ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue));
}
#line 5687 "bisonparserV3.tab.c"
    break;

  case 201: /* item: FLOATINLET  */
#line 1207 "bisonparserV3.y"
             {
    if (params->dataInlets && params->fnDepth == 0 && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue) > *(params->dataInlets))
    *(params->dataInlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue);
    ((*yyvalp).astNodeValue) = new astConvInlet<hatom_fn_float>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue), params->owner);
    code_dev_post ("parse: FLOATINLET %ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue));
}
#line 5698 "bisonparserV3.tab.c"
    break;

  case 202: /* item: PITCHINLET  */
#line 1213 "bisonparserV3.y"
             {
    if (params->dataInlets && params->fnDepth == 0 && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue) > *(params->dataInlets))
    *(params->dataInlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue);
    ((*yyvalp).astNodeValue) = new astConvInlet<hatom_fn_pitch>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue), params->owner);
    code_dev_post ("parse: PITCHINLET %ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue));
}
#line 5709 "bisonparserV3.tab.c"
    break;

  case 203: /* item: DIRINLET  */
#line 1219 "bisonparserV3.y"
           {
    if (params->directInlets && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue) > *(params->directInlets))
        *(params->directInlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue);
    auto fnConst = new astConst((*(params->ofTable))["directin"], params->owner);
    auto numConst = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.longValue), params->owner);
    auto tempList = new countedList<astNode *>(numConst);
    ((*yyvalp).astNodeValue) = new astFunctionCall(fnConst, tempList, nullptr, params->owner);
    code_dev_post("parse: DIRINLET");
}
#line 5723 "bisonparserV3.tab.c"
    break;

  case 204: /* item: OPEN sequence CLOSEDROUND  */
#line 1228 "bisonparserV3.y"
                            {
    ((*yyvalp).astNodeValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeValue);
    code_dev_post ("parse: []\n");
}
#line 5732 "bisonparserV3.tab.c"
    break;

  case 205: /* item: OPEN CLOSEDROUND  */
#line 1232 "bisonparserV3.y"
                   {
    ((*yyvalp).astNodeValue) = new astConst(llll_get(), params->owner);
}
#line 5740 "bisonparserV3.tab.c"
    break;

  case 206: /* item: PUSH sequence POP  */
#line 1235 "bisonparserV3.y"
                    {
    ((*yyvalp).astNodeValue) = new astWrap((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post("parse: []\n");
}
#line 5749 "bisonparserV3.tab.c"
    break;

  case 207: /* item: PUSH POP  */
#line 1239 "bisonparserV3.y"
           {
    t_llll *ll = llll_get();
    llll_appendllll(ll, llll_get());
    ((*yyvalp).astNodeValue) = new astConst(ll, params->owner);
    code_dev_post("parse: PushPop");
}
#line 5760 "bisonparserV3.tab.c"
    break;

  case 208: /* item: BIF  */
#line 1245 "bisonparserV3.y"
      {
    t_function *fn = (*(params->bifs))[(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue)->s_name];
    ((*yyvalp).astNodeValue) = new astConst(fn, params->owner);
    code_dev_post("parse: bif %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue)->s_name);
}
#line 5770 "bisonparserV3.tab.c"
    break;

  case 209: /* item: OF  */
#line 1250 "bisonparserV3.y"
     {
    t_function *fn = (*(params->ofTable))[(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue)->s_name];
    ((*yyvalp).astNodeValue) = new astConst(fn, params->owner);
    code_dev_post("parse: owned function %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.symValue)->s_name);
}
#line 5780 "bisonparserV3.tab.c"
    break;

  case 210: /* item: MAXFUNCTION  */
#line 1255 "bisonparserV3.y"
              {
    t_function *fn = new t_maxFunction(std::string((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.textValue)));
    params->funcs->insert(fn);
    ((*yyvalp).astNodeValue) = new astConst(fn, params->owner);
    code_dev_post("parse: Max function %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.textValue));
}
#line 5791 "bisonparserV3.tab.c"
    break;

  case 211: /* assignment: INIT LOCALVAR ASSIGN list  */
#line 1266 "bisonparserV3.y"
                          {
    addVariableToScope<e_flexBisonV3>(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.symValue));
    ((*yyvalp).astNodeValue) = new astInit((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.symValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    code_dev_post("parse: INIT LOCALVAR ASSIGN list");
}
#line 5801 "bisonparserV3.tab.c"
    break;

  case 212: /* assignment: lvalue ASSIGN list  */
#line 1271 "bisonparserV3.y"
                     {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astAssign((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astRichAssignment<E_RA_STANDARD>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5812 "bisonparserV3.tab.c"
    break;

  case 213: /* assignment: lvalue APOWOP list  */
#line 1277 "bisonparserV3.y"
                     {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astOperatorAPow((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astOperatorRAPow((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5823 "bisonparserV3.tab.c"
    break;

  case 214: /* assignment: lvalue ATIMES list  */
#line 1283 "bisonparserV3.y"
                     {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astOperatorATimes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astOperatorRATimes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5834 "bisonparserV3.tab.c"
    break;

  case 215: /* assignment: lvalue ADIVDIV list  */
#line 1289 "bisonparserV3.y"
                      {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astOperatorADivdiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astOperatorRADivdiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5845 "bisonparserV3.tab.c"
    break;

  case 216: /* assignment: lvalue ADIV list  */
#line 1295 "bisonparserV3.y"
                   {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astOperatorADiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astOperatorRADiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5856 "bisonparserV3.tab.c"
    break;

  case 217: /* assignment: lvalue AREM list  */
#line 1301 "bisonparserV3.y"
                   {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astOperatorARemainder((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astOperatorRARemainder((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5867 "bisonparserV3.tab.c"
    break;

  case 218: /* assignment: lvalue APLUS list  */
#line 1307 "bisonparserV3.y"
                    {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astOperatorAPlus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astOperatorRAPlus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5878 "bisonparserV3.tab.c"
    break;

  case 219: /* assignment: lvalue AMINUS list  */
#line 1313 "bisonparserV3.y"
                     {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astOperatorAMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astOperatorRAMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5889 "bisonparserV3.tab.c"
    break;

  case 220: /* assignment: lvalue ALOGAND list  */
#line 1319 "bisonparserV3.y"
                      {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astSCAAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astLogRASCAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5900 "bisonparserV3.tab.c"
    break;

  case 221: /* assignment: lvalue ALOGANDEXT list  */
#line 1325 "bisonparserV3.y"
                         {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astSCAAndExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astLogRASCAndExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5911 "bisonparserV3.tab.c"
    break;

  case 222: /* assignment: lvalue ALOGXOR list  */
#line 1331 "bisonparserV3.y"
                      {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astLogAXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astLogRAXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5922 "bisonparserV3.tab.c"
    break;

  case 223: /* assignment: lvalue ALOGOR list  */
#line 1337 "bisonparserV3.y"
                     {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astSCAOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astLogRASCOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5933 "bisonparserV3.tab.c"
    break;

  case 224: /* assignment: lvalue ALOGOREXT list  */
#line 1343 "bisonparserV3.y"
                        {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astSCAOrExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astLogRASCOrExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5944 "bisonparserV3.tab.c"
    break;

  case 225: /* assignment: lvalue ABITAND list  */
#line 1349 "bisonparserV3.y"
                      {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astOperatorABitAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astOperatorRABitAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5955 "bisonparserV3.tab.c"
    break;

  case 226: /* assignment: lvalue ABITXOR list  */
#line 1355 "bisonparserV3.y"
                      {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astOperatorABitXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astOperatorRABitXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5966 "bisonparserV3.tab.c"
    break;

  case 227: /* assignment: lvalue ABITOR list  */
#line 1361 "bisonparserV3.y"
                     {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astOperatorABitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astOperatorRABitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5977 "bisonparserV3.tab.c"
    break;

  case 228: /* assignment: lvalue ALSHIFT list  */
#line 1367 "bisonparserV3.y"
                      {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astOperatorALShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astOperatorRALShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5988 "bisonparserV3.tab.c"
    break;

  case 229: /* assignment: lvalue ARSHIFT list  */
#line 1373 "bisonparserV3.y"
                      {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astOperatorARShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astOperatorRARShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 5999 "bisonparserV3.tab.c"
    break;

  case 230: /* assignment: lvalue ACONCAT list  */
#line 1379 "bisonparserV3.y"
                      {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astConcatAssignOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astRAConcat((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 6010 "bisonparserV3.tab.c"
    break;

  case 231: /* assignment: lvalue ARCONCAT list  */
#line 1385 "bisonparserV3.y"
                       {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astRevConcatAssignOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = new astRARConcat((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), s, params->owner);
}
#line 6021 "bisonparserV3.tab.c"
    break;

  case 232: /* assignment: lvalue ANTHOP list  */
#line 1391 "bisonparserV3.y"
                     {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr)
        ((*yyvalp).astNodeValue) = new astNthAssignOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), params->owner);
    else
        ((*yyvalp).astNodeValue) = nullptr;
}
#line 6032 "bisonparserV3.tab.c"
    break;

  case 233: /* assignment: fakeLvalue ASSIGN list  */
#line 1398 "bisonparserV3.y"
                         {
    ((*yyvalp).astNodeValue) = new astRichEdit<E_RA_STANDARD>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 6040 "bisonparserV3.tab.c"
    break;

  case 234: /* assignment: fakeLvalue APOWOP list  */
#line 1401 "bisonparserV3.y"
                         {
    ((*yyvalp).astNodeValue) = new astOperatorREPow((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 6048 "bisonparserV3.tab.c"
    break;

  case 235: /* assignment: fakeLvalue ATIMES list  */
#line 1404 "bisonparserV3.y"
                         {
    ((*yyvalp).astNodeValue) = new astOperatorRETimes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 6056 "bisonparserV3.tab.c"
    break;

  case 236: /* assignment: fakeLvalue ADIVDIV list  */
#line 1407 "bisonparserV3.y"
                          {
    ((*yyvalp).astNodeValue) = new astOperatorREDivdiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 6064 "bisonparserV3.tab.c"
    break;

  case 237: /* assignment: fakeLvalue ADIV list  */
#line 1410 "bisonparserV3.y"
                       {
    ((*yyvalp).astNodeValue) = new astOperatorREDiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 6072 "bisonparserV3.tab.c"
    break;

  case 238: /* assignment: fakeLvalue AREM list  */
#line 1413 "bisonparserV3.y"
                       {
    ((*yyvalp).astNodeValue) = new astOperatorRERemainder((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 6080 "bisonparserV3.tab.c"
    break;

  case 239: /* assignment: fakeLvalue APLUS list  */
#line 1416 "bisonparserV3.y"
                        {
    ((*yyvalp).astNodeValue) = new astOperatorREPlus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 6088 "bisonparserV3.tab.c"
    break;

  case 240: /* assignment: fakeLvalue AMINUS list  */
#line 1419 "bisonparserV3.y"
                         {
    ((*yyvalp).astNodeValue) = new astOperatorREMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 6096 "bisonparserV3.tab.c"
    break;

  case 241: /* assignment: fakeLvalue ALOGAND list  */
#line 1422 "bisonparserV3.y"
                          {
    ((*yyvalp).astNodeValue) = new astLogRESCAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 6104 "bisonparserV3.tab.c"
    break;

  case 242: /* assignment: fakeLvalue ALOGANDEXT list  */
#line 1425 "bisonparserV3.y"
                             {
    ((*yyvalp).astNodeValue) = new astLogRESCAndExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 6112 "bisonparserV3.tab.c"
    break;

  case 243: /* assignment: fakeLvalue ALOGXOR list  */
#line 1428 "bisonparserV3.y"
                          {
    ((*yyvalp).astNodeValue) = new astLogREXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 6120 "bisonparserV3.tab.c"
    break;

  case 244: /* assignment: fakeLvalue ALOGOR list  */
#line 1431 "bisonparserV3.y"
                         {
    ((*yyvalp).astNodeValue) = new astLogRESCOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 6128 "bisonparserV3.tab.c"
    break;

  case 245: /* assignment: fakeLvalue ALOGOREXT list  */
#line 1434 "bisonparserV3.y"
                            {
    ((*yyvalp).astNodeValue) = new astLogRESCOrExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 6136 "bisonparserV3.tab.c"
    break;

  case 246: /* assignment: fakeLvalue ABITAND list  */
#line 1437 "bisonparserV3.y"
                          {
    ((*yyvalp).astNodeValue) = new astOperatorREBitAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 6144 "bisonparserV3.tab.c"
    break;

  case 247: /* assignment: fakeLvalue ABITXOR list  */
#line 1440 "bisonparserV3.y"
                          {
    ((*yyvalp).astNodeValue) = new astOperatorREBitXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 6152 "bisonparserV3.tab.c"
    break;

  case 248: /* assignment: fakeLvalue ABITOR list  */
#line 1443 "bisonparserV3.y"
                         {
    ((*yyvalp).astNodeValue) = new astOperatorREBitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 6160 "bisonparserV3.tab.c"
    break;

  case 249: /* assignment: fakeLvalue ALSHIFT list  */
#line 1446 "bisonparserV3.y"
                          {
    ((*yyvalp).astNodeValue) = new astOperatorRELShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 6168 "bisonparserV3.tab.c"
    break;

  case 250: /* assignment: fakeLvalue ARSHIFT list  */
#line 1449 "bisonparserV3.y"
                          {
    ((*yyvalp).astNodeValue) = new astOperatorRERShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 6176 "bisonparserV3.tab.c"
    break;

  case 251: /* assignment: fakeLvalue ACONCAT list  */
#line 1452 "bisonparserV3.y"
                          {
    ((*yyvalp).astNodeValue) = new astREConcat((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 6184 "bisonparserV3.tab.c"
    break;

  case 252: /* assignment: fakeLvalue ARCONCAT list  */
#line 1455 "bisonparserV3.y"
                           {
    ((*yyvalp).astNodeValue) = new astRERConcat((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs(), params->owner);
}
#line 6192 "bisonparserV3.tab.c"
    break;

  case 253: /* assignment: lvalue AAPPLY funcall  */
#line 1459 "bisonparserV3.y"
                        {
    if (auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getSpecs(); s == nullptr) {
        (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astFunctionCallValue)->addDataflowStyleArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar());
        ((*yyvalp).astNodeValue) = new astAssign((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astFunctionCallValue), params->owner);
    } else {
        auto v = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvalueValue)->getVar();
        (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astFunctionCallValue)->addDataflowStyleArg(new astConst(params->owner));
        ((*yyvalp).astNodeValue) = new astRichAccessApplyOp<astRichAssignment<E_RA_SHORTCIRCUIT>>(v, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astFunctionCallValue), s, params->owner);
    }
    code_dev_post("parse: lvalue AAPPLY funcall");
}
#line 6208 "bisonparserV3.tab.c"
    break;

  case 254: /* assignment: fakeLvalue AAPPLY funcall  */
#line 1471 "bisonparserV3.y"
                            {
    auto n = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getNode();
    auto s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fakeLvalueValue)->getSpecs();
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astFunctionCallValue)->addDataflowStyleArg(new astConst(params->owner));
    ((*yyvalp).astNodeValue) = new astRichAccessApplyOp<astRichEdit<E_RA_SHORTCIRCUIT>>(n, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astFunctionCallValue), s, params->owner);
    code_dev_post("parse: fakeLvalue AAPPLY funcall");
}
#line 6220 "bisonparserV3.tab.c"
    break;

  case 255: /* assignment: OUTLET ASSIGN list  */
#line 1479 "bisonparserV3.y"
                     {
    if (params->dataOutlets && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.longValue) > *(params->dataOutlets))
        *(params->dataOutlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.longValue);
    auto fnConst = new astConst((*(params->bifs))["outlet"], params->owner);


    auto numConst = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.longValue), params->owner);
    auto v = new std::vector<astNode*>;
    v->push_back(numConst);
    v->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    ((*yyvalp).astNodeValue) = new astFunctionCall(fnConst, v, nullptr, params->owner);
    code_dev_post("parse: OUTLET ASSIGN list");
}
#line 6238 "bisonparserV3.tab.c"
    break;

  case 256: /* assignment: DIROUTLET ASSIGN list  */
#line 1493 "bisonparserV3.y"
                        {
    if (params->directOutlets && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.longValue) > *(params->directOutlets))
        *(params->directOutlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.longValue);
    auto fnConst = new astConst((*(params->ofTable))["directout"], params->owner);
    auto v = new std::vector<astNode*>;
    v->push_back(new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.longValue), params->owner));
    v->push_back((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue));
    ((*yyvalp).astNodeValue) = new astFunctionCall(fnConst, v, nullptr, params->owner);
    code_dev_post("parse: DIROUTLET ASSIGN list");
}
#line 6253 "bisonparserV3.tab.c"
    break;

  case 257: /* conditional: IF_KW sequence THEN_KW list  */
#line 1508 "bisonparserV3.y"
                                          {
    ((*yyvalp).astNodeValue) = new astIfThenElse((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.astNodeValue), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.astNodeValue), nullptr, params->owner);
    code_dev_post ("parse: if then\n");
}
#line 6262 "bisonparserV3.tab.c"
    break;

  case 258: /* conditional: IF_KW sequence THEN_KW list ELSE_KW list  */
#line 1512 "bisonparserV3.y"
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
#line 6288 "bisonparserV3.tab.c"
    break;


#line 6292 "bisonparserV3.tab.c"

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
#line 194 "bisonparserV3.y"
{
    #ifdef YYDEBUG
    #if YYDEBUG == 1
    yydebug = 1;
    #endif
    #endif
}

#line 7699 "bisonparserV3.tab.c"


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


#line 1536 "bisonparserV3.y"


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
    params.localVariablesStackBase[0] = nullptr;
    params.localVariablesStackBaseV[0] = new std::vector<t_localVar>;
    params.localVariablesStackV = params.localVariablesStackBaseV;
    params.localVariablesAuxMapStack = params.localVariablesAuxMapStackBase;
    params.localVariablesAuxMapStack[0] = new std::unordered_map<t_symbol *, int>;
    params.liftedVariablesStack = params.liftedVariablesStackBase;
    params.argumentsStack = params.argumentsStackBase;
    params.argumentsStackBase[0] = nullptr;
    params.argumentsStackBaseV[0] = new std::vector<funArg*>;
    params.argumentsStackV = params.argumentsStackBaseV;
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
            params.localVariablesStackBaseV[0],
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


