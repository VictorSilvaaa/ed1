#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int cmpInteiro(void * elm, void * num){
    if(elm!=NULL && num!=NULL){
        int * auxElm, * auxNum;
        auxElm=(int *)elm;
        auxNum=(int *)num;
        if(*auxElm==*auxNum){
            return TRUE;
        }
    }
    return FALSE;
}

int cmpInterioMaior(void * elm, void * num){
    if(elm!=NULL && num!=NULL){
        int * auxElm, * auxNum;
        auxElm=(int *)elm;
        auxNum=(int *)num;
        if(*auxElm>*auxNum){
            return TRUE;
        }
    }
    return FALSE;
}

int cmpFloat(void * elm, void * num){
    if(elm!=NULL && num!=NULL){
        float *auxElm,* auxNum;
        auxElm=(float *)elm;
        auxNum=(float *)num;
        if(*auxElm==*auxNum){
            return TRUE;
        }
    }
    return FALSE;
}