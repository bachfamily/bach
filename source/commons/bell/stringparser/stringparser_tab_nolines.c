/* A Bison parser, made by GNU Bison 3.7.6.  */

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
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

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
  YYSYMBOL_MAXFUNCTION = 22,               /* MAXFUNCTION  */
  YYSYMBOL_SEQ = 23,                       /* SEQ  */
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
  YYSYMBOL_sequence = 110,                 /* sequence  */
  YYSYMBOL_ifThenElse = 111,               /* ifThenElse  */
  YYSYMBOL_whileloop = 112,                /* whileloop  */
  YYSYMBOL_forloop = 113,                  /* forloop  */
  YYSYMBOL_forargList = 114,               /* forargList  */
  YYSYMBOL_forarg = 115,                   /* forarg  */
  YYSYMBOL_fundef = 116,                   /* fundef  */
  YYSYMBOL_117_1 = 117,                    /* $@1  */
  YYSYMBOL_118_2 = 118,                    /* $@2  */
  YYSYMBOL_119_3 = 119,                    /* $@3  */
  YYSYMBOL_120_4 = 120,                    /* $@4  */
  YYSYMBOL_funargList = 121,               /* funargList  */
  YYSYMBOL_122_5 = 122,                    /* $@5  */
  YYSYMBOL_123_6 = 123,                    /* $@6  */
  YYSYMBOL_liftedargList = 124,            /* liftedargList  */
  YYSYMBOL_functionApplication = 125,      /* functionApplication  */
  YYSYMBOL_funcall = 126,                  /* funcall  */
  YYSYMBOL_argsByPositionList = 127,       /* argsByPositionList  */
  YYSYMBOL_argsByNameList = 128,           /* argsByNameList  */
  YYSYMBOL_argByName = 129,                /* argByName  */
  YYSYMBOL_list = 130,                     /* list  */
  YYSYMBOL_listEnd = 131,                  /* listEnd  */
  YYSYMBOL_simpleList = 132,               /* simpleList  */
  YYSYMBOL_assignment = 133,               /* assignment  */
  YYSYMBOL_assign = 134,                   /* assign  */
  YYSYMBOL_lvalueStepList = 135,           /* lvalueStepList  */
  YYSYMBOL_lvalueStepParams = 136,         /* lvalueStepParams  */
  YYSYMBOL_exp = 137,                      /* exp  */
  YYSYMBOL_term = 138,                     /* term  */
  YYSYMBOL_var = 139,                      /* var  */
  YYSYMBOL_globalVar = 140,                /* globalVar  */
  YYSYMBOL_patcherVar = 141,               /* patcherVar  */
  YYSYMBOL_localVar = 142                  /* localVar  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;

/* Second part of user prologue.  */

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
                && (__4 < __GNUC__ + (7 <= __GNUC_MINOR__) \
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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  85
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1771

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  242
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  422
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
       0,   213,   213,   218,   224,   230,   238,   239,   245,   249,
     271,   275,   281,   286,   291,   296,   301,   306,   311,   316,
     321,   326,   333,   337,   343,   348,   356,   356,   373,   373,
     392,   392,   414,   414,   440,   447,   453,   453,   470,   475,
     479,   479,   492,   496,   502,   503,   510,   515,   520,   526,
     532,   538,   542,   548,   552,   556,   562,   567,   568,   569,
     575,   576,   577,   578,   579,   582,   583,   589,   590,   602,
     613,   617,   622,   626,   630,   634,   638,   642,   646,   650,
     654,   658,   662,   666,   670,   674,   678,   682,   686,   690,
     694,   698,   702,   706,   710,   714,   718,   722,   726,   730,
     734,   738,   742,   746,   750,   754,   758,   762,   766,   770,
     774,   778,   782,   786,   791,   798,   803,   811,   815,   819,
     823,   830,   831,   837,   838,   839,   843,   847,   851,   855,
     859,   863,   867,   871,   875,   879,   883,   887,   891,   895,
     899,   903,   907,   911,   915,   919,   923,   927,   931,   935,
     939,   943,   947,   951,   955,   959,   963,   968,   969,   973,
     977,   981,   985,   989,   993,   997,  1001,  1005,  1009,  1013,
    1017,  1021,  1025,  1029,  1033,  1037,  1041,  1045,  1049,  1053,
    1057,  1061,  1065,  1069,  1073,  1077,  1081,  1085,  1089,  1093,
    1098,  1102,  1106,  1110,  1114,  1118,  1122,  1126,  1130,  1134,
    1138,  1142,  1146,  1150,  1154,  1158,  1162,  1166,  1170,  1174,
    1178,  1182,  1189,  1193,  1197,  1201,  1205,  1209,  1213,  1218,
    1224,  1230,  1236,  1242,  1248,  1254,  1263,  1267,  1270,  1274,
    1280,  1285,  1290,  1296,  1297,  1300,  1301,  1302,  1305,  1313,
    1321,  1326,  1331
};
#endif

#define YYPACT_NINF (-153)
#define YYTABLE_NINF (-45)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     770,  -153,  -153,  -153,  -153,  -153,  -153,   -12,  -153,    13,
    -153,  -153,  -153,  -153,  -153,  -153,   116,  -153,  -153,  -153,
    -153,  1010,  1010,    11,   830,  -153,   890,  -153,  -153,  -153,
    -153,    36,  1010,  1010,  1010,  1010,    43,    51,    62,    34,
      76,  -153,  -153,  -153,  -153,    16,   117,  -153,  -153,  -153,
    -153,  1070,  -153,  -153,  1279,   -46,  1568,    -6,    21,    50,
    1010,  1010,  -153,   -13,    45,    -9,    -4,  -153,  -153,    10,
    1010,  -153,     2,  -153,  -153,    30,  -153,    30,  -153,  -153,
    -153,  -153,  -153,  -153,    64,  -153,  -153,  1010,  -153,    -3,
     126,  -153,    82,  -153,  1279,  1010,  1010,  1010,  1010,  1010,
    1010,  1010,  1010,  1010,  1010,  1010,  1010,  1010,  1010,  1010,
    1010,  1010,  1010,  1010,  1010,  1010,  1010,  1010,  1010,  1010,
    1010,  1010,  1010,  1010,   450,   424,   424,  1424,  1010,  1010,
    1010,  1010,  1010,  1010,  1010,  1010,  1010,  1010,  1010,  1010,
    1010,  1010,  1010,  1010,  1010,  1010,  1010,  1010,  1010,  1475,
     424,   424,   424,  -153,  -153,  1010,  1010,  1010,  1010,    72,
    1010,  1010,  1010,    11,  1010,   123,  -153,  -153,  -153,  1010,
    -153,  1010,   104,  -153,  -153,  1010,  -153,  -153,   259,  -153,
     259,  -153,    30,  -153,    30,  -153,    30,  -153,  1295,  -153,
    1531,  -153,  1295,  -153,  1531,  -153,   290,  -153,   526,  -153,
     526,  -153,   526,  -153,   526,  -153,   290,  -153,  1378,  -153,
    1624,  -153,  1640,  -153,  1656,  -153,  1491,  -153,  1672,  -153,
     122,  -153,   122,  -153,    30,  -153,    30,  -153,  -153,  -153,
    -153,   665,  -153,  -153,  -153,  -153,  1010,  -153,   121,     9,
      20,  -153,  -153,   424,  1362,  -153,  -153,  -153,  -153,   424,
    1010,  1010,  1010,  1010,  1010,  1010,  1010,  1010,  1010,  1010,
    1010,  1010,  1010,  1010,  1010,  1010,  1010,  1010,  1010,   424,
    1010,  1010,   424,   424,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,  1010,  1010,  1010,  1010,  1010,
    1010,  1010,  1010,  1010,  1010,  1010,  1010,  1010,  1010,  1010,
    1010,  1010,  1010,  1010,   424,  1010,  1010,  1097,  1279,  1113,
    1180,  -153,   124,  -153,  -153,  1010,   121,  -153,  -153,  -153,
     -17,   -15,  -153,  -153,  -153,  1010,  -153,   121,  -153,   950,
      22,  -153,   123,  -153,  1362,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,  1196,  -153,  -153,   424,   424,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  1263,  -153,
    -153,  1010,   121,  1010,  1010,   123,  1010,  1010,  1010,  1010,
    -153,   121,    39,  -153,  -153,  -153,  -153,  -153,     7,  -153,
    -153,    56,  -153,  -153,  1010,  1010,  1010,  1010,  -153,  -153,
    -153,  -153
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,   212,   220,   221,   222,   223,   224,     0,   225,     0,
     213,   214,   215,   216,   238,   239,   240,     3,   230,   231,
     232,     0,     0,     0,     0,    28,     0,    35,   217,   219,
     218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,    63,    61,    62,    64,     0,     0,   234,    44,     6,
      57,    58,    60,    67,    65,   123,   233,   235,   237,   236,
       0,     0,    36,     0,     0,     0,     0,    22,   227,     0,
       0,   229,     0,    42,   124,   157,   125,   158,   126,   159,
     127,   160,   241,   242,     0,     1,     5,     0,    26,     0,
       0,    32,     0,    59,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    68,    69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   226,    29,   228,     0,
       7,     0,    38,    39,    30,     0,    43,   128,   161,   129,
     162,   130,   163,   131,   164,   132,   165,   146,   179,   147,
     180,   149,   182,   150,   183,   140,   173,   142,   175,   143,
     176,   144,   177,   145,   178,   141,   174,   148,   181,   137,
     170,   136,   169,   135,   168,   154,   187,   153,   186,   138,
     171,   139,   172,   133,   166,   134,   167,   151,   184,   152,
     185,    44,   155,   188,   156,   189,     0,    50,    51,     0,
       0,    53,   240,   117,   121,   233,   235,   237,   236,   118,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,    73,    75,    77,    79,    81,
      83,    85,    87,    89,    91,    93,    95,    97,    99,   101,
     103,   105,   107,   109,   111,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   115,     0,   114,
     113,    37,     8,    10,    11,     0,    24,    12,    17,    23,
       0,     0,    71,    27,    40,     0,    33,    56,    46,     0,
       0,    47,     0,    55,   122,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   211,   209,   210,   119,   120,    72,
      74,    76,    78,    80,    82,    84,    86,    88,    90,    92,
      94,    96,    98,   100,   102,   104,   106,   108,   116,   110,
     112,     0,    25,     0,     0,     0,     0,     0,     0,     0,
      31,    52,     0,    49,    54,     9,    14,    19,     0,    13,
      18,     0,    41,    48,     0,     0,     0,     0,    15,    20,
      16,    21
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,   -21,  -153,  -153,  -153,  -153,   -11,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,   115,  -153,  -120,  -153,
    -146,  -152,   -24,   481,  -153,  -153,  -153,   106,  -119,   299,
    -153,  -108,  -103,   -69,   -60
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    39,    40,    41,    42,    43,    66,    67,    44,   171,
      70,   335,   175,    45,   155,   399,    46,    47,    48,   239,
     240,   241,    49,    50,    51,    52,    53,   127,   243,    54,
      55,    56,    57,    58,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,    64,   231,    69,   236,    72,    87,   249,   124,   159,
      87,   393,   156,   396,   394,   172,   397,   245,   245,   331,
      60,   160,   246,   246,   161,    87,   236,   162,   236,    65,
     317,   319,   320,    87,    85,   414,   153,   154,   415,   236,
     342,   236,   245,   245,   245,    61,   167,   246,   246,   246,
     125,   163,   126,   173,    73,   168,   247,   247,   236,   338,
     166,    82,   342,   170,   339,   248,   248,    88,    87,    83,
     341,    89,   403,   157,   150,   342,   158,   342,    31,    87,
      84,   247,   247,   247,   416,   395,   398,   417,   343,   413,
     248,   248,   248,   340,   342,    86,   169,   164,   165,    87,
     176,   151,   325,   238,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   119,   120,   121,   122,   123,
     152,   321,   322,   323,   324,   245,   334,   327,   328,   326,
     246,   245,   236,   330,    87,   332,   246,   333,    62,   364,
     391,   336,   329,   367,   368,    95,    96,    97,    98,    99,
      90,   245,   149,     0,   245,   245,   246,   -34,    91,   246,
     246,   -34,    92,     0,   247,     0,     0,   174,   -34,   343,
     247,    92,     0,   248,     0,     0,     0,     0,   343,   248,
     404,     0,     0,   402,   388,     0,     0,     0,     0,     0,
     247,     0,     0,   247,   247,     0,   245,     0,     0,   248,
       0,   246,   248,   248,   118,   337,     0,   119,   120,   121,
     122,   123,     0,     0,     0,     0,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   247,   365,   366,     0,   408,
     343,     0,     0,     0,   248,     0,   343,     0,     0,   245,
     245,     0,     0,     0,   246,   246,     0,     0,     0,     0,
       0,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
       0,   389,   390,     0,    97,    98,    99,     0,   247,   247,
       0,     0,     0,     0,   392,     0,     0,   248,   248,     0,
       0,   400,     0,     0,     0,     0,     0,     0,   401,     0,
       0,     0,     0,    95,    96,    97,    98,    99,     0,     0,
       0,    75,    77,    79,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,   118,     0,     0,   119,   120,   121,   122,   123,     0,
       0,     0,     0,     0,     0,     0,     0,   405,     0,   406,
     407,     0,   409,   410,     0,   412,     0,   411,   114,   115,
     116,   117,   118,     0,     0,   119,   120,   121,   122,   123,
     418,   419,   420,   421,   178,   180,   182,   184,   186,   188,
     190,   192,   194,   196,   198,   200,   202,   204,   206,   208,
     210,   212,   214,   216,   218,   220,   222,   224,   226,   228,
     230,   233,   235,     0,   244,   244,     0,     1,     2,     3,
       4,     5,     6,     0,     8,     0,    10,    11,    12,    13,
      14,    15,   242,     0,    18,    19,    20,     0,     0,   318,
     318,   318,     0,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,   236,
      18,    19,    20,    24,    21,     0,    26,    22,     0,    23,
       0,    28,    29,    30,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
     237,    25,    26,     0,     0,     0,    27,    28,    29,    30,
       0,     0,    31,    74,    76,    78,    80,    32,    33,     0,
       0,     0,     0,     0,     0,     0,     0,    34,    35,    36,
      37,     0,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   344,    32,    33,     0,     0,     0,   344,     0,
       0,     0,     0,    34,    35,    36,    37,    38,     0,    95,
      96,    97,    98,    99,     0,     0,     0,     0,   318,   104,
       0,   244,   244,     0,   109,     0,   177,   179,   181,   183,
     185,   187,   189,   191,   193,   195,   197,   199,   201,   203,
     205,   207,   209,   211,   213,   215,   217,   219,   221,   223,
     225,   227,   229,   232,   234,     0,     0,     0,     0,     0,
       0,     0,     0,   318,   114,   115,   116,   117,   118,     0,
       0,   119,   120,   121,   122,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -44,   344,   344,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,     0,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,     0,     0,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,     0,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,     0,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,    21,     0,     0,    22,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
       0,    25,    26,     0,     0,     0,    27,    28,    29,    30,
       0,     0,    31,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     0,
      18,    19,    20,     0,    21,     0,     0,    22,     0,    23,
       0,     0,     0,    32,    33,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    35,    36,    37,    38,     0,    24,
      68,    25,    26,     0,     0,     0,    27,    28,    29,    30,
       0,     0,    31,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     0,
      18,    19,    20,     0,    21,     0,     0,    22,     0,    23,
       0,     0,     0,    32,    33,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    35,    36,    37,    38,     0,    24,
       0,    25,    26,    71,     0,     0,    27,    28,    29,    30,
       0,     0,    31,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,   236,
      18,    19,    20,     0,    21,     0,     0,    22,     0,    23,
       0,     0,     0,    32,    33,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    35,    36,    37,    38,     0,    24,
       0,    25,    26,     0,     0,     0,    27,    28,    29,    30,
       0,     0,    31,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     0,
      18,    19,    20,     0,    21,     0,     0,    22,     0,    23,
       0,     0,     0,    32,    33,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    35,    36,    37,    38,     0,    24,
       0,    25,    26,     0,     0,     0,    27,    28,    29,    30,
       0,     0,    31,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     0,
      18,    19,    20,     0,    21,     0,     0,    22,     0,    23,
       0,     0,     0,    32,    33,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    35,    36,    37,    38,     0,    24,
       0,     0,    26,     0,     0,     0,    27,    28,    29,    30,
     -44,   -44,   -44,   -44,   -44,     0,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,     0,    32,    33,     0,     0,   -44,     0,     0,
       0,     0,     0,    34,    35,    36,    37,    38,     0,     0,
       0,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
       0,     0,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,     0,     0,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,     0,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,     0,     0,     0,     0,     0,
     -44,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,     0,     0,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,     0,
       0,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,     0,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,    95,    96,    97,    98,    99,   -44,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    95,    96,
      97,    98,    99,     0,     0,   101,     0,   103,   104,   105,
     106,   107,   108,   109,     0,     0,     0,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,     0,     0,   -44,   -44,
     -44,   -44,   -44,   110,   111,   112,   113,   114,   115,   116,
     117,   118,     0,     0,   119,   120,   121,   122,   123,   110,
     111,   112,   113,   114,   115,   116,   117,   118,     0,     0,
     119,   120,   121,   122,   123,    95,    96,    97,    98,    99,
       0,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,    95,    96,    97,    98,    99,     0,     0,   101,     0,
     103,   104,   105,   106,   107,   108,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   250,   119,     0,   121,
       0,   123,   251,   111,   112,   113,   114,   115,   116,   117,
     118,     0,     0,   119,   120,   121,   122,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   295,     0,     0,
       0,     0,     0,   296,     0,     0,     0,     0,     0,     0,
     272,     0,   273,     0,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,     0,    95,    96,    97,    98,    99,     0,
       0,   272,     0,   273,   104,   105,   106,   107,   108,   109,
     115,   116,   117,   118,     0,     0,   119,   120,   121,   122,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,     0,     0,     0,     0,     0,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   111,   112,   113,   114,
     115,   116,   117,   118,     0,     0,   119,   120,   121,   122,
     123,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,   147,
     148,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,     0,     0,   125,     0,   126,   104,   105,   106,
     107,   108,   109,    95,    96,    97,    98,    99,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,    95,
      96,    97,    98,    99,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,    95,    96,    97,    98,    99,
     112,   113,   114,   115,   116,   117,   118,     0,     0,   119,
     120,   121,   122,   123,     0,     0,     0,   113,   114,   115,
     116,   117,   118,     0,     0,   119,   120,   121,   122,   123,
       0,     0,     0,     0,   114,   115,   116,   117,   118,     0,
       0,   119,   120,   121,   122,   123,     0,     0,     0,     0,
       0,     0,   116,   117,   118,     0,     0,   119,   120,   121,
     122,   123
};

static const yytype_int16 yycheck[] =
{
      21,    22,   122,    24,    19,    26,    23,   126,    54,    18,
      23,    28,    25,    28,    31,    18,    31,   125,   126,   165,
      32,    30,   125,   126,    28,    23,    19,    31,    19,    18,
     150,   151,   152,    23,     0,    28,    60,    61,    31,    19,
      55,    19,   150,   151,   152,    32,    70,   150,   151,   152,
      96,    55,    98,    56,    18,    53,   125,   126,    19,    50,
      50,    18,    55,    87,    55,   125,   126,    51,    23,    18,
      50,    55,    50,    28,    80,    55,    31,    55,    62,    23,
      18,   150,   151,   152,    28,   102,   101,    31,   240,    50,
     150,   151,   152,   239,    55,    19,    32,   101,   102,    23,
      18,    80,    30,   124,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,    95,    96,    97,    98,    99,
      80,   155,   156,   157,   158,   243,    32,   161,   162,   160,
     243,   249,    19,   164,    23,   169,   249,   171,    32,   269,
      26,   175,   163,   272,   273,    33,    34,    35,    36,    37,
      45,   269,    56,    -1,   272,   273,   269,    51,    51,   272,
     273,    55,    55,    -1,   243,    -1,    -1,    51,    62,   331,
     249,    55,    -1,   243,    -1,    -1,    -1,    -1,   340,   249,
     342,    -1,    -1,   339,   314,    -1,    -1,    -1,    -1,    -1,
     269,    -1,    -1,   272,   273,    -1,   314,    -1,    -1,   269,
      -1,   314,   272,   273,    92,   236,    -1,    95,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   314,   270,   271,    -1,   395,
     402,    -1,    -1,    -1,   314,    -1,   408,    -1,    -1,   367,
     368,    -1,    -1,    -1,   367,   368,    -1,    -1,    -1,    -1,
      -1,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
      -1,   315,   316,    -1,    35,    36,    37,    -1,   367,   368,
      -1,    -1,    -1,    -1,   325,    -1,    -1,   367,   368,    -1,
      -1,   335,    -1,    -1,    -1,    -1,    -1,    -1,   339,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    92,    -1,    -1,    95,    96,    97,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   391,    -1,   393,
     394,    -1,   396,   397,    -1,   399,    -1,   398,    88,    89,
      90,    91,    92,    -1,    -1,    95,    96,    97,    98,    99,
     414,   415,   416,   417,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    -1,   125,   126,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    12,    13,    14,    15,
      16,    17,    18,    -1,    20,    21,    22,    -1,    -1,   150,
     151,   152,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    49,    24,    -1,    52,    27,    -1,    29,
      -1,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    -1,    62,    32,    33,    34,    35,    93,    94,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,
     106,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,    93,    94,    -1,    -1,    -1,   249,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,    -1,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,   269,    43,
      -1,   272,   273,    -1,    48,    -1,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   314,    88,    89,    90,    91,    92,    -1,
      -1,    95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     0,   367,   368,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,    -1,   101,   102,   103,   104,
     105,   106,   107,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    -1,    27,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    51,    52,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    -1,    62,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      20,    21,    22,    -1,    24,    -1,    -1,    27,    -1,    29,
      -1,    -1,    -1,    93,    94,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,    -1,    49,
      50,    51,    52,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    -1,    62,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      20,    21,    22,    -1,    24,    -1,    -1,    27,    -1,    29,
      -1,    -1,    -1,    93,    94,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,    -1,    49,
      -1,    51,    52,    53,    -1,    -1,    56,    57,    58,    59,
      -1,    -1,    62,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    -1,    27,    -1,    29,
      -1,    -1,    -1,    93,    94,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,    -1,    49,
      -1,    51,    52,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    -1,    62,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      20,    21,    22,    -1,    24,    -1,    -1,    27,    -1,    29,
      -1,    -1,    -1,    93,    94,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,    -1,    49,
      -1,    51,    52,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    -1,    62,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      20,    21,    22,    -1,    24,    -1,    -1,    27,    -1,    29,
      -1,    -1,    -1,    93,    94,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,    -1,    49,
      -1,    -1,    52,    -1,    -1,    -1,    56,    57,    58,    59,
      33,    34,    35,    36,    37,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    33,    34,    35,    36,
      37,    54,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    93,    94,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    -1,    95,    96,    97,    98,    99,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    -1,    95,    96,
      97,    98,    99,    33,    34,    35,    36,    37,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    33,
      34,    35,    36,    37,    54,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    -1,    95,    96,    97,    98,    99,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      -1,    95,    96,    97,    98,    99,    33,    34,    35,    36,
      37,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    33,    34,    35,    36,    37,    54,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    33,    34,
      35,    36,    37,    -1,    -1,    40,    -1,    42,    43,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    -1,    95,    96,
      97,    98,    99,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    95,    96,    97,    98,    99,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    -1,
      95,    96,    97,    98,    99,    33,    34,    35,    36,    37,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    33,    34,    35,    36,    37,    -1,    -1,    40,    -1,
      42,    43,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    32,    95,    -1,    97,
      -1,    99,    38,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    -1,    95,    96,    97,    98,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    32,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    -1,    98,    -1,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    -1,
      -1,    96,    -1,    98,    43,    44,    45,    46,    47,    48,
      89,    90,    91,    92,    -1,    -1,    95,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    -1,    95,    96,    97,    98,
      99,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    -1,    -1,    96,    -1,    98,    43,    44,    45,
      46,    47,    48,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    48,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    33,    34,    35,    36,    37,
      86,    87,    88,    89,    90,    91,    92,    -1,    -1,    95,
      96,    97,    98,    99,    -1,    -1,    -1,    87,    88,    89,
      90,    91,    92,    -1,    -1,    95,    96,    97,    98,    99,
      -1,    -1,    -1,    -1,    88,    89,    90,    91,    92,    -1,
      -1,    95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    91,    92,    -1,    -1,    95,    96,    97,
      98,    99
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    24,    27,    29,    49,    51,    52,    56,    57,    58,
      59,    62,    93,    94,   103,   104,   105,   106,   107,   109,
     110,   111,   112,   113,   116,   121,   124,   125,   126,   130,
     131,   132,   133,   134,   137,   138,   139,   140,   141,   142,
      32,    32,    32,   110,   110,    18,   114,   115,    50,   110,
     118,    53,   110,    18,   131,   137,   131,   137,   131,   137,
     131,   137,    18,    18,    18,     0,    19,    23,    51,    55,
     124,    51,    55,   131,   137,    33,    34,    35,    36,    37,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    95,
      96,    97,    98,    99,    54,    96,    98,   135,    32,    38,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    81,    82,   135,
      80,    80,    80,   130,   130,   122,    25,    28,    31,    18,
      30,    28,    31,    55,   101,   102,    50,   130,    53,    32,
     130,   117,    18,    56,    51,   120,    18,   131,   137,   131,
     137,   131,   137,   131,   137,   131,   137,   131,   137,   131,
     137,   131,   137,   131,   137,   131,   137,   131,   137,   131,
     137,   131,   137,   131,   137,   131,   137,   131,   137,   131,
     137,   131,   137,   131,   137,   131,   137,   131,   137,   131,
     137,   131,   137,   131,   137,   131,   137,   131,   137,   131,
     137,   126,   131,   137,   131,   137,    19,    50,   110,   127,
     128,   129,    18,   136,   137,   139,   140,   141,   142,   136,
      32,    38,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    96,    98,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,    32,    38,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,   126,   137,   126,
     126,   130,   130,   130,   130,    30,   110,   130,   130,   115,
     110,   128,   130,   130,    32,   119,   130,   110,    50,    55,
     128,    50,    55,   129,   137,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   126,   130,   130,   136,   136,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   126,   130,
     130,    26,   110,    28,    31,   102,    28,    31,   101,   123,
     130,   110,   128,    50,   129,   130,   130,   130,   128,   130,
     130,   110,   130,    50,    28,    31,    28,    31,   130,   130,
     130,   130
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   109,   109,   110,   110,   111,   111,
     112,   112,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   114,   114,   115,   115,   117,   116,   118,   116,
     119,   116,   120,   116,   121,   121,   122,   121,   121,   121,
     123,   121,   124,   124,   125,   125,   126,   126,   126,   126,
     126,   127,   127,   128,   128,   128,   129,   130,   130,   130,
     131,   131,   131,   131,   131,   132,   132,   133,   133,   133,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   135,   135,   135,
     135,   136,   136,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   139,   139,   139,   140,   141,
     142,   142,   142
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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
       1,     2,     2
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
       0,     0,     0
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
       0,     0,     0
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
       0,     0,     0
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
      59,     0,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,   115,     0,     0,   117,   119,
     121,   123,   125,   127,   129,   131,   133,   135,   137,   139,
     141,   143,   145,   147,   149,   151,   153,   155,   157,   159,
     161,   163,   165,   167,   169,     0,   171,   173,   175,   177,
     179,   181,   183,   185,   187,   189,   191,   193,   195,   197,
     199,   201,   203,   205,   207,   209,   211,   213,   215,   217,
     219,   221,   223,   225,   227,     0,     0,   229,   231,   233,
     235,   237,   239,   241,   243,   245,   247,   249,   251,   253,
     255,   257,   259,   261,   263,   265,   267,   269,     0,   271,
     273,   275,   277,   279,   281,   283,   285,   287,   289,   291,
     293,   295,   297,   299,   301,     0,   303,   305,   307,   309,
     311,   313,   315,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     9,    11,    13,    15,    17,    19,    21,
      23,    25,    27,    29,    31,    33,    35,    37,    39,     0,
      41,    43,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       0,     0,    49,     0,     0,     0,    51,    53,    55,    57,
     317,   319,   321,   323,   325,     0,   327,   329,   331,   333,
     335,   337,   339,   341,   343,   345,   375,   377,   379,   381,
     383,     0,   385,   387,   389,   391,   393,   395,   397,   399,
     401,   403,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   347,   349,   351,   353,   355,   357,   359,   361,   363,
       0,     0,   365,   367,   369,   371,   373,   405,   407,   409,
     411,   413,   415,   417,   419,   421,     0,     0,   423,   425,
     427,   429,   431,   433,   435,   437,   439,   441,     0,   443,
     445,   447,   449,   451,   453,   455,   457,   459,   461,   491,
     493,   495,   497,   499,     0,   501,   503,   505,   507,   509,
     511,   513,   515,   517,   519,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   463,   465,   467,   469,   471,   473,
     475,   477,   479,     0,     0,   481,   483,   485,   487,   489,
     521,   523,   525,   527,   529,   531,   533,   535,   537,     0,
       0,   539,   541,   543,   545,   547,   549,   551,   553,   555,
     557,     0,   559,   561,   563,   565,   567,   569,   571,   573,
     575,   577,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   579,   581,   583,
     585,   587,   589,   591,   593,   595,     0,     0,   597,   599,
     601,   603,   605,     0,     0,     0,     0,     0,     0,     0,
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
      63,     0,     0,     0,     0,     0,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,    69,    71,    73,    75,    77,    79,    81,    83,
      85,    87,    89,    91,    93,    95,    97,    99,     0,   101,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   105,     0,   107,     0,     0,     0,
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

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,   240,     0,   240,     0,   240,     0,   240,     0,    58,
       0,    58,     0,    58,     0,    58,     0,    58,     0,    58,
       0,    58,     0,    58,     0,    58,     0,    58,     0,    58,
       0,    58,     0,    58,     0,    58,     0,    58,     0,    58,
       0,    58,     0,    58,     0,    58,     0,    58,     0,    58,
       0,    58,     0,    58,     0,    58,     0,    58,     0,   123,
       0,   123,     0,   233,     0,   233,     0,   233,     0,   233,
       0,   233,     0,   233,     0,   233,     0,   233,     0,   233,
       0,   233,     0,   233,     0,   233,     0,   233,     0,   233,
       0,   233,     0,   233,     0,   233,     0,   233,     0,   233,
       0,   233,     0,   233,     0,   233,     0,   233,     0,   235,
       0,   237,     0,   236,     0,    45,     0,    45,     0,    45,
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
       0,    45,     0,    45,     0,    45,     0,   115,     0,   115,
       0,   115,     0,   115,     0,   115,     0,   115,     0,   115,
       0,   115,     0,   115,     0,   115,     0,   115,     0,   115,
       0,   115,     0,   115,     0,   115,     0,   115,     0,   115,
       0,   115,     0,   115,     0,   115,     0,   115,     0,   115,
       0,   115,     0,   115,     0,   115,     0,   115,     0,   115,
       0,   115,     0,   115,     0,   114,     0,   114,     0,   114,
       0,   114,     0,   114,     0,   114,     0,   114,     0,   114,
       0,   114,     0,   114,     0,   114,     0,   114,     0,   114,
       0,   114,     0,   114,     0,   114,     0,   114,     0,   114,
       0,   114,     0,   114,     0,   114,     0,   114,     0,   114,
       0,   114,     0,   114,     0,   114,     0,   114,     0,   114,
       0,   114,     0,   113,     0,   113,     0,   113,     0,   113,
       0,   113,     0,   113,     0,   113,     0,   113,     0,   113,
       0,   113,     0,   113,     0,   113,     0,   113,     0,   113,
       0,   113,     0,   113,     0,   113,     0,   113,     0,   113,
       0,   113,     0,   113,     0,   113,     0,   113,     0,   113,
       0,   113,     0,   113,     0,   113,     0,   113,     0,   113,
       0,   211,     0,   211,     0,   211,     0,   211,     0,   211,
       0,   211,     0,   211,     0,   211,     0,   211,     0,   211,
       0,   211,     0,   211,     0,   211,     0,   211,     0,   211,
       0,   211,     0,   211,     0,   211,     0,   211,     0,   211,
       0,   211,     0,   211,     0,   211,     0,   211,     0,   211,
       0,   211,     0,   211,     0,   211,     0,   211,     0,   116,
       0,   116,     0,   116,     0,   116,     0,   116,     0,   116,
       0,   116,     0,   116,     0,   116,     0,   116,     0,   116,
       0,   116,     0,   116,     0,   116,     0,   116,     0,   116,
       0,   116,     0,   116,     0,   116,     0,   116,     0,   116,
       0,   116,     0,   116,     0,   116,     0,   116,     0,   116,
       0,   116,     0,   116,     0,   116,     0
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

typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;

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

struct yyGLRState {
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yysval applies, otherwise
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
    YYSTYPE yysval;
  } yysemantics;
};

struct yyGLRStateSet {
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  YYPTRDIFF_T yysize;
  YYPTRDIFF_T yycapacity;
};

struct yySemanticOption {
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
  "NAMEDPARAM", "BIF", "OF", "MAXFUNCTION", "SEQ", "IF_KW", "THEN_KW",
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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif



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
        yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
      else
        /* The effect of using yysval or yyloc (in an immediate rule) is
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
 *  yyerr for YYERROR, yyabort for YYABORT.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp,
              YYSTYPE* yyvalp, void *scanner, struct _parseParams *params)
{
  yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
  int yylow;
  YY_USE (yyvalp);
  YY_USE (scanner);
  YY_USE (params);
  YY_USE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
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

  yylow = 1;
  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
  switch (yyn)
    {
  case 2: /* program: %empty  */
                {
    params->ast = new astConst(llll_get(), params->owner);
    *params->codeac = -1;
    code_dev_post ("parse: empty program\n");
}
    break;

  case 3: /* program: NAMEDPARAM  */
             {
    params->ast = new astConst(llll_get(), params->owner);
    *params->codeac = 0;
    code_dev_post ("parse: NAMEDPARAM: empty program\n");
    YYACCEPT;
}
    break;

  case 4: /* program: sequence  */
           {
    params->ast = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n);
    *params->codeac = -1;
    code_dev_post("codeac: %ld", *params->codeac);
    code_dev_post ("parse: sequence: program\n");
}
    break;

  case 5: /* program: sequence NAMEDPARAM  */
                      {
    params->ast = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.n);
    code_dev_post("codeac: %ld", *params->codeac);
    code_dev_post ("parse: sequence NAMEDPARAM: program\n");
    YYACCEPT;
}
    break;

  case 7: /* sequence: sequence SEQ list  */
                    {
    ((*yyvalp).n) = new astSequence((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: seq\n");
}
    break;

  case 8: /* ifThenElse: IF_KW sequence THEN_KW list  */
                                         {
    ((*yyvalp).n) = new astIfThenElse((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), nullptr, params->owner);
    code_dev_post ("parse: if then\n");
}
    break;

  case 9: /* ifThenElse: IF_KW sequence THEN_KW list ELSE_KW list  */
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
    
    ((*yyvalp).n) = new astIfThenElse((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: if then else\n");
}
    break;

  case 10: /* whileloop: WHILE_KW sequence DO_KW list  */
                                         {
    ((*yyvalp).n) = new astWhileLoop<E_LOOP_DO>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: while...do\n");
}
    break;

  case 11: /* whileloop: WHILE_KW sequence COLLECT_KW list  */
                                    {
    ((*yyvalp).n) = new astWhileLoop<E_LOOP_COLLECT>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: while...collect\n");
}
    break;

  case 12: /* forloop: FOR_KW forargList DO_KW list  */
{
    ((*yyvalp).n) = new astForLoop<E_LOOP_DO>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.fal), nullptr, nullptr, nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: FOR_KW forargList DO_KW list\n");
}
    break;

  case 13: /* forloop: FOR_KW forargList WITH_KW argsByNameList DO_KW list  */
{
    ((*yyvalp).n) = new astForLoop<E_LOOP_DO>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.fal), nullptr, nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.snpl), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: forargList WITH_KW argsByNameList DO_KW list\n");
}
    break;

  case 14: /* forloop: FOR_KW forargList AS_KW sequence DO_KW list  */
{
    ((*yyvalp).n) = new astForLoop<E_LOOP_DO>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.fal), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: FOR_KW forargList AS_KW sequence DO_KW list\n");
}
    break;

  case 15: /* forloop: FOR_KW forargList AS_KW sequence WITH_KW argsByNameList DO_KW list  */
{
    ((*yyvalp).n) = new astForLoop<E_LOOP_DO>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.fal), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.snpl), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: forargList AS_KW sequence WITH_KW argsByNameList DO_KW list\n");
}
    break;

  case 16: /* forloop: FOR_KW forargList WITH_KW argsByNameList AS_KW sequence DO_KW list  */
{
    ((*yyvalp).n) = new astForLoop<E_LOOP_DO>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.fal), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.snpl), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: FOR_KW forargList WITH_KW argsByNameList AS_KW sequence DO_KW list\n");
}
    break;

  case 17: /* forloop: FOR_KW forargList COLLECT_KW list  */
{
    ((*yyvalp).n) = new astForLoop<E_LOOP_COLLECT>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.fal), nullptr, nullptr, nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: FOR_KW forargList COLLECT_KW list\n");
}
    break;

  case 18: /* forloop: FOR_KW forargList WITH_KW argsByNameList COLLECT_KW list  */
{
    ((*yyvalp).n) = new astForLoop<E_LOOP_COLLECT>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.fal), nullptr, nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.snpl), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: forargList WITH_KW argsByNameList COLLECT_KW list\n");
}
    break;

  case 19: /* forloop: FOR_KW forargList AS_KW sequence COLLECT_KW list  */
{
    ((*yyvalp).n) = new astForLoop<E_LOOP_COLLECT>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.fal), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: FOR_KW forargList AS_KW sequence COLLECT_KW list\n");
}
    break;

  case 20: /* forloop: FOR_KW forargList AS_KW sequence WITH_KW argsByNameList COLLECT_KW list  */
{
    ((*yyvalp).n) = new astForLoop<E_LOOP_COLLECT>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.fal), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.snpl), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: forargList AS_KW sequence WITH_KW argsByNameList COLLECT_KW list\n");
}
    break;

  case 21: /* forloop: FOR_KW forargList WITH_KW argsByNameList AS_KW sequence COLLECT_KW list  */
{
    ((*yyvalp).n) = new astForLoop<E_LOOP_COLLECT>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.fal), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.snpl), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: FOR_KW forargList WITH_KW argsByNameList AS_KW sequence COLLECT_KW list\n");
}
    break;

  case 22: /* forargList: forarg  */
                    {
    ((*yyvalp).fal) = new countedList<forArg *>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.forarg));
    code_dev_post ("parse: for iterator (first term)\n");
}
    break;

  case 23: /* forargList: forargList COMMA forarg  */
                          {
    ((*yyvalp).fal) = new countedList<forArg *>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.forarg), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.fal));
    code_dev_post ("parse: for iterator (subsequent term)\n");
}
    break;

  case 24: /* forarg: LOCALVAR IN_KW sequence  */
                                 {
    ((*yyvalp).forarg) = new forArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.sym), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n));
    addVariableToScope(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.sym));
    code_dev_post ("parse: for iterator with index");
}
    break;

  case 25: /* forarg: LOCALVAR LOCALVAR IN_KW sequence  */
                                   {
    addVariableToScope(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.sym));
    addVariableToScope(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.sym));
    ((*yyvalp).forarg) = new forArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.sym), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.sym), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n));
    code_dev_post ("parse: for iterator with index and address");
}
    break;

  case 26: /* $@1: %empty  */
                           {
    params->fnDepth++;
    *++(params->liftedVariablesStack) = new std::unordered_set<t_symbol *>;
    *++(params->argumentsStack) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.funarglist);
}
    break;

  case 27: /* fundef: funargList FUNDEF $@1 list  */
       {
    t_function *fn = new t_userFunction(*(params->argumentsStack), *(params->localVariablesStack), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    params->funcs->insert(fn);
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
    break;

  case 28: /* $@2: %empty  */
         {
    ++(params->localVariablesStack);
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
    *++(params->liftedVariablesStack) = new std::unordered_set<t_symbol *>;
    params->fnDepth++;
    *++(params->argumentsStack) = nullptr;
}
    break;

  case 29: /* fundef: FUNDEF $@2 list  */
       {
    t_function *fn = new t_userFunction(*(params->argumentsStack), *(params->localVariablesStack), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    params->funcs->insert(fn);
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
    break;

  case 30: /* $@3: %empty  */
                                  {
    params->fnDepth++;
    *++(params->liftedVariablesStack) = new std::unordered_set<t_symbol *>;
    for (countedList<t_localVar> *v = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.liftedarglist)->getHead();
         v;
         v = v->getNext()) {
             (*(params->liftedVariablesStack))->insert(v->getItem().getName());
    }
    *++(params->argumentsStack) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.funarglist);
}
    break;

  case 31: /* fundef: funargList liftedargList FUNDEF $@3 list  */
       {
    t_function *fn = new t_userFunction(*(params->argumentsStack), *(params->localVariablesStack), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    params->funcs->insert(fn);
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
    break;

  case 32: /* $@4: %empty  */
                       {
    params->fnDepth++;
    ++(params->localVariablesStack);
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
    *++(params->liftedVariablesStack) = new std::unordered_set<t_symbol *>;
    *++(params->argumentsStack) = nullptr;
    for (countedList<t_localVar> *v = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.liftedarglist)->getHead();
         v;
         v = v->getNext()) {
        (*(params->liftedVariablesStack))->insert(v->getItem().getName());
    }
}
    break;

  case 33: /* fundef: liftedargList FUNDEF $@4 list  */
       {
    t_function *fn = new t_userFunction(*++(params->argumentsStack), *(params->localVariablesStack), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    params->funcs->insert(fn);
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
    break;

  case 34: /* funargList: LOCALVAR  */
                      {
    ++(params->localVariablesStack);
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
    ((*yyvalp).funarglist) = new countedList<funArg *>(new funArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym)));
    (**(params->localVariablesAuxMapStack))[(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym)] = 1;
    code_dev_post ("parse: funargList (first term, no default)\n");
}
    break;

  case 35: /* funargList: ELLIPSIS  */
           {
    ++(params->localVariablesStack);
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
    ((*yyvalp).funarglist) = new countedList<funArg *>(new funArg(gensym("<...>")));
    code_dev_post ("parse: ELLIPSIS");
}
    break;

  case 36: /* $@5: %empty  */
                  {
    // two levels are pushed:
    // one for the function, whose definition is beginning here,
    // and one for the parameter default, which is in an inner scope
    params->localVariablesStack += 2;
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
    (**(params->localVariablesAuxMapStack))[(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.sym)] = 1;
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
}
    break;

  case 37: /* funargList: LOCALVAR ASSIGN $@5 list  */
       {
    ((*yyvalp).funarglist) = new countedList<funArg *>(new funArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.sym), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), *(params->localVariablesStack)));
    delete *(params->localVariablesAuxMapStack);
    
    // this pops the parameter default level
    *(params->localVariablesAuxMapStack--) = nullptr;
    *(params->localVariablesStack--) = nullptr;
    code_dev_post ("parse: funargList (first term, with default)\n");
}
    break;

  case 38: /* funargList: funargList COMMA LOCALVAR  */
                            {
    ((*yyvalp).funarglist) = new countedList<funArg *>(new funArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.funarglist));
    (**(params->localVariablesAuxMapStack))[(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym)] = 1;
    code_dev_post ("parse: funargList (subsequent term, no default)\n");
}
    break;

  case 39: /* funargList: funargList COMMA ELLIPSIS  */
                            {
    ((*yyvalp).funarglist) = new countedList<funArg *>(new funArg(gensym("<...>")), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.funarglist));
    code_dev_post ("parse: funargList (subsequent term, no default)\n");
}
    break;

  case 40: /* $@6: %empty  */
                                   {
    (**(params->localVariablesAuxMapStack))[(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.sym)] = 1;
    ++(params->localVariablesStack);
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
}
    break;

  case 41: /* funargList: funargList COMMA LOCALVAR ASSIGN $@6 list  */
       {
    ((*yyvalp).funarglist) = new countedList<funArg *>(new funArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.sym), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), *(params->localVariablesStack)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.funarglist));
    delete *(params->localVariablesAuxMapStack);
    *(params->localVariablesAuxMapStack--) = nullptr;
    *(params->localVariablesStack--) = nullptr;
    code_dev_post ("parse: funargList (subsequent term, with default)\n");
}
    break;

  case 42: /* liftedargList: LIFT LOCALVAR  */
                              {
    ((*yyvalp).liftedarglist) = new countedList<t_localVar>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym));
    code_dev_post ("parse: liftedargList (first term)\n");
}
    break;

  case 43: /* liftedargList: liftedargList COMMA LOCALVAR  */
                               {
    ((*yyvalp).liftedarglist) = new countedList<t_localVar>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.liftedarglist));
    code_dev_post ("parse: liftedargList (subsequent term)\n");
}
    break;

  case 45: /* functionApplication: exp APPLY funcall  */
{
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fc)->addOopStyleArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n));
    code_dev_post ("parse: term APPLY funcall");
    ((*yyvalp).fc) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fc);
}
    break;

  case 46: /* funcall: term STARTPARAMS argsByPositionList CLOSEDROUND  */
                                                          {
    ((*yyvalp).fc) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.nl), nullptr, params->owner);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.nl);
    code_dev_post ("parse: function call with args by position");
}
    break;

  case 47: /* funcall: term STARTPARAMS argsByNameList CLOSEDROUND  */
                                              {
    ((*yyvalp).fc) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.n), nullptr, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.snpl), params->owner);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.snpl);
    code_dev_post ("parse: function call with args by name");
}
    break;

  case 48: /* funcall: term STARTPARAMS argsByPositionList COMMA argsByNameList CLOSEDROUND  */
                                                                       {
    ((*yyvalp).fc) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.nl), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.snpl), params->owner);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.nl);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.snpl);
    code_dev_post ("parse: function call with args by position and by name");
}
    break;

  case 49: /* funcall: term STARTPARAMS argsByPositionList argsByNameList CLOSEDROUND  */
                                                                 {
    ((*yyvalp).fc) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.nl), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.snpl), params->owner);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.nl);
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.snpl);
    code_dev_post ("parse: function call with args by position and by name");
}
    break;

  case 50: /* funcall: term STARTPARAMS CLOSEDROUND  */
                               {
    ((*yyvalp).fc) = new astFunctionCall((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), nullptr, nullptr, params->owner);
    code_dev_post ("parse: function call with no args");
}
    break;

  case 51: /* argsByPositionList: sequence  */
                              {
    ((*yyvalp).nl) = new countedList<astNode *>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n));
    code_dev_post ("parse: argsByPositionList (first term)\n");
}
    break;

  case 52: /* argsByPositionList: argsByPositionList COMMA sequence  */
                                    {
    ((*yyvalp).nl) = new countedList<astNode *>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.nl));
    code_dev_post ("parse: argsByPositionList (subsequent term)\n");
}
    break;

  case 53: /* argsByNameList: argByName  */
                           {
    ((*yyvalp).snpl) = new countedList<symNodePair *>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.snp));
    code_dev_post ("parse: argsByNameList (first term)\n");
}
    break;

  case 54: /* argsByNameList: argsByNameList COMMA argByName  */
                                 {
    ((*yyvalp).snpl) = new countedList<symNodePair *>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.snp), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.snpl));
    code_dev_post ("parse: argsByNameList (subsequent term)\n");
}
    break;

  case 55: /* argsByNameList: argsByNameList argByName  */
                           {
    ((*yyvalp).snpl) = new countedList<symNodePair *>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.snp), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.snpl));
    code_dev_post ("parse: argsByNameList (subsequent term)\n");
}
    break;

  case 56: /* argByName: NAMEDPARAM sequence  */
                                {
    ((*yyvalp).snp) = new symNodePair((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.sym), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n));
    code_dev_post ("parse: named parameter %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.sym)->s_name);
}
    break;

  case 59: /* list: simpleList listEnd  */
                                  {
    ((*yyvalp).n) = new astConcat((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: cat\n");
}
    break;

  case 66: /* simpleList: simpleList exp  */
                              {
    ((*yyvalp).n) = new astConcat((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: cat\n");
}
    break;

  case 68: /* assignment: OUTLET ASSIGN list  */
                     {
    if (params->dataOutlets && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.l) > *(params->dataOutlets))
        *(params->dataOutlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.l);
    auto fnConst = new astConst((*(params->bifs))["outlet"], params->owner);


    auto numConst = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.l), params->owner);
    auto tempList = new countedList<astNode *>(numConst);
    tempList = new countedList<astNode *>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), tempList);
    ((*yyvalp).n) = new astFunctionCall(fnConst, tempList, nullptr, params->owner);
    code_dev_post("parse: OUTLET ASSIGN list");
}
    break;

  case 69: /* assignment: DIROUTLET ASSIGN list  */
                        {
    if (params->directOutlets && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.l) > *(params->directOutlets))
        *(params->directOutlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.l);
    auto fnConst = new astConst((*(params->ofTable))["directout"], params->owner);
    auto tempList = new countedList<astNode *>(new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.l), params->owner));
    tempList = new countedList<astNode *>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), tempList);
    ((*yyvalp).n) = new astFunctionCall(fnConst, tempList, nullptr, params->owner);
    code_dev_post("parse: DIROUTLET ASSIGN list");
}
    break;

  case 70: /* assign: var ASSIGN list  */
                         {
    ((*yyvalp).n) = new astAssign((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: var ASSIGN list");
}
    break;

  case 71: /* assign: INIT LOCALVAR ASSIGN list  */
                            {
    addVariableToScope(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.sym));
    ((*yyvalp).n) = new astInit((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.sym), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: INIT LOCALVAR ASSIGN list");
}
    break;

  case 72: /* assign: var lvalueStepList ASSIGN list  */
                                 {
    ((*yyvalp).n) = new astRichAssignment<E_RA_STANDARD>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ASSIGN list");
}
    break;

  case 73: /* assign: var APLUS list  */
                 {
    ((*yyvalp).n) = new astOperatorAPlus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: var APLUS list");
}
    break;

  case 74: /* assign: var lvalueStepList APLUS list  */
                                {
    ((*yyvalp).n) = new astOperatorRAPlus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList APLUS list");
}
    break;

  case 75: /* assign: var AMINUS list  */
                  {
    ((*yyvalp).n) = new astOperatorAMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: var AMINUS list");
}
    break;

  case 76: /* assign: var lvalueStepList AMINUS list  */
                                 {
    ((*yyvalp).n) = new astOperatorRAMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList AMINUS list");
}
    break;

  case 77: /* assign: var ATIMES list  */
                  {
    ((*yyvalp).n) = new astOperatorATimes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: var ATIMES list");
}
    break;

  case 78: /* assign: var lvalueStepList ATIMES list  */
                                 {
    ((*yyvalp).n) = new astOperatorRATimes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ATIMES list");
}
    break;

  case 79: /* assign: var APOWOP list  */
                  {
    ((*yyvalp).n) = new astOperatorAPow((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: var APOWOP list");
}
    break;

  case 80: /* assign: var lvalueStepList APOWOP list  */
                                 {
    ((*yyvalp).n) = new astOperatorRAPow((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList APOWOP list");
}
    break;

  case 81: /* assign: var ADIV list  */
                {
    ((*yyvalp).n) = new astOperatorADiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: var ADIV list");
}
    break;

  case 82: /* assign: var lvalueStepList ADIV list  */
                               {
    ((*yyvalp).n) = new astOperatorRADiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ADIV list");
}
    break;

  case 83: /* assign: var ADIVDIV list  */
                   {
    ((*yyvalp).n) = new astOperatorADivdiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: var ADIVDIV list");
}
    break;

  case 84: /* assign: var lvalueStepList ADIVDIV list  */
                                  {
    ((*yyvalp).n) = new astOperatorRADivdiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ADIVDIV list");
}
    break;

  case 85: /* assign: var AREM list  */
                {
    ((*yyvalp).n) = new astOperatorARemainder((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: var AREM list");
}
    break;

  case 86: /* assign: var lvalueStepList AREM list  */
                               {
    ((*yyvalp).n) = new astOperatorRARemainder((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList AREM list");
}
    break;

  case 87: /* assign: var ABITAND list  */
                   {
    ((*yyvalp).n) = new astOperatorABitAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: var ABITAND list");
}
    break;

  case 88: /* assign: var lvalueStepList ABITAND list  */
                                  {
    ((*yyvalp).n) = new astOperatorRABitAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ABITAND list");
}
    break;

  case 89: /* assign: var ABITXOR list  */
                   {
    ((*yyvalp).n) = new astOperatorABitXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: var ABITXOR list");
}
    break;

  case 90: /* assign: var lvalueStepList ABITXOR list  */
                                  {
    ((*yyvalp).n) = new astOperatorRABitXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ABITXOR list");
}
    break;

  case 91: /* assign: var ABITOR list  */
                  {
    ((*yyvalp).n) = new astOperatorABitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: localVar ABITOR list");
}
    break;

  case 92: /* assign: var lvalueStepList ABITOR list  */
                                 {
    ((*yyvalp).n) = new astOperatorRABitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ABITOR list");
}
    break;

  case 93: /* assign: var ALSHIFT list  */
                   {
    ((*yyvalp).n) = new astOperatorALShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: var ALSHIFT list");
}
    break;

  case 94: /* assign: var lvalueStepList ALSHIFT list  */
                                  {
    ((*yyvalp).n) = new astOperatorRALShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ALSHIFT list");
}
    break;

  case 95: /* assign: var ARSHIFT list  */
                   {
    ((*yyvalp).n) = new astOperatorARShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: var ARSHIFT list");
}
    break;

  case 96: /* assign: var lvalueStepList ARSHIFT list  */
                                  {
    ((*yyvalp).n) = new astOperatorRARShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ARSHIFT list");
}
    break;

  case 97: /* assign: var ALOGAND list  */
                   {
    ((*yyvalp).n) = new astSCAAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: var ALOGAND list");
}
    break;

  case 98: /* assign: var lvalueStepList ALOGAND list  */
                                  {
    ((*yyvalp).n) = new astLogRASCAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ALOGAND list");
}
    break;

  case 99: /* assign: var ALOGANDEXT list  */
                      {
    ((*yyvalp).n) = new astSCAAndExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: var ALOGANDEXT list");
}
    break;

  case 100: /* assign: var lvalueStepList ALOGANDEXT list  */
                                     {
    ((*yyvalp).n) = new astSCRichAccessAndExt<astRichAssignment<E_RA_SHORTCIRCUIT>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ALOGANDEXT list");
}
    break;

  case 101: /* assign: var ALOGXOR list  */
                   {
    ((*yyvalp).n) = new astLogAXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: var ALOGXOR list");
}
    break;

  case 102: /* assign: var lvalueStepList ALOGXOR list  */
                                  {
    ((*yyvalp).n) = new astLogRAXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ALOGXOR list");
}
    break;

  case 103: /* assign: var ALOGOR list  */
                  {
    ((*yyvalp).n) = new astSCAOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: var ALOGOR list");
}
    break;

  case 104: /* assign: var lvalueStepList ALOGOR list  */
                                 {
    ((*yyvalp).n) = new astLogRASCOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ALOGOR list");
}
    break;

  case 105: /* assign: var ALOGOREXT list  */
                     {
    ((*yyvalp).n) = new astSCAOrExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: var ALOGOREXT list");
}
    break;

  case 106: /* assign: var lvalueStepList ALOGOREXT list  */
                                    {
    ((*yyvalp).n) = new astSCRichAccessOrExt<astRichAssignment<E_RA_SHORTCIRCUIT>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ALOGOREXT list");
}
    break;

  case 107: /* assign: var ANTHOP list  */
                  {
    ((*yyvalp).n) = new astNthAssignOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: var ANTHOP list op\n");
}
    break;

  case 108: /* assign: var lvalueStepList ANTHOP list  */
                                 {
    ((*yyvalp).n) = new astRichAccessNthOp<astRichAssignment<E_RA_STANDARD>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ANTHOP list");
}
    break;

  case 109: /* assign: var ACONCAT list  */
                   {
    ((*yyvalp).n) = new astConcatAssignOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: var ACONCAT list op\n");
}
    break;

  case 110: /* assign: var lvalueStepList ACONCAT list  */
                                  {
    ((*yyvalp).n) = new astRichAccessConcatOp<astRichAssignment<E_RA_STANDARD>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ACONCAT list");
}
    break;

  case 111: /* assign: var ARCONCAT list  */
                    {
    ((*yyvalp).n) = new astRevConcatAssignOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: var ARCONCAT list op\n");
}
    break;

  case 112: /* assign: var lvalueStepList ARCONCAT list  */
                                   {
    ((*yyvalp).n) = new astRichAccessRConcatOp<astRichAssignment<E_RA_STANDARD>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ARCONCAT list");
}
    break;

  case 113: /* assign: localVar AAPPLY funcall  */
                          {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fc)->addOopStyleArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lv));
    ((*yyvalp).n) = new astAssign(new astLocalVar((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lv)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fc), params->owner);
    code_dev_post ("parse: localVar AAPPLY funcall");
}
    break;

  case 114: /* assign: patcherVar AAPPLY funcall  */
                            {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fc)->addOopStyleArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.pv));
    astPatcherVar *v = new astPatcherVar((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.pv));
    (*params->name2patcherVars)[v->getName()].insert(v);
    ((*yyvalp).n) = new astAssign(v, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fc), params->owner);
    code_dev_post ("parse: patcherVar AAPPLY funcall");
}
    break;

  case 115: /* assign: globalVar AAPPLY funcall  */
                           {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fc)->addOopStyleArg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.gv));
    ((*yyvalp).n) = new astAssign(new astGlobalVar((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.gv)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fc), params->owner);
    code_dev_post ("parse: globalVar AAPPLY funcall");
}
    break;

  case 116: /* assign: var lvalueStepList AAPPLY funcall  */
                                    {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fc)->addOopStyleArg(new astConst(params->owner));
    ((*yyvalp).n) = new astRichAccessApplyOp<astRichAssignment<E_RA_SHORTCIRCUIT>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.var), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fc), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList AAPPLY list");
}
    break;

  case 117: /* lvalueStepList: NTHOP lvalueStepParams  */
                                       {
    ((*yyvalp).lvsl) = new lvalueStepList(new lvalueStep(lvalueStep::E_LV_NTH, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n)));
    code_dev_post ("parse: lvalueStepList (NTH first term)");
}
    break;

  case 118: /* lvalueStepList: APPLY lvalueStepParams  */
                         {
    ((*yyvalp).lvsl) = new lvalueStepList(new lvalueStep(lvalueStep::E_LV_KEY, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n)));
    code_dev_post ("parse: lvalueStepList (KEY first term)");
}
    break;

  case 119: /* lvalueStepList: lvalueStepList NTHOP lvalueStepParams  */
                                        {
    ((*yyvalp).lvsl) = new lvalueStepList(new lvalueStep(lvalueStep::E_LV_NTH, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl));
    code_dev_post ("parse: lvalueStepList (NTH subsequent term)");
}
    break;

  case 120: /* lvalueStepList: lvalueStepList APPLY lvalueStepParams  */
                                        {
    ((*yyvalp).lvsl) = new lvalueStepList(new lvalueStep(lvalueStep::E_LV_KEY, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl));
    code_dev_post ("parse: lvalueStepList (KEY subsequent term)");
}
    break;

  case 122: /* lvalueStepParams: lvalueStepParams exp  */
                                              {
    ((*yyvalp).n) = new astConcat((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: cat\n");
}
    break;

  case 124: /* exp: UPLUS listEnd  */
                { ((*yyvalp).n) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n); }
    break;

  case 125: /* exp: UMINUS listEnd  */
                 {
    ((*yyvalp).n) = new astOperatorUMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: U-\n");
}
    break;

  case 126: /* exp: LOGNOT listEnd  */
                 {
    ((*yyvalp).n) = new astLogNot((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: !\n");
}
    break;

  case 127: /* exp: BITNOT listEnd  */
                 {
    ((*yyvalp).n) = new astOperatorBitNot((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: ~\n");
}
    break;

  case 128: /* exp: exp PLUS listEnd  */
                   {
    ((*yyvalp).n) = new astOperatorPlus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: +\n");
}
    break;

  case 129: /* exp: exp MINUS listEnd  */
                    {
    ((*yyvalp).n) = new astOperatorMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: -\n");
}
    break;

  case 130: /* exp: exp TIMES listEnd  */
                    {
    ((*yyvalp).n) = new astOperatorTimes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: *\n");
}
    break;

  case 131: /* exp: exp DIV listEnd  */
                  {
    ((*yyvalp).n) = new astOperatorDiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: /\n");
}
    break;

  case 132: /* exp: exp DIVDIV listEnd  */
                     {
    ((*yyvalp).n) = new astOperatorDivdiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: //\n");
}
    break;

  case 133: /* exp: exp REM listEnd  */
                  {
    ((*yyvalp).n) = new astOperatorRemainder((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: %\n");
}
    break;

  case 134: /* exp: exp POWOP listEnd  */
                    {
    ((*yyvalp).n) = new astOperatorPow((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: **\n");
}
    break;

  case 135: /* exp: exp BITAND listEnd  */
                     {
    ((*yyvalp).n) = new astOperatorBitAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: &\n");
}
    break;

  case 136: /* exp: exp BITXOR listEnd  */
                     {
    ((*yyvalp).n) = new astOperatorBitXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: ^\n");
}
    break;

  case 137: /* exp: exp BITOR listEnd  */
                    {
    ((*yyvalp).n) = new astOperatorBitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: |\n");
}
    break;

  case 138: /* exp: exp LSHIFT listEnd  */
                     {
    ((*yyvalp).n) = new astOperatorLShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: <<\n");
}
    break;

  case 139: /* exp: exp RSHIFT listEnd  */
                     {
    ((*yyvalp).n) = new astOperatorRShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: >>\n");
}
    break;

  case 140: /* exp: exp EQUAL listEnd  */
                    {
    ((*yyvalp).n) = new astComparatorEq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: ==\n");
}
    break;

  case 141: /* exp: exp NEQ listEnd  */
                  {
    ((*yyvalp).n) = new astComparatorNeq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: !=\n");
}
    break;

  case 142: /* exp: exp LT listEnd  */
                 {
    ((*yyvalp).n) = new astComparatorLt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: <\n");
}
    break;

  case 143: /* exp: exp GT listEnd  */
                 {
    ((*yyvalp).n) = new astComparatorGt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: <\n");
}
    break;

  case 144: /* exp: exp LEQ listEnd  */
                  {
    ((*yyvalp).n) = new astComparatorLeq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: <=\n");
}
    break;

  case 145: /* exp: exp GEQ listEnd  */
                  {
    ((*yyvalp).n) = new astComparatorGeq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: >=\n");
}
    break;

  case 146: /* exp: exp LOGOR listEnd  */
                    {
    ((*yyvalp).n) = new astSCOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: ||\n");
}
    break;

  case 147: /* exp: exp LOGAND listEnd  */
                     {
    ((*yyvalp).n) = new astSCAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: &&\n");
}
    break;

  case 148: /* exp: exp LOGXOR listEnd  */
                     {
    ((*yyvalp).n) = new astLogXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: &&\n");
}
    break;

  case 149: /* exp: exp LOGOREXT listEnd  */
                       {
    ((*yyvalp).n) = new astSCOrExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: |||\n");
}
    break;

  case 150: /* exp: exp LOGANDEXT listEnd  */
                        {
    ((*yyvalp).n) = new astSCAndExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: &&&\n");
}
    break;

  case 151: /* exp: exp NTHOP listEnd  */
                    {
    ((*yyvalp).n) = new astNthOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: nthop (exp NTHOP listEnd)\n");
}
    break;

  case 152: /* exp: exp PICKOP listEnd  */
                     {
    ((*yyvalp).n) = new astPickOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: nthop\n");
}
    break;

  case 153: /* exp: exp RANGE listEnd  */
                    {
    ((*yyvalp).n) = new astRangeOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: range\n");
}
    break;

  case 154: /* exp: exp REPEAT listEnd  */
                     {
    ((*yyvalp).n) = new astRepeatOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: range\n");
}
    break;

  case 155: /* exp: exp APPLY listEnd  */
                             {
    ((*yyvalp).n) = new astKeyOp<e_keyOpStandard>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: access\n");
}
    break;

  case 156: /* exp: exp ACCESS_UNWRAP listEnd  */
                            {
    ((*yyvalp).n) = new astKeyOp<e_keyOpUnwrapping>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: access\n");
}
    break;

  case 157: /* exp: UPLUS exp  */
            { ((*yyvalp).n) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n); }
    break;

  case 158: /* exp: UMINUS exp  */
             {
    ((*yyvalp).n) = new astOperatorUMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: U-\n");
}
    break;

  case 159: /* exp: LOGNOT exp  */
             {
    ((*yyvalp).n) = new astLogNot((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: !\n");
}
    break;

  case 160: /* exp: BITNOT exp  */
             {
    ((*yyvalp).n) = new astOperatorBitNot((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: ~\n");
}
    break;

  case 161: /* exp: exp PLUS exp  */
               {
    ((*yyvalp).n) = new astOperatorPlus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: +\n");
}
    break;

  case 162: /* exp: exp MINUS exp  */
                {
    ((*yyvalp).n) = new astOperatorMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: -\n");
}
    break;

  case 163: /* exp: exp TIMES exp  */
                {
    ((*yyvalp).n) = new astOperatorTimes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: *\n");
}
    break;

  case 164: /* exp: exp DIV exp  */
              {
    ((*yyvalp).n) = new astOperatorDiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: /\n");
}
    break;

  case 165: /* exp: exp DIVDIV exp  */
                 {
    ((*yyvalp).n) = new astOperatorDivdiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: //\n");
}
    break;

  case 166: /* exp: exp REM exp  */
              {
    ((*yyvalp).n) = new astOperatorRemainder((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: %\n");
}
    break;

  case 167: /* exp: exp POWOP exp  */
                {
    ((*yyvalp).n) = new astOperatorPow((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: **\n");
}
    break;

  case 168: /* exp: exp BITAND exp  */
                 {
    ((*yyvalp).n) = new astOperatorBitAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: &\n");
}
    break;

  case 169: /* exp: exp BITXOR exp  */
                 {
    ((*yyvalp).n) = new astOperatorBitXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: ^\n");
}
    break;

  case 170: /* exp: exp BITOR exp  */
                {
    ((*yyvalp).n) = new astOperatorBitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: |\n");
}
    break;

  case 171: /* exp: exp LSHIFT exp  */
                 {
    ((*yyvalp).n) = new astOperatorBitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: <<\n");
}
    break;

  case 172: /* exp: exp RSHIFT exp  */
                 {
    ((*yyvalp).n) = new astOperatorBitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: >>\n");
}
    break;

  case 173: /* exp: exp EQUAL exp  */
                {
    ((*yyvalp).n) = new astComparatorEq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: ==\n");
}
    break;

  case 174: /* exp: exp NEQ exp  */
              {
    ((*yyvalp).n) = new astComparatorNeq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: !=\n");
}
    break;

  case 175: /* exp: exp LT exp  */
             {
    ((*yyvalp).n) = new astComparatorLt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: <\n");
}
    break;

  case 176: /* exp: exp GT exp  */
             {
    ((*yyvalp).n) = new astComparatorGt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: <\n");
}
    break;

  case 177: /* exp: exp LEQ exp  */
              {
    ((*yyvalp).n) = new astComparatorLeq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: <=\n");
}
    break;

  case 178: /* exp: exp GEQ exp  */
              {
    ((*yyvalp).n) = new astComparatorGeq((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: >=\n");
}
    break;

  case 179: /* exp: exp LOGOR exp  */
                {
    ((*yyvalp).n) = new astSCOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: ||\n");
}
    break;

  case 180: /* exp: exp LOGAND exp  */
                 {
    ((*yyvalp).n) = new astSCAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: &&\n");
}
    break;

  case 181: /* exp: exp LOGXOR exp  */
                 {
    ((*yyvalp).n) = new astLogXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: &&\n");
}
    break;

  case 182: /* exp: exp LOGOREXT exp  */
                   {
    ((*yyvalp).n) = new astSCOrExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: |||\n");
}
    break;

  case 183: /* exp: exp LOGANDEXT exp  */
                    {
    ((*yyvalp).n) = new astSCAndExt((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: &&&\n");
}
    break;

  case 184: /* exp: exp NTHOP exp  */
                {
    ((*yyvalp).n) = new astNthOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: nthop (exp NTHOP exp)\n");
}
    break;

  case 185: /* exp: exp PICKOP exp  */
                 {
    ((*yyvalp).n) = new astPickOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: nthop\n");
}
    break;

  case 186: /* exp: exp RANGE exp  */
                {
    ((*yyvalp).n) = new astRangeOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: range\n");
}
    break;

  case 187: /* exp: exp REPEAT exp  */
                 {
    ((*yyvalp).n) = new astRepeatOp((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: range\n");
}
    break;

  case 188: /* exp: exp APPLY exp  */
                {
    ((*yyvalp).n) = new astKeyOp<e_keyOpStandard>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: access\n");
}
    break;

  case 189: /* exp: exp ACCESS_UNWRAP exp  */
                        {
    ((*yyvalp).n) = new astKeyOp<e_keyOpUnwrapping>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post ("parse: access_unwrap\n");
}
    break;

  case 190: /* exp: term lvalueStepList ASSIGN list  */
                                           {
    ((*yyvalp).n) = new astRichEdit<E_RA_STANDARD>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ASSIGN list");
}
    break;

  case 191: /* exp: term lvalueStepList APLUS list  */
                                          {
    ((*yyvalp).n) = new astOperatorREPlus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList APLUS list");
}
    break;

  case 192: /* exp: term lvalueStepList AMINUS list  */
                                           {
    ((*yyvalp).n) = new astOperatorREMinus((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList AMINUS list");
}
    break;

  case 193: /* exp: term lvalueStepList ATIMES list  */
                                           {
    ((*yyvalp).n) = new astOperatorRETimes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ATIMES list");
}
    break;

  case 194: /* exp: term lvalueStepList APOWOP list  */
                                           {
    ((*yyvalp).n) = new astOperatorREPow((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList APOWOP list");
}
    break;

  case 195: /* exp: term lvalueStepList ADIV list  */
                                         {
    ((*yyvalp).n) = new astOperatorREDiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ADIV list");
}
    break;

  case 196: /* exp: term lvalueStepList ADIVDIV list  */
                                            {
    ((*yyvalp).n) = new astOperatorREDivdiv((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ADIVDIV list");
}
    break;

  case 197: /* exp: term lvalueStepList AREM list  */
                                         {
    ((*yyvalp).n) = new astOperatorRERemainder((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList AREM list");
}
    break;

  case 198: /* exp: term lvalueStepList ABITAND list  */
                                            {
    ((*yyvalp).n) = new astOperatorREBitAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ABITAND list");
}
    break;

  case 199: /* exp: term lvalueStepList ABITXOR list  */
                                            {
    ((*yyvalp).n) = new astOperatorREBitXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ABITXOR list");
}
    break;

  case 200: /* exp: term lvalueStepList ABITOR list  */
                                           {
    ((*yyvalp).n) = new astOperatorREBitOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ABITOR list");
}
    break;

  case 201: /* exp: term lvalueStepList ALSHIFT list  */
                                            {
    ((*yyvalp).n) = new astOperatorRELShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ALSHIFT list");
}
    break;

  case 202: /* exp: term lvalueStepList ARSHIFT list  */
                                            {
    ((*yyvalp).n) = new astOperatorRERShift((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ARSHIFT list");
}
    break;

  case 203: /* exp: term lvalueStepList ALOGAND list  */
                                            {
    ((*yyvalp).n) = new astLogRESCAnd((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ALOGAND list");
}
    break;

  case 204: /* exp: term lvalueStepList ALOGANDEXT list  */
                                               {
    ((*yyvalp).n) = new astSCRichAccessAndExt<astRichEdit<E_RA_SHORTCIRCUIT>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ALOGANDEXT list");
}
    break;

  case 205: /* exp: term lvalueStepList ALOGXOR list  */
                                            {
    ((*yyvalp).n) = new astLogREXor((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ALOGXOR list");
}
    break;

  case 206: /* exp: term lvalueStepList ALOGOR list  */
                                           {
    ((*yyvalp).n) = new astLogRESCOr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ALOGOR list");
}
    break;

  case 207: /* exp: term lvalueStepList ALOGOREXT list  */
                                              {
    ((*yyvalp).n) = new astSCRichAccessOrExt<astRichEdit<E_RA_SHORTCIRCUIT>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ALOGOREXT list");
}
    break;

  case 208: /* exp: term lvalueStepList ANTHOP list  */
                                           {
    ((*yyvalp).n) = new astRichAccessNthOp<astRichEdit<E_RA_STANDARD>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ANTHOP list");
}
    break;

  case 209: /* exp: term lvalueStepList ACONCAT list  */
                                            {
    ((*yyvalp).n) = new astRichAccessConcatOp<astRichEdit<E_RA_STANDARD>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ACONCAT list");
}
    break;

  case 210: /* exp: term lvalueStepList ARCONCAT list  */
                                             {
    ((*yyvalp).n) = new astRichAccessRConcatOp<astRichEdit<E_RA_STANDARD>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList ARCONCAT list");
}
    break;

  case 211: /* exp: term lvalueStepList AAPPLY funcall  */
                                              {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fc)->addOopStyleArg(new astConst(params->owner));
    ((*yyvalp).n) = new astRichAccessApplyOp<astRichEdit<E_RA_SHORTCIRCUIT>>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.n), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fc), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.lvsl), params->owner);
    code_dev_post("parse: var lvalueStepList AAPPLY list");
}
    break;

  case 212: /* term: LONG_LITERAL  */
                   {
    ((*yyvalp).n) = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.l), params->owner);
    code_dev_post("parse: INT %ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.l));
}
    break;

  case 213: /* term: RAT_LITERAL  */
              {
    ((*yyvalp).n) = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.r), params->owner);
    code_dev_post("parse: RAT_LITERAL %ld/%ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.r).num(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.r).den());
}
    break;

  case 214: /* term: DOUBLE_LITERAL  */
                 {
    ((*yyvalp).n) = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.d), params->owner);
    code_dev_post("parse: DOUBLE_LITERAL %lf", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.d));
}
    break;

  case 215: /* term: PITCH_LITERAL  */
                {
    ((*yyvalp).n) = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.p), params->owner);
    code_dev_post("parse: PITCH_LITERAL %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.p).toSym()->s_name);
}
    break;

  case 216: /* term: SYMBOL_LITERAL  */
                 {
    ((*yyvalp).n) = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym), params->owner);
    code_dev_post("parse: SYMBOL_LITERAL %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym)->s_name);
}
    break;

  case 217: /* term: BACHNULL  */
           {
    ((*yyvalp).n) = new astConst(llll_get(), params->owner);
    code_dev_post("parse: NULL");
}
    break;

  case 218: /* term: ARGCOUNT  */
           {
    auto fnConst = new astConst((*(params->bifs))["$argcount"], params->owner);
    ((*yyvalp).n) = new astFunctionCall(fnConst, nullptr, nullptr, params->owner);
    code_dev_post("parse: ARGCOUNT");
}
    break;

  case 219: /* term: BACHNIL  */
          {
    t_llll *ll = llll_get();
    llll_appendllll(ll, llll_get());
    ((*yyvalp).n) = new astConst(ll, params->owner);
    code_dev_post("parse: NIL");
}
    break;

  case 220: /* term: INLET  */
        {
    if (params->dataInlets && params->fnDepth == 0 && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.l) > *(params->dataInlets))
        *(params->dataInlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.l);
    ((*yyvalp).n) = new astInlet((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.l), params->owner);
    code_dev_post ("parse: INLET %ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.l));
}
    break;

  case 221: /* term: INTINLET  */
           {
    if (params->dataInlets && params->fnDepth == 0 && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.l) > *(params->dataInlets))
    *(params->dataInlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.l);
    ((*yyvalp).n) = new astConvInlet<hatom_fn_int>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.l), params->owner);
    code_dev_post ("parse: INTINLET %ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.l));
}
    break;

  case 222: /* term: RATINLET  */
           {
    if (params->dataInlets && params->fnDepth == 0 && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.l) > *(params->dataInlets))
    *(params->dataInlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.l);
    ((*yyvalp).n) = new astConvInlet<hatom_fn_rat>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.l), params->owner);
    code_dev_post ("parse: RATINLET %ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.l));
}
    break;

  case 223: /* term: FLOATINLET  */
             {
    if (params->dataInlets && params->fnDepth == 0 && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.l) > *(params->dataInlets))
    *(params->dataInlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.l);
    ((*yyvalp).n) = new astConvInlet<hatom_fn_float>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.l), params->owner);
    code_dev_post ("parse: FLOATINLET %ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.l));
}
    break;

  case 224: /* term: PITCHINLET  */
             {
    if (params->dataInlets && params->fnDepth == 0 && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.l) > *(params->dataInlets))
    *(params->dataInlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.l);
    ((*yyvalp).n) = new astConvInlet<hatom_fn_pitch>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.l), params->owner);
    code_dev_post ("parse: PITCHINLET %ld", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.l));
}
    break;

  case 225: /* term: DIRINLET  */
           {
    if (params->directInlets && (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.l) > *(params->directInlets))
        *(params->directInlets) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.l);
    auto fnConst = new astConst((*(params->ofTable))["directin"], params->owner);
    auto numConst = new astConst((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.l), params->owner);
    auto tempList = new countedList<astNode *>(numConst);
    ((*yyvalp).n) = new astFunctionCall(fnConst, tempList, nullptr, params->owner);
    code_dev_post("parse: DIRINLET");
}
    break;

  case 226: /* term: OPEN sequence CLOSEDROUND  */
                            {
    ((*yyvalp).n) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.n);
    code_dev_post ("parse: []\n");
}
    break;

  case 227: /* term: OPEN CLOSEDROUND  */
                   {
    ((*yyvalp).n) = new astConst(llll_get(), params->owner);
}
    break;

  case 228: /* term: PUSH sequence POP  */
                    {
    ((*yyvalp).n) = new astWrap((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.n), params->owner);
    code_dev_post("parse: []\n");
}
    break;

  case 229: /* term: PUSH POP  */
           {
    t_llll *ll = llll_get();
    llll_appendllll(ll, llll_get());
    ((*yyvalp).n) = new astConst(ll, params->owner);
    code_dev_post("parse: PushPop");
}
    break;

  case 230: /* term: BIF  */
      {
    t_function *fn = (*(params->bifs))[(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym)->s_name];
    ((*yyvalp).n) = new astConst(fn, params->owner);
    code_dev_post("parse: bif %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym)->s_name);
}
    break;

  case 231: /* term: OF  */
     {
    t_function *fn = (*(params->ofTable))[(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym)->s_name];
    ((*yyvalp).n) = new astConst(fn, params->owner);
    code_dev_post("parse: owned function %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym)->s_name);
}
    break;

  case 232: /* term: MAXFUNCTION  */
              {
    t_function *fn = new t_maxFunction(std::string((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.text)));
    params->funcs->insert(fn);
    ((*yyvalp).n) = new astConst(fn, params->owner);
    code_dev_post("parse: Max function %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.text));
}
    break;

  case 238: /* globalVar: GLOBALVAR  */
                     {
    astGlobalVar *v = new astGlobalVar(params->gvt, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym), params->owner);
    params->globalVariables->insert(v->getVar());
    ((*yyvalp).gv) = v;
    code_dev_post ("parse: Global variable %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym)->s_name);
}
    break;

  case 239: /* patcherVar: PATCHERVAR  */
                       {
    astPatcherVar *v = new astPatcherVar((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym), params->owner);
    (*params->name2patcherVars)[(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym)].insert(v);
    ((*yyvalp).pv) = v;
    code_dev_post ("parse: Patcher variable %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym)->s_name);
}
    break;

  case 240: /* localVar: LOCALVAR  */
                   {
    ((*yyvalp).lv) = new astLocalVar((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym), params->owner);
    addVariableToScope(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym));
    code_dev_post ("parse: Local variable %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym)->s_name);
}
    break;

  case 241: /* localVar: KEEP LOCALVAR  */
                {
    ((*yyvalp).lv) = new astKeep((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym), params->owner);
    addVariableToScope(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym));
    code_dev_post ("parse: Keep local variable %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym)->s_name);
}
    break;

  case 242: /* localVar: UNKEEP LOCALVAR  */
                  {
    ((*yyvalp).lv) = new astUnkeep((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym), params->owner);
    addVariableToScope(params, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym));
    code_dev_post ("parse: Unkeep local variable %s", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sym)->s_name);
}
    break;



      default: break;
    }

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
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
                &yys->yysemantics.yysval, scanner, params);
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

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yysymbol_kind_t
yylhsNonterm (yyRuleNum yyrule)
{
  return YY_CAST (yysymbol_kind_t, yyr1[yyrule]);
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
  yynewState->yysemantics.yysval = *yyvalp;
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

#if !YYDEBUG
# define YY_REDUCE_PRINT(Args)
#else
# define YY_REDUCE_PRINT(Args)          \
  do {                                  \
    if (yydebug)                        \
      yy_reduce_print Args;             \
  } while (0)

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
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yysval                       , scanner, params);
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
      YY_REDUCE_PRINT ((yytrue, yyrhs, yyk, yyrule, scanner, params));
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp,
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
      YY_REDUCE_PRINT ((yyfalse, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1, yyk, yyrule, scanner, params));
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp, scanner, params);
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
      YYSTYPE yysval;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yysval, scanner, params);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        YY_DPRINTF ((stderr,
                     "Parse on stack %ld rejected by rule %d (line %d).\n",
                     YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule - 1]));
      if (yyflag != yyok)
        return yyflag;
      YY_SYMBOL_PRINT ("-> $$ =", yylhsNonterm (yyrule), &yysval, &yyloc);
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yysval);
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
                   YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule - 1],
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
          yys1->yysemantics.yysval = yys0->yysemantics.yysval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yysval = yys1->yysemantics.yysval;
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

static YYRESULTTAG yyresolveValue (yyGLRState* yys,
                                   yyGLRStack* yystackp, void *scanner, struct _parseParams *params);


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
                           yystackp, yyvalp, scanner, params);
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
  YYSTYPE yysval;
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
      yyflag = yyresolveAction (yybest, yystackp, &yysval, scanner, params);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yysval_other;
                yyflag = yyresolveAction (yyp, yystackp, &yysval_other, scanner, params);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yy_accessing_symbol (yys->yylrState),
                                &yysval, scanner, params);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yysval, scanner, params);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yysval = yysval;
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

static void
yycompressStack (yyGLRStack* yystackp)
{
  yyGLRState* yyp, *yyq, *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
       yyp != yystackp->yysplitPoint;
       yyr = yyp, yyp = yyq, yyq = yyp->yypred)
    yyp->yypred = yyr;

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
       action, or user semantic action that manipulated yychar.b4_lac_if([
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.], [
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.])
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

#define YYCHK1(YYE)                                                          \
  do {                                                                       \
    switch (YYE) {                                                           \
    case yyok:                                                               \
      break;                                                                 \
    case yyabort:                                                            \
      goto yyabortlab;                                                       \
    case yyaccept:                                                           \
      goto yyacceptlab;                                                      \
    case yyerr:                                                              \
      goto yyuser_error;                                                     \
    default:                                                                 \
      goto yybuglab;                                                         \
    }                                                                        \
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
{
    #ifdef YYDEBUG
    #if YYDEBUG == 1
    yydebug = 1;
    #endif
    #endif
}



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
              YY_DPRINTF ((stderr, "Stack %ld now in state #%d\n",
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
  goto yyreturn;

 yybuglab:
  YY_ASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturn;

 yyexhaustedlab:
  yyerror (scanner, params, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;

 yyreturn:
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

static void
yypstates (yyGLRState* yyst)
{
  if (yyst == YY_NULLPTR)
    YY_FPRINTF ((stderr, "<null>"));
  else
    yy_yypstack (yyst);
  YY_FPRINTF ((stderr, "\n"));
}

static void
yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

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
    params.funcs = new std::unordered_set<t_function*>;
    
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


