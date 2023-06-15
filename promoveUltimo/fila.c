#include <stdio.h>
#include <stdlib.h>


typedef struct _queue_ {
    int front, rear;
    int maxItens;
    void **item;
}Queue;

Queue *qCreate( int n ){
    Queue *q;
    if ( n >0 ) {
        q = (Queue *) malloc(sizeof(Queue));
        if ( q != NULL ) {
            q->item = (void **) malloc (sizeof(void *)*n);
            if ( q->item != NULL ){
                q->maxItens = n;
                q->front = 0;
                q->rear = -1;
                return q;
            }
        }
        free(q);
    }
    return NULL;
}

int qEnqueue( Queue *q, void *data){
    if ( q != NULL ) {
        if ( q->rear < q->maxItens-1){
            q->rear++;
            q->item[q->rear] = data;
            return 1;
        }
    }
    return 0;
}

void *qDequeue( Queue *q ){
    void *data; int cur, next, i;
    if ( q != NULL ) {
        if ( q->rear >= 0 ){
            data = q->item[q->front];
            for (i=q->front; i< q->rear;i++){
                cur = i; next = i+1;
                q->item[cur] = q->item[next];
            }
            q->rear--;
            return data;
        }
    }
    return NULL;
}