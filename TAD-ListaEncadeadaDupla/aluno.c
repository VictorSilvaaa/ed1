


/*-----------------------------------------
Aluno: Juan Carlos Melo do Nascimento
Inscrição: 2021068719
Disciplina: Estrutura de dados
-----------------------------------------*/


#ifndef _ALUNO_C_
#define _ALUNO_C_
#include "aluno.h"
#include <string.h>
#include <stdio.h>

Aluno * alunoCriar(char nome[30],float id, int inscricao){
    if(id>0 && inscricao>0){
        Aluno * aluno;
        aluno=(Aluno*)malloc(sizeof(Aluno));
        if(aluno!=NULL){
            for(int i=0;i<30;i++){
              aluno->nome[i]=nome[i];
            }
            aluno->id=id;
            aluno->inscricao=inscricao;
            return aluno;
        }
    }
    return NULL;
}

int alunoCmpNome(void * a, void * b){
  if(b!=NULL){
    if(a!=NULL){
        char *nome = (char*)b;
        Aluno *aluno = (Aluno *)a;
        int size = strlen(nome);     
        if(strncmp(aluno->nome,nome,size)==0){
          return TRUE;
        }
    }
  }
  return FALSE;
}

int alunoCmpId(void *a, void *b){
  if(b!=NULL){
    if(a!=NULL){
      
      float *id = (float*)b;
      Aluno *aluno = (Aluno*)a;
    
      if(aluno->id == *id){//Se forem iguais retorna TRUE
        return TRUE;
      }
    }
  }
  return FALSE;//Retorna FALSE em caso de qualquer falha na execução ou se os dados não forem       iguais
}

int alunoCmpInscricao(void *a, void *b){
  if(b!=NULL){
    if(a!=NULL){
      
      int * incricao = (int*)b;
      Aluno * aluno    = (Aluno*)a;
    
      if(aluno->inscricao == *incricao){//Se forem iguais retorna TRUE
        return TRUE;
      }
    }
  }
  return FALSE;//Retorna FALSE em caso de qualquer falha na execução ou se os dados não forem iguais
}

char * alunoGetNome(void * aluno){
  if(aluno!=NULL){
    Aluno * auxAluno = (Aluno *) aluno;
    char *aux;
    aux=(char *)malloc(sizeof(char)*30);
    if(aux!=NULL){
      if(auxAluno->nome!=NULL){
        strcpy(aux,auxAluno->nome);
        return aux;
      }
      
    }
  }
  return NULL;
}

int alunoCmp(void * tipo, void * chave){
  int status = FALSE;
  if(tipo!=NULL){
    if(chave!=NULL){
      status = alunoCmpNome(tipo,chave);
      if(status==FALSE){
        status = alunoCmpId(tipo,chave);
        if(status==FALSE){
          status = alunoCmpInscricao(tipo,chave);
        }
      }
    }
  }
  return status;
}


#endif