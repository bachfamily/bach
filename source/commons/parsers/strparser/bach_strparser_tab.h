/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_STRPARSER_STRPARSER_TAB_H_INCLUDED
# define YY_STRPARSER_STRPARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef STRPARSER_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define STRPARSER_DEBUG 1
#  else
#   define STRPARSER_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define STRPARSER_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined STRPARSER_DEBUG */
#if STRPARSER_DEBUG
extern int strparser_debug;
#endif

/* Token kinds.  */
#ifndef STRPARSER_TOKENTYPE
# define STRPARSER_TOKENTYPE
  enum strparser_tokentype
  {
    STRPARSER_EMPTY = -2,
    STRPARSER_EOF = 0,             /* "end of file"  */
    STRPARSER_error = 256,         /* error  */
    STRPARSER_UNDEF = 257,         /* "invalid token"  */
    BACH_LONG = 258,               /* BACH_LONG  */
    BACH_DOUBLE = 259,             /* BACH_DOUBLE  */
    BACH_RAT = 260,                /* BACH_RAT  */
    BACH_PITCH = 261,              /* BACH_PITCH  */
    BACH_SYMBOL = 262,             /* BACH_SYMBOL  */
    BACH_PUSH = 263,               /* BACH_PUSH  */
    BACH_POP = 264,                /* BACH_POP  */
    BACH_NULL = 265,               /* BACH_NULL  */
    BACH_NIL = 266                 /* BACH_NIL  */
  };
  typedef enum strparser_tokentype strparser_token_kind_t;
#endif

/* Value type.  */
#if ! defined STRPARSER_STYPE && ! defined STRPARSER_STYPE_IS_DECLARED
union STRPARSER_STYPE
{

	long l;
	double d;
	t_rational r;
	t_pitch p;
	t_symbol *sym;


};
typedef union STRPARSER_STYPE STRPARSER_STYPE;
# define STRPARSER_STYPE_IS_TRIVIAL 1
# define STRPARSER_STYPE_IS_DECLARED 1
#endif




int strparser_parse (void *scanner, t_llll **ll, t_llll_stack *stack, long *depth);

/* "%code provides" blocks.  */

  // Tell Flex the expected prototype of yylex.
  #define YY_DECL                             \
    int strparser_lex (STRPARSER_STYPE *yylval, void* yyscanner)

    typedef STRPARSER_STYPE YYSTYPE;
  // Declare the scanner.
  YY_DECL;


#endif /* !YY_STRPARSER_STRPARSER_TAB_H_INCLUDED  */
