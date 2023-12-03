#ifndef _ELM_H_
#define _ELM_H_
#ifdef  _ELM_C_

    #include <stdlib.h>
    #include <string.h>
    #define TRUE 1
    #define FALSE 0
    typedef struct _elm_
    {
       char * data;
    }Elm;

    //Função para criar o elemento
    Elm * elmCriar(char * data);

    //Função de comparação
    int elmCmp(void * data,void * chave);

    //Função de transformação para String
    char * elmToString(Elm * e);

    //Função de Apagar 
    int elmFree(void * data);

    void freeTeste(Elm * data);
    

#else

    typedef struct _elm_ Elm;

    //Função para criar o elemento
    extern Elm * elmCriar(char * data);

    //Função de comparação
    extern int elmCmp(void * data,void * chave);

    //Função de transformação para String
    extern char * elmToString(Elm * e);

    //Função de Apagar 
    extern int elmFree(void * data);

    extern void freeTeste(Elm * data);

#endif
#endif