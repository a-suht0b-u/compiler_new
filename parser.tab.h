/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    ID = 259,                      /* ID  */
    RELOP = 260,                   /* RELOP  */
    TYPE = 261,                    /* TYPE  */
    FLOAT = 262,                   /* FLOAT  */
    DPLUS = 263,                   /* DPLUS  */
    GE = 264,                      /* GE  */
    GT = 265,                      /* GT  */
    LE = 266,                      /* LE  */
    LP = 267,                      /* LP  */
    LT = 268,                      /* LT  */
    NE = 269,                      /* NE  */
    RP = 270,                      /* RP  */
    LB = 271,                      /* LB  */
    RB = 272,                      /* RB  */
    LC = 273,                      /* LC  */
    RC = 274,                      /* RC  */
    SEMI = 275,                    /* SEMI  */
    COMMA = 276,                   /* COMMA  */
    PLUS = 277,                    /* PLUS  */
    MINUS = 278,                   /* MINUS  */
    STAR = 279,                    /* STAR  */
    DIV = 280,                     /* DIV  */
    ASSIGNOP = 281,                /* ASSIGNOP  */
    AND = 282,                     /* AND  */
    OR = 283,                      /* OR  */
    NOT = 284,                     /* NOT  */
    IF = 285,                      /* IF  */
    ELSE = 286,                    /* ELSE  */
    WHILE = 287,                   /* WHILE  */
    RETURN = 288,                  /* RETURN  */
    STRUCT = 289,                  /* STRUCT  */
    FOR = 290,                     /* FOR  */
    SWITCH = 291,                  /* SWITCH  */
    CASE = 292,                    /* CASE  */
    COLON = 293,                   /* COLON  */
    DEFAULT = 294,                 /* DEFAULT  */
    EXT_DEF_LIST = 295,            /* EXT_DEF_LIST  */
    EXT_VAR_DEF = 296,             /* EXT_VAR_DEF  */
    FUNC_DEF = 297,                /* FUNC_DEF  */
    FUNC_DEC = 298,                /* FUNC_DEC  */
    EXT_DEC_LIST = 299,            /* EXT_DEC_LIST  */
    PARAM_LIST = 300,              /* PARAM_LIST  */
    PARAM_DEC = 301,               /* PARAM_DEC  */
    VAR_DEF = 302,                 /* VAR_DEF  */
    DEC_LIST = 303,                /* DEC_LIST  */
    DEF_LIST = 304,                /* DEF_LIST  */
    COMP_STM = 305,                /* COMP_STM  */
    STM_LIST = 306,                /* STM_LIST  */
    EXP_STMT = 307,                /* EXP_STMT  */
    IF_THEN = 308,                 /* IF_THEN  */
    IF_THEN_ELSE = 309,            /* IF_THEN_ELSE  */
    FUNC_CALL = 310,               /* FUNC_CALL  */
    ARGS = 311,                    /* ARGS  */
    FUNCTION = 312,                /* FUNCTION  */
    PARAM = 313,                   /* PARAM  */
    ARG = 314,                     /* ARG  */
    CALL = 315,                    /* CALL  */
    LABEL = 316,                   /* LABEL  */
    GOTO = 317,                    /* GOTO  */
    JLT = 318,                     /* JLT  */
    JLE = 319,                     /* JLE  */
    JGT = 320,                     /* JGT  */
    JGE = 321,                     /* JGE  */
    EQ = 322,                      /* EQ  */
    NEQ = 323,                     /* NEQ  */
    UMINUS = 324,                  /* UMINUS  */
    LOWER_THEN_ELSE = 325          /* LOWER_THEN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "parser.y"

	int    type_int;
	float  type_float;
	char   type_id[32];
	struct ASTNode *ptr;

#line 141 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
