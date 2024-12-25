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
    RAT_LITERAL = 267,             /* RAT_LITERAL  */
    DOUBLE_LITERAL = 268,          /* DOUBLE_LITERAL  */
    PITCH_LITERAL = 269,           /* PITCH_LITERAL  */
    SYMBOL_LITERAL = 270,          /* SYMBOL_LITERAL  */
    GLOBALVAR = 271,               /* GLOBALVAR  */
    PATCHERVAR = 272,              /* PATCHERVAR  */
    LOCALVAR = 273,                /* LOCALVAR  */
    NAMEDPARAM = 274,              /* NAMEDPARAM  */
    BIF = 275,                     /* BIF  */
    OF = 276,                      /* OF  */
    MAXFUNCTION = 277,             /* MAXFUNCTION  */
    NULLIFY = 278,                 /* NULLIFY  */
    IF_KW = 279,                   /* IF_KW  */
    THEN_KW = 280,                 /* THEN_KW  */
    ELSE_KW = 281,                 /* ELSE_KW  */
    WHILE_KW = 282,                /* WHILE_KW  */
    DO_KW = 283,                   /* DO_KW  */
    FOR_KW = 284,                  /* FOR_KW  */
    IN_KW = 285,                   /* IN_KW  */
    COLLECT_KW = 286,              /* COLLECT_KW  */
    ASSIGN = 287,                  /* ASSIGN  */
    PLUS = 288,                    /* PLUS  */
    MINUS = 289,                   /* MINUS  */
    TIMES = 290,                   /* TIMES  */
    DIV = 291,                     /* DIV  */
    DIVDIV = 292,                  /* DIVDIV  */
    APLUS = 293,                   /* APLUS  */
    LOGOR = 294,                   /* LOGOR  */
    LOGAND = 295,                  /* LOGAND  */
    LOGOREXT = 296,                /* LOGOREXT  */
    LOGANDEXT = 297,               /* LOGANDEXT  */
    EQUAL = 298,                   /* EQUAL  */
    LT = 299,                      /* LT  */
    GT = 300,                      /* GT  */
    LEQ = 301,                     /* LEQ  */
    GEQ = 302,                     /* GEQ  */
    NEQ = 303,                     /* NEQ  */
    OPEN = 304,                    /* OPEN  */
    CLOSEDROUND = 305,             /* CLOSEDROUND  */
    FUNDEF = 306,                  /* FUNDEF  */
    EMPTYFUNARGLIST = 307,         /* EMPTYFUNARGLIST  */
    PUSH = 308,                    /* PUSH  */
    POP = 309,                     /* POP  */
    STARTPARAMS = 310,             /* STARTPARAMS  */
    COMMA = 311,                   /* COMMA  */
    ELLIPSIS = 312,                /* ELLIPSIS  */
    BACHNULL = 313,                /* BACHNULL  */
    BACHNIL = 314,                 /* BACHNIL  */
    ARGCOUNT = 315,                /* ARGCOUNT  */
    EOL = 316,                     /* EOL  */
    UNRECOGNIZED = 317,            /* UNRECOGNIZED  */
    LIFT = 318,                    /* LIFT  */
    AMINUS = 319,                  /* AMINUS  */
    ATIMES = 320,                  /* ATIMES  */
    APOWOP = 321,                  /* APOWOP  */
    ADIV = 322,                    /* ADIV  */
    ADIVDIV = 323,                 /* ADIVDIV  */
    AREM = 324,                    /* AREM  */
    ABITAND = 325,                 /* ABITAND  */
    ABITXOR = 326,                 /* ABITXOR  */
    ABITOR = 327,                  /* ABITOR  */
    ALSHIFT = 328,                 /* ALSHIFT  */
    ARSHIFT = 329,                 /* ARSHIFT  */
    ALOGAND = 330,                 /* ALOGAND  */
    ALOGANDEXT = 331,              /* ALOGANDEXT  */
    ALOGXOR = 332,                 /* ALOGXOR  */
    ALOGOR = 333,                  /* ALOGOR  */
    ALOGOREXT = 334,               /* ALOGOREXT  */
    ANTHOP = 335,                  /* ANTHOP  */
    AAPPLY = 336,                  /* AAPPLY  */
    ACONCAT = 337,                 /* ACONCAT  */
    ARCONCAT = 338,                /* ARCONCAT  */
    CONCAT = 339,                  /* CONCAT  */
    LOGXOR = 340,                  /* LOGXOR  */
    BITOR = 341,                   /* BITOR  */
    BITXOR = 342,                  /* BITXOR  */
    BITAND = 343,                  /* BITAND  */
    REPEAT = 344,                  /* REPEAT  */
    RANGE = 345,                   /* RANGE  */
    LSHIFT = 346,                  /* LSHIFT  */
    RSHIFT = 347,                  /* RSHIFT  */
    REM = 348,                     /* REM  */
    UPLUS = 349,                   /* UPLUS  */
    UMINUS = 350,                  /* UMINUS  */
    POWOP = 351,                   /* POWOP  */
    NTHOP = 352,                   /* NTHOP  */
    PICKOP = 353,                  /* PICKOP  */
    APPLY = 354,                   /* APPLY  */
    ACCESS_UNWRAP = 355,           /* ACCESS_UNWRAP  */
    LVALUESTEPPARAMS = 356,        /* LVALUESTEPPARAMS  */
    AS_KW = 357,                   /* AS_KW  */
    WITH_KW = 358,                 /* WITH_KW  */
    LOGNOT = 359,                  /* LOGNOT  */
    BITNOT = 360,                  /* BITNOT  */
    KEEP = 361,                    /* KEEP  */
    UNKEEP = 362,                  /* UNKEEP  */
    INIT = 363                     /* INIT  */
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
