/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 3 "parse.y"

#include "intern.h"
#include "debug.h"
#include <stdio.h>

#ifdef YYTEXT_POINTER
  extern char *yytext;
#else
  extern char yytext[];
#endif

extern int yylineno;

int error_reported = 0;

void yyerror(const char *);

/* Line 371 of yacc.c  */
#line 86 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TIDENT = 258,
     TSTRING_CONST = 259,
     TINT_CONST = 260,
     TFLOAT_CONST = 261,
     TTRUE = 262,
     TFALSE = 263,
     TVAR = 264,
     TIMPORT = 265,
     TMODULE = 266,
     TAS = 267,
     TSELF = 268,
     TSTRING = 269,
     TINT = 270,
     TFLOAT = 271,
     TIF = 272,
     TELSE = 273,
     TELIF = 274,
     TBREAK = 275,
     TCONTINUE = 276,
     TFOR = 277,
     TWHILE = 278,
     TIN = 279,
     TNIL = 280,
     TBOOL = 281,
     TRET = 282,
     TFUNC = 283,
     TEND = 284,
     TNOT = 285,
     TASSIGN = 286,
     TAND = 287,
     TOR = 288,
     TINC = 289,
     TDEC = 290,
     TPOW = 291,
     TEQ = 292,
     TNE = 293,
     TLE = 294,
     TGE = 295,
     TNEWL = 296
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 205 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   123

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNRULES -- Number of states.  */
#define YYNSTATES  118

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      57,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,     2,     2,    48,    49,     2,
      50,    51,    46,    42,    56,    43,     2,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    58,
      53,    52,    54,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    44,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    16,    18,    20,
      22,    24,    26,    28,    30,    32,    35,    37,    40,    44,
      48,    50,    54,    58,    60,    63,    65,    69,    73,    77,
      81,    85,    89,    91,    95,    99,   103,   107,   109,   113,
     117,   121,   123,   126,   129,   131,   135,   137,   145,   147,
     149,   153,   156,   159,   161,   165,   167,   169,   171,   173,
     175,   178,   180,   184,   186,   188,   190,   194,   196,   198,
     200,   202,   204,   206,   209,   214,   216,   218
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      60,     0,    -1,    61,    -1,    90,    -1,    61,    62,    -1,
      89,    -1,    62,    63,    89,    -1,    88,    -1,    76,    -1,
      64,    -1,    82,    -1,    78,    -1,    68,    -1,    67,    -1,
      90,    -1,    65,    66,    -1,    89,    -1,    64,    89,    -1,
       3,    31,    68,    -1,     3,    52,    68,    -1,    69,    -1,
      69,    32,    70,    -1,    69,    33,    70,    -1,    70,    -1,
      30,    71,    -1,    71,    -1,    71,    37,    72,    -1,    71,
      38,    72,    -1,    71,    53,    72,    -1,    71,    54,    72,
      -1,    71,    39,    72,    -1,    71,    40,    72,    -1,    72,
      -1,    72,    42,    73,    -1,    72,    43,    73,    -1,    72,
      49,    73,    -1,    72,    44,    73,    -1,    73,    -1,    73,
      46,    74,    -1,    73,    47,    74,    -1,    73,    48,    74,
      -1,    74,    -1,    43,    74,    -1,    55,    74,    -1,    75,
      -1,    50,    68,    51,    -1,    87,    -1,    28,     3,    50,
      77,    51,    65,    29,    -1,    90,    -1,    79,    -1,    79,
      56,    79,    -1,     9,    79,    -1,    80,    81,    -1,     3,
      -1,    80,    56,     3,    -1,    15,    -1,    16,    -1,    14,
      -1,    26,    -1,    25,    -1,    83,    84,    -1,     3,    -1,
      50,    85,    51,    -1,    90,    -1,    86,    -1,    87,    -1,
      86,    56,    87,    -1,     3,    -1,     5,    -1,     6,    -1,
       4,    -1,     7,    -1,     8,    -1,    10,     4,    -1,    10,
       4,    12,     3,    -1,    57,    -1,    58,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    57,    57,    60,    61,    64,    65,    68,    69,    70,
      73,    74,    75,    76,    79,    80,    83,    84,    87,    88,
      91,    94,    95,    96,    99,   100,   103,   104,   105,   106,
     107,   108,   109,   112,   113,   114,   115,   116,   119,   120,
     121,   122,   125,   126,   127,   130,   131,   134,   141,   142,
     143,   146,   149,   152,   153,   156,   157,   158,   159,   160,
     163,   166,   169,   172,   173,   176,   177,   180,   181,   182,
     183,   184,   185,   188,   189,   192,   193,   195
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIDENT", "TSTRING_CONST", "TINT_CONST",
  "TFLOAT_CONST", "TTRUE", "TFALSE", "TVAR", "TIMPORT", "TMODULE", "TAS",
  "TSELF", "TSTRING", "TINT", "TFLOAT", "TIF", "TELSE", "TELIF", "TBREAK",
  "TCONTINUE", "TFOR", "TWHILE", "TIN", "TNIL", "TBOOL", "TRET", "TFUNC",
  "TEND", "TNOT", "TASSIGN", "TAND", "TOR", "TINC", "TDEC", "TPOW", "TEQ",
  "TNE", "TLE", "TGE", "TNEWL", "'+'", "'-'", "'|'", "'^'", "'*'", "'/'",
  "'%'", "'&'", "'('", "')'", "'='", "'<'", "'>'", "'!'", "','", "'\\n'",
  "';'", "$accept", "files", "program", "stmt_list", "top_stmt", "stmt",
  "bodystmt", "bodystmt_list", "assignment", "expressions", "condition",
  "logic", "comparison", "arithmetic", "term", "factor", "final",
  "function_definition", "opt_parameters", "declaration",
  "declaration_list", "declaration_specifier", "type_specifier",
  "method_call", "operation", "arguments", "opt_call_args", "call_args",
  "primary", "import", "newl", "none", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,    43,    45,   124,    94,    42,    47,    37,    38,
      40,    41,    61,    60,    62,    33,    44,    10,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    61,    61,    62,    62,    63,    63,    63,
      64,    64,    64,    64,    65,    65,    66,    66,    67,    67,
      68,    69,    69,    69,    70,    70,    71,    71,    71,    71,
      71,    71,    71,    72,    72,    72,    72,    72,    73,    73,
      73,    73,    74,    74,    74,    75,    75,    76,    77,    77,
      77,    78,    79,    80,    80,    81,    81,    81,    81,    81,
      82,    83,    84,    85,    85,    86,    86,    87,    87,    87,
      87,    87,    87,    88,    88,    89,    89,    90
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     3,     3,
       1,     3,     3,     1,     2,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       3,     1,     2,     2,     1,     3,     1,     7,     1,     1,
       3,     2,     2,     1,     3,     1,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     2,     4,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      77,     0,     2,     3,     1,    75,    76,     4,     5,    67,
      70,    68,    69,    71,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     9,    13,    12,    20,    23,    25,    32,
      37,    41,    44,     8,    11,    10,     0,    46,     7,     0,
       0,    53,    51,     0,    73,     0,    67,    24,    42,     0,
      43,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,    60,    18,
      19,    57,    55,    56,    59,    58,     0,    52,     0,    77,
      45,    21,    22,    26,    27,    30,    31,    28,    29,    33,
      34,    36,    35,    38,    39,    40,     0,    64,    65,    63,
      54,    74,     0,    49,    48,    62,     0,    77,     0,    66,
       0,    14,    50,    47,     0,    15,    16,    17
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     7,    22,    23,   110,   115,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,   102,    34,
      42,    43,    77,    35,    36,    68,    96,    97,    37,    38,
       8,     3
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -60
static const yytype_int8 yypact[] =
{
     -60,     9,   -14,   -60,   -60,   -60,   -60,     7,   -60,    11,
     -60,   -60,   -60,   -60,   -60,    23,    35,    46,    26,    26,
      15,    26,   -14,   -60,   -60,   -60,    27,   -60,    56,    31,
      71,   -60,   -60,   -60,   -60,   -60,    -4,   -60,   -60,    15,
      15,   -60,   -60,    52,    39,    29,   -60,    56,   -60,    38,
     -60,   -60,    15,    15,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    94,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,    79,   -60,    87,    23,
     -60,   -60,   -60,    31,    31,    31,    31,    31,    31,    71,
      71,    71,    71,   -60,   -60,   -60,    40,    51,   -60,   -60,
     -60,   -60,    69,    65,   -60,   -60,    94,   -60,    23,   -60,
      -2,   -60,   -60,   -60,   -14,   -60,   -60,   -60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -60,   -60,   -60,   -60,   -60,    12,   -60,   -60,   -60,    32,
     -60,    34,   105,    57,    43,    19,   -60,   -60,   -60,   -60,
     -54,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -59,   -60,
     -22,   -43
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -62
static const yytype_int8 yytable[] =
{
      51,     9,    10,    11,    12,    13,    14,    15,    98,     4,
       9,    10,    11,    12,    13,    14,    15,    16,    46,    10,
      11,    12,    13,    14,    99,   103,    41,   113,    18,    46,
      10,    11,    12,    13,    14,    17,   104,    18,    48,    44,
      50,    19,    39,     5,     6,    18,    67,   109,    20,    45,
      19,    78,    49,    21,   112,     5,     6,    20,    19,    52,
      53,   -61,    21,    40,   111,    20,    71,    72,    73,    19,
      21,    69,    70,    60,    61,    62,    20,    74,    75,    79,
      63,    21,   100,    93,    94,    95,    81,    82,   116,    80,
     101,   105,   117,    54,    55,    56,    57,    46,    10,    11,
      12,    13,    14,    89,    90,    91,    92,   106,    76,    58,
      59,    83,    84,    85,    86,    87,    88,    64,    65,    66,
     107,   108,   114,    47
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-60)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
      22,     3,     4,     5,     6,     7,     8,     9,    67,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     3,     4,
       5,     6,     7,     8,    67,    79,     3,    29,    30,     3,
       4,     5,     6,     7,     8,    28,    79,    30,    19,     4,
      21,    43,    31,    57,    58,    30,    50,   106,    50,     3,
      43,    12,    20,    55,   108,    57,    58,    50,    43,    32,
      33,    50,    55,    52,   107,    50,    14,    15,    16,    43,
      55,    39,    40,    42,    43,    44,    50,    25,    26,    50,
      49,    55,     3,    64,    65,    66,    52,    53,   110,    51,
       3,    51,   114,    37,    38,    39,    40,     3,     4,     5,
       6,     7,     8,    60,    61,    62,    63,    56,    56,    53,
      54,    54,    55,    56,    57,    58,    59,    46,    47,    48,
      51,    56,   110,    18
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    60,    61,    90,     0,    57,    58,    62,    89,     3,
       4,     5,     6,     7,     8,     9,    10,    28,    30,    43,
      50,    55,    63,    64,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    78,    82,    83,    87,    88,    31,
      52,     3,    79,    80,     4,     3,     3,    71,    74,    68,
      74,    89,    32,    33,    37,    38,    39,    40,    53,    54,
      42,    43,    44,    49,    46,    47,    48,    50,    84,    68,
      68,    14,    15,    16,    25,    26,    56,    81,    12,    50,
      51,    70,    70,    72,    72,    72,    72,    72,    72,    73,
      73,    73,    73,    74,    74,    74,    85,    86,    87,    90,
       3,     3,    77,    79,    90,    51,    56,    51,    56,    87,
      65,    90,    79,    29,    64,    66,    89,    89
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 57 "parse.y"
    { xtop = make_node(NT_PROGRAM, (yyvsp[(1) - (1)].node), NULL, null_value()); }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 60 "parse.y"
    { (yyval.node) = nil; }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 61 "parse.y"
    { (yyval.node) = list2((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 64 "parse.y"
    { (yyval.node) = nil; }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 65 "parse.y"
    { (yyval.node) = list2((yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node)); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 68 "parse.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 69 "parse.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 70 "parse.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 73 "parse.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 74 "parse.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 75 "parse.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 76 "parse.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 79 "parse.y"
    { (yyval.node) = nil; }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 80 "parse.y"
    { (yyval.node) = list2((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 83 "parse.y"
    { (yyval.node) = nil; }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 84 "parse.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 87 "parse.y"
    { (yyval.node) = make_node(NT_VASSIGN, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), null_value()); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 88 "parse.y"
    { (yyval.node) = make_node(NT_ASSIGN, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), null_value()); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 91 "parse.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 94 "parse.y"
    { (yyval.node) = make_node(NT_AND, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), null_value()); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 95 "parse.y"
    { (yyval.node) = make_node(NT_OR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), null_value()); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 96 "parse.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 99 "parse.y"
    { (yyval.node) = make_node(NT_NOT, (yyvsp[(2) - (2)].node), NULL, null_value()); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 100 "parse.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 103 "parse.y"
    { (yyval.node) = make_node(NT_EQ, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), null_value()); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 104 "parse.y"
    { (yyval.node) = make_node(NT_NE, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), null_value()); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 105 "parse.y"
    { (yyval.node) = make_node(NT_LT, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), null_value()); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 106 "parse.y"
    { (yyval.node) = make_node(NT_GT, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), null_value()); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 107 "parse.y"
    { (yyval.node) = make_node(NT_LE, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), null_value()); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 108 "parse.y"
    { (yyval.node) = make_node(NT_GE, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), null_value()); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 109 "parse.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 112 "parse.y"
    { (yyval.node) = make_node(NT_ADD, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), null_value()); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 113 "parse.y"
    { (yyval.node) = make_node(NT_SUB, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), null_value()); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 114 "parse.y"
    { (yyval.node) = make_node(NT_SHAND, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), null_value()); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 115 "parse.y"
    { (yyval.node) = make_node(NT_SHOR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), null_value()); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 116 "parse.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 119 "parse.y"
    { (yyval.node) = make_node(NT_MUL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), null_value()); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 120 "parse.y"
    { (yyval.node) = make_node(NT_DIV, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), null_value()); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 121 "parse.y"
    { (yyval.node) = make_node(NT_MOD, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), null_value()); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 122 "parse.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 125 "parse.y"
    { (yyval.node) = make_node(NT_UNEG, (yyvsp[(2) - (2)].node), NULL, null_value()); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 126 "parse.y"
    { (yyval.node) = make_node(NT_UNOT, (yyvsp[(2) - (2)].node), NULL, null_value()); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 127 "parse.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 130 "parse.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 131 "parse.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 135 "parse.y"
    {
     (yyval.node) = list2((yyvsp[(4) - (7)].node), (yyvsp[(6) - (7)].node));
     (yyval.node) = make_node(NT_FUNC, (yyvsp[(2) - (7)].node), (yyval.node), null_value());
  }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 141 "parse.y"
    { (yyval.node) = nil; }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 142 "parse.y"
    { (yyval.node) = make_node(NT_PARAM, (yyvsp[(1) - (1)].node), NULL, null_value()); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 143 "parse.y"
    { (yyval.node) = make_node(NT_PARAM, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), null_value()); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 146 "parse.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 149 "parse.y"
    { (yyval.node) = make_node(NT_DECL, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), null_value()); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 152 "parse.y"
    { (yyval.node) = make_node(NT_VAR, (yyvsp[(1) - (1)].node), NULL, null_value()); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 153 "parse.y"
    { (yyval.node) = list2((yyvsp[(1) - (3)].node), make_node(NT_VAR, (yyvsp[(1) - (3)].node), NULL, null_value())); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 156 "parse.y"
    { (yyval.node) = make_node(NT_TYPE, NULL, NULL, int_value(0)); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 157 "parse.y"
    { (yyval.node) = make_node(NT_TYPE, NULL, NULL, float_value(0)); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 158 "parse.y"
    { (yyval.node) = make_node(NT_TYPE, NULL, NULL, string_value(NULL)); }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 159 "parse.y"
    { (yyval.node) = make_node(NT_TYPE, NULL, NULL, bool_value(0)); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 160 "parse.y"
    { (yyval.node) = make_node(NT_TYPE, NULL, NULL, null_value()); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 163 "parse.y"
    { (yyval.node) = make_node(NT_CALL, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), null_value()); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 166 "parse.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 169 "parse.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 172 "parse.y"
    { (yyval.node) = make_node(NT_ARGS, NULL, NULL, null_value()); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 173 "parse.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 176 "parse.y"
    { (yyval.node) = make_node(NT_ARGS, (yyvsp[(1) - (1)].node), NULL, null_value()); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 177 "parse.y"
    { (yyval.node) = list2((yyvsp[(1) - (3)].node), make_node(NT_ARGS, (yyvsp[(3) - (3)].node), NULL, null_value())); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 180 "parse.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 181 "parse.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 182 "parse.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 183 "parse.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 184 "parse.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 185 "parse.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 188 "parse.y"
    { (yyval.node) = make_node(NT_IMPORT, (yyvsp[(2) - (2)].node), NULL, null_value()); }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 189 "parse.y"
    { (yyval.node) = make_node(NT_IMPORT, (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node), null_value()); }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 193 "parse.y"
    { yyerrok; }
    break;


/* Line 1792 of yacc.c  */
#line 2077 "y.tab.c"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 198 "parse.y"


void
yyerror(const char *msg) {
  fprintf(stderr, "%ld: %s\n", yylineno, msg);
}
