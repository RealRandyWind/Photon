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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TFUNCTION = 258,
    TBOOL = 259,
    TNOT = 260,
    TPARENTHESISOPEN = 261,
    TPARENTHESISCLOSE = 262,
    TBRACKETCLOSE = 263,
    TBRACKETOPEN = 264,
    TCOLON = 265,
    TCOMMA = 266,
    TDOT = 267,
    TLINE = 268,
    TBLANK = 269,
    TADD = 270,
    TMUL = 271,
    TREL = 272,
    TIDENTIFIER = 273,
    TNUMBER = 274,
    TEOF = 275
  };
#endif
/* Tokens.  */
#define TFUNCTION 258
#define TBOOL 259
#define TNOT 260
#define TPARENTHESISOPEN 261
#define TPARENTHESISCLOSE 262
#define TBRACKETCLOSE 263
#define TBRACKETOPEN 264
#define TCOLON 265
#define TCOMMA 266
#define TDOT 267
#define TLINE 268
#define TBLANK 269
#define TADD 270
#define TMUL 271
#define TREL 272
#define TIDENTIFIER 273
#define TNUMBER 274
#define TEOF 275

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
