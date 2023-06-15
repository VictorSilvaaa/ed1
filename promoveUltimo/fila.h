#ifndef __FILA_H
#define __FILA_H

typedef struct {
    int front, rear;
    int maxItens;
    void **item;
}Queue;

Queue *qCreate(int n);
int qEnqueue( Queue *q, void *data);
void *qDequeue( Queue *q );
#endif