
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "../src/TP4.y"
 
//Definiciones y declaraciones de C
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

#define YYDEBUG 1

extern FILE* yyin;
extern int yylineno;
int tipo_sentencia=0;
int tipo_declaracion=0;
char* tipo;
char* identificador;

int yylex(void);
int yywrap(){
    return(1);
}

void yyerror (char const *s) {

}



/* Line 189 of yacc.c  */
#line 101 "TP4.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFICADOR = 258,
     LITERAL_CADENA = 259,
     CONTINUE_O_BREAK = 260,
     CONSTANTE_ENTERA = 261,
     CONSTANTE_REAL = 262,
     CONSTANTE_CARACTER = 263,
     ESPECIFICADOR_DE_TIPOS = 264,
     CALIFICADOR_DE_TIPOS = 265,
     ESPECIFICADOR_CLASE_DE_ALMACENAMIENTO = 266,
     ESPECIFICADOR_STRUCT_UNION = 267,
     OPERADOR_ASIGNACION = 268,
     IGUAL_O_DISTINTO = 269,
     SIMBOLO_RELACIONAL = 270,
     SIMBOLO_CORRIMIENTO = 271,
     MAS_MAS_O_MENOS_MENOS = 272,
     TRES_PUNTOS = 273,
     AND = 274,
     OR = 275,
     FLECHA = 276,
     ENUM = 277,
     WHILE = 278,
     DO = 279,
     FOR = 280,
     SWITCH = 281,
     CASE = 282,
     DEFAULT = 283,
     RETURN = 284,
     IF = 285,
     ELSE = 286,
     GOTO = 287,
     SIZEOF = 288,
     TYPEDEF = 289,
     ERROR_LEXICO = 290
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 28 "../src/TP4.y"

    char* cadena;
    int entero;
    float real;
    char caracter;



/* Line 214 of yacc.c  */
#line 181 "TP4.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 193 "TP4.tab.c"

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
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   817

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  94
/* YYNRULES -- Number of rules.  */
#define YYNRULES  213
/* YYNRULES -- Number of states.  */
#define YYNSTATES  354

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,     2,     2,    54,    50,     2,
      42,    43,    46,    51,    39,    52,    57,    53,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,    36,
       2,    40,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,    49,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,    48,    38,    55,     2,     2,     2,
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
      35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,     9,    11,    13,    15,    16,
      20,    22,    24,    25,    31,    32,    37,    38,    43,    44,
      48,    52,    55,    57,    60,    63,    66,    69,    71,    72,
      74,    76,    78,    80,    81,    87,    89,    92,    94,    96,
      99,   101,   105,   107,   111,   115,   118,   120,   123,   125,
     127,   131,   133,   137,   140,   146,   151,   154,   156,   160,
     162,   163,   168,   171,   173,   174,   178,   183,   188,   192,
     193,   199,   200,   206,   207,   212,   213,   216,   219,   221,
     223,   224,   226,   229,   231,   235,   237,   241,   244,   247,
     249,   251,   255,   257,   261,   266,   268,   272,   275,   277,
     279,   282,   284,   288,   293,   297,   301,   304,   309,   313,
     317,   320,   322,   324,   326,   328,   330,   332,   333,   338,
     339,   345,   346,   351,   354,   356,   360,   364,   367,   368,
     371,   372,   375,   377,   380,   381,   389,   390,   397,   398,
     402,   403,   404,   411,   412,   421,   422,   433,   435,   436,
     440,   443,   444,   449,   452,   454,   458,   460,   464,   466,
     468,   470,   476,   478,   482,   484,   488,   490,   494,   496,
     500,   502,   506,   508,   512,   514,   518,   520,   524,   526,
     530,   534,   536,   540,   544,   548,   550,   555,   557,   560,
     563,   566,   571,   573,   575,   577,   579,   581,   583,   585,
     590,   595,   599,   603,   607,   610,   612,   614,   616,   620,
     622,   626,   628,   630
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      59,     0,    -1,    -1,    -1,    59,    60,    61,    -1,    63,
      -1,   108,    -1,    35,    -1,    -1,     1,    62,    61,    -1,
      64,    -1,    69,    -1,    -1,    71,    88,    70,    65,   114,
      -1,    -1,    88,    70,    66,   114,    -1,    -1,    71,    88,
      67,   114,    -1,    -1,    88,    68,   114,    -1,    71,    78,
      36,    -1,    71,    36,    -1,    69,    -1,    70,    69,    -1,
      11,    72,    -1,    73,    72,    -1,    10,    72,    -1,    71,
      -1,    -1,     9,    -1,    74,    -1,    84,    -1,    34,    -1,
      -1,    76,    37,    75,    77,    38,    -1,    76,    -1,    12,
       3,    -1,    12,    -1,    80,    -1,    77,    80,    -1,    79,
      -1,    78,    39,    79,    -1,    88,    -1,    88,    40,   103,
      -1,    81,    82,    36,    -1,    73,    81,    -1,    73,    -1,
      10,    81,    -1,    10,    -1,    83,    -1,    82,    39,    83,
      -1,    88,    -1,    88,    41,   134,    -1,    41,   134,    -1,
      22,     3,    37,    85,    38,    -1,    22,    37,    85,    38,
      -1,    22,     3,    -1,    86,    -1,    85,    39,    86,    -1,
       3,    -1,    -1,     3,    87,    40,   134,    -1,    95,    89,
      -1,    89,    -1,    -1,     3,    90,    91,    -1,    42,    88,
      43,    91,    -1,    44,   134,    45,    91,    -1,    44,    45,
      91,    -1,    -1,    42,    92,    99,    43,    91,    -1,    -1,
      42,    93,   102,    43,    91,    -1,    -1,    42,    94,    43,
      91,    -1,    -1,    46,    96,    -1,    95,    97,    -1,    97,
      -1,    98,    -1,    -1,    10,    -1,    98,    10,    -1,   100,
      -1,   100,    39,    18,    -1,   101,    -1,   100,    39,   101,
      -1,    71,    88,    -1,    71,   106,    -1,    71,    -1,     3,
      -1,   102,    39,     3,    -1,   132,    -1,    37,   104,    38,
      -1,    37,   104,    39,    38,    -1,   103,    -1,   104,    39,
     103,    -1,    81,   106,    -1,    81,    -1,    95,    -1,    95,
     107,    -1,   107,    -1,    42,   106,    43,    -1,   107,    44,
     134,    45,    -1,    44,   134,    45,    -1,   107,    44,    45,
      -1,    44,    45,    -1,   107,    42,    99,    43,    -1,    42,
      99,    43,    -1,   107,    42,    43,    -1,    42,    43,    -1,
     109,    -1,   113,    -1,   114,    -1,   119,    -1,   124,    -1,
     129,    -1,    -1,     3,   110,    41,   108,    -1,    -1,    27,
     111,   134,    41,   108,    -1,    -1,    28,   112,    41,   108,
      -1,   131,    36,    -1,    36,    -1,    37,   115,    38,    -1,
      37,   117,    38,    -1,    70,   116,    -1,    -1,   118,   115,
      -1,    -1,   118,   115,    -1,   108,    -1,   118,   108,    -1,
      -1,    30,   120,    42,   131,    43,   108,   122,    -1,    -1,
      26,   121,    42,   131,    43,   108,    -1,    -1,    31,   123,
     108,    -1,    -1,    -1,    23,   125,    42,   131,    43,   108,
      -1,    -1,    24,   126,   108,    23,    42,   131,    43,    36,
      -1,    -1,    25,   127,    42,   128,    36,   128,    36,   128,
      43,   108,    -1,   131,    -1,    -1,    32,     3,    36,    -1,
       5,    36,    -1,    -1,    29,   130,   131,    36,    -1,    29,
      36,    -1,   132,    -1,   131,    39,   132,    -1,   134,    -1,
     146,   133,   132,    -1,    13,    -1,    40,    -1,   135,    -1,
     135,    47,   131,    41,   134,    -1,   136,    -1,   135,    20,
     136,    -1,   137,    -1,   136,    19,   137,    -1,   138,    -1,
     137,    48,   138,    -1,   139,    -1,   138,    49,   139,    -1,
     140,    -1,   139,    50,   140,    -1,   141,    -1,   140,    14,
     141,    -1,   142,    -1,   141,    15,   142,    -1,   143,    -1,
     142,    16,   143,    -1,   144,    -1,   143,    51,   144,    -1,
     143,    52,   144,    -1,   145,    -1,   144,    46,   145,    -1,
     144,    53,   145,    -1,   144,    54,   145,    -1,   146,    -1,
      42,   105,    43,   145,    -1,   148,    -1,    17,   146,    -1,
     147,   145,    -1,    33,   146,    -1,    33,    42,   105,    43,
      -1,    50,    -1,    46,    -1,    51,    -1,    52,    -1,    55,
      -1,    56,    -1,   149,    -1,   148,    44,   131,    45,    -1,
     148,    42,   150,    43,    -1,   148,    42,    43,    -1,   148,
      57,     3,    -1,   148,    21,     3,    -1,   148,    17,    -1,
       3,    -1,   151,    -1,     4,    -1,    42,   131,    43,    -1,
     132,    -1,   150,    39,   132,    -1,     6,    -1,     8,    -1,
       7,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    62,    62,    65,    65,    67,    68,    69,    70,    70,
      72,    73,    75,    75,    76,    76,    77,    77,    78,    78,
      80,    81,    83,    84,    86,    87,    88,    90,    91,    93,
      94,    95,    96,    98,    98,    99,   106,   107,   109,   110,
     112,   113,   115,   116,   118,   120,   121,   122,   123,   125,
     126,   128,   129,   130,   132,   133,   134,   136,   137,   139,
     140,   140,   142,   143,   145,   145,   146,   148,   149,   150,
     150,   151,   151,   152,   152,   153,   155,   157,   158,   160,
     161,   163,   164,   166,   167,   169,   170,   172,   173,   174,
     176,   177,   179,   180,   181,   183,   184,   186,   187,   189,
     190,   191,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   203,   204,   205,   206,   207,   208,   210,   210,   211,
     211,   212,   212,   214,   215,   217,   218,   221,   222,   224,
     225,   227,   229,   230,   232,   232,   233,   233,   235,   235,
     236,   238,   238,   239,   239,   240,   240,   242,   243,   245,
     246,   247,   247,   248,   250,   251,   253,   254,   256,   257,
     259,   260,   262,   263,   265,   266,   268,   269,   271,   272,
     274,   275,   277,   278,   280,   281,   283,   284,   286,   287,
     288,   290,   291,   292,   293,   295,   296,   298,   299,   300,
     301,   302,   304,   305,   306,   307,   308,   309,   311,   312,
     313,   314,   315,   316,   317,   319,   320,   321,   322,   324,
     325,   327,   328,   329
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFICADOR", "LITERAL_CADENA",
  "CONTINUE_O_BREAK", "CONSTANTE_ENTERA", "CONSTANTE_REAL",
  "CONSTANTE_CARACTER", "ESPECIFICADOR_DE_TIPOS", "CALIFICADOR_DE_TIPOS",
  "ESPECIFICADOR_CLASE_DE_ALMACENAMIENTO", "ESPECIFICADOR_STRUCT_UNION",
  "OPERADOR_ASIGNACION", "IGUAL_O_DISTINTO", "SIMBOLO_RELACIONAL",
  "SIMBOLO_CORRIMIENTO", "MAS_MAS_O_MENOS_MENOS", "TRES_PUNTOS", "AND",
  "OR", "FLECHA", "ENUM", "WHILE", "DO", "FOR", "SWITCH", "CASE",
  "DEFAULT", "RETURN", "IF", "ELSE", "GOTO", "SIZEOF", "TYPEDEF",
  "ERROR_LEXICO", "';'", "'{'", "'}'", "','", "'='", "':'", "'('", "')'",
  "'['", "']'", "'*'", "'?'", "'|'", "'^'", "'&'", "'+'", "'-'", "'/'",
  "'%'", "'~'", "'!'", "'.'", "$accept", "unidad_de_programa", "$@1",
  "unidad_de_traduccion", "$@2", "declaracion_externa",
  "definicion_de_funcion", "$@3", "$@4", "$@5", "$@6", "declaracion",
  "lista_de_declaracion", "especificadores_de_declaracion",
  "especificadores_de_declaracion_o_vacio", "especificador_de_tipo",
  "especificador_estructura_o_union", "$@7", "a",
  "lista_declaraciones_struct", "lista_declaradores_init",
  "declarador_init", "declaracion_struct",
  "lista_calificador_especificador", "lista_declaradores_struct",
  "declarador_struct", "especificador_enum", "lista_de_enumerador",
  "enumerador", "$@8", "declarador", "declarador_directo", "$@9",
  "R_declarador_directo", "$@10", "$@11", "$@12", "apuntador",
  "apuntador_aux", "apuntador_aux2", "lista_calificadores_de_tipo",
  "lista_tipos_de_parametro", "lista_de_parametros",
  "declaracion_de_parametro", "lista_de_identificadores", "inicializador",
  "lista_de_inicializadores", "nombre_de_tipo", "declarador_abstracto",
  "declarador_abstracto_directo", "sentencia", "sentencia_etiquetada",
  "$@13", "$@14", "$@15", "sentencia_expresion", "sentencia_compuesta",
  "X", "Y", "Z", "lista_de_sentencias", "sentencia_de_seleccion", "$@16",
  "$@17", "sentencia_de_seleccion_aux", "$@18", "sentencia_de_iteracion",
  "$@19", "$@20", "$@21", "expresion_o_vacio", "sentencia_de_salto",
  "$@22", "expresion", "expresion_de_asignacion", "operador_de_asignacion",
  "expresion_condicional", "expresion_logica_or", "expresion_logica_and",
  "expresion_or_inclusivo", "expresion_or_exclusivo", "expresion_and",
  "expresion_de_igualdad", "expresion_relacional",
  "expresion_de_corrimiento", "expresion_aditiva",
  "expresion_multiplicativa", "expresion_cast", "expresion_unaria",
  "operador_unario", "expresion_posfija", "expresion_primaria",
  "lista_expresiones_argumento", "constante", 0
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
     285,   286,   287,   288,   289,   290,    59,   123,   125,    44,
      61,    58,    40,    41,    91,    93,    42,    63,   124,    94,
      38,    43,    45,    47,    37,   126,    33,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    59,    61,    61,    61,    62,    61,
      63,    63,    65,    64,    66,    64,    67,    64,    68,    64,
      69,    69,    70,    70,    71,    71,    71,    72,    72,    73,
      73,    73,    73,    75,    74,    74,    76,    76,    77,    77,
      78,    78,    79,    79,    80,    81,    81,    81,    81,    82,
      82,    83,    83,    83,    84,    84,    84,    85,    85,    86,
      87,    86,    88,    88,    90,    89,    89,    91,    91,    92,
      91,    93,    91,    94,    91,    91,    95,    96,    96,    97,
      97,    98,    98,    99,    99,   100,   100,   101,   101,   101,
     102,   102,   103,   103,   103,   104,   104,   105,   105,   106,
     106,   106,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   108,   108,   108,   108,   108,   108,   110,   109,   111,
     109,   112,   109,   113,   113,   114,   114,   115,   115,   116,
     116,   117,   118,   118,   120,   119,   121,   119,   123,   122,
     122,   125,   124,   126,   124,   127,   124,   128,   128,   129,
     129,   130,   129,   129,   131,   131,   132,   132,   133,   133,
     134,   134,   135,   135,   136,   136,   137,   137,   138,   138,
     139,   139,   140,   140,   141,   141,   142,   142,   143,   143,
     143,   144,   144,   144,   144,   145,   145,   146,   146,   146,
     146,   146,   147,   147,   147,   147,   147,   147,   148,   148,
     148,   148,   148,   148,   148,   149,   149,   149,   149,   150,
     150,   151,   151,   151
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     3,     1,     1,     1,     0,     3,
       1,     1,     0,     5,     0,     4,     0,     4,     0,     3,
       3,     2,     1,     2,     2,     2,     2,     1,     0,     1,
       1,     1,     1,     0,     5,     1,     2,     1,     1,     2,
       1,     3,     1,     3,     3,     2,     1,     2,     1,     1,
       3,     1,     3,     2,     5,     4,     2,     1,     3,     1,
       0,     4,     2,     1,     0,     3,     4,     4,     3,     0,
       5,     0,     5,     0,     4,     0,     2,     2,     1,     1,
       0,     1,     2,     1,     3,     1,     3,     2,     2,     1,
       1,     3,     1,     3,     4,     1,     3,     2,     1,     1,
       2,     1,     3,     4,     3,     3,     2,     4,     3,     3,
       2,     1,     1,     1,     1,     1,     1,     0,     4,     0,
       5,     0,     4,     2,     1,     3,     3,     2,     0,     2,
       0,     2,     1,     2,     0,     7,     0,     6,     0,     3,
       0,     0,     6,     0,     8,     0,    10,     1,     0,     3,
       2,     0,     4,     2,     1,     3,     1,     3,     1,     1,
       1,     5,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     4,     1,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     3,     3,     3,     2,     1,     1,     1,     3,     1,
       3,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     3,     1,     0,     8,   205,   207,     0,   211,   213,
     212,    29,    28,    28,    37,     0,     0,   141,   143,   145,
     136,   119,   121,   151,   134,     0,     0,    32,     7,   124,
     128,     0,   193,   192,   194,   195,   196,   197,     4,     5,
      10,    11,     0,    28,    30,    35,    31,    18,    63,     0,
       6,   111,   112,   113,   114,   115,   116,     0,   154,   156,
     160,   162,   164,   166,   168,   170,   172,   174,   176,   178,
     181,   185,     0,   187,   198,   206,     0,    75,     0,   150,
      27,    26,    24,    36,   205,     0,   193,   188,    56,     0,
       0,     0,     0,     0,     0,     0,   153,     0,     0,     0,
       0,   190,   205,     0,    22,   130,     0,   132,     0,     0,
     128,   205,    48,    46,    98,     0,     0,     0,    81,    80,
      80,    76,    78,    79,    64,    21,     0,     0,    40,    42,
      25,    33,     0,    14,    62,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   158,   159,     0,   189,   185,   204,     0,     0,     0,
       0,     9,    69,     0,    65,     0,     0,    59,     0,    57,
       0,     0,   148,     0,     0,     0,     0,     0,   149,     0,
      23,   127,   128,    42,   125,   126,   133,   131,    47,    45,
       0,     0,    99,    97,   101,    75,     0,   208,    77,    82,
      20,     0,     0,     0,    12,     0,    19,     0,   155,   163,
       0,   165,   167,   169,   171,   173,   175,   177,   179,   180,
     182,   183,   184,   157,   203,   201,   209,     0,     0,   202,
       0,     0,     0,    75,     0,   118,     0,     0,    55,     0,
       0,     0,     0,   147,     0,     0,   122,   152,     0,   191,
     129,   110,    89,     0,    83,    85,     0,   106,     0,   100,
       0,     0,    66,   186,    41,     0,    43,    92,    17,     0,
       0,    38,     0,    15,     0,     0,   200,   199,     0,    90,
       0,    75,    68,    75,    54,     0,    58,     0,     0,   148,
       0,   120,     0,     0,    87,    99,    88,   108,     0,   102,
     104,   109,     0,   105,     0,    95,     0,    13,    34,    39,
       0,     0,    49,    51,   161,   210,    75,     0,    75,    74,
      67,    61,   142,     0,     0,   137,   140,    84,    86,   107,
     103,    93,     0,    53,    44,     0,     0,    70,    91,    72,
       0,   148,   138,   135,    94,    96,    50,    52,   144,     0,
       0,     0,   139,   146
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     3,    38,    76,    39,    40,   269,   207,   203,
     132,   104,   105,   106,    81,    43,    44,   205,    45,   270,
     127,   128,   271,   114,   311,   312,    46,   168,   169,   237,
     115,    48,    77,   164,   230,   231,   232,    49,   121,   122,
     123,   253,   254,   255,   280,   266,   306,   116,   256,   194,
      50,    51,    78,    94,    95,    52,    53,   108,   181,   109,
     110,    54,    98,    93,   343,   350,    55,    90,    91,    92,
     242,    56,    97,    57,    58,   153,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,   227,    75
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -280
static const yytype_int16 yypact[] =
{
    -280,    29,  -280,   330,  -280,   773,  -280,    13,  -280,  -280,
    -280,  -280,   230,   230,    34,   694,    20,  -280,  -280,  -280,
    -280,  -280,  -280,    30,  -280,    80,   718,  -280,  -280,  -280,
     384,   492,    22,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,    17,   230,  -280,    52,  -280,   230,  -280,    42,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,    11,  -280,  -280,
       4,    82,    47,    72,   113,   131,   138,   155,     9,   -12,
    -280,    15,   725,    95,  -280,  -280,   330,    -4,   139,  -280,
    -280,  -280,  -280,  -280,  -280,   725,  -280,  -280,   178,   205,
     183,   438,   193,   196,   725,   209,  -280,   725,   201,   218,
     546,  -280,   221,   546,  -280,   384,    17,  -280,   227,   229,
     384,   214,   275,   275,   120,   216,   231,   103,  -280,    25,
     268,  -280,  -280,   273,  -280,  -280,   114,   142,  -280,   496,
    -280,  -280,   256,   230,  -280,  -280,   725,   725,   725,   725,
     725,   725,   725,   725,   725,   725,   725,   725,   725,   725,
     725,  -280,  -280,   725,  -280,  -280,  -280,   292,   566,   725,
     295,  -280,    33,   578,  -280,   438,   205,   263,    71,  -280,
     725,   282,   725,   725,   267,   438,   150,   725,  -280,   274,
    -280,  -280,   384,   278,  -280,  -280,  -280,  -280,  -280,  -280,
     270,   632,   115,  -280,   202,    -4,   725,  -280,  -280,  -280,
    -280,   114,   639,   256,   230,   275,  -280,   256,  -280,    82,
     212,    47,    72,   113,   131,   138,   155,     9,   -12,   -12,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,   130,     7,  -280,
     230,   307,   280,    -4,   283,  -280,   157,   289,  -280,   205,
     149,   288,   308,   306,   168,   438,  -280,  -280,   171,  -280,
    -280,  -280,    76,   303,   309,  -280,   318,  -280,   304,   202,
     194,   663,  -280,  -280,  -280,   639,  -280,  -280,  -280,   256,
     175,  -280,    28,  -280,   725,   725,  -280,  -280,   325,  -280,
     184,    -4,  -280,    -4,  -280,   725,  -280,   438,   725,   725,
     438,  -280,   438,   190,  -280,    12,  -280,  -280,   501,  -280,
    -280,  -280,   326,  -280,   305,  -280,   250,  -280,  -280,  -280,
     725,   181,  -280,   310,  -280,  -280,    -4,   367,    -4,  -280,
    -280,  -280,  -280,   187,   335,  -280,   342,  -280,  -280,  -280,
    -280,  -280,   269,  -280,  -280,    28,   725,  -280,  -280,  -280,
     338,   725,  -280,  -280,  -280,  -280,  -280,  -280,  -280,   332,
     438,   438,  -280,  -280
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -280,  -280,  -280,   301,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,    14,   -25,     1,    81,   -15,  -280,  -280,  -280,  -280,
    -280,   177,   109,   -94,  -280,    48,  -280,   232,   145,  -280,
      -3,   -47,  -280,  -168,  -280,  -280,  -280,   -23,  -280,   277,
    -280,   -92,  -280,   101,  -280,  -257,  -280,   300,  -109,  -181,
     -24,  -280,  -280,  -280,  -280,  -280,  -125,   -89,  -280,  -280,
     297,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
    -279,  -280,  -280,     2,  -110,  -280,   -91,  -280,   266,   265,
     279,   264,   281,   272,   284,   286,   154,   -42,   -14,  -280,
    -280,  -280,  -280,  -280
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -118
static const yytype_int16 yytable[] =
{
      47,    87,   134,   174,    42,   193,   107,   206,   305,   120,
     324,   259,   101,    80,    80,   124,   113,    41,   188,   189,
     124,   187,   133,    88,   137,   -80,   208,   262,   151,     2,
     154,   124,   118,   117,   148,   118,   -71,    83,   162,   129,
     163,   149,   150,   223,    80,   124,   136,   135,   226,    79,
     136,   138,   277,   125,   293,   152,   191,    89,   155,   126,
     146,   147,   349,   119,   -80,   282,    96,   171,   119,   310,
     126,   119,   234,    47,   119,   345,   -73,    42,   268,   124,
     155,   107,   273,    99,   126,   113,   186,   117,   113,   131,
      41,   192,   267,   250,    82,   140,   120,   113,   113,   176,
     258,   139,   117,   183,   204,   117,   220,   221,   222,   238,
     239,   272,   156,   319,   259,   320,   157,   124,   293,   180,
     191,   141,   119,   155,   130,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   158,   278,   159,
     210,   235,   136,   296,   307,   143,   197,   180,   337,   155,
     339,   246,   160,   144,   263,   267,   126,   190,   186,   191,
     119,   228,   190,   142,   191,   315,   119,   192,   302,   275,
     304,   145,   240,   276,   243,   244,   272,   155,   200,   248,
     165,   201,   155,   314,    11,   112,   247,    14,   136,   136,
     113,   252,   287,   124,   321,   284,   239,    16,   183,    11,
      12,    13,    14,    11,    12,    13,    14,   136,   167,    27,
     136,   290,    16,   308,   292,   166,    16,   334,   180,   333,
     335,   291,   267,   317,    27,   170,   136,   318,    27,   295,
     340,   252,   293,   251,   191,   172,   119,   301,   173,    11,
      12,    13,    14,   177,   260,   347,   261,   155,   134,   294,
     175,   136,    16,   274,   178,   113,   -64,   -64,   -64,   195,
     155,   252,  -117,   322,    27,   184,   325,   185,   326,   313,
     295,   155,    84,     6,   196,     8,     9,    10,   118,    11,
      12,    13,    14,   199,    11,   112,    15,    14,   331,   332,
     323,   243,    16,    30,   252,   224,   155,    16,   229,   252,
     218,   219,    26,   -60,    27,   241,   265,   344,   245,    27,
     279,   103,   190,   251,   191,    86,   119,   249,   202,    33,
      34,    35,   155,   281,    36,    37,   352,   353,   283,   285,
     288,     4,   313,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,   243,   289,   136,   297,    15,   298,   300,
     330,   336,    16,    17,    18,    19,    20,    21,    22,    23,
      24,   299,    25,    26,    27,    28,    29,    30,   316,   329,
     338,   341,    31,   342,   348,   351,    32,   161,   264,   309,
      33,    34,    35,   346,   286,    36,    37,   102,     6,     7,
       8,     9,    10,    11,    12,    13,    14,   198,   236,   328,
     179,    15,   182,   209,   211,   213,    16,    17,    18,    19,
      20,    21,    22,    23,    24,   215,    25,    26,    27,   212,
      29,    30,     0,   214,     0,     0,   103,     0,   216,     0,
      86,   217,     0,     0,    33,    34,    35,     0,     0,    36,
      37,   102,     6,     7,     8,     9,    10,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
       0,    17,    18,    19,    20,    21,    22,    23,    24,     0,
      25,    26,     0,     0,    29,    30,     0,     0,     0,     0,
     103,     0,     0,     0,    86,     0,     0,     0,    33,    34,
      35,     0,     0,    36,    37,   111,     6,     0,     8,     9,
      10,    11,   112,     0,    14,    11,    12,    13,    14,    15,
      11,    12,    13,    14,    16,     0,     0,     0,    16,   327,
       0,     0,     0,    16,     0,    26,    27,     0,     0,     0,
      27,     0,     0,   -16,    31,    27,   202,     0,    32,     0,
       0,     0,    33,    34,    35,     0,     0,    36,    37,    84,
       6,     0,     8,     9,    10,    11,   112,     0,    14,     0,
       0,     0,     0,    15,     0,     0,     0,     0,    16,    84,
       6,     0,     8,     9,    10,     0,     0,     0,     0,    26,
      27,    84,     6,    15,     8,     9,    10,     0,   103,     0,
       0,     0,    86,     0,     0,    15,    33,    34,    35,    26,
       0,    36,    37,     0,     0,     0,     0,     0,   103,   225,
       0,    26,    86,     0,     0,     0,    33,    34,    35,     0,
     103,    36,    37,   233,    86,     0,     0,     0,    33,    34,
      35,     0,     0,    36,    37,    84,     6,     0,     8,     9,
      10,     0,    84,     6,     0,     8,     9,    10,     0,    15,
       0,     0,     0,     0,     0,     0,    15,     0,     0,     0,
       0,     0,     0,     0,     0,    26,    84,     6,     0,     8,
       9,    10,    26,     0,   103,     0,   265,   257,    86,     0,
      15,   103,    33,    34,    35,    86,     0,    36,    37,    33,
      34,    35,     0,     0,    36,    37,    26,    84,     6,     0,
       8,     9,    10,     0,     0,   103,     0,     0,   303,    86,
       0,    15,     0,    33,    34,    35,     0,     0,    36,    37,
       0,    84,     6,     0,     8,     9,    10,    26,    84,     6,
       0,     8,     9,    10,     0,    15,    85,     0,     0,     0,
      86,     0,    15,     0,    33,    34,    35,     0,     0,    36,
      37,    26,     0,     0,     0,     0,     0,     0,    26,     0,
     100,     0,     0,     0,    86,     0,     0,   103,    33,    34,
      35,    86,     0,    36,    37,    33,    34,    35,     0,     0,
      36,    37,   -64,   -64,   -64,   -64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -64,     0,     0,
     -64,     0,     0,     0,  -117,   -64,     0,   -64
};

static const yytype_int16 yycheck[] =
{
       3,    15,    49,    94,     3,   114,    30,   132,   265,    32,
     289,   192,    26,    12,    13,     3,    31,     3,   112,   113,
       3,   110,    47,     3,    20,     3,   136,   195,    13,     0,
      72,     3,    10,    31,    46,    10,     3,     3,    42,    42,
      44,    53,    54,   153,    43,     3,    39,    36,   158,    36,
      39,    47,    45,    36,    42,    40,    44,    37,    72,    42,
      51,    52,   341,    46,    42,   233,    36,    91,    46,    41,
      42,    46,   163,    76,    46,   332,    43,    76,   203,     3,
      94,   105,   207,     3,    42,   100,   110,    85,   103,    37,
      76,   114,   202,   182,    13,    48,   119,   112,   113,    97,
     191,    19,   100,   106,   129,   103,   148,   149,   150,    38,
      39,   205,    17,   281,   295,   283,    21,     3,    42,   105,
      44,    49,    46,   137,    43,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,    42,   230,    44,
     138,   165,    39,   252,   269,    14,    43,   133,   316,   163,
     318,   175,    57,    15,   196,   265,    42,    42,   182,    44,
      46,   159,    42,    50,    44,   275,    46,   190,   260,    39,
     261,    16,   170,    43,   172,   173,   270,   191,    36,   177,
      41,    39,   196,   274,     9,    10,    36,    12,    39,    39,
     205,   190,    43,     3,   285,    38,    39,    22,   201,     9,
      10,    11,    12,     9,    10,    11,    12,    39,     3,    34,
      39,    43,    22,    38,    43,    37,    22,    36,   204,   310,
      39,   245,   332,    39,    34,    42,    39,    43,    34,   252,
      43,   230,    42,    43,    44,    42,    46,    43,    42,     9,
      10,    11,    12,    42,    42,   336,    44,   261,   295,   252,
      41,    39,    22,    41,    36,   270,    42,    43,    44,    43,
     274,   260,    41,   287,    34,    38,   290,    38,   292,   272,
     293,   285,     3,     4,    43,     6,     7,     8,    10,     9,
      10,    11,    12,    10,     9,    10,    17,    12,    38,    39,
     288,   289,    22,    37,   293,     3,   310,    22,     3,   298,
     146,   147,    33,    40,    34,    23,    37,    38,    41,    34,
       3,    42,    42,    43,    44,    46,    46,    43,    40,    50,
      51,    52,   336,    43,    55,    56,   350,   351,    45,    40,
      42,     1,   335,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,   341,    36,    39,    43,    17,    39,    45,
      45,    41,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    43,    32,    33,    34,    35,    36,    37,    43,    43,
       3,    36,    42,    31,    36,    43,    46,    76,   201,   270,
      50,    51,    52,   335,   239,    55,    56,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,   120,   166,   298,
     100,    17,   105,   137,   139,   141,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   143,    32,    33,    34,   140,
      36,    37,    -1,   142,    -1,    -1,    42,    -1,   144,    -1,
      46,   145,    -1,    -1,    50,    51,    52,    -1,    -1,    55,
      56,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      32,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    55,    56,     3,     4,    -1,     6,     7,
       8,     9,    10,    -1,    12,     9,    10,    11,    12,    17,
       9,    10,    11,    12,    22,    -1,    -1,    -1,    22,    18,
      -1,    -1,    -1,    22,    -1,    33,    34,    -1,    -1,    -1,
      34,    -1,    -1,    37,    42,    34,    40,    -1,    46,    -1,
      -1,    -1,    50,    51,    52,    -1,    -1,    55,    56,     3,
       4,    -1,     6,     7,     8,     9,    10,    -1,    12,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    22,     3,
       4,    -1,     6,     7,     8,    -1,    -1,    -1,    -1,    33,
      34,     3,     4,    17,     6,     7,     8,    -1,    42,    -1,
      -1,    -1,    46,    -1,    -1,    17,    50,    51,    52,    33,
      -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    33,    46,    -1,    -1,    -1,    50,    51,    52,    -1,
      42,    55,    56,    45,    46,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    55,    56,     3,     4,    -1,     6,     7,
       8,    -1,     3,     4,    -1,     6,     7,     8,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,     3,     4,    -1,     6,
       7,     8,    33,    -1,    42,    -1,    37,    45,    46,    -1,
      17,    42,    50,    51,    52,    46,    -1,    55,    56,    50,
      51,    52,    -1,    -1,    55,    56,    33,     3,     4,    -1,
       6,     7,     8,    -1,    -1,    42,    -1,    -1,    45,    46,
      -1,    17,    -1,    50,    51,    52,    -1,    -1,    55,    56,
      -1,     3,     4,    -1,     6,     7,     8,    33,     3,     4,
      -1,     6,     7,     8,    -1,    17,    42,    -1,    -1,    -1,
      46,    -1,    17,    -1,    50,    51,    52,    -1,    -1,    55,
      56,    33,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      42,    -1,    -1,    -1,    46,    -1,    -1,    42,    50,    51,
      52,    46,    -1,    55,    56,    50,    51,    52,    -1,    -1,
      55,    56,     9,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      37,    -1,    -1,    -1,    41,    42,    -1,    44
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    59,     0,    60,     1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    17,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    32,    33,    34,    35,    36,
      37,    42,    46,    50,    51,    52,    55,    56,    61,    63,
      64,    69,    71,    73,    74,    76,    84,    88,    89,    95,
     108,   109,   113,   114,   119,   124,   129,   131,   132,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   151,    62,    90,   110,    36,
      71,    72,    72,     3,     3,    42,    46,   146,     3,    37,
     125,   126,   127,   121,   111,   112,    36,   130,   120,     3,
      42,   146,     3,    42,    69,    70,    71,   108,   115,   117,
     118,     3,    10,    73,    81,    88,   105,   131,    10,    46,
      95,    96,    97,    98,     3,    36,    42,    78,    79,    88,
      72,    37,    68,    70,    89,    36,    39,    20,    47,    19,
      48,    49,    50,    14,    15,    16,    51,    52,    46,    53,
      54,    13,    40,   133,   145,   146,    17,    21,    42,    44,
      57,    61,    42,    44,    91,    41,    37,     3,    85,    86,
      42,   108,    42,    42,   134,    41,   131,    42,    36,   105,
      69,   116,   118,    88,    38,    38,   108,   115,    81,    81,
      42,    44,    95,   106,   107,    43,    43,    43,    97,    10,
      36,    39,    40,    67,    70,    75,   114,    66,   132,   136,
     131,   137,   138,   139,   140,   141,   142,   143,   144,   144,
     145,   145,   145,   132,     3,    43,   132,   150,   131,     3,
      92,    93,    94,    45,   134,   108,    85,    87,    38,    39,
     131,    23,   128,   131,   131,    41,   108,    36,   131,    43,
     115,    43,    71,    99,   100,   101,   106,    45,   134,   107,
      42,    44,    91,   145,    79,    37,   103,   132,   114,    65,
      77,    80,    81,   114,    41,    39,    43,    45,    99,     3,
     102,    43,    91,    45,    38,    40,    86,    43,    42,    36,
      43,   108,    43,    42,    88,    95,   106,    43,    39,    43,
      45,    43,    99,    45,   134,   103,   104,   114,    38,    80,
      41,    82,    83,    88,   134,   132,    43,    39,    43,    91,
      91,   134,   108,   131,   128,   108,   108,    18,   101,    43,
      45,    38,    39,   134,    36,    39,    41,    91,     3,    91,
      43,    36,    31,   122,    38,   103,    83,   134,    36,   128,
     123,    43,   108,   108
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

/* Line 1455 of yacc.c  */
#line 65 "../src/TP4.y"
    {tipo_declaracion=0;;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 69 "../src/TP4.y"
    {imprimirError("[ERROR LEXICO]", (yyvsp[(1) - (1)].cadena), yylineno);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 70 "../src/TP4.y"
    {imprimirError("[ERROR SINTACTICO]", "", yylineno);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 70 "../src/TP4.y"
    {yyerrok;;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 75 "../src/TP4.y"
    {tipo_declaracion=0;;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 76 "../src/TP4.y"
    {tipo_declaracion=0;;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 77 "../src/TP4.y"
    {tipo_declaracion=0;;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 78 "../src/TP4.y"
    {tipo_declaracion=0;;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 80 "../src/TP4.y"
    {imprimirInfo(tipo_declaracion, tipo, identificador, yylineno);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 93 "../src/TP4.y"
    {tipo=strdup((yyvsp[(1) - (1)].cadena));;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 98 "../src/TP4.y"
    {tipo=strdup((yyvsp[(1) - (2)].cadena));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 99 "../src/TP4.y"
    {tipo=strdup((yyvsp[(1) - (1)].cadena));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 106 "../src/TP4.y"
    {tipo=strdup((yyvsp[(1) - (2)].cadena)); identificador=strdup((yyvsp[(2) - (2)].cadena));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 107 "../src/TP4.y"
    {tipo=strdup((yyvsp[(1) - (1)].cadena));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 139 "../src/TP4.y"
    {identificador=strdup((yyvsp[(1) - (1)].cadena));;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 140 "../src/TP4.y"
    {identificador=strdup((yyvsp[(1) - (1)].cadena));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 145 "../src/TP4.y"
    {if(tipo_declaracion == 0) identificador = strdup((yyvsp[(1) - (1)].cadena));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 150 "../src/TP4.y"
    {tipo_declaracion=1;;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 151 "../src/TP4.y"
    {tipo_declaracion=1;;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 152 "../src/TP4.y"
    {tipo_declaracion=1;;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 176 "../src/TP4.y"
    {identificador = strdup((yyvsp[(1) - (1)].cadena));;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 177 "../src/TP4.y"
    {identificador = strdup((yyvsp[(3) - (3)].cadena));;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 204 "../src/TP4.y"
    {imprimirData("Expresion", tipo_sentencia, yylineno); tipo = 0;;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 210 "../src/TP4.y"
    {imprimirData("Etiquetada", tipo_sentencia, yylineno); identificador = strdup((yyvsp[(1) - (1)].cadena));;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 211 "../src/TP4.y"
    {imprimirData("Etiquetada", tipo_sentencia, yylineno);;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 212 "../src/TP4.y"
    {imprimirData("Etiquetada", tipo_sentencia, yylineno);;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 232 "../src/TP4.y"
    {imprimirData("de Seleccion", tipo_sentencia, yylineno);;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 233 "../src/TP4.y"
    {imprimirData("de Seleccion", tipo_sentencia, yylineno);;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 235 "../src/TP4.y"
    {imprimirData("de Seleccion", tipo_sentencia, yylineno);;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 238 "../src/TP4.y"
    {imprimirData("de Iteracion", tipo_sentencia, yylineno);;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 239 "../src/TP4.y"
    {imprimirData("de Iteracion", tipo_sentencia, yylineno);;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 240 "../src/TP4.y"
    {imprimirData("de Iteracion", tipo_sentencia, yylineno);;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 245 "../src/TP4.y"
    {identificador = strdup((yyvsp[(2) - (3)].cadena)); imprimirData("de Salto", tipo_sentencia, yylineno);;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 246 "../src/TP4.y"
    {imprimirData("de Salto", tipo_sentencia, yylineno);;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 247 "../src/TP4.y"
    {imprimirData("de Salto", tipo_sentencia, yylineno);;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 248 "../src/TP4.y"
    {imprimirData("de Salto", tipo_sentencia, yylineno);;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 254 "../src/TP4.y"
    {if(tipo_sentencia<1) tipo_sentencia=1;;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 260 "../src/TP4.y"
    {if(tipo_sentencia<2) tipo_sentencia=2;;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 263 "../src/TP4.y"
    {if(tipo_sentencia<3) tipo_sentencia=3;;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 266 "../src/TP4.y"
    {if(tipo_sentencia<3) tipo_sentencia=3;;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 269 "../src/TP4.y"
    {if(tipo_sentencia<3) tipo_sentencia=3;;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 272 "../src/TP4.y"
    {if(tipo_sentencia<3) tipo_sentencia=3;;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 275 "../src/TP4.y"
    {if(tipo_sentencia<3) tipo_sentencia=3;;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 278 "../src/TP4.y"
    {if(tipo_sentencia<4) tipo_sentencia=4;;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 281 "../src/TP4.y"
    {if(tipo_sentencia<5) tipo_sentencia=5;;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 284 "../src/TP4.y"
    {if(tipo_sentencia<6) tipo_sentencia=6;;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 287 "../src/TP4.y"
    {if(tipo_sentencia<7) tipo_sentencia=7;;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 288 "../src/TP4.y"
    {if(tipo_sentencia<7) tipo_sentencia=7;;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 291 "../src/TP4.y"
    {if(tipo_sentencia<8) tipo_sentencia=8;;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 292 "../src/TP4.y"
    {if(tipo_sentencia<8) tipo_sentencia=8;;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 293 "../src/TP4.y"
    {if(tipo_sentencia<8) tipo_sentencia=8;;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 296 "../src/TP4.y"
    {if(tipo_sentencia<9) tipo_sentencia=9;;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 299 "../src/TP4.y"
    {if(tipo_sentencia<10) tipo_sentencia=10;;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 300 "../src/TP4.y"
    {if(tipo_sentencia<10) tipo_sentencia=10;;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 301 "../src/TP4.y"
    {if(tipo_sentencia<10) tipo_sentencia=10;;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 302 "../src/TP4.y"
    {if(tipo_sentencia<10) tipo_sentencia=10;;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 312 "../src/TP4.y"
    {if(tipo_sentencia<11) tipo_sentencia=11;;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 313 "../src/TP4.y"
    {if(tipo_sentencia<11) tipo_sentencia=11;;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 314 "../src/TP4.y"
    {if(tipo_sentencia<11) tipo_sentencia=11;;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 315 "../src/TP4.y"
    {identificador = strdup((yyvsp[(3) - (3)].cadena));if(tipo_sentencia<11) tipo_sentencia=11;;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 316 "../src/TP4.y"
    {identificador = strdup((yyvsp[(3) - (3)].cadena));if(tipo_sentencia<11) tipo_sentencia=11;;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 317 "../src/TP4.y"
    {if(tipo_sentencia<11) tipo_sentencia=11;;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 319 "../src/TP4.y"
    {identificador = strdup((yyvsp[(1) - (1)].cadena));;}
    break;



/* Line 1455 of yacc.c  */
#line 2289 "TP4.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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



/* Line 1675 of yacc.c  */
#line 331 "../src/TP4.y"

void main (int argc, char *argv[])
{
        yyin = fopen(argv[1], "r");
        /*
#ifdef BISON_DEBUG
        yydebug = 1;
#endif
*/
        printf("||--------------- REPORTE ---------------||");
        yyparse ();
        fclose(yyin);
        printf("\n\n||---------------------------------------||\n");
}
