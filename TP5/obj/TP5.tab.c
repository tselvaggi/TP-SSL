
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
#line 1 "../src/TP5.y"
 
//Definiciones y declaraciones de C
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "funciones.h"

extern FILE* yyin;
extern int yylineno;
int tipo_declaracion=0;
char* tipo;
char* nombre_ppal;
char* nombreFuncion;
char* identificador;
int dimensiones=0;
int cant_corchetes=0;
int contador_parametros=0;
char* auxiliar;
int hay_llaves=0;
int cantidad_valores=0;
int es_puntero=0;

int yylex(void);
int yywrap(){ return(1); }

int yyerror (char* msg) {
        insertarError(&listaErrores, msg, "",'Z', yylineno);
        return 0;
}


/* Line 189 of yacc.c  */
#line 108 "TP5.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
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
     TYPEDEF = 289
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 36 "../src/TP5.y"

        struct yylval_struct {
                char* cadena;
                int entero;
                float real;
                char* tipo;
                char simbolo;
                char* identificador;
                char funcion;
        }myStruct;



/* Line 214 of yacc.c  */
#line 192 "TP5.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 204 "TP5.tab.c"

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
#define YYLAST   943

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  87
/* YYNRULES -- Number of rules.  */
#define YYNRULES  205
/* YYNRULES -- Number of states.  */
#define YYNSTATES  351

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,     2,     2,    53,    49,     2,
      41,    42,    45,    50,    38,    51,    56,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    35,
       2,    39,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,    48,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,    47,    37,    54,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,     9,    11,    13,    15,    17,
      18,    24,    25,    30,    31,    36,    37,    41,    45,    48,
      51,    53,    56,    59,    61,    64,    66,    67,    69,    71,
      73,    75,    81,    86,    89,    91,    94,    96,    97,   102,
     104,   105,   110,   114,   117,   120,   122,   125,   127,   129,
     133,   135,   139,   142,   148,   153,   156,   158,   162,   164,
     168,   171,   173,   174,   178,   183,   184,   190,   191,   196,
     197,   203,   204,   210,   211,   216,   217,   218,   222,   224,
     226,   230,   232,   236,   239,   242,   244,   246,   250,   252,
     256,   261,   263,   267,   270,   272,   274,   277,   279,   283,
     288,   292,   296,   299,   304,   308,   312,   315,   317,   319,
     321,   323,   325,   327,   330,   334,   339,   343,   346,   348,
     352,   356,   359,   360,   363,   364,   367,   369,   372,   379,
     385,   388,   389,   395,   403,   413,   415,   416,   420,   423,
     427,   430,   432,   436,   438,   442,   444,   446,   448,   454,
     456,   460,   462,   466,   468,   472,   474,   478,   480,   484,
     486,   490,   492,   496,   498,   502,   504,   508,   512,   514,
     518,   522,   526,   528,   533,   535,   538,   541,   544,   549,
     551,   553,   555,   557,   559,   561,   563,   568,   569,   575,
     579,   583,   586,   588,   590,   592,   596,   598,   600,   601,
     602,   606,   610,   611,   613,   615
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      58,     0,    -1,    -1,    -1,    58,    59,    60,    -1,    61,
      -1,   105,    -1,    62,    -1,    67,    -1,    -1,    69,    85,
      68,    63,   108,    -1,    -1,    85,    68,    64,   108,    -1,
      -1,    69,    85,    65,   108,    -1,    -1,    85,    66,   108,
      -1,    69,    74,    35,    -1,    69,    35,    -1,     1,    35,
      -1,    67,    -1,    68,    67,    -1,    11,    70,    -1,    71,
      -1,    10,    70,    -1,    69,    -1,    -1,     9,    -1,    72,
      -1,    82,    -1,    34,    -1,    12,     3,    36,    73,    37,
      -1,    12,    36,    73,    37,    -1,    12,     3,    -1,    78,
      -1,    73,    78,    -1,    76,    -1,    -1,    74,    75,    38,
      76,    -1,    85,    -1,    -1,    85,    39,   100,    77,    -1,
      79,    80,    35,    -1,     1,    35,    -1,    71,    79,    -1,
      71,    -1,    10,    79,    -1,    10,    -1,    81,    -1,    80,
      38,    81,    -1,    85,    -1,    85,    40,   121,    -1,    40,
     121,    -1,    22,     3,    36,    83,    37,    -1,    22,    36,
      83,    37,    -1,    22,     3,    -1,    84,    -1,    83,    38,
      84,    -1,     3,    -1,     3,    39,   121,    -1,    94,    86,
      -1,    86,    -1,    -1,     3,    87,    88,    -1,    41,    85,
      42,    88,    -1,    -1,    43,   121,    44,    89,    88,    -1,
      -1,    43,    44,    90,    88,    -1,    -1,    41,    91,    96,
      42,    88,    -1,    -1,    41,    92,    99,    42,    88,    -1,
      -1,    41,    93,    42,    88,    -1,    -1,    -1,    45,    95,
      94,    -1,    45,    -1,    97,    -1,    97,    38,    18,    -1,
      98,    -1,    97,    38,    98,    -1,    69,    85,    -1,    69,
     103,    -1,    69,    -1,     3,    -1,    99,    38,     3,    -1,
     119,    -1,    36,   101,    37,    -1,    36,   101,    38,    37,
      -1,   100,    -1,   101,    38,   100,    -1,    79,   103,    -1,
      79,    -1,    94,    -1,    94,   104,    -1,   104,    -1,    41,
     103,    42,    -1,   104,    43,   121,    44,    -1,    43,   121,
      44,    -1,   104,    43,    44,    -1,    43,    44,    -1,   104,
      41,    96,    42,    -1,    41,    96,    42,    -1,   104,    41,
      42,    -1,    41,    42,    -1,   106,    -1,   107,    -1,   108,
      -1,   113,    -1,   115,    -1,   117,    -1,     1,    35,    -1,
       3,    40,   105,    -1,    27,   121,    40,   105,    -1,    28,
      40,   105,    -1,   118,    35,    -1,    35,    -1,    36,   109,
      37,    -1,    36,   111,    37,    -1,    68,   110,    -1,    -1,
     112,   109,    -1,    -1,   112,   109,    -1,   105,    -1,   112,
     105,    -1,    30,    41,   118,    42,   105,   114,    -1,    26,
      41,   118,    42,   105,    -1,    31,   105,    -1,    -1,    23,
      41,   118,    42,   105,    -1,    24,   105,    23,    41,   118,
      42,    35,    -1,    25,    41,   116,    35,   116,    35,   116,
      42,   105,    -1,   118,    -1,    -1,    32,     3,    35,    -1,
       5,    35,    -1,    29,   118,    35,    -1,    29,    35,    -1,
     119,    -1,   118,    38,   119,    -1,   121,    -1,   133,   120,
     119,    -1,    13,    -1,    39,    -1,   122,    -1,   122,    46,
     118,    40,   121,    -1,   123,    -1,   122,    20,   123,    -1,
     124,    -1,   123,    19,   124,    -1,   125,    -1,   124,    47,
     125,    -1,   126,    -1,   125,    48,   126,    -1,   127,    -1,
     126,    49,   127,    -1,   128,    -1,   127,    14,   128,    -1,
     129,    -1,   128,    15,   129,    -1,   130,    -1,   129,    16,
     130,    -1,   131,    -1,   130,    50,   131,    -1,   130,    51,
     131,    -1,   132,    -1,   131,    45,   132,    -1,   131,    52,
     132,    -1,   131,    53,   132,    -1,   133,    -1,    41,   102,
      42,   132,    -1,   135,    -1,    17,   133,    -1,   134,   132,
      -1,    33,   133,    -1,    33,    41,   102,    42,    -1,    49,
      -1,    45,    -1,    50,    -1,    51,    -1,    54,    -1,    55,
      -1,   137,    -1,   135,    43,   118,    44,    -1,    -1,   138,
     136,    41,   139,    42,    -1,   135,    56,     3,    -1,   135,
      21,     3,    -1,   135,    17,    -1,   138,    -1,   143,    -1,
       4,    -1,    41,   118,    42,    -1,     3,    -1,   140,    -1,
      -1,    -1,   119,   141,   142,    -1,    38,   119,   142,    -1,
      -1,     6,    -1,     8,    -1,     7,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    72,    72,    73,    73,    75,    76,    78,    79,    81,
      81,    82,    82,    83,    83,    99,    99,   101,   106,   107,
     109,   110,   112,   113,   114,   116,   117,   119,   120,   121,
     122,   124,   125,   126,   128,   129,   131,   132,   132,   134,
     135,   135,   150,   151,   153,   154,   155,   156,   158,   159,
     161,   162,   163,   165,   166,   167,   169,   170,   172,   173,
     175,   176,   178,   178,   199,   201,   201,   202,   202,   203,
     203,   204,   204,   205,   205,   206,   208,   208,   209,   211,
     212,   214,   215,   217,   218,   219,   221,   222,   224,   225,
     226,   228,   229,   231,   232,   234,   235,   236,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   248,   249,   250,
     251,   252,   253,   254,   256,   257,   258,   260,   261,   263,
     264,   267,   268,   270,   271,   273,   275,   276,   278,   279,
     281,   282,   284,   285,   286,   288,   289,   291,   292,   293,
     294,   296,   297,   299,   300,   309,   310,   312,   313,   315,
     316,   318,   319,   321,   322,   324,   325,   327,   328,   330,
     331,   333,   334,   336,   337,   339,   340,   355,   371,   372,
     387,   412,   414,   415,   417,   418,   419,   420,   421,   423,
     424,   425,   426,   427,   428,   430,   440,   441,   441,   456,
     457,   458,   460,   461,   466,   470,   476,   493,   494,   496,
     496,   504,   512,   515,   519,   523
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
  "DEFAULT", "RETURN", "IF", "ELSE", "GOTO", "SIZEOF", "TYPEDEF", "';'",
  "'{'", "'}'", "','", "'='", "':'", "'('", "')'", "'['", "']'", "'*'",
  "'?'", "'|'", "'^'", "'&'", "'+'", "'-'", "'/'", "'%'", "'~'", "'!'",
  "'.'", "$accept", "unidad_de_programa", "$@1", "unidad_de_traduccion",
  "declaracion_externa", "definicion_de_funcion", "$@2", "$@3", "$@4",
  "$@5", "declaracion", "lista_de_declaracion",
  "especificadores_de_declaracion",
  "especificadores_de_declaracion_o_vacio", "especificador_de_tipo",
  "especificador_estructura_o_union", "lista_declaraciones_struct",
  "lista_declaradores_init", "$@6", "declarador_init", "$@7",
  "declaracion_struct", "lista_calificador_especificador",
  "lista_declaradores_struct", "declarador_struct", "especificador_enum",
  "lista_de_enumerador", "enumerador", "declarador", "declarador_directo",
  "@8", "R_declarador_directo", "$@9", "$@10", "$@11", "$@12", "$@13",
  "apuntador", "$@14", "lista_tipos_de_parametro", "lista_de_parametros",
  "declaracion_de_parametro", "lista_de_identificadores", "inicializador",
  "lista_de_inicializadores", "nombre_de_tipo", "declarador_abstracto",
  "declarador_abstracto_directo", "sentencia", "sentencia_etiquetada",
  "sentencia_expresion", "sentencia_compuesta", "X", "Y", "Z",
  "lista_de_sentencias", "sentencia_de_seleccion",
  "sentencia_de_seleccion_aux", "sentencia_de_iteracion",
  "expresion_o_vacio", "sentencia_de_salto", "expresion",
  "expresion_de_asignacion", "operador_de_asignacion",
  "expresion_condicional", "expresion_logica_or", "expresion_logica_and",
  "expresion_or_inclusivo", "expresion_or_exclusivo", "expresion_and",
  "expresion_de_igualdad", "expresion_relacional",
  "expresion_de_corrimiento", "expresion_aditiva",
  "expresion_multiplicativa", "expresion_cast", "expresion_unaria",
  "operador_unario", "expresion_posfija", "@15", "expresion_primaria",
  "id", "lista_expresiones_argumento_o_vacio",
  "lista_expresiones_argumento", "$@16", "r_r", "constante", 0
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
     285,   286,   287,   288,   289,    59,   123,   125,    44,    61,
      58,    40,    41,    91,    93,    42,    63,   124,    94,    38,
      43,    45,    47,    37,   126,    33,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    58,    60,    60,    61,    61,    63,
      62,    64,    62,    65,    62,    66,    62,    67,    67,    67,
      68,    68,    69,    69,    69,    70,    70,    71,    71,    71,
      71,    72,    72,    72,    73,    73,    74,    75,    74,    76,
      77,    76,    78,    78,    79,    79,    79,    79,    80,    80,
      81,    81,    81,    82,    82,    82,    83,    83,    84,    84,
      85,    85,    87,    86,    86,    89,    88,    90,    88,    91,
      88,    92,    88,    93,    88,    88,    95,    94,    94,    96,
      96,    97,    97,    98,    98,    98,    99,    99,   100,   100,
     100,   101,   101,   102,   102,   103,   103,   103,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   105,   105,   105,
     105,   105,   105,   105,   106,   106,   106,   107,   107,   108,
     108,   109,   109,   110,   110,   111,   112,   112,   113,   113,
     114,   114,   115,   115,   115,   116,   116,   117,   117,   117,
     117,   118,   118,   119,   119,   120,   120,   121,   121,   122,
     122,   123,   123,   124,   124,   125,   125,   126,   126,   127,
     127,   128,   128,   129,   129,   130,   130,   130,   131,   131,
     131,   131,   132,   132,   133,   133,   133,   133,   133,   134,
     134,   134,   134,   134,   134,   135,   135,   136,   135,   135,
     135,   135,   137,   137,   137,   137,   138,   139,   139,   141,
     140,   142,   142,   143,   143,   143
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     3,     1,     1,     1,     1,     0,
       5,     0,     4,     0,     4,     0,     3,     3,     2,     2,
       1,     2,     2,     1,     2,     1,     0,     1,     1,     1,
       1,     5,     4,     2,     1,     2,     1,     0,     4,     1,
       0,     4,     3,     2,     2,     1,     2,     1,     1,     3,
       1,     3,     2,     5,     4,     2,     1,     3,     1,     3,
       2,     1,     0,     3,     4,     0,     5,     0,     4,     0,
       5,     0,     5,     0,     4,     0,     0,     3,     1,     1,
       3,     1,     3,     2,     2,     1,     1,     3,     1,     3,
       4,     1,     3,     2,     1,     1,     2,     1,     3,     4,
       3,     3,     2,     4,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     2,     3,     4,     3,     2,     1,     3,
       3,     2,     0,     2,     0,     2,     1,     2,     6,     5,
       2,     0,     5,     7,     9,     1,     0,     3,     2,     3,
       2,     1,     3,     1,     3,     1,     1,     1,     5,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     4,     1,     2,     2,     2,     4,     1,
       1,     1,     1,     1,     1,     1,     4,     0,     5,     3,
       3,     2,     1,     1,     1,     3,     1,     1,     0,     0,
       3,     3,     0,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     3,     1,     0,     0,   196,   194,     0,   203,   205,
     204,    27,    26,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    30,   118,     0,
       0,   180,   179,   181,   182,   183,   184,     4,     5,     7,
       8,     0,    23,    28,    29,     0,    61,     0,     6,   107,
     108,   109,   110,   111,   112,     0,   141,   143,   147,   149,
     151,   153,   155,   157,   159,   161,   163,   165,   168,   172,
       0,   174,   185,   192,   193,    19,     0,    75,   138,    25,
      24,    22,    33,     0,   196,     0,   180,   175,    55,     0,
       0,     0,   196,     0,     0,   136,     0,     0,   172,     0,
     140,     0,     0,     0,     0,   177,    20,     0,     0,   126,
       0,     0,     0,   196,    47,    45,    94,     0,     0,     0,
       0,    62,    18,     0,    78,    37,    36,     0,     0,     0,
       0,    60,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   145,   146,
       0,   176,   191,     0,     0,     0,     0,   114,    69,     0,
      63,     0,     0,     0,    34,     0,     0,    58,     0,    56,
       0,   113,     0,     0,   135,     0,     0,   116,   139,     0,
     137,     0,    21,   121,     0,    39,   119,   120,   127,   125,
      46,    44,     0,     0,    95,    93,    97,    75,     0,   195,
      77,    17,     0,     0,     0,     0,    19,    16,     0,   142,
     150,     0,   152,   154,   156,   158,   160,   162,   164,   166,
     167,   169,   170,   171,   144,   190,     0,   189,   198,     0,
       0,     0,    67,     0,     0,    43,    32,    35,     0,     0,
      48,    50,     0,     0,    54,     0,     0,     0,   136,     0,
     115,     0,   178,   123,   106,    85,     0,    79,    81,     0,
     102,     0,    96,     0,     0,    64,   173,     0,     0,    40,
      88,    14,     0,    12,     0,   186,   199,     0,   197,     0,
      86,     0,    75,    75,    65,    31,    52,    42,     0,     0,
      53,    59,    57,   132,     0,     0,   129,   131,     0,    83,
      95,    84,   104,     0,    98,   100,   105,     0,   101,     0,
      38,    91,     0,    41,    10,   148,   202,   188,    75,     0,
      75,    74,    68,    75,    49,    51,     0,   136,     0,   128,
      80,    82,   103,    99,    89,     0,     0,   200,    70,    87,
      72,    66,   133,     0,   130,    90,    92,   202,     0,   201,
     134
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     3,    37,    38,    39,   272,   208,   204,   129,
     106,   107,   108,    80,    42,    43,   163,   125,   202,   126,
     313,   164,   165,   239,   240,    44,   168,   169,   117,    46,
      77,   160,   323,   283,   229,   230,   231,    47,   120,   256,
     257,   258,   281,   269,   312,   118,   259,   196,   109,    49,
      50,    51,   110,   183,   111,   112,    52,   329,    53,   173,
      54,    55,    56,   150,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,   156,
      72,    73,   277,   278,   316,   337,    74
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -259
static const yytype_int16 yypact[] =
{
    -259,    38,  -259,   416,    10,   858,  -259,    14,  -259,  -259,
    -259,  -259,   370,   370,    27,   773,    31,    12,   471,    19,
      24,   780,    71,   217,    85,   128,   833,  -259,  -259,   306,
     524,    39,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,
    -259,    21,  -259,  -259,  -259,   709,  -259,    30,  -259,  -259,
    -259,  -259,  -259,  -259,  -259,     2,  -259,  -259,    11,   167,
     132,   143,   145,   194,   207,   197,   124,    -9,  -259,    22,
     780,   150,  -259,   187,  -259,  -259,   471,   119,  -259,  -259,
    -259,  -259,   201,   480,  -259,   780,  -259,  -259,   209,   227,
     780,   212,   211,   577,   231,   780,   780,   215,  -259,   471,
    -259,    90,   780,   221,   577,  -259,  -259,   361,    21,  -259,
     223,   224,   306,   155,   501,   501,     7,   222,   232,    13,
     228,  -259,  -259,    56,   234,   246,  -259,   528,   247,   249,
     843,  -259,  -259,   780,   780,   780,   780,   780,   780,   780,
     780,   780,   780,   780,   780,   780,   780,   780,  -259,  -259,
     780,  -259,  -259,   280,   780,   284,   248,  -259,    92,   633,
    -259,   480,   255,   168,  -259,    75,   227,   252,   174,  -259,
      79,  -259,   251,   258,   256,    80,   471,  -259,  -259,    81,
    -259,   254,  -259,  -259,   306,   260,  -259,  -259,  -259,  -259,
    -259,  -259,   893,   652,   146,  -259,   160,   119,   780,  -259,
    -259,  -259,   259,   705,   249,   907,  -259,  -259,   249,  -259,
     167,   179,   132,   143,   145,   194,   207,   197,   124,    -9,
      -9,  -259,  -259,  -259,  -259,  -259,     3,  -259,   780,   370,
     298,   262,  -259,   261,   446,  -259,  -259,  -259,   780,   123,
    -259,   279,   198,   780,  -259,   227,   471,   780,   780,   471,
    -259,   471,  -259,  -259,  -259,   127,   278,   264,  -259,   282,
    -259,   277,   160,   266,   720,  -259,  -259,    56,   705,  -259,
    -259,  -259,   249,  -259,   780,  -259,  -259,   285,  -259,   295,
    -259,    99,   119,   119,  -259,  -259,  -259,  -259,    75,   780,
    -259,  -259,  -259,  -259,   117,   287,  -259,   313,   173,  -259,
      67,  -259,  -259,   782,  -259,  -259,  -259,   304,  -259,   305,
    -259,  -259,   202,  -259,  -259,  -259,   288,  -259,   119,   345,
     119,  -259,  -259,   119,  -259,  -259,   315,   780,   471,  -259,
    -259,  -259,  -259,  -259,  -259,   597,   780,  -259,  -259,  -259,
    -259,  -259,  -259,   310,  -259,  -259,  -259,   288,   471,  -259,
    -259
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,
       5,   -20,     0,   340,   -25,  -259,   193,  -259,  -259,    91,
    -259,  -149,   -11,  -259,    86,  -259,   210,   114,    -2,   -43,
    -259,  -191,  -259,  -259,  -259,  -259,  -259,   -98,  -259,  -209,
    -259,    60,  -259,  -258,  -259,   271,   -99,  -187,    -3,  -259,
    -259,  -106,   -84,  -259,  -259,   270,  -259,  -259,  -259,  -222,
    -259,   -21,  -104,  -259,    -5,  -259,   265,   267,   263,   269,
     274,   268,   273,   276,    98,   -59,     6,  -259,  -259,  -259,
    -259,  -259,  -259,  -259,  -259,    54,  -259
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -188
static const yytype_int16 yytable[] =
{
      48,    45,   101,    41,   131,   115,   265,   262,    40,   119,
     311,   151,    79,    79,   237,    94,    97,   195,   194,   116,
     279,    87,   200,   207,   121,   130,   295,    98,   189,   209,
      82,   134,   105,   121,    88,   148,   145,   132,     2,   127,
     133,   133,   -78,   146,   147,    75,   224,   275,   192,    78,
     193,   133,   124,    90,   307,   199,   122,   135,   115,   121,
      95,   149,   123,    83,   119,    96,   124,    89,   115,   170,
     121,   123,   119,   157,   174,   175,    98,   346,   121,   115,
     -78,   179,   116,   119,   -76,   237,   221,   222,   223,   115,
     115,   321,   322,   116,   194,   -71,   177,   123,   271,   270,
     253,   124,   273,   190,   191,   343,   185,   205,   298,   188,
     193,    99,   182,   262,   211,   238,   123,   133,   133,   133,
     124,   246,   249,   251,   276,   178,   102,   338,   133,   340,
     121,   103,   341,   226,   -73,   182,   115,   319,   115,   266,
      98,   320,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,   233,   133,   301,   300,   287,   326,
     158,   288,   159,   241,   270,    98,   314,   152,   298,   162,
     193,   153,   124,   250,   143,   144,   121,    11,   114,   137,
      14,   188,    11,    12,    13,    14,   136,   192,   261,   193,
      16,   138,   255,   154,   139,    16,   -62,   -62,   -62,    98,
     300,   263,    27,   264,    98,   236,   155,    27,   140,   115,
     182,   244,   245,   142,   298,   254,   193,   133,   124,   274,
      84,     6,   141,     8,     9,    10,   294,   174,  -187,   255,
     167,   270,   347,   286,    15,   290,   245,   161,   291,   334,
     335,   219,   220,   293,    98,   166,   296,   171,   297,    98,
      26,    76,   100,   299,   172,   176,   180,   131,    93,   309,
     186,   187,    86,   255,   197,   185,    32,    33,    34,   315,
      98,    35,    36,   124,   198,    11,    12,    13,    14,   -76,
      98,   201,   206,   225,   325,    29,   241,   227,    16,   228,
     235,   243,   247,   248,   133,    98,   252,   267,   255,   203,
      27,   280,   303,   255,   282,   284,   174,     4,   306,    92,
       6,     7,     8,     9,    10,    11,    12,    13,    14,   289,
     302,   305,   327,    15,   304,   344,   336,   317,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   318,    25,    26,
      27,    28,    29,  -122,   328,   350,   332,    93,   339,   333,
     342,    86,   348,    81,   234,    32,    33,    34,   310,   292,
      35,    36,     4,   331,    92,     6,     7,     8,     9,    10,
      11,    12,    13,    14,   324,   181,   242,   184,    15,    11,
      12,    13,    14,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    16,    25,    26,    27,    28,    29,  -124,   210,
     213,   349,    93,   212,    27,     0,    86,   214,   216,     0,
      32,    33,    34,   215,   217,    35,    36,     4,   218,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,     0,
       0,     0,     0,    15,     0,     0,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   162,    25,    26,
      27,    28,    29,     0,     0,    11,   114,    30,    14,     0,
       0,    31,     0,     0,     0,    32,    33,    34,    16,     0,
      35,    36,    91,     0,    92,     6,     7,     8,     9,    10,
      27,   162,     0,   285,     0,     0,     0,     0,    15,    11,
     114,     0,    14,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    16,    25,    26,     0,    28,    29,     0,     0,
      11,   114,    93,    14,    27,     0,    86,     0,     0,     0,
      32,    33,    34,    16,     0,    35,    36,   113,     6,   128,
       8,     9,    10,    11,   114,    27,    14,    11,    12,    13,
      14,    15,     0,     0,     0,     0,    16,     0,     0,     0,
      16,     0,     0,     0,     0,     0,     0,    26,    27,     0,
       0,     0,    27,   -39,   -13,    30,   -39,   203,     0,    31,
       0,     0,     0,    32,    33,    34,     0,     0,    35,    36,
      84,     6,     0,     8,     9,    10,    11,   114,     0,    14,
       0,     0,     0,     0,    15,     0,     0,     0,     0,    16,
      84,     6,     0,     8,     9,    10,     0,     0,     0,     0,
      26,    27,     0,     0,    15,     0,     0,     0,    93,     0,
       0,     0,    86,     0,     0,     0,    32,    33,    34,     0,
      26,    35,    36,   268,   345,     0,    84,     6,    93,     8,
       9,    10,    86,     0,     0,     0,    32,    33,    34,     0,
      15,    35,    36,     0,     0,    84,     6,     0,     8,     9,
      10,     0,     0,     0,     0,     0,    26,     0,     0,    15,
       0,     0,     0,     0,    93,     0,     0,   232,    86,     0,
       0,     0,    32,    33,    34,    26,     0,    35,    36,     0,
       0,     0,     0,    93,     0,     0,   260,    86,     0,     0,
       0,    32,    33,    34,     0,     0,    35,    36,    84,     6,
     128,     8,     9,    10,     0,     0,     0,     0,    11,    12,
      13,    14,    15,    84,     6,     0,     8,     9,    10,     0,
       0,    16,     0,     0,     0,     0,     0,    15,    26,     0,
       0,   268,     0,    27,     0,   -15,    93,     0,     0,     0,
      86,     0,     0,    26,    32,    33,    34,     0,     0,    35,
      36,    93,     0,     0,   308,    86,     0,     0,     0,    32,
      33,    34,     0,     0,    35,    36,    84,     6,     0,     8,
       9,    10,     0,    84,     6,     0,     8,     9,    10,     0,
      15,    11,    12,    13,    14,     0,     0,    15,     0,     0,
     330,     0,     0,     0,    16,     0,    26,     0,     0,     0,
       0,     0,     0,    26,    85,     0,    27,     0,    86,     0,
       0,    93,    32,    33,    34,    86,     0,    35,    36,    32,
      33,    34,     0,     0,    35,    36,    84,     6,     0,     8,
       9,    10,     0,     0,   128,     0,     0,     0,     0,     0,
      15,     0,    11,    12,    13,    14,     0,     0,     0,   -62,
       0,     0,     0,     0,     0,    16,    26,   -62,   -62,   -62,
     -62,     0,     0,     0,   104,     0,     0,    27,    86,   -11,
     -62,     0,    32,    33,    34,     0,     0,    35,    36,     0,
       0,     0,   -62,     0,   -62,     0,     0,     0,    76,   -62,
       0,   -62,    11,    12,    13,    14,     0,     0,   128,     0,
       0,     0,     0,     0,     0,    16,    11,    12,    13,    14,
       0,     0,     0,     0,     0,     0,     0,    27,     0,    16,
       0,     0,     0,     0,   192,   254,   193,     0,   124,     0,
       0,    27,     0,    -9
};

static const yytype_int16 yycheck[] =
{
       3,     3,    23,     3,    47,    30,   197,   194,     3,    30,
     268,    70,    12,    13,   163,    18,    21,   116,   116,    30,
     229,    15,   120,   129,     3,    45,   248,    21,   112,   133,
       3,    20,    26,     3,     3,    13,    45,    35,     0,    41,
      38,    38,     3,    52,    53,    35,   150,    44,    41,    35,
      43,    38,    45,    41,   263,    42,    35,    46,    83,     3,
      41,    39,    41,    36,    85,    41,    45,    36,    93,    90,
       3,    41,    93,    76,    95,    96,    70,   335,     3,   104,
      41,   102,    93,   104,    45,   234,   145,   146,   147,   114,
     115,   282,   283,   104,   192,     3,    99,    41,   204,   203,
     184,    45,   208,   114,   115,   327,   108,   127,    41,   112,
      43,    40,   107,   300,   135,    40,    41,    38,    38,    38,
      45,    42,    42,    42,   228,    35,    41,   318,    38,   320,
       3,     3,   323,   154,    42,   130,   161,    38,   163,   198,
     134,    42,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   159,    38,   255,   255,    35,    42,
      41,    38,    43,   165,   268,   159,   272,    17,    41,     1,
      43,    21,    45,   176,    50,    51,     3,     9,    10,    47,
      12,   184,     9,    10,    11,    12,    19,    41,   193,    43,
      22,    48,   192,    43,    49,    22,    41,    42,    43,   193,
     298,    41,    34,    43,   198,    37,    56,    34,    14,   234,
     205,    37,    38,    16,    41,    42,    43,    38,    45,    40,
       3,     4,    15,     6,     7,     8,   247,   248,    41,   229,
       3,   335,   336,   238,    17,    37,    38,    36,   243,    37,
      38,   143,   144,   246,   238,    36,   249,    35,   251,   243,
      33,    40,    35,   255,    23,    40,    35,   300,    41,   264,
      37,    37,    45,   263,    42,   267,    49,    50,    51,   274,
     264,    54,    55,    45,    42,     9,    10,    11,    12,    45,
     274,    35,    35,     3,   289,    36,   288,     3,    22,    41,
      35,    39,    41,    35,    38,   289,    42,    38,   298,    39,
      34,     3,    38,   303,    42,    44,   327,     1,    42,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    40,
      42,    44,    35,    17,    42,   328,    38,    42,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    42,    32,    33,
      34,    35,    36,    37,    31,   348,    42,    41,     3,    44,
      35,    45,    42,    13,   161,    49,    50,    51,   267,   245,
      54,    55,     1,   303,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,   288,   104,   166,   107,    17,     9,
      10,    11,    12,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    22,    32,    33,    34,    35,    36,    37,   134,
     137,   347,    41,   136,    34,    -1,    45,   138,   140,    -1,
      49,    50,    51,   139,   141,    54,    55,     1,   142,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     1,    32,    33,
      34,    35,    36,    -1,    -1,     9,    10,    41,    12,    -1,
      -1,    45,    -1,    -1,    -1,    49,    50,    51,    22,    -1,
      54,    55,     1,    -1,     3,     4,     5,     6,     7,     8,
      34,     1,    -1,    37,    -1,    -1,    -1,    -1,    17,     9,
      10,    -1,    12,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    22,    32,    33,    -1,    35,    36,    -1,    -1,
       9,    10,    41,    12,    34,    -1,    45,    -1,    -1,    -1,
      49,    50,    51,    22,    -1,    54,    55,     3,     4,     1,
       6,     7,     8,     9,    10,    34,    12,     9,    10,    11,
      12,    17,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      -1,    -1,    34,    35,    36,    41,    38,    39,    -1,    45,
      -1,    -1,    -1,    49,    50,    51,    -1,    -1,    54,    55,
       3,     4,    -1,     6,     7,     8,     9,    10,    -1,    12,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    22,
       3,     4,    -1,     6,     7,     8,    -1,    -1,    -1,    -1,
      33,    34,    -1,    -1,    17,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    49,    50,    51,    -1,
      33,    54,    55,    36,    37,    -1,     3,     4,    41,     6,
       7,     8,    45,    -1,    -1,    -1,    49,    50,    51,    -1,
      17,    54,    55,    -1,    -1,     3,     4,    -1,     6,     7,
       8,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    41,    -1,    -1,    44,    45,    -1,
      -1,    -1,    49,    50,    51,    33,    -1,    54,    55,    -1,
      -1,    -1,    -1,    41,    -1,    -1,    44,    45,    -1,    -1,
      -1,    49,    50,    51,    -1,    -1,    54,    55,     3,     4,
       1,     6,     7,     8,    -1,    -1,    -1,    -1,     9,    10,
      11,    12,    17,     3,     4,    -1,     6,     7,     8,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    17,    33,    -1,
      -1,    36,    -1,    34,    -1,    36,    41,    -1,    -1,    -1,
      45,    -1,    -1,    33,    49,    50,    51,    -1,    -1,    54,
      55,    41,    -1,    -1,    44,    45,    -1,    -1,    -1,    49,
      50,    51,    -1,    -1,    54,    55,     3,     4,    -1,     6,
       7,     8,    -1,     3,     4,    -1,     6,     7,     8,    -1,
      17,     9,    10,    11,    12,    -1,    -1,    17,    -1,    -1,
      18,    -1,    -1,    -1,    22,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    41,    -1,    34,    -1,    45,    -1,
      -1,    41,    49,    50,    51,    45,    -1,    54,    55,    49,
      50,    51,    -1,    -1,    54,    55,     3,     4,    -1,     6,
       7,     8,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,
      17,    -1,     9,    10,    11,    12,    -1,    -1,    -1,     1,
      -1,    -1,    -1,    -1,    -1,    22,    33,     9,    10,    11,
      12,    -1,    -1,    -1,    41,    -1,    -1,    34,    45,    36,
      22,    -1,    49,    50,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    34,    -1,    36,    -1,    -1,    -1,    40,    41,
      -1,    43,     9,    10,    11,    12,    -1,    -1,     1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    22,
      -1,    -1,    -1,    -1,    41,    42,    43,    -1,    45,    -1,
      -1,    34,    -1,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    58,     0,    59,     1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    17,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    32,    33,    34,    35,    36,
      41,    45,    49,    50,    51,    54,    55,    60,    61,    62,
      67,    69,    71,    72,    82,    85,    86,    94,   105,   106,
     107,   108,   113,   115,   117,   118,   119,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   137,   138,   143,    35,    40,    87,    35,    69,
      70,    70,     3,    36,     3,    41,    45,   133,     3,    36,
      41,     1,     3,    41,   105,    41,    41,   121,   133,    40,
      35,   118,    41,     3,    41,   133,    67,    68,    69,   105,
     109,   111,   112,     3,    10,    71,    79,    85,   102,   118,
      95,     3,    35,    41,    45,    74,    76,    85,     1,    66,
      68,    86,    35,    38,    20,    46,    19,    47,    48,    49,
      14,    15,    16,    50,    51,    45,    52,    53,    13,    39,
     120,   132,    17,    21,    43,    56,   136,   105,    41,    43,
      88,    36,     1,    73,    78,    79,    36,     3,    83,    84,
     118,    35,    23,   116,   118,   118,    40,   105,    35,   118,
      35,   102,    67,   110,   112,    85,    37,    37,   105,   109,
      79,    79,    41,    43,    94,   103,   104,    42,    42,    42,
      94,    35,    75,    39,    65,    68,    35,   108,    64,   119,
     123,   118,   124,   125,   126,   127,   128,   129,   130,   131,
     131,   132,   132,   132,   119,     3,   118,     3,    41,    91,
      92,    93,    44,   121,    73,    35,    37,    78,    40,    80,
      81,    85,    83,    39,    37,    38,    42,    41,    35,    42,
     105,    42,    42,   109,    42,    69,    96,    97,    98,   103,
      44,   121,   104,    41,    43,    88,   132,    38,    36,   100,
     119,   108,    63,   108,    40,    44,   119,   139,   140,    96,
       3,    99,    42,    90,    44,    37,   121,    35,    38,    40,
      37,   121,    84,   105,   118,   116,   105,   105,    41,    85,
      94,   103,    42,    38,    42,    44,    42,    96,    44,   121,
      76,   100,   101,    77,   108,   121,   141,    42,    42,    38,
      42,    88,    88,    89,    81,   121,    42,    35,    31,   114,
      18,    98,    42,    44,    37,    38,    38,   142,    88,     3,
      88,    88,    35,   116,   105,    37,   100,   119,    42,   142,
     105
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
#line 73 "../src/TP5.y"
    {tipo_declaracion = 0;;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 81 "../src/TP5.y"
    {tipo_declaracion = 0;;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 82 "../src/TP5.y"
    {tipo_declaracion = 0;;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 83 "../src/TP5.y"
    {
                                declararParametros(&listaTS);
                                //if(listaTS->sgte)
                                        if(validarDeclaracionNEW(&listaTS, nombre_ppal, yylineno)){
                                                if(definido(&listaTS, nombre_ppal)) {
                                                        insertarError(&listaErrores, "Funcion ya definida: ", nombre_ppal, 'S', yylineno);
                                                }else{

                                                        definir(&listaTS, nombre_ppal);
                                                }
                                        }else if(definido(&listaTS, nombre_ppal)){
                                                insertarError(&listaErrores, "Funcion ya definida: ", nombre_ppal, 'S', yylineno);
                                        }
                                tipo_declaracion = 0;
                                dimensiones=0;
                        ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 99 "../src/TP5.y"
    {tipo_declaracion = 0;;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 101 "../src/TP5.y"
    {
                                //if(listaTS->sgte)
                                        validarDeclaracionNEW(&listaTS, nombre_ppal, yylineno);
                                dimensiones=0;
                ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 107 "../src/TP5.y"
    {yyerrok;;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 119 "../src/TP5.y"
    {tipo = strdup((yyvsp[(1) - (1)].myStruct).tipo);;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 132 "../src/TP5.y"
    {tipo_declaracion = 2;;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 132 "../src/TP5.y"
    {tipo_declaracion = 0;;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 134 "../src/TP5.y"
    {es_puntero=0;;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 135 "../src/TP5.y"
    {
                        if(!es_puntero){
                                if(strcmp((yyvsp[(1) - (3)].myStruct).tipo, (yyvsp[(3) - (3)].myStruct).tipo)){
                                                insertarError(&listaErrores, "Asignacion de distinto tipo a: ",(yyvsp[(1) - (3)].myStruct).identificador, 'S', yylineno);
                        }
                        }
                        
                  ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 143 "../src/TP5.y"
    {
                        if(es_puntero && !hay_llaves){
                                insertarError(&listaErrores, "syntax error - Inicializacion de array incorrecta", "", 'Z', yylineno);
                  }
                  es_puntero=0;
                        ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 151 "../src/TP5.y"
    {yyerrok;;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 178 "../src/TP5.y"
    { 
                                {(yyval.myStruct).tipo = tipo;}
                                identificador = strdup((yyvsp[(1) - (1)].myStruct).identificador);
                                if(tipo_declaracion == 0){nombre_ppal = strdup(identificador); insertarTipo_ts(&listaTS, tipo, identificador, dimensiones);}
                                if(tipo_declaracion == 1){insertarListaParametros_ts(listaTS, tipo, identificador, dimensiones); dimensiones=0;}
                                if(tipo_declaracion == 2) {insertarIDHermano_ts(&listaTS, identificador, dimensiones);  validarDeclaracionNEW(&listaTS, identificador, yylineno);}
                                ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 184 "../src/TP5.y"
    {
                                if(tipo_declaracion == 1){
                                        insertarVoF_ts(&listaTS, 'F');
                                }

                                insertarDimensionTS(listaTS, cant_corchetes);

                                if(dimensiones || cant_corchetes){
                                        es_puntero=1;
                                        dimensiones=0;
                                        cant_corchetes=0;
                                }
                                
                        
                        ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 201 "../src/TP5.y"
    {cant_corchetes++;;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 202 "../src/TP5.y"
    {cant_corchetes++;;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 203 "../src/TP5.y"
    {tipo_declaracion = 1; dimensiones=0; ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 204 "../src/TP5.y"
    {tipo_declaracion = 1;dimensiones=0; ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 205 "../src/TP5.y"
    {tipo_declaracion = 1;dimensiones=0; ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 208 "../src/TP5.y"
    {dimensiones++;;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 209 "../src/TP5.y"
    {dimensiones++;;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 218 "../src/TP5.y"
    {insertarListaParametros_ts(listaTS, tipo, "", dimensiones); dimensiones=0;;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 219 "../src/TP5.y"
    {insertarListaParametros_ts(listaTS, tipo, "", dimensiones); dimensiones=0;;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 221 "../src/TP5.y"
    {identificador = strdup((yyvsp[(1) - (1)].myStruct).identificador);;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 222 "../src/TP5.y"
    {identificador = strdup((yyvsp[(3) - (3)].myStruct).identificador);;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 224 "../src/TP5.y"
    {cantidad_valores++;{(yyval.myStruct).tipo = strdup((yyvsp[(1) - (1)].myStruct).tipo);};}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 225 "../src/TP5.y"
    {hay_llaves++;;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 226 "../src/TP5.y"
    {hay_llaves++;;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 254 "../src/TP5.y"
    {yyerrok;;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 299 "../src/TP5.y"
    {(yyval.myStruct).tipo = strdup((yyvsp[(1) - (1)].myStruct).tipo);;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 300 "../src/TP5.y"
    {
                                       
                                        if((yyvsp[(1) - (3)].myStruct).funcion!='V'){
                                                insertarError(&listaErrores, "syntax error - ValorL no modificable", "", 'Z', yylineno);
                                        }else if(strcmp((yyvsp[(1) - (3)].myStruct).tipo, (yyvsp[(3) - (3)].myStruct).tipo)){
                                                insertarError(&listaErrores, "Asignacion de distinto tipo a: ",(yyvsp[(1) - (3)].myStruct).identificador, 'S', yylineno);
                                        }
                                ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 312 "../src/TP5.y"
    {(yyval.myStruct).tipo = strdup((yyvsp[(1) - (1)].myStruct).tipo);(yyval.myStruct).funcion=(yyvsp[(1) - (1)].myStruct).funcion;;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 315 "../src/TP5.y"
    {(yyval.myStruct).tipo = strdup((yyvsp[(1) - (1)].myStruct).tipo);(yyval.myStruct).funcion=(yyvsp[(1) - (1)].myStruct).funcion;;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 318 "../src/TP5.y"
    {(yyval.myStruct).tipo = strdup((yyvsp[(1) - (1)].myStruct).tipo);(yyval.myStruct).funcion=(yyvsp[(1) - (1)].myStruct).funcion;;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 321 "../src/TP5.y"
    {(yyval.myStruct).tipo = strdup((yyvsp[(1) - (1)].myStruct).tipo);(yyval.myStruct).funcion=(yyvsp[(1) - (1)].myStruct).funcion;;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 324 "../src/TP5.y"
    {(yyval.myStruct).tipo = strdup((yyvsp[(1) - (1)].myStruct).tipo);(yyval.myStruct).funcion=(yyvsp[(1) - (1)].myStruct).funcion;;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 327 "../src/TP5.y"
    {(yyval.myStruct).tipo = strdup((yyvsp[(1) - (1)].myStruct).tipo);(yyval.myStruct).funcion=(yyvsp[(1) - (1)].myStruct).funcion;;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 330 "../src/TP5.y"
    {(yyval.myStruct).tipo = strdup((yyvsp[(1) - (1)].myStruct).tipo);(yyval.myStruct).funcion=(yyvsp[(1) - (1)].myStruct).funcion;;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 333 "../src/TP5.y"
    {(yyval.myStruct).tipo = strdup((yyvsp[(1) - (1)].myStruct).tipo);(yyval.myStruct).funcion=(yyvsp[(1) - (1)].myStruct).funcion;;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 336 "../src/TP5.y"
    {(yyval.myStruct).tipo = strdup((yyvsp[(1) - (1)].myStruct).tipo);(yyval.myStruct).funcion=(yyvsp[(1) - (1)].myStruct).funcion;;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 339 "../src/TP5.y"
    {(yyval.myStruct).tipo = strdup((yyvsp[(1) - (1)].myStruct).tipo);(yyval.myStruct).funcion=(yyvsp[(1) - (1)].myStruct).funcion;;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 340 "../src/TP5.y"
    {
                                (yyval.myStruct).funcion='C';
                                if(validarOperacionBinaria(&listaTS, (yyvsp[(1) - (3)].myStruct).tipo, (yyvsp[(3) - (3)].myStruct).tipo) == 1){
                                        (yyval.myStruct).tipo = strdup((yyvsp[(1) - (3)].myStruct).tipo);
                                        (yyval.myStruct).real = (yyvsp[(1) - (3)].myStruct).real+(yyvsp[(3) - (3)].myStruct).real;
                                }
                                else if(validarOperacionBinaria(&listaTS, (yyvsp[(1) - (3)].myStruct).tipo, (yyvsp[(3) - (3)].myStruct).tipo) == 0){
                                        (yyval.myStruct).tipo = "float";
                                        insertarError(&listaErrores, "Operandos de distinto tipo", "", 'S', yylineno);
                                        (yyval.myStruct).real = (yyvsp[(1) - (3)].myStruct).real+(yyvsp[(3) - (3)].myStruct).real;
                                }
                                else{
                                        (yyval.myStruct).tipo = "NULL";
                                        insertarError(&listaErrores, "Operandos no pueden sumarse", "", 'S', yylineno);
                                };}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 355 "../src/TP5.y"
    {
                                (yyval.myStruct).funcion='C';
                                if(validarOperacionBinaria(&listaTS, (yyvsp[(1) - (3)].myStruct).tipo, (yyvsp[(3) - (3)].myStruct).tipo) == 1){
                                        (yyval.myStruct).tipo = strdup((yyvsp[(1) - (3)].myStruct).tipo);
                                        (yyval.myStruct).real = (yyvsp[(1) - (3)].myStruct).real-(yyvsp[(3) - (3)].myStruct).real;
                                }
                                else if(validarOperacionBinaria(&listaTS, (yyvsp[(1) - (3)].myStruct).tipo, (yyvsp[(3) - (3)].myStruct).tipo) == 0){
                                        (yyval.myStruct).tipo = "float";
                                        insertarError(&listaErrores, "Operandos de distinto tipo", "", 'S', yylineno);
                                        (yyval.myStruct).real = (yyvsp[(1) - (3)].myStruct).real-(yyvsp[(3) - (3)].myStruct).real;
                                }
                                else{
                                        (yyval.myStruct).tipo = "NULL";
                                        insertarError(&listaErrores, "Operandos no pueden restarse", "", 'S', yylineno);
                                };}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 371 "../src/TP5.y"
    {(yyval.myStruct).tipo = strdup((yyvsp[(1) - (1)].myStruct).tipo);(yyval.myStruct).funcion=(yyvsp[(1) - (1)].myStruct).funcion;;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 372 "../src/TP5.y"
    {
                                        (yyval.myStruct).funcion='C';
                                        if(validarOperacionBinaria(&listaTS, (yyvsp[(1) - (3)].myStruct).tipo, (yyvsp[(3) - (3)].myStruct).tipo) == 1){
                                                (yyval.myStruct).tipo = strdup((yyvsp[(1) - (3)].myStruct).tipo);
                                                (yyval.myStruct).real = (yyvsp[(1) - (3)].myStruct).real*(yyvsp[(3) - (3)].myStruct).real;
                                        }
                                        else if(validarOperacionBinaria(&listaTS, (yyvsp[(1) - (3)].myStruct).tipo, (yyvsp[(3) - (3)].myStruct).tipo) == 0){
                                                (yyval.myStruct).tipo = "float";
                                                insertarError(&listaErrores, "Operandos de distinto tipo", "", 'S', yylineno);
                                                (yyval.myStruct).real = (yyvsp[(1) - (3)].myStruct).real*(yyvsp[(3) - (3)].myStruct).real;
                                        }
                                        else{
                                                (yyval.myStruct).tipo = "NULL";
                                                insertarError(&listaErrores, "Operandos no pueden multiplicarse", "", 'S', yylineno);
                                        };}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 387 "../src/TP5.y"
    {
                                        (yyval.myStruct).funcion='C';
                                        if(validarOperacionBinaria(&listaTS, (yyvsp[(1) - (3)].myStruct).tipo, (yyvsp[(3) - (3)].myStruct).tipo) == 1){
                                                (yyval.myStruct).tipo = strdup((yyvsp[(1) - (3)].myStruct).tipo);
                                                if((yyvsp[(3) - (3)].myStruct).real == 0){
                                                        insertarError(&listaErrores, "NUNCA DIVIDAS POR 0 - Asignamos 0 mientras tanto :P", "", 'S', yylineno);
                                                        (yyval.myStruct).real = 0;
                                                }else{
                                                        (yyval.myStruct).real =(yyvsp[(1) - (3)].myStruct).real/(yyvsp[(3) - (3)].myStruct).real;
                                                }
                                        }
                                        else if(validarOperacionBinaria(&listaTS, (yyvsp[(1) - (3)].myStruct).tipo, (yyvsp[(3) - (3)].myStruct).tipo) == 0){
                                                if((yyvsp[(3) - (3)].myStruct).real == 0){
                                                        insertarError(&listaErrores, "NUNCA DIVIDAS POR 0 - Asignamos 0 mientras tanto :P", "", 'S', yylineno);
                                                        (yyval.myStruct).real = 0;
                                                }else{
                                                        (yyval.myStruct).real =(yyvsp[(1) - (3)].myStruct).real/(yyvsp[(3) - (3)].myStruct).real;
                                                }
                                                (yyval.myStruct).tipo = "float";
                                                insertarError(&listaErrores, "Operandos de distinto tipo", "", 'S', yylineno);
                                        }
                                        else{
                                                (yyval.myStruct).tipo = "NULL";
                                                insertarError(&listaErrores, "Operandos no pueden dividirse", "", 'S', yylineno);
                                };}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 414 "../src/TP5.y"
    {(yyval.myStruct).tipo = strdup((yyvsp[(1) - (1)].myStruct).tipo);(yyval.myStruct).real =(yyvsp[(1) - (1)].myStruct).real;(yyval.myStruct).funcion=(yyvsp[(1) - (1)].myStruct).funcion;;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 417 "../src/TP5.y"
    {(yyval.myStruct).tipo = strdup((yyvsp[(1) - (1)].myStruct).tipo);(yyval.myStruct).identificador = strdup((yyvsp[(1) - (1)].myStruct).identificador);(yyval.myStruct).real =(yyvsp[(1) - (1)].myStruct).real;(yyval.myStruct).funcion=(yyvsp[(1) - (1)].myStruct).funcion;;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 430 "../src/TP5.y"
    {
                        (yyval.myStruct).funcion=(yyvsp[(1) - (1)].myStruct).funcion;
                        (yyval.myStruct).real =(yyvsp[(1) - (1)].myStruct).real;
                        (yyval.myStruct).identificador = strdup((yyvsp[(1) - (1)].myStruct).identificador);
                        if((yyvsp[(1) - (1)].myStruct).funcion =='F'){
                                (yyval.myStruct).tipo = "NULL";
                                insertarError(&listaErrores, "Funcion utilizada como variable: ", identificador,'S', yylineno);
                        }else{
                                (yyval.myStruct).tipo = strdup((yyvsp[(1) - (1)].myStruct).tipo);
                        };}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 441 "../src/TP5.y"
    {
                                contador_parametros=0;
                                (yyval.myStruct).identificador = strdup((yyvsp[(1) - (1)].myStruct).identificador);
                                if((yyvsp[(1) - (1)].myStruct).funcion=='F'){
                                        (yyval.myStruct).tipo = strdup((yyvsp[(1) - (1)].myStruct).tipo);
                                }else{
                                        (yyval.myStruct).tipo = "NULL";
                                        insertarError(&listaErrores, "Variable utilizada como funcion: ", identificador,'S', yylineno);
                        };}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 449 "../src/TP5.y"
    {
                                if((yyvsp[(1) - (5)].myStruct).funcion=='F'){
                                        if(cantParams(&listaTS, nombreFuncion) != contador_parametros){
                                                insertarError(&listaErrores, "Cantidad de Parametros Erronea de: ", nombreFuncion,'S', yylineno);
                                        }
                                }
                        ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 460 "../src/TP5.y"
    {(yyval.myStruct).funcion = (yyvsp[(1) - (1)].myStruct).funcion;;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 461 "../src/TP5.y"
    {
                                (yyval.myStruct).real = (yyvsp[(1) - (1)].myStruct).real;
                                (yyval.myStruct).tipo = strdup((yyvsp[(1) - (1)].myStruct).tipo);
                                (yyval.myStruct).funcion = 'C';
                        ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 466 "../src/TP5.y"
    {
                                (yyval.myStruct).tipo = strdup((yyvsp[(1) - (1)].myStruct).tipo);
                                (yyval.myStruct).funcion = 'C';
                        ;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 470 "../src/TP5.y"
    {
                                (yyval.myStruct).real =(yyvsp[(2) - (3)].myStruct).real;
                                (yyval.myStruct).tipo = strdup((yyvsp[(2) - (3)].myStruct).tipo);
                                (yyval.myStruct).funcion = 'C';
                        ;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 476 "../src/TP5.y"
    {
        identificador = strdup((yyvsp[(1) - (1)].myStruct).identificador);
        if(validarDeclaracion(&listaTS, identificador) == 0){
                insertarError(&listaErrores, "Variable no declarada ", identificador,'S', yylineno);
                (yyval.myStruct).funcion =  'N';
                (yyval.myStruct).tipo = "NULL";
        }else{
                if(esFuncion(&listaTS, (yyvsp[(1) - (1)].myStruct).identificador)){
                        (yyval.myStruct).funcion =  'F';
                        invocar(&listaTS, identificador);
                        nombreFuncion=identificador;
                }else
                        (yyval.myStruct).funcion =  'V';
                
                (yyval.myStruct).tipo = devolverTipo(&listaTS, identificador);
        };}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 496 "../src/TP5.y"
    {contador_parametros++;
        if(tipoCorrecto(nombreFuncion,contador_parametros,(yyvsp[(1) - (1)].myStruct).tipo,&listaTS)!=1){
                auxiliar = strdup("Parametro N ");
                auxiliar = stringConcatenate(auxiliar, intToString(contador_parametros));
                auxiliar = stringConcatenate(auxiliar,  " es de tipo erroneo en invocacion de: ");
                insertarError(&listaErrores, auxiliar, nombreFuncion, 'S', yylineno);
        };}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 504 "../src/TP5.y"
    {contador_parametros++;
                if(tipoCorrecto(nombreFuncion, contador_parametros, (yyvsp[(1) - (3)].myStruct).tipo, &listaTS) != 1){
                        auxiliar = strdup("Parametro N ");
                        auxiliar = stringConcatenate(auxiliar, intToString(contador_parametros));
                        auxiliar = stringConcatenate(auxiliar, " es de tipo erroneo en invocacion de: ");
                        insertarError(&listaErrores, auxiliar, nombreFuncion, 'S', yylineno); 
                }
        ;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 515 "../src/TP5.y"
    {
                        (yyval.myStruct).tipo = strdup((yyvsp[(1) - (1)].myStruct).tipo);
                        (yyval.myStruct).real = (yyvsp[(1) - (1)].myStruct).entero;
                ;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 519 "../src/TP5.y"
    {
                        (yyval.myStruct).tipo = strdup((yyvsp[(1) - (1)].myStruct).tipo);
                        (yyval.myStruct).real = (yyvsp[(1) - (1)].myStruct).simbolo;
                ;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 523 "../src/TP5.y"
    {
                        (yyval.myStruct).tipo = strdup((yyvsp[(1) - (1)].myStruct).tipo);
                        (yyval.myStruct).real = (yyvsp[(1) - (1)].myStruct).real;
                ;}
    break;



/* Line 1455 of yacc.c  */
#line 2511 "TP5.tab.c"
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
#line 528 "../src/TP5.y"

void main (int argc, char *argv[]){
        salvavidas = 0;
        yyin = fopen(argv[1], "r");
        yydebug = 0;
        yyparse ();
        fclose(yyin);
        validarInvocaciones(&listaTS);
        mostrarTS(listaTS);
        mostrarErrores(listaErrores);
}
