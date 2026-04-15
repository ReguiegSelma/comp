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

#ifndef YY_YY_SYNTAXIQUE_TAB_H_INCLUDED
# define YY_YY_SYNTAXIQUE_TAB_H_INCLUDED
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
    IDF = 258,                     /* IDF  */
    INT_VAL = 259,                 /* INT_VAL  */
    FLOAT_VAL = 260,               /* FLOAT_VAL  */
    PROGRAM = 261,                 /* PROGRAM  */
    DECL = 262,                    /* DECL  */
    ENDDECL = 263,                 /* ENDDECL  */
    BEGIN_P = 264,                 /* BEGIN_P  */
    END = 265,                     /* END  */
    INTEGER = 266,                 /* INTEGER  */
    FLOAT = 267,                   /* FLOAT  */
    CONST = 268,                   /* CONST  */
    IF = 269,                      /* IF  */
    ELSE = 270,                    /* ELSE  */
    FOR = 271,                     /* FOR  */
    WHILE = 272,                   /* WHILE  */
    WRITE = 273,                   /* WRITE  */
    PLUS = 274,                    /* PLUS  */
    MOINS = 275,                   /* MOINS  */
    MULT = 276,                    /* MULT  */
    DIV = 277,                     /* DIV  */
    AFFECT = 278,                  /* AFFECT  */
    SUP = 279,                     /* SUP  */
    INF = 280,                     /* INF  */
    EGAL = 281,                    /* EGAL  */
    PV = 282,                      /* PV  */
    DEUXPTS = 283,                 /* DEUXPTS  */
    VIRG = 284,                    /* VIRG  */
    PARG = 285,                    /* PARG  */
    PARD = 286,                    /* PARD  */
    ACCOLG = 287,                  /* ACCOLG  */
    ACCOLD = 288,                  /* ACCOLD  */
    CROCHG = 289,                  /* CROCHG  */
    CROCHD = 290,                  /* CROCHD  */
    AND = 291,                     /* AND  */
    OR = 292,                      /* OR  */
    NOT = 293,                     /* NOT  */
    LOWER_THAN_ELSE = 294          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "syntaxique.y"
 
    char* str;
    int integer;
    float float_val;

#line 109 "syntaxique.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SYNTAXIQUE_TAB_H_INCLUDED  */
