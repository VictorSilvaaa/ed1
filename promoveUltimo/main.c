#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int qPromoveUltimo(Queue* fila, int n){
    void* data;
    int newPosition;
    if(fila!=NULL && n>0){
        if(fila->item!=NULL){ 
            data = fila->item[fila->rear];
            if(n<fila->rear){
                newPosition = fila->rear - n;
            }else{
                newPosition = fila->front;
            }
            for(int i = fila->rear; i>newPosition; i--){
                fila->item[i] = fila->item[i-1];
            }
            fila->item[newPosition] = data;
            return 1;
        }
    }
    return 0;
}


int main(){
    Queue* fila = qCreate(4);
    int num1 = 1;
    int num2 = 2;
    int num3 = 3;
    int num4 = 4;
    qEnqueue(fila,(void*)num1);
    qEnqueue(fila,(void*)num2);
    qEnqueue(fila,(void*)num3);
    qEnqueue(fila,(void*)num4);
    //out: 1,2,3,4
    qPromoveUltimo(fila, 2);
    //out: 1,3, 2, 3
    for(int i=0; i<4; i++){
        printf("%d ", (int)fila->item[i]);
    }
    
    return 0;
}