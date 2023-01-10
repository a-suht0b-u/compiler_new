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
    DMINUS = 265,                  /* DMINUS  */
    GE = 266,                      /* GE  */
    GT = 267,                      /* GT  */
    LE = 268,                      /* LE  */
    LP = 269,                      /* LP  */
    LT = 270,                      /* LT  */
    NE = 271,                      /* NE  */
    RP = 272,                      /* RP  */
    LB = 273,                      /* LB  */
    RB = 274,                      /* RB  */
    LC = 275,                      /* LC  */
    RC = 276,                      /* RC  */
    SEMI = 277,                    /* SEMI  */
    COMMA = 278,                   /* COMMA  */
    PLUS = 279,                    /* PLUS  */
    MINUS = 280,                   /* MINUS  */
    STAR = 281,                    /* STAR  */
    DIV = 282,                     /* DIV  */
    ASSIGNOP = 283,                /* ASSIGNOP  */
    AND = 284,                     /* AND  */
    OR = 285,                      /* OR  */
    NOT = 286,                     /* NOT  */
    IF = 287,                      /* IF  */
    ELSE = 288,                    /* ELSE  */
    WHILE = 289,                   /* WHILE  */
    RETURN = 290,                  /* RETURN  */
    STRUCT = 291,                  /* STRUCT  */
    FOR = 292,                     /* FOR  */
    SWITCH = 293,                  /* SWITCH  */
    CASE = 294,                    /* CASE  */
    COLON = 295,                   /* COLON  */
    DEFAULT = 296,                 /* DEFAULT  */
    BREAK = 297,                   /* BREAK  */
    CONTINUE = 298,                /* CONTINUE  */
    INCREASE = 299,                /* INCREASE  */
    DECREASE = 300,                /* DECREASE  */
    EXT_DEF_LIST = 301,            /* EXT_DEF_LIST  */
    EXT_VAR_DEF = 302,             /* EXT_VAR_DEF  */
    FUNC_DEF = 303,                /* FUNC_DEF  */
    FUNC_DEC = 304,                /* FUNC_DEC  */
    EXT_DEC_LIST = 305,            /* EXT_DEC_LIST  */
    PARAM_LIST = 306,              /* PARAM_LIST  */
    PARAM_DEC = 307,               /* PARAM_DEC  */
    VAR_DEF = 308,                 /* VAR_DEF  */
    DEC_LIST = 309,                /* DEC_LIST  */
    DEF_LIST = 310,                /* DEF_LIST  */
    COMP_STM = 311,                /* COMP_STM  */
    STM_LIST = 312,                /* STM_LIST  */
    EXP_STMT = 313,                /* EXP_STMT  */
    IF_THEN = 314,                 /* IF_THEN  */
    IF_THEN_ELSE = 315,            /* IF_THEN_ELSE  */
    DPLUS_PREFIX = 316,            /* DPLUS_PREFIX  */
    DPLUS_POSTFIX = 317,           /* DPLUS_POSTFIX  */
    DMINUS_PREFIX = 318,           /* DMINUS_PREFIX  */
    DMINUS_POSTFIX = 319,          /* DMINUS_POSTFIX  */
    ARRAY = 320,                   /* ARRAY  */
    ARRAY_LIST = 321,              /* ARRAY_LIST  */
    FUNC_CALL = 322,               /* FUNC_CALL  */
    ARGS = 323,                    /* ARGS  */
    FUNCTION = 324,                /* FUNCTION  */
    PARAM = 325,                   /* PARAM  */
    ARG = 326,                     /* ARG  */
    CALL = 327,                    /* CALL  */
    LABEL = 328,                   /* LABEL  */
    GOTO = 329,                    /* GOTO  */
    JLT = 330,                     /* JLT  */
    JLE = 331,                     /* JLE  */
    JGT = 332,                     /* JGT  */
    JGE = 333,                     /* JGE  */
    EQ = 334,                      /* EQ  */
    NEQ = 335,                     /* NEQ  */
    UMINUS = 336,                  /* UMINUS  */
    LOWER_THEN_ELSE = 337          /* LOWER_THEN_ELSE  */
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

#line 154 "parser.tab.h"

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
