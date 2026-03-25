/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 9 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtable.h"
#include "quadruplets.h"
#include "optimiseur.h"
#include "codegen86.h"

extern int  yylex(void);
extern int  line_num;
extern int  col_num;
extern char *yytext;

int nb_erreurs = 0;
TypeDonnee type_courant = TYPE_INCONNU;
static char nom_prog_global[MAX_ID_LEN + 1] = "prog";

void erreur_syntaxique(const char *msg) {
    fprintf(stderr, "Erreur Syntaxique : ligne %d , colonne %d , element \"%s\" -- %s\n",
            line_num, col_num, yytext, msg);
    nb_erreurs++;
}

void erreur_semantique(int ligne, const char *nom, const char *msg) {
    fprintf(stderr, "Erreur Semantique : ligne %d , element \"%s\" -- %s\n",
            ligne, nom, msg);
    nb_erreurs++;
}

void yyerror(const char *s) { erreur_syntaxique(s); }

Symbole *verifier_declare(const char *nom, int ligne) {
    Symbole *s = ts_rechercher(nom);
    if (!s) erreur_semantique(ligne, nom, "variable non declaree");
    return s;
}

#line 110 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOK_PROGRAM = 3,                /* TOK_PROGRAM  */
  YYSYMBOL_TOK_DECL = 4,                   /* TOK_DECL  */
  YYSYMBOL_TOK_ENDDECL = 5,                /* TOK_ENDDECL  */
  YYSYMBOL_TOK_BEGIN = 6,                  /* TOK_BEGIN  */
  YYSYMBOL_TOK_END = 7,                    /* TOK_END  */
  YYSYMBOL_TOK_INTEGER = 8,                /* TOK_INTEGER  */
  YYSYMBOL_TOK_FLOAT = 9,                  /* TOK_FLOAT  */
  YYSYMBOL_TOK_CONST = 10,                 /* TOK_CONST  */
  YYSYMBOL_TOK_IF = 11,                    /* TOK_IF  */
  YYSYMBOL_TOK_ELSE = 12,                  /* TOK_ELSE  */
  YYSYMBOL_TOK_FOR = 13,                   /* TOK_FOR  */
  YYSYMBOL_TOK_WHILE = 14,                 /* TOK_WHILE  */
  YYSYMBOL_TOK_WRITE = 15,                 /* TOK_WRITE  */
  YYSYMBOL_TOK_READ = 16,                  /* TOK_READ  */
  YYSYMBOL_TOK_GE = 17,                    /* TOK_GE  */
  YYSYMBOL_TOK_LE = 18,                    /* TOK_LE  */
  YYSYMBOL_TOK_EQ = 19,                    /* TOK_EQ  */
  YYSYMBOL_TOK_NE = 20,                    /* TOK_NE  */
  YYSYMBOL_TOK_GT = 21,                    /* TOK_GT  */
  YYSYMBOL_TOK_LT = 22,                    /* TOK_LT  */
  YYSYMBOL_TOK_AND = 23,                   /* TOK_AND  */
  YYSYMBOL_TOK_OR = 24,                    /* TOK_OR  */
  YYSYMBOL_TOK_NOT = 25,                   /* TOK_NOT  */
  YYSYMBOL_TOK_ENTIER = 26,                /* TOK_ENTIER  */
  YYSYMBOL_TOK_REEL = 27,                  /* TOK_REEL  */
  YYSYMBOL_TOK_IDF = 28,                   /* TOK_IDF  */
  YYSYMBOL_29_ = 29,                       /* '+'  */
  YYSYMBOL_30_ = 30,                       /* '-'  */
  YYSYMBOL_31_ = 31,                       /* '*'  */
  YYSYMBOL_32_ = 32,                       /* '/'  */
  YYSYMBOL_UMINUS = 33,                    /* UMINUS  */
  YYSYMBOL_34_ = 34,                       /* ':'  */
  YYSYMBOL_35_ = 35,                       /* ';'  */
  YYSYMBOL_36_ = 36,                       /* '['  */
  YYSYMBOL_37_ = 37,                       /* ']'  */
  YYSYMBOL_38_ = 38,                       /* '='  */
  YYSYMBOL_39_ = 39,                       /* ','  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* '{'  */
  YYSYMBOL_43_ = 43,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_programme = 45,                 /* programme  */
  YYSYMBOL_nom_programme = 46,             /* nom_programme  */
  YYSYMBOL_declarations = 47,              /* declarations  */
  YYSYMBOL_declaration = 48,               /* declaration  */
  YYSYMBOL_decl_variable = 49,             /* decl_variable  */
  YYSYMBOL_decl_tableau = 50,              /* decl_tableau  */
  YYSYMBOL_decl_constante = 51,            /* decl_constante  */
  YYSYMBOL_type_simple = 52,               /* type_simple  */
  YYSYMBOL_liste_idf = 53,                 /* liste_idf  */
  YYSYMBOL_instructions = 54,              /* instructions  */
  YYSYMBOL_instruction = 55,               /* instruction  */
  YYSYMBOL_affectation = 56,               /* affectation  */
  YYSYMBOL_condition = 57,                 /* condition  */
  YYSYMBOL_mark_ifz = 58,                  /* mark_ifz  */
  YYSYMBOL_partie_else_ci = 59,            /* partie_else_ci  */
  YYSYMBOL_60_1 = 60,                      /* @1  */
  YYSYMBOL_boucle_for = 61,                /* boucle_for  */
  YYSYMBOL_62_2 = 62,                      /* @2  */
  YYSYMBOL_boucle_while = 63,              /* boucle_while  */
  YYSYMBOL_64_3 = 64,                      /* @3  */
  YYSYMBOL_65_4 = 65,                      /* @4  */
  YYSYMBOL_instr_write = 66,               /* instr_write  */
  YYSYMBOL_instr_read = 67,                /* instr_read  */
  YYSYMBOL_expression = 68                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   361

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  139

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,    41,    31,    29,    39,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    34,    35,
       2,    38,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,   116,   124,   125,   129,   130,   131,   135,
     139,   149,   158,   170,   171,   175,   180,   188,   189,   193,
     194,   195,   196,   197,   198,   203,   215,   241,   247,   259,
     275,   274,   311,   310,   357,   363,   356,   382,   388,   399,
     401,   403,   405,   413,   415,   417,   419,   427,   429,   431,
     433,   435,   437,   439,   441,   443,   452,   454,   456
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOK_PROGRAM",
  "TOK_DECL", "TOK_ENDDECL", "TOK_BEGIN", "TOK_END", "TOK_INTEGER",
  "TOK_FLOAT", "TOK_CONST", "TOK_IF", "TOK_ELSE", "TOK_FOR", "TOK_WHILE",
  "TOK_WRITE", "TOK_READ", "TOK_GE", "TOK_LE", "TOK_EQ", "TOK_NE",
  "TOK_GT", "TOK_LT", "TOK_AND", "TOK_OR", "TOK_NOT", "TOK_ENTIER",
  "TOK_REEL", "TOK_IDF", "'+'", "'-'", "'*'", "'/'", "UMINUS", "':'",
  "';'", "'['", "']'", "'='", "','", "'('", "')'", "'{'", "'}'", "$accept",
  "programme", "nom_programme", "declarations", "declaration",
  "decl_variable", "decl_tableau", "decl_constante", "type_simple",
  "liste_idf", "instructions", "instruction", "affectation", "condition",
  "mark_ifz", "partie_else_ci", "@1", "boucle_for", "@2", "boucle_while",
  "@3", "@4", "instr_write", "instr_read", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-115)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,    -5,    27,  -115,    42,  -115,  -115,     1,    47,  -115,
    -115,    20,  -115,  -115,  -115,  -115,    21,  -115,    16,    34,
     174,   -22,    30,   -20,  -115,    23,    25,  -115,    28,    31,
     -16,  -115,  -115,  -115,  -115,  -115,  -115,  -115,    39,    40,
      43,  -115,    48,   321,    49,    41,   321,    58,   321,   321,
    -115,  -115,    50,  -115,   321,  -115,  -115,    62,   321,   321,
     321,    72,    65,   321,    97,    59,   175,   217,    74,   307,
     321,  -115,  -115,   113,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,  -115,   321,   129,    75,
      87,    73,  -115,  -115,   196,  -115,    76,    76,   313,   313,
      76,    76,   307,   291,    -6,    -6,  -115,  -115,    81,   255,
    -115,  -115,  -115,   321,  -115,  -115,   321,    82,   236,    29,
     273,  -115,  -115,   127,   321,    36,  -115,  -115,   145,  -115,
      83,  -115,  -115,    98,    45,  -115,  -115,    69,  -115
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     3,     0,     1,     5,     0,     0,    13,
      14,     0,     4,     6,     7,     8,     0,    18,     0,     0,
       0,     0,    16,     0,     2,     0,     0,    34,     0,     0,
       0,    17,    19,    20,    21,    22,    23,    24,     0,     0,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    12,     0,    15,     0,    56,    57,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       0,    44,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,     0,     0,     0,
       0,     0,    25,    10,     0,    58,    49,    51,    52,    53,
      48,    50,    45,    46,    39,    40,    41,    42,     0,     0,
      35,    37,    38,     0,    55,    18,     0,     0,     0,     0,
       0,    18,    26,    29,     0,     0,    30,    27,     0,    36,
       0,    32,    18,     0,     0,    18,    31,     0,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
    -114,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,   -46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     4,     7,    12,    13,    14,    15,    16,    23,
      20,    31,    32,    33,   108,   127,   130,    34,   133,    35,
      45,   117,    36,    37,    61
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      64,   119,    66,    67,    38,    39,     8,   125,    69,     9,
      10,    11,    71,    72,    73,    41,     1,    88,   134,    42,
      48,   137,    49,     3,    94,    84,    85,     5,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
      25,   109,    26,    27,    28,    29,     6,    25,    18,    26,
      27,    28,    29,    17,    21,    19,    25,    30,    26,    27,
      28,    29,    22,    43,    30,    44,    40,   118,    46,    52,
     120,    47,   123,    30,    50,    51,    53,    62,   128,   129,
      25,    63,    26,    27,    28,    29,    65,    68,   136,    74,
      75,    76,    77,    78,    79,    80,    81,    30,    70,    87,
      90,    82,    83,    84,    85,    82,    83,    84,    85,    93,
     111,   113,   138,    86,    74,    75,    76,    77,    78,    79,
      80,    81,   112,   115,   121,   132,    82,    83,    84,    85,
      74,    75,    76,    77,    78,    79,    80,    81,    89,   126,
     135,     0,    82,    83,    84,    85,    74,    75,    76,    77,
      78,    79,    80,    81,    95,     0,     0,     0,    82,    83,
      84,    85,    74,    75,    76,    77,    78,    79,    80,    81,
     110,     0,     0,     0,    82,    83,    84,    85,     0,     0,
       0,    24,     0,     0,     0,    25,   131,    26,    27,    28,
      29,     0,    74,    75,    76,    77,    78,    79,    80,    81,
       0,     0,    30,     0,    82,    83,    84,    85,     0,     0,
       0,     0,    91,    74,    75,    76,    77,    78,    79,    80,
      81,     0,     0,     0,     0,    82,    83,    84,    85,     0,
       0,     0,     0,   114,    74,    75,    76,    77,    78,    79,
      80,    81,     0,     0,     0,     0,    82,    83,    84,    85,
       0,     0,    92,    74,    75,    76,    77,    78,    79,    80,
      81,     0,     0,     0,     0,    82,    83,    84,    85,     0,
       0,   122,    74,    75,    76,    77,    78,    79,    80,    81,
       0,     0,     0,     0,    82,    83,    84,    85,     0,   116,
      74,    75,    76,    77,    78,    79,    80,    81,     0,     0,
       0,     0,    82,    83,    84,    85,     0,   124,    74,    75,
      76,    77,    78,    79,    80,     0,     0,     0,     0,     0,
      82,    83,    84,    85,    74,    75,    76,    77,    78,    79,
      74,    75,     0,     0,    78,    79,    82,    83,    84,    85,
       0,     0,    82,    83,    84,    85,    54,    55,    56,    57,
      58,    59,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    60
};

static const yytype_int16 yycheck[] =
{
      46,   115,    48,    49,    26,    27,     5,   121,    54,     8,
       9,    10,    58,    59,    60,    35,     3,    63,   132,    39,
      36,   135,    38,    28,    70,    31,    32,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      11,    87,    13,    14,    15,    16,     4,    11,    28,    13,
      14,    15,    16,     6,    38,    34,    11,    28,    13,    14,
      15,    16,    28,    40,    28,    40,    36,   113,    40,    26,
     116,    40,    43,    28,    35,    35,    28,    28,   124,    43,
      11,    40,    13,    14,    15,    16,    28,    37,    43,    17,
      18,    19,    20,    21,    22,    23,    24,    28,    36,    34,
      41,    29,    30,    31,    32,    29,    30,    31,    32,    35,
      35,    38,    43,    41,    17,    18,    19,    20,    21,    22,
      23,    24,    35,    42,    42,    42,    29,    30,    31,    32,
      17,    18,    19,    20,    21,    22,    23,    24,    41,    12,
      42,    -1,    29,    30,    31,    32,    17,    18,    19,    20,
      21,    22,    23,    24,    41,    -1,    -1,    -1,    29,    30,
      31,    32,    17,    18,    19,    20,    21,    22,    23,    24,
      41,    -1,    -1,    -1,    29,    30,    31,    32,    -1,    -1,
      -1,     7,    -1,    -1,    -1,    11,    41,    13,    14,    15,
      16,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    28,    -1,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    37,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    37,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      -1,    -1,    35,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    -1,
      -1,    35,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    -1,    34,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    -1,    34,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    17,    18,    19,    20,    21,    22,
      17,    18,    -1,    -1,    21,    22,    29,    30,    31,    32,
      -1,    -1,    29,    30,    31,    32,    25,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    45,    28,    46,     0,     4,    47,     5,     8,
       9,    10,    48,    49,    50,    51,    52,     6,    28,    34,
      54,    38,    28,    53,     7,    11,    13,    14,    15,    16,
      28,    55,    56,    57,    61,    63,    66,    67,    26,    27,
      36,    35,    39,    40,    40,    64,    40,    40,    36,    38,
      35,    35,    26,    28,    25,    26,    27,    28,    29,    30,
      40,    68,    28,    40,    68,    28,    68,    68,    37,    68,
      36,    68,    68,    68,    17,    18,    19,    20,    21,    22,
      23,    24,    29,    30,    31,    32,    41,    34,    68,    41,
      41,    37,    35,    35,    68,    41,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    58,    68,
      41,    35,    35,    38,    37,    42,    34,    65,    68,    54,
      68,    42,    35,    43,    34,    54,    12,    59,    68,    43,
      60,    41,    42,    62,    54,    42,    43,    54,    43
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    47,    47,    48,    48,    48,    49,
      50,    51,    51,    52,    52,    53,    53,    54,    54,    55,
      55,    55,    55,    55,    55,    56,    56,    57,    58,    59,
      60,    59,    62,    61,    64,    65,    63,    66,    67,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     8,     1,     2,     0,     1,     1,     1,     4,
       7,     5,     5,     1,     1,     3,     1,     2,     0,     1,
       1,     1,     1,     1,     1,     4,     7,     9,     0,     0,
       0,     5,     0,    14,     0,     0,     9,     5,     5,     3,
       3,     3,     3,     2,     2,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     1,     4,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* programme: TOK_PROGRAM nom_programme TOK_DECL declarations TOK_ENDDECL TOK_BEGIN instructions TOK_END  */
#line 90 "parser.y"
      {
          ci_emettre(Q_HALT, "-", "-", "-");
          ts_afficher();
          ci_afficher();

          if (nb_erreurs == 0) {
              opt_optimiser();
              printf("\n--- Code intermediaire apres optimisation ---\n");
              ci_afficher();

              char asm_file[64];
              snprintf(asm_file, sizeof(asm_file), "%s.asm", nom_prog_global);
              FILE *f = fopen(asm_file, "w");
              if (f) {
                  cg_generer(f, nom_prog_global);
                  fclose(f);
                  printf("[Generation] Fichier assembleur : %s\n\n", asm_file);
              }
              printf("Compilation reussie -- aucune erreur.\n");
          } else {
              printf("\nCompilation terminee avec %d erreur(s).\n", nb_erreurs);
          }
      }
#line 1316 "parser.tab.c"
    break;

  case 3: /* nom_programme: TOK_IDF  */
#line 117 "parser.y"
      {
          strncpy(nom_prog_global, (yyvsp[0].sval), MAX_ID_LEN);
          strncpy((yyval.temp), (yyvsp[0].sval), 63);
      }
#line 1325 "parser.tab.c"
    break;

  case 10: /* decl_tableau: type_simple ':' TOK_IDF '[' TOK_ENTIER ']' ';'  */
#line 140 "parser.y"
      {
          if ((yyvsp[-2].ival) <= 0)
              erreur_semantique(line_num, (yyvsp[-4].sval), "taille de tableau invalide (> 0 requis)");
          else if (ts_inserer((yyvsp[-4].sval), CAT_TAB, (yyvsp[-6].tval), (yyvsp[-2].ival), line_num) == -1)
              erreur_semantique(line_num, (yyvsp[-4].sval), "double declaration");
      }
#line 1336 "parser.tab.c"
    break;

  case 11: /* decl_constante: TOK_CONST TOK_IDF '=' TOK_ENTIER ';'  */
#line 150 "parser.y"
      {
          if (ts_inserer((yyvsp[-3].sval), CAT_CONST, TYPE_INTEGER, 1, line_num) == -1)
              erreur_semantique(line_num, (yyvsp[-3].sval), "double declaration");
          else {
              Symbole *s = ts_rechercher((yyvsp[-3].sval));
              if (s) { s->valeur.ival = (yyvsp[-1].ival); s->est_init = 1; }
          }
      }
#line 1349 "parser.tab.c"
    break;

  case 12: /* decl_constante: TOK_CONST TOK_IDF '=' TOK_REEL ';'  */
#line 159 "parser.y"
      {
          if (ts_inserer((yyvsp[-3].sval), CAT_CONST, TYPE_FLOAT, 1, line_num) == -1)
              erreur_semantique(line_num, (yyvsp[-3].sval), "double declaration");
          else {
              Symbole *s = ts_rechercher((yyvsp[-3].sval));
              if (s) { s->valeur.rval = (yyvsp[-1].rval); s->est_init = 1; }
          }
      }
#line 1362 "parser.tab.c"
    break;

  case 13: /* type_simple: TOK_INTEGER  */
#line 170 "parser.y"
                   { (yyval.tval) = TYPE_INTEGER; type_courant = TYPE_INTEGER; }
#line 1368 "parser.tab.c"
    break;

  case 14: /* type_simple: TOK_FLOAT  */
#line 171 "parser.y"
                   { (yyval.tval) = TYPE_FLOAT;   type_courant = TYPE_FLOAT;   }
#line 1374 "parser.tab.c"
    break;

  case 15: /* liste_idf: liste_idf ',' TOK_IDF  */
#line 176 "parser.y"
      {
          if (ts_inserer((yyvsp[0].sval), CAT_VAR, type_courant, 1, line_num) == -1)
              erreur_semantique(line_num, (yyvsp[0].sval), "double declaration");
      }
#line 1383 "parser.tab.c"
    break;

  case 16: /* liste_idf: TOK_IDF  */
#line 181 "parser.y"
      {
          if (ts_inserer((yyvsp[0].sval), CAT_VAR, type_courant, 1, line_num) == -1)
              erreur_semantique(line_num, (yyvsp[0].sval), "double declaration");
      }
#line 1392 "parser.tab.c"
    break;

  case 25: /* affectation: TOK_IDF '=' expression ';'  */
#line 204 "parser.y"
      {
          Symbole *s = verifier_declare((yyvsp[-3].sval), line_num);
          if (s) {
              if (s->categorie == CAT_CONST)
                  erreur_semantique(line_num, (yyvsp[-3].sval), "constante non modifiable");
              else {
                  ci_emettre(Q_ASGN, (yyvsp[-1].temp), "-", (yyvsp[-3].sval));
                  s->est_init = 1;
              }
          }
      }
#line 1408 "parser.tab.c"
    break;

  case 26: /* affectation: TOK_IDF '[' expression ']' '=' expression ';'  */
#line 216 "parser.y"
      {
          Symbole *s = verifier_declare((yyvsp[-6].sval), line_num);
          if (s) {
              if (s->categorie != CAT_TAB)
                  erreur_semantique(line_num, (yyvsp[-6].sval), "acces tableau sur scalaire");
              else
                  ci_emettre(Q_TASGN, (yyvsp[-6].sval), (yyvsp[-4].temp), (yyvsp[-1].temp));
          }
      }
#line 1422 "parser.tab.c"
    break;

  case 28: /* mark_ifz: %empty  */
#line 247 "parser.y"
      {
          char *lf = ci_nouveau_label();
          int idx = ci_emettre(Q_IFZ, "", "-", lf);
          /* Copier la cond depuis $<temp>-1 (= $3 du parent) n'est pas
             portable en ANSI Bison. On stocke dans un tableau statique. */
          /* Solution simple : on retransmet label_faux via $$ */
          snprintf((yyval.temp), 63, "%d|%s", idx, lf);
      }
#line 1435 "parser.tab.c"
    break;

  case 29: /* partie_else_ci: %empty  */
#line 259 "parser.y"
      {
          /* Lire info de mark_ifz = $<temp>5 de la règle condition */
          /* $<temp>-1 dans une règle imbriquée = $<temp>0 en pratique */
          /* On utilise ici la valeur de marque transmise via l'union   */
          char *lf_info = (yyvsp[(-1) - (0)].temp);   /* valeur de mark_ifz */
          char *colon = strchr(lf_info, '|');
          if (colon) {
              int   idx   = atoi(lf_info);
              char *l_faux = colon + 1;
              /* Patcher l'arg1 du IFZ avec la cond correcte */
              /* (déjà mis au moment de l'émission)           */
              /* Émettre le LABEL faux (pas de ELSE → fin = faux) */
              ci_emettre(Q_LABEL, "-", "-", l_faux);
          }
      }
#line 1455 "parser.tab.c"
    break;

  case 30: /* @1: %empty  */
#line 275 "parser.y"
      {
          /* Avant le bloc ELSE : émettre GOTO vers L_fin, puis LABEL L_faux */
          char *lf_info = (yyvsp[(-2) - (1)].temp);   /* mark_ifz de la règle parente */
          char *colon = strchr(lf_info, '|');
          char *l_fin = ci_nouveau_label();
          snprintf((yyval.temp), 63, "%s", l_fin);
          ci_emettre(Q_GOTO, "-", "-", l_fin);
          if (colon) {
              char *l_faux = colon + 1;
              ci_emettre(Q_LABEL, "-", "-", l_faux);
          }
      }
#line 1472 "parser.tab.c"
    break;

  case 31: /* partie_else_ci: TOK_ELSE @1 '{' instructions '}'  */
#line 288 "parser.y"
      {
          /* Après le bloc ELSE : émettre LABEL L_fin */
          ci_emettre(Q_LABEL, "-", "-", (yyvsp[-3].temp));
      }
#line 1481 "parser.tab.c"
    break;

  case 32: /* @2: %empty  */
#line 311 "parser.y"
      {
          /* $3=var  $5=debut  $7=pas  $9=fin */
          Symbole *sv = verifier_declare((yyvsp[-7].sval), line_num);
          if (sv) {
              ci_emettre(Q_ASGN, (yyvsp[-5].temp), "-", (yyvsp[-7].sval));
              char *l_debut = ci_nouveau_label();
              ci_emettre(Q_LABEL, "-", "-", l_debut);
              char *t_cond = ci_nouveau_temp();
              ci_emettre(Q_LE, (yyvsp[-7].sval), (yyvsp[-1].temp), t_cond);
              char *l_fin = ci_nouveau_label();
              ci_emettre(Q_IFZ, t_cond, "-", l_fin);
              /* Transporter les infos pour l'après-corps */
              snprintf((yyval.temp), 63, "%s|%s|%s|%s", l_debut, l_fin, (yyvsp[-7].sval), (yyvsp[-3].temp));
          } else {
              strncpy((yyval.temp), "?|?|?|?", 63);
          }
      }
#line 1503 "parser.tab.c"
    break;

  case 33: /* boucle_for: TOK_FOR '(' TOK_IDF ':' expression ':' expression ':' expression ')' @2 '{' instructions '}'  */
#line 329 "parser.y"
      {
          char info[64]; strncpy(info, (yyvsp[-4].temp), 63);
          char *l_debut = strtok(info, "|");
          char *l_fin   = strtok(NULL, "|");
          char *var_i   = strtok(NULL, "|");
          char *pas_s   = strtok(NULL, "|");
          if (l_debut && l_fin && var_i && pas_s) {
              char *t_inc = ci_nouveau_temp();
              ci_emettre(Q_ADD, var_i, pas_s, t_inc);
              ci_emettre(Q_ASGN, t_inc, "-", var_i);
              ci_emettre(Q_GOTO, "-", "-", l_debut);
              ci_emettre(Q_LABEL, "-", "-", l_fin);
          }
      }
#line 1522 "parser.tab.c"
    break;

  case 34: /* @3: %empty  */
#line 357 "parser.y"
      {
          char *l_debut = ci_nouveau_label();
          ci_emettre(Q_LABEL, "-", "-", l_debut);
          strncpy((yyval.temp), l_debut, 63);
      }
#line 1532 "parser.tab.c"
    break;

  case 35: /* @4: %empty  */
#line 363 "parser.y"
      {
          char *l_fin = ci_nouveau_label();
          ci_emettre(Q_IFZ, (yyvsp[-1].temp), "-", l_fin);
          snprintf((yyval.temp), 63, "%s|%s", (yyvsp[-3].temp), l_fin);
      }
#line 1542 "parser.tab.c"
    break;

  case 36: /* boucle_while: TOK_WHILE @3 '(' expression ')' @4 '{' instructions '}'  */
#line 369 "parser.y"
      {
          char info[64]; strncpy(info, (yyvsp[-3].temp), 63);
          char *l_debut = strtok(info, "|");
          char *l_fin   = strtok(NULL, "|");
          if (l_debut && l_fin) {
              ci_emettre(Q_GOTO, "-", "-", l_debut);
              ci_emettre(Q_LABEL, "-", "-", l_fin);
          }
      }
#line 1556 "parser.tab.c"
    break;

  case 37: /* instr_write: TOK_WRITE '(' expression ')' ';'  */
#line 383 "parser.y"
      { ci_emettre(Q_WRITE, (yyvsp[-2].temp), "-", "-"); }
#line 1562 "parser.tab.c"
    break;

  case 38: /* instr_read: TOK_READ '(' TOK_IDF ')' ';'  */
#line 389 "parser.y"
      {
          verifier_declare((yyvsp[-2].sval), line_num);
          ci_emettre(Q_READ, "-", "-", (yyvsp[-2].sval));
      }
#line 1571 "parser.tab.c"
    break;

  case 39: /* expression: expression '+' expression  */
#line 400 "parser.y"
      { char *t = ci_nouveau_temp(); ci_emettre(Q_ADD, (yyvsp[-2].temp), (yyvsp[0].temp), t); strncpy((yyval.temp), t, 63); }
#line 1577 "parser.tab.c"
    break;

  case 40: /* expression: expression '-' expression  */
#line 402 "parser.y"
      { char *t = ci_nouveau_temp(); ci_emettre(Q_SUB, (yyvsp[-2].temp), (yyvsp[0].temp), t); strncpy((yyval.temp), t, 63); }
#line 1583 "parser.tab.c"
    break;

  case 41: /* expression: expression '*' expression  */
#line 404 "parser.y"
      { char *t = ci_nouveau_temp(); ci_emettre(Q_MUL, (yyvsp[-2].temp), (yyvsp[0].temp), t); strncpy((yyval.temp), t, 63); }
#line 1589 "parser.tab.c"
    break;

  case 42: /* expression: expression '/' expression  */
#line 406 "parser.y"
      {
          if (strcmp((yyvsp[0].temp), "0") == 0 || strcmp((yyvsp[0].temp), "0.0") == 0)
              erreur_semantique(line_num, "/", "division par zero (operande constant)");
          char *t = ci_nouveau_temp();
          ci_emettre(Q_DIV, (yyvsp[-2].temp), (yyvsp[0].temp), t);
          strncpy((yyval.temp), t, 63);
      }
#line 1601 "parser.tab.c"
    break;

  case 43: /* expression: '-' expression  */
#line 414 "parser.y"
      { char *t = ci_nouveau_temp(); ci_emettre(Q_NEG, (yyvsp[0].temp), "-", t); strncpy((yyval.temp), t, 63); }
#line 1607 "parser.tab.c"
    break;

  case 44: /* expression: '+' expression  */
#line 416 "parser.y"
      { strncpy((yyval.temp), (yyvsp[0].temp), 63); }
#line 1613 "parser.tab.c"
    break;

  case 45: /* expression: expression TOK_AND expression  */
#line 418 "parser.y"
      { char *t = ci_nouveau_temp(); ci_emettre(Q_MUL, (yyvsp[-2].temp), (yyvsp[0].temp), t); strncpy((yyval.temp), t, 63); }
#line 1619 "parser.tab.c"
    break;

  case 46: /* expression: expression TOK_OR expression  */
#line 420 "parser.y"
      {
          char *t1 = ci_nouveau_temp();
          char *t2 = ci_nouveau_temp();
          ci_emettre(Q_ADD, (yyvsp[-2].temp), (yyvsp[0].temp), t1);
          ci_emettre(Q_GT,  t1, "0", t2);
          strncpy((yyval.temp), t2, 63);
      }
#line 1631 "parser.tab.c"
    break;

  case 47: /* expression: TOK_NOT expression  */
#line 428 "parser.y"
      { char *t = ci_nouveau_temp(); ci_emettre(Q_EQ, (yyvsp[0].temp), "0", t); strncpy((yyval.temp), t, 63); }
#line 1637 "parser.tab.c"
    break;

  case 48: /* expression: expression TOK_GT expression  */
#line 430 "parser.y"
      { char *t = ci_nouveau_temp(); ci_emettre(Q_GT, (yyvsp[-2].temp), (yyvsp[0].temp), t); strncpy((yyval.temp), t, 63); }
#line 1643 "parser.tab.c"
    break;

  case 49: /* expression: expression TOK_GE expression  */
#line 432 "parser.y"
      { char *t = ci_nouveau_temp(); ci_emettre(Q_GE, (yyvsp[-2].temp), (yyvsp[0].temp), t); strncpy((yyval.temp), t, 63); }
#line 1649 "parser.tab.c"
    break;

  case 50: /* expression: expression TOK_LT expression  */
#line 434 "parser.y"
      { char *t = ci_nouveau_temp(); ci_emettre(Q_LT, (yyvsp[-2].temp), (yyvsp[0].temp), t); strncpy((yyval.temp), t, 63); }
#line 1655 "parser.tab.c"
    break;

  case 51: /* expression: expression TOK_LE expression  */
#line 436 "parser.y"
      { char *t = ci_nouveau_temp(); ci_emettre(Q_LE, (yyvsp[-2].temp), (yyvsp[0].temp), t); strncpy((yyval.temp), t, 63); }
#line 1661 "parser.tab.c"
    break;

  case 52: /* expression: expression TOK_EQ expression  */
#line 438 "parser.y"
      { char *t = ci_nouveau_temp(); ci_emettre(Q_EQ, (yyvsp[-2].temp), (yyvsp[0].temp), t); strncpy((yyval.temp), t, 63); }
#line 1667 "parser.tab.c"
    break;

  case 53: /* expression: expression TOK_NE expression  */
#line 440 "parser.y"
      { char *t = ci_nouveau_temp(); ci_emettre(Q_NE, (yyvsp[-2].temp), (yyvsp[0].temp), t); strncpy((yyval.temp), t, 63); }
#line 1673 "parser.tab.c"
    break;

  case 54: /* expression: TOK_IDF  */
#line 442 "parser.y"
      { verifier_declare((yyvsp[0].sval), line_num); strncpy((yyval.temp), (yyvsp[0].sval), 63); }
#line 1679 "parser.tab.c"
    break;

  case 55: /* expression: TOK_IDF '[' expression ']'  */
#line 444 "parser.y"
      {
          Symbole *s = verifier_declare((yyvsp[-3].sval), line_num);
          if (s && s->categorie != CAT_TAB)
              erreur_semantique(line_num, (yyvsp[-3].sval), "acces tableau sur scalaire");
          char *t = ci_nouveau_temp();
          ci_emettre(Q_TLOAD, (yyvsp[-3].sval), (yyvsp[-1].temp), t);
          strncpy((yyval.temp), t, 63);
      }
#line 1692 "parser.tab.c"
    break;

  case 56: /* expression: TOK_ENTIER  */
#line 453 "parser.y"
      { snprintf((yyval.temp), 63, "%d", (yyvsp[0].ival)); }
#line 1698 "parser.tab.c"
    break;

  case 57: /* expression: TOK_REEL  */
#line 455 "parser.y"
      { snprintf((yyval.temp), 63, "%g", (yyvsp[0].rval)); }
#line 1704 "parser.tab.c"
    break;

  case 58: /* expression: '(' expression ')'  */
#line 457 "parser.y"
      { strncpy((yyval.temp), (yyvsp[-1].temp), 63); }
#line 1710 "parser.tab.c"
    break;


#line 1714 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 460 "parser.y"


int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (!f) { perror(argv[1]); return EXIT_FAILURE; }
        extern FILE *yyin;
        yyin = f;
    }
    ts_init();
    ci_init();
    printf("=== Compilation MiniAlgo : %s ===\n\n",
           (argc > 1) ? argv[1] : "stdin");
    yyparse();
    ts_liberer();
    return (nb_erreurs == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
