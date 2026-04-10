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

int contient_point_decimal(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') return 1;
    }
    return 0;
}

// Pour la gestion des sauts
char tmp_addr[10];
int fin_if, deb_else, deb_while, cond_while;

extern int nb_lignes;
extern int nb_col;
extern char* yytext;
extern FILE *yyin; 

int nb_erreurs = 0;
int yylex();
void yyerror(const char* s);
char type_svg[20];

#line 100 "syntaxique.tab.c"

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
  YYSYMBOL_LOWER_THAN_ELSE = 36,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_PROG = 38,                      /* PROG  */
  YYSYMBOL_DECLS = 39,                     /* DECLS  */
  YYSYMBOL_DEC = 40,                       /* DEC  */
  YYSYMBOL_LISTE_OBJETS = 41,              /* LISTE_OBJETS  */
  YYSYMBOL_OBJET = 42,                     /* OBJET  */
  YYSYMBOL_VAL_CONST = 43,                 /* VAL_CONST  */
  YYSYMBOL_TYPE = 44,                      /* TYPE  */
  YYSYMBOL_INSTS = 45,                     /* INSTS  */
  YYSYMBOL_INST = 46,                      /* INST  */
  YYSYMBOL_AFF = 47,                       /* AFF  */
  YYSYMBOL_expression = 48,                /* expression  */
  YYSYMBOL_terme = 49,                     /* terme  */
  YYSYMBOL_facteur = 50,                   /* facteur  */
  YYSYMBOL_COND = 51,                      /* COND  */
  YYSYMBOL_52_1 = 52,                      /* $@1  */
  YYSYMBOL_ELSE_PART = 53,                 /* ELSE_PART  */
  YYSYMBOL_54_2 = 54,                      /* $@2  */
  YYSYMBOL_BOUCLE = 55,                    /* BOUCLE  */
  YYSYMBOL_56_3 = 56,                      /* $@3  */
  YYSYMBOL_57_4 = 57,                      /* $@4  */
  YYSYMBOL_58_5 = 58,                      /* $@5  */
  YYSYMBOL_EXPR_LOG = 59,                  /* EXPR_LOG  */
  YYSYMBOL_WRITE_I = 60                    /* WRITE_I  */
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
#define YYLAST   172

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    46,    46,    56,    56,    58,    59,    60,    68,    69,
      72,    75,    83,    83,    83,    83,    83,    83,    85,    86,
      88,    88,    89,    89,    89,    89,    90,    98,   118,   155,
     159,   163,   165,   169,   179,   181,   193,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   221,   220,   231,   230,
     239,   243,   245,   243,   257,   256,   278,   279,   280,   283
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
  "PARG", "PARD", "ACCOLG", "ACCOLD", "CROCHG", "CROCHD",
  "LOWER_THAN_ELSE", "$accept", "PROG", "DECLS", "DEC", "LISTE_OBJETS",
  "OBJET", "VAL_CONST", "TYPE", "INSTS", "INST", "AFF", "expression",
  "terme", "facteur", "COND", "$@1", "ELSE_PART", "$@2", "BOUCLE", "$@3",
  "$@4", "$@5", "EXPR_LOG", "WRITE_I", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-46)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-22)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,    15,    34,    53,   -46,    70,    46,   -46,   -46,    91,
      33,    70,    68,   -46,    76,    92,   -46,    97,    12,    58,
      72,    75,    78,   -46,   -46,    17,    82,    84,   -20,    80,
      85,   -46,    87,   102,     5,   -46,   -46,   -46,   -46,   109,
     -46,    97,    49,    65,   -46,   -46,    26,    26,    26,   111,
      88,   113,   -46,   -46,    89,   -46,    90,    94,    95,    96,
      98,   -46,   -46,   115,   116,    47,   -15,    41,   -46,   -10,
      60,    99,   100,    26,   103,   -46,   -46,   -46,   -46,   -46,
      26,   -46,   -46,    83,    86,    13,    26,    26,   -46,    26,
      26,   106,    26,    26,    26,   -46,   118,   104,   110,    20,
     105,   107,   108,   112,   -46,    41,    41,   -46,   -46,    26,
      73,    73,    73,   101,   114,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,    38,    10,   119,   117,   -46,   120,   122,    10,
     125,   127,   121,   -46,   -46,   124,   -46,   126,   -46,    10,
     128,   123,    10,   -46,   129,   -46
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,    18,    19,     0,
       0,     0,     0,     7,     0,     0,     3,     0,     0,     0,
      10,     0,     9,    12,    13,     0,     0,     0,     0,     0,
       0,    51,     0,     0,     0,    22,    23,    24,    25,     0,
       5,     0,     0,     0,     6,    26,     0,     0,     0,     0,
       0,     0,     2,    20,     0,     8,     0,     0,     0,     0,
      35,    37,    38,     0,     0,     0,     0,    31,    34,     0,
       0,     0,     0,     0,     0,    11,    16,    17,    14,    15,
       0,    45,    44,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
      45,     0,    44,     0,    39,    29,    30,    32,    33,     0,
      56,    57,    58,     0,     0,    52,    59,    36,    41,    43,
      40,    42,     0,     0,     0,     0,    28,     0,     0,     0,
      50,     0,     0,    48,    47,     0,    53,     0,    54,     0,
       0,     0,     0,    49,     0,    55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -46,   -46,   130,   -46,   131,   -46,   -46,   -46,   -34,   -46,
     -46,   -45,    11,    14,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,    71,   -46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,    10,    11,    21,    22,    26,    12,    33,    34,
      35,    70,    67,    68,    36,   113,   134,   137,    37,    50,
     125,   140,    71,    38
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    66,    69,    46,    86,    87,    27,     1,    28,    86,
      87,    27,    88,    28,    47,   -21,    23,    24,     3,    29,
      85,    30,    31,    32,    29,    91,    30,    31,    32,    60,
      61,    62,    86,    87,     4,    99,    42,    43,   -21,    86,
      87,    15,    25,   -21,   104,    63,    64,   110,   111,   112,
      60,    61,    62,    56,    57,   117,    65,    86,    87,    27,
       5,    28,    89,    90,   122,   126,    83,    84,   -21,    58,
      59,     6,    29,    13,    30,    31,    32,    65,    -4,    86,
      87,     7,     8,     9,    92,    93,    94,   100,   101,   127,
     102,   103,    86,    87,    14,   132,    17,   105,   106,    18,
      20,    19,    40,   107,   108,   141,    39,    41,   144,    44,
      48,    45,    52,    54,    72,    49,    74,    51,    73,    81,
      82,    76,   114,   128,    75,    77,    78,    79,    96,   109,
      95,   135,    80,   123,    98,   115,   118,   116,   119,   120,
     133,    16,   124,   121,    97,     0,     0,     0,     0,   129,
     131,     0,     0,   130,   136,   138,   143,     0,   139,     0,
     142,     0,   145,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55
};

static const yytype_int16 yycheck[] =
{
      34,    46,    47,    23,    19,    20,     1,     6,     3,    19,
      20,     1,    27,     3,    34,    10,     4,     5,     3,    14,
      65,    16,    17,    18,    14,    35,    16,    17,    18,     3,
       4,     5,    19,    20,     0,    80,    19,    20,    33,    19,
      20,     8,    30,    33,    31,    19,    20,    92,    93,    94,
       3,     4,     5,     4,     5,    35,    30,    19,    20,     1,
       7,     3,    21,    22,   109,    27,    19,    20,    10,     4,
       5,     1,    14,    27,    16,    17,    18,    30,     8,    19,
      20,    11,    12,    13,    24,    25,    26,     4,     5,   123,
       4,     5,    19,    20,     3,   129,    28,    86,    87,    23,
       3,     9,    27,    89,    90,   139,    34,    29,   142,    27,
      30,    27,    10,     4,     3,    30,     3,    30,    30,     4,
       4,    31,     4,     4,    35,    31,    31,    31,    28,    23,
      31,     4,    34,    32,    31,    31,    31,    27,    31,    31,
      15,    11,    28,    31,    73,    -1,    -1,    -1,    -1,    32,
      28,    -1,    -1,    33,    33,    31,    33,    -1,    32,    -1,
      32,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    38,     3,     0,     7,     1,    11,    12,    13,
      39,    40,    44,    27,     3,     8,    39,    28,    23,     9,
       3,    41,    42,     4,     5,    30,    43,     1,     3,    14,
      16,    17,    18,    45,    46,    47,    51,    55,    60,    34,
      27,    29,    19,    20,    27,    27,    23,    34,    30,    30,
      56,    30,    10,    45,     4,    41,     4,     5,     4,     5,
       3,     4,     5,    19,    20,    30,    48,    49,    50,    48,
      48,    59,     3,    30,     3,    35,    31,    31,    31,    31,
      34,     4,     4,    19,    20,    48,    19,    20,    27,    21,
      22,    35,    24,    25,    26,    31,    28,    59,    31,    48,
       4,     5,     4,     5,    31,    49,    49,    50,    50,    23,
      48,    48,    48,    52,     4,    31,    27,    35,    31,    31,
      31,    31,    48,    32,    28,    57,    27,    45,     4,    32,
      33,    28,    45,    15,    53,     4,    33,    54,    31,    32,
      58,    45,    32,    33,    45,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    41,    41,
      42,    42,    43,    43,    43,    43,    43,    43,    44,    44,
      45,    45,    46,    46,    46,    46,    46,    47,    47,    48,
      48,    48,    49,    49,    49,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    52,    51,    54,    53,
      53,    56,    57,    55,    58,    55,    59,    59,    59,    60
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     8,     2,     0,     4,     5,     2,     3,     1,
       1,     4,     1,     1,     4,     4,     4,     4,     1,     1,
       2,     0,     1,     1,     1,     1,     2,     4,     7,     3,
       3,     1,     3,     3,     1,     1,     4,     1,     1,     3,
       4,     4,     4,     4,     2,     2,     0,     9,     0,     5,
       0,     0,     0,     9,     0,    14,     3,     3,     3,     5
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
#line 47 "syntaxique.y"
      {     
        if(nb_erreurs == 0){
        printf("Syntaxe Correcte\n");
        afficher_quads();
    }else{
        printf("\nCompilation echouee : %d erreur(s) detectee(s)\n", nb_erreurs);
     }
      }
#line 1246 "syntaxique.tab.c"
    break;

  case 6: /* DEC: CONST IDF AFFECT VAL_CONST PV  */
#line 59 "syntaxique.y"
                                   { inserer((yyvsp[-3].str), "CONST", 1, 0, 0); }
#line 1252 "syntaxique.tab.c"
    break;

  case 7: /* DEC: error PV  */
#line 61 "syntaxique.y"
      {
          printf("Erreur Syntaxique: ligne %d de declaration\n", nb_lignes);
          nb_erreurs++;
          yyerrok;
      }
#line 1262 "syntaxique.tab.c"
    break;

  case 10: /* OBJET: IDF  */
#line 72 "syntaxique.y"
           { 
         inserer((yyvsp[0].str), type_svg, 0, 0, 0); 
       }
#line 1270 "syntaxique.tab.c"
    break;

  case 11: /* OBJET: IDF CROCHG INT_VAL CROCHD  */
#line 75 "syntaxique.y"
                                 { 
         int t = atoi((yyvsp[-1].str));
         if(t <= 0) {printf("Erreur Semantique: ligne %d: taille de tableau invalide pour '%s'\n", nb_lignes, (yyvsp[-3].str));
                        nb_erreurs++;
         }else inserer((yyvsp[-3].str), type_svg, 0, 1, t); 
       }
#line 1281 "syntaxique.tab.c"
    break;

  case 18: /* TYPE: INTEGER  */
#line 85 "syntaxique.y"
              { strcpy(type_svg, "INTEGER"); }
#line 1287 "syntaxique.tab.c"
    break;

  case 19: /* TYPE: FLOAT  */
#line 86 "syntaxique.y"
            { strcpy(type_svg, "FLOAT"); }
#line 1293 "syntaxique.tab.c"
    break;

  case 26: /* INST: error PV  */
#line 91 "syntaxique.y"
      {
          printf("Erreur Syntaxique: ligne %d , col %d instruction fausse \n", nb_lignes, nb_col);
          nb_erreurs++;
          yyerrok;
      }
#line 1303 "syntaxique.tab.c"
    break;

  case 27: /* AFF: IDF AFFECT expression PV  */
#line 98 "syntaxique.y"
                              { 
    int p = rechercher((yyvsp[-3].str));
    if(p != -1) {
        if (strcmp((yyvsp[-1].str), "ID_ERR") == 0) {}
        else if(strcmp(table[p].type, "INTEGER") == 0 && contient_point_decimal((yyvsp[-1].str))) {
            printf("Erreur Semantique: ligne %d: incompatibilite de type, '%s' est INTEGER\n", nb_lignes, (yyvsp[-3].str));
            nb_erreurs++;
        }
        else if(table[p].estConstante) {
            printf("Erreur Semantique: ligne %d, Modif constante '%s'\n", nb_lignes, (yyvsp[-3].str));
            nb_erreurs++;
        }
        else {
            quad("=", (yyvsp[-1].str), "", (yyvsp[-3].str)); 
        }
    } else {
        printf("Erreur Semantique: ligne %d '%s' non declare\n", nb_lignes, (yyvsp[-3].str));
        nb_erreurs++;
    }
}
#line 1328 "syntaxique.tab.c"
    break;

  case 28: /* AFF: IDF CROCHG expression CROCHD AFFECT expression PV  */
#line 118 "syntaxique.y"
                                                       { 
    int p = rechercher((yyvsp[-6].str));
    if(p == -1) {
        printf("Erreur Semantique: ligne %d: tableau '%s' non declare\n", nb_lignes, (yyvsp[-6].str));
        nb_erreurs++;
    } else if (strcmp((yyvsp[-4].str), "ID_ERR") == 0 || strcmp((yyvsp[-1].str), "ID_ERR") == 0) {}
    else if(!table[p].estTableau) {
        printf("Erreur Semantique: ligne %d: '%s' n'est pas un tableau\n", nb_lignes, (yyvsp[-6].str));
        nb_erreurs++;
    }
    else if(table[p].estConstante) {
        printf("Erreur Semantique: ligne %d: '%s' est une constante, pas un tableau\n", nb_lignes, (yyvsp[-6].str));
        nb_erreurs++;
    } else {
        // --- DEBUT AJOUT VERIFICATION TYPE ---
        int p_val = rechercher((yyvsp[-1].str));
        int est_float = 0;
        
        // Si c'est une variable, on check son type dans la TS
        if(p_val != -1) {
            if(strcmp(table[p_val].type, "FLOAT") == 0) est_float = 1;
        } 
        // Si c'est une valeur directe (constante), on check le point decimal
        else if(contient_point_decimal((yyvsp[-1].str))) {
            est_float = 1;
        }

        if(strcmp(table[p].type, "INTEGER") == 0 && est_float) {
            printf("Erreur Semantique: ligne %d: incompatibilite de type, '%s' est INTEGER\n", nb_lignes, (yyvsp[-6].str));
            nb_erreurs++;
        }else {
        char res[30]; 
        sprintf(res, "%s[%s]", (yyvsp[-6].str), (yyvsp[-4].str));
        quad("=", (yyvsp[-1].str), "", res); 
    }
}
   }
#line 1370 "syntaxique.tab.c"
    break;

  case 29: /* expression: expression PLUS terme  */
#line 155 "syntaxique.y"
                                  { 
            if(strcmp((yyvsp[-2].str), "ID_ERR") == 0 || strcmp((yyvsp[0].str), "ID_ERR") == 0) (yyval.str) = "ID_ERR";
            else { (yyval.str) = new_temp(); quad("+", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
          }
#line 1379 "syntaxique.tab.c"
    break;

  case 30: /* expression: expression MOINS terme  */
#line 159 "syntaxique.y"
                                   { 
            if(strcmp((yyvsp[-2].str), "ID_ERR") == 0 || strcmp((yyvsp[0].str), "ID_ERR") == 0) (yyval.str) = "ID_ERR";
            else { (yyval.str) = new_temp(); quad("-", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
          }
#line 1388 "syntaxique.tab.c"
    break;

  case 31: /* expression: terme  */
#line 163 "syntaxique.y"
                  { (yyval.str) = (yyvsp[0].str); }
#line 1394 "syntaxique.tab.c"
    break;

  case 32: /* terme: terme MULT facteur  */
#line 165 "syntaxique.y"
                          { 
            if(strcmp((yyvsp[-2].str), "ID_ERR") == 0 || strcmp((yyvsp[0].str), "ID_ERR") == 0) (yyval.str) = "ID_ERR";
            else { (yyval.str) = new_temp(); quad("*", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
          }
#line 1403 "syntaxique.tab.c"
    break;

  case 33: /* terme: terme DIV facteur  */
#line 169 "syntaxique.y"
                         { 
            if(strcmp((yyvsp[-2].str), "ID_ERR") == 0 || strcmp((yyvsp[0].str), "ID_ERR") == 0) (yyval.str) = "ID_ERR";
            else if(strcmp((yyvsp[0].str), "0") == 0 || strcmp((yyvsp[0].str), "0.0") == 0) {
                printf("Erreur Semantique: ligne %d, Division par zero !\n", nb_lignes);
                nb_erreurs++;
                (yyval.str) = "ID_ERR"; 
            } else {
                (yyval.str) = new_temp(); quad("/", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); 
            }
       }
#line 1418 "syntaxique.tab.c"
    break;

  case 34: /* terme: facteur  */
#line 179 "syntaxique.y"
               { (yyval.str) = (yyvsp[0].str); }
#line 1424 "syntaxique.tab.c"
    break;

  case 35: /* facteur: IDF  */
#line 181 "syntaxique.y"
             { 
            if (rechercher((yyvsp[0].str)) == -1) {
                printf("Erreur Semantique: ligne %d: variable '%s' non declaree\n", nb_lignes, (yyvsp[0].str));
                nb_erreurs++;
                (yyval.str) = "ID_ERR"; 
            } else {
                int p = rechercher((yyvsp[0].str));
                if(p != -1 && table[p].estTableau) 
                    printf("Erreur Semantique: '%s' est un tableau, index requis\n", (yyvsp[0].str));
                (yyval.str) = (yyvsp[0].str); 
            }
         }
#line 1441 "syntaxique.tab.c"
    break;

  case 36: /* facteur: IDF CROCHG expression CROCHD  */
#line 193 "syntaxique.y"
                                      { 
            if (rechercher((yyvsp[-3].str)) == -1) {
                printf("Erreur Semantique: ligne %d: tableau '%s' non declare\n", nb_lignes, (yyvsp[-3].str));
                nb_erreurs++;
                (yyval.str) = "ID_ERR"; 
            } else if (strcmp((yyvsp[-1].str), "ID_ERR") == 0) {
                (yyval.str) = "ID_ERR";
            } else {
                int p = rechercher((yyvsp[-3].str));
                if(p != -1 && !table[p].estTableau) 
                    printf("Erreur Semantique: ligne %d, '%s' n'est pas un tableau\n", nb_lignes, (yyvsp[-3].str));
                    nb_erreurs++;
                char* t = malloc(30); sprintf(t, "%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str)); (yyval.str) = t; 
            }
         }
#line 1461 "syntaxique.tab.c"
    break;

  case 37: /* facteur: INT_VAL  */
#line 208 "syntaxique.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1467 "syntaxique.tab.c"
    break;

  case 38: /* facteur: FLOAT_VAL  */
#line 209 "syntaxique.y"
                   { (yyval.str) = (yyvsp[0].str); }
#line 1473 "syntaxique.tab.c"
    break;

  case 39: /* facteur: PARG expression PARD  */
#line 210 "syntaxique.y"
                              { (yyval.str) = (yyvsp[-1].str); }
#line 1479 "syntaxique.tab.c"
    break;

  case 40: /* facteur: PARG MOINS INT_VAL PARD  */
#line 211 "syntaxique.y"
                                 { char* t=malloc(25); sprintf(t,"-%s",(yyvsp[-1].str)); (yyval.str)=t; }
#line 1485 "syntaxique.tab.c"
    break;

  case 41: /* facteur: PARG PLUS INT_VAL PARD  */
#line 212 "syntaxique.y"
                                { char* r=malloc(20); sprintf(r,"+%s",(yyvsp[-1].str)); (yyval.str)=r; }
#line 1491 "syntaxique.tab.c"
    break;

  case 42: /* facteur: PARG MOINS FLOAT_VAL PARD  */
#line 213 "syntaxique.y"
                                   { char* temp = malloc(30); sprintf(temp, "-%s", (yyvsp[-1].str)); (yyval.str)= temp; }
#line 1497 "syntaxique.tab.c"
    break;

  case 43: /* facteur: PARG PLUS FLOAT_VAL PARD  */
#line 214 "syntaxique.y"
                                  {  char* temp = malloc(30); sprintf(temp, "+%s", (yyvsp[-1].str));(yyval.str) = temp;  }
#line 1503 "syntaxique.tab.c"
    break;

  case 44: /* facteur: MOINS INT_VAL  */
#line 215 "syntaxique.y"
                       { printf("Erreur Synt: ligne %d: parentheses manquantes\n", nb_lignes);nb_erreurs++; (yyval.str)="ID_ERR"; }
#line 1509 "syntaxique.tab.c"
    break;

  case 45: /* facteur: PLUS INT_VAL  */
#line 216 "syntaxique.y"
                      { printf("Erreur Synt: ligne %d: parentheses manquantes\n", nb_lignes);nb_erreurs++; (yyval.str)=(yyvsp[0].str); }
#line 1515 "syntaxique.tab.c"
    break;

  case 46: /* $@1: %empty  */
#line 221 "syntaxique.y"
      { 
        fin_if = prochain_quad(); 
        quad("BZ", "", (yyvsp[-1].str), ""); 
      }
#line 1524 "syntaxique.tab.c"
    break;

  case 47: /* COND: IF PARG EXPR_LOG PARD $@1 ACCOLG INSTS ACCOLD ELSE_PART  */
#line 225 "syntaxique.y"
                                    {
          sprintf(tmp_addr, "%d", prochain_quad());
          modifier_quad(fin_if, 3, tmp_addr);
      }
#line 1533 "syntaxique.tab.c"
    break;

  case 48: /* $@2: %empty  */
#line 231 "syntaxique.y"
           {
             deb_else = prochain_quad();
             quad("BR", "", "", "");
             sprintf(tmp_addr, "%d", prochain_quad());
             modifier_quad(fin_if, 3, tmp_addr);
             fin_if = deb_else; // On re-utilise fin_if pour le saut du else
           }
#line 1545 "syntaxique.tab.c"
    break;

  case 51: /* $@3: %empty  */
#line 243 "syntaxique.y"
              { deb_while = prochain_quad(); }
#line 1551 "syntaxique.tab.c"
    break;

  case 52: /* $@4: %empty  */
#line 245 "syntaxique.y"
        {
           cond_while = prochain_quad();
           quad("BZ", "", (yyvsp[-1].str), "");
        }
#line 1560 "syntaxique.tab.c"
    break;

  case 53: /* BOUCLE: WHILE $@3 PARG EXPR_LOG PARD $@4 ACCOLG INSTS ACCOLD  */
#line 250 "syntaxique.y"
        {
           sprintf(tmp_addr, "%d", deb_while);
           quad("BR", "", "", tmp_addr);
           sprintf(tmp_addr, "%d", prochain_quad());
           modifier_quad(cond_while, 3, tmp_addr);
        }
#line 1571 "syntaxique.tab.c"
    break;

  case 54: /* $@5: %empty  */
#line 257 "syntaxique.y"
        {
            // Initialisation i = debut
            quad("=", (yyvsp[-5].str), "", (yyvsp[-7].str));
            deb_while = prochain_quad(); // Debut du test
            char* t = new_temp();
            quad("BG", (yyvsp[-7].str), (yyvsp[-3].str), t); // i > fin ?
            cond_while = prochain_quad();
            quad("BZ", "", t, ""); 
        }
#line 1585 "syntaxique.tab.c"
    break;

  case 55: /* BOUCLE: FOR PARG IDF DEUXPTS INT_VAL DEUXPTS INT_VAL DEUXPTS INT_VAL PARD $@5 ACCOLG INSTS ACCOLD  */
#line 267 "syntaxique.y"
        {
            // i = i + pas
            char* t2 = new_temp();
            quad("+", (yyvsp[-11].str), (yyvsp[-5].str), t2);
            quad("=", t2, "", (yyvsp[-11].str));
            sprintf(tmp_addr, "%d", deb_while);
            quad("BR", "", "", tmp_addr);
            sprintf(tmp_addr, "%d", prochain_quad());
            modifier_quad(cond_while, 3, tmp_addr);
        }
#line 1600 "syntaxique.tab.c"
    break;

  case 56: /* EXPR_LOG: expression SUP expression  */
#line 278 "syntaxique.y"
                                    { (yyval.str) = new_temp(); quad("SUP", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
#line 1606 "syntaxique.tab.c"
    break;

  case 57: /* EXPR_LOG: expression INF expression  */
#line 279 "syntaxique.y"
                                    { (yyval.str) = new_temp(); quad("INF", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
#line 1612 "syntaxique.tab.c"
    break;

  case 58: /* EXPR_LOG: expression EGAL expression  */
#line 280 "syntaxique.y"
                                     { (yyval.str) = new_temp(); quad("EGAL", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
#line 1618 "syntaxique.tab.c"
    break;

  case 59: /* WRITE_I: WRITE PARG IDF PARD PV  */
#line 283 "syntaxique.y"
                                { 
    if(rechercher((yyvsp[-2].str)) == -1) {printf("Erreur Semantique: ligne %d, col %d, variable '%s' non declaree\n",nb_lignes, nb_col, (yyvsp[-2].str));nb_erreurs++;}
}
#line 1626 "syntaxique.tab.c"
    break;


#line 1630 "syntaxique.tab.c"

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

#line 287 "syntaxique.y"

void yyerror(const char* s) { printf("Erreur Syntaxique: ligne %d, col %d, pres de '%s'\n", nb_lignes, nb_col, yytext);nb_erreurs++; }
int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (f == NULL) {
            printf("impossible d'ouvrir %s\n", argv[1]);
            return 1;
        }
        yyin = f;
    }

    yyparse();
    return 0;
}
