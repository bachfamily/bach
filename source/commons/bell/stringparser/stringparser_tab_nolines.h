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
    MAXFUNCTION = 277,             /* MAXFUNCTION  */
    SEQ = 278,                     /* SEQ  */
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
    PUSH = 307,                    /* PUSH  */
    POP = 308,                     /* POP  */
    STARTPARAMS = 309,             /* STARTPARAMS  */
    COMMA = 310,                   /* COMMA  */
    ELLIPSIS = 311,                /* ELLIPSIS  */
    BACHNULL = 312,                /* BACHNULL  */
    BACHNIL = 313,                 /* BACHNIL  */
    ARGCOUNT = 314,                /* ARGCOUNT  */
    EOL = 315,                     /* EOL  */
    UNRECOGNIZED = 316,            /* UNRECOGNIZED  */
    LIFT = 317,                    /* LIFT  */
    AMINUS = 318,                  /* AMINUS  */
    ATIMES = 319,                  /* ATIMES  */
    APOWOP = 320,                  /* APOWOP  */
    ADIV = 321,                    /* ADIV  */
    ADIVDIV = 322,                 /* ADIVDIV  */
    AREM = 323,                    /* AREM  */
    ABITAND = 324,                 /* ABITAND  */
    ABITXOR = 325,                 /* ABITXOR  */
    ABITOR = 326,                  /* ABITOR  */
    ALSHIFT = 327,                 /* ALSHIFT  */
    ARSHIFT = 328,                 /* ARSHIFT  */
    ALOGAND = 329,                 /* ALOGAND  */
    ALOGANDEXT = 330,              /* ALOGANDEXT  */
    ALOGXOR = 331,                 /* ALOGXOR  */
    ALOGOR = 332,                  /* ALOGOR  */
    ALOGOREXT = 333,               /* ALOGOREXT  */
    ANTHOP = 334,                  /* ANTHOP  */
    AAPPLY = 335,                  /* AAPPLY  */
    ACONCAT = 336,                 /* ACONCAT  */
    ARCONCAT = 337,                /* ARCONCAT  */
    CONCAT = 338,                  /* CONCAT  */
    LOGXOR = 339,                  /* LOGXOR  */
    BITOR = 340,                   /* BITOR  */
    BITXOR = 341,                  /* BITXOR  */
    BITAND = 342,                  /* BITAND  */
    REPEAT = 343,                  /* REPEAT  */
    RANGE = 344,                   /* RANGE  */
    LSHIFT = 345,                  /* LSHIFT  */
    RSHIFT = 346,                  /* RSHIFT  */
    REM = 347,                     /* REM  */
    UPLUS = 348,                   /* UPLUS  */
    UMINUS = 349,                  /* UMINUS  */
    POWOP = 350,                   /* POWOP  */
    NTHOP = 351,                   /* NTHOP  */
    PICKOP = 352,                  /* PICKOP  */
    APPLY = 353,                   /* APPLY  */
    ACCESS_UNWRAP = 354,           /* ACCESS_UNWRAP  */
    LVALUESTEPPARAMS = 355,        /* LVALUESTEPPARAMS  */
    AS_KW = 356,                   /* AS_KW  */
    WITH_KW = 357,                 /* WITH_KW  */
    LOGNOT = 358,                  /* LOGNOT  */
    BITNOT = 359,                  /* BITNOT  */
    KEEP = 360,                    /* KEEP  */
    UNKEEP = 361,                  /* UNKEEP  */
    INIT = 362                     /* INIT  */
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
    char *text;


};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int stringparser_parse (void *scanner, struct _parseParams *params);

#endif /* !YY_STRINGPARSER_STRINGPARSER_TAB_H_INCLUDED  */
