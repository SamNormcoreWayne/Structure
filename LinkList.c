#include "stdio.h"
#include "stdlib.h"

#define TRUE 1
#define FALSE 0
#define ERORR 0
#define OK 1
#define OVERFLOW -1

typedef int status;
typedef char EleType;
typedef struct linkList
{
    EleType * data;
    struct linkList * next;
}LinkList, * LNode;

status InitList(LinkList *list)
{
    list = (LNode)malloc(sizeof(LinkList));
    list->data = { '\0' };
    if (!list)
        exit(-1);
    list->next = NULL;
    return OK;
}//InitList

status DestoryList(LinkList * list)
{
    if (!list->data)
        return ERORR;
    free(list);
    return OK;
}//DestoryList

status ClearList(LinkList *list)
{
    if (!list->data)
        return ERORR;
    free(list);
    list->data = { '\0' };
    list->next = NULL;
    return OK;
}//ClearList

status ListEmpty(LinkList list)
{
    if (!list.data)
        return ERORR;
    if (!list.next)
        return TRUE;
    else
        return FALSE;
}//ListEmpty

status GetElem(LinkList list, int i, EleType *e)
{
    if (!list.data)
        return ERORR;
    int k = 0;
    LinkList * tmp;
    *tmp = list;
    
    for (k = 0; k < i - 1; ++k)
    {
        if (!tmp)
            return ERORR;
        if (e == tmp->data)
            return OK;
        tmp = tmp->next;
    }
    return ERORR;
}//GetElem

status LocateElem(LinkList list, EleType e, int compare(EleType *))
{
    if (!list.data)
        return ERORR;
    int k = 0;
    LinkList * tmp;
    EleType * tmpE;
    *tmp = list;

    while (tmp)
    {
        if (compare(tmp->data))
            return TRUE;
        tmp = tmp->next;
    }
    return FALSE;
}//LocateElem

status PriorElem(LinkList list, EleType * e, EleType * pre)
{
    if (!list.data || e == list.data)
        return ERORR;
    
    LinkList * tmp_1, * tmp_2;
    *tmp_1 = list;
    while (tmp_1->next)
    {
        tmp_2 = tmp_1->next;
        if (tmp_2->data == e)
        {
            pre = tmp_1->data;
            return OK;
        }
        tmp_1 = tmp_1->next;
    }
    return ERORR;
}//PriorElem

status NextElem(LinkList list, EleType * e, EleType * next)
{
    if (!list.data)
        return ERORR;

    LinkList * tmp_1, * tmp_2;
    *tmp_1 = list;
    while (tmp_1->next)
    {
        tmp_2 = tmp_1;
        tmp_1 = tmp_1->next;
        if (tmp_2->data == e)
        {
            next = tmp_1->data;
            return OK;
        }
    }
    return ERORR;
}//NextElem

status ListInsert(LinkList * list, int i, EleType * e)
{
    int k = 0;
    LNode NewNode;
    LinkList * tmp;
    tmp = list;
    InitList(NewNode);
    NewNode->data = e;

    for (k = 0; k < i - 2; ++k)
    {
        tmp = tmp->next;
        if (!tmp->next)
            return ERORR;
    }
    NewNode->next = tmp->next->next;
    tmp->next = NewNode;
    return OK;
}//ListInsert

status ListDelete(LinkList * list, int i, EleType *e)
{
    if (!list->data)
        return ERORR;

    int k = 0;
    LinkList * tmp;
    tmp = list;
    
    for (k = 0; k < i - 2; ++k)
    {
        if (!tmp->next)
            return ERORR;
        tmp = tmp->next;
    }
    tmp->next = tmp->next->next;
    return OK;
}//ListDelete

status ListTraversal(LinkList list, int visit(LinkList *))
{
    if (!list.data)
        return ERORR;

    LinkList * tmp;
    *tmp = list;

    while (tmp)
    {
        if (!visit(tmp))
            return ERORR;
        tmp = tmp->next;
    }
    return OK;
}//ListTraversal

//Finished