#ifndef __CFILA_H
#define __CFILA_H

typedef struct _cqueue_ {
    int front, rear;
    int maxItens;
    int nElements;
    void **item;
}cQueue;

cQueue *cqCreate(int n);
int cqEnqueue( cQueue *cq, void *data);
void *cqDequeue( cQueue *cq );
int incCirc(int i, int max);
int decCirc(int i, int max);

#endif