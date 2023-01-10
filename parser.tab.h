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
    CHAR = 263,                    /* CHAR  */
    DPLUS = 264,                   /* DPLUS  */
    GE = 265,                      /* GE  */
    GT = 266,                      /* GT  */
    LE = 267,                      /* LE  */
    LP = 268,                      /* LP  */
    LT = 269,                      /* LT  */
    NE = 270,                      /* NE  */
    RP = 271,                      /* RP  */
    LB = 272,                      /* LB  */
    RB = 273,                      /* RB  */
    LC = 274,                      /* LC  */
    RC = 275,                      /* RC  */
    SEMI = 276,                    /* SEMI  */
    COMMA = 277,                   /* COMMA  */
    PLUS = 278,                    /* PLUS  */
    MINUS = 279,                   /* MINUS  */
    STAR = 280,                    /* STAR  */
    DIV = 281,                     /* DIV  */
    ASSIGNOP = 282,                /* ASSIGNOP  */
    AND = 283,                     /* AND  */
    OR = 284,                      /* OR  */
    NOT = 285,                     /* NOT  */
    IF = 286,                      /* IF  */
    ELSE = 287,                    /* ELSE  */
    WHILE = 288,                   /* WHILE  */
    RETURN = 289,                  /* RETURN  */
    STRUCT = 290,                  /* STRUCT  */
    FOR = 291,                     /* FOR  */
    SWITCH = 292,                  /* SWITCH  */
    CASE = 293,                    /* CASE  */
    COLON = 294,                   /* COLON  */
    DEFAULT = 295,                 /* DEFAULT  */
    EXT_DEF_LIST = 296,            /* EXT_DEF_LIST  */
    EXT_VAR_DEF = 297,             /* EXT_VAR_DEF  */
    FUNC_DEF = 298,                /* FUNC_DEF  */
    FUNC_DEC = 299,                /* FUNC_DEC  */
    EXT_DEC_LIST = 300,            /* EXT_DEC_LIST  */
    PARAM_LIST = 301,              /* PARAM_LIST  */
    PARAM_DEC = 302,               /* PARAM_DEC  */
    VAR_DEF = 303,                 /* VAR_DEF  */
    DEC_LIST = 304,                /* DEC_LIST  */
    DEF_LIST = 305,                /* DEF_LIST  */
    COMP_STM = 306,                /* COMP_STM  */
    STM_LIST = 307,                /* STM_LIST  */
    EXP_STMT = 308,                /* EXP_STMT  */
    IF_THEN = 309,                 /* IF_THEN  */
    IF_THEN_ELSE = 310,            /* IF_THEN_ELSE  */
    FUNC_CALL = 311,               /* FUNC_CALL  */
    ARGS = 312,                    /* ARGS  */
    FUNCTION = 313,                /* FUNCTION  */
    PARAM = 314,                   /* PARAM  */
    ARG = 315,                     /* ARG  */
    CALL = 316,                    /* CALL  */
    LABEL = 317,                   /* LABEL  */
    GOTO = 318,                    /* GOTO  */
    JLT = 319,                     /* JLT  */
    JLE = 320,                     /* JLE  */
    JGT = 321,                     /* JGT  */
    JGE = 322,                     /* JGE  */
    EQ = 323,                      /* EQ  */
    NEQ = 324,                     /* NEQ  */
    UMINUS = 325,                  /* UMINUS  */
    LOWER_THEN_ELSE = 326          /* LOWER_THEN_ELSE  */
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
        char   type_char;
	char   type_id[32];
	struct ASTNode *ptr;

#line 143 "parser.tab.h"

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
