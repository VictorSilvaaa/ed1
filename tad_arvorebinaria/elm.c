#ifndef _ELM_C_
#define _ELM_C_
#include "elm.h"

//Função para criar o elemento
Elm * elmCriar(char * data){
    
    int size=strlen(data);
    if(data!=NULL && size>0){
        if(data[0]!=*"\n"){
            Elm * newElm=NULL;
            newElm=(Elm *)malloc(sizeof(Elm));
            if(newElm!=NULL){
                char* string=(char *)malloc(sizeof(char)*size);
                if(newElm->data!=NULL){
                    strncpy(string,data,size);
                    string[size-1]=0;
                    newElm->data=string;
                    return newElm;
                }
            }
        }
    }
    return NULL;
}

//Função de comparação
int elmCmp(void * data,void * chave){
    Elm * elm;
    char * string;
    if(data!=NULL && chave!=NULL){
        string=(char *)chave;
        elm=(Elm *)data;
        if(strcmp(string,elm->data)==0){
            return TRUE;
        }
    }
    return FALSE;
}

//Função de transformação para String
char * elmToString(Elm * e){
    if(e!=NULL){
        char * data;
        data=e->data;
        return data;
    }
    return NULL;
}

//Função de Apagar 
int elmFree(void * data){
    if(data!=NULL){
        Elm * aux;
        aux=data;
        if(aux!=NULL){
            free(aux);
            return TRUE;
        }
    }
    return FALSE;
}

#endif