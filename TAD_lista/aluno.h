#ifndef _ALUNO_H
#define _ALUNO_H

#ifdef  _ALUNO_C_
    #include <stdlib.h>
    #include <string.h>

    #define TRUE  1
    #define FALSE 0
    
    typedef struct _aluno_ Aluno;

    typedef struct _aluno_{
        char    nome[30];
        float   id;
        int     inscricao;

    }Aluno;

    //Função para criar o aluno
    Aluno * alunoCriar(char * nome,float id, int inscricao);


    //Função que compara o nome do aluno com um nome recebido
    int alunoCmpNome(void * a, void * b);


    //Função que compara a ID do aluno com uma ID recebida
    int alunoCmpId(void *a, void *b);


    //Função que compara o número de inscrição do aluno com um número de inscrição recebido
    int alunoCmpInscricao(void *a, void *b);

    int alunoCmp(void * aluno,void * chave);

    //Função que pega a string com o nome do aluno
    char * alunoGetNome(void * aluno);


    int alunoEAluno(void * aluno);

    int alunoPar(void * aluno);

#else

    typedef struct _aluno_ Aluno;

    //Função para criar o aluno
    extern Aluno * alunoCriar(char * nome,float id, int inscricao);


    //Função que compara o nome do aluno com um nome recebido
    extern int alunoCmpNome(void * a, void * b);


    //Função que compara a ID do aluno com uma ID recebida
    extern int alunoCmpId(void *a, void *b);


    //Função que compara o número de inscrição do aluno com um número de inscrição recebido
    extern int alunoCmpInscricao(void *a, void *b);

    //Função que pega a string com o nome do aluno
    extern char * alunoGetNome(void * aluno);

    extern int alunoCmp(void * tipo,void * chave);

    extern int alunoEAluno(void * aluno);

    extern int alunoPar(void * aluno);


    

#endif
#endif