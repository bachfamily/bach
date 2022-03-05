<<<<<<< HEAD
/* A Bison parser, made by GNU Bison 3.8.2.  */
=======
/* A Bison parser, made by GNU Bison 3.7.6.  */
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8

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
<<<<<<< HEAD
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"
=======
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 1




/* Substitute the variable and function names.  */
#define yyparse stringparser_parse
#define yylex   stringparser_lex
#define yyerror stringparser_error
#define yydebug stringparser_debug

/* First part of user prologue.  */
#line 1 "stringparser.y"

    /*
     *  stringparser.y
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
#line 28 "stringparser.y"

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
    #include "stringparser.h"
    
    extern t_bach *bach;


    

#line 113 "stringparser.tab.c"

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

#include "stringparser.tab.h"

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
  YYSYMBOL_SEQ = 22,                       /* SEQ  */
  YYSYMBOL_IF_KW = 23,                     /* IF_KW  */
  YYSYMBOL_THEN_KW = 24,                   /* THEN_KW  */
  YYSYMBOL_ELSE_KW = 25,                   /* ELSE_KW  */
  YYSYMBOL_WHILE_KW = 26,                  /* WHILE_KW  */
  YYSYMBOL_DO_KW = 27,                     /* DO_KW  */
  YYSYMBOL_FOR_KW = 28,                    /* FOR_KW  */
  YYSYMBOL_IN_KW = 29,                     /* IN_KW  */
  YYSYMBOL_COLLECT_KW = 30,                /* COLLECT_KW  */
  YYSYMBOL_ASSIGN = 31,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 32,                      /* PLUS  */
  YYSYMBOL_MINUS = 33,                     /* MINUS  */
  YYSYMBOL_TIMES = 34,                     /* TIMES  */
  YYSYMBOL_DIV = 35,                       /* DIV  */
  YYSYMBOL_DIVDIV = 36,                    /* DIVDIV  */
  YYSYMBOL_APLUS = 37,                     /* APLUS  */
  YYSYMBOL_LOGOR = 38,                     /* LOGOR  */
  YYSYMBOL_LOGAND = 39,                    /* LOGAND  */
  YYSYMBOL_LOGOREXT = 40,                  /* LOGOREXT  */
  YYSYMBOL_LOGANDEXT = 41,                 /* LOGANDEXT  */
  YYSYMBOL_EQUAL = 42,                     /* EQUAL  */
  YYSYMBOL_LT = 43,                        /* LT  */
  YYSYMBOL_GT = 44,                        /* GT  */
  YYSYMBOL_LEQ = 45,                       /* LEQ  */
  YYSYMBOL_GEQ = 46,                       /* GEQ  */
  YYSYMBOL_NEQ = 47,                       /* NEQ  */
  YYSYMBOL_OPEN = 48,                      /* OPEN  */
  YYSYMBOL_CLOSEDROUND = 49,               /* CLOSEDROUND  */
  YYSYMBOL_FUNDEF = 50,                    /* FUNDEF  */
  YYSYMBOL_PUSH = 51,                      /* PUSH  */
  YYSYMBOL_POP = 52,                       /* POP  */
  YYSYMBOL_STARTPARAMS = 53,               /* STARTPARAMS  */
  YYSYMBOL_COMMA = 54,                     /* COMMA  */
  YYSYMBOL_ELLIPSIS = 55,                  /* ELLIPSIS  */
  YYSYMBOL_BACHNULL = 56,                  /* BACHNULL  */
  YYSYMBOL_BACHNIL = 57,                   /* BACHNIL  */
  YYSYMBOL_ARGCOUNT = 58,                  /* ARGCOUNT  */
  YYSYMBOL_EOL = 59,                       /* EOL  */
  YYSYMBOL_UNRECOGNIZED = 60,              /* UNRECOGNIZED  */
  YYSYMBOL_LIFT = 61,                      /* LIFT  */
  YYSYMBOL_AMINUS = 62,                    /* AMINUS  */
  YYSYMBOL_ATIMES = 63,                    /* ATIMES  */
  YYSYMBOL_APOWOP = 64,                    /* APOWOP  */
  YYSYMBOL_ADIV = 65,                      /* ADIV  */
  YYSYMBOL_ADIVDIV = 66,                   /* ADIVDIV  */
  YYSYMBOL_AREM = 67,                      /* AREM  */
  YYSYMBOL_ABITAND = 68,                   /* ABITAND  */
  YYSYMBOL_ABITXOR = 69,                   /* ABITXOR  */
  YYSYMBOL_ABITOR = 70,                    /* ABITOR  */
  YYSYMBOL_ALSHIFT = 71,                   /* ALSHIFT  */
  YYSYMBOL_ARSHIFT = 72,                   /* ARSHIFT  */
  YYSYMBOL_ALOGAND = 73,                   /* ALOGAND  */
  YYSYMBOL_ALOGANDEXT = 74,                /* ALOGANDEXT  */
  YYSYMBOL_ALOGXOR = 75,                   /* ALOGXOR  */
  YYSYMBOL_ALOGOR = 76,                    /* ALOGOR  */
  YYSYMBOL_ALOGOREXT = 77,                 /* ALOGOREXT  */
  YYSYMBOL_ANTHOP = 78,                    /* ANTHOP  */
  YYSYMBOL_AAPPLY = 79,                    /* AAPPLY  */
  YYSYMBOL_ACONCAT = 80,                   /* ACONCAT  */
  YYSYMBOL_ARCONCAT = 81,                  /* ARCONCAT  */
  YYSYMBOL_CONCAT = 82,                    /* CONCAT  */
  YYSYMBOL_LOGXOR = 83,                    /* LOGXOR  */
  YYSYMBOL_BITOR = 84,                     /* BITOR  */
  YYSYMBOL_BITXOR = 85,                    /* BITXOR  */
  YYSYMBOL_BITAND = 86,                    /* BITAND  */
  YYSYMBOL_REPEAT = 87,                    /* REPEAT  */
  YYSYMBOL_RANGE = 88,                     /* RANGE  */
  YYSYMBOL_LSHIFT = 89,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 90,                    /* RSHIFT  */
  YYSYMBOL_REM = 91,                       /* REM  */
  YYSYMBOL_UPLUS = 92,                     /* UPLUS  */
  YYSYMBOL_UMINUS = 93,                    /* UMINUS  */
  YYSYMBOL_POWOP = 94,                     /* POWOP  */
  YYSYMBOL_NTHOP = 95,                     /* NTHOP  */
  YYSYMBOL_PICKOP = 96,                    /* PICKOP  */
  YYSYMBOL_APPLY = 97,                     /* APPLY  */
  YYSYMBOL_ACCESS_UNWRAP = 98,             /* ACCESS_UNWRAP  */
  YYSYMBOL_LVALUESTEPPARAMS = 99,          /* LVALUESTEPPARAMS  */
  YYSYMBOL_AS_KW = 100,                    /* AS_KW  */
  YYSYMBOL_WITH_KW = 101,                  /* WITH_KW  */
  YYSYMBOL_LOGNOT = 102,                   /* LOGNOT  */
  YYSYMBOL_BITNOT = 103,                   /* BITNOT  */
  YYSYMBOL_KEEP = 104,                     /* KEEP  */
  YYSYMBOL_UNKEEP = 105,                   /* UNKEEP  */
  YYSYMBOL_INIT = 106,                     /* INIT  */
  YYSYMBOL_YYACCEPT = 107,                 /* $accept  */
  YYSYMBOL_program = 108,                  /* program  */
  YYSYMBOL_sequence = 109,                 /* sequence  */
  YYSYMBOL_ifThenElse = 110,               /* ifThenElse  */
  YYSYMBOL_whileloop = 111,                /* whileloop  */
  YYSYMBOL_forloop = 112,                  /* forloop  */
  YYSYMBOL_forargList = 113,               /* forargList  */
  YYSYMBOL_forarg = 114,                   /* forarg  */
  YYSYMBOL_fundef = 115,                   /* fundef  */
  YYSYMBOL_116_1 = 116,                    /* $@1  */
  YYSYMBOL_117_2 = 117,                    /* $@2  */
  YYSYMBOL_118_3 = 118,                    /* $@3  */
  YYSYMBOL_119_4 = 119,                    /* $@4  */
  YYSYMBOL_funargList = 120,               /* funargList  */
  YYSYMBOL_121_5 = 121,                    /* $@5  */
  YYSYMBOL_122_6 = 122,                    /* $@6  */
  YYSYMBOL_liftedargList = 123,            /* liftedargList  */
  YYSYMBOL_functionApplication = 124,      /* functionApplication  */
  YYSYMBOL_funcall = 125,                  /* funcall  */
  YYSYMBOL_argsByPositionList = 126,       /* argsByPositionList  */
  YYSYMBOL_argsByNameList = 127,           /* argsByNameList  */
  YYSYMBOL_argByName = 128,                /* argByName  */
  YYSYMBOL_list = 129,                     /* list  */
  YYSYMBOL_listEnd = 130,                  /* listEnd  */
  YYSYMBOL_simpleList = 131,               /* simpleList  */
  YYSYMBOL_assignment = 132,               /* assignment  */
  YYSYMBOL_assign = 133,                   /* assign  */
  YYSYMBOL_lvalueStepList = 134,           /* lvalueStepList  */
  YYSYMBOL_lvalueStepParams = 135,         /* lvalueStepParams  */
  YYSYMBOL_exp = 136,                      /* exp  */
  YYSYMBOL_term = 137,                     /* term  */
  YYSYMBOL_var = 138,                      /* var  */
  YYSYMBOL_globalVar = 139,                /* globalVar  */
  YYSYMBOL_patcherVar = 140,               /* patcherVar  */
  YYSYMBOL_localVar = 141                  /* localVar  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;

/* Second part of user prologue.  */
#line 149 "stringparser.y"

    #include "stringparser_tab_nolines.h"
    
    #define YY_HEADER_EXPORT_START_CONDITIONS
    #define YY_NO_UNISTD_H
    
    #include "stringparser_lex_nolines.h"
    

    
    int yylex(YYSTYPE *yylval_param, yyscan_t myscanner, struct _parseParams
    *params);
    
    int yyerror(yyscan_t myscanner,
    t_parseParams *params,
    const char *s);
    
    
    YY_BUFFER_STATE stringparser_scan_string(yyscan_t myscanner, const char *buf);
    void stringparser_flush_and_delete_buffer(yyscan_t myscanner, YY_BUFFER_STATE bp);
    
    void addVariableToScope(t_parseParams *params, t_symbol *name)
    {
        auto known = (*(params->localVariablesAuxMapStack))->find(name);
        if (known == (*(params->localVariablesAuxMapStack))->end()) { // yet unknown
            (**(params->localVariablesAuxMapStack))[name] = 1;
            
            if (params->liftedVariablesStack == params->liftedVariablesStackBase) {
                *(params->localVariablesStack) = new countedList<t_localVar> (t_localVar(name, true), *(params->localVariablesStack)); // if we're at the main function level, then everything is lifted (as it can be set from the outside)
            } else {
                t_bool lifted = (*(params->liftedVariablesStack))->find(name) != (*(params->liftedVariablesStack))->end();
                
                *(params->localVariablesStack) = new countedList<t_localVar> (t_localVar(name, lifted), *(params->localVariablesStack));

                /*
                if (lifted == (*(params->liftedVariablesStack))->end()) { // not lifted
                    *(params->argumentsStack) = new countedList<funArg *>(new funArg(name), *(params->argumentsStack));
                } else { // old behavior: lifted
                    *(params->localVariablesStack) = new countedList<t_symbol *> (name, *(params->localVariablesStack));
                }
                 */
            }
        }
    }

#line 341 "stringparser.tab.c"


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
<<<<<<< HEAD
                && (4 < __GNUC__ + (7 <= __GNUC_MINOR__) \
=======
                && (__4 < __GNUC__ + (7 <= __GNUC_MINOR__) \
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
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
#define YYFINAL  84
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1785

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  107
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  241
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  421
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 8
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   361

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
     105,   106
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   211,   211,   216,   222,   228,   236,   237,   243,   247,
     269,   273,   279,   284,   289,   294,   299,   304,   309,   314,
     319,   324,   331,   335,   341,   346,   354,   354,   370,   370,
     388,   388,   409,   409,   434,   441,   447,   447,   464,   469,
     473,   473,   486,   490,   496,   497,   504,   509,   514,   520,
     526,   532,   536,   542,   546,   550,   556,   561,   562,   563,
     569,   570,   571,   572,   573,   576,   577,   583,   584,   596,
     607,   611,   616,   620,   624,   628,   632,   636,   640,   644,
     648,   652,   656,   660,   664,   668,   672,   676,   680,   684,
     688,   692,   696,   700,   704,   708,   712,   716,   720,   724,
     728,   732,   736,   740,   744,   748,   752,   756,   760,   764,
     768,   772,   776,   780,   785,   792,   797,   805,   809,   813,
     817,   824,   825,   831,   832,   833,   837,   841,   845,   849,
     853,   857,   861,   865,   869,   873,   877,   881,   885,   889,
     893,   897,   901,   905,   909,   913,   917,   921,   925,   929,
     933,   937,   941,   945,   949,   953,   957,   962,   963,   967,
     971,   975,   979,   983,   987,   991,   995,   999,  1003,  1007,
    1011,  1015,  1019,  1023,  1027,  1031,  1035,  1039,  1043,  1047,
    1051,  1055,  1059,  1063,  1067,  1071,  1075,  1079,  1083,  1087,
    1092,  1096,  1100,  1104,  1108,  1112,  1116,  1120,  1124,  1128,
    1132,  1136,  1140,  1144,  1148,  1152,  1156,  1160,  1164,  1168,
    1172,  1176,  1183,  1187,  1191,  1195,  1199,  1203,  1207,  1212,
    1218,  1224,  1230,  1236,  1242,  1248,  1257,  1261,  1264,  1268,
    1274,  1279,  1284,  1285,  1288,  1289,  1290,  1293,  1301,  1309,
    1314,  1319
};
#endif

#define YYPACT_NINF (-152)
#define YYTABLE_NINF (-45)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     769,  -152,  -152,  -152,  -152,  -152,  -152,    -7,  -152,    29,
    -152,  -152,  -152,  -152,  -152,  -152,   117,  -152,  -152,  -152,
    1017,  1017,    43,   795,  -152,   899,  -152,  -152,  -152,  -152,
      56,  1017,  1017,  1017,  1017,    60,    68,    78,    11,    76,
    -152,  -152,  -152,  -152,    23,   -29,  -152,  -152,  -152,  -152,
    1076,  -152,  -152,  1285,   -43,  1532,    20,    51,    57,  1017,
    1017,  -152,    45,    67,    16,   -21,  -152,  -152,     4,  1017,
    -152,     6,  -152,  -152,    31,  -152,    31,  -152,  -152,  -152,
    -152,  -152,  -152,    69,  -152,  -152,  1017,  -152,    -4,    18,
    -152,    83,  -152,  1285,  1017,  1017,  1017,  1017,  1017,  1017,
    1017,  1017,  1017,  1017,  1017,  1017,  1017,  1017,  1017,  1017,
    1017,  1017,  1017,  1017,  1017,  1017,  1017,  1017,  1017,  1017,
    1017,  1017,  1017,   451,   425,   425,  1430,  1017,  1017,  1017,
    1017,  1017,  1017,  1017,  1017,  1017,  1017,  1017,  1017,  1017,
    1017,  1017,  1017,  1017,  1017,  1017,  1017,  1017,  1481,   425,
     425,   425,  -152,  -152,  1017,  1017,  1017,  1017,    73,  1017,
    1017,  1017,    43,  1017,   125,  -152,  -152,  -152,  1017,  -152,
    1017,   111,  -152,  -152,  1017,  -152,  -152,   260,  -152,   260,
    -152,    31,  -152,    31,  -152,    31,  -152,  1301,  -152,   847,
    -152,  1301,  -152,   847,  -152,   291,  -152,   527,  -152,   527,
    -152,   527,  -152,   527,  -152,   291,  -152,  1384,  -152,  1588,
    -152,  1604,  -152,  1620,  -152,  1636,  -152,  1687,  -152,   123,
    -152,   123,  -152,    31,  -152,    31,  -152,  -152,  -152,  -152,
     665,  -152,  -152,  -152,  -152,  1017,  -152,   128,     1,    10,
    -152,  -152,   425,  1368,  -152,  -152,  -152,  -152,   425,  1017,
    1017,  1017,  1017,  1017,  1017,  1017,  1017,  1017,  1017,  1017,
    1017,  1017,  1017,  1017,  1017,  1017,  1017,  1017,   425,  1017,
    1017,   425,   425,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  1017,  1017,  1017,  1017,  1017,  1017,
    1017,  1017,  1017,  1017,  1017,  1017,  1017,  1017,  1017,  1017,
    1017,  1017,  1017,   425,  1017,  1017,  1103,  1285,  1119,  1186,
    -152,   127,  -152,  -152,  1017,   128,  -152,  -152,  -152,   -14,
     -15,  -152,  -152,  -152,  1017,  -152,   128,  -152,   958,    21,
    -152,   125,  -152,  1368,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  1202,  -152,  -152,   425,   425,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  1269,  -152,  -152,
    1017,   128,  1017,  1017,   125,  1017,  1017,  1017,  1017,  -152,
     128,    22,  -152,  -152,  -152,  -152,  -152,     8,  -152,  -152,
     146,  -152,  -152,  1017,  1017,  1017,  1017,  -152,  -152,  -152,
    -152
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,   212,   220,   221,   222,   223,   224,     0,   225,     0,
     213,   214,   215,   216,   237,   238,   239,     3,   230,   231,
       0,     0,     0,     0,    28,     0,    35,   217,   219,   218,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
      63,    61,    62,    64,     0,     0,   233,    44,     6,    57,
      58,    60,    67,    65,   123,   232,   234,   236,   235,     0,
       0,    36,     0,     0,     0,     0,    22,   227,     0,     0,
     229,     0,    42,   124,   157,   125,   158,   126,   159,   127,
     160,   240,   241,     0,     1,     5,     0,    26,     0,     0,
      32,     0,    59,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    68,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   226,    29,   228,     0,     7,
       0,    38,    39,    30,     0,    43,   128,   161,   129,   162,
     130,   163,   131,   164,   132,   165,   146,   179,   147,   180,
     149,   182,   150,   183,   140,   173,   142,   175,   143,   176,
     144,   177,   145,   178,   141,   174,   148,   181,   137,   170,
     136,   169,   135,   168,   154,   187,   153,   186,   138,   171,
     139,   172,   133,   166,   134,   167,   151,   184,   152,   185,
      44,   155,   188,   156,   189,     0,    50,    51,     0,     0,
      53,   239,   117,   121,   232,   234,   236,   235,   118,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,    73,    75,    77,    79,    81,    83,
      85,    87,    89,    91,    93,    95,    97,    99,   101,   103,
     105,   107,   109,   111,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   115,     0,   114,   113,
      37,     8,    10,    11,     0,    24,    12,    17,    23,     0,
       0,    71,    27,    40,     0,    33,    56,    46,     0,     0,
      47,     0,    55,   122,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   211,   209,   210,   119,   120,    72,    74,
      76,    78,    80,    82,    84,    86,    88,    90,    92,    94,
      96,    98,   100,   102,   104,   106,   108,   116,   110,   112,
       0,    25,     0,     0,     0,     0,     0,     0,     0,    31,
      52,     0,    49,    54,     9,    14,    19,     0,    13,    18,
       0,    41,    48,     0,     0,     0,     0,    15,    20,    16,
      21
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -152,  -152,   -20,  -152,  -152,  -152,  -152,    -2,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,   118,  -152,  -119,  -152,
    -145,  -151,   -23,   482,  -152,  -152,  -152,   108,  -118,   300,
    -152,  -107,  -102,   -68,   -59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    38,    39,    40,    41,    42,    65,    66,    43,   170,
      69,   334,   174,    44,   154,   398,    45,    46,    47,   238,
     239,   240,    48,    49,    50,    51,    52,   126,   242,    53,
      54,    55,    56,    57,    58
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,    63,   230,    68,   235,    71,   160,   248,    86,   161,
     123,    84,   395,   392,   171,   396,   393,   244,   244,   330,
     235,    90,   245,   245,    59,    91,    86,   235,    86,   235,
     316,   318,   319,   162,   158,   413,   152,   153,   414,   341,
     235,   235,   244,   244,   244,   159,   166,   245,   245,   245,
     337,   172,   124,   165,   125,   338,   246,   246,   167,   340,
      60,    64,   341,   169,   341,   247,   247,    86,   173,   155,
     402,   412,    91,    87,    72,   341,   341,    88,    81,   163,
     164,   246,   246,   246,    30,   397,    82,   394,   342,    86,
     247,   247,   247,   339,   156,    85,    83,   157,    86,   149,
     168,   175,   324,   237,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   118,   119,   120,   121,   122,
     150,   320,   321,   322,   323,   244,   151,   326,   327,   325,
     245,   244,   333,   329,   235,   331,   245,   332,    61,   363,
      86,   335,   390,   366,   367,    94,    95,    96,    97,    98,
     328,   244,    89,   148,   244,   244,   245,   -34,    86,   245,
     245,   -34,     0,   415,   246,     0,   416,     0,   -34,   342,
     246,     0,     0,   247,     0,     0,     0,     0,   342,   247,
     403,     0,     0,   401,   387,     0,     0,     0,     0,     0,
     246,     0,     0,   246,   246,     0,   244,     0,     0,   247,
       0,   245,   247,   247,   117,   336,     0,   118,   119,   120,
     121,   122,     0,     0,     0,     0,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   246,   364,   365,     0,   407,
     342,     0,     0,     0,   247,     0,   342,     0,     0,   244,
     244,     0,     0,     0,   245,   245,     0,     0,     0,     0,
       0,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
       0,   388,   389,     0,    96,    97,    98,     0,   246,   246,
       0,     0,     0,     0,   391,     0,     0,   247,   247,     0,
       0,   399,     0,     0,     0,     0,     0,     0,   400,     0,
       0,     0,     0,    94,    95,    96,    97,    98,     0,     0,
       0,    74,    76,    78,    80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      93,   117,     0,     0,   118,   119,   120,   121,   122,     0,
       0,     0,     0,     0,     0,     0,     0,   404,     0,   405,
     406,     0,   408,   409,     0,   411,     0,   410,   113,   114,
     115,   116,   117,     0,     0,   118,   119,   120,   121,   122,
     417,   418,   419,   420,   177,   179,   181,   183,   185,   187,
     189,   191,   193,   195,   197,   199,   201,   203,   205,   207,
     209,   211,   213,   215,   217,   219,   221,   223,   225,   227,
     229,   232,   234,     0,   243,   243,     0,     0,     1,     2,
       3,     4,     5,     6,     0,     8,     0,    10,    11,    12,
      13,    14,    15,   241,     0,    18,    19,     0,     0,   317,
     317,   317,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
     235,    18,    19,    23,    20,     0,    25,    21,     0,    22,
       0,    27,    28,    29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
     236,    24,    25,     0,     0,     0,    26,    27,    28,    29,
       0,     0,    30,    73,    75,    77,    79,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,     0,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   343,    31,    32,     0,     0,     0,   343,     0,
       0,     0,     0,    33,    34,    35,    36,    37,     0,    94,
      95,    96,    97,    98,     0,     0,     0,     0,   317,   103,
       0,   243,   243,     0,   108,     0,   176,   178,   180,   182,
     184,   186,   188,   190,   192,   194,   196,   198,   200,   202,
     204,   206,   208,   210,   212,   214,   216,   218,   220,   222,
     224,   226,   228,   231,   233,     0,     0,     0,     0,     0,
       0,     0,     0,   317,   113,   114,   115,   116,   117,     0,
       0,   118,   119,   120,   121,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -44,   343,   343,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,     0,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,     0,     0,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,     0,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,     0,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,     0,     0,    21,     0,    22,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     0,    18,    19,    23,    20,    24,
      25,    21,     0,    22,    26,    27,    28,    29,     0,     0,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    23,    67,    24,    25,     0,     0,     0,
      26,    27,    28,    29,     0,     0,    30,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,     0,     0,     0,    94,
      95,    96,    97,    98,     0,     0,     0,    31,    32,   103,
     104,   105,   106,   107,   108,     0,     0,    33,    34,    35,
      36,    37,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     0,    18,
      19,     0,    20,     0,     0,    21,     0,    22,     0,     0,
       0,   110,   111,   112,   113,   114,   115,   116,   117,     0,
       0,   118,   119,   120,   121,   122,     0,    23,     0,    24,
      25,    70,     0,     0,    26,    27,    28,    29,     0,     0,
      30,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,   235,    18,    19,
       0,    20,     0,     0,    21,     0,    22,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    23,     0,    24,    25,
       0,     0,     0,    26,    27,    28,    29,     0,     0,    30,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     0,    18,    19,     0,
      20,     0,     0,    21,     0,    22,     0,     0,     0,     0,
      31,    32,     0,     0,     0,     0,     0,     0,     0,     0,
      33,    34,    35,    36,    37,    23,     0,    24,    25,     0,
       0,     0,    26,    27,    28,    29,     0,     0,    30,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     0,    18,    19,     0,    20,
       0,     0,    21,     0,    22,     0,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    23,     0,     0,    25,     0,     0,
       0,    26,    27,    28,    29,   -44,   -44,   -44,   -44,   -44,
       0,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,     0,    31,    32,
       0,     0,   -44,     0,     0,     0,     0,     0,    33,    34,
      35,    36,    37,     0,     0,     0,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,     0,     0,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,     0,     0,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,     0,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
       0,     0,     0,     0,     0,   -44,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,     0,     0,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,     0,     0,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,     0,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,    94,    95,    96,
      97,    98,   -44,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    94,    95,    96,    97,    98,     0,     0,
     100,     0,   102,   103,   104,   105,   106,   107,   108,     0,
       0,     0,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,     0,     0,   -44,   -44,   -44,   -44,   -44,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     0,     0,   118,
     119,   120,   121,   122,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     0,     0,   118,   119,   120,   121,   122,
      94,    95,    96,    97,    98,     0,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    94,    95,    96,    97,
      98,     0,     0,   100,     0,   102,   103,   104,   105,   106,
     107,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
       0,   249,   118,     0,   120,     0,   122,   250,   110,   111,
     112,   113,   114,   115,   116,   117,     0,     0,   118,   119,
     120,   121,   122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   294,     0,     0,     0,     0,     0,   295,     0,
       0,     0,     0,     0,     0,   271,     0,   272,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   127,     0,     0,     0,     0,     0,   128,
       0,     0,     0,     0,     0,     0,   271,     0,   272,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,   146,   147,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,    98,     0,     0,   124,     0,   125,
     103,   104,   105,   106,   107,   108,    94,    95,    96,    97,
      98,     0,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,    94,    95,    96,    97,    98,     0,     0,     0,
       0,     0,   103,   104,   105,   106,   107,   108,    94,    95,
      96,    97,    98,   111,   112,   113,   114,   115,   116,   117,
       0,     0,   118,   119,   120,   121,   122,     0,     0,     0,
     112,   113,   114,   115,   116,   117,     0,     0,   118,   119,
     120,   121,   122,     0,     0,     0,     0,   113,   114,   115,
     116,   117,     0,     0,   118,   119,   120,   121,   122,    94,
      95,    96,    97,    98,   114,   115,   116,   117,     0,     0,
     118,   119,   120,   121,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   115,   116,   117,     0,
       0,   118,   119,   120,   121,   122
};

static const yytype_int16 yycheck[] =
{
      20,    21,   121,    23,    19,    25,    27,   125,    22,    30,
      53,     0,    27,    27,    18,    30,    30,   124,   125,   164,
      19,    50,   124,   125,    31,    54,    22,    19,    22,    19,
     149,   150,   151,    54,    18,    27,    59,    60,    30,    54,
      19,    19,   149,   150,   151,    29,    69,   149,   150,   151,
      49,    55,    95,    49,    97,    54,   124,   125,    52,    49,
      31,    18,    54,    86,    54,   124,   125,    22,    50,    24,
      49,    49,    54,    50,    18,    54,    54,    54,    18,   100,
     101,   149,   150,   151,    61,   100,    18,   101,   239,    22,
     149,   150,   151,   238,    27,    19,    18,    30,    22,    79,
      31,    18,    29,   123,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,    94,    95,    96,    97,    98,
      79,   154,   155,   156,   157,   242,    79,   160,   161,   159,
     242,   248,    31,   163,    19,   168,   248,   170,    31,   268,
      22,   174,    25,   271,   272,    32,    33,    34,    35,    36,
     162,   268,    44,    55,   271,   272,   268,    50,    22,   271,
     272,    54,    -1,    27,   242,    -1,    30,    -1,    61,   330,
     248,    -1,    -1,   242,    -1,    -1,    -1,    -1,   339,   248,
     341,    -1,    -1,   338,   313,    -1,    -1,    -1,    -1,    -1,
     268,    -1,    -1,   271,   272,    -1,   313,    -1,    -1,   268,
      -1,   313,   271,   272,    91,   235,    -1,    94,    95,    96,
      97,    98,    -1,    -1,    -1,    -1,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   313,   269,   270,    -1,   394,
     401,    -1,    -1,    -1,   313,    -1,   407,    -1,    -1,   366,
     367,    -1,    -1,    -1,   366,   367,    -1,    -1,    -1,    -1,
      -1,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
      -1,   314,   315,    -1,    34,    35,    36,    -1,   366,   367,
      -1,    -1,    -1,    -1,   324,    -1,    -1,   366,   367,    -1,
      -1,   334,    -1,    -1,    -1,    -1,    -1,    -1,   338,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    91,    -1,    -1,    94,    95,    96,    97,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,    -1,   392,
     393,    -1,   395,   396,    -1,   398,    -1,   397,    87,    88,
      89,    90,    91,    -1,    -1,    94,    95,    96,    97,    98,
     413,   414,   415,   416,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,   124,   125,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    12,    13,    14,
      15,    16,    17,    18,    -1,    20,    21,    -1,    -1,   149,
     150,   151,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    48,    23,    -1,    51,    26,    -1,    28,
      -1,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    61,    31,    32,    33,    34,    92,    93,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,
     105,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   242,    92,    93,    -1,    -1,    -1,   248,    -1,
      -1,    -1,    -1,   102,   103,   104,   105,   106,    -1,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,   268,    42,
      -1,   271,   272,    -1,    47,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   313,    87,    88,    89,    90,    91,    -1,
      -1,    94,    95,    96,    97,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     0,   366,   367,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    -1,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    -1,   100,   101,   102,   103,   104,
     105,   106,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    23,    -1,    -1,    26,    -1,    28,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    20,    21,    48,    23,    50,
      51,    26,    -1,    28,    55,    56,    57,    58,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    51,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    92,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   102,   103,   104,   105,   106,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    92,    93,    42,
      43,    44,    45,    46,    47,    -1,    -1,   102,   103,   104,
     105,   106,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    20,
      21,    -1,    23,    -1,    -1,    26,    -1,    28,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      -1,    94,    95,    96,    97,    98,    -1,    48,    -1,    50,
      51,    52,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      61,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    23,    -1,    -1,    26,    -1,    28,    -1,    -1,    -1,
      -1,    92,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   102,   103,   104,   105,   106,    48,    -1,    50,    51,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    61,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    20,    21,    -1,
      23,    -1,    -1,    26,    -1,    28,    -1,    -1,    -1,    -1,
      92,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     102,   103,   104,   105,   106,    48,    -1,    50,    51,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    61,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    20,    21,    -1,    23,
      -1,    -1,    26,    -1,    28,    -1,    -1,    -1,    -1,    92,
      93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     103,   104,   105,   106,    48,    -1,    -1,    51,    -1,    -1,
      -1,    55,    56,    57,    58,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    32,    33,    34,    35,    36,    53,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    92,    93,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,   102,   103,
     104,   105,   106,    -1,    -1,    -1,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    -1,    94,    95,    96,
      97,    98,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    -1,    94,    95,    96,    97,    98,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    32,    33,    34,    35,    36,    53,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    -1,
      94,    95,    96,    97,    98,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    -1,    94,    95,    96,    97,
      98,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    32,    33,    34,
      35,    36,    53,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    -1,    94,    95,    96,    97,    98,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    -1,    94,
      95,    96,    97,    98,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    -1,    94,    95,    96,    97,    98,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    31,    94,    -1,    96,    -1,    98,    37,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    -1,    94,    95,
      96,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    31,    -1,    -1,    -1,    -1,    -1,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    31,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    -1,    -1,    95,    -1,    97,
      42,    43,    44,    45,    46,    47,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    47,    32,    33,
      34,    35,    36,    85,    86,    87,    88,    89,    90,    91,
      -1,    -1,    94,    95,    96,    97,    98,    -1,    -1,    -1,
      86,    87,    88,    89,    90,    91,    -1,    -1,    94,    95,
      96,    97,    98,    -1,    -1,    -1,    -1,    87,    88,    89,
      90,    91,    -1,    -1,    94,    95,    96,    97,    98,    32,
      33,    34,    35,    36,    88,    89,    90,    91,    -1,    -1,
      94,    95,    96,    97,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    -1,
      -1,    94,    95,    96,    97,    98
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      23,    26,    28,    48,    50,    51,    55,    56,    57,    58,
      61,    92,    93,   102,   103,   104,   105,   106,   108,   109,
     110,   111,   112,   115,   120,   123,   124,   125,   129,   130,
     131,   132,   133,   136,   137,   138,   139,   140,   141,    31,
      31,    31,   109,   109,    18,   113,   114,    49,   109,   117,
      52,   109,    18,   130,   136,   130,   136,   130,   136,   130,
     136,    18,    18,    18,     0,    19,    22,    50,    54,   123,
      50,    54,   130,   136,    32,    33,    34,    35,    36,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    94,    95,
      96,    97,    98,    53,    95,    97,   134,    31,    37,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    80,    81,   134,    79,
      79,    79,   129,   129,   121,    24,    27,    30,    18,    29,
      27,    30,    54,   100,   101,    49,   129,    52,    31,   129,
     116,    18,    55,    50,   119,    18,   130,   136,   130,   136,
     130,   136,   130,   136,   130,   136,   130,   136,   130,   136,
     130,   136,   130,   136,   130,   136,   130,   136,   130,   136,
     130,   136,   130,   136,   130,   136,   130,   136,   130,   136,
     130,   136,   130,   136,   130,   136,   130,   136,   130,   136,
     130,   136,   130,   136,   130,   136,   130,   136,   130,   136,
     125,   130,   136,   130,   136,    19,    49,   109,   126,   127,
     128,    18,   135,   136,   138,   139,   140,   141,   135,    31,
      37,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    95,    97,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,    31,    37,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,   125,   136,   125,   125,
     129,   129,   129,   129,    29,   109,   129,   129,   114,   109,
     127,   129,   129,    31,   118,   129,   109,    49,    54,   127,
      49,    54,   128,   136,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   125,   129,   129,   135,   135,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   125,   129,   129,
      25,   109,    27,    30,   101,    27,    30,   100,   122,   129,
     109,   127,    49,   128,   129,   129,   129,   127,   129,   129,
     109,   129,    49,    27,    30,    27,    30,   129,   129,   129,
     129
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   107,   108,   108,   108,   108,   109,   109,   110,   110,
     111,   111,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   113,   113,   114,   114,   116,   115,   117,   115,
     118,   115,   119,   115,   120,   120,   121,   120,   120,   120,
     122,   120,   123,   123,   124,   124,   125,   125,   125,   125,
     125,   126,   126,   127,   127,   127,   128,   129,   129,   129,
     130,   130,   130,   130,   130,   131,   131,   132,   132,   132,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   134,   134,   134,
     134,   135,   135,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   138,   138,   138,   139,   140,   141,
     141,   141
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     3,     4,     6,
       4,     4,     4,     6,     6,     8,     8,     4,     6,     6,
       8,     8,     1,     3,     3,     4,     0,     4,     0,     3,
       0,     5,     0,     4,     1,     1,     0,     4,     3,     3,
       0,     6,     2,     3,     1,     3,     4,     4,     6,     5,
       3,     1,     3,     1,     3,     2,     2,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     3,
       3,     4,     4,     3,     4,     3,     4,     3,     4,     3,
       4,     3,     4,     3,     4,     3,     4,     3,     4,     3,
       4,     3,     4,     3,     4,     3,     4,     3,     4,     3,
       4,     3,     4,     3,     4,     3,     4,     3,     4,     3,
       4,     3,     4,     3,     3,     3,     4,     2,     2,     3,
       3,     1,     2,     1,     2,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const yytype_int8 yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     2,     0,     0,
       0,     0,     0,     0,     2,     1,     0,     0,     0,     0,
       0,     1,     2,     0,     0,     0,     0,     2,     1,     0,
       2,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
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
       0,     0
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
       0,     0
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    57,     0,    59,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,     0,     0,     0,     0,     0,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     3,     0,     0,
       0,     5,     0,     0,     0,     0,     0,     0,     7,     0,
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
       0,     0,     0,     0,     0,   113,     0,     0,   115,   117,
     119,   121,   123,   125,   127,   129,   131,   133,   135,   137,
     139,   141,   143,   145,   147,   149,   151,   153,   155,   157,
     159,   161,   163,   165,     0,   167,   169,   171,   173,   175,
     177,   179,   181,   183,   185,   187,   189,   191,   193,   195,
     197,   199,   201,   203,   205,   207,   209,   211,   213,   215,
     217,   219,   221,   223,     0,     0,   225,   227,   229,   231,
     233,   235,   237,   239,   241,   243,   245,   247,   249,   251,
     253,   255,   257,   259,   261,   263,   265,     0,   267,   269,
     271,   273,   275,   277,   279,   281,   283,   285,   287,   289,
     291,   293,   295,   297,     0,   299,   301,   303,   305,   307,
     309,   311,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     9,
      11,    13,    15,    17,    19,    21,    23,    25,    27,    29,
      31,    33,    35,    37,    39,     0,    41,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    45,     0,     0,    47,     0,     0,
       0,    49,    51,    53,    55,   313,   315,   317,   319,   321,
       0,   323,   325,   327,   329,   331,   333,   335,   337,   339,
     341,   371,   373,   375,   377,   379,     0,   381,   383,   385,
     387,   389,   391,   393,   395,   397,   399,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   343,   345,   347,   349,
     351,   353,   355,   357,   359,     0,     0,   361,   363,   365,
     367,   369,   401,   403,   405,   407,   409,   411,   413,   415,
     417,     0,     0,   419,   421,   423,   425,   427,   429,   431,
     433,   435,   437,     0,   439,   441,   443,   445,   447,   449,
     451,   453,   455,   457,   487,   489,   491,   493,   495,     0,
     497,   499,   501,   503,   505,   507,   509,   511,   513,   515,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   459,
     461,   463,   465,   467,   469,   471,   473,   475,     0,     0,
     477,   479,   481,   483,   485,   517,   519,   521,   523,   525,
     527,   529,   531,   533,     0,     0,   535,   537,   539,   541,
     543,   545,   547,   549,   551,   553,     0,   555,   557,   559,
     561,   563,   565,   567,   569,   571,   573,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   575,   577,   579,   581,   583,   585,   587,   589,
     591,     0,     0,   593,   595,   597,   599,   601,     0,     0,
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
       0,     0,     0,    61,     0,     0,     0,     0,     0,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    67,    69,    71,    73,    75,
      77,    79,    81,    83,    85,    87,    89,    91,    93,    95,
      97,     0,    99,   101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,     0,   105,
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
       0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,   239,     0,   239,     0,   239,     0,   239,     0,    58,
       0,    58,     0,    58,     0,    58,     0,    58,     0,    58,
       0,    58,     0,    58,     0,    58,     0,    58,     0,    58,
       0,    58,     0,    58,     0,    58,     0,    58,     0,    58,
       0,    58,     0,    58,     0,    58,     0,    58,     0,    58,
       0,    58,     0,    58,     0,    58,     0,   123,     0,   123,
       0,   232,     0,   232,     0,   232,     0,   232,     0,   232,
       0,   232,     0,   232,     0,   232,     0,   232,     0,   232,
       0,   232,     0,   232,     0,   232,     0,   232,     0,   232,
       0,   232,     0,   232,     0,   232,     0,   232,     0,   232,
       0,   232,     0,   232,     0,   232,     0,   234,     0,   236,
       0,   235,     0,    45,     0,    45,     0,    45,     0,    45,
       0,    45,     0,    45,     0,    45,     0,    45,     0,    45,
       0,    45,     0,    45,     0,    45,     0,    45,     0,    45,
       0,    45,     0,    45,     0,    45,     0,    45,     0,    45,
       0,    45,     0,    45,     0,    45,     0,    45,     0,    45,
       0,    45,     0,    45,     0,    45,     0,    45,     0,    45,
       0,    45,     0,    45,     0,    45,     0,    45,     0,    45,
       0,    45,     0,    45,     0,    45,     0,    45,     0,    45,
       0,    45,     0,    45,     0,    45,     0,    45,     0,    45,
       0,    45,     0,    45,     0,    45,     0,    45,     0,    45,
       0,    45,     0,    45,     0,    45,     0,    45,     0,    45,
       0,    45,     0,    45,     0,    45,     0,    45,     0,    45,
       0,    45,     0,    45,     0,    45,     0,    45,     0,    45,
       0,    45,     0,    45,     0,    45,     0,    45,     0,    45,
       0,    45,     0,    45,     0,    45,     0,    45,     0,    45,
       0,    45,     0,    45,     0,    45,     0,    45,     0,    45,
       0,    45,     0,    45,     0,    45,     0,    45,     0,    45,
       0,    45,     0,    45,     0,    45,     0,    45,     0,    45,
       0,    45,     0,    45,     0,    45,     0,    45,     0,    45,
       0,    45,     0,    45,     0,    45,     0,    45,     0,    45,
       0,    45,     0,   115,     0,   115,     0,   115,     0,   115,
       0,   115,     0,   115,     0,   115,     0,   115,     0,   115,
       0,   115,     0,   115,     0,   115,     0,   115,     0,   115,
       0,   115,     0,   115,     0,   115,     0,   115,     0,   115,
       0,   115,     0,   115,     0,   115,     0,   115,     0,   115,
       0,   115,     0,   115,     0,   115,     0,   115,     0,   115,
       0,   114,     0,   114,     0,   114,     0,   114,     0,   114,
       0,   114,     0,   114,     0,   114,     0,   114,     0,   114,
       0,   114,     0,   114,     0,   114,     0,   114,     0,   114,
       0,   114,     0,   114,     0,   114,     0,   114,     0,   114,
       0,   114,     0,   114,     0,   114,     0,   114,     0,   114,
       0,   114,     0,   114,     0,   114,     0,   114,     0,   113,
       0,   113,     0,   113,     0,   113,     0,   113,     0,   113,
       0,   113,     0,   113,     0,   113,     0,   113,     0,   113,
       0,   113,     0,   113,     0,   113,     0,   113,     0,   113,
       0,   113,     0,   113,     0,   113,     0,   113,     0,   113,
       0,   113,     0,   113,     0,   113,     0,   113,     0,   113,
       0,   113,     0,   113,     0,   113,     0,   211,     0,   211,
       0,   211,     0,   211,     0,   211,     0,   211,     0,   211,
       0,   211,     0,   211,     0,   211,     0,   211,     0,   211,
       0,   211,     0,   211,     0,   211,     0,   211,     0,   211,
       0,   211,     0,   211,     0,   211,     0,   211,     0,   211,
       0,   211,     0,   211,     0,   211,     0,   211,     0,   211,
       0,   211,     0,   211,     0,   116,     0,   116,     0,   116,
       0,   116,     0,   116,     0,   116,     0,   116,     0,   116,
       0,   116,     0,   116,     0,   116,     0,   116,     0,   116,
       0,   116,     0,   116,     0,   116,     0,   116,     0,   116,
       0,   116,     0,   116,     0,   116,     0,   116,     0,   116,
       0,   116,     0,   116,     0,   116,     0,   116,     0,   116,
       0,   116,     0
};




#undef yynerrs
#define yynerrs (yystackp->yyerrcnt)
#undef yychar
#define yychar (yystackp->yyrawchar)
#undef yylval
#define yylval (yystackp->yyval)
#undef yylloc
#define yylloc (yystackp->yyloc)
#define stringparser_nerrs yynerrs
#define stringparser_char yychar
#define stringparser_lval yylval
#define stringparser_lloc yylloc

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
  "NAMEDPARAM", "BIF", "OF", "SEQ", "IF_KW", "THEN_KW", "ELSE_KW",
  "WHILE_KW", "DO_KW", "FOR_KW", "IN_KW", "COLLECT_KW", "ASSIGN", "PLUS",
  "MINUS", "TIMES", "DIV", "DIVDIV", "APLUS", "LOGOR", "LOGAND",
  "LOGOREXT", "LOGANDEXT", "EQUAL", "LT", "GT", "LEQ", "GEQ", "NEQ",
  "OPEN", "CLOSEDROUND", "FUNDEF", "PUSH", "POP", "STARTPARAMS", "COMMA",
  "ELLIPSIS", "BACHNULL", "BACHNIL", "ARGCOUNT", "EOL", "UNRECOGNIZED",
  "LIFT", "AMINUS", "ATIMES", "APOWOP", "ADIV", "ADIVDIV", "AREM",
  "ABITAND", "ABITXOR", "ABITOR", "ALSHIFT", "ARSHIFT", "ALOGAND",
  "ALOGANDEXT", "ALOGXOR", "ALOGOR", "ALOGOREXT", "ANTHOP", "AAPPLY",
  "ACONCAT", "ARCONCAT", "CONCAT", "LOGXOR", "BITOR", "BITXOR", "BITAND",
  "REPEAT", "RANGE", "LSHIFT", "RSHIFT", "REM", "UPLUS", "UMINUS", "POWOP",
  "NTHOP", "PICKOP", "APPLY", "ACCESS_UNWRAP", "LVALUESTEPPARAMS", "AS_KW",
  "WITH_KW", "LOGNOT", "BITNOT", "KEEP", "UNKEEP", "INIT", "$accept",
  "program", "sequence", "ifThenElse", "whileloop", "forloop",
  "forargList", "forarg", "fundef", "$@1", "$@2", "$@3", "$@4",
  "funargList", "$@5", "$@6", "liftedargList", "functionApplication",
  "funcall", "argsByPositionList", "argsByNameList", "argByName", "list",
  "listEnd", "simpleList", "assignment", "assign", "lvalueStepList",
  "lvalueStepParams", "exp", "term", "var", "globalVar", "patcherVar",
  "localVar", YY_NULLPTR
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
<<<<<<< HEAD
  const yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
  int yylow = 1;
  YY_USE (yyvalp);
  YY_USE (scanner);
  YY_USE (params);
  YY_USE (yyk);
=======
  yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
  int yylow;
  YY_USE (yyvalp);
  YY_USE (scanner);
  YY_USE (params);
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
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
#line 211 "stringparser.y"
                {
    params->ast = new astConst(llll_get(), params->owner);
    *params->codeac = -1;
    code_dev_post ("parse: empty program\n");
}
<<<<<<< HEAD
#line 2171 "stringparser.tab.c"
=======
#line 2141 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 3: /* program: NAMEDPARAM  */
#line 216 "stringparser.y"
             {
    params->ast = new astConst(llll_get(), params->owner);
    *params->codeac = 0;
    code_dev_post ("parse: NAMEDPARAM: empty program\n");
    YYACCEPT;
}
<<<<<<< HEAD
#line 2182 "stringparser.tab.c"
=======
#line 2152 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 4: /* program: sequence  */
#line 222 "stringparser.y"
           {
    params->ast = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n);
    *params->codeac = -1;
    code_dev_post("codeac: %ld", *params->codeac);
    code_dev_post ("parse: sequence: program\n");
}
<<<<<<< HEAD
#line 2193 "stringparser.tab.c"
=======
#line 2163 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 5: /* program: sequence NAMEDPARAM  */
#line 228 "stringparser.y"
                      {
    params->ast = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.n);
    code_dev_post("codeac: %ld", *params->codeac);
    code_dev_post ("parse: sequence NAMEDPARAM: program\n");
    YYACCEPT;
}
<<<<<<< HEAD
#line 2204 "stringparser.tab.c"
=======
#line 2174 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 7: /* sequence: sequence SEQ list  */
#line 237 "stringparser.y"
                    {
    ((*yyvalp).n) = new astSequence((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: seq\n");
}
<<<<<<< HEAD
#line 2213 "stringparser.tab.c"
=======
#line 2183 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 8: /* ifThenElse: IF_KW sequence THEN_KW list  */
#line 243 "stringparser.y"
                                         {
    ((*yyvalp).n) = new astIfThenElse((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), nullptr, params->owner);
    code_dev_post ("parse: if then\n");
}
<<<<<<< HEAD
#line 2222 "stringparser.tab.c"
=======
#line 2192 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 9: /* ifThenElse: IF_KW sequence THEN_KW list ELSE_KW list  */
#line 247 "stringparser.y"
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
    
    ((*yyvalp).n) = new astIfThenElse((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: if then else\n");
}
<<<<<<< HEAD
#line 2248 "stringparser.tab.c"
=======
#line 2218 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 10: /* whileloop: WHILE_KW sequence DO_KW list  */
#line 269 "stringparser.y"
                                         {
    ((*yyvalp).n) = new astWhileLoop<E_LOOP_DO>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: while...do\n");
}
<<<<<<< HEAD
#line 2257 "stringparser.tab.c"
=======
#line 2227 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 11: /* whileloop: WHILE_KW sequence COLLECT_KW list  */
#line 273 "stringparser.y"
                                    {
    ((*yyvalp).n) = new astWhileLoop<E_LOOP_COLLECT>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: while...collect\n");
}
<<<<<<< HEAD
#line 2266 "stringparser.tab.c"
=======
#line 2236 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 12: /* forloop: FOR_KW forargList DO_KW list  */
#line 280 "stringparser.y"
{
    ((*yyvalp).n) = new astForLoop<E_LOOP_DO>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fal), nullptr, nullptr, nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: FOR_KW forargList DO_KW list\n");
}
<<<<<<< HEAD
#line 2275 "stringparser.tab.c"
=======
#line 2245 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 13: /* forloop: FOR_KW forargList WITH_KW argsByNameList DO_KW list  */
#line 285 "stringparser.y"
{
    ((*yyvalp).n) = new astForLoop<E_LOOP_DO>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.fal), nullptr, nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.snpl), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: forargList WITH_KW argsByNameList DO_KW list\n");
}
<<<<<<< HEAD
#line 2284 "stringparser.tab.c"
=======
#line 2254 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 14: /* forloop: FOR_KW forargList AS_KW sequence DO_KW list  */
#line 290 "stringparser.y"
{
    ((*yyvalp).n) = new astForLoop<E_LOOP_DO>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.fal), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: FOR_KW forargList AS_KW sequence DO_KW list\n");
}
<<<<<<< HEAD
#line 2293 "stringparser.tab.c"
=======
#line 2263 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 15: /* forloop: FOR_KW forargList AS_KW sequence WITH_KW argsByNameList DO_KW list  */
#line 295 "stringparser.y"
{
    ((*yyvalp).n) = new astForLoop<E_LOOP_DO>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.fal), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.snpl), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: forargList AS_KW sequence WITH_KW argsByNameList DO_KW list\n");
}
<<<<<<< HEAD
#line 2302 "stringparser.tab.c"
=======
#line 2272 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 16: /* forloop: FOR_KW forargList WITH_KW argsByNameList AS_KW sequence DO_KW list  */
#line 300 "stringparser.y"
{
    ((*yyvalp).n) = new astForLoop<E_LOOP_DO>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.fal), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.snpl), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: FOR_KW forargList WITH_KW argsByNameList AS_KW sequence DO_KW list\n");
}
<<<<<<< HEAD
#line 2311 "stringparser.tab.c"
=======
#line 2281 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 17: /* forloop: FOR_KW forargList COLLECT_KW list  */
#line 305 "stringparser.y"
{
    ((*yyvalp).n) = new astForLoop<E_LOOP_COLLECT>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fal), nullptr, nullptr, nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: FOR_KW forargList COLLECT_KW list\n");
}
<<<<<<< HEAD
#line 2320 "stringparser.tab.c"
=======
#line 2290 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 18: /* forloop: FOR_KW forargList WITH_KW argsByNameList COLLECT_KW list  */
#line 310 "stringparser.y"
{
    ((*yyvalp).n) = new astForLoop<E_LOOP_COLLECT>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.fal), nullptr, nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.snpl), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: forargList WITH_KW argsByNameList COLLECT_KW list\n");
}
<<<<<<< HEAD
#line 2329 "stringparser.tab.c"
=======
#line 2299 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 19: /* forloop: FOR_KW forargList AS_KW sequence COLLECT_KW list  */
#line 315 "stringparser.y"
{
    ((*yyvalp).n) = new astForLoop<E_LOOP_COLLECT>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.fal), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: FOR_KW forargList AS_KW sequence COLLECT_KW list\n");
}
<<<<<<< HEAD
#line 2338 "stringparser.tab.c"
=======
#line 2308 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 20: /* forloop: FOR_KW forargList AS_KW sequence WITH_KW argsByNameList COLLECT_KW list  */
#line 320 "stringparser.y"
{
    ((*yyvalp).n) = new astForLoop<E_LOOP_COLLECT>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.fal), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.snpl), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: forargList AS_KW sequence WITH_KW argsByNameList COLLECT_KW list\n");
}
<<<<<<< HEAD
#line 2347 "stringparser.tab.c"
=======
#line 2317 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 21: /* forloop: FOR_KW forargList WITH_KW argsByNameList AS_KW sequence COLLECT_KW list  */
#line 325 "stringparser.y"
{
    ((*yyvalp).n) = new astForLoop<E_LOOP_COLLECT>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.fal), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.snpl), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: FOR_KW forargList WITH_KW argsByNameList AS_KW sequence COLLECT_KW list\n");
}
<<<<<<< HEAD
#line 2356 "stringparser.tab.c"
=======
#line 2326 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 22: /* forargList: forarg  */
#line 331 "stringparser.y"
                    {
    ((*yyvalp).fal) = new countedList<forArg *>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.forarg));
    code_dev_post ("parse: for iterator (first term)\n");
}
<<<<<<< HEAD
#line 2365 "stringparser.tab.c"
=======
#line 2335 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 23: /* forargList: forargList COMMA forarg  */
#line 335 "stringparser.y"
                          {
    ((*yyvalp).fal) = new countedList<forArg *>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.forarg), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.fal));
    code_dev_post ("parse: for iterator (subsequent term)\n");
}
<<<<<<< HEAD
#line 2374 "stringparser.tab.c"
=======
#line 2344 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 24: /* forarg: LOCALVAR IN_KW sequence  */
#line 341 "stringparser.y"
                                 {
    ((*yyvalp).forarg) = new forArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.sym), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n));
    addVariableToScope(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.sym));
    code_dev_post ("parse: for iterator with index");
}
<<<<<<< HEAD
#line 2384 "stringparser.tab.c"
=======
#line 2354 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 25: /* forarg: LOCALVAR LOCALVAR IN_KW sequence  */
#line 346 "stringparser.y"
                                   {
    addVariableToScope(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.sym));
    addVariableToScope(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.sym));
    ((*yyvalp).forarg) = new forArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.sym), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.sym), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n));
    code_dev_post ("parse: for iterator with index and address");
}
<<<<<<< HEAD
#line 2395 "stringparser.tab.c"
=======
#line 2365 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 26: /* $@1: %empty  */
#line 354 "stringparser.y"
                           {
    params->fnDepth++;
    *++(params->liftedVariablesStack) = new std::unordered_set<t_symbol *>;
    *++(params->argumentsStack) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.funarglist);
}
<<<<<<< HEAD
#line 2405 "stringparser.tab.c"
=======
#line 2375 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 27: /* fundef: funargList FUNDEF $@1 list  */
#line 358 "stringparser.y"
       {
    t_function *fn = new t_userFunction(*(params->argumentsStack), *(params->localVariablesStack), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    ((*yyvalp).n) = new astConst(fn, params->owner);
    *(params->localVariablesStack--) = nullptr;
    --(params->fnDepth);
    delete *(params->localVariablesAuxMapStack);
    *(params->localVariablesAuxMapStack--) = nullptr;
    delete *(params->liftedVariablesStack);
    *(params->liftedVariablesStack--) = nullptr;
    --(params->argumentsStack);
    code_dev_post ("parse: user defined function funargList FUNDEF");
}
<<<<<<< HEAD
#line 2422 "stringparser.tab.c"
=======
#line 2392 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 28: /* $@2: %empty  */
#line 370 "stringparser.y"
         {
    ++(params->localVariablesStack);
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
    *++(params->liftedVariablesStack) = new std::unordered_set<t_symbol *>;
    params->fnDepth++;
    *++(params->argumentsStack) = nullptr;
}
<<<<<<< HEAD
#line 2434 "stringparser.tab.c"
=======
#line 2404 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 29: /* fundef: FUNDEF $@2 list  */
#line 376 "stringparser.y"
       {
    t_function *fn = new t_userFunction(*(params->argumentsStack), *(params->localVariablesStack), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    ((*yyvalp).n) = new astConst(fn, params->owner);
    *(params->localVariablesStack--) = nullptr;;
    --(params->fnDepth);
    delete *(params->localVariablesAuxMapStack);
    *(params->localVariablesAuxMapStack--) = nullptr;
    delete *(params->liftedVariablesStack);
    *(params->liftedVariablesStack--) = nullptr;
    --(params->argumentsStack);
    code_dev_post ("parse: user defined function FUNDEF");
}
<<<<<<< HEAD
#line 2451 "stringparser.tab.c"
=======
#line 2421 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 30: /* $@3: %empty  */
#line 388 "stringparser.y"
                                  {
    params->fnDepth++;
    *++(params->liftedVariablesStack) = new std::unordered_set<t_symbol *>;
    for (countedList<t_localVar> *v = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.liftedarglist)->getHead();
         v;
         v = v->getNext()) {
             (*(params->liftedVariablesStack))->insert(v->getItem().getName());
    }
    *++(params->argumentsStack) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.funarglist);
}
<<<<<<< HEAD
#line 2466 "stringparser.tab.c"
=======
#line 2436 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 31: /* fundef: funargList liftedargList FUNDEF $@3 list  */
#line 397 "stringparser.y"
       {
    t_function *fn = new t_userFunction(*(params->argumentsStack), *(params->localVariablesStack), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    ((*yyvalp).n) = new astConst(fn, params->owner);
    *(params->localVariablesStack--) = nullptr;
    --(params->fnDepth);
    delete *(params->localVariablesAuxMapStack);
    *(params->localVariablesAuxMapStack--) = nullptr;
    delete *(params->liftedVariablesStack);
    *(params->liftedVariablesStack--) = nullptr;
    --(params->argumentsStack);
    code_dev_post ("parse: user defined function funargList liftedargList");
}
<<<<<<< HEAD
#line 2483 "stringparser.tab.c"
=======
#line 2453 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 32: /* $@4: %empty  */
#line 409 "stringparser.y"
                       {
    params->fnDepth++;
    ++(params->localVariablesStack);
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
    *++(params->liftedVariablesStack) = new std::unordered_set<t_symbol *>;
    *++(params->argumentsStack) = nullptr;
    for (countedList<t_localVar> *v = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.liftedarglist)->getHead();
         v;
         v = v->getNext()) {
        (*(params->liftedVariablesStack))->insert(v->getItem().getName());
    }
}
<<<<<<< HEAD
#line 2500 "stringparser.tab.c"
=======
#line 2470 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 33: /* fundef: liftedargList FUNDEF $@4 list  */
#line 420 "stringparser.y"
       {
    t_function *fn = new t_userFunction(*++(params->argumentsStack), *(params->localVariablesStack), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    ((*yyvalp).n) = new astConst(fn, params->owner);
    *(params->localVariablesStack--) = nullptr;;
    --(params->fnDepth);
    delete *(params->localVariablesAuxMapStack);
    *(params->localVariablesAuxMapStack--) = nullptr;
    delete *(params->liftedVariablesStack);
    *(params->liftedVariablesStack--) = nullptr;
    --(params->argumentsStack);
    code_dev_post ("parse: user defined function liftedargList FUNDEF");
}
<<<<<<< HEAD
#line 2517 "stringparser.tab.c"
=======
#line 2487 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 34: /* funargList: LOCALVAR  */
#line 434 "stringparser.y"
                      {
    ++(params->localVariablesStack);
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
    ((*yyvalp).funarglist) = new countedList<funArg *>(new funArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym)));
    (**(params->localVariablesAuxMapStack))[(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym)] = 1;
    code_dev_post ("parse: funargList (first term, no default)\n");
}
<<<<<<< HEAD
#line 2529 "stringparser.tab.c"
=======
#line 2499 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 35: /* funargList: ELLIPSIS  */
#line 441 "stringparser.y"
           {
    ++(params->localVariablesStack);
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
    ((*yyvalp).funarglist) = new countedList<funArg *>(new funArg(gensym("<...>")));
    code_dev_post ("parse: ELLIPSIS");
}
<<<<<<< HEAD
#line 2540 "stringparser.tab.c"
=======
#line 2510 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 36: /* $@5: %empty  */
#line 447 "stringparser.y"
                  {
    // two levels are pushed:
    // one for the function, whose definition is beginning here,
    // and one for the parameter default, which is in an inner scope
    params->localVariablesStack += 2;
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
    (**(params->localVariablesAuxMapStack))[(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.sym)] = 1;
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
}
<<<<<<< HEAD
#line 2554 "stringparser.tab.c"
=======
#line 2524 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 37: /* funargList: LOCALVAR ASSIGN $@5 list  */
#line 455 "stringparser.y"
       {
    ((*yyvalp).funarglist) = new countedList<funArg *>(new funArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.sym), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), *(params->localVariablesStack)));
    delete *(params->localVariablesAuxMapStack);
    
    // this pops the parameter default level
    *(params->localVariablesAuxMapStack--) = nullptr;
    *(params->localVariablesStack--) = nullptr;
    code_dev_post ("parse: funargList (first term, with default)\n");
}
<<<<<<< HEAD
#line 2568 "stringparser.tab.c"
=======
#line 2538 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 38: /* funargList: funargList COMMA LOCALVAR  */
#line 464 "stringparser.y"
                            {
    ((*yyvalp).funarglist) = new countedList<funArg *>(new funArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.funarglist));
    (**(params->localVariablesAuxMapStack))[(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym)] = 1;
    code_dev_post ("parse: funargList (subsequent term, no default)\n");
}
<<<<<<< HEAD
#line 2578 "stringparser.tab.c"
=======
#line 2548 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 39: /* funargList: funargList COMMA ELLIPSIS  */
#line 469 "stringparser.y"
                            {
    ((*yyvalp).funarglist) = new countedList<funArg *>(new funArg(gensym("<...>")), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.funarglist));
    code_dev_post ("parse: funargList (subsequent term, no default)\n");
}
<<<<<<< HEAD
#line 2587 "stringparser.tab.c"
=======
#line 2557 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 40: /* $@6: %empty  */
#line 473 "stringparser.y"
                                   {
    (**(params->localVariablesAuxMapStack))[(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.sym)] = 1;
    ++(params->localVariablesStack);
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
}
<<<<<<< HEAD
#line 2597 "stringparser.tab.c"
=======
#line 2567 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 41: /* funargList: funargList COMMA LOCALVAR ASSIGN $@6 list  */
#line 477 "stringparser.y"
       {
    ((*yyvalp).funarglist) = new countedList<funArg *>(new funArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.sym), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), *(params->localVariablesStack)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.funarglist));
    delete *(params->localVariablesAuxMapStack);
    *(params->localVariablesAuxMapStack--) = nullptr;
    *(params->localVariablesStack--) = nullptr;
    code_dev_post ("parse: funargList (subsequent term, with default)\n");
}
<<<<<<< HEAD
#line 2609 "stringparser.tab.c"
=======
#line 2579 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 42: /* liftedargList: LIFT LOCALVAR  */
#line 486 "stringparser.y"
                              {
    ((*yyvalp).liftedarglist) = new countedList<t_localVar>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym));
    code_dev_post ("parse: liftedargList (first term)\n");
}
<<<<<<< HEAD
#line 2618 "stringparser.tab.c"
=======
#line 2588 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 43: /* liftedargList: liftedargList COMMA LOCALVAR  */
#line 490 "stringparser.y"
                               {
    ((*yyvalp).liftedarglist) = new countedList<t_localVar>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.liftedarglist));
    code_dev_post ("parse: liftedargList (subsequent term)\n");
}
<<<<<<< HEAD
#line 2627 "stringparser.tab.c"
=======
#line 2597 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 45: /* functionApplication: exp APPLY funcall  */
#line 498 "stringparser.y"
{
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.fc)->addOopStyleArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n));
    code_dev_post ("parse: term APPLY funcall");
    ((*yyvalp).fc) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.fc);
}
<<<<<<< HEAD
#line 2637 "stringparser.tab.c"
=======
#line 2607 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 46: /* funcall: term STARTPARAMS argsByPositionList CLOSEDROUND  */
#line 504 "stringparser.y"
                                                          {
    ((*yyvalp).fc) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.nl), nullptr, params->owner);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.nl);
    code_dev_post ("parse: function call with args by position");
}
<<<<<<< HEAD
#line 2647 "stringparser.tab.c"
=======
#line 2617 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 47: /* funcall: term STARTPARAMS argsByNameList CLOSEDROUND  */
#line 509 "stringparser.y"
                                              {
    ((*yyvalp).fc) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.n), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.snpl), params->owner);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.snpl);
    code_dev_post ("parse: function call with args by name");
}
<<<<<<< HEAD
#line 2657 "stringparser.tab.c"
=======
#line 2627 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 48: /* funcall: term STARTPARAMS argsByPositionList COMMA argsByNameList CLOSEDROUND  */
#line 514 "stringparser.y"
                                                                       {
    ((*yyvalp).fc) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.nl), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.snpl), params->owner);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.nl);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.snpl);
    code_dev_post ("parse: function call with args by position and by name");
}
<<<<<<< HEAD
#line 2668 "stringparser.tab.c"
=======
#line 2638 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 49: /* funcall: term STARTPARAMS argsByPositionList argsByNameList CLOSEDROUND  */
#line 520 "stringparser.y"
                                                                 {
    ((*yyvalp).fc) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.nl), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.snpl), params->owner);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.nl);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.snpl);
    code_dev_post ("parse: function call with args by position and by name");
}
<<<<<<< HEAD
#line 2679 "stringparser.tab.c"
=======
#line 2649 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 50: /* funcall: term STARTPARAMS CLOSEDROUND  */
#line 526 "stringparser.y"
                               {
    ((*yyvalp).fc) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), nullptr, nullptr, params->owner);
    code_dev_post ("parse: function call with no args");
}
<<<<<<< HEAD
#line 2688 "stringparser.tab.c"
=======
#line 2658 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 51: /* argsByPositionList: sequence  */
#line 532 "stringparser.y"
                              {
    ((*yyvalp).nl) = new countedList<astNode *>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n));
    code_dev_post ("parse: argsByPositionList (first term)\n");
}
<<<<<<< HEAD
#line 2697 "stringparser.tab.c"
=======
#line 2667 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 52: /* argsByPositionList: argsByPositionList COMMA sequence  */
#line 536 "stringparser.y"
                                    {
    ((*yyvalp).nl) = new countedList<astNode *>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.nl));
    code_dev_post ("parse: argsByPositionList (subsequent term)\n");
}
<<<<<<< HEAD
#line 2706 "stringparser.tab.c"
=======
#line 2676 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 53: /* argsByNameList: argByName  */
#line 542 "stringparser.y"
                           {
    ((*yyvalp).snpl) = new countedList<symNodePair *>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.snp));
    code_dev_post ("parse: argsByNameList (first term)\n");
}
<<<<<<< HEAD
#line 2715 "stringparser.tab.c"
=======
#line 2685 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 54: /* argsByNameList: argsByNameList COMMA argByName  */
#line 546 "stringparser.y"
                                 {
    ((*yyvalp).snpl) = new countedList<symNodePair *>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.snp), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.snpl));
    code_dev_post ("parse: argsByNameList (subsequent term)\n");
}
<<<<<<< HEAD
#line 2724 "stringparser.tab.c"
=======
#line 2694 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 55: /* argsByNameList: argsByNameList argByName  */
#line 550 "stringparser.y"
                           {
    ((*yyvalp).snpl) = new countedList<symNodePair *>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.snp), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.snpl));
    code_dev_post ("parse: argsByNameList (subsequent term)\n");
}
<<<<<<< HEAD
#line 2733 "stringparser.tab.c"
=======
#line 2703 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 56: /* argByName: NAMEDPARAM sequence  */
#line 556 "stringparser.y"
                                {
    ((*yyvalp).snp) = new symNodePair((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.sym), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n));
    code_dev_post ("parse: named parameter %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.sym)->s_name);
}
<<<<<<< HEAD
#line 2742 "stringparser.tab.c"
=======
#line 2712 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 59: /* list: simpleList listEnd  */
#line 563 "stringparser.y"
                                  {
    ((*yyvalp).n) = new astConcat((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: cat\n");
}
<<<<<<< HEAD
#line 2751 "stringparser.tab.c"
=======
#line 2721 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 66: /* simpleList: simpleList exp  */
#line 577 "stringparser.y"
                              {
    ((*yyvalp).n) = new astConcat((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: cat\n");
}
<<<<<<< HEAD
#line 2760 "stringparser.tab.c"
=======
#line 2730 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 68: /* assignment: OUTLET ASSIGN list  */
#line 584 "stringparser.y"
                     {
    if (params->dataOutlets && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.l) > *(params->dataOutlets))
        *(params->dataOutlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.l);
    auto fnConst = new astConst((*(params->bifs))["outlet"], params->owner);


    auto numConst = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.l), params->owner);
    auto tempList = new countedList<astNode *>(numConst);
    tempList = new countedList<astNode *>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), tempList);
    ((*yyvalp).n) = new astFunctionCall(fnConst, tempList, nullptr, params->owner);
    code_dev_post("parse: OUTLET ASSIGN list");
}
<<<<<<< HEAD
#line 2777 "stringparser.tab.c"
=======
#line 2747 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 69: /* assignment: DIROUTLET ASSIGN list  */
#line 596 "stringparser.y"
                        {
    if (params->directOutlets && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.l) > *(params->directOutlets))
        *(params->directOutlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.l);
    auto fnConst = new astConst((*(params->ofTable))["directout"], params->owner);
    auto tempList = new countedList<astNode *>(new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.l), params->owner));
    tempList = new countedList<astNode *>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), tempList);
    ((*yyvalp).n) = new astFunctionCall(fnConst, tempList, nullptr, params->owner);
    code_dev_post("parse: DIROUTLET ASSIGN list");
}
<<<<<<< HEAD
#line 2791 "stringparser.tab.c"
=======
#line 2761 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 70: /* assign: var ASSIGN list  */
#line 607 "stringparser.y"
                         {
    ((*yyvalp).n) = new astAssign((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: var ASSIGN list");
}
<<<<<<< HEAD
#line 2800 "stringparser.tab.c"
=======
#line 2770 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 71: /* assign: INIT LOCALVAR ASSIGN list  */
#line 611 "stringparser.y"
                            {
    addVariableToScope(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.sym));
    ((*yyvalp).n) = new astInit((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.sym), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: INIT LOCALVAR ASSIGN list");
}
<<<<<<< HEAD
#line 2810 "stringparser.tab.c"
=======
#line 2780 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 72: /* assign: var lvalueStepList ASSIGN list  */
#line 616 "stringparser.y"
                                 {
    ((*yyvalp).n) = new astRichAssignment<E_RA_STANDARD>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ASSIGN list");
}
<<<<<<< HEAD
#line 2819 "stringparser.tab.c"
=======
#line 2789 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 73: /* assign: var APLUS list  */
#line 620 "stringparser.y"
                 {
    ((*yyvalp).n) = new astOperatorAPlus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: var APLUS list");
}
<<<<<<< HEAD
#line 2828 "stringparser.tab.c"
=======
#line 2798 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 74: /* assign: var lvalueStepList APLUS list  */
#line 624 "stringparser.y"
                                {
    ((*yyvalp).n) = new astOperatorRAPlus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList APLUS list");
}
<<<<<<< HEAD
#line 2837 "stringparser.tab.c"
=======
#line 2807 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 75: /* assign: var AMINUS list  */
#line 628 "stringparser.y"
                  {
    ((*yyvalp).n) = new astOperatorAMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: var AMINUS list");
}
<<<<<<< HEAD
#line 2846 "stringparser.tab.c"
=======
#line 2816 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 76: /* assign: var lvalueStepList AMINUS list  */
#line 632 "stringparser.y"
                                 {
    ((*yyvalp).n) = new astOperatorRAMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList AMINUS list");
}
<<<<<<< HEAD
#line 2855 "stringparser.tab.c"
=======
#line 2825 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 77: /* assign: var ATIMES list  */
#line 636 "stringparser.y"
                  {
    ((*yyvalp).n) = new astOperatorATimes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: var ATIMES list");
}
<<<<<<< HEAD
#line 2864 "stringparser.tab.c"
=======
#line 2834 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 78: /* assign: var lvalueStepList ATIMES list  */
#line 640 "stringparser.y"
                                 {
    ((*yyvalp).n) = new astOperatorRATimes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ATIMES list");
}
<<<<<<< HEAD
#line 2873 "stringparser.tab.c"
=======
#line 2843 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 79: /* assign: var APOWOP list  */
#line 644 "stringparser.y"
                  {
    ((*yyvalp).n) = new astOperatorAPow((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: var APOWOP list");
}
<<<<<<< HEAD
#line 2882 "stringparser.tab.c"
=======
#line 2852 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 80: /* assign: var lvalueStepList APOWOP list  */
#line 648 "stringparser.y"
                                 {
    ((*yyvalp).n) = new astOperatorRAPow((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList APOWOP list");
}
<<<<<<< HEAD
#line 2891 "stringparser.tab.c"
=======
#line 2861 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 81: /* assign: var ADIV list  */
#line 652 "stringparser.y"
                {
    ((*yyvalp).n) = new astOperatorADiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: var ADIV list");
}
<<<<<<< HEAD
#line 2900 "stringparser.tab.c"
=======
#line 2870 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 82: /* assign: var lvalueStepList ADIV list  */
#line 656 "stringparser.y"
                               {
    ((*yyvalp).n) = new astOperatorRADiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ADIV list");
}
<<<<<<< HEAD
#line 2909 "stringparser.tab.c"
=======
#line 2879 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 83: /* assign: var ADIVDIV list  */
#line 660 "stringparser.y"
                   {
    ((*yyvalp).n) = new astOperatorADivdiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: var ADIVDIV list");
}
<<<<<<< HEAD
#line 2918 "stringparser.tab.c"
=======
#line 2888 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 84: /* assign: var lvalueStepList ADIVDIV list  */
#line 664 "stringparser.y"
                                  {
    ((*yyvalp).n) = new astOperatorRADivdiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ADIVDIV list");
}
<<<<<<< HEAD
#line 2927 "stringparser.tab.c"
=======
#line 2897 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 85: /* assign: var AREM list  */
#line 668 "stringparser.y"
                {
    ((*yyvalp).n) = new astOperatorARemainder((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: var AREM list");
}
<<<<<<< HEAD
#line 2936 "stringparser.tab.c"
=======
#line 2906 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 86: /* assign: var lvalueStepList AREM list  */
#line 672 "stringparser.y"
                               {
    ((*yyvalp).n) = new astOperatorRARemainder((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList AREM list");
}
<<<<<<< HEAD
#line 2945 "stringparser.tab.c"
=======
#line 2915 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 87: /* assign: var ABITAND list  */
#line 676 "stringparser.y"
                   {
    ((*yyvalp).n) = new astOperatorABitAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: var ABITAND list");
}
<<<<<<< HEAD
#line 2954 "stringparser.tab.c"
=======
#line 2924 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 88: /* assign: var lvalueStepList ABITAND list  */
#line 680 "stringparser.y"
                                  {
    ((*yyvalp).n) = new astOperatorRABitAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ABITAND list");
}
<<<<<<< HEAD
#line 2963 "stringparser.tab.c"
=======
#line 2933 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 89: /* assign: var ABITXOR list  */
#line 684 "stringparser.y"
                   {
    ((*yyvalp).n) = new astOperatorABitXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: var ABITXOR list");
}
<<<<<<< HEAD
#line 2972 "stringparser.tab.c"
=======
#line 2942 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 90: /* assign: var lvalueStepList ABITXOR list  */
#line 688 "stringparser.y"
                                  {
    ((*yyvalp).n) = new astOperatorRABitXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ABITXOR list");
}
<<<<<<< HEAD
#line 2981 "stringparser.tab.c"
=======
#line 2951 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 91: /* assign: var ABITOR list  */
#line 692 "stringparser.y"
                  {
    ((*yyvalp).n) = new astOperatorABitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: localVar ABITOR list");
}
<<<<<<< HEAD
#line 2990 "stringparser.tab.c"
=======
#line 2960 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 92: /* assign: var lvalueStepList ABITOR list  */
#line 696 "stringparser.y"
                                 {
    ((*yyvalp).n) = new astOperatorRABitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ABITOR list");
}
<<<<<<< HEAD
#line 2999 "stringparser.tab.c"
=======
#line 2969 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 93: /* assign: var ALSHIFT list  */
#line 700 "stringparser.y"
                   {
    ((*yyvalp).n) = new astOperatorALShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: var ALSHIFT list");
}
<<<<<<< HEAD
#line 3008 "stringparser.tab.c"
=======
#line 2978 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 94: /* assign: var lvalueStepList ALSHIFT list  */
#line 704 "stringparser.y"
                                  {
    ((*yyvalp).n) = new astOperatorRALShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ALSHIFT list");
}
<<<<<<< HEAD
#line 3017 "stringparser.tab.c"
=======
#line 2987 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 95: /* assign: var ARSHIFT list  */
#line 708 "stringparser.y"
                   {
    ((*yyvalp).n) = new astOperatorARShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: var ARSHIFT list");
}
<<<<<<< HEAD
#line 3026 "stringparser.tab.c"
=======
#line 2996 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 96: /* assign: var lvalueStepList ARSHIFT list  */
#line 712 "stringparser.y"
                                  {
    ((*yyvalp).n) = new astOperatorRARShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ARSHIFT list");
}
<<<<<<< HEAD
#line 3035 "stringparser.tab.c"
=======
#line 3005 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 97: /* assign: var ALOGAND list  */
#line 716 "stringparser.y"
                   {
    ((*yyvalp).n) = new astSCAAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: var ALOGAND list");
}
<<<<<<< HEAD
#line 3044 "stringparser.tab.c"
=======
#line 3014 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 98: /* assign: var lvalueStepList ALOGAND list  */
#line 720 "stringparser.y"
                                  {
    ((*yyvalp).n) = new astLogRASCAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ALOGAND list");
}
<<<<<<< HEAD
#line 3053 "stringparser.tab.c"
=======
#line 3023 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 99: /* assign: var ALOGANDEXT list  */
#line 724 "stringparser.y"
                      {
    ((*yyvalp).n) = new astSCAAndExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: var ALOGANDEXT list");
}
<<<<<<< HEAD
#line 3062 "stringparser.tab.c"
=======
#line 3032 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 100: /* assign: var lvalueStepList ALOGANDEXT list  */
#line 728 "stringparser.y"
                                     {
    ((*yyvalp).n) = new astSCRichAccessAndExt<astRichAssignment<E_RA_SHORTCIRCUIT>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ALOGANDEXT list");
}
<<<<<<< HEAD
#line 3071 "stringparser.tab.c"
=======
#line 3041 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 101: /* assign: var ALOGXOR list  */
#line 732 "stringparser.y"
                   {
    ((*yyvalp).n) = new astLogAXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: var ALOGXOR list");
}
<<<<<<< HEAD
#line 3080 "stringparser.tab.c"
=======
#line 3050 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 102: /* assign: var lvalueStepList ALOGXOR list  */
#line 736 "stringparser.y"
                                  {
    ((*yyvalp).n) = new astLogRAXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ALOGXOR list");
}
<<<<<<< HEAD
#line 3089 "stringparser.tab.c"
=======
#line 3059 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 103: /* assign: var ALOGOR list  */
#line 740 "stringparser.y"
                  {
    ((*yyvalp).n) = new astSCAOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: var ALOGOR list");
}
<<<<<<< HEAD
#line 3098 "stringparser.tab.c"
=======
#line 3068 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 104: /* assign: var lvalueStepList ALOGOR list  */
#line 744 "stringparser.y"
                                 {
    ((*yyvalp).n) = new astLogRASCOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ALOGOR list");
}
<<<<<<< HEAD
#line 3107 "stringparser.tab.c"
=======
#line 3077 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 105: /* assign: var ALOGOREXT list  */
#line 748 "stringparser.y"
                     {
    ((*yyvalp).n) = new astSCAOrExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: var ALOGOREXT list");
}
<<<<<<< HEAD
#line 3116 "stringparser.tab.c"
=======
#line 3086 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 106: /* assign: var lvalueStepList ALOGOREXT list  */
#line 752 "stringparser.y"
                                    {
    ((*yyvalp).n) = new astSCRichAccessOrExt<astRichAssignment<E_RA_SHORTCIRCUIT>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ALOGOREXT list");
}
<<<<<<< HEAD
#line 3125 "stringparser.tab.c"
=======
#line 3095 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 107: /* assign: var ANTHOP list  */
#line 756 "stringparser.y"
                  {
    ((*yyvalp).n) = new astNthAssignOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: var ANTHOP list op\n");
}
<<<<<<< HEAD
#line 3134 "stringparser.tab.c"
=======
#line 3104 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 108: /* assign: var lvalueStepList ANTHOP list  */
#line 760 "stringparser.y"
                                 {
    ((*yyvalp).n) = new astRichAccessNthOp<astRichAssignment<E_RA_STANDARD>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ANTHOP list");
}
<<<<<<< HEAD
#line 3143 "stringparser.tab.c"
=======
#line 3113 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 109: /* assign: var ACONCAT list  */
#line 764 "stringparser.y"
                   {
    ((*yyvalp).n) = new astConcatAssignOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: var ACONCAT list op\n");
}
<<<<<<< HEAD
#line 3152 "stringparser.tab.c"
=======
#line 3122 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 110: /* assign: var lvalueStepList ACONCAT list  */
#line 768 "stringparser.y"
                                  {
    ((*yyvalp).n) = new astRichAccessConcatOp<astRichAssignment<E_RA_STANDARD>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ACONCAT list");
}
<<<<<<< HEAD
#line 3161 "stringparser.tab.c"
=======
#line 3131 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 111: /* assign: var ARCONCAT list  */
#line 772 "stringparser.y"
                    {
    ((*yyvalp).n) = new astRevConcatAssignOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: var ARCONCAT list op\n");
}
<<<<<<< HEAD
#line 3170 "stringparser.tab.c"
=======
#line 3140 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 112: /* assign: var lvalueStepList ARCONCAT list  */
#line 776 "stringparser.y"
                                   {
    ((*yyvalp).n) = new astRichAccessRConcatOp<astRichAssignment<E_RA_STANDARD>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ARCONCAT list");
}
<<<<<<< HEAD
#line 3179 "stringparser.tab.c"
=======
#line 3149 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 113: /* assign: localVar AAPPLY funcall  */
#line 780 "stringparser.y"
                          {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.fc)->addOopStyleArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lv));
    ((*yyvalp).n) = new astAssign(new astLocalVar((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lv)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.fc), params->owner);
    code_dev_post ("parse: localVar AAPPLY funcall");
}
<<<<<<< HEAD
#line 3189 "stringparser.tab.c"
=======
#line 3159 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 114: /* assign: patcherVar AAPPLY funcall  */
#line 785 "stringparser.y"
                            {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.fc)->addOopStyleArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.pv));
    astPatcherVar *v = new astPatcherVar((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.pv));
    (*params->name2patcherVars)[v->getName()].insert(v);
    ((*yyvalp).n) = new astAssign(v, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.fc), params->owner);
    code_dev_post ("parse: patcherVar AAPPLY funcall");
}
<<<<<<< HEAD
#line 3201 "stringparser.tab.c"
=======
#line 3171 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 115: /* assign: globalVar AAPPLY funcall  */
#line 792 "stringparser.y"
                           {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.fc)->addOopStyleArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.gv));
    ((*yyvalp).n) = new astAssign(new astGlobalVar((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.gv)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.fc), params->owner);
    code_dev_post ("parse: globalVar AAPPLY funcall");
}
<<<<<<< HEAD
#line 3211 "stringparser.tab.c"
=======
#line 3181 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 116: /* assign: var lvalueStepList AAPPLY funcall  */
#line 797 "stringparser.y"
                                    {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.fc)->addOopStyleArg(new astConst(params->owner));
    ((*yyvalp).n) = new astRichAccessApplyOp<astRichAssignment<E_RA_SHORTCIRCUIT>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.fc), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList AAPPLY list");
}
<<<<<<< HEAD
#line 3221 "stringparser.tab.c"
=======
#line 3191 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 117: /* lvalueStepList: NTHOP lvalueStepParams  */
#line 805 "stringparser.y"
                                       {
    ((*yyvalp).lvsl) = new lvalueStepList(new lvalueStep(lvalueStep::E_LV_NTH, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n)));
    code_dev_post ("parse: lvalueStepList (NTH first term)");
}
<<<<<<< HEAD
#line 3230 "stringparser.tab.c"
=======
#line 3200 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 118: /* lvalueStepList: APPLY lvalueStepParams  */
#line 809 "stringparser.y"
                         {
    ((*yyvalp).lvsl) = new lvalueStepList(new lvalueStep(lvalueStep::E_LV_KEY, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n)));
    code_dev_post ("parse: lvalueStepList (KEY first term)");
}
<<<<<<< HEAD
#line 3239 "stringparser.tab.c"
=======
#line 3209 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 119: /* lvalueStepList: lvalueStepList NTHOP lvalueStepParams  */
#line 813 "stringparser.y"
                                        {
    ((*yyvalp).lvsl) = new lvalueStepList(new lvalueStep(lvalueStep::E_LV_NTH, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl));
    code_dev_post ("parse: lvalueStepList (NTH subsequent term)");
}
<<<<<<< HEAD
#line 3248 "stringparser.tab.c"
=======
#line 3218 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 120: /* lvalueStepList: lvalueStepList APPLY lvalueStepParams  */
#line 817 "stringparser.y"
                                        {
    ((*yyvalp).lvsl) = new lvalueStepList(new lvalueStep(lvalueStep::E_LV_KEY, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl));
    code_dev_post ("parse: lvalueStepList (KEY subsequent term)");
}
<<<<<<< HEAD
#line 3257 "stringparser.tab.c"
=======
#line 3227 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 122: /* lvalueStepParams: lvalueStepParams exp  */
#line 825 "stringparser.y"
                                              {
    ((*yyvalp).n) = new astConcat((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: cat\n");
}
<<<<<<< HEAD
#line 3266 "stringparser.tab.c"
=======
#line 3236 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 124: /* exp: UPLUS listEnd  */
#line 832 "stringparser.y"
<<<<<<< HEAD
                { ((*yyvalp).n) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n); }
#line 3272 "stringparser.tab.c"
=======
                { ((*yyvalp).n) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n); }
#line 3242 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 125: /* exp: UMINUS listEnd  */
#line 833 "stringparser.y"
                 {
    ((*yyvalp).n) = new astOperatorUMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: U-\n");
}
<<<<<<< HEAD
#line 3281 "stringparser.tab.c"
=======
#line 3251 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 126: /* exp: LOGNOT listEnd  */
#line 837 "stringparser.y"
                 {
    ((*yyvalp).n) = new astLogNot((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: !\n");
}
<<<<<<< HEAD
#line 3290 "stringparser.tab.c"
=======
#line 3260 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 127: /* exp: BITNOT listEnd  */
#line 841 "stringparser.y"
                 {
    ((*yyvalp).n) = new astOperatorBitNot((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: ~\n");
}
<<<<<<< HEAD
#line 3299 "stringparser.tab.c"
=======
#line 3269 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 128: /* exp: exp PLUS listEnd  */
#line 845 "stringparser.y"
                   {
    ((*yyvalp).n) = new astOperatorPlus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: +\n");
}
<<<<<<< HEAD
#line 3308 "stringparser.tab.c"
=======
#line 3278 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 129: /* exp: exp MINUS listEnd  */
#line 849 "stringparser.y"
                    {
    ((*yyvalp).n) = new astOperatorMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: -\n");
}
<<<<<<< HEAD
#line 3317 "stringparser.tab.c"
=======
#line 3287 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 130: /* exp: exp TIMES listEnd  */
#line 853 "stringparser.y"
                    {
    ((*yyvalp).n) = new astOperatorTimes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: *\n");
}
<<<<<<< HEAD
#line 3326 "stringparser.tab.c"
=======
#line 3296 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 131: /* exp: exp DIV listEnd  */
#line 857 "stringparser.y"
                  {
    ((*yyvalp).n) = new astOperatorDiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: /\n");
}
<<<<<<< HEAD
#line 3335 "stringparser.tab.c"
=======
#line 3305 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 132: /* exp: exp DIVDIV listEnd  */
#line 861 "stringparser.y"
                     {
    ((*yyvalp).n) = new astOperatorDivdiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: //\n");
}
<<<<<<< HEAD
#line 3344 "stringparser.tab.c"
=======
#line 3314 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 133: /* exp: exp REM listEnd  */
#line 865 "stringparser.y"
                  {
    ((*yyvalp).n) = new astOperatorRemainder((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: %\n");
}
<<<<<<< HEAD
#line 3353 "stringparser.tab.c"
=======
#line 3323 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 134: /* exp: exp POWOP listEnd  */
#line 869 "stringparser.y"
                    {
    ((*yyvalp).n) = new astOperatorPow((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: **\n");
}
<<<<<<< HEAD
#line 3362 "stringparser.tab.c"
=======
#line 3332 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 135: /* exp: exp BITAND listEnd  */
#line 873 "stringparser.y"
                     {
    ((*yyvalp).n) = new astOperatorBitAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: &\n");
}
<<<<<<< HEAD
#line 3371 "stringparser.tab.c"
=======
#line 3341 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 136: /* exp: exp BITXOR listEnd  */
#line 877 "stringparser.y"
                     {
    ((*yyvalp).n) = new astOperatorBitXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: ^\n");
}
<<<<<<< HEAD
#line 3380 "stringparser.tab.c"
=======
#line 3350 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 137: /* exp: exp BITOR listEnd  */
#line 881 "stringparser.y"
                    {
    ((*yyvalp).n) = new astOperatorBitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: |\n");
}
<<<<<<< HEAD
#line 3389 "stringparser.tab.c"
=======
#line 3359 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 138: /* exp: exp LSHIFT listEnd  */
#line 885 "stringparser.y"
                     {
    ((*yyvalp).n) = new astOperatorBitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: <<\n");
}
<<<<<<< HEAD
#line 3398 "stringparser.tab.c"
=======
#line 3368 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 139: /* exp: exp RSHIFT listEnd  */
#line 889 "stringparser.y"
                     {
    ((*yyvalp).n) = new astOperatorBitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: >>\n");
}
<<<<<<< HEAD
#line 3407 "stringparser.tab.c"
=======
#line 3377 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 140: /* exp: exp EQUAL listEnd  */
#line 893 "stringparser.y"
                    {
    ((*yyvalp).n) = new astComparatorEq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: ==\n");
}
<<<<<<< HEAD
#line 3416 "stringparser.tab.c"
=======
#line 3386 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 141: /* exp: exp NEQ listEnd  */
#line 897 "stringparser.y"
                  {
    ((*yyvalp).n) = new astComparatorNeq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: !=\n");
}
<<<<<<< HEAD
#line 3425 "stringparser.tab.c"
=======
#line 3395 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 142: /* exp: exp LT listEnd  */
#line 901 "stringparser.y"
                 {
    ((*yyvalp).n) = new astComparatorLt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: <\n");
}
<<<<<<< HEAD
#line 3434 "stringparser.tab.c"
=======
#line 3404 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 143: /* exp: exp GT listEnd  */
#line 905 "stringparser.y"
                 {
    ((*yyvalp).n) = new astComparatorGt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: <\n");
}
<<<<<<< HEAD
#line 3443 "stringparser.tab.c"
=======
#line 3413 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 144: /* exp: exp LEQ listEnd  */
#line 909 "stringparser.y"
                  {
    ((*yyvalp).n) = new astComparatorLeq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: <=\n");
}
<<<<<<< HEAD
#line 3452 "stringparser.tab.c"
=======
#line 3422 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 145: /* exp: exp GEQ listEnd  */
#line 913 "stringparser.y"
                  {
    ((*yyvalp).n) = new astComparatorGeq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: >=\n");
}
<<<<<<< HEAD
#line 3461 "stringparser.tab.c"
=======
#line 3431 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 146: /* exp: exp LOGOR listEnd  */
#line 917 "stringparser.y"
                    {
    ((*yyvalp).n) = new astSCOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: ||\n");
}
<<<<<<< HEAD
#line 3470 "stringparser.tab.c"
=======
#line 3440 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 147: /* exp: exp LOGAND listEnd  */
#line 921 "stringparser.y"
                     {
    ((*yyvalp).n) = new astSCAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: &&\n");
}
<<<<<<< HEAD
#line 3479 "stringparser.tab.c"
=======
#line 3449 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 148: /* exp: exp LOGXOR listEnd  */
#line 925 "stringparser.y"
                     {
    ((*yyvalp).n) = new astLogXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: &&\n");
}
<<<<<<< HEAD
#line 3488 "stringparser.tab.c"
=======
#line 3458 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 149: /* exp: exp LOGOREXT listEnd  */
#line 929 "stringparser.y"
                       {
    ((*yyvalp).n) = new astSCOrExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: |||\n");
}
<<<<<<< HEAD
#line 3497 "stringparser.tab.c"
=======
#line 3467 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 150: /* exp: exp LOGANDEXT listEnd  */
#line 933 "stringparser.y"
                        {
    ((*yyvalp).n) = new astSCAndExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: &&&\n");
}
<<<<<<< HEAD
#line 3506 "stringparser.tab.c"
=======
#line 3476 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 151: /* exp: exp NTHOP listEnd  */
#line 937 "stringparser.y"
                    {
    ((*yyvalp).n) = new astNthOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: nthop (exp NTHOP listEnd)\n");
}
<<<<<<< HEAD
#line 3515 "stringparser.tab.c"
=======
#line 3485 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 152: /* exp: exp PICKOP listEnd  */
#line 941 "stringparser.y"
                     {
    ((*yyvalp).n) = new astPickOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: nthop\n");
}
<<<<<<< HEAD
#line 3524 "stringparser.tab.c"
=======
#line 3494 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 153: /* exp: exp RANGE listEnd  */
#line 945 "stringparser.y"
                    {
    ((*yyvalp).n) = new astRangeOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: range\n");
}
<<<<<<< HEAD
#line 3533 "stringparser.tab.c"
=======
#line 3503 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 154: /* exp: exp REPEAT listEnd  */
#line 949 "stringparser.y"
                     {
    ((*yyvalp).n) = new astRepeatOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: range\n");
}
<<<<<<< HEAD
#line 3542 "stringparser.tab.c"
=======
#line 3512 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 155: /* exp: exp APPLY listEnd  */
#line 953 "stringparser.y"
                             {
    ((*yyvalp).n) = new astKeyOp<e_keyOpStandard>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: access\n");
}
<<<<<<< HEAD
#line 3551 "stringparser.tab.c"
=======
#line 3521 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 156: /* exp: exp ACCESS_UNWRAP listEnd  */
#line 957 "stringparser.y"
                            {
    ((*yyvalp).n) = new astKeyOp<e_keyOpUnwrapping>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: access\n");
}
<<<<<<< HEAD
#line 3560 "stringparser.tab.c"
=======
#line 3530 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 157: /* exp: UPLUS exp  */
#line 962 "stringparser.y"
<<<<<<< HEAD
            { ((*yyvalp).n) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n); }
#line 3566 "stringparser.tab.c"
=======
            { ((*yyvalp).n) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n); }
#line 3536 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 158: /* exp: UMINUS exp  */
#line 963 "stringparser.y"
             {
    ((*yyvalp).n) = new astOperatorUMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: U-\n");
}
<<<<<<< HEAD
#line 3575 "stringparser.tab.c"
=======
#line 3545 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 159: /* exp: LOGNOT exp  */
#line 967 "stringparser.y"
             {
    ((*yyvalp).n) = new astLogNot((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: !\n");
}
<<<<<<< HEAD
#line 3584 "stringparser.tab.c"
=======
#line 3554 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 160: /* exp: BITNOT exp  */
#line 971 "stringparser.y"
             {
    ((*yyvalp).n) = new astOperatorBitNot((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: ~\n");
}
<<<<<<< HEAD
#line 3593 "stringparser.tab.c"
=======
#line 3563 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 161: /* exp: exp PLUS exp  */
#line 975 "stringparser.y"
               {
    ((*yyvalp).n) = new astOperatorPlus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: +\n");
}
<<<<<<< HEAD
#line 3602 "stringparser.tab.c"
=======
#line 3572 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 162: /* exp: exp MINUS exp  */
#line 979 "stringparser.y"
                {
    ((*yyvalp).n) = new astOperatorMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: -\n");
}
<<<<<<< HEAD
#line 3611 "stringparser.tab.c"
=======
#line 3581 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 163: /* exp: exp TIMES exp  */
#line 983 "stringparser.y"
                {
    ((*yyvalp).n) = new astOperatorTimes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: *\n");
}
<<<<<<< HEAD
#line 3620 "stringparser.tab.c"
=======
#line 3590 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 164: /* exp: exp DIV exp  */
#line 987 "stringparser.y"
              {
    ((*yyvalp).n) = new astOperatorDiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: /\n");
}
<<<<<<< HEAD
#line 3629 "stringparser.tab.c"
=======
#line 3599 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 165: /* exp: exp DIVDIV exp  */
#line 991 "stringparser.y"
                 {
    ((*yyvalp).n) = new astOperatorDivdiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: //\n");
}
<<<<<<< HEAD
#line 3638 "stringparser.tab.c"
=======
#line 3608 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 166: /* exp: exp REM exp  */
#line 995 "stringparser.y"
              {
    ((*yyvalp).n) = new astOperatorRemainder((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: %\n");
}
<<<<<<< HEAD
#line 3647 "stringparser.tab.c"
=======
#line 3617 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 167: /* exp: exp POWOP exp  */
#line 999 "stringparser.y"
                {
    ((*yyvalp).n) = new astOperatorPow((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: **\n");
}
<<<<<<< HEAD
#line 3656 "stringparser.tab.c"
=======
#line 3626 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 168: /* exp: exp BITAND exp  */
#line 1003 "stringparser.y"
                 {
    ((*yyvalp).n) = new astOperatorBitAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: &\n");
}
<<<<<<< HEAD
#line 3665 "stringparser.tab.c"
=======
#line 3635 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 169: /* exp: exp BITXOR exp  */
#line 1007 "stringparser.y"
                 {
    ((*yyvalp).n) = new astOperatorBitXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: ^\n");
}
<<<<<<< HEAD
#line 3674 "stringparser.tab.c"
=======
#line 3644 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 170: /* exp: exp BITOR exp  */
#line 1011 "stringparser.y"
                {
    ((*yyvalp).n) = new astOperatorBitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: |\n");
}
<<<<<<< HEAD
#line 3683 "stringparser.tab.c"
=======
#line 3653 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 171: /* exp: exp LSHIFT exp  */
#line 1015 "stringparser.y"
                 {
    ((*yyvalp).n) = new astOperatorBitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: <<\n");
}
<<<<<<< HEAD
#line 3692 "stringparser.tab.c"
=======
#line 3662 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 172: /* exp: exp RSHIFT exp  */
#line 1019 "stringparser.y"
                 {
    ((*yyvalp).n) = new astOperatorBitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: >>\n");
}
<<<<<<< HEAD
#line 3701 "stringparser.tab.c"
=======
#line 3671 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 173: /* exp: exp EQUAL exp  */
#line 1023 "stringparser.y"
                {
    ((*yyvalp).n) = new astComparatorEq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: ==\n");
}
<<<<<<< HEAD
#line 3710 "stringparser.tab.c"
=======
#line 3680 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 174: /* exp: exp NEQ exp  */
#line 1027 "stringparser.y"
              {
    ((*yyvalp).n) = new astComparatorNeq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: !=\n");
}
<<<<<<< HEAD
#line 3719 "stringparser.tab.c"
=======
#line 3689 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 175: /* exp: exp LT exp  */
#line 1031 "stringparser.y"
             {
    ((*yyvalp).n) = new astComparatorLt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: <\n");
}
<<<<<<< HEAD
#line 3728 "stringparser.tab.c"
=======
#line 3698 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 176: /* exp: exp GT exp  */
#line 1035 "stringparser.y"
             {
    ((*yyvalp).n) = new astComparatorGt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: <\n");
}
<<<<<<< HEAD
#line 3737 "stringparser.tab.c"
=======
#line 3707 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 177: /* exp: exp LEQ exp  */
#line 1039 "stringparser.y"
              {
    ((*yyvalp).n) = new astComparatorLeq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: <=\n");
}
<<<<<<< HEAD
#line 3746 "stringparser.tab.c"
=======
#line 3716 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 178: /* exp: exp GEQ exp  */
#line 1043 "stringparser.y"
              {
    ((*yyvalp).n) = new astComparatorGeq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: >=\n");
}
<<<<<<< HEAD
#line 3755 "stringparser.tab.c"
=======
#line 3725 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 179: /* exp: exp LOGOR exp  */
#line 1047 "stringparser.y"
                {
    ((*yyvalp).n) = new astSCOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: ||\n");
}
<<<<<<< HEAD
#line 3764 "stringparser.tab.c"
=======
#line 3734 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 180: /* exp: exp LOGAND exp  */
#line 1051 "stringparser.y"
                 {
    ((*yyvalp).n) = new astSCAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: &&\n");
}
<<<<<<< HEAD
#line 3773 "stringparser.tab.c"
=======
#line 3743 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 181: /* exp: exp LOGXOR exp  */
#line 1055 "stringparser.y"
                 {
    ((*yyvalp).n) = new astLogXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: &&\n");
}
<<<<<<< HEAD
#line 3782 "stringparser.tab.c"
=======
#line 3752 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 182: /* exp: exp LOGOREXT exp  */
#line 1059 "stringparser.y"
                   {
    ((*yyvalp).n) = new astSCOrExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: |||\n");
}
<<<<<<< HEAD
#line 3791 "stringparser.tab.c"
=======
#line 3761 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 183: /* exp: exp LOGANDEXT exp  */
#line 1063 "stringparser.y"
                    {
    ((*yyvalp).n) = new astSCAndExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: &&&\n");
}
<<<<<<< HEAD
#line 3800 "stringparser.tab.c"
=======
#line 3770 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 184: /* exp: exp NTHOP exp  */
#line 1067 "stringparser.y"
                {
    ((*yyvalp).n) = new astNthOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: nthop (exp NTHOP exp)\n");
}
<<<<<<< HEAD
#line 3809 "stringparser.tab.c"
=======
#line 3779 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 185: /* exp: exp PICKOP exp  */
#line 1071 "stringparser.y"
                 {
    ((*yyvalp).n) = new astPickOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: nthop\n");
}
<<<<<<< HEAD
#line 3818 "stringparser.tab.c"
=======
#line 3788 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 186: /* exp: exp RANGE exp  */
#line 1075 "stringparser.y"
                {
    ((*yyvalp).n) = new astRangeOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: range\n");
}
<<<<<<< HEAD
#line 3827 "stringparser.tab.c"
=======
#line 3797 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 187: /* exp: exp REPEAT exp  */
#line 1079 "stringparser.y"
                 {
    ((*yyvalp).n) = new astRepeatOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: range\n");
}
<<<<<<< HEAD
#line 3836 "stringparser.tab.c"
=======
#line 3806 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 188: /* exp: exp APPLY exp  */
#line 1083 "stringparser.y"
                {
    ((*yyvalp).n) = new astKeyOp<e_keyOpStandard>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: access\n");
}
<<<<<<< HEAD
#line 3845 "stringparser.tab.c"
=======
#line 3815 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 189: /* exp: exp ACCESS_UNWRAP exp  */
#line 1087 "stringparser.y"
                        {
    ((*yyvalp).n) = new astKeyOp<e_keyOpUnwrapping>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post ("parse: access_unwrap\n");
}
<<<<<<< HEAD
#line 3854 "stringparser.tab.c"
=======
#line 3824 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 190: /* exp: term lvalueStepList ASSIGN list  */
#line 1092 "stringparser.y"
                                           {
    ((*yyvalp).n) = new astRichEdit<E_RA_STANDARD>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ASSIGN list");
}
<<<<<<< HEAD
#line 3863 "stringparser.tab.c"
=======
#line 3833 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 191: /* exp: term lvalueStepList APLUS list  */
#line 1096 "stringparser.y"
                                          {
    ((*yyvalp).n) = new astOperatorREPlus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList APLUS list");
}
<<<<<<< HEAD
#line 3872 "stringparser.tab.c"
=======
#line 3842 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 192: /* exp: term lvalueStepList AMINUS list  */
#line 1100 "stringparser.y"
                                           {
    ((*yyvalp).n) = new astOperatorREMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList AMINUS list");
}
<<<<<<< HEAD
#line 3881 "stringparser.tab.c"
=======
#line 3851 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 193: /* exp: term lvalueStepList ATIMES list  */
#line 1104 "stringparser.y"
                                           {
    ((*yyvalp).n) = new astOperatorRETimes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ATIMES list");
}
<<<<<<< HEAD
#line 3890 "stringparser.tab.c"
=======
#line 3860 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 194: /* exp: term lvalueStepList APOWOP list  */
#line 1108 "stringparser.y"
                                           {
    ((*yyvalp).n) = new astOperatorREPow((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList APOWOP list");
}
<<<<<<< HEAD
#line 3899 "stringparser.tab.c"
=======
#line 3869 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 195: /* exp: term lvalueStepList ADIV list  */
#line 1112 "stringparser.y"
                                         {
    ((*yyvalp).n) = new astOperatorREDiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ADIV list");
}
<<<<<<< HEAD
#line 3908 "stringparser.tab.c"
=======
#line 3878 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 196: /* exp: term lvalueStepList ADIVDIV list  */
#line 1116 "stringparser.y"
                                            {
    ((*yyvalp).n) = new astOperatorREDivdiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ADIVDIV list");
}
<<<<<<< HEAD
#line 3917 "stringparser.tab.c"
=======
#line 3887 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 197: /* exp: term lvalueStepList AREM list  */
#line 1120 "stringparser.y"
                                         {
    ((*yyvalp).n) = new astOperatorRERemainder((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList AREM list");
}
<<<<<<< HEAD
#line 3926 "stringparser.tab.c"
=======
#line 3896 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 198: /* exp: term lvalueStepList ABITAND list  */
#line 1124 "stringparser.y"
                                            {
    ((*yyvalp).n) = new astOperatorREBitAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ABITAND list");
}
<<<<<<< HEAD
#line 3935 "stringparser.tab.c"
=======
#line 3905 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 199: /* exp: term lvalueStepList ABITXOR list  */
#line 1128 "stringparser.y"
                                            {
    ((*yyvalp).n) = new astOperatorREBitXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ABITXOR list");
}
<<<<<<< HEAD
#line 3944 "stringparser.tab.c"
=======
#line 3914 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 200: /* exp: term lvalueStepList ABITOR list  */
#line 1132 "stringparser.y"
                                           {
    ((*yyvalp).n) = new astOperatorREBitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ABITOR list");
}
<<<<<<< HEAD
#line 3953 "stringparser.tab.c"
=======
#line 3923 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 201: /* exp: term lvalueStepList ALSHIFT list  */
#line 1136 "stringparser.y"
                                            {
    ((*yyvalp).n) = new astOperatorRELShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ALSHIFT list");
}
<<<<<<< HEAD
#line 3962 "stringparser.tab.c"
=======
#line 3932 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 202: /* exp: term lvalueStepList ARSHIFT list  */
#line 1140 "stringparser.y"
                                            {
    ((*yyvalp).n) = new astOperatorRERShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ARSHIFT list");
}
<<<<<<< HEAD
#line 3971 "stringparser.tab.c"
=======
#line 3941 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 203: /* exp: term lvalueStepList ALOGAND list  */
#line 1144 "stringparser.y"
                                            {
    ((*yyvalp).n) = new astLogRESCAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ALOGAND list");
}
<<<<<<< HEAD
#line 3980 "stringparser.tab.c"
=======
#line 3950 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 204: /* exp: term lvalueStepList ALOGANDEXT list  */
#line 1148 "stringparser.y"
                                               {
    ((*yyvalp).n) = new astSCRichAccessAndExt<astRichEdit<E_RA_SHORTCIRCUIT>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ALOGANDEXT list");
}
<<<<<<< HEAD
#line 3989 "stringparser.tab.c"
=======
#line 3959 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 205: /* exp: term lvalueStepList ALOGXOR list  */
#line 1152 "stringparser.y"
                                            {
    ((*yyvalp).n) = new astLogREXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ALOGXOR list");
}
<<<<<<< HEAD
#line 3998 "stringparser.tab.c"
=======
#line 3968 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 206: /* exp: term lvalueStepList ALOGOR list  */
#line 1156 "stringparser.y"
                                           {
    ((*yyvalp).n) = new astLogRESCOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ALOGOR list");
}
<<<<<<< HEAD
#line 4007 "stringparser.tab.c"
=======
#line 3977 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 207: /* exp: term lvalueStepList ALOGOREXT list  */
#line 1160 "stringparser.y"
                                              {
    ((*yyvalp).n) = new astSCRichAccessOrExt<astRichEdit<E_RA_SHORTCIRCUIT>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ALOGOREXT list");
}
<<<<<<< HEAD
#line 4016 "stringparser.tab.c"
=======
#line 3986 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 208: /* exp: term lvalueStepList ANTHOP list  */
#line 1164 "stringparser.y"
                                           {
    ((*yyvalp).n) = new astRichAccessNthOp<astRichEdit<E_RA_STANDARD>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ANTHOP list");
}
<<<<<<< HEAD
#line 4025 "stringparser.tab.c"
=======
#line 3995 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 209: /* exp: term lvalueStepList ACONCAT list  */
#line 1168 "stringparser.y"
                                            {
    ((*yyvalp).n) = new astRichAccessConcatOp<astRichEdit<E_RA_STANDARD>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ACONCAT list");
}
<<<<<<< HEAD
#line 4034 "stringparser.tab.c"
=======
#line 4004 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 210: /* exp: term lvalueStepList ARCONCAT list  */
#line 1172 "stringparser.y"
                                             {
    ((*yyvalp).n) = new astRichAccessRConcatOp<astRichEdit<E_RA_STANDARD>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ARCONCAT list");
}
<<<<<<< HEAD
#line 4043 "stringparser.tab.c"
=======
#line 4013 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 211: /* exp: term lvalueStepList AAPPLY funcall  */
#line 1176 "stringparser.y"
                                              {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.fc)->addOopStyleArg(new astConst(params->owner));
    ((*yyvalp).n) = new astRichAccessApplyOp<astRichEdit<E_RA_SHORTCIRCUIT>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.fc), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList AAPPLY list");
}
<<<<<<< HEAD
#line 4053 "stringparser.tab.c"
=======
#line 4023 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 212: /* term: LONG_LITERAL  */
#line 1183 "stringparser.y"
                   {
    ((*yyvalp).n) = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.l), params->owner);
    code_dev_post("parse: INT %ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.l));
}
<<<<<<< HEAD
#line 4062 "stringparser.tab.c"
=======
#line 4032 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 213: /* term: RAT_LITERAL  */
#line 1187 "stringparser.y"
              {
    ((*yyvalp).n) = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.r), params->owner);
    code_dev_post("parse: RAT_LITERAL %ld/%ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.r).num(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.r).den());
}
<<<<<<< HEAD
#line 4071 "stringparser.tab.c"
=======
#line 4041 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 214: /* term: DOUBLE_LITERAL  */
#line 1191 "stringparser.y"
                 {
    ((*yyvalp).n) = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.d), params->owner);
    code_dev_post("parse: DOUBLE_LITERAL %lf", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.d));
}
<<<<<<< HEAD
#line 4080 "stringparser.tab.c"
=======
#line 4050 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 215: /* term: PITCH_LITERAL  */
#line 1195 "stringparser.y"
                {
    ((*yyvalp).n) = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.p), params->owner);
    code_dev_post("parse: PITCH_LITERAL %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.p).toSym()->s_name);
}
<<<<<<< HEAD
#line 4089 "stringparser.tab.c"
=======
#line 4059 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 216: /* term: SYMBOL_LITERAL  */
#line 1199 "stringparser.y"
                 {
    ((*yyvalp).n) = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym), params->owner);
    code_dev_post("parse: SYMBOL_LITERAL %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym)->s_name);
}
<<<<<<< HEAD
#line 4098 "stringparser.tab.c"
=======
#line 4068 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 217: /* term: BACHNULL  */
#line 1203 "stringparser.y"
           {
    ((*yyvalp).n) = new astConst(llll_get(), params->owner);
    code_dev_post("parse: NULL");
}
<<<<<<< HEAD
#line 4107 "stringparser.tab.c"
=======
#line 4077 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 218: /* term: ARGCOUNT  */
#line 1207 "stringparser.y"
           {
    auto fnConst = new astConst((*(params->bifs))["$argcount"], params->owner);
    ((*yyvalp).n) = new astFunctionCall(fnConst, nullptr, nullptr, params->owner);
    code_dev_post("parse: ARGCOUNT");
}
<<<<<<< HEAD
#line 4117 "stringparser.tab.c"
=======
#line 4087 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 219: /* term: BACHNIL  */
#line 1212 "stringparser.y"
          {
    t_llll *ll = llll_get();
    llll_appendllll(ll, llll_get());
    ((*yyvalp).n) = new astConst(ll, params->owner);
    code_dev_post("parse: NIL");
}
<<<<<<< HEAD
#line 4128 "stringparser.tab.c"
=======
#line 4098 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 220: /* term: INLET  */
#line 1218 "stringparser.y"
        {
    if (params->dataInlets && params->fnDepth == 0 && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.l) > *(params->dataInlets))
        *(params->dataInlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.l);
    ((*yyvalp).n) = new astInlet((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.l), params->owner);
    code_dev_post ("parse: INLET %ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.l));
}
<<<<<<< HEAD
#line 4139 "stringparser.tab.c"
=======
#line 4109 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 221: /* term: INTINLET  */
#line 1224 "stringparser.y"
           {
    if (params->dataInlets && params->fnDepth == 0 && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.l) > *(params->dataInlets))
    *(params->dataInlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.l);
    ((*yyvalp).n) = new astConvInlet<hatom_fn_int>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.l), params->owner);
    code_dev_post ("parse: INTINLET %ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.l));
}
<<<<<<< HEAD
#line 4150 "stringparser.tab.c"
=======
#line 4120 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 222: /* term: RATINLET  */
#line 1230 "stringparser.y"
           {
    if (params->dataInlets && params->fnDepth == 0 && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.l) > *(params->dataInlets))
    *(params->dataInlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.l);
    ((*yyvalp).n) = new astConvInlet<hatom_fn_rat>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.l), params->owner);
    code_dev_post ("parse: RATINLET %ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.l));
}
<<<<<<< HEAD
#line 4161 "stringparser.tab.c"
=======
#line 4131 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 223: /* term: FLOATINLET  */
#line 1236 "stringparser.y"
             {
    if (params->dataInlets && params->fnDepth == 0 && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.l) > *(params->dataInlets))
    *(params->dataInlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.l);
    ((*yyvalp).n) = new astConvInlet<hatom_fn_float>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.l), params->owner);
    code_dev_post ("parse: FLOATINLET %ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.l));
}
<<<<<<< HEAD
#line 4172 "stringparser.tab.c"
=======
#line 4142 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 224: /* term: PITCHINLET  */
#line 1242 "stringparser.y"
             {
    if (params->dataInlets && params->fnDepth == 0 && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.l) > *(params->dataInlets))
    *(params->dataInlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.l);
    ((*yyvalp).n) = new astConvInlet<hatom_fn_pitch>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.l), params->owner);
    code_dev_post ("parse: PITCHINLET %ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.l));
}
<<<<<<< HEAD
#line 4183 "stringparser.tab.c"
=======
#line 4153 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 225: /* term: DIRINLET  */
#line 1248 "stringparser.y"
           {
    if (params->directInlets && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.l) > *(params->directInlets))
        *(params->directInlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.l);
    auto fnConst = new astConst((*(params->ofTable))["directin"], params->owner);
    auto numConst = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.l), params->owner);
    auto tempList = new countedList<astNode *>(numConst);
    ((*yyvalp).n) = new astFunctionCall(fnConst, tempList, nullptr, params->owner);
    code_dev_post("parse: DIRINLET");
}
<<<<<<< HEAD
#line 4197 "stringparser.tab.c"
=======
#line 4167 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 226: /* term: OPEN sequence CLOSEDROUND  */
#line 1257 "stringparser.y"
                            {
    ((*yyvalp).n) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.n);
    code_dev_post ("parse: []\n");
}
<<<<<<< HEAD
#line 4206 "stringparser.tab.c"
=======
#line 4176 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 227: /* term: OPEN CLOSEDROUND  */
#line 1261 "stringparser.y"
                   {
    ((*yyvalp).n) = new astConst(llll_get(), params->owner);
}
<<<<<<< HEAD
#line 4214 "stringparser.tab.c"
=======
#line 4184 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 228: /* term: PUSH sequence POP  */
#line 1264 "stringparser.y"
                    {
    ((*yyvalp).n) = new astWrap((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.n), params->owner);
    code_dev_post("parse: []\n");
}
<<<<<<< HEAD
#line 4223 "stringparser.tab.c"
=======
#line 4193 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 229: /* term: PUSH POP  */
#line 1268 "stringparser.y"
           {
    t_llll *ll = llll_get();
    llll_appendllll(ll, llll_get());
    ((*yyvalp).n) = new astConst(ll, params->owner);
    code_dev_post("parse: PushPop");
}
<<<<<<< HEAD
#line 4234 "stringparser.tab.c"
=======
#line 4204 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 230: /* term: BIF  */
#line 1274 "stringparser.y"
      {
    t_function *fn = (*(params->bifs))[(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym)->s_name];
    ((*yyvalp).n) = new astConst(fn, params->owner);
    code_dev_post("parse: bif %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym)->s_name);
}
<<<<<<< HEAD
#line 4244 "stringparser.tab.c"
=======
#line 4214 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 231: /* term: OF  */
#line 1279 "stringparser.y"
     {
    t_function *fn = (*(params->ofTable))[(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym)->s_name];
    ((*yyvalp).n) = new astConst(fn, params->owner);
    code_dev_post("parse: owned function %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym)->s_name);
}
<<<<<<< HEAD
#line 4254 "stringparser.tab.c"
=======
#line 4224 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 237: /* globalVar: GLOBALVAR  */
#line 1293 "stringparser.y"
                     {
    astGlobalVar *v = new astGlobalVar(params->gvt, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym), params->owner);
    params->globalVariables->insert(v->getVar());
    ((*yyvalp).gv) = v;
    code_dev_post ("parse: Global variable %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym)->s_name);
}
<<<<<<< HEAD
#line 4265 "stringparser.tab.c"
=======
#line 4235 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 238: /* patcherVar: PATCHERVAR  */
#line 1301 "stringparser.y"
                       {
    astPatcherVar *v = new astPatcherVar((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym), params->owner);
    (*params->name2patcherVars)[(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym)].insert(v);
    ((*yyvalp).pv) = v;
    code_dev_post ("parse: Patcher variable %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym)->s_name);
}
<<<<<<< HEAD
#line 4276 "stringparser.tab.c"
=======
#line 4246 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 239: /* localVar: LOCALVAR  */
#line 1309 "stringparser.y"
                   {
    ((*yyvalp).lv) = new astLocalVar((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym), params->owner);
    addVariableToScope(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym));
    code_dev_post ("parse: Local variable %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym)->s_name);
}
<<<<<<< HEAD
#line 4286 "stringparser.tab.c"
=======
#line 4256 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 240: /* localVar: KEEP LOCALVAR  */
#line 1314 "stringparser.y"
                {
    ((*yyvalp).lv) = new astKeep((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym), params->owner);
    addVariableToScope(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym));
    code_dev_post ("parse: Keep local variable %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym)->s_name);
}
<<<<<<< HEAD
#line 4296 "stringparser.tab.c"
=======
#line 4266 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8
    break;

  case 241: /* localVar: UNKEEP LOCALVAR  */
#line 1319 "stringparser.y"
                  {
    ((*yyvalp).lv) = new astUnkeep((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym), params->owner);
    addVariableToScope(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym));
    code_dev_post ("parse: Unkeep local variable %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.sym)->s_name);
}
<<<<<<< HEAD
#line 4306 "stringparser.tab.c"
    break;


#line 4310 "stringparser.tab.c"
=======
#line 4276 "stringparser.tab.c"
    break;


#line 4280 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8

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
#line 201 "stringparser.y"
{
    #ifdef YYDEBUG
    #if YYDEBUG == 1
    yydebug = 1;
    #endif
    #endif
}

<<<<<<< HEAD
#line 5717 "stringparser.tab.c"
=======
#line 5705 "stringparser.tab.c"
>>>>>>> 1525fb86dd4bad7aaab4fca1f8a7b5b9198880d8


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
#define yyparse stringparser_parse
#define yylex   stringparser_lex
#define yyerror stringparser_error
#define yylval  stringparser_lval
#define yychar  stringparser_char
#define yydebug stringparser_debug
#define yynerrs stringparser_nerrs


#line 1328 "stringparser.y"


t_mainFunction *codableobj_parse_buffer(t_codableobj *x, long *codeac, t_atom_long *dataInlets, t_atom_long *dataOutlets, t_atom_long *directInlets, t_atom_long *directOutlets)
{
    yyscan_t myscanner;
    
    t_lexparams lexparams;
    
    stringparser_lex_init_extra(&lexparams, &myscanner);
    stringparser_scan_string(myscanner, x->c_text);
    
    t_parseParams params;
    params.ast = NULL;
    params.fnDepth = 0;
    params.localVariablesStack = params.localVariablesStackBase;
    params.localVariablesAuxMapStack = params.localVariablesAuxMapStackBase;
    params.localVariablesAuxMapStack[0] = new std::unordered_map<t_symbol *, int>;
    params.liftedVariablesStack = params.liftedVariablesStackBase;
    params.argumentsStack = params.argumentsStackBase;
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
    
    code_dev_post("--- BUILDING AST!\n");
    stringparser_parse(myscanner, &params);
    
    for (int i = 0; i < 256; i++) {
        if (params.localVariablesAuxMapStack[i] == nullptr)
            break;
        delete params.localVariablesAuxMapStack[i];
    }
    
    stringparser_lex_destroy(myscanner);
    
    code_dev_post("first attribute at %ld", *params.codeac);
    
    if (params.ast) {
        t_mainFunction *mainFunction = new t_mainFunction(
            params.ast,
            params.localVariablesStackBase[0],
            params.globalVariables,
            params.name2patcherVars,
            x
        );
        codableobj_clear_included_filewatchers(x);
        codableobj_add_included_filewatchers(x, &lexparams.files);
        return mainFunction;
    } else {
        object_error((t_object *) x, "Syntax errors present — couldn't parse code");
        return nullptr;
    }
}


