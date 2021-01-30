/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Skeleton interface for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    LONG_LITERAL = 258,
    INLET = 259,
    INTINLET = 260,
    RATINLET = 261,
    FLOATINLET = 262,
    PITCHINLET = 263,
    OUTLET = 264,
    DIRINLET = 265,
    DIROUTLET = 266,
    RAT_LITERAL = 267,
    DOUBLE_LITERAL = 268,
    PITCH_LITERAL = 269,
    SYMBOL_LITERAL = 270,
    GLOBALVAR = 271,
    PATCHERVAR = 272,
    LOCALVAR = 273,
    OBJECTVAR = 274,
    NAMEDPARAM = 275,
    BIF = 276,
    OF = 277,
    SEQ = 278,
    IF_KW = 279,
    THEN_KW = 280,
    ELSE_KW = 281,
    WHILE_KW = 282,
    DO_KW = 283,
    FOR_KW = 284,
    IN_KW = 285,
    COLLECT_KW = 286,
    ASSIGN = 287,
    PLUS = 288,
    MINUS = 289,
    TIMES = 290,
    DIV = 291,
    DIVDIV = 292,
    APLUS = 293,
    LOGOR = 294,
    LOGAND = 295,
    LOGOREXT = 296,
    LOGANDEXT = 297,
    EQUAL = 298,
    LT = 299,
    GT = 300,
    LEQ = 301,
    GEQ = 302,
    NEQ = 303,
    OPEN = 304,
    CLOSEDROUND = 305,
    FUNDEF = 306,
    PUSH = 307,
    POP = 308,
    STARTPARAMS = 309,
    COMMA = 310,
    ELLIPSIS = 311,
    BACHNULL = 312,
    BACHNIL = 313,
    ARGCOUNT = 314,
    EOL = 315,
    UNRECOGNIZED = 316,
    LIFT = 317,
    AMINUS = 318,
    ATIMES = 319,
    APOWOP = 320,
    ADIV = 321,
    ADIVDIV = 322,
    AREM = 323,
    ABITAND = 324,
    ABITXOR = 325,
    ABITOR = 326,
    ALSHIFT = 327,
    ARSHIFT = 328,
    ALOGAND = 329,
    ALOGANDEXT = 330,
    ALOGXOR = 331,
    ALOGOR = 332,
    ALOGOREXT = 333,
    ANTHOP = 334,
    AAPPLY = 335,
    ACONCAT = 336,
    ARCONCAT = 337,
    CONCAT = 338,
    LOGXOR = 339,
    BITOR = 340,
    BITXOR = 341,
    BITAND = 342,
    REPEAT = 343,
    RANGE = 344,
    LSHIFT = 345,
    RSHIFT = 346,
    REM = 347,
    UPLUS = 348,
    UMINUS = 349,
    POWOP = 350,
    NTHOP = 351,
    PICKOP = 352,
    APPLY = 353,
    ACCESS_UNWRAP = 354,
    LVALUESTEPPARAMS = 355,
    AS_KW = 356,
    WITH_KW = 357,
    LOGNOT = 358,
    BITNOT = 359,
    KEEP = 360,
    UNKEEP = 361,
    INIT = 362
  };
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
    astObjectVar *ov;
    astVar *var;
    
    countedList<astNode *> *nl;
    countedList<symNodePair *> *snpl;
    countedList<funArg *> *funarglist;
    countedList<t_symbol *> *liftedarglist;
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
