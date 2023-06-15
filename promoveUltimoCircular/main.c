#include <stdio.h>
#include <stdlib.h>
#include "cfila.h"

int cqPromoveUltimo(cQueue* fila, int n){
    void* data;
    data = fila->item[fila->rear];
    if(n>0){
        if(n>fila->nElements){
            n = fila->nElements;
        }
        int curr, next;
        curr = fila->rear;
        for(int i =0; i<n; i++){
            next = decCirc(curr, fila->maxItens);
            fila->item[curr] = fila->item[next];
            curr = next;
        }
        fila->item[curr] = data;
    }
    return 0;
}


int main(){
    cQueue* fila = cqCreate(4);
    int num1 = 1;
    int num2 = 2;
    int num3 = 3;
    int num4 = 4;
 
    cqEnqueue(fila,(void*)num1);
    cqEnqueue(fila,(void*)num2);
    cqEnqueue(fila,(void*)num3);
    cqEnqueue(fila,(void*)num4);
 
    //out: 1,2,3,4
    cqPromoveUltimo(fila, 2);
    //out: 1,3, 2, 3
    for(int i=0; i<4; i++){
        printf("%d ", (int)cqDequeue(fila));
    }
   
    return 0;
}