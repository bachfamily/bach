/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Skeleton interface for Bison GLR parsers in C

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

#ifndef YY_BISONPARSERV3_BISONPARSERV3_TAB_H_INCLUDED
# define YY_BISONPARSERV3_BISONPARSERV3_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int bisonparserV3_debug;
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
    LONG_LITERAL = 258,            /* LONG_LITERAL  */
    INLET = 259,                   /* INLET  */
    INTINLET = 260,                /* INTINLET  */
    RATINLET = 261,                /* RATINLET  */
    FLOATINLET = 262,              /* FLOATINLET  */
    PITCHINLET = 263,              /* PITCHINLET  */
    OUTLET = 264,                  /* OUTLET  */
    DIRINLET = 265,                /* DIRINLET  */
    DIROUTLET = 266,               /* DIROUTLET  */
    JIPITCHBASE_START = 267,       /* JIPITCHBASE_START  */
    JIPITCHBASE_END = 268,         /* JIPITCHBASE_END  */
    RAT_LITERAL = 269,             /* RAT_LITERAL  */
    DOUBLE_LITERAL = 270,          /* DOUBLE_LITERAL  */
    PITCH_LITERAL = 271,           /* PITCH_LITERAL  */
    SYMBOL_LITERAL = 272,          /* SYMBOL_LITERAL  */
    GLOBALVAR = 273,               /* GLOBALVAR  */
    PATCHERVAR = 274,              /* PATCHERVAR  */
    LOCALVAR = 275,                /* LOCALVAR  */
    NAMEDPARAM = 276,              /* NAMEDPARAM  */
    BIF = 277,                     /* BIF  */
    OF = 278,                      /* OF  */
    MAXFUNCTION = 279,             /* MAXFUNCTION  */
    NULLIFY = 280,                 /* NULLIFY  */
    IF_KW = 281,                   /* IF_KW  */
    THEN_KW = 282,                 /* THEN_KW  */
    ELSE_KW = 283,                 /* ELSE_KW  */
    WHILE_KW = 284,                /* WHILE_KW  */
    DO_KW = 285,                   /* DO_KW  */
    FOR_KW = 286,                  /* FOR_KW  */
    IN_KW = 287,                   /* IN_KW  */
    COLLECT_KW = 288,              /* COLLECT_KW  */
    ASSIGN = 289,                  /* ASSIGN  */
    PLUS = 290,                    /* PLUS  */
    MINUS = 291,                   /* MINUS  */
    TIMES = 292,                   /* TIMES  */
    DIV = 293,                     /* DIV  */
    DIVDIV = 294,                  /* DIVDIV  */
    APLUS = 295,                   /* APLUS  */
    LOGOR = 296,                   /* LOGOR  */
    LOGAND = 297,                  /* LOGAND  */
    LOGOREXT = 298,                /* LOGOREXT  */
    LOGANDEXT = 299,               /* LOGANDEXT  */
    EQUAL = 300,                   /* EQUAL  */
    LT = 301,                      /* LT  */
    GT = 302,                      /* GT  */
    LEQ = 303,                     /* LEQ  */
    GEQ = 304,                     /* GEQ  */
    NEQ = 305,                     /* NEQ  */
    OPEN = 306,                    /* OPEN  */
    CLOSEDROUND = 307,             /* CLOSEDROUND  */
    FUNDEF = 308,                  /* FUNDEF  */
    EMPTYFUNARGLIST = 309,         /* EMPTYFUNARGLIST  */
    PUSH = 310,                    /* PUSH  */
    POP = 311,                     /* POP  */
    STARTPARAMS = 312,             /* STARTPARAMS  */
    COMMA = 313,                   /* COMMA  */
    ELLIPSIS = 314,                /* ELLIPSIS  */
    BACHNULL = 315,                /* BACHNULL  */
    BACHNIL = 316,                 /* BACHNIL  */
    ARGCOUNT = 317,                /* ARGCOUNT  */
    EOL = 318,                     /* EOL  */
    UNRECOGNIZED = 319,            /* UNRECOGNIZED  */
    LIFT = 320,                    /* LIFT  */
    AMINUS = 321,                  /* AMINUS  */
    ATIMES = 322,                  /* ATIMES  */
    APOWOP = 323,                  /* APOWOP  */
    ADIV = 324,                    /* ADIV  */
    ADIVDIV = 325,                 /* ADIVDIV  */
    AREM = 326,                    /* AREM  */
    ABITAND = 327,                 /* ABITAND  */
    ABITXOR = 328,                 /* ABITXOR  */
    ABITOR = 329,                  /* ABITOR  */
    ALSHIFT = 330,                 /* ALSHIFT  */
    ARSHIFT = 331,                 /* ARSHIFT  */
    ALOGAND = 332,                 /* ALOGAND  */
    ALOGANDEXT = 333,              /* ALOGANDEXT  */
    ALOGXOR = 334,                 /* ALOGXOR  */
    ALOGOR = 335,                  /* ALOGOR  */
    ALOGOREXT = 336,               /* ALOGOREXT  */
    ANTHOP = 337,                  /* ANTHOP  */
    AAPPLY = 338,                  /* AAPPLY  */
    ACONCAT = 339,                 /* ACONCAT  */
    ARCONCAT = 340,                /* ARCONCAT  */
    CONCAT = 341,                  /* CONCAT  */
    LOGXOR = 342,                  /* LOGXOR  */
    BITOR = 343,                   /* BITOR  */
    BITXOR = 344,                  /* BITXOR  */
    BITAND = 345,                  /* BITAND  */
    REPEAT = 346,                  /* REPEAT  */
    RANGE = 347,                   /* RANGE  */
    LSHIFT = 348,                  /* LSHIFT  */
    RSHIFT = 349,                  /* RSHIFT  */
    R = 350,                       /* R  */
    T = 351,                       /* T  */
    REM = 352,                     /* REM  */
    UPLUS = 353,                   /* UPLUS  */
    UMINUS = 354,                  /* UMINUS  */
    POWOP = 355,                   /* POWOP  */
    NTHOP = 356,                   /* NTHOP  */
    PICKOP = 357,                  /* PICKOP  */
    APPLY = 358,                   /* APPLY  */
    ACCESS_UNWRAP = 359,           /* ACCESS_UNWRAP  */
    LVALUESTEPPARAMS = 360,        /* LVALUESTEPPARAMS  */
    AS_KW = 361,                   /* AS_KW  */
    WITH_KW = 362,                 /* WITH_KW  */
    LOGNOT = 363,                  /* LOGNOT  */
    BITNOT = 364,                  /* BITNOT  */
    KEEP = 365,                    /* KEEP  */
    UNKEEP = 366,                  /* UNKEEP  */
    INIT = 367                     /* INIT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{

    astNode *astNodeValue;
    astFunctionCall *astFunctionCallValue;
    astLocalVar *astLocalVarValue;
    astPatcherVar *astPatcherVarValue;
    astGlobalVar *astGlobalVarValue;
    astVar *astVarValue;

    std::vector<funArg*> *funArgVector;
    std::vector<forArg*> *forArgVector;
    std::vector<t_localVar*> *localVarVector;
    std::vector<astNode*> *astNodeVector;
    std::vector<symNodePair*> *symNodePairVector;
    std::vector<int8_t> *int8Vector;
    
    lvalueStepList *lvalueStepListValue;
    symNodePair *symNodePairValue;
    forArg *forArgValue;
    funArg *funArgValue;
    lvalue *lvalueValue;
    fakeLvalue *fakeLvalueValue;
    lvalueSpecs *lvalueSpecsValue;
    
    long longValue;
    t_rational ratValue;
    double doubleValue;
    t_pitch pitchValue;
    t_symbol *symValue;
    char *textValue;


};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int bisonparserV3_parse (void *scanner, struct _parseParams *params);

#endif /* !YY_BISONPARSERV3_BISONPARSERV3_TAB_H_INCLUDED  */
