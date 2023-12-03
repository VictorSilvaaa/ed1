#include <stdio.h>
#include <stdlib.h>
#include "cfila.h"

int cqPromoveN(cQueue *fila, int n)
{
    void *temp;
    int curr, next;
    if (n > 0)
    {
        if (n > fila->nElements)
        {
            n = fila->nElements;
        }
        curr = fila->front;
        for (int i = 0; i < n - 1; i++)
        {
            curr = incCirc(curr, fila->maxItens);
        }

        temp = fila->item[curr];

        for (int i = 0; i < n - 1; i++)
        {
            next = decCirc(curr, fila->maxItens);
            fila->item[curr] = fila->item[next];
            curr = next;
        }
        fila->item[curr] = temp;
    }
    return 0;
}

int main()
{
    cQueue *fila = cqCreate(6);
    int num1 = 1;
    int num2 = 2;
    int num3 = 3;
    int num4 = 4;
    int num5 = 5;
    int num6 = 6;

    cqEnqueue(fila, (void *)num1);
    cqEnqueue(fila, (void *)num2);
    cqEnqueue(fila, (void *)num3);
    cqEnqueue(fila, (void *)num4);
    cqEnqueue(fila, (void *)num5);
    cqEnqueue(fila, (void *)num6);

    // out: 1,2,3,4
    cqPromoveN(fila, 3);
    // out: 1,3, 2, 3
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", (int)cqDequeue(fila));
    }

    return 0;
}