#include "stdio.h"
#include "stdlib.h"

#define OK 1
#define TRUE 1
#define ERORR 0
#define FALSE 0
#define OVERFLOW -1
#define LIST_SIZE 100
#define LIST_SIZE_BACKUP 10

typedef int EleType;
typedef int status;
typedef struct LinearList
{
    EleType * data;
    int size;
    int length;
}LinearList, * pList; // ADT LiearList

status InitList(LinearList * list)
{
    list->data = (EleType *)malloc(LIST_SIZE * sizeof(EleType));
    if (!list->data)
        return ERORR;
    list->length = 0;
    list->size = LIST_SIZE;
    return OK;
}// InitList

status DestroyList(LinearList * list)
{
    if (!list->data)
        return ERORR;
    free(list->data);
    list->size = 0;
    list->length = 0;
    return OK;
}// DestroyList

status ClearList(LinearList * list)
{
    if (!list->data)
        return ERORR;
    free(list->data);
    list->data = (EleType *)malloc(LIST_SIZE * sizeof(EleType));
    if (!list->data)
        return ERORR;
    list->size = LIST_SIZE;
    list->length = 0;
    return 0; 
}// ClearList

status ListEmpty(LinearList list)
{
    if (!list.data)
        return ERORR;

    if (list.length == 0)
        return TRUE;
    else
        return FALSE;
}// ListEmpty

int ListLength(LinearList list)
{
    if (!list.data)
        return ERORR;
    return list.length;
}// ListLength

status GetElem(LinearList list, int i, EleType * e)
{
    if (!list.data && i > 0 && i <= list.length)
        return ERORR;
    *e = list.data[i];
    return OK;
}// GetElem

status LocateElem(LinearList list, EleType * e, status *compare(EleType ))
{
    if (!list.data)
        return ERORR;
    int i = 0;
    for (; i < list.length; ++i)
        if (*compare(*e))
            return (i+1);
    return ERORR;
}// LocateElem

status PriorElem(LinearList list, EleType cur_e, EleType * pre_e)
{
    if (!list.data)
        return ERORR;
    int i = 0;
    for (; i < list.length; ++i)
    {
        if (list.data[i] == cur_e && cur_e == list.data[0])
        {
            *pre_e = cur_e;
            return OK;
        }// if
    }// for
    return ERORR;
}// PriorElem

status NextElem(LinearList list, EleType cur_e, EleType * next_e)
{
    if (!list.data)
        return ERORR;
    int i = 0;
    for (; i < list.length; ++i)
    {
        if (list.data[i] == cur_e && i != list.length - 1)
        {
            *next_e = list.data[i + 1];
            return OK;
        }// if
    }// for
    return ERORR;
}// NextElem

status ListInsert(LinearList * list, int i, EleType e)
{
    if (!list->data)
        return ERORR;
    int j = 0;
    if (i >= 1 && i <= list->length + 1)
    {
        if (list->length + 1 > list->size)
        {
            list->data = (EleType *)realloc(list->data, (LIST_SIZE + LIST_SIZE_BACKUP) * sizeof(EleType));
            list->size += LIST_SIZE_BACKUP;
        }
        for (j = list->length + 1; j > i; --j)
            list->data[j] = list->data[j - 1];
        list->data[i] = e;
        list->length += 1;
        return OK;
    }
    return ERORR;
}// ListInsert

status ListDelete(LinearList * list, int i, EleType * e)
{
    if (!list->data)
        return ERORR;
    if (i >= 1 && i <= list->length)
    {
        *e = list->data[i];
        for (; i < list->length - 1; ++i)
            list->data[i] = list->data[i + 1];
        list->length -= 1;
        return OK;
    }
    return ERORR;
}// ListDelete

status ListTraverse(LinearList list, status * visit(LinearList))
{
    int i;
    for (i = 0; i < list.length; ++i)
        if (!*visit(list))
            return ERORR;
    return OK;
}// ListTraverse