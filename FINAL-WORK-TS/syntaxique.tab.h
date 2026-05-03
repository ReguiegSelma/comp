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
    ENT_SIGNE = 261,               /* ENT_SIGNE  */
    REEL_SIGNE = 262,              /* REEL_SIGNE  */
    PROGRAM = 263,                 /* PROGRAM  */
    DECL = 264,                    /* DECL  */
    ENDDECL = 265,                 /* ENDDECL  */
    BEGIN_P = 266,                 /* BEGIN_P  */
    END = 267,                     /* END  */
    INTEGER = 268,                 /* INTEGER  */
    FLOAT = 269,                   /* FLOAT  */
    CONST = 270,                   /* CONST  */
    IF = 271,                      /* IF  */
    ELSE = 272,                    /* ELSE  */
    FOR = 273,                     /* FOR  */
    WHILE = 274,                   /* WHILE  */
    WRITE = 275,                   /* WRITE  */
    PLUS = 276,                    /* PLUS  */
    MOINS = 277,                   /* MOINS  */
    MULT = 278,                    /* MULT  */
    DIV = 279,                     /* DIV  */
    AFFECT = 280,                  /* AFFECT  */
    SUP = 281,                     /* SUP  */
    INF = 282,                     /* INF  */
    EGAL = 283,                    /* EGAL  */
    SUPEG = 284,                   /* SUPEG  */
    INFEG = 285,                   /* INFEG  */
    DIFF = 286,                    /* DIFF  */
    PV = 287,                      /* PV  */
    DEUXPTS = 288,                 /* DEUXPTS  */
    VIRG = 289,                    /* VIRG  */
    PARG = 290,                    /* PARG  */
    PARD = 291,                    /* PARD  */
    ACCOLG = 292,                  /* ACCOLG  */
    ACCOLD = 293,                  /* ACCOLD  */
    CROCHG = 294,                  /* CROCHG  */
    CROCHD = 295,                  /* CROCHD  */
    AND = 296,                     /* AND  */
    OR = 297,                      /* OR  */
    NOT = 298,                     /* NOT  */
    LOWER_THAN_ELSE = 299          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "syntaxique.y"

    int entier;
    float reel;
    char* str;

#line 114 "syntaxique.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SYNTAXIQUE_TAB_H_INCLUDED  */
