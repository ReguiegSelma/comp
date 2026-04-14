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

// Fonction pour vérifier si une chaîne est un entier non signe
int est_un_entier(char* s) {
    if (s == NULL || *s == '\0' || strcmp(s, "ID_ERR") == 0) return 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] < '0' || s[i] > '9') return 0;
    }
    return 1;
}

char tmp_addr[10];
int fin_if, deb_else;

#define LOOP_STACK_MAX 128
int loop_start[LOOP_STACK_MAX];
int loop_cond[LOOP_STACK_MAX];
int loop_top = -1;

void push_loop_start(int start) {
    if (loop_top + 1 >= LOOP_STACK_MAX) {
        printf("Erreur interne: pile de boucles pleine\n");
        return;
    }
    loop_top++;
    loop_start[loop_top] = start;
    loop_cond[loop_top] = -1;
}

void set_loop_cond(int cond) {
    if (loop_top < 0) return;
    loop_cond[loop_top] = cond;
}

int pop_loop_start() {
    if (loop_top < 0) return -1;
    return loop_start[loop_top];
}

int pop_loop_cond() {
    if (loop_top < 0) return -1;
    return loop_cond[loop_top--];
}

extern int nb_lignes;
extern int nb_col;
extern char* yytext;
extern FILE *yyin; 

int nb_erreurs = 0;
int yylex();
void yyerror(const char* s);
char type_svg[20];

#line 138 "syntaxique.tab.c"

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
  YYSYMBOL_56_2 = 56,                      /* $@2  */
  YYSYMBOL_ELSE_PART = 57,                 /* ELSE_PART  */
  YYSYMBOL_58_3 = 58,                      /* $@3  */
  YYSYMBOL_BOUCLE = 59,                    /* BOUCLE  */
  YYSYMBOL_60_4 = 60,                      /* $@4  */
  YYSYMBOL_61_5 = 61,                      /* $@5  */
  YYSYMBOL_62_6 = 62,                      /* $@6  */
  YYSYMBOL_EXPR_LOG = 63,                  /* EXPR_LOG  */
  YYSYMBOL_WRITE_I = 64                    /* WRITE_I  */
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
#define YYLAST   234

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  172

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
static const yytype_int16 yyrline[] =
{
       0,    88,    88,    98,    98,   100,   101,   102,   110,   111,
     114,   117,   126,   126,   126,   126,   126,   126,   128,   129,
     131,   131,   132,   132,   132,   132,   133,   141,   177,   182,
     232,   237,   243,   247,   251,   253,   257,   272,   274,   287,
     307,   313,   314,   315,   316,   322,   323,   324,   325,   333,
     332,   342,   341,   350,   349,   358,   361,   363,   361,   377,
     376,   398,   399,   400,   401,   402,   403,   404,   409
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
  "expression", "terme", "facteur", "COND", "$@1", "$@2", "ELSE_PART",
  "$@3", "BOUCLE", "$@4", "$@5", "$@6", "EXPR_LOG", "WRITE_I", YY_NULLPTR
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
       3,     1,    34,    61,   -46,    12,    37,   -46,   -46,    67,
      70,    12,    53,   -46,    65,    75,   -46,   101,    42,   119,
      74,   118,   123,   -46,   -46,    -2,   129,   147,     4,   100,
     148,   -46,   150,   167,    49,   -46,   -46,   -46,   -46,   162,
     -46,   101,    26,    95,   -46,   -46,    88,    93,     7,   176,
     151,   179,   -46,   -46,   152,   -46,   153,   154,   155,   157,
     163,   158,   -46,   -46,    82,   124,   103,   -46,   159,    16,
     160,     2,    11,   139,    17,   161,    11,   164,   -46,   -46,
     -46,   -46,   -46,   -46,   102,   165,   134,   156,    97,    39,
      39,   -46,    39,    39,   170,   174,   -46,   122,    90,   -46,
      39,    39,    39,   -46,    11,    11,   194,   136,   172,   166,
      60,   -46,   169,   171,   173,   175,   -46,   103,   103,   -46,
     -46,    39,   110,   177,   -46,   149,   149,   149,   178,   -46,
     180,   183,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
     130,   181,   135,    57,    57,   199,   182,   -46,   -46,   -46,
     184,   185,   187,    57,   168,   168,   201,   186,   -46,   -46,
     -46,   189,   -46,   190,   -46,    57,   191,   188,    57,   -46,
     192,   -46
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,    18,    19,     0,
       0,     0,     0,     7,     0,     0,     3,     0,     0,     0,
      10,     0,     9,    12,    13,     0,     0,     0,     0,     0,
       0,    56,     0,     0,     0,    22,    23,    24,    25,     0,
       5,     0,     0,     0,     6,    26,     0,     0,     0,     0,
       0,     0,     2,    20,     0,     8,     0,     0,     0,     0,
       0,    38,    41,    42,     0,     0,    34,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    16,
      17,    14,    15,    28,     0,     0,     0,     0,     0,     0,
       0,    27,     0,     0,     0,     0,    51,     0,     0,    63,
       0,     0,     0,    49,     0,     0,     0,     0,     0,     0,
       0,    44,     0,     0,     0,     0,    43,    32,    33,    35,
      36,     0,     0,     0,    67,    64,    65,    66,     0,    62,
      61,     0,    57,    68,    40,    39,    46,    48,    45,    47,
       0,     0,     0,     0,     0,     0,     0,    30,    31,    29,
       0,     0,     0,     0,    55,    55,     0,     0,    53,    52,
      50,     0,    58,     0,    59,     0,     0,     0,     0,    54,
       0,    60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -46,   -46,   196,   -46,   193,   -46,   -46,   -46,   -34,   -46,
     -46,   -45,    81,    83,   -46,   -46,   -46,    58,   -46,   -46,
     -46,   -46,   -46,   -43,   -46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,    10,    11,    21,    22,    26,    12,    33,    34,
      35,    73,    66,    67,    36,   128,   123,   159,   163,    37,
      50,   146,   166,    74,    38
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    65,    69,    85,     3,    61,    62,    63,    70,     1,
      61,    62,    63,     6,    61,    62,    63,    42,    43,    88,
      -4,    86,    87,     7,     8,     9,    97,    46,    98,    99,
      56,    57,    71,   107,     4,    89,    90,    71,    47,   110,
      72,    71,    61,    62,    63,    72,    23,    24,   103,    72,
      27,    95,    28,   104,   105,   125,   126,   127,    27,   -21,
      28,   129,   130,    29,    13,    30,    31,    32,     5,    64,
      14,    29,    25,    30,    31,    32,   140,   142,    15,    89,
      90,    17,   -21,    85,    19,    61,    62,    63,    18,    60,
     -21,    61,    62,    63,    68,   135,    61,    62,    63,    58,
      59,    86,    87,   109,    20,    61,    62,    63,    39,   150,
     151,   141,    64,    61,    62,    63,    89,    90,    64,   157,
      27,   124,    28,    64,    92,    93,   104,   105,   116,   -21,
      48,   167,    64,    29,   170,    30,    31,    32,   112,   113,
      64,    89,    90,    89,    90,    40,   100,   101,   102,    89,
      90,    91,    41,   116,    89,    90,    44,   147,    89,    90,
     114,   115,   149,   100,   101,   102,    54,   132,    89,    90,
     117,   118,   104,   105,    45,   119,   120,    52,    49,    75,
      51,    76,    77,   158,    79,    80,    81,    78,    82,   106,
      83,    96,    84,   121,    94,   108,   111,   122,   131,   133,
     136,   134,   137,   152,   138,   161,   139,    16,   148,   143,
     144,   145,     0,   160,   153,   156,   104,   154,   155,   162,
     164,   169,   165,   168,     0,   171,     0,     0,     0,     0,
       0,     0,     0,     0,    55
};

static const yytype_int16 yycheck[] =
{
      34,    46,    47,     1,     3,     3,     4,     5,     1,     6,
       3,     4,     5,     1,     3,     4,     5,    19,    20,    64,
       8,    19,    20,    11,    12,    13,    71,    23,    71,    72,
       4,     5,    30,    76,     0,    19,    20,    30,    34,    84,
      38,    30,     3,     4,     5,    38,     4,     5,    31,    38,
       1,    35,     3,    36,    37,   100,   101,   102,     1,    10,
       3,   104,   105,    14,    27,    16,    17,    18,     7,    30,
       3,    14,    30,    16,    17,    18,   121,   122,     8,    19,
      20,    28,    33,     1,     9,     3,     4,     5,    23,     1,
      33,     3,     4,     5,     1,    35,     3,     4,     5,     4,
       5,    19,    20,     1,     3,     3,     4,     5,    34,   143,
     144,     1,    30,     3,     4,     5,    19,    20,    30,   153,
       1,    31,     3,    30,    21,    22,    36,    37,    31,    10,
      30,   165,    30,    14,   168,    16,    17,    18,     4,     5,
      30,    19,    20,    19,    20,    27,    24,    25,    26,    19,
      20,    27,    29,    31,    19,    20,    27,    27,    19,    20,
       4,     5,    27,    24,    25,    26,     4,    31,    19,    20,
      89,    90,    36,    37,    27,    92,    93,    10,    30,     3,
      30,    30,     3,    15,    31,    31,    31,    35,    31,    28,
      27,    31,    34,    23,    35,    31,    31,    23,     4,    27,
      31,    35,    31,     4,    31,     4,    31,    11,    27,    32,
      32,    28,    -1,   155,    32,    28,    36,    33,    33,    33,
      31,    33,    32,    32,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    41,     3,     0,     7,     1,    11,    12,    13,
      42,    43,    47,    27,     3,     8,    42,    28,    23,     9,
       3,    44,    45,     4,     5,    30,    46,     1,     3,    14,
      16,    17,    18,    48,    49,    50,    54,    59,    64,    34,
      27,    29,    19,    20,    27,    27,    23,    34,    30,    30,
      60,    30,    10,    48,     4,    44,     4,     5,     4,     5,
       1,     3,     4,     5,    30,    51,    52,    53,     1,    51,
       1,    30,    38,    51,    63,     3,    30,     3,    35,    31,
      31,    31,    31,    27,    34,     1,    19,    20,    51,    19,
      20,    27,    21,    22,    35,    35,    31,    51,    63,    63,
      24,    25,    26,    31,    36,    37,    28,    63,    31,     1,
      51,    31,     4,     5,     4,     5,    31,    52,    52,    53,
      53,    23,    23,    56,    31,    51,    51,    51,    55,    63,
      63,     4,    31,    27,    35,    35,    31,    31,    31,    31,
      51,     1,    51,    32,    32,    28,    61,    27,    27,    27,
      48,    48,     4,    32,    33,    33,    28,    48,    15,    57,
      57,     4,    33,    58,    31,    32,    62,    48,    32,    33,
      48,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    44,    44,
      45,    45,    46,    46,    46,    46,    46,    46,    47,    47,
      48,    48,    49,    49,    49,    49,    49,    50,    50,    50,
      50,    50,    51,    51,    51,    52,    52,    52,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    55,
      54,    56,    54,    58,    57,    57,    60,    61,    59,    62,
      59,    63,    63,    63,    63,    63,    63,    63,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     8,     2,     0,     4,     5,     2,     3,     1,
       1,     4,     1,     1,     4,     4,     4,     4,     1,     1,
       2,     0,     1,     1,     1,     1,     2,     4,     4,     7,
       7,     7,     3,     3,     1,     3,     3,     1,     1,     4,
       4,     1,     1,     3,     3,     4,     4,     4,     4,     0,
       9,     0,     9,     0,     5,     0,     0,     0,     9,     0,
      14,     3,     3,     2,     3,     3,     3,     3,     5
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
#line 89 "syntaxique.y"
      {      
        if(nb_erreurs == 0){
            printf("Syntaxe Correcte\n");
            afficher_quads();
        }else{
            printf("\nCompilation echouee : %d erreur(s) detectee(s)\n", nb_erreurs);
        }
      }
#line 1312 "syntaxique.tab.c"
    break;

  case 6: /* DEC: CONST IDF AFFECT VAL_CONST PV  */
#line 101 "syntaxique.y"
                                   { inserer((yyvsp[-3].str), "CONST", 1, 0, 0); }
#line 1318 "syntaxique.tab.c"
    break;

  case 7: /* DEC: error PV  */
#line 103 "syntaxique.y"
      {
          printf("Erreur Syntaxique: ligne %d de declaration\n", nb_lignes);
          nb_erreurs++;
          yyerrok;
      }
#line 1328 "syntaxique.tab.c"
    break;

  case 10: /* OBJET: IDF  */
#line 114 "syntaxique.y"
           { 
         inserer((yyvsp[0].str), type_svg, 0, 0, 0); 
       }
#line 1336 "syntaxique.tab.c"
    break;

  case 11: /* OBJET: IDF CROCHG INT_VAL CROCHD  */
#line 117 "syntaxique.y"
                                 { 
         int t = atoi((yyvsp[-1].str));
         if(t <= 0) {
            printf("Erreur Semantique: ligne %d: taille de tableau invalide pour '%s'\n", nb_lignes, (yyvsp[-3].str));
            nb_erreurs++;
         } else inserer((yyvsp[-3].str), type_svg, 0, 1, t); 
       }
#line 1348 "syntaxique.tab.c"
    break;

  case 18: /* TYPE: INTEGER  */
#line 128 "syntaxique.y"
              { strcpy(type_svg, "INTEGER"); }
#line 1354 "syntaxique.tab.c"
    break;

  case 19: /* TYPE: FLOAT  */
#line 129 "syntaxique.y"
            { strcpy(type_svg, "FLOAT"); }
#line 1360 "syntaxique.tab.c"
    break;

  case 26: /* INST: error PV  */
#line 134 "syntaxique.y"
      {
          printf("Erreur Syntaxique: ligne %d , col %d instruction fausse \n", nb_lignes, nb_col);
          nb_erreurs++;
          yyerrok;
      }
#line 1370 "syntaxique.tab.c"
    break;

  case 27: /* AFF: IDF AFFECT expression PV  */
#line 141 "syntaxique.y"
                              { 
    Symbole* s = rechercher((yyvsp[-3].str));
    if(s != NULL) {
        int ok = 1;
        if (strcmp((yyvsp[-1].str), "ID_ERR") == 0) { ok = 0; }
        if(strcmp(s->type, "INTEGER") == 0 && contient_point_decimal((yyvsp[-1].str))) {
            printf("Erreur Semantique: ligne %d: incompatibilite de type, '%s' est INTEGER\n", nb_lignes, (yyvsp[-3].str));
            nb_erreurs++;
            ok = 0;
        }
        if(s->estConstante) {
            printf("Erreur Semantique: ligne %d, Modif constante '%s'\n", nb_lignes, (yyvsp[-3].str));
            nb_erreurs++;
            ok = 0;
        }
        if (ok) {
            // Mémorisation de la valeur pour la propagation de constante
            if (est_un_entier((yyvsp[-1].str))) {
                s->valeur = atof((yyvsp[-1].str));
                s->a_une_valeur = 1;
            } else {
                Symbole* rhs = rechercher((yyvsp[-1].str));
                if (rhs != NULL && rhs->a_une_valeur) {
                    s->valeur = rhs->valeur;
                    s->a_une_valeur = 1;
                } else {
                    s->a_une_valeur = 0; // valeur inconnue
                }
            }
            quad("=", (yyvsp[-1].str), "", (yyvsp[-3].str)); 
        }
    } else {
        printf("Erreur Semantique: ligne %d '%s' non declare\n", nb_lignes, (yyvsp[-3].str));
        nb_erreurs++;
    }
}
#line 1411 "syntaxique.tab.c"
    break;

  case 28: /* AFF: IDF AFFECT error PV  */
#line 177 "syntaxique.y"
                         {
        printf("Erreur Syntaxique: ligne %d , col %d expression invalide \n", nb_lignes, nb_col);
        nb_erreurs++;
        yyerrok;
     }
#line 1421 "syntaxique.tab.c"
    break;

  case 29: /* AFF: IDF CROCHG expression CROCHD AFFECT expression PV  */
#line 182 "syntaxique.y"
                                                       { 
    Symbole* s = rechercher((yyvsp[-6].str));
    if(s == NULL) {
        printf("Erreur Semantique: ligne %d: tableau '%s' non declare\n", nb_lignes, (yyvsp[-6].str));
        nb_erreurs++;
    } else if (strcmp((yyvsp[-4].str), "ID_ERR") == 0 || strcmp((yyvsp[-1].str), "ID_ERR") == 0) {}
    else {
        // Détection débordement tableau
        if (est_un_entier((yyvsp[-4].str))) {
            int idx = atoi((yyvsp[-4].str));
            if (idx >= s->taille || idx < 0) {
                printf("Erreur Semantique: ligne %d: index %d hors limites pour '%s' (taille %d)\n", nb_lignes, idx, (yyvsp[-6].str), s->taille);
                nb_erreurs++;
            }
        }
        
        if(!s->estTableau) {
            printf("Erreur Semantique: ligne %d: '%s' n'est pas un tableau\n", nb_lignes, (yyvsp[-6].str));
            nb_erreurs++;
        }
        if(s->estConstante) {
            printf("Erreur Semantique: ligne %d: '%s' est une constante\n", nb_lignes, (yyvsp[-6].str));
            nb_erreurs++;
        }
        if(s->estTableau && !s->estConstante) {
            Symbole* s_val = rechercher((yyvsp[-1].str));
            int est_float = (s_val != NULL) ? (strcmp(s_val->type, "FLOAT") == 0) : contient_point_decimal((yyvsp[-1].str));

            if(strcmp(s->type, "INTEGER") == 0 && est_float) {
                printf("Erreur Semantique: ligne %d: incompatibilite de type sur '%s'\n", nb_lignes, (yyvsp[-6].str));
                nb_erreurs++;
            } else {
                char res[30]; sprintf(res, "%s[%s]", (yyvsp[-6].str), (yyvsp[-4].str));
                quad("=", (yyvsp[-1].str), "", res); 
                if (est_un_entier((yyvsp[-1].str))) {
                    s->valeur = atof((yyvsp[-1].str));
                    s->a_une_valeur = 1;
                } else {
                    Symbole* rhs = rechercher((yyvsp[-1].str));
                    if (rhs != NULL && rhs->a_une_valeur) {
                        s->valeur = rhs->valeur;
                        s->a_une_valeur = 1;
                    } else {
                        s->a_une_valeur = 0;
                    }
                }
            }
        }
    }
}
#line 1476 "syntaxique.tab.c"
    break;

  case 30: /* AFF: IDF CROCHG error CROCHD AFFECT expression PV  */
#line 232 "syntaxique.y"
                                                  {
        printf("Erreur Syntaxique: ligne %d , col %d index invalide \n", nb_lignes, nb_col);
        nb_erreurs++;
        yyerrok;
     }
#line 1486 "syntaxique.tab.c"
    break;

  case 31: /* AFF: IDF CROCHG expression CROCHD AFFECT error PV  */
#line 237 "syntaxique.y"
                                                  {
        printf("Erreur Syntaxique: ligne %d , col %d expression invalide \n", nb_lignes, nb_col);
        nb_erreurs++;
        yyerrok;
     }
#line 1496 "syntaxique.tab.c"
    break;

  case 32: /* expression: expression PLUS terme  */
#line 243 "syntaxique.y"
                                  { 
            if(strcmp((yyvsp[-2].str), "ID_ERR") == 0 || strcmp((yyvsp[0].str), "ID_ERR") == 0) (yyval.str) = "ID_ERR";
            else { (yyval.str) = new_temp(); quad("+", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
          }
#line 1505 "syntaxique.tab.c"
    break;

  case 33: /* expression: expression MOINS terme  */
#line 247 "syntaxique.y"
                                   { 
            if(strcmp((yyvsp[-2].str), "ID_ERR") == 0 || strcmp((yyvsp[0].str), "ID_ERR") == 0) (yyval.str) = "ID_ERR";
            else { (yyval.str) = new_temp(); quad("-", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
          }
#line 1514 "syntaxique.tab.c"
    break;

  case 34: /* expression: terme  */
#line 251 "syntaxique.y"
                  { (yyval.str) = (yyvsp[0].str); }
#line 1520 "syntaxique.tab.c"
    break;

  case 35: /* terme: terme MULT facteur  */
#line 253 "syntaxique.y"
                          { 
            if(strcmp((yyvsp[-2].str), "ID_ERR") == 0 || strcmp((yyvsp[0].str), "ID_ERR") == 0) (yyval.str) = "ID_ERR";
            else { (yyval.str) = new_temp(); quad("*", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
          }
#line 1529 "syntaxique.tab.c"
    break;

  case 36: /* terme: terme DIV facteur  */
#line 257 "syntaxique.y"
                         { 
            int div_nulle = 0;
            if(strcmp((yyvsp[0].str), "0") == 0 || strcmp((yyvsp[0].str), "0.0") == 0) div_nulle = 1;
            else {
                Symbole* s_div = rechercher((yyvsp[0].str));
                if (s_div != NULL && s_div->a_une_valeur && s_div->valeur == 0) div_nulle = 1;
            }

            if(div_nulle) {
                printf("Erreur Semantique: ligne %d, Division par zero !\n", nb_lignes);
                nb_erreurs++; (yyval.str) = "ID_ERR"; 
            } else {
                (yyval.str) = new_temp(); quad("/", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); 
            }
       }
#line 1549 "syntaxique.tab.c"
    break;

  case 37: /* terme: facteur  */
#line 272 "syntaxique.y"
               { (yyval.str) = (yyvsp[0].str); }
#line 1555 "syntaxique.tab.c"
    break;

  case 38: /* facteur: IDF  */
#line 274 "syntaxique.y"
             { 
            Symbole* s = rechercher((yyvsp[0].str));
            if (s == NULL) {
                printf("Erreur Semantique: ligne %d: variable '%s' non declaree\n", nb_lignes, (yyvsp[0].str));
                nb_erreurs++; (yyval.str) = "ID_ERR"; 
            } else {
                if(s->estTableau) {
                    printf("Erreur Semantique: ligne %d: '%s' est un tableau, index requis\n", nb_lignes, (yyvsp[0].str));
                    nb_erreurs++;
                }
                (yyval.str) = (yyvsp[0].str); 
            }
         }
#line 1573 "syntaxique.tab.c"
    break;

  case 39: /* facteur: IDF CROCHG expression CROCHD  */
#line 287 "syntaxique.y"
                                      { 
            Symbole* s = rechercher((yyvsp[-3].str));
            if (s == NULL) {
                printf("Erreur Semantique: ligne %d: tableau '%s' non declare\n", nb_lignes, (yyvsp[-3].str));
                nb_erreurs++; (yyval.str) = "ID_ERR"; 
            } else {
                if(!s->estTableau) {
                    printf("Erreur Semantique: ligne %d: '%s' n'est pas un tableau\n", nb_lignes, (yyvsp[-3].str));
                    nb_erreurs++;
                }
                if (est_un_entier((yyvsp[-1].str))) {
                    int idx = atoi((yyvsp[-1].str));
                    if (idx >= s->taille || idx < 0) {
                        printf("Erreur Semantique: ligne %d: index %d hors limites pour '%s'\n", nb_lignes, idx, (yyvsp[-3].str));
                        nb_erreurs++;
                    }
                }
                char* t = malloc(30); sprintf(t, "%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str)); (yyval.str) = t; 
            }
         }
#line 1598 "syntaxique.tab.c"
    break;

  case 40: /* facteur: IDF CROCHG error CROCHD  */
#line 307 "syntaxique.y"
                                 {
            printf("Erreur Syntaxique: ligne %d , col %d index invalide \n", nb_lignes, nb_col);
            nb_erreurs++;
            yyerrok;
            (yyval.str) = "ID_ERR";
         }
#line 1609 "syntaxique.tab.c"
    break;

  case 41: /* facteur: INT_VAL  */
#line 313 "syntaxique.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1615 "syntaxique.tab.c"
    break;

  case 42: /* facteur: FLOAT_VAL  */
#line 314 "syntaxique.y"
                   { (yyval.str) = (yyvsp[0].str); }
#line 1621 "syntaxique.tab.c"
    break;

  case 43: /* facteur: PARG expression PARD  */
#line 315 "syntaxique.y"
                              { (yyval.str) = (yyvsp[-1].str); }
#line 1627 "syntaxique.tab.c"
    break;

  case 44: /* facteur: PARG error PARD  */
#line 316 "syntaxique.y"
                         {
            printf("Erreur Syntaxique: ligne %d , col %d expression invalide \n", nb_lignes, nb_col);
            nb_erreurs++;
            yyerrok;
            (yyval.str) = "ID_ERR";
         }
#line 1638 "syntaxique.tab.c"
    break;

  case 45: /* facteur: PARG MOINS INT_VAL PARD  */
#line 322 "syntaxique.y"
                                 { char* t=malloc(25); sprintf(t,"-%s",(yyvsp[-1].str)); (yyval.str)=t; }
#line 1644 "syntaxique.tab.c"
    break;

  case 46: /* facteur: PARG PLUS INT_VAL PARD  */
#line 323 "syntaxique.y"
                                { char* r=malloc(20); sprintf(r,"+%s",(yyvsp[-1].str)); (yyval.str)=r; }
#line 1650 "syntaxique.tab.c"
    break;

  case 47: /* facteur: PARG MOINS FLOAT_VAL PARD  */
#line 324 "syntaxique.y"
                                   { char* temp = malloc(30); sprintf(temp, "-%s", (yyvsp[-1].str)); (yyval.str)= temp; }
#line 1656 "syntaxique.tab.c"
    break;

  case 48: /* facteur: PARG PLUS FLOAT_VAL PARD  */
#line 325 "syntaxique.y"
                                  { char* temp = malloc(30); sprintf(temp, "+%s", (yyvsp[-1].str)); (yyval.str) = temp; }
#line 1662 "syntaxique.tab.c"
    break;

  case 49: /* $@1: %empty  */
#line 333 "syntaxique.y"
      { 
        fin_if = prochain_quad(); 
        quad("BZ", "", (yyvsp[-1].str), ""); 
      }
#line 1671 "syntaxique.tab.c"
    break;

  case 50: /* COND: IF PARG EXPR_LOG PARD $@1 ACCOLG INSTS ACCOLD ELSE_PART  */
#line 337 "syntaxique.y"
                                    {
          sprintf(tmp_addr, "%d", prochain_quad());
          modifier_quad(fin_if, 3, tmp_addr);
      }
#line 1680 "syntaxique.tab.c"
    break;

  case 51: /* $@2: %empty  */
#line 342 "syntaxique.y"
      {
        printf("Erreur Syntaxique: ligne %d , col %d condition invalide \n", nb_lignes, nb_col);
        nb_erreurs++;
        yyerrok;
      }
#line 1690 "syntaxique.tab.c"
    break;

  case 53: /* $@3: %empty  */
#line 350 "syntaxique.y"
           {
             deb_else = prochain_quad();
             quad("BR", "", "", "");
             sprintf(tmp_addr, "%d", prochain_quad());
             modifier_quad(fin_if, 3, tmp_addr);
             fin_if = deb_else;
           }
#line 1702 "syntaxique.tab.c"
    break;

  case 56: /* $@4: %empty  */
#line 361 "syntaxique.y"
              { push_loop_start(prochain_quad()); }
#line 1708 "syntaxique.tab.c"
    break;

  case 57: /* $@5: %empty  */
#line 363 "syntaxique.y"
        {
           set_loop_cond(prochain_quad());
           quad("BZ", "", (yyvsp[-1].str), "");
        }
#line 1717 "syntaxique.tab.c"
    break;

  case 58: /* BOUCLE: WHILE $@4 PARG EXPR_LOG PARD $@5 ACCOLG INSTS ACCOLD  */
#line 368 "syntaxique.y"
        {
           int cond = pop_loop_cond();
           int start = pop_loop_start();
           sprintf(tmp_addr, "%d", start);
           quad("BR", "", "", tmp_addr);
           sprintf(tmp_addr, "%d", prochain_quad());
           modifier_quad(cond, 3, tmp_addr);
        }
#line 1730 "syntaxique.tab.c"
    break;

  case 59: /* $@6: %empty  */
#line 377 "syntaxique.y"
        {
            quad("=", (yyvsp[-5].str), "", (yyvsp[-7].str));
            push_loop_start(prochain_quad()); 
            char* t = new_temp();
            quad("BG", (yyvsp[-7].str), (yyvsp[-3].str), t); 
            set_loop_cond(prochain_quad());
            quad("BZ", "", t, ""); 
        }
#line 1743 "syntaxique.tab.c"
    break;

  case 60: /* BOUCLE: FOR PARG IDF DEUXPTS INT_VAL DEUXPTS INT_VAL DEUXPTS INT_VAL PARD $@6 ACCOLG INSTS ACCOLD  */
#line 386 "syntaxique.y"
        {
            char* t2 = new_temp();
            quad("+", (yyvsp[-11].str), (yyvsp[-5].str), t2);
            quad("=", t2, "", (yyvsp[-11].str));
            int cond = pop_loop_cond();
            int start = pop_loop_start();
            sprintf(tmp_addr, "%d", start);
            quad("BR", "", "", tmp_addr);
            sprintf(tmp_addr, "%d", prochain_quad());
            modifier_quad(cond, 3, tmp_addr);
        }
#line 1759 "syntaxique.tab.c"
    break;

  case 61: /* EXPR_LOG: EXPR_LOG OR EXPR_LOG  */
#line 398 "syntaxique.y"
                               { (yyval.str) = new_temp(); quad("OR", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
#line 1765 "syntaxique.tab.c"
    break;

  case 62: /* EXPR_LOG: EXPR_LOG AND EXPR_LOG  */
#line 399 "syntaxique.y"
                                { (yyval.str) = new_temp(); quad("AND", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
#line 1771 "syntaxique.tab.c"
    break;

  case 63: /* EXPR_LOG: NOT EXPR_LOG  */
#line 400 "syntaxique.y"
                       { (yyval.str) = new_temp(); quad("NOT", (yyvsp[0].str), "", (yyval.str)); }
#line 1777 "syntaxique.tab.c"
    break;

  case 64: /* EXPR_LOG: expression SUP expression  */
#line 401 "syntaxique.y"
                                    { (yyval.str) = new_temp(); quad("SUP", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
#line 1783 "syntaxique.tab.c"
    break;

  case 65: /* EXPR_LOG: expression INF expression  */
#line 402 "syntaxique.y"
                                    { (yyval.str) = new_temp(); quad("INF", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
#line 1789 "syntaxique.tab.c"
    break;

  case 66: /* EXPR_LOG: expression EGAL expression  */
#line 403 "syntaxique.y"
                                     { (yyval.str) = new_temp(); quad("EGAL", (yyvsp[-2].str), (yyvsp[0].str), (yyval.str)); }
#line 1795 "syntaxique.tab.c"
    break;

  case 67: /* EXPR_LOG: PARG EXPR_LOG PARD  */
#line 404 "syntaxique.y"
                             { (yyval.str) = (yyvsp[-1].str); }
#line 1801 "syntaxique.tab.c"
    break;

  case 68: /* WRITE_I: WRITE PARG IDF PARD PV  */
#line 409 "syntaxique.y"
                                { 
    if(rechercher((yyvsp[-2].str)) == NULL) {printf("Erreur Semantique: ligne %d, variable '%s' non declaree\n",nb_lignes, (yyvsp[-2].str));nb_erreurs++;}
}
#line 1809 "syntaxique.tab.c"
    break;


#line 1813 "syntaxique.tab.c"

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

#line 416 "syntaxique.y"

void yyerror(const char* s) { 
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
