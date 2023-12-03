

#include "DLList.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menuEscolheOpcao();
int menuCriarLista(DLList ** lista);
int menuAdicionarNaLista(DLList * lista, int (dllInsert(DLList * l,void * data) ) );
int menuEncontrarElemento(DLList * lista);
int menuRemoverElemento(DLList * lista);

void * menuDefinirChave();
void menuExibirElementos(DLList * lista);
Aluno * menuCriarAluno();

int main(){
  void * aux = NULL;
  DLList * lista = NULL;
  int menu=-1;
  int subMenu=-1;
  int status=TRUE;
  while(TRUE){
    printf("TAD - Lista Duplamente Encadeada\n");
    printf("0 - Criar Lista\n");
    printf("1 - Adicionar elemento\n");
    printf("2 - Consultar elemento\n");
    printf("3 - Exibir todos os elementos\n");
    printf("4 - Remover itens da Lista\n");
    printf("5 - Esvaziar a lista\n");
    printf("6 - Destruir a lista\n");

    menu = menuEscolheOpcao();

    if(menu==0){
      if(lista==NULL){
        status = menuCriarLista(&lista);
        if(lista!=NULL){
          printf("\nLista Criada com sucesso\n");
        }else{
          printf("\nFalha ao tentar criar a lista\n");
        }
      }else{
        printf("\nJá existe uma lista\n");
      }
    }else if(menu==1){
      printf("Escolha a forma de inserir\n");
      printf("0 - Como primeiro\n");
      printf("1 - Como ultimo\n");

      subMenu = menuEscolheOpcao();

      if(subMenu==0){
        status = menuAdicionarNaLista(lista, dllInsertAsFirst);
      }else if(subMenu==1){
        status = menuAdicionarNaLista(lista,dllInsertAsLast);
      }

      if(status==TRUE){
        printf("\nAdicionado com sucesso\n");
      }else{
        printf("\nFalha ao tentar adicionar\n");
      }
      subMenu=-1;
    }else if(menu==2){
      status = menuEncontrarElemento(lista);

      if(status==TRUE){
        printf("\nElemento está na Lista\n");
      }else{
        printf("\nElemento não está na Lista\n");
      }



    }else if(menu==3){
      menuExibirElementos(lista);
    }else if(menu==4){
      status = menuRemoverElemento(lista);

      if(status==TRUE){
        printf("\nElemento Removido\n");
      }else{
        printf("\nElemento não removido\nO elemento pode não estar na lista\n");
      }
    }else if(menu==5){
      status = dllCleanList(lista);
      if(status){
        printf("\nLista Esvaziada\n");
      }else{
        printf("\nFalha ao tentar esvaziar a lista\n");
      }

    }else if(menu==6){
      status = dllDestroy(lista);
      if(status){
        printf("\nLista Destruída com sucesso\n");
        lista=NULL;
      }else{
        printf("\nFalha ao tentar destruir a lista\n");
      }


    }else if(menu==7){
      dllCleanList(lista);
      printf("\nPrograma encerrado\n");
      break;
    }

    printf("\n");

  }
}


int menuEscolheOpcao(){
  char aux[100];
  fgets(aux,100,stdin);
  int num=strtol(aux,NULL,10);
  if(num>=0){
    return num;
  }
  return -1;
}

int menuCriarLista(DLList ** lista){
  if(*(lista)==NULL){
    *(lista)=dllCreate();
    if(*(lista)!=NULL){
      return TRUE;
    }
  }
    
  return FALSE;
}
 
int menuAdicionarNaLista(DLList * lista, int (dllInsert(DLList * l,void * data) ) ){
  Aluno * aux;
  aux=menuCriarAluno();
  if(aux!=NULL){
    if(dllInsert(lista,aux)){
      return TRUE;
    }
  }
  return FALSE;
}

int menuEncontrarElemento(DLList * lista){
  
  void * aux=NULL;
  void * chave=NULL;

  chave = menuDefinirChave();
  if(chave!=NULL){
    aux=dllQuery(lista,chave,alunoCmp);
    if(aux!=NULL){
      return TRUE;
    }
  }

  return FALSE;
}

int menuRemoverElemento(DLList * lista){
  void * aux=NULL;
  void * chave=NULL;

  chave = menuDefinirChave();
  if(chave!=NULL){
    aux=dllRemoveSpec(lista,chave,alunoCmp);
    if(aux!=NULL){
      return TRUE;
    }
  }

  return FALSE;
}

void * menuDefinirChave(){
  printf("\nEscolha por qual dado você quer usar para encontrar o aluno\n");
  printf("0 - Nome\n1 - Identificação\n2 - Incrição\n");
  int subMenu=-1;

  subMenu = menuEscolheOpcao();

  if(subMenu==0){
    printf("Escreva o nome do aluno\n");
    char * nome;
    nome=(char *)malloc(sizeof(char)*30);
    if(nome!=NULL){
      fgets(nome,30,stdin);
      return (void *)nome;
    }
  }
  
  else if(subMenu==1){
    printf("Escreva o número de identificação do aluno\n");
    float * id;
    id=(float *)malloc(sizeof(float));
    if(id!=NULL){
      scanf("%f",id);
      getchar();
      return (void *)id;
    }
    
  }
  
  else if(subMenu==2){
    printf("Escreva o número de inscrição do aluno\n");
    int * inscricao;
    inscricao=(int *)malloc(sizeof(int));
    if(inscricao!=NULL){
      scanf("%d",inscricao);
      getchar();
      return (void *)inscricao;
    }
  }

  return NULL;
}

void menuExibirElementos(DLList * lista){
  void * auxAluno;
  auxAluno=dllGetFirst(lista);
  if(auxAluno!=NULL){
      char * auxNome;
      auxNome=alunoGetNome(auxAluno);
      printf("\n");
      printf("Elemento %d - %s",0,auxNome);
      auxAluno=dllGetNext(lista);
      for(int i=1;auxAluno!=NULL;i++){
        auxNome=alunoGetNome(auxAluno);
        printf("Elemento %d - %s",i,auxNome);
        auxAluno=dllGetNext(lista);
        
      }
      printf("\n");
  }else{
    printf("\nSem elementos na coleção\n");
  }
}

Aluno * menuCriarAluno(){
  printf("\nDigite o nomo do aluno\n");
  char nome[30];
  fgets(nome,30,stdin);

  printf("Digite a identificação do aluno\n");
  float id;
  scanf("%f",&id);

  printf("Digite o número de inscrição do aluno\n");
  int inscricao;
  scanf("%d", &inscricao);
  getchar();

  return alunoCriar(nome,id,inscricao);
}
