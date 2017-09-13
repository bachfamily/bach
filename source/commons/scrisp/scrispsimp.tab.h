/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_SCRISPSIMP_TAB_H_INCLUDED
# define YY_YY_SCRISPSIMP_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    INLET = 259,
    DOUBLE = 260,
    SYMBOL = 261,
    GLOBALVAR = 262,
    BIF1 = 263,
    SEQ = 264,
    IF = 265,
    THEN = 266,
    ELSE = 267,
    ASSIGN = 268,
    PLUS = 269,
    MINUS = 270,
    TIMES = 271,
    DIV = 272,
    LOGOR = 273,
    LOGAND = 274,
    LOGOREXT = 275,
    LOGANDEXT = 276,
    EQUAL = 277,
    LT = 278,
    GT = 279,
    LEQ = 280,
    GEQ = 281,
    NEQ = 282,
    OPEN = 283,
    CLOSED = 284,
    PUSH = 285,
    POP = 286,
    STARTPARAMS = 287,
    ENDPARAMS = 288,
    BACHNULL = 289,
    BACHNIL = 290,
    EOL = 291,
    UPLUS = 292,
    UMINUS = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "scrispsimp.y" /* yacc.c:1909  */

    struct _astNode *n;
    int i;
    double d;
    t_symbol *sym;
    char *str;
    method bif;

#line 102 "scrispsimp.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (t_astNode **ast, t_globalVarTable *gvt, long *maxvars);

#endif /* !YY_YY_SCRISPSIMP_TAB_H_INCLUDED  */
