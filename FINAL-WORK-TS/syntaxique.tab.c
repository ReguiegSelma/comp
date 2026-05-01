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
#include "opti.h"

extern int nb_lignes;
extern int nb_col;
extern char* yytext;
extern FILE *yyin; 
extern int nb_erreurs;

int fin_if, deb_else;
void yyerror(char *s);
int nb_erreurs = 0;
int yylex();
char type_svg[20];
char tmp_addr[10];
char type_const[20];

#line 94 "syntaxique.tab.c"

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
  YYSYMBOL_DIFF = 31,                      /* DIFF  */
  YYSYMBOL_PV = 32,                        /* PV  */
  YYSYMBOL_DEUXPTS = 33,                   /* DEUXPTS  */
  YYSYMBOL_VIRG = 34,                      /* VIRG  */
  YYSYMBOL_PARG = 35,                      /* PARG  */
  YYSYMBOL_PARD = 36,                      /* PARD  */
  YYSYMBOL_ACCOLG = 37,                    /* ACCOLG  */
  YYSYMBOL_ACCOLD = 38,                    /* ACCOLD  */
  YYSYMBOL_CROCHG = 39,                    /* CROCHG  */
  YYSYMBOL_CROCHD = 40,                    /* CROCHD  */
  YYSYMBOL_AND = 41,                       /* AND  */
  YYSYMBOL_OR = 42,                        /* OR  */
  YYSYMBOL_NOT = 43,                       /* NOT  */
  YYSYMBOL_LOWER_THAN_ELSE = 44,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_PROG = 46,                      /* PROG  */
  YYSYMBOL_DECLS = 47,                     /* DECLS  */
  YYSYMBOL_DEC = 48,                       /* DEC  */
  YYSYMBOL_TYPE = 49,                      /* TYPE  */
  YYSYMBOL_LISTE_OBJETS = 50,              /* LISTE_OBJETS  */
  YYSYMBOL_OBJET = 51,                     /* OBJET  */
  YYSYMBOL_DEC_CONST = 52,                 /* DEC_CONST  */
  YYSYMBOL_VAL_CONST = 53,                 /* VAL_CONST  */
  YYSYMBOL_INSTS = 54,                     /* INSTS  */
  YYSYMBOL_INST = 55,                      /* INST  */
  YYSYMBOL_AFF = 56,                       /* AFF  */
  YYSYMBOL_expression = 57,                /* expression  */
  YYSYMBOL_terme = 58,                     /* terme  */
  YYSYMBOL_facteur = 59,                   /* facteur  */
  YYSYMBOL_COND = 60,                      /* COND  */
  YYSYMBOL_61_1 = 61,                      /* $@1  */
  YYSYMBOL_62_2 = 62,                      /* $@2  */
  YYSYMBOL_ELSE_PART_MODIF = 63,           /* ELSE_PART_MODIF  */
  YYSYMBOL_BOUCLE = 64,                    /* BOUCLE  */
  YYSYMBOL_65_3 = 65,                      /* $@3  */
  YYSYMBOL_66_4 = 66,                      /* $@4  */
  YYSYMBOL_67_5 = 67,                      /* $@5  */
  YYSYMBOL_EXPR_LOG = 68,                  /* EXPR_LOG  */
  YYSYMBOL_WRITE_I = 69                    /* WRITE_I  */
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
#define YYLAST   217

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    47,    47,    59,    60,    61,    63,    65,    66,    69,
      70,    73,    76,    87,    90,    93,    96,    99,   104,   104,
     105,   105,   105,   105,   106,   115,   158,   211,   216,   223,
     242,   260,   263,   281,   307,   312,   329,   363,   370,   375,
     380,   385,   392,   395,   404,   411,   403,   427,   435,   444,
     446,   444,   463,   462,   510,   517,   524,   530,   537,   544,
     551,   558,   565,   572,   575
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
  "EGAL", "SUPEG", "INFEG", "DIFF", "PV", "DEUXPTS", "VIRG", "PARG",
  "PARD", "ACCOLG", "ACCOLD", "CROCHG", "CROCHD", "AND", "OR", "NOT",
  "LOWER_THAN_ELSE", "$accept", "PROG", "DECLS", "DEC", "TYPE",
  "LISTE_OBJETS", "OBJET", "DEC_CONST", "VAL_CONST", "INSTS", "INST",
  "AFF", "expression", "terme", "facteur", "COND", "$@1", "$@2",
  "ELSE_PART_MODIF", "BOUCLE", "$@3", "$@4", "$@5", "EXPR_LOG", "WRITE_I", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-45)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-20)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,    31,    42,    53,   -45,   158,   -45,   -45,    48,    76,
     158,    61,   158,    79,    96,   -45,   108,   -45,   161,   119,
      82,    93,   106,   -45,   -45,   -45,   -45,   104,   109,    -8,
     120,   139,   -45,   140,   144,    20,   -45,   -45,   -45,   -45,
     172,   -45,   108,   -45,   -45,   111,    70,    22,   174,   143,
     176,   -45,   -45,   141,   -45,   145,   -45,   -45,   -45,   -45,
      77,    38,    -4,   -45,   142,   -16,     6,    22,   132,    25,
     147,    22,   149,   -45,    84,   150,   -18,   111,   111,   -45,
     111,   111,   162,   163,   121,    67,   -45,   111,   111,   111,
     111,   111,   111,   -45,    22,    22,   179,   128,   157,   151,
      -7,   -45,   -45,    -4,    -4,   -45,   -45,   111,    92,   -45,
     123,   123,   123,   123,   123,   123,   153,   -45,   152,   159,
     -45,   -45,   -45,   -45,    47,   164,   102,    34,   190,   160,
     -45,   -45,   -45,   165,   166,    34,   -45,   191,   167,   181,
     168,   -45,   169,   -45,   -45,    34,   170,   171,    34,   -45,
     173,   -45
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     5,     7,     8,     0,     0,
       5,     0,     5,     0,     0,     3,     0,     4,     0,     0,
      11,     0,    10,    14,    15,    16,    17,     0,     0,     0,
       0,     0,    49,     0,     0,     0,    20,    21,    22,    23,
       0,     6,     0,    13,    24,     0,     0,     0,     0,     0,
       0,     2,    18,     0,     9,    35,    38,    39,    40,    41,
       0,     0,    31,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,     0,     0,     0,     0,     0,    25,
       0,     0,     0,     0,     0,     0,    56,     0,     0,     0,
       0,     0,     0,    44,     0,     0,     0,     0,     0,     0,
       0,    43,    42,    29,    30,    32,    33,     0,     0,    63,
      57,    58,    62,    59,    60,    61,     0,    55,    54,     0,
      50,    64,    37,    36,     0,     0,     0,     0,     0,     0,
      27,    28,    26,     0,     0,     0,    45,     0,     0,    48,
       0,    51,     0,    46,    52,     0,     0,     0,     0,    47,
       0,    53
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -45,   -45,   116,   -45,   -45,   175,   -45,   -45,   -45,   -35,
     -45,   -45,   -44,   -22,    52,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,    35,   -45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     9,    10,    11,    21,    22,    12,    27,    34,
      35,    36,    68,    62,    63,    37,   116,   139,   143,    38,
      49,   129,   146,    69,    39
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    61,    65,    77,    78,    77,    78,    75,     1,    55,
      56,    57,    58,    59,    77,    78,    76,    45,   102,    80,
      81,    28,    84,    29,    83,    55,    56,    57,    58,    59,
     100,    46,   -19,   123,     3,    28,    30,    29,    31,    32,
      33,    66,     4,   110,   111,   112,   113,   114,   115,    67,
      30,    13,    31,    32,    33,   103,   104,    66,   -19,    77,
      78,    93,     5,   124,   126,    67,    94,    95,    77,    78,
      79,    64,   -19,    55,    56,    57,    58,    59,    75,   130,
      55,    56,    57,    58,    59,    99,    14,    55,    56,    57,
      58,    59,   133,   125,    16,    55,    56,    57,    58,    59,
     138,    85,    86,   109,    18,    60,    97,    19,    94,    95,
     147,    20,    60,   150,    55,    56,    57,    58,    59,    60,
      28,    40,    29,    77,    78,    41,    15,    60,    17,   117,
     118,   -19,   105,   106,   132,    30,    43,    31,    32,    33,
      42,    44,    77,    78,    77,    78,    60,    87,    88,    89,
      90,    91,    92,    77,    78,    47,    51,   102,    87,    88,
      89,    90,    91,    92,   120,    23,    24,    25,    26,    94,
      95,     6,     7,     8,    48,    50,    53,    70,    71,    72,
      96,    73,    82,   119,    74,    98,   101,   107,   108,   121,
     127,   122,   128,    94,   134,   140,   131,   135,   142,   137,
       0,     0,     0,   136,   144,   141,   145,   148,     0,   149,
       0,   151,     0,     0,     0,     0,     0,    54
};

static const yytype_int16 yycheck[] =
{
      35,    45,    46,    21,    22,    21,    22,     1,     8,     3,
       4,     5,     6,     7,    21,    22,    60,    25,    36,    23,
      24,     1,    66,     3,    40,     3,     4,     5,     6,     7,
      74,    39,    12,    40,     3,     1,    16,     3,    18,    19,
      20,    35,     0,    87,    88,    89,    90,    91,    92,    43,
      16,     3,    18,    19,    20,    77,    78,    35,    38,    21,
      22,    36,     9,   107,   108,    43,    41,    42,    21,    22,
      32,     1,    38,     3,     4,     5,     6,     7,     1,    32,
       3,     4,     5,     6,     7,     1,    10,     3,     4,     5,
       6,     7,   127,     1,    33,     3,     4,     5,     6,     7,
     135,    66,    67,    36,    25,    35,    71,    11,    41,    42,
     145,     3,    35,   148,     3,     4,     5,     6,     7,    35,
       1,    39,     3,    21,    22,    32,    10,    35,    12,    94,
      95,    12,    80,    81,    32,    16,    32,    18,    19,    20,
      34,    32,    21,    22,    21,    22,    35,    26,    27,    28,
      29,    30,    31,    21,    22,    35,    12,    36,    26,    27,
      28,    29,    30,    31,    36,     4,     5,     6,     7,    41,
      42,    13,    14,    15,    35,    35,     4,     3,    35,     3,
      33,    40,    40,     4,    39,    36,    36,    25,    25,    32,
      37,    40,    33,    41,     4,     4,    32,    37,    17,    33,
      -1,    -1,    -1,    38,    36,    38,    37,    37,    -1,    38,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    46,     3,     0,     9,    13,    14,    15,    47,
      48,    49,    52,     3,    10,    47,    33,    47,    25,    11,
       3,    50,    51,     4,     5,     6,     7,    53,     1,     3,
      16,    18,    19,    20,    54,    55,    56,    60,    64,    69,
      39,    32,    34,    32,    32,    25,    39,    35,    35,    65,
      35,    12,    54,     4,    50,     3,     4,     5,     6,     7,
      35,    57,    58,    59,     1,    57,    35,    43,    57,    68,
       3,    35,     3,    40,    39,     1,    57,    21,    22,    32,
      23,    24,    40,    40,    57,    68,    68,    26,    27,    28,
      29,    30,    31,    36,    41,    42,    33,    68,    36,     1,
      57,    36,    36,    58,    58,    59,    59,    25,    25,    36,
      57,    57,    57,    57,    57,    57,    61,    68,    68,     4,
      36,    32,    40,    40,    57,     1,    57,    37,    33,    66,
      32,    32,    32,    54,     4,    37,    38,    33,    54,    62,
       4,    38,    17,    63,    36,    37,    67,    54,    37,    38,
      54,    38
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    47,    48,    49,    49,    50,
      50,    51,    51,    52,    53,    53,    53,    53,    54,    54,
      55,    55,    55,    55,    55,    56,    56,    56,    56,    57,
      57,    57,    58,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    61,    62,    60,    63,    63,    65,
      66,    64,    67,    64,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     8,     2,     2,     0,     4,     1,     1,     3,
       1,     1,     4,     5,     1,     1,     1,     1,     2,     0,
       1,     1,     1,     1,     2,     4,     7,     7,     7,     3,
       3,     1,     3,     3,     1,     1,     4,     4,     1,     1,
       1,     1,     3,     3,     0,     0,    10,     4,     0,     0,
       0,     9,     0,    14,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     5
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
#line 48 "syntaxique.y"
      {      
        if(nb_erreurs == 0){
            printf("Syntaxe Correcte\n");
            afficher_quads();
            optimiser_code();  // Optimisation complète
            YYACCEPT;
        }else{
            printf("\n Compilation echouee : %d erreur(s) detectee(s)\n", nb_erreurs);
        }
      }
#line 1266 "syntaxique.tab.c"
    break;

  case 7: /* TYPE: INTEGER  */
#line 65 "syntaxique.y"
              { strcpy(type_svg, "INTEGER"); }
#line 1272 "syntaxique.tab.c"
    break;

  case 8: /* TYPE: FLOAT  */
#line 66 "syntaxique.y"
              { strcpy(type_svg, "FLOAT"); }
#line 1278 "syntaxique.tab.c"
    break;

  case 11: /* OBJET: IDF  */
#line 73 "syntaxique.y"
           { 
        inserer((yyvsp[0].str), "idf", type_svg, 0, 0); 
     }
#line 1286 "syntaxique.tab.c"
    break;

  case 12: /* OBJET: IDF CROCHG INT_VAL CROCHD  */
#line 76 "syntaxique.y"
                                 { 
        // taille du tableau doit être > 0
        if ((yyvsp[-1].entier) <= 0) {
            printf("Erreur Semantique ligne %d: La taille du tableau '%s' doit etre positive (donnee: %d)\n", 
                    nb_lignes, (yyvsp[-3].str), (yyvsp[-1].entier));
            nb_erreurs++; 
        } else {
            inserer((yyvsp[-3].str), "tab", type_svg, 0, (yyvsp[-1].entier)); 
        }
     }
#line 1301 "syntaxique.tab.c"
    break;

  case 13: /* DEC_CONST: CONST IDF AFFECT VAL_CONST PV  */
#line 87 "syntaxique.y"
                                        { inserer((yyvsp[-3].str), "cst", type_const, (yyvsp[-1].reel), 0);}
#line 1307 "syntaxique.tab.c"
    break;

  case 14: /* VAL_CONST: INT_VAL  */
#line 91 "syntaxique.y"
      {  (yyval.reel) = (float)(yyvsp[0].entier);  strcpy(type_const, "INTEGER"); }
#line 1313 "syntaxique.tab.c"
    break;

  case 15: /* VAL_CONST: FLOAT_VAL  */
#line 94 "syntaxique.y"
      { (yyval.reel) = (yyvsp[0].reel);   strcpy(type_const, "FLOAT");}
#line 1319 "syntaxique.tab.c"
    break;

  case 16: /* VAL_CONST: ENT_SIGNE  */
#line 97 "syntaxique.y"
      { (yyval.reel) = (float)(yyvsp[0].entier); strcpy(type_const, "INTEGER"); }
#line 1325 "syntaxique.tab.c"
    break;

  case 17: /* VAL_CONST: REEL_SIGNE  */
#line 100 "syntaxique.y"
      { (yyval.reel) = (yyvsp[0].reel); strcpy(type_const, "FLOAT");
    
    }
#line 1333 "syntaxique.tab.c"
    break;

  case 24: /* INST: error PV  */
#line 106 "syntaxique.y"
               { 
        printf("Erreur Syntaxique ligne %d: ';' manquant ou instruction mal formee\n", nb_lignes);
        nb_erreurs++;
      }
#line 1342 "syntaxique.tab.c"
    break;

  case 25: /* AFF: IDF AFFECT expression PV  */
#line 115 "syntaxique.y"
                             {
        Symbole* s1 = rechercher((yyvsp[-3].str));
        if (s1 == NULL) {
            printf("Erreur Semantique ligne %d: Variable '%s' non declaree\n", nb_lignes, (yyvsp[-3].str));
            nb_erreurs++;
        } else if (strcmp(s1->code, "cst") == 0) {
            printf("Erreur Semantique ligne %d: Modification de la constante '%s' interdite\n", nb_lignes, (yyvsp[-3].str));
            nb_erreurs++;
        } else {
            Symbole* s3 = rechercher((yyvsp[-1].str));
            char* type_src;
            float val_src;

            // 1. On détermine le type et la valeur de ce qui arrive ($3)
            if (s3 != NULL) {
                type_src = s3->type;
                val_src = s3->val;
            } else {
                // Si c'est un chiffre direct (ex: 5 ou 5.5), on détecte son type
                type_src = (strchr((yyvsp[-1].str), '.')) ? "FLOAT" : "INTEGER";
                val_src = atof((yyvsp[-1].str));
            }

            // 2. Vérification de compatibilité avec (INT -> FLOAT)
            int compatible = 0;
            if (strcmp(s1->type, type_src) == 0) {
                compatible = 1; // Même type (INT=INT ou FLOAT=FLOAT)
            } else if (strcmp(s1->type, "FLOAT") == 0 && strcmp(type_src, "INTEGER") == 0) {
                compatible = 1; // Promotion : FLOAT = INTEGER (OK)
            }
            if (!compatible) {
                printf("Erreur Semantique ligne %d: Incompatibilite de type entre %s (%s) et %s (%s)\n", 
                        nb_lignes, (yyvsp[-3].str), s1->type, (yyvsp[-1].str), type_src);
                nb_erreurs++;
            }

            // 3. Mise à jour de la valeur et génération du Quad
            mettre_a_jour_val((yyvsp[-3].str), val_src);
            quad("=", (yyvsp[-1].str), "", (yyvsp[-3].str));
        }
    }
#line 1388 "syntaxique.tab.c"
    break;

  case 26: /* AFF: IDF CROCHG expression CROCHD AFFECT expression PV  */
#line 158 "syntaxique.y"
                                                        { 
        Symbole* p = rechercher((yyvsp[-6].str));     // Recherche du tableau
        Symbole* p_idx = rechercher((yyvsp[-4].str)); // Recherche si l'indice est une variable
        Symbole* p_src = rechercher((yyvsp[-1].str)); // Recherche si la source est une variable

        if(p == NULL) {
            printf("Erreur Semantique ligne %d: tableau '%s' non declare\n", nb_lignes, (yyvsp[-6].str));
            nb_erreurs++;
        } 
        else {
            // 1. Vérifier si c'est bien un tableau
            if(strcmp(p->code, "tab") != 0) {
                printf("Erreur Semantique ligne %d: '%s' n'est pas un tableau\n", nb_lignes, (yyvsp[-6].str));
                nb_erreurs++;
            } 
            
            // 2. Vérification de la borne (si l'indice est un nombre constant)(i+1, a )
            // On convertit le texte de l'indice en entier pour comparer
            float v_idx = (p_idx) ? p_idx->val : atof((yyvsp[-4].str));//pour verifier avec les bornnes dans la ts
            if (v_idx >= p->taille || v_idx < 0) {
                printf("Erreur Semantique ligne %d: index %.0f hors limites pour '%s' (taille %d)\n", 
                        nb_lignes, v_idx, (yyvsp[-6].str), p->taille);
                nb_erreurs++;
            } 
            // 3. Vérification des types
            char* type_source;
            if (p_src != NULL) {
                type_source = p_src->type;
            } else {
                // Détecter le type si c'est une valeur brute (chiffre)
                type_source = (strchr((yyvsp[-1].str), '.')) ? "FLOAT" : "INTEGER";
            }
            int compatible = 0;
            if (strcmp(p->type, type_source) == 0) {
                compatible = 1; // Types identiques
            } else if (strcmp(p->type, "FLOAT") == 0 && strcmp(type_source, "INTEGER") == 0) {
                compatible = 1; // Promotion : Tableau FLOAT accepte INTEGER
            }
            if (!compatible) {
                printf("Erreur Semantique ligne %d: incompatibilite de type entre le tableau %s (%s) et %s (%s)\n", 
                        nb_lignes, (yyvsp[-6].str), p->type, (yyvsp[-1].str), type_source);
                nb_erreurs++;
            }

            // 4. Génération du quadruplet
            // ne stocke qu'une valeur simple, pas tout le contenu du tableau
            char res[40];
            sprintf(res, "%s[%s]", (yyvsp[-6].str), (yyvsp[-4].str));
            quad("=", (yyvsp[-1].str), "", res);
        }
    }
#line 1444 "syntaxique.tab.c"
    break;

  case 27: /* AFF: IDF CROCHG error CROCHD AFFECT expression PV  */
#line 211 "syntaxique.y"
                                                  {
        printf("Erreur Syntaxique: ligne %d , col %d index invalide \n", nb_lignes, nb_col);
        nb_erreurs++;
        yyerrok;
     }
#line 1454 "syntaxique.tab.c"
    break;

  case 28: /* AFF: IDF CROCHG expression CROCHD AFFECT error PV  */
#line 216 "syntaxique.y"
                                                  {
        printf("Erreur Syntaxique: ligne %d , col %d expression invalide \n", nb_lignes, nb_col);
        nb_erreurs++;
        yyerrok;
     }
#line 1464 "syntaxique.tab.c"
    break;

  case 29: /* expression: expression PLUS terme  */
#line 223 "syntaxique.y"
                                  { 
                if(strcmp((yyvsp[-2].str), "empty") == 0 || strcmp((yyvsp[0].str), "empty") == 0) {
                    (yyval.str) = strdup("empty");
                } else {
                    Symbole* s1 = rechercher((yyvsp[-2].str));
                    Symbole* s3 = rechercher((yyvsp[0].str));
                    float v1 = (s1) ? obtenir_val((yyvsp[-2].str)) : atof((yyvsp[-2].str));
                    float v3 = (s3) ? obtenir_val((yyvsp[0].str)) : atof((yyvsp[0].str));

                    // Détermination du type du temporaire
                    char* type_res = "INTEGER";
                    if ((s1 && strcmp(s1->type, "FLOAT") == 0) || (s3 && strcmp(s3->type, "FLOAT") == 0)) 
                        type_res = "FLOAT";

                    (yyval.str) = new_temp(); 
                    quad("+", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); 
                    inserer((yyval.str), "temp", type_res, v1 + v3, 0); 
                }
            }
#line 1488 "syntaxique.tab.c"
    break;

  case 30: /* expression: expression MOINS terme  */
#line 242 "syntaxique.y"
                                   { 
                if(strcmp((yyvsp[-2].str), "empty") == 0 || strcmp((yyvsp[0].str), "empty") == 0) {
                    (yyval.str) = strdup("empty");
                } else {
                    Symbole* s1 = rechercher((yyvsp[-2].str));
                    Symbole* s3 = rechercher((yyvsp[0].str));
                    float v1 = (s1) ? obtenir_val((yyvsp[-2].str)) : atof((yyvsp[-2].str));
                    float v3 = (s3) ? obtenir_val((yyvsp[0].str)) : atof((yyvsp[0].str));

                    char* type_res = "INTEGER";
                    if ((s1 && strcmp(s1->type, "FLOAT") == 0) || (s3 && strcmp(s3->type, "FLOAT") == 0)) 
                        type_res = "FLOAT";

                    (yyval.str) = new_temp(); 
                    quad("-", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); 
                    inserer((yyval.str), "temp", type_res, v1 - v3, 0);
                }
            }
#line 1511 "syntaxique.tab.c"
    break;

  case 31: /* expression: terme  */
#line 260 "syntaxique.y"
                  { (yyval.str) = (yyvsp[0].str); }
#line 1517 "syntaxique.tab.c"
    break;

  case 32: /* terme: terme MULT facteur  */
#line 263 "syntaxique.y"
                          { 
            if(strcmp((yyvsp[-2].str), "empty") == 0 || strcmp((yyvsp[0].str), "empty") == 0) {
                (yyval.str) = strdup("empty");
            } else {
                Symbole* s1 = rechercher((yyvsp[-2].str));
                Symbole* s3 = rechercher((yyvsp[0].str));
                float v1 = (s1) ? obtenir_val((yyvsp[-2].str)) : atof((yyvsp[-2].str));
                float v3 = (s3) ? obtenir_val((yyvsp[0].str)) : atof((yyvsp[0].str));

                char* type_res = "INTEGER";
                if ((s1 && strcmp(s1->type, "FLOAT") == 0) || (s3 && strcmp(s3->type, "FLOAT") == 0)) 
                    type_res = "FLOAT";

                (yyval.str) = new_temp(); 
                quad("*", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); 
                inserer((yyval.str), "temp", type_res, v1 * v3, 0);
            }
        }
#line 1540 "syntaxique.tab.c"
    break;

  case 33: /* terme: terme DIV facteur  */
#line 281 "syntaxique.y"
                    { 
            if(strcmp((yyvsp[-2].str), "empty") == 0 || strcmp((yyvsp[0].str), "empty") == 0) {
                (yyval.str) = strdup("empty");
            } else {
                Symbole* s1 = rechercher((yyvsp[-2].str));
                Symbole* s3 = rechercher((yyvsp[0].str));
                float v1 = (s1) ? obtenir_val((yyvsp[-2].str)) : atof((yyvsp[-2].str));
                float v3 = (s3) ? obtenir_val((yyvsp[0].str)) : atof((yyvsp[0].str));

                if (v3 == 0) {
                    printf("Erreur Semantique ligne %d: Division par zero detectee !\n", nb_lignes);
                    nb_erreurs++;
                    (yyval.str) = strdup("empty");
                } else {
                    // Pour la division, on peut décider qu'elle donne toujours un FLOAT
                    // ou suivre la règle des entiers. Ici, on suit la règle mixte :
                    char* type_res = "INTEGER";
                    if ((s1 && strcmp(s1->type, "FLOAT") == 0) || (s3 && strcmp(s3->type, "FLOAT") == 0)) 
                        type_res = "FLOAT";

                    (yyval.str) = new_temp(); 
                    quad("/", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); 
                    inserer((yyval.str), "temp", type_res, v1 / v3, 0);
                }
            }
        }
#line 1571 "syntaxique.tab.c"
    break;

  case 34: /* terme: facteur  */
#line 307 "syntaxique.y"
               { (yyval.str) = (yyvsp[0].str); }
#line 1577 "syntaxique.tab.c"
    break;

  case 35: /* facteur: IDF  */
#line 312 "syntaxique.y"
        { 
        Symbole* s = rechercher((yyvsp[0].str));
        if (s == NULL) {
            printf("Erreur Semantique: variable '%s' non declaree ligne %d\n", (yyvsp[0].str), nb_lignes);
            nb_erreurs++;
            (yyval.str) = strdup("empty");
        } else {
            if (strcmp(s->code, "tab") == 0) {
                printf("Erreur Semantique: '%s' est un tableau, index requis ligne %d\n", (yyvsp[0].str), nb_lignes);
                nb_erreurs++;
                (yyval.str) = strdup("empty");
            } else {
                (yyval.str) = strdup((yyvsp[0].str));
            }
        }
    }
#line 1598 "syntaxique.tab.c"
    break;

  case 36: /* facteur: IDF CROCHG expression CROCHD  */
#line 329 "syntaxique.y"
                                   { 
        Symbole* s = rechercher((yyvsp[-3].str));
        if (s == NULL) {
            printf("Erreur Semantique: ligne %d: tableau '%s' non declare\n", nb_lignes, (yyvsp[-3].str));
            nb_erreurs++; 
            (yyval.str) = strdup("empty");
        } else {
            // 2. Vérification de la nature de l'objet
            if (strcmp(s->code, "tab") != 0) {
                printf("Erreur Semantique: ligne %d: '%s' n'est pas un tableau\n", nb_lignes, (yyvsp[-3].str));
                nb_erreurs++;
                (yyval.str) = strdup("empty");
            } else {
                // Si l'index est valide (pas empty), on vérifie la borne
                if (strcmp((yyvsp[-1].str), "empty") != 0) {
                    // On récupère la valeur numérique de l'index (soit le chiffre, soit la valeur de la variable)
                    float v_idx = (rechercher((yyvsp[-1].str))) ? obtenir_val((yyvsp[-1].str)) : atof((yyvsp[-1].str));
                    
                    if (v_idx >= s->taille || v_idx < 0) {
                        printf("Erreur Semantique ligne %d: index %.0f hors limites pour '%s' (taille %d)\n", 
                                nb_lignes, v_idx, (yyvsp[-3].str), s->taille);
                        nb_erreurs++;
                        yyerrok;
                    }
                }

                // 4. Construction du nom pour le quadruplet (ex: T[2] ou T[i])
                char* t = malloc(50);
                sprintf(t, "%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str));
                (yyval.str) = t; 
            }
        }
    }
#line 1636 "syntaxique.tab.c"
    break;

  case 37: /* facteur: IDF CROCHG error CROCHD  */
#line 363 "syntaxique.y"
                              {
        printf("Erreur Syntaxique: ligne %d , col %d index invalide \n", nb_lignes, nb_col);
        nb_erreurs++;
        yyerrok;
        (yyval.str) = strdup("empty");
    }
#line 1647 "syntaxique.tab.c"
    break;

  case 38: /* facteur: INT_VAL  */
#line 370 "syntaxique.y"
              { 
        char b[20]; 
        sprintf(b, "%d", (yyvsp[0].entier)); 
        (yyval.str) = strdup(b); 
    }
#line 1657 "syntaxique.tab.c"
    break;

  case 39: /* facteur: FLOAT_VAL  */
#line 375 "syntaxique.y"
                { 
        char b[20]; 
        sprintf(b, "%.2f", (yyvsp[0].reel)); 
        (yyval.str) = strdup(b); 
    }
#line 1667 "syntaxique.tab.c"
    break;

  case 40: /* facteur: ENT_SIGNE  */
#line 380 "syntaxique.y"
                { 
        char b[20]; 
        sprintf(b, "%d", (yyvsp[0].entier)); 
        (yyval.str) = strdup(b); 
    }
#line 1677 "syntaxique.tab.c"
    break;

  case 41: /* facteur: REEL_SIGNE  */
#line 385 "syntaxique.y"
                 { 
        char b[20]; 
        sprintf(b, "%.2f", (yyvsp[0].reel)); 
        (yyval.str) = strdup(b); 
    }
#line 1687 "syntaxique.tab.c"
    break;

  case 42: /* facteur: PARG expression PARD  */
#line 392 "syntaxique.y"
                           { (yyval.str) = (yyvsp[-1].str); }
#line 1693 "syntaxique.tab.c"
    break;

  case 43: /* facteur: PARG error PARD  */
#line 395 "syntaxique.y"
                      {
        printf("Erreur Syntaxique: ligne %d , col %d expression invalide \n", nb_lignes, nb_col);
        nb_erreurs++;
        yyerrok;
        (yyval.str) = strdup("empty");
    }
#line 1704 "syntaxique.tab.c"
    break;

  case 44: /* $@1: %empty  */
#line 404 "syntaxique.y"
      { 
        // 1. On génère le saut si FAUX (BZ)
        // On empile l'indice du quad pour le modifier plus tard
        push_if(prochain_quad()); 
        quad("BZ", "", (yyvsp[-1].str), ""); 
      }
#line 1715 "syntaxique.tab.c"
    break;

  case 45: /* $@2: %empty  */
#line 411 "syntaxique.y"
      {
        // 2. Fin du bloc IF : on doit sauter par-dessus le ELSE
        int q_bz = pop_if(); // On récupère l'adresse du BZ
        
        int q_br = prochain_quad();
        quad("BR", "", "", ""); // Saut inconditionnel vers la fin
        push_if(q_br); // On empile ce BR pour le patcher à la fin du ELSE
        
        // 3. On patche le BZ pour qu'il pointe vers le début du ELSE (ici)
        char tmp[10];
        sprintf(tmp, "%d", prochain_quad());
        modifier_quad(q_bz, 3, tmp);
      }
#line 1733 "syntaxique.tab.c"
    break;

  case 47: /* ELSE_PART_MODIF: ELSE ACCOLG INSTS ACCOLD  */
#line 428 "syntaxique.y"
      {
        // 4. On patche le BR de sortie du bloc IF
        int q_br = pop_if();
        char tmp[10];
        sprintf(tmp, "%d", prochain_quad());
        modifier_quad(q_br, 3, tmp);
      }
#line 1745 "syntaxique.tab.c"
    break;

  case 48: /* ELSE_PART_MODIF: %empty  */
#line 436 "syntaxique.y"
      {
        // Cas sans ELSE : on patche quand même le BR généré
        int q_br = pop_if();
        char tmp[10];
        sprintf(tmp, "%d", prochain_quad());
        modifier_quad(q_br, 3, tmp);
      }
#line 1757 "syntaxique.tab.c"
    break;

  case 49: /* $@3: %empty  */
#line 444 "syntaxique.y"
              { push_loop_start(prochain_quad()); }
#line 1763 "syntaxique.tab.c"
    break;

  case 50: /* $@4: %empty  */
#line 446 "syntaxique.y"
        {
           int q_bz = prochain_quad();
           quad("BZ", "", (yyvsp[-1].str), ""); 
           push_loop_cond(q_bz); // On mémorise l'adresse du BZ pour l'utiliser 
        }
#line 1773 "syntaxique.tab.c"
    break;

  case 51: /* BOUCLE: WHILE $@3 PARG EXPR_LOG PARD $@4 ACCOLG INSTS ACCOLD  */
#line 452 "syntaxique.y"
        {
           int cond = pop_loop_cond();
           int start = pop_loop_start();
           
           sprintf(tmp_addr, "%d", start);
           quad("BR", "", "", tmp_addr); // Retour au test de condition
           
           sprintf(tmp_addr, "%d", prochain_quad());
           modifier_quad(cond, 3, tmp_addr); // Sortie de boucle
        }
#line 1788 "syntaxique.tab.c"
    break;

  case 52: /* $@5: %empty  */
#line 463 "syntaxique.y"
        {
           // Initialisation : i = start_val
        // 1. Initialisation dans la TS pour la propagation
            mettre_a_jour_val((yyvsp[-7].str), (float)(yyvsp[-5].entier));

            // 2. Génération du quad d'initialisation (i = debut)
            char val_init[20]; sprintf(val_init, "%d", (yyvsp[-5].entier));
            quad("=", val_init, "", (yyvsp[-7].str));
            
            // 3. Mémoriser le début du test de borne
            push_loop_start(prochain_quad()); 
            
            // 4. Test de sortie : si i > limite, on crée un drapeau t
            char* t = new_temp();
            char val_limit[20]; sprintf(val_limit, "%d", (yyvsp[-3].entier));
            quad("BG", (yyvsp[-7].str), val_limit, t); 
            
            // 5. Saut si i > limite
            int q_bz = prochain_quad();
            quad("BZ", "", t, ""); 
            push_loop_cond(q_bz);
        }
#line 1815 "syntaxique.tab.c"
    break;

  case 53: /* BOUCLE: FOR PARG IDF DEUXPTS INT_VAL DEUXPTS INT_VAL DEUXPTS INT_VAL PARD $@5 ACCOLG INSTS ACCOLD  */
#line 486 "syntaxique.y"
        {
            // 6. Mise à jour de la valeur de l'index dans la TS (i = i + step)
            float v_current = obtenir_val((yyvsp[-11].str));
            mettre_a_jour_val((yyvsp[-11].str), v_current + (yyvsp[-5].entier));

            // 7. Génération du quad d'incrémentation
            char* t2 = new_temp();
            char val_step[20]; sprintf(val_step, "%d", (yyvsp[-5].entier));
            quad("+", (yyvsp[-11].str), val_step, t2);
            quad("=", t2, "", (yyvsp[-11].str));
            
            // 8. On récupère les adresses
            int cond_to_patch = pop_loop_cond();
            int loop_start = pop_loop_start();
            
            // 9. Bouclage
            sprintf(tmp_addr, "%d", loop_start);
            quad("BR", "", "", tmp_addr);
            
            // 10. Sortie définitive
            sprintf(tmp_addr, "%d", prochain_quad());
            modifier_quad(cond_to_patch, 3, tmp_addr);
        }
#line 1843 "syntaxique.tab.c"
    break;

  case 54: /* EXPR_LOG: EXPR_LOG OR EXPR_LOG  */
#line 510 "syntaxique.y"
                                { 
            float v1 = (rechercher((yyvsp[-2].str))) ? obtenir_val((yyvsp[-2].str)) : 0;
            float v3 = (rechercher((yyvsp[0].str))) ? obtenir_val((yyvsp[0].str)) : 0;
            (yyval.str) = new_temp(); 
            quad("OR", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); 
            inserer((yyval.str), "temp", "INTEGER", (v1 || v3) ? 1.0 : 0.0, 0);
        }
#line 1855 "syntaxique.tab.c"
    break;

  case 55: /* EXPR_LOG: EXPR_LOG AND EXPR_LOG  */
#line 517 "syntaxique.y"
                                { 
            float v1 = (rechercher((yyvsp[-2].str))) ? obtenir_val((yyvsp[-2].str)) : 0;
            float v3 = (rechercher((yyvsp[0].str))) ? obtenir_val((yyvsp[0].str)) : 0;
            (yyval.str) = new_temp(); 
            quad("AND", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); 
            inserer((yyval.str), "temp", "INTEGER", (v1 && v3) ? 1.0 : 0.0, 0);
        }
#line 1867 "syntaxique.tab.c"
    break;

  case 56: /* EXPR_LOG: NOT EXPR_LOG  */
#line 524 "syntaxique.y"
                       { 
            float v2 = (rechercher((yyvsp[0].str))) ? obtenir_val((yyvsp[0].str)) : 0;
            (yyval.str) = new_temp(); 
            quad("NOT", (yyvsp[0].str), "", (yyval.str)); 
            inserer((yyval.str), "temp", "INTEGER", (!v2) ? 1.0 : 0.0, 0);
        }
#line 1878 "syntaxique.tab.c"
    break;

  case 57: /* EXPR_LOG: expression SUP expression  */
#line 530 "syntaxique.y"
                                      { 
            float v1 = (rechercher((yyvsp[-2].str))) ? obtenir_val((yyvsp[-2].str)) : atof((yyvsp[-2].str));
            float v3 = (rechercher((yyvsp[0].str))) ? obtenir_val((yyvsp[0].str)) : atof((yyvsp[0].str));
            (yyval.str) = new_temp(); 
            quad("SUP", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); 
            inserer((yyval.str), "temp", "INTEGER", (v1 > v3) ? 1.0 : 0.0, 0);
        }
#line 1890 "syntaxique.tab.c"
    break;

  case 58: /* EXPR_LOG: expression INF expression  */
#line 537 "syntaxique.y"
                                      { 
            float v1 = (rechercher((yyvsp[-2].str))) ? obtenir_val((yyvsp[-2].str)) : atof((yyvsp[-2].str));
            float v3 = (rechercher((yyvsp[0].str))) ? obtenir_val((yyvsp[0].str)) : atof((yyvsp[0].str));
            (yyval.str) = new_temp(); 
            quad("INF", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); 
            inserer((yyval.str), "temp", "INTEGER", (v1 < v3) ? 1.0 : 0.0, 0);
        }
#line 1902 "syntaxique.tab.c"
    break;

  case 59: /* EXPR_LOG: expression SUPEG expression  */
#line 544 "syntaxique.y"
                                      { 
            float v1 = (rechercher((yyvsp[-2].str))) ? obtenir_val((yyvsp[-2].str)) : atof((yyvsp[-2].str));
            float v3 = (rechercher((yyvsp[0].str))) ? obtenir_val((yyvsp[0].str)) : atof((yyvsp[0].str));
            (yyval.str) = new_temp(); 
            quad("SUPEG", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); 
            inserer((yyval.str), "temp", "INTEGER", (v1 >= v3) ? 1.0 : 0.0, 0);
        }
#line 1914 "syntaxique.tab.c"
    break;

  case 60: /* EXPR_LOG: expression INFEG expression  */
#line 551 "syntaxique.y"
                                      { 
            float v1 = (rechercher((yyvsp[-2].str))) ? obtenir_val((yyvsp[-2].str)) : atof((yyvsp[-2].str));
            float v3 = (rechercher((yyvsp[0].str))) ? obtenir_val((yyvsp[0].str)) : atof((yyvsp[0].str));
            (yyval.str) = new_temp(); 
            quad("INFEG", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); 
            inserer((yyval.str), "temp", "INTEGER", (v1 <= v3) ? 1.0 : 0.0, 0);
        }
#line 1926 "syntaxique.tab.c"
    break;

  case 61: /* EXPR_LOG: expression DIFF expression  */
#line 558 "syntaxique.y"
                                      { 
            float v1 = (rechercher((yyvsp[-2].str))) ? obtenir_val((yyvsp[-2].str)) : atof((yyvsp[-2].str));
            float v3 = (rechercher((yyvsp[0].str))) ? obtenir_val((yyvsp[0].str)) : atof((yyvsp[0].str));
            (yyval.str) = new_temp(); 
            quad("DIFF", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); 
            inserer((yyval.str), "temp", "INTEGER", (v1 != v3) ? 1.0 : 0.0, 0);
        }
#line 1938 "syntaxique.tab.c"
    break;

  case 62: /* EXPR_LOG: expression EGAL expression  */
#line 565 "syntaxique.y"
                                      { 
            float v1 = (rechercher((yyvsp[-2].str))) ? obtenir_val((yyvsp[-2].str)) : atof((yyvsp[-2].str));
            float v3 = (rechercher((yyvsp[0].str))) ? obtenir_val((yyvsp[0].str)) : atof((yyvsp[0].str));
            (yyval.str) = new_temp(); 
            quad("EGAL", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); 
            inserer((yyval.str), "temp", "INTEGER", (v1 == v3) ? 1.0 : 0.0, 0);
        }
#line 1950 "syntaxique.tab.c"
    break;

  case 63: /* EXPR_LOG: PARG EXPR_LOG PARD  */
#line 572 "syntaxique.y"
                                { (yyval.str) = (yyvsp[-1].str); }
#line 1956 "syntaxique.tab.c"
    break;

  case 64: /* WRITE_I: WRITE PARG IDF PARD PV  */
#line 575 "syntaxique.y"
                                { 
    Symbole* s = rechercher((yyvsp[-2].str));
    if(s == NULL) { 
        printf("Erreur Semantique ligne %d: variable '%s' non declaree\n", nb_lignes, (yyvsp[-2].str));
        nb_erreurs++;
    } else {
        // Affiche le nom ET la valeur stockée dans la TS au moment de la compilation
        quad("WRITE", (yyvsp[-2].str), "", "");
        printf(" Variable %s = %.2f\n", s->name, s->val);
    }
}
#line 1972 "syntaxique.tab.c"
    break;


#line 1976 "syntaxique.tab.c"

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

#line 589 "syntaxique.y"


void yyerror(char *s) {}


int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (f) { yyin = f; }
        else {
            printf("Impossible d'ouvrir le fichier !\n");
            exit(1);
        }
    }
    
    yyparse();

    afficher_ts_ids();
    afficher_ts_kw();
    afficher_ts_sep();
    
    return 0;
}
