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
extern int nb_col;
extern char* yytext;
extern FILE *yyin; 
extern int nb_erreurs;

int nb_erreurs = 0;
int yylex();
void yyerror(const char* S);
char type_svg[20];
char tmp_addr[10];

#line 91 "syntaxique.tab.c"

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
  YYSYMBOL_ENT_SIGNE = 6,                  /* ENT_SIGNE  */
  YYSYMBOL_REEL_SIGNE = 7,                 /* REEL_SIGNE  */
  YYSYMBOL_PROGRAM = 8,                    /* PROGRAM  */
  YYSYMBOL_DECL = 9,                       /* DECL  */
  YYSYMBOL_ENDDECL = 10,                   /* ENDDECL  */
  YYSYMBOL_BEGIN_P = 11,                   /* BEGIN_P  */
  YYSYMBOL_END = 12,                       /* END  */
  YYSYMBOL_INTEGER = 13,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 14,                     /* FLOAT  */
  YYSYMBOL_CONST = 15,                     /* CONST  */
  YYSYMBOL_IF = 16,                        /* IF  */
  YYSYMBOL_ELSE = 17,                      /* ELSE  */
  YYSYMBOL_FOR = 18,                       /* FOR  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_WRITE = 20,                     /* WRITE  */
  YYSYMBOL_PLUS = 21,                      /* PLUS  */
  YYSYMBOL_MOINS = 22,                     /* MOINS  */
  YYSYMBOL_MULT = 23,                      /* MULT  */
  YYSYMBOL_DIV = 24,                       /* DIV  */
  YYSYMBOL_AFFECT = 25,                    /* AFFECT  */
  YYSYMBOL_SUP = 26,                       /* SUP  */
  YYSYMBOL_INF = 27,                       /* INF  */
  YYSYMBOL_EGAL = 28,                      /* EGAL  */
  YYSYMBOL_SUPEG = 29,                     /* SUPEG  */
  YYSYMBOL_INFEG = 30,                     /* INFEG  */
  YYSYMBOL_PV = 31,                        /* PV  */
  YYSYMBOL_DEUXPTS = 32,                   /* DEUXPTS  */
  YYSYMBOL_VIRG = 33,                      /* VIRG  */
  YYSYMBOL_PARG = 34,                      /* PARG  */
  YYSYMBOL_PARD = 35,                      /* PARD  */
  YYSYMBOL_ACCOLG = 36,                    /* ACCOLG  */
  YYSYMBOL_ACCOLD = 37,                    /* ACCOLD  */
  YYSYMBOL_CROCHG = 38,                    /* CROCHG  */
  YYSYMBOL_CROCHD = 39,                    /* CROCHD  */
  YYSYMBOL_AND = 40,                       /* AND  */
  YYSYMBOL_OR = 41,                        /* OR  */
  YYSYMBOL_NOT = 42,                       /* NOT  */
  YYSYMBOL_LOWER_THAN_ELSE = 43,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_PROG = 45,                      /* PROG  */
  YYSYMBOL_DECLS = 46,                     /* DECLS  */
  YYSYMBOL_DEC = 47,                       /* DEC  */
  YYSYMBOL_TYPE = 48,                      /* TYPE  */
  YYSYMBOL_LISTE_OBJETS = 49,              /* LISTE_OBJETS  */
  YYSYMBOL_OBJET = 50,                     /* OBJET  */
  YYSYMBOL_VAL_CONST = 51,                 /* VAL_CONST  */
  YYSYMBOL_INSTS = 52,                     /* INSTS  */
  YYSYMBOL_INST = 53,                      /* INST  */
  YYSYMBOL_AFF = 54,                       /* AFF  */
  YYSYMBOL_expression = 55,                /* expression  */
  YYSYMBOL_terme = 56,                     /* terme  */
  YYSYMBOL_facteur = 57,                   /* facteur  */
  YYSYMBOL_COND = 58,                      /* COND  */
  YYSYMBOL_59_1 = 59,                      /* $@1  */
  YYSYMBOL_60_2 = 60,                      /* $@2  */
  YYSYMBOL_ELSE_PART = 61,                 /* ELSE_PART  */
  YYSYMBOL_62_3 = 62,                      /* $@3  */
  YYSYMBOL_BOUCLE = 63,                    /* BOUCLE  */
  YYSYMBOL_64_4 = 64,                      /* $@4  */
  YYSYMBOL_65_5 = 65,                      /* $@5  */
  YYSYMBOL_66_6 = 66,                      /* $@6  */
  YYSYMBOL_EXPR_LOG = 67,                  /* EXPR_LOG  */
  YYSYMBOL_WRITE_I = 68                    /* WRITE_I  */
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
#define YYLAST   218

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    42,    42,    53,    53,    55,    56,    64,    65,    68,
      69,    72,    77,    87,    95,    95,    95,    95,    97,    97,
      98,    98,    98,    98,    99,   107,   133,   138,   176,   181,
     188,   196,   204,   207,   214,   226,   229,   245,   264,   270,
     271,   272,   273,   279,   280,   281,   282,   290,   289,   299,
     298,   307,   306,   315,   318,   320,   318,   334,   333,   355,
     356,   357,   358,   359,   360,   361,   366
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
  "FLOAT_VAL", "ENT_SIGNE", "REEL_SIGNE", "PROGRAM", "DECL", "ENDDECL",
  "BEGIN_P", "END", "INTEGER", "FLOAT", "CONST", "IF", "ELSE", "FOR",
  "WHILE", "WRITE", "PLUS", "MOINS", "MULT", "DIV", "AFFECT", "SUP", "INF",
  "EGAL", "SUPEG", "INFEG", "PV", "DEUXPTS", "VIRG", "PARG", "PARD",
  "ACCOLG", "ACCOLD", "CROCHG", "CROCHD", "AND", "OR", "NOT",
  "LOWER_THAN_ELSE", "$accept", "PROG", "DECLS", "DEC", "TYPE",
  "LISTE_OBJETS", "OBJET", "VAL_CONST", "INSTS", "INST", "AFF",
  "expression", "terme", "facteur", "COND", "$@1", "$@2", "ELSE_PART",
  "$@3", "BOUCLE", "$@4", "$@5", "$@6", "EXPR_LOG", "WRITE_I", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-38)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-20)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -2,    12,    22,    27,   -38,    19,    10,   -38,   -38,    40,
      19,    31,   -38,    56,   -38,    37,   101,    33,    90,    67,
      72,    83,   -14,    95,   138,   -38,   139,   133,    46,   -38,
     -38,   -38,   -38,   148,   129,   -38,    37,   -38,    76,    81,
       9,   171,   141,   173,   -38,   -38,   140,   158,   -38,   146,
     142,   -38,   -38,    69,   105,     7,   -38,   143,   -18,   149,
       4,    14,   121,   116,   151,    14,   150,   -38,   -38,   -38,
     -38,   -38,   147,   -38,    91,   152,   107,   162,    87,    84,
      84,   -38,    84,    84,   156,   161,   -38,   111,   118,   -38,
      84,    84,    84,   -38,    14,    14,   184,   120,   159,   -38,
     153,     6,   -38,   154,   160,   163,   164,   -38,     7,     7,
     -38,   -38,    84,    96,   155,   -38,   102,   102,   102,   157,
     -38,   165,   168,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   113,   166,   119,    41,    41,   190,   167,   -38,   -38,
     -38,   169,   170,   172,    41,   179,   179,   197,   174,   -38,
     -38,   -38,   175,   -38,   176,   -38,    41,   177,   178,    41,
     -38,   180,   -38
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     7,     8,     0,
       0,     0,     6,     0,     3,     0,     0,    11,     0,     0,
      10,     0,     0,     0,     0,    54,     0,     0,     0,    20,
      21,    22,    23,     0,     0,     5,     0,    24,     0,     0,
       0,     0,     0,     0,     2,    18,     0,     0,     9,     0,
      36,    39,    40,     0,     0,    32,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    12,    14,    15,
      16,    17,     0,    26,     0,     0,     0,     0,     0,     0,
       0,    25,     0,     0,     0,     0,    49,     0,     0,    61,
       0,     0,     0,    47,     0,     0,     0,     0,     0,    13,
       0,     0,    42,     0,     0,     0,     0,    41,    30,    31,
      33,    34,     0,     0,     0,    65,    62,    63,    64,     0,
      60,    59,     0,    55,    66,    38,    37,    44,    46,    43,
      45,     0,     0,     0,     0,     0,     0,     0,    28,    29,
      27,     0,     0,     0,     0,    53,    53,     0,     0,    51,
      50,    48,     0,    56,     0,    57,     0,     0,     0,     0,
      52,     0,    58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -38,   -38,   192,   -38,   -38,   182,   -38,   -38,   -28,   -38,
     -38,   -37,    89,    88,   -38,   -38,   -38,    62,   -38,   -38,
     -38,   -38,   -38,   -26,   -38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     9,    10,    11,    19,    20,    72,    27,    28,
      29,    62,    55,    56,    30,   119,   114,   150,   154,    31,
      42,   137,   157,    63,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    54,    58,    79,    80,    75,     1,    50,    51,    52,
      59,    38,    50,    51,    52,     3,    78,    50,    51,    52,
       6,    85,     4,    87,    39,    76,    77,    79,    80,    -4,
      82,    83,     7,     8,    88,    89,     5,   101,    60,    97,
      17,    12,    21,    60,    22,   126,    61,    21,    60,    22,
      13,    61,    18,   116,   117,   118,    61,    23,   -19,    24,
      25,    26,    23,    15,    24,    25,    26,    16,   120,   121,
      75,    33,    50,    51,    52,   131,   133,    49,   -19,    50,
      51,    52,    57,   -19,    50,    51,    52,    50,    51,    52,
      76,    77,   100,    34,    50,    51,    52,   132,    35,    50,
      51,    52,    21,    53,    22,    36,   141,   142,    79,    80,
      53,   103,   104,   -19,    37,    53,   148,    23,    53,    24,
      25,    26,   107,    79,    80,    53,    79,    80,   158,    40,
      53,   161,    79,    80,    79,    80,    81,    90,    91,    92,
      79,    80,    79,    80,   138,    44,   107,    90,    91,    92,
     140,    93,    46,   115,    47,   123,    94,    95,    94,    95,
      94,    95,    68,    69,    70,    71,   105,   106,   108,   109,
     110,   111,    41,    43,    64,    65,    66,    73,    99,    67,
      74,   112,    84,    96,    86,    98,   113,   102,   122,   127,
     124,   134,   125,   135,   143,   128,   149,   139,   129,   130,
     136,   152,    14,   144,   147,    94,   145,   146,   151,     0,
     155,   153,   156,   159,     0,   160,     0,   162,    48
};

static const yytype_int16 yycheck[] =
{
      28,    38,    39,    21,    22,     1,     8,     3,     4,     5,
       1,    25,     3,     4,     5,     3,    53,     3,     4,     5,
       1,    39,     0,    60,    38,    21,    22,    21,    22,    10,
      23,    24,    13,    14,    60,    61,     9,    74,    34,    65,
       3,    31,     1,    34,     3,    39,    42,     1,    34,     3,
      10,    42,    15,    90,    91,    92,    42,    16,    12,    18,
      19,    20,    16,    32,    18,    19,    20,    11,    94,    95,
       1,    38,     3,     4,     5,   112,   113,     1,    37,     3,
       4,     5,     1,    37,     3,     4,     5,     3,     4,     5,
      21,    22,     1,     3,     3,     4,     5,     1,    31,     3,
       4,     5,     1,    34,     3,    33,   134,   135,    21,    22,
      34,     4,     5,    12,    31,    34,   144,    16,    34,    18,
      19,    20,    35,    21,    22,    34,    21,    22,   156,    34,
      34,   159,    21,    22,    21,    22,    31,    26,    27,    28,
      21,    22,    21,    22,    31,    12,    35,    26,    27,    28,
      31,    35,     4,    35,    25,    35,    40,    41,    40,    41,
      40,    41,     4,     5,     6,     7,     4,     5,    79,    80,
      82,    83,    34,    34,     3,    34,     3,    31,    31,    39,
      38,    25,    39,    32,    35,    35,    25,    35,     4,    35,
      31,    36,    39,    36,     4,    35,    17,    31,    35,    35,
      32,     4,    10,    36,    32,    40,    37,    37,   146,    -1,
      35,    37,    36,    36,    -1,    37,    -1,    37,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    45,     3,     0,     9,     1,    13,    14,    46,
      47,    48,    31,    10,    46,    32,    11,     3,    15,    49,
      50,     1,     3,    16,    18,    19,    20,    52,    53,    54,
      58,    63,    68,    38,     3,    31,    33,    31,    25,    38,
      34,    34,    64,    34,    12,    52,     4,    25,    49,     1,
       3,     4,     5,    34,    55,    56,    57,     1,    55,     1,
      34,    42,    55,    67,     3,    34,     3,    39,     4,     5,
       6,     7,    51,    31,    38,     1,    21,    22,    55,    21,
      22,    31,    23,    24,    39,    39,    35,    55,    67,    67,
      26,    27,    28,    35,    40,    41,    32,    67,    35,    31,
       1,    55,    35,     4,     5,     4,     5,    35,    56,    56,
      57,    57,    25,    25,    60,    35,    55,    55,    55,    59,
      67,    67,     4,    35,    31,    39,    39,    35,    35,    35,
      35,    55,     1,    55,    36,    36,    32,    65,    31,    31,
      31,    52,    52,     4,    36,    37,    37,    32,    52,    17,
      61,    61,     4,    37,    62,    35,    36,    66,    52,    36,
      37,    52,    37
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    48,    48,    49,
      49,    50,    50,    50,    51,    51,    51,    51,    52,    52,
      53,    53,    53,    53,    53,    54,    54,    54,    54,    54,
      55,    55,    55,    56,    56,    56,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    59,    58,    60,
      58,    62,    61,    61,    64,    65,    63,    66,    63,    67,
      67,    67,    67,    67,    67,    67,    68
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     8,     2,     0,     4,     2,     1,     1,     3,
       1,     1,     4,     5,     1,     1,     1,     1,     2,     0,
       1,     1,     1,     1,     2,     4,     4,     7,     7,     7,
       3,     3,     1,     3,     3,     1,     1,     4,     4,     1,
       1,     3,     3,     4,     4,     4,     4,     0,     9,     0,
       9,     0,     5,     0,     0,     0,     9,     0,    14,     3,
       3,     2,     3,     3,     3,     3,     5
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
#line 43 "syntaxique.y"
      {      
        if(nb_erreurs == 0){
            printf("Syntaxe Correcte\n");
            YYACCEPT;
            afficher_quads();
        }else{
            printf("\n Compilation echouee : %d erreur(p) detectee(p)\n", nb_erreurs);
        }
      }
#line 1264 "syntaxique.tab.c"
    break;

  case 6: /* DEC: error PV  */
#line 57 "syntaxique.y"
      {
          printf("Erreur Syntaxique: ligne %d de declaration\n", nb_lignes);
          nb_erreurs++;
          yyerrok;
      }
#line 1274 "syntaxique.tab.c"
    break;

  case 7: /* TYPE: INTEGER  */
#line 64 "syntaxique.y"
              { strcpy(type_svg, "INTEGER"); }
#line 1280 "syntaxique.tab.c"
    break;

  case 8: /* TYPE: FLOAT  */
#line 65 "syntaxique.y"
            { strcpy(type_svg, "FLOAT"); }
#line 1286 "syntaxique.tab.c"
    break;

  case 11: /* OBJET: IDF  */
#line 72 "syntaxique.y"
           { 
        if (rechercher((yyvsp[0].str)) != -1) {printf("Erreur Semantique: Double declaration de %s ligne %d\n", (yyvsp[0].str), nb_lignes);
            nb_erreurs++;}
        else inserer((yyvsp[0].str), "IDF", type_svg, 0, 0); 
     }
#line 1296 "syntaxique.tab.c"
    break;

  case 12: /* OBJET: IDF CROCHG INT_VAL CROCHD  */
#line 77 "syntaxique.y"
                                 { 
         if((yyvsp[-1].entier) <= 0) {
            printf("Erreur Semantique: ligne %d: taille de tableau invalide pour '%s'\n", nb_lignes, (yyvsp[-3].str));
            nb_erreurs++;
            yyerrok;
         } else if (rechercher((yyvsp[-3].str)) != -1){ printf("Erreur Semantique: Double declaration ligne %d\n", nb_lignes);
            nb_erreurs++;
            yyerrok;}
        else inserer((yyvsp[-3].str), "TAB", type_svg, 0, (yyvsp[-1].entier));
       }
#line 1311 "syntaxique.tab.c"
    break;

  case 13: /* OBJET: CONST IDF AFFECT VAL_CONST PV  */
#line 87 "syntaxique.y"
                                     { 
        if (rechercher((yyvsp[-3].str)) != -1){ printf("Erreur Semantique: Double declaration ligne %d\n", nb_lignes);
        nb_erreurs++;
        yyerrok;
        }
        else inserer((yyvsp[-3].str), "CONST", type_svg, 0, 0); }
#line 1322 "syntaxique.tab.c"
    break;

  case 24: /* INST: error PV  */
#line 100 "syntaxique.y"
      {
          printf("Erreur Syntaxique: ligne %d , col %d instruction fausse \n", nb_lignes, nb_col);
          nb_erreurs++;
          yyerrok;
      }
#line 1332 "syntaxique.tab.c"
    break;

  case 25: /* AFF: IDF AFFECT expression PV  */
#line 107 "syntaxique.y"
                               {
    int pos1 = rechercher((yyvsp[-3].str));

    if (pos1 == -1) {
        printf("Erreur Semantique: %s non declare ligne %d\n", (yyvsp[-3].str), nb_lignes);
        nb_erreurs++;
    } 
    else if (tab[pos1].cst == 1) {
        printf("Erreur Semantique: Modification d'une constante '%s'\n", (yyvsp[-3].str));
        nb_erreurs++;
    } 
    else {
        int pos2 = rechercher((yyvsp[-1].str));

        // Si $3 est une variable → vérifier type
        if (pos2 != -1) {
            if (strcmp(tab[pos1].type, tab[pos2].type) != 0) {
                printf("Erreur Semantique: incompatibilite de type ligne %d\n", nb_lignes);
                nb_erreurs++;
            }
        }

        // génération du quad seulement si pas d'erreur critique
        quad("=", (yyvsp[-1].str), "", (yyvsp[-3].str));
    }
}
#line 1363 "syntaxique.tab.c"
    break;

  case 26: /* AFF: IDF AFFECT error PV  */
#line 133 "syntaxique.y"
                         {
        printf("Erreur Syntaxique: ligne %d , col %d expression invalide \n", nb_lignes, nb_col);
        nb_erreurs++;
        yyerrok;
     }
#line 1373 "syntaxique.tab.c"
    break;

  case 27: /* AFF: IDF CROCHG expression CROCHD AFFECT expression PV  */
#line 138 "syntaxique.y"
                                                       { 
    int p = rechercher((yyvsp[-6].str));
    int p2 = rechercher((yyvsp[-1].str));
    if(rechercher((yyvsp[-6].str)) == -1) {
        printf("Erreur Semantique: ligne %d: tableau '%s' non declare\n", nb_lignes, (yyvsp[-6].str));
        nb_erreurs++;
        yyerrok;
    } else if ((yyvsp[-4].str) <=tab[rechercher((yyvsp[-6].str))].taille || (yyvsp[-4].str) < 0) {
                printf("Erreur Semantique: ligne %d: index %d hors limites pour '%s' (taille %d)\n", nb_lignes, (yyvsp[-4].str), (yyvsp[-6].str), tab[p].taille);
                nb_erreurs++;
                yyerrok;
            }
        
        if(tab[rechercher((yyvsp[-6].str))].tab == 0) {
            printf("Erreur Semantique: ligne %d: '%s' n'est pas un tableau\n", nb_lignes, (yyvsp[-6].str));
            nb_erreurs++;
        } else if ( tab[rechercher((yyvsp[-6].str))].cst == 0) {
        printf("Erreur Semantique: ligne %d: '%s' est une constante\n", nb_lignes, (yyvsp[-6].str));
        nb_erreurs++;
        yyerrok;
        } else if (p2= -1) {
        if (strcmp(tab[rechercher((yyvsp[-6].str))].type, "INTEGER") == 0 && strcmp(tab[rechercher((yyvsp[-1].str))].type, "FLOAT") == 0) {
            printf("Erreur Semantique: ligne %d: incompatibilite de type sur '%s'\n", nb_lignes, (yyvsp[-6].str));
            nb_erreurs++;
            yyerrok;
        }}
        else {
            char res[30];
            sprintf(res, "%s[%s]", (yyvsp[-6].str), (yyvsp[-4].str));
            quad("=", (yyvsp[-1].str), "", res);

            if (rechercher((yyvsp[-1].str)) != -1) {
                tab[rechercher((yyvsp[-6].str))].valeur = tab[rechercher((yyvsp[-1].str))].valeur;
            } else {
                tab[rechercher((yyvsp[-6].str))].valeur = atof((yyvsp[-1].str));
            }
        }
    }
#line 1416 "syntaxique.tab.c"
    break;

  case 28: /* AFF: IDF CROCHG error CROCHD AFFECT expression PV  */
#line 176 "syntaxique.y"
                                                  {
        printf("Erreur Syntaxique: ligne %d , col %d index invalide \n", nb_lignes, nb_col);
        nb_erreurs++;
        yyerrok;
     }
#line 1426 "syntaxique.tab.c"
    break;

  case 29: /* AFF: IDF CROCHG expression CROCHD AFFECT error PV  */
#line 181 "syntaxique.y"
                                                  {
        printf("Erreur Syntaxique: ligne %d , col %d expression invalide \n", nb_lignes, nb_col);
        nb_erreurs++;
        yyerrok;
     }
#line 1436 "syntaxique.tab.c"
    break;

  case 30: /* expression: expression PLUS terme  */
#line 188 "syntaxique.y"
                                  {
    if(strcmp((yyvsp[-2].str), "empty")==0 || strcmp((yyvsp[0].str), "empty")==0)
        (yyval.str) = strdup("empty");
    else {
        (yyval.str) = new_temp();
        quad("+", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str));
    }
}
#line 1449 "syntaxique.tab.c"
    break;

  case 31: /* expression: expression MOINS terme  */
#line 196 "syntaxique.y"
                         {
    if(strcmp((yyvsp[-2].str), "empty")==0 || strcmp((yyvsp[0].str), "empty")==0)
        (yyval.str) = strdup("empty");
    else {
        (yyval.str) = new_temp();
        quad("-", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str));
    }
}
#line 1462 "syntaxique.tab.c"
    break;

  case 32: /* expression: terme  */
#line 204 "syntaxique.y"
        { (yyval.str) = (yyvsp[0].str); }
#line 1468 "syntaxique.tab.c"
    break;

  case 33: /* terme: terme MULT facteur  */
#line 207 "syntaxique.y"
                          {
    if(strcmp((yyvsp[-2].str),"empty")==0 || strcmp((yyvsp[0].str),"empty")==0)
        (yyval.str) = strdup("empty");
    else {
        (yyval.str) = new_temp();
        quad("*", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str));
    }}
#line 1480 "syntaxique.tab.c"
    break;

  case 34: /* terme: terme DIV facteur  */
#line 214 "syntaxique.y"
                    {
    if(strcmp((yyvsp[0].str),"0")==0 || strcmp((yyvsp[0].str),"0.0")==0) {
        printf("Erreur Semantique: Division par zero ligne %d\n", nb_lignes);
        nb_erreurs++;
        (yyval.str) = strdup("empty");
    } else if(strcmp((yyvsp[-2].str),"empty")==0 || strcmp((yyvsp[0].str),"empty")==0) {
        (yyval.str) = strdup("empty");
    } else {
        (yyval.str) = new_temp();
        quad("/", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str));
    }
}
#line 1497 "syntaxique.tab.c"
    break;

  case 35: /* terme: facteur  */
#line 226 "syntaxique.y"
          { (yyval.str) = (yyvsp[0].str); }
#line 1503 "syntaxique.tab.c"
    break;

  case 36: /* facteur: IDF  */
#line 229 "syntaxique.y"
             { 
            int pos = rechercher((yyvsp[0].str));
            if (pos == -1) {
             printf("Erreur Semantique: variable '%s' non declaree ligne %d\n", (yyvsp[0].str), nb_lignes);
             nb_erreurs++;
             (yyval.str) = strdup("empty");
            } 
            else {
                //tableau utilisé sans index
             if (tab[pos].tab != 0) {
                 printf("Erreur Semantique: '%s' est un tableau, index requis ligne %d\n", (yyvsp[0].str), nb_lignes);
                 nb_erreurs++;
                }
             (yyval.str) = strdup((yyvsp[0].str));
            }
        }
#line 1524 "syntaxique.tab.c"
    break;

  case 37: /* facteur: IDF CROCHG expression CROCHD  */
#line 245 "syntaxique.y"
                                      { 
            
            if (rechercher((yyvsp[-3].str)) == -1) {
                printf("Erreur Semantique: ligne %d: tableau '%s' non declare\n", nb_lignes, (yyvsp[-3].str));
                nb_erreurs++; (yyval.str)=strdup("empty");
            } else {
                if(tab[rechercher((yyvsp[-3].str))].tab != 0) {
                    printf("Erreur Semantique: ligne %d: '%s' n'est pas un tableau\n", nb_lignes, (yyvsp[-3].str));
                    nb_erreurs++;
                }
                if (strcmp(tab[pos].type, "INTEGER") == 0){
                    if ((yyvsp[-1].str) >= taille || (yyvsp[-1].str) < 0) {
                        printf("Erreur Semantique: ligne %d: index %d hors limites pour '%s'\n", nb_lignes, idx, (yyvsp[-3].str));
                        nb_erreurs++;
                    }
                }
                char* t = malloc(30); sprintf(t, "%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str)); (yyval.str) = t; 
            }
         }
#line 1548 "syntaxique.tab.c"
    break;

  case 38: /* facteur: IDF CROCHG error CROCHD  */
#line 264 "syntaxique.y"
                                 {
            printf("Erreur Syntaxique: ligne %d , col %d index invalide \n", nb_lignes, nb_col);
            nb_erreurs++;
            yyerrok;
            (yyval.str) = strdup("empty");
         }
#line 1559 "syntaxique.tab.c"
    break;

  case 39: /* facteur: INT_VAL  */
#line 270 "syntaxique.y"
                 { (yyval.str) = (yyvsp[0].entier); }
#line 1565 "syntaxique.tab.c"
    break;

  case 40: /* facteur: FLOAT_VAL  */
#line 271 "syntaxique.y"
                   { (yyval.str) = (yyvsp[0].reel); }
#line 1571 "syntaxique.tab.c"
    break;

  case 41: /* facteur: PARG expression PARD  */
#line 272 "syntaxique.y"
                              { (yyval.str) = (yyvsp[-1].str); }
#line 1577 "syntaxique.tab.c"
    break;

  case 42: /* facteur: PARG error PARD  */
#line 273 "syntaxique.y"
                         {
            printf("Erreur Syntaxique: ligne %d , col %d expression invalide \n", nb_lignes, nb_col);
            nb_erreurs++;
            yyerrok;
            (yyval.str) =strdup("empty");
         }
#line 1588 "syntaxique.tab.c"
    break;

  case 43: /* facteur: PARG MOINS INT_VAL PARD  */
#line 279 "syntaxique.y"
                                 { char* t=malloc(25); sprintf(t,"-%s",(yyvsp[-1].entier)); (yyval.str)=t; }
#line 1594 "syntaxique.tab.c"
    break;

  case 44: /* facteur: PARG PLUS INT_VAL PARD  */
#line 280 "syntaxique.y"
                                { char* r=malloc(20); sprintf(r,"+%s",(yyvsp[-1].entier)); (yyval.str)=r; }
#line 1600 "syntaxique.tab.c"
    break;

  case 45: /* facteur: PARG MOINS FLOAT_VAL PARD  */
#line 281 "syntaxique.y"
                                   { char* temp = malloc(30); sprintf(temp, "-%s", (yyvsp[-1].reel)); (yyval.str)= temp; }
#line 1606 "syntaxique.tab.c"
    break;

  case 46: /* facteur: PARG PLUS FLOAT_VAL PARD  */
#line 282 "syntaxique.y"
                                  { char* temp = malloc(30); sprintf(temp, "+%s", (yyvsp[-1].reel)); (yyval.str) = temp; }
#line 1612 "syntaxique.tab.c"
    break;

  case 47: /* $@1: %empty  */
#line 290 "syntaxique.y"
      { 
        fin_if = prochain_quad(); 
        quad("BZ", "", (yyvsp[-1].str), ""); 
      }
#line 1621 "syntaxique.tab.c"
    break;

  case 48: /* COND: IF PARG EXPR_LOG PARD $@1 ACCOLG INSTS ACCOLD ELSE_PART  */
#line 294 "syntaxique.y"
                                    {
          sprintf(tmp_addr, "%d", prochain_quad());
          modifier_quad(fin_if, 3, tmp_addr);
      }
#line 1630 "syntaxique.tab.c"
    break;

  case 49: /* $@2: %empty  */
#line 299 "syntaxique.y"
      {
        printf("Erreur Syntaxique: ligne %d , col %d condition invalide \n", nb_lignes, nb_col);
        nb_erreurs++;
        yyerrok;
      }
#line 1640 "syntaxique.tab.c"
    break;

  case 51: /* $@3: %empty  */
#line 307 "syntaxique.y"
           {
             deb_else = prochain_quad();
             quad("BR", "", "", "");
             sprintf(tmp_addr, "%d", prochain_quad());
             modifier_quad(fin_if, 3, tmp_addr);
             fin_if = deb_else;
           }
#line 1652 "syntaxique.tab.c"
    break;

  case 54: /* $@4: %empty  */
#line 318 "syntaxique.y"
              { push_loop_start(prochain_quad()); }
#line 1658 "syntaxique.tab.c"
    break;

  case 55: /* $@5: %empty  */
#line 320 "syntaxique.y"
        {
           prochain_quad();
           quad("BZ", "", (yyvsp[-1].str), "");
        }
#line 1667 "syntaxique.tab.c"
    break;

  case 56: /* BOUCLE: WHILE $@4 PARG EXPR_LOG PARD $@5 ACCOLG INSTS ACCOLD  */
#line 325 "syntaxique.y"
        {
           int cond = pop_loop_cond();
           int start = pop_loop_start();
           sprintf(tmp_addr, "%d", start);
           quad("BR", "", "", tmp_addr);
           sprintf(tmp_addr, "%d", prochain_quad());
           modifier_quad(cond, 3, tmp_addr);
        }
#line 1680 "syntaxique.tab.c"
    break;

  case 57: /* $@6: %empty  */
#line 334 "syntaxique.y"
        {
            quad("=", (yyvsp[-5].entier), "", (yyvsp[-7].str));
            prochain_quad(); 
            char* t = new_temp();
            quad("BG", (yyvsp[-7].str), (yyvsp[-3].entier), t); 
            prochain_quad();
            quad("BZ", "", t, ""); 
        }
#line 1693 "syntaxique.tab.c"
    break;

  case 58: /* BOUCLE: FOR PARG IDF DEUXPTS INT_VAL DEUXPTS INT_VAL DEUXPTS INT_VAL PARD $@6 ACCOLG INSTS ACCOLD  */
#line 343 "syntaxique.y"
        {
            char* t2 = new_temp();
            quad("+", (yyvsp[-11].str), (yyvsp[-5].entier), t2);
            quad("=", t2, "", (yyvsp[-11].str));
            int cond = 0;
            int start = 0;
            sprintf(tmp_addr, "%d", start);
            quad("BR", "", "", tmp_addr);
            sprintf(tmp_addr, "%d", prochain_quad());
            modifier_quad(cond, 3, tmp_addr);
        }
#line 1709 "syntaxique.tab.c"
    break;

  case 59: /* EXPR_LOG: EXPR_LOG OR EXPR_LOG  */
#line 355 "syntaxique.y"
                               { (yyval.str) = new_temp(); quad("OR", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
#line 1715 "syntaxique.tab.c"
    break;

  case 60: /* EXPR_LOG: EXPR_LOG AND EXPR_LOG  */
#line 356 "syntaxique.y"
                                { (yyval.str) = new_temp(); quad("AND", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
#line 1721 "syntaxique.tab.c"
    break;

  case 61: /* EXPR_LOG: NOT EXPR_LOG  */
#line 357 "syntaxique.y"
                       { (yyval.str) = new_temp(); quad("NOT", (yyvsp[0].str), "", (yyval.str)); }
#line 1727 "syntaxique.tab.c"
    break;

  case 62: /* EXPR_LOG: expression SUP expression  */
#line 358 "syntaxique.y"
                                    { (yyval.str) = new_temp(); quad("SUP", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
#line 1733 "syntaxique.tab.c"
    break;

  case 63: /* EXPR_LOG: expression INF expression  */
#line 359 "syntaxique.y"
                                    { (yyval.str) = new_temp(); quad("INF", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
#line 1739 "syntaxique.tab.c"
    break;

  case 64: /* EXPR_LOG: expression EGAL expression  */
#line 360 "syntaxique.y"
                                     { (yyval.str) = new_temp(); quad("EGAL", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
#line 1745 "syntaxique.tab.c"
    break;

  case 65: /* EXPR_LOG: PARG EXPR_LOG PARD  */
#line 361 "syntaxique.y"
                             { (yyval.str) = (yyvsp[-1].str); }
#line 1751 "syntaxique.tab.c"
    break;

  case 66: /* WRITE_I: WRITE PARG IDF PARD PV  */
#line 366 "syntaxique.y"
                                { 
    if(rechercher((yyvsp[-2].str)) ==-1){ printf("Erreur Semantique: ligne %d, variable '%s' non declaree\n",nb_lignes, (yyvsp[-2].str));nb_erreurs++;}
}
#line 1759 "syntaxique.tab.c"
    break;


#line 1763 "syntaxique.tab.c"

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

#line 373 "syntaxique.y"

void yyerror(const char* p) { 
    printf("Erreur Syntaxique: ligne %d, col %d, pres de '%s'\n", nb_lignes, nb_col, yytext);nb_erreurs++; 
    }
int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (f){ yyin = f;}
        else {
            printf("Can't open!\n");
            exit(1);
        }
    }
    yyparse();
    afficher_ts_ids();
    afficher_ts_kw();
    afficher_ts_sep();
    return 0;
}
