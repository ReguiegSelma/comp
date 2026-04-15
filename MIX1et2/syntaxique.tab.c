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
#line 1 "syntaxique.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ts.h"
#include "quad.h"

extern int nb_lignes;
extern int nb_erreurs;
extern char* yytext;
extern FILE *yyin;

int yylex();
void yyerror(const char* s);

char type_svg[20];
char save_type[20];

// Variables pour les quadruplets
int fin_if = 0;
int deb_else = 0;
int loop_start = 0;
int loop_cond = 0;
char tmp_addr[10];

#line 97 "syntaxique.tab.c"

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

#include "syntaxique.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDF = 3,                        /* IDF  */
  YYSYMBOL_INT_VAL = 4,                    /* INT_VAL  */
  YYSYMBOL_FLOAT_VAL = 5,                  /* FLOAT_VAL  */
  YYSYMBOL_PROGRAM = 6,                    /* PROGRAM  */
  YYSYMBOL_DECL = 7,                       /* DECL  */
  YYSYMBOL_ENDDECL = 8,                    /* ENDDECL  */
  YYSYMBOL_BEGIN_P = 9,                    /* BEGIN_P  */
  YYSYMBOL_END = 10,                       /* END  */
  YYSYMBOL_INTEGER = 11,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 12,                     /* FLOAT  */
  YYSYMBOL_CONST = 13,                     /* CONST  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_FOR = 16,                       /* FOR  */
  YYSYMBOL_WHILE = 17,                     /* WHILE  */
  YYSYMBOL_WRITE = 18,                     /* WRITE  */
  YYSYMBOL_PLUS = 19,                      /* PLUS  */
  YYSYMBOL_MOINS = 20,                     /* MOINS  */
  YYSYMBOL_MULT = 21,                      /* MULT  */
  YYSYMBOL_DIV = 22,                       /* DIV  */
  YYSYMBOL_AFFECT = 23,                    /* AFFECT  */
  YYSYMBOL_SUP = 24,                       /* SUP  */
  YYSYMBOL_INF = 25,                       /* INF  */
  YYSYMBOL_EGAL = 26,                      /* EGAL  */
  YYSYMBOL_PV = 27,                        /* PV  */
  YYSYMBOL_DEUXPTS = 28,                   /* DEUXPTS  */
  YYSYMBOL_VIRG = 29,                      /* VIRG  */
  YYSYMBOL_PARG = 30,                      /* PARG  */
  YYSYMBOL_PARD = 31,                      /* PARD  */
  YYSYMBOL_ACCOLG = 32,                    /* ACCOLG  */
  YYSYMBOL_ACCOLD = 33,                    /* ACCOLD  */
  YYSYMBOL_CROCHG = 34,                    /* CROCHG  */
  YYSYMBOL_CROCHD = 35,                    /* CROCHD  */
  YYSYMBOL_AND = 36,                       /* AND  */
  YYSYMBOL_OR = 37,                        /* OR  */
  YYSYMBOL_NOT = 38,                       /* NOT  */
  YYSYMBOL_LOWER_THAN_ELSE = 39,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_PROG = 41,                      /* PROG  */
  YYSYMBOL_DECLS = 42,                     /* DECLS  */
  YYSYMBOL_DEC = 43,                       /* DEC  */
  YYSYMBOL_LISTE_OBJETS = 44,              /* LISTE_OBJETS  */
  YYSYMBOL_OBJET = 45,                     /* OBJET  */
  YYSYMBOL_VAL_CONST = 46,                 /* VAL_CONST  */
  YYSYMBOL_TYPE = 47,                      /* TYPE  */
  YYSYMBOL_INSTS = 48,                     /* INSTS  */
  YYSYMBOL_INST = 49,                      /* INST  */
  YYSYMBOL_AFF = 50,                       /* AFF  */
  YYSYMBOL_expression = 51,                /* expression  */
  YYSYMBOL_terme = 52,                     /* terme  */
  YYSYMBOL_facteur = 53,                   /* facteur  */
  YYSYMBOL_COND = 54,                      /* COND  */
  YYSYMBOL_55_1 = 55,                      /* $@1  */
  YYSYMBOL_ELSE_PART = 56,                 /* ELSE_PART  */
  YYSYMBOL_57_2 = 57,                      /* $@2  */
  YYSYMBOL_BOUCLE = 58,                    /* BOUCLE  */
  YYSYMBOL_59_3 = 59,                      /* $@3  */
  YYSYMBOL_60_4 = 60,                      /* $@4  */
  YYSYMBOL_61_5 = 61,                      /* $@5  */
  YYSYMBOL_EXPR_LOG = 62,                  /* EXPR_LOG  */
  YYSYMBOL_WRITE_I = 63                    /* WRITE_I  */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   154

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    53,    53,    63,    63,    65,    66,    70,    78,    78,
      80,    81,    84,    85,    88,    89,    92,    92,    94,    95,
      96,    97,    98,   106,   118,   134,   135,   136,   139,   140,
     144,   147,   155,   160,   161,   162,   166,   165,   177,   176,
     184,   188,   192,   187,   204,   203,   234,   235,   236,   237,
     238,   239,   240,   243
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
  "\"end of file\"", "error", "\"invalid token\"", "IDF", "INT_VAL",
  "FLOAT_VAL", "PROGRAM", "DECL", "ENDDECL", "BEGIN_P", "END", "INTEGER",
  "FLOAT", "CONST", "IF", "ELSE", "FOR", "WHILE", "WRITE", "PLUS", "MOINS",
  "MULT", "DIV", "AFFECT", "SUP", "INF", "EGAL", "PV", "DEUXPTS", "VIRG",
  "PARG", "PARD", "ACCOLG", "ACCOLD", "CROCHG", "CROCHD", "AND", "OR",
  "NOT", "LOWER_THAN_ELSE", "$accept", "PROG", "DECLS", "DEC",
  "LISTE_OBJETS", "OBJET", "VAL_CONST", "TYPE", "INSTS", "INST", "AFF",
  "expression", "terme", "facteur", "COND", "$@1", "ELSE_PART", "$@2",
  "BOUCLE", "$@3", "$@4", "$@5", "EXPR_LOG", "WRITE_I", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-43)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-18)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,    53,    13,    25,   -43,    54,    34,   -43,   -43,    60,
      68,    54,    43,   -43,    50,    70,   -43,    92,    10,    71,
      74,    82,    76,   -43,   -43,    83,    84,    -6,    85,    86,
     -43,    87,   102,     9,    91,   -43,   -43,    93,   109,   -43,
      92,   -43,   -43,    40,    40,     0,   111,    89,   118,   -43,
     -43,   -43,   -43,    88,   -43,    90,   -43,   -43,    40,    78,
      15,   -43,   -13,     0,     0,    58,    55,    94,     0,    95,
     -43,    40,    29,    40,    40,    40,    40,   104,    33,    63,
     -43,    40,    40,    40,   -43,     0,     0,   121,    65,   -43,
     -11,   -43,    15,    15,   -43,   -43,    40,   -43,    78,    78,
      78,    96,   -43,    97,   101,   -43,   -43,    78,    17,   126,
      99,   103,   106,    17,   117,   131,   105,   -43,   -43,   108,
     -43,   110,   -43,    17,   112,   107,    17,   -43,   113,   -43
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,    14,    15,     0,
       0,     0,     0,     7,     0,     0,     3,     0,     0,     0,
      10,     0,     9,    12,    13,     0,     0,     0,     0,     0,
      41,     0,     0,     0,     0,    19,    20,     0,     0,     5,
       0,     6,    22,     0,     0,     0,     0,     0,     0,     2,
      16,    18,    21,     0,     8,    31,    33,    34,     0,    23,
      27,    30,     0,     0,     0,     0,     0,     0,     0,     0,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,     0,     0,     0,    36,     0,     0,     0,     0,    53,
       0,    35,    25,    26,    28,    29,     0,    52,    49,    50,
      51,     0,    47,    46,     0,    42,    32,    24,     0,     0,
       0,     0,     0,     0,    40,     0,     0,    38,    37,     0,
      43,     0,    44,     0,     0,     0,     0,    39,     0,    45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -43,   -43,   130,   -43,   114,   -43,   -43,   -43,   -33,   -43,
     -43,   -42,    30,    31,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   -17,   -43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    10,    11,    21,    22,    25,    12,    32,    33,
      34,    65,    60,    61,    35,   101,   118,   121,    36,    47,
     110,   124,    66,    37
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    59,    62,    55,    56,    57,    73,    74,    73,    74,
      26,     1,    27,     4,    23,    24,    72,    43,    26,   -17,
      27,    78,    77,    28,   106,    29,    30,    31,    44,    90,
      63,    28,     5,    29,    30,    31,    75,    76,    64,    98,
      99,   100,   -17,    55,    56,    57,    79,    80,    73,    74,
     -17,    88,    73,    74,   107,     6,     3,    81,    82,    83,
      91,    13,    -4,    14,    91,     7,     8,     9,   102,   103,
      58,    17,    26,    18,    27,   111,    15,    73,    74,    19,
     116,   -17,    81,    82,    83,    28,    84,    29,    30,    31,
     125,    85,    86,   128,    97,    20,   105,    73,    74,    85,
      86,    85,    86,    92,    93,    40,    94,    95,    38,    39,
      41,    42,    49,    53,    67,    45,    46,    48,    51,    68,
      52,    69,    87,    70,    71,   104,    89,    96,   108,   109,
     112,   113,   117,    85,   115,   119,   114,     0,   120,   122,
     127,    16,   123,     0,   126,     0,   129,     0,     0,     0,
       0,     0,     0,     0,    54
};

static const yytype_int8 yycheck[] =
{
      33,    43,    44,     3,     4,     5,    19,    20,    19,    20,
       1,     6,     3,     0,     4,     5,    58,    23,     1,    10,
       3,    63,    35,    14,    35,    16,    17,    18,    34,    71,
      30,    14,     7,    16,    17,    18,    21,    22,    38,    81,
      82,    83,    33,     3,     4,     5,    63,    64,    19,    20,
      33,    68,    19,    20,    96,     1,     3,    24,    25,    26,
      31,    27,     8,     3,    31,    11,    12,    13,    85,    86,
      30,    28,     1,    23,     3,   108,     8,    19,    20,     9,
     113,    10,    24,    25,    26,    14,    31,    16,    17,    18,
     123,    36,    37,   126,    31,     3,    31,    19,    20,    36,
      37,    36,    37,    73,    74,    29,    75,    76,    34,    27,
      27,    27,    10,     4,     3,    30,    30,    30,    27,    30,
      27,     3,    28,    35,    34,     4,    31,    23,    32,    28,
       4,    32,    15,    36,    28,     4,    33,    -1,    33,    31,
      33,    11,    32,    -1,    32,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    41,     3,     0,     7,     1,    11,    12,    13,
      42,    43,    47,    27,     3,     8,    42,    28,    23,     9,
       3,    44,    45,     4,     5,    46,     1,     3,    14,    16,
      17,    18,    48,    49,    50,    54,    58,    63,    34,    27,
      29,    27,    27,    23,    34,    30,    30,    59,    30,    10,
      48,    27,    27,     4,    44,     3,     4,     5,    30,    51,
      52,    53,    51,    30,    38,    51,    62,     3,    30,     3,
      35,    34,    51,    19,    20,    21,    22,    35,    51,    62,
      62,    24,    25,    26,    31,    36,    37,    28,    62,    31,
      51,    31,    52,    52,    53,    53,    23,    31,    51,    51,
      51,    55,    62,    62,     4,    31,    35,    51,    32,    28,
      60,    48,     4,    32,    33,    28,    48,    15,    56,     4,
      33,    57,    31,    32,    61,    48,    32,    33,    48,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    44,    44,
      45,    45,    46,    46,    47,    47,    48,    48,    49,    49,
      49,    49,    49,    50,    50,    51,    51,    51,    52,    52,
      52,    53,    53,    53,    53,    53,    55,    54,    57,    56,
      56,    59,    60,    58,    61,    58,    62,    62,    62,    62,
      62,    62,    62,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     8,     2,     0,     4,     5,     2,     3,     1,
       1,     4,     1,     1,     1,     1,     2,     0,     2,     1,
       1,     2,     2,     3,     6,     3,     3,     1,     3,     3,
       1,     1,     4,     1,     1,     3,     0,     9,     0,     5,
       0,     0,     0,     9,     0,    14,     3,     3,     2,     3,
       3,     3,     3,     4
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
  case 2: /* PROG: PROGRAM IDF DECL DECLS ENDDECL BEGIN_P INSTS END  */
#line 54 "syntaxique.y"
      {      
        if(nb_erreurs == 0){
            printf("Syntaxe Correcte\n");
            afficher_quads();
        }else{
            printf("\nCompilation echouee : %d erreur(s)\n", nb_erreurs);
        }
      }
#line 1236 "syntaxique.tab.c"
    break;

  case 6: /* DEC: CONST IDF AFFECT VAL_CONST PV  */
#line 67 "syntaxique.y"
     { 
        insert_idf_cst((yyvsp[-3].str), "CONST", type_svg, (yyvsp[-1].float_val), 0, 0, 1);
     }
#line 1244 "syntaxique.tab.c"
    break;

  case 7: /* DEC: error PV  */
#line 71 "syntaxique.y"
      {
          printf("Erreur Syntaxique: ligne %d\n", nb_lignes);
          nb_erreurs++;
          yyerrok;
      }
#line 1254 "syntaxique.tab.c"
    break;

  case 10: /* OBJET: IDF  */
#line 80 "syntaxique.y"
           { insert_idf_cst((yyvsp[0].str), "VAR", type_svg, 0, 0, 0, 0); }
#line 1260 "syntaxique.tab.c"
    break;

  case 11: /* OBJET: IDF CROCHG INT_VAL CROCHD  */
#line 81 "syntaxique.y"
                                 { insert_idf_cst((yyvsp[-3].str), "TAB", type_svg, 0, 1, (yyvsp[-1].integer), 0); }
#line 1266 "syntaxique.tab.c"
    break;

  case 12: /* VAL_CONST: INT_VAL  */
#line 84 "syntaxique.y"
                   { (yyval.float_val) = (float)(yyvsp[0].integer); }
#line 1272 "syntaxique.tab.c"
    break;

  case 13: /* VAL_CONST: FLOAT_VAL  */
#line 85 "syntaxique.y"
                     { (yyval.float_val) = (yyvsp[0].float_val); }
#line 1278 "syntaxique.tab.c"
    break;

  case 14: /* TYPE: INTEGER  */
#line 88 "syntaxique.y"
              { strcpy(type_svg, "INTEGER"); }
#line 1284 "syntaxique.tab.c"
    break;

  case 15: /* TYPE: FLOAT  */
#line 89 "syntaxique.y"
            { strcpy(type_svg, "FLOAT"); }
#line 1290 "syntaxique.tab.c"
    break;

  case 22: /* INST: error PV  */
#line 99 "syntaxique.y"
      {
          printf("Erreur Syntaxique: ligne %d\n", nb_lignes);
          nb_erreurs++;
          yyerrok;
      }
#line 1300 "syntaxique.tab.c"
    break;

  case 23: /* AFF: IDF AFFECT expression  */
#line 106 "syntaxique.y"
                           { 
    int idx = search_idf_cst((yyvsp[-2].str));
    if(idx == -1) {
        printf("Erreur Semantique: ligne %d '%s' non declare\n", nb_lignes, (yyvsp[-2].str));
        nb_erreurs++;
    } else if(ts_idf_cst[idx].estConstante) {
        printf("Erreur Semantique: ligne %d, Modif constante '%s'\n", nb_lignes, (yyvsp[-2].str));
        nb_erreurs++;
    } else {
        quad("=", (yyvsp[0].str), "", (yyvsp[-2].str));
    }
}
#line 1317 "syntaxique.tab.c"
    break;

  case 24: /* AFF: IDF CROCHG expression CROCHD AFFECT expression  */
#line 118 "syntaxique.y"
                                                    {
    int idx = search_idf_cst((yyvsp[-5].str));
    if(idx == -1) {
        printf("Erreur Semantique: ligne %d: tableau '%s' non declare\n", nb_lignes, (yyvsp[-5].str));
        nb_erreurs++;
    } else if(!ts_idf_cst[idx].estTableau) {
        printf("Erreur Semantique: ligne %d: '%s' n'est pas un tableau\n", nb_lignes, (yyvsp[-5].str));
        nb_erreurs++;
    } else {
        char res[30]; 
        sprintf(res, "%s[%s]", (yyvsp[-5].str), (yyvsp[-3].str));
        quad("=", (yyvsp[0].str), "", res);
    }
   }
#line 1336 "syntaxique.tab.c"
    break;

  case 25: /* expression: expression PLUS terme  */
#line 134 "syntaxique.y"
                                  { (yyval.str) = new_temp(); quad("+", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
#line 1342 "syntaxique.tab.c"
    break;

  case 26: /* expression: expression MOINS terme  */
#line 135 "syntaxique.y"
                                   { (yyval.str) = new_temp(); quad("-", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
#line 1348 "syntaxique.tab.c"
    break;

  case 27: /* expression: terme  */
#line 136 "syntaxique.y"
                  { (yyval.str) = (yyvsp[0].str); }
#line 1354 "syntaxique.tab.c"
    break;

  case 28: /* terme: terme MULT facteur  */
#line 139 "syntaxique.y"
                          { (yyval.str) = new_temp(); quad("*", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
#line 1360 "syntaxique.tab.c"
    break;

  case 29: /* terme: terme DIV facteur  */
#line 140 "syntaxique.y"
                         { 
        (yyval.str) = new_temp(); 
        quad("/", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str));
       }
#line 1369 "syntaxique.tab.c"
    break;

  case 30: /* terme: facteur  */
#line 144 "syntaxique.y"
               { (yyval.str) = (yyvsp[0].str); }
#line 1375 "syntaxique.tab.c"
    break;

  case 31: /* facteur: IDF  */
#line 147 "syntaxique.y"
             { 
            int idx = search_idf_cst((yyvsp[0].str));
            if(idx == -1) {
                printf("Erreur Semantique: ligne %d: variable '%s' non declaree\n", nb_lignes, (yyvsp[0].str));
                nb_erreurs++;
            }
            (yyval.str) = (yyvsp[0].str); 
         }
#line 1388 "syntaxique.tab.c"
    break;

  case 32: /* facteur: IDF CROCHG expression CROCHD  */
#line 155 "syntaxique.y"
                                      { 
            char* t = malloc(30); 
            sprintf(t, "%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str)); 
            (yyval.str) = t; 
         }
#line 1398 "syntaxique.tab.c"
    break;

  case 33: /* facteur: INT_VAL  */
#line 160 "syntaxique.y"
                 { char* t=malloc(20); sprintf(t,"%d",(yyvsp[0].integer)); (yyval.str)=t; }
#line 1404 "syntaxique.tab.c"
    break;

  case 34: /* facteur: FLOAT_VAL  */
#line 161 "syntaxique.y"
                   { char* t=malloc(20); sprintf(t,"%f",(yyvsp[0].float_val)); (yyval.str)=t; }
#line 1410 "syntaxique.tab.c"
    break;

  case 35: /* facteur: PARG expression PARD  */
#line 162 "syntaxique.y"
                              { (yyval.str) = (yyvsp[-1].str); }
#line 1416 "syntaxique.tab.c"
    break;

  case 36: /* $@1: %empty  */
#line 166 "syntaxique.y"
      { 
        fin_if = prochain_quad(); 
        quad("BZ", "", (yyvsp[-1].str), ""); 
      }
#line 1425 "syntaxique.tab.c"
    break;

  case 37: /* COND: IF PARG EXPR_LOG PARD $@1 ACCOLG INSTS ACCOLD ELSE_PART  */
#line 170 "syntaxique.y"
                                    {
          sprintf(tmp_addr, "%d", prochain_quad());
          modifier_quad(fin_if, 3, tmp_addr);
      }
#line 1434 "syntaxique.tab.c"
    break;

  case 38: /* $@2: %empty  */
#line 177 "syntaxique.y"
           {
             deb_else = prochain_quad();
             quad("BR", "", "", "");
             sprintf(tmp_addr, "%d", prochain_quad());
             modifier_quad(fin_if, 3, tmp_addr);
           }
#line 1445 "syntaxique.tab.c"
    break;

  case 41: /* $@3: %empty  */
#line 188 "syntaxique.y"
        { 
            loop_start = prochain_quad(); 
        }
#line 1453 "syntaxique.tab.c"
    break;

  case 42: /* $@4: %empty  */
#line 192 "syntaxique.y"
        {
            loop_cond = prochain_quad();
            quad("BZ", "", (yyvsp[-1].str), "");
        }
#line 1462 "syntaxique.tab.c"
    break;

  case 43: /* BOUCLE: WHILE $@3 PARG EXPR_LOG PARD $@4 ACCOLG INSTS ACCOLD  */
#line 197 "syntaxique.y"
        {
            sprintf(tmp_addr, "%d", loop_start);
            quad("BR", "", "", tmp_addr);
            sprintf(tmp_addr, "%d", prochain_quad());
            modifier_quad(loop_cond, 3, tmp_addr);
        }
#line 1473 "syntaxique.tab.c"
    break;

  case 44: /* $@5: %empty  */
#line 204 "syntaxique.y"
        {
            // Initialisation: $3 = variable, $5 = debut, $7 = pas, $9 = fin
            char* start_val = malloc(20);
            char* step_val = malloc(20);
            char* end_val = malloc(20);
            sprintf(start_val, "%d", (yyvsp[-5].integer));
            sprintf(step_val, "%d", (yyvsp[-3].integer));
            sprintf(end_val, "%d", (yyvsp[-1].integer));
            
            quad("=", start_val, "", (yyvsp[-7].str));
            loop_start = prochain_quad();
            char* temp_cond = new_temp();
            quad("SUP", (yyvsp[-7].str), end_val, temp_cond);
            loop_cond = prochain_quad();
            quad("BZ", "", temp_cond, "");
        }
#line 1494 "syntaxique.tab.c"
    break;

  case 45: /* BOUCLE: FOR PARG IDF DEUXPTS INT_VAL DEUXPTS INT_VAL DEUXPTS INT_VAL PARD $@5 ACCOLG INSTS ACCOLD  */
#line 221 "syntaxique.y"
        {
            char* temp_step = new_temp();
            char* step_val = malloc(20);
            sprintf(step_val, "%d", (yyvsp[-7].integer));
            quad("+", (yyvsp[-11].str), step_val, temp_step);
            quad("=", temp_step, "", (yyvsp[-11].str));
            sprintf(tmp_addr, "%d", loop_start);
            quad("BR", "", "", tmp_addr);
            sprintf(tmp_addr, "%d", prochain_quad());
            modifier_quad(loop_cond, 3, tmp_addr);
        }
#line 1510 "syntaxique.tab.c"
    break;

  case 46: /* EXPR_LOG: EXPR_LOG OR EXPR_LOG  */
#line 234 "syntaxique.y"
                               { (yyval.str) = new_temp(); quad("OR", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
#line 1516 "syntaxique.tab.c"
    break;

  case 47: /* EXPR_LOG: EXPR_LOG AND EXPR_LOG  */
#line 235 "syntaxique.y"
                                { (yyval.str) = new_temp(); quad("AND", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
#line 1522 "syntaxique.tab.c"
    break;

  case 48: /* EXPR_LOG: NOT EXPR_LOG  */
#line 236 "syntaxique.y"
                       { (yyval.str) = new_temp(); quad("NOT", (yyvsp[0].str), "", (yyval.str)); }
#line 1528 "syntaxique.tab.c"
    break;

  case 49: /* EXPR_LOG: expression SUP expression  */
#line 237 "syntaxique.y"
                                    { (yyval.str) = new_temp(); quad("SUP", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
#line 1534 "syntaxique.tab.c"
    break;

  case 50: /* EXPR_LOG: expression INF expression  */
#line 238 "syntaxique.y"
                                    { (yyval.str) = new_temp(); quad("INF", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
#line 1540 "syntaxique.tab.c"
    break;

  case 51: /* EXPR_LOG: expression EGAL expression  */
#line 239 "syntaxique.y"
                                     { (yyval.str) = new_temp(); quad("EGAL", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
#line 1546 "syntaxique.tab.c"
    break;

  case 52: /* EXPR_LOG: PARG EXPR_LOG PARD  */
#line 240 "syntaxique.y"
                             { (yyval.str) = (yyvsp[-1].str); }
#line 1552 "syntaxique.tab.c"
    break;

  case 53: /* WRITE_I: WRITE PARG IDF PARD  */
#line 243 "syntaxique.y"
                             {
    int idx = search_idf_cst((yyvsp[-1].str));
    if(idx == -1) {
        printf("Erreur Semantique: ligne %d, variable '%s' non declaree\n", nb_lignes, (yyvsp[-1].str));
        nb_erreurs++;
    }
}
#line 1564 "syntaxique.tab.c"
    break;


#line 1568 "syntaxique.tab.c"

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

#line 252 "syntaxique.y"


void yyerror(const char* s) { 
    printf("Erreur Syntaxique: ligne %d, pres de '%s'\n", nb_lignes, yytext);
    nb_erreurs++; 
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (f) yyin = f;
        else {
            printf("Can't open file!\n");
            return 1;
        }
    }
    yyparse();
    afficher_ts_ids();
    afficher_ts_kw();
    afficher_ts_sep();
    return 0;
}
