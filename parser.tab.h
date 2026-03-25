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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
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
    TOK_PROGRAM = 258,             /* TOK_PROGRAM  */
    TOK_DECL = 259,                /* TOK_DECL  */
    TOK_ENDDECL = 260,             /* TOK_ENDDECL  */
    TOK_BEGIN = 261,               /* TOK_BEGIN  */
    TOK_END = 262,                 /* TOK_END  */
    TOK_INTEGER = 263,             /* TOK_INTEGER  */
    TOK_FLOAT = 264,               /* TOK_FLOAT  */
    TOK_CONST = 265,               /* TOK_CONST  */
    TOK_IF = 266,                  /* TOK_IF  */
    TOK_ELSE = 267,                /* TOK_ELSE  */
    TOK_FOR = 268,                 /* TOK_FOR  */
    TOK_WHILE = 269,               /* TOK_WHILE  */
    TOK_WRITE = 270,               /* TOK_WRITE  */
    TOK_READ = 271,                /* TOK_READ  */
    TOK_GE = 272,                  /* TOK_GE  */
    TOK_LE = 273,                  /* TOK_LE  */
    TOK_EQ = 274,                  /* TOK_EQ  */
    TOK_NE = 275,                  /* TOK_NE  */
    TOK_GT = 276,                  /* TOK_GT  */
    TOK_LT = 277,                  /* TOK_LT  */
    TOK_AND = 278,                 /* TOK_AND  */
    TOK_OR = 279,                  /* TOK_OR  */
    TOK_NOT = 280,                 /* TOK_NOT  */
    TOK_ENTIER = 281,              /* TOK_ENTIER  */
    TOK_REEL = 282,                /* TOK_REEL  */
    TOK_IDF = 283,                 /* TOK_IDF  */
    UMINUS = 284                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 48 "parser.y"

    int        ival;
    float      rval;
    char       sval[9];
    TypeDonnee tval;
    char       temp[64];

#line 101 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
