#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct LinearList
{
    int * elem;
    int length;
    int listsize;
}List;
//zzy
int InitList(List *list)
{
    int tmpLen = 0;
    printf("length: ");
    scanf("%d", &tmpLen);
    printf("\n");
    fflush(stdin);
    list->elem = (int *)malloc(sizeof(int) * tmpLen);
    if (!list->elem)
        exit(-1);
    list->length = tmpLen;
    list->listsize = tmpLen * sizeof(int);
    return 1;
}

int ShowList(List theList)
{
    int i = 0;
    for (i = 0; i < theList.length; ++i)
        printf("%d ", theList.elem[i]);
    printf("\n");
    return 1;
}

int DeleteList(List *theList)
{
    theList->length = 0;
    theList->listsize = 0;
    free(theList->elem);
    return 1;
}

int RandonList(List *theList)
{
    int i = 0;
    srand((unsigned)time(NULL));
    for (i = 0; i < theList->length; ++i)
    {
        theList->elem[i] = rand() % 100;
        theList->listsize += 1 * sizeof(int);
    }
    return 1;
}

void Swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int Partition(int * elem, int low, int high)
{
    int a = low, b = high, key = elem[0];
    int length = high - low;
    if (length < 2)
        return low;
    while(1)
    {
        do
            ++a;
        while(a < high && elem[a] < key);
        do
            --b;
        while(b > low && elem[b] > key);
        if (a >= b)
            break;
        Swap(&elem[a], &elem[b]);
    }
    Swap(&elem[0], &elem[b]); //Why b?
    return b;
}

int QuickSortWithRecursion(int *a, int len)
{
    if (len < 2)
        return 0;
    int j = Partition(a, 0, len);
    QuickSortWithRecursion(a, j);
    QuickSortWithRecursion(a + j + 1, len - j - 1);
}

int main()
{
    List theList;
    InitList(&theList);
    RandonList(&theList);
    ShowList(theList);
    QuickSortWithRecursion(theList.elem, theList.length);
    ShowList(theList);
    DeleteList(&theList);
    return 1;
}