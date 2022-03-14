
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
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



/* Line 1676 of yacc.c  */
#line 100 "TP5.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


