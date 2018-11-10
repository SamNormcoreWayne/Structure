#include "stdio.h"
#include "stdlib.h"

#define OK 1
#define ERORR -1
#define FALSE -1
#define TRUE 1
#define OVERFLOW -1
#define STACK_INIT_SIZE 100
#define SIZE_BACKUP 10

typedef char EleType;
typedef int status;
typedef struct Stack
{
    EleType * base;
    EleType * top;
    int stacksize;
}SqStack;

status InitStack(SqStack &stack)
{
    stack.base = (EleType *)malloc(STACK_INIT_SIZE * sizeof(EleType));
    if (!stack.base)
        exit(OVERFLOW);
    stack.top = stack.base;
    stack.stacksize = STACK_INIT_SIZE;
    return OK;
}

status DestroyStack(SqStack &stack)
{
    free(stack.base);
    free(stack.top);

    return OK;
}

status ClearStack(SqStack &stack)
{
    stack.top = stack.base;
    stack.stacksize = 0;
    return OK;
}

status StackEmpty(SqStack stack)
{
    if (stack.base == stack.top)
        return TRUE;
    else
        return FALSE;
    return OK;
}

status StackLength(SqStack stack)
{
    return stack.stacksize;
}

status GetTop(SqStack stack, EleType * e)
{
    if (stack.top == stack.base)
        return ERORR;
    *e = *(stack.top - 1);
    return OK;
}

status Push(SqStack &stack, EleType e)
{
    if (stack.base - stack.top >= stack.stacksize)
        return OVERFLOW;
    *stack.top++ = e;
    return OK;
}

status Pop(SqStack stack, EleType *e)
{
    if (stack.top == stack.base)
        return ERORR;
    *e = *--stack.top;
    return OK;
}

status StackTraverse(SqStack stack, status(* visit)(EleType *))
{
    if (stack.base == stack.top)
        return ERORR;
    
    while (!visit(--stack.top))
        return ERORR;
    return OK;
}