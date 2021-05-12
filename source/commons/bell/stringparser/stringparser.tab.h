/* A Bison parser, made by GNU Bison 3.7.6.  */

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

#ifndef YY_STRINGPARSER_STRINGPARSER_TAB_H_INCLUDED
# define YY_STRINGPARSER_STRINGPARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int stringparser_debug;
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
    SEQ = 277,                     /* SEQ  */
    IF_KW = 278,                   /* IF_KW  */
    THEN_KW = 279,                 /* THEN_KW  */
    ELSE_KW = 280,                 /* ELSE_KW  */
    WHILE_KW = 281,                /* WHILE_KW  */
    DO_KW = 282,                   /* DO_KW  */
    FOR_KW = 283,                  /* FOR_KW  */
    IN_KW = 284,                   /* IN_KW  */
    COLLECT_KW = 285,              /* COLLECT_KW  */
    ASSIGN = 286,                  /* ASSIGN  */
    PLUS = 287,                    /* PLUS  */
    MINUS = 288,                   /* MINUS  */
    TIMES = 289,                   /* TIMES  */
    DIV = 290,                     /* DIV  */
    DIVDIV = 291,                  /* DIVDIV  */
    APLUS = 292,                   /* APLUS  */
    LOGOR = 293,                   /* LOGOR  */
    LOGAND = 294,                  /* LOGAND  */
    LOGOREXT = 295,                /* LOGOREXT  */
    LOGANDEXT = 296,               /* LOGANDEXT  */
    EQUAL = 297,                   /* EQUAL  */
    LT = 298,                      /* LT  */
    GT = 299,                      /* GT  */
    LEQ = 300,                     /* LEQ  */
    GEQ = 301,                     /* GEQ  */
    NEQ = 302,                     /* NEQ  */
    OPEN = 303,                    /* OPEN  */
    CLOSEDROUND = 304,             /* CLOSEDROUND  */
    FUNDEF = 305,                  /* FUNDEF  */
    PUSH = 306,                    /* PUSH  */
    POP = 307,                     /* POP  */
    STARTPARAMS = 308,             /* STARTPARAMS  */
    COMMA = 309,                   /* COMMA  */
    ELLIPSIS = 310,                /* ELLIPSIS  */
    BACHNULL = 311,                /* BACHNULL  */
    BACHNIL = 312,                 /* BACHNIL  */
    ARGCOUNT = 313,                /* ARGCOUNT  */
    EOL = 314,                     /* EOL  */
    UNRECOGNIZED = 315,            /* UNRECOGNIZED  */
    LIFT = 316,                    /* LIFT  */
    AMINUS = 317,                  /* AMINUS  */
    ATIMES = 318,                  /* ATIMES  */
    APOWOP = 319,                  /* APOWOP  */
    ADIV = 320,                    /* ADIV  */
    ADIVDIV = 321,                 /* ADIVDIV  */
    AREM = 322,                    /* AREM  */
    ABITAND = 323,                 /* ABITAND  */
    ABITXOR = 324,                 /* ABITXOR  */
    ABITOR = 325,                  /* ABITOR  */
    ALSHIFT = 326,                 /* ALSHIFT  */
    ARSHIFT = 327,                 /* ARSHIFT  */
    ALOGAND = 328,                 /* ALOGAND  */
    ALOGANDEXT = 329,              /* ALOGANDEXT  */
    ALOGXOR = 330,                 /* ALOGXOR  */
    ALOGOR = 331,                  /* ALOGOR  */
    ALOGOREXT = 332,               /* ALOGOREXT  */
    ANTHOP = 333,                  /* ANTHOP  */
    AAPPLY = 334,                  /* AAPPLY  */
    ACONCAT = 335,                 /* ACONCAT  */
    ARCONCAT = 336,                /* ARCONCAT  */
    CONCAT = 337,                  /* CONCAT  */
    LOGXOR = 338,                  /* LOGXOR  */
    BITOR = 339,                   /* BITOR  */
    BITXOR = 340,                  /* BITXOR  */
    BITAND = 341,                  /* BITAND  */
    REPEAT = 342,                  /* REPEAT  */
    RANGE = 343,                   /* RANGE  */
    LSHIFT = 344,                  /* LSHIFT  */
    RSHIFT = 345,                  /* RSHIFT  */
    REM = 346,                     /* REM  */
    UPLUS = 347,                   /* UPLUS  */
    UMINUS = 348,                  /* UMINUS  */
    POWOP = 349,                   /* POWOP  */
    NTHOP = 350,                   /* NTHOP  */
    PICKOP = 351,                  /* PICKOP  */
    APPLY = 352,                   /* APPLY  */
    ACCESS_UNWRAP = 353,           /* ACCESS_UNWRAP  */
    LVALUESTEPPARAMS = 354,        /* LVALUESTEPPARAMS  */
    AS_KW = 355,                   /* AS_KW  */
    WITH_KW = 356,                 /* WITH_KW  */
    LOGNOT = 357,                  /* LOGNOT  */
    BITNOT = 358,                  /* BITNOT  */
    KEEP = 359,                    /* KEEP  */
    UNKEEP = 360,                  /* UNKEEP  */
    INIT = 361                     /* INIT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{

    astNode *n;
    astFunctionCall *fc;
    astLocalVar *lv;
    astPatcherVar *pv;
    astGlobalVar *gv;
    astVar *var;
    
    countedList<astNode *> *nl;
    countedList<symNodePair *> *snpl;
    countedList<funArg *> *funarglist;
    countedList<t_localVar> *liftedarglist;
    countedList<forArg *> *fal;
    lvalueStepList *lvsl;
    symNodePair *snp;
    forArg *forarg;
    
    long l;
    t_rational r;
    double d;
    t_pitch p;
    t_symbol *sym;


};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int stringparser_parse (void *scanner, struct _parseParams *params);

#endif /* !YY_STRINGPARSER_STRINGPARSER_TAB_H_INCLUDED  */
