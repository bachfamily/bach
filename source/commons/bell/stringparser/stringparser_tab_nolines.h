/* A Bison parser, made by GNU Bison 3.4.2.  */

/* Skeleton interface for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

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
    NAMEDPARAM = 274,
    BIF = 275,
    OF = 276,
    SEQ = 277,
    IF_KW = 278,
    THEN_KW = 279,
    ELSE_KW = 280,
    WHILE_KW = 281,
    DO_KW = 282,
    FOR_KW = 283,
    IN_KW = 284,
    COLLECT_KW = 285,
    ASSIGN = 286,
    PLUS = 287,
    MINUS = 288,
    TIMES = 289,
    DIV = 290,
    DIVDIV = 291,
    APLUS = 292,
    LOGOR = 293,
    LOGAND = 294,
    LOGOREXT = 295,
    LOGANDEXT = 296,
    EQUAL = 297,
    LT = 298,
    GT = 299,
    LEQ = 300,
    GEQ = 301,
    NEQ = 302,
    OPEN = 303,
    CLOSEDROUND = 304,
    FUNDEF = 305,
    PUSH = 306,
    POP = 307,
    STARTPARAMS = 308,
    COMMA = 309,
    ELLIPSIS = 310,
    BACHNULL = 311,
    BACHNIL = 312,
    ARGCOUNT = 313,
    EOL = 314,
    UNRECOGNIZED = 315,
    LIFT = 316,
    AMINUS = 317,
    ATIMES = 318,
    APOWOP = 319,
    ADIV = 320,
    ADIVDIV = 321,
    AREM = 322,
    ABITAND = 323,
    ABITXOR = 324,
    ABITOR = 325,
    ALSHIFT = 326,
    ARSHIFT = 327,
    ALOGAND = 328,
    ALOGANDEXT = 329,
    ALOGXOR = 330,
    ALOGOR = 331,
    ALOGOREXT = 332,
    ANTHOP = 333,
    AAPPLY = 334,
    ACONCAT = 335,
    ARCONCAT = 336,
    CONCAT = 337,
    LOGXOR = 338,
    BITOR = 339,
    BITXOR = 340,
    BITAND = 341,
    RANGE = 342,
    LSHIFT = 343,
    RSHIFT = 344,
    REM = 345,
    NTHOP = 346,
    PICKOP = 347,
    APPLY = 348,
    ACCESS_UNWRAP = 349,
    LVALUESTEPPARAMS = 350,
    AS_KW = 351,
    WITH_KW = 352,
    UPLUS = 353,
    LOGNOT = 354,
    BITNOT = 355,
    UMINUS = 356,
    POWOP = 357,
    KEEP = 358,
    UNKEEP = 359,
    INIT = 360
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
