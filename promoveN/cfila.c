#include <stdio.h>
#include <stdlib.h>

typedef struct _cqueue_ {
    int front, rear;
    int maxItens;
    int nElements;
    void **item;
}cQueue;


int incCirc(int i, int max){
    if(i==max-1){
        return 0;
    }else{
        return i+1;
    }
}
int decCirc(int i, int max){
    if(i==0){
        return max-1;
    }else{
        return i-1;
    }
}


cQueue *cqCreate( int n ){
    cQueue *cq;
    if ( n >0 ) {
        cq = (cQueue *) malloc(sizeof(cQueue));
        if ( cq != NULL ) {
            cq->item = (void **) malloc (sizeof(void *)*n);
            if ( cq->item != NULL ){
                cq->maxItens = n;
                cq->front = 0;
                cq->nElements = 0;
                cq->rear = -1;
                return cq;
            }
        }
        free(cq);
    }
    return NULL;
}

int cqEnqueue( cQueue *cq, void *data){
    if ( cq != NULL ) {
        if ( cq->nElements < cq->maxItens){
            cq->rear = incCirc(cq->rear, cq->maxItens);
            cq->item[cq->rear] = data;
            cq->nElements++;
            return 1;
        }
    }
    return 0;
}

void *cqDequeue( cQueue *cq ){
    void* data;
    if ( cq != NULL ) {
        if ( cq->nElements > 0 ){
            data = cq->item[cq->front];
            cq->front = incCirc(cq->front, cq->maxItens);
            cq->nElements--;
            return data;
        }
    }
    return NULL;
}