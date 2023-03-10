#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "def.h"
#include "parser.tab.h"

void display(struct ASTNode *T, int indent)
{ // 对抽象语法树的先根遍历
    int i = 1;
    struct ASTNode *T0;
    if (T)
    {
        switch (T->kind)
        {
        case EXT_DEF_LIST:
            display(T->Def, indent + 3);     // 显示该外部定义（外部变量和函数）列表中的第一个
            display(T->DefList, indent + 3); // 显示该外部定义列表中的其它外部定义
            break;
        case EXT_VAR_DEF:
            printf("%*c外部变量定义：(%d)\n", indent, ' ', T->pos);
            display(T->Specifier, indent + 3); // 显示外部变量类型
            printf("%*c变量名：\n", indent + 3, ' ');
            display(T->DecList, indent + 6); // 显示变量列表
            break;
        case TYPE:
            printf("%*c类型： %s\n", indent, ' ', T->type_id);
            break;
        case EXT_DEC_LIST:
            display(T->Dec, indent);     // 依次显示外部变量名，
            display(T->DecList, indent); // 后续还有相同的，仅显示语法树此处理代码可以和类似代码合并
            break;
        case FUNC_DEF:
            printf("%*c函数定义：(%d)\n", indent, ' ', T->pos);
            display(T->Specifier, indent + 3); // 显示函数返回类型
            display(T->FuncDec, indent + 3);   // 显示函数名和参数
            display(T->Body, indent + 3);      // 显示函数体
            break;
        case FUNC_DEC:
            printf("%*c函数名：%s\n", indent, ' ', T->type_id);
            if (T->ParamList)
            {
                printf("%*c函数形参：\n", indent, ' ');
                display(T->ParamList, indent + 3); // 显示函数参数列表
            }
            else
                printf("%*c无参函数\n", indent + 3, ' ');
            break;
        case PARAM_LIST:
            display(T->Param, indent); // 依次显示全部参数类型和名称，
            display(T->ParamList, indent);
            break;
        case PARAM_DEC:
        {
            char *ckind;
            switch (T->Specifier->type)
            {
            case INT:
                ckind = "int";
                break;
            case FLOAT:
                ckind = "float";
                break;
            case CHAR:
                ckind = "char"; // 增加了 char
                break;
            default:
                break;
            }
            printf("%*c类型：%s, 参数名：%s\n", indent, ' ', ckind, T->ID->type_id);
            break;
        }
        case EXP_STMT:
            printf("%*c表达式语句：(%d)\n", indent, ' ', T->pos);
            display(T->Exp1, indent + 3);
            break;
        case RETURN:
            printf("%*c返回语句：(%d)\n", indent, ' ', T->pos);
            display(T->Exp1, indent + 3);
            break;
        case COMP_STM:
            printf("%*c复合语句：(%d)\n", indent, ' ', T->pos);
            if (T->DefList)
            {
                printf("%*c复合语句的变量定义部分：\n", indent + 3, ' ');
                display(T->DefList, indent + 6); // 显示定义部分
            }
            if (T->StmList)
            {
                printf("%*c复合语句的语句部分：\n", indent + 3, ' ');
                display(T->StmList, indent + 6); // 显示语句部分
            }
            break;
        case STM_LIST:
            display(T->Stm, indent);     // 显示第一条语句
            display(T->StmList, indent); // 显示剩下语句
            break;
        case WHILE:
            printf("%*cWHILE循环语句：(%d)\n", indent, ' ', T->pos);
            printf("%*c循环条件：\n", indent + 3, ' ');
            display(T->Cond, indent + 6); // 显示循环条件
            printf("%*c循环体：(%d)\n", indent + 3, ' ', T->pos);
            display(T->Body, indent + 6); // 显示循环体
            break;
        case FOR:
            printf("%*cFOR循环语句：(%d)\n", indent, ' ', T->pos);
            printf("%*c循环变量定义：\n", indent + 3, ' ');
            display(T->Def, indent + 6); // 显示变量声名赋值
            printf("%*c循环条件：\n", indent + 3, ' ');
            display(T->Exp2, indent + 6); // 显示循环条件
            printf("%*c更新语句：\n", indent + 3, ' ');
            display(T->Exp3, indent + 6); // 显示更新语句
            printf("%*c循环体：(%d)\n", indent + 3, ' ', T->pos);
            display(T->Body, indent + 6); // 显示循环体
            break;
        case BREAK:
            printf("%*cbreak中断返回语句(%d)\n", indent, ' ', T->pos);
            break;
        case CONTINUE:
            printf("%*cCONTINUE跳出继续循环语句(%d)\n", indent, ' ', T->pos);
            break;
        case IF_THEN:
            printf("%*c条件语句(IF_THEN)：(%d)\n", indent, ' ', T->pos);
            printf("%*c条件：\n", indent + 3, ' ');
            display(T->Cond, indent + 6); // 显示条件
            printf("%*cIF子句：(%d)\n", indent + 3, ' ', T->pos);
            display(T->IfStm, indent + 6); // 显示if子句
            break;
        case IF_THEN_ELSE:
            printf("%*c条件语句(IF_THEN_ELSE)：(%d)\n", indent, ' ', T->pos);
            printf("%*c条件：\n", indent + 3, ' ');
            display(T->Cond, indent + 6); // 显示条件
            printf("%*cIF子句：(%d)\n", indent + 3, ' ', T->pos);
            display(T->IfStm, indent + 6); // 显示if子句
            printf("%*cELSE子句：(%d)\n", indent + 3, ' ', T->pos);
            display(T->ElseStm, indent + 6); // 显示else子句
            break;
        case DEF_LIST:
            display(T->Def, indent);     // 显示该局部变量定义列表中的第一个
            display(T->DefList, indent); // 显示其它局部变量定义
            break;
        case VAR_DEF:
            printf("%*c局部变量定义：(%d)\n", indent, ' ', T->pos);
            display(T->Specifier, indent + 3); // 显示变量类型
            display(T->DecList, indent + 3);   // 显示该定义的全部变量名
            break;
        case DEC_LIST:
            printf("%*c变量名：\n", indent, ' ');
            T0 = T;
            while (T0)
            {
                if (T0->Dec->kind == ID)
                    printf("%*c %s\n", indent + 6, ' ', T0->Dec->type_id);
                else if (T0->Dec->kind == ARRAY)
                    display(T0->Dec, indent + 6);
                else if (T0->Dec->kind == ASSIGNOP)
                {
                    printf("%*c %s ASSIGNOP\n ", indent + 6, ' ', T0->Dec->Dec->type_id);
                    display(T0->Dec->RightExp, indent + strlen(T0->Dec->Dec->type_id) + 7); // 显示初始化表达式
                }
                T0 = T0->DecList;
            }
            break;
        case ARRAY:
            printf("%*cID： %s\n", indent, ' ', T->type_id);
            display(T->Arr, indent);
            break;
        case ARRAY_LIST:
            printf("%*c维数：%d\n", indent, ' ', T->type_int);
            display(T->ArrList, indent);
            break;
        case ARRAY_VAL:
            printf("%*c%c\n", indent, ' ', '{'); // 数组括号
            display(T->ArrVal, indent + 3);
            printf("%*c%c\n", indent, ' ', '}');
            break;
        case ARRAY_VAL_LIST:
            display(T->ArrVal, indent); // 数组的值
            display(T->ArrValList, indent);
            break;
        case ARRAY_VAL_N:
            display(T->ArrVal, indent); // 数组的值
            display(T->ArrValList, indent);
            break;
        case ARRAY_VAL_1:
            display(T->ArrVal, indent);
            break;
        case ID:
            printf("%*cID： %s\n", indent, ' ', T->type_id);
            break;
        case INT:
            printf("%*cINT：%d\n", indent, ' ', T->type_int);
            break;
        case FLOAT:
            printf("%*cFLAOT：%f\n", indent, ' ', T->type_float);
            break;
        case CHAR:
            printf("%*cCHAR：%c\n", indent, ' ', T->type_char); // 增加了 char
            break;
        case ASSIGNOP:
        case AND:
        case OR:
        case RELOP:
        case PLUS:
        case MINUS:
        case STAR:
        case DIV:
            printf("%*c%s\n", indent, ' ', T->type_id);
            display(T->Exp1, indent + 3);
            display(T->Exp2, indent + 3);
            break;
        case DPLUS_PREFIX:
        case DPLUS_POSTFIX:
        case DMINUS_PREFIX:
        case DMINUS_POSTFIX:
        case NOT:
        case UMINUS:
            printf("%*c%s\n", indent, ' ', T->type_id);
            display(T->Exp1, indent + 3);
            break;
        case FUNC_CALL:
            printf("%*c函数调用：(%d)\n", indent, ' ', T->pos);
            printf("%*c函数名：%s\n", indent + 3, ' ', T->type_id);
            if (T->Args)
                display(T->Args, indent + 3);
            else
                printf("%*c 无参数\n", indent + 3, ' ');
            break;
        case ARGS:
            i = 1;
            while (T)
            { // ARGS表示实际参数表达式序列结点，其第一棵子树为其一个实际参数表达式，第二棵子树为剩下的
                struct ASTNode *T0 = T->Exp1;
                printf("%*c第%d个实际参数表达式：\n", indent, ' ', i++);
                display(T0, indent + 3);
                T = T->Args;
            }
            printf("\n");
            break;
        }
    }
}
