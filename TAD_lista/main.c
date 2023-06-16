#include "SLList.h"
#include "aluno.h"
#include "nums.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Funções para de navegação do menu

//**********************************************************************************
int menuCriarLista(SLList ** lista);
int menuAdicionarNaLista(SLList * lista, int (sllInsert(SLList * l,void * data) ) );
int menuAdicionarNaListaUsandoChave(SLList * lista, int (sllInsert (SLList * l,void * key,int (*cmp)(void *, void *), void * data )));
int menuEncontrarElemento(SLList * lista);
int menuRemoverElemento(SLList * lista);
//**********************************************************************************//




//Funções de Exibição

//**********************************************************************************
void menuExibirElementos(SLList * lista);
//**********************************************************************************//



//Criação de Variaveis

//**********************************************************************************
void * menuDefinirChave();
Aluno * menuCriarAluno();
int menuEscolheOpcao();
//**********************************************************************************//




//Funções de teste de Questões

//**********************************************************************************
void menuTestarFuncoesDuasListas();

void menuTestarFuncoesEntradaVetor();

void menuTestarFuncoesEntradaLista();
//**********************************************************************************//


//**********************************************************************************

//Funções Main

//**********************************************************************************


int main(){
  void * aux = NULL;
  SLList * lista = NULL;
  int menu=-1;
  int subMenu=-1;
  int status=TRUE;
  while(TRUE){
    printf("TAD - Lista Simplesmente Encadeada\n");
    printf("0 - Criar Lista\n");
    printf("1 - Adicionar elemento\n");
    printf("2 - Consultar elemento\n");
    printf("3 - Exibir todos os elementos\n");
    printf("4 - Remover itens da Lista\n");
    printf("5 - Esvaziar a lista\n");
    printf("6 - Destruir a lista\n");
    printf("7 - Encerrar programa\n");
    printf("8 - Testar Questões\n");

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
      printf("2 - Após uma elemento\n");
      printf("3 - Antes de um elemento\n");
      

      subMenu = menuEscolheOpcao();

      if(subMenu==0){
        status = menuAdicionarNaLista(lista,sllInsertAsFirst);
      }else if(subMenu==1){
        status = menuAdicionarNaLista(lista,sllInsertAsLast);
      }else if(subMenu==2){
        status = menuAdicionarNaListaUsandoChave(lista,sllInsertAfterSpec);
      }else if(subMenu==3){
        status = menuAdicionarNaListaUsandoChave(lista,sllInsertBeforeSpec);
      }

      if(status==TRUE){
        printf("\nAdicionado com sucesso\n");
      }else{
        printf("\nFalha ao tentar adicionar\n");
      }
      subMenu=-1;
    }else if(menu==2){
      menuEncontrarElemento(lista);

      status = FALSE;

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
      status = sllCleanList(lista);
      if(status){
        printf("\nLista Esvaziada\n");
      }else{
        printf("\nFalha ao tentar esvaziar a lista\n");
      }

    }else if(menu==6){
      status = sllDestroy(lista);
      if(status){
        printf("\nLista Destruída com sucesso\n");
        lista=NULL;
      }else{
        printf("\nFalha ao tentar destruir a lista\n");
      }


    }else if(menu==7){
      sllCleanList(lista);
      printf("\nPrograma encerrado\n");
      break;
    }else if(menu==8){
      menuTestarFuncoesEntradaLista();
    }
    printf("\n");
  }

}

//**********************************************************************************

//Funções main

//**********************************************************************************



//Funções de teste de Questões

//**********************************************************************************

void menuTestarFuncoesDuasListas(){
  SLList * lista1;
  SLList * lista2;
  SLList * lista3;
  int menu=-1;
  printf("Preencher lista 1\n");
  lista1=sllCreate();
  lista2=sllCreate();
  lista3=sllCreate();
  while(TRUE){
    printf("0 - Adicionar elemento\n9 - Continuar\n");
    menu=menuEscolheOpcao();
    if(menu==0){
      menuAdicionarNaLista(lista1,sllInsertAsLast);
    }else if(menu==9){
      printf("Lista 1\n");
      menuExibirElementos(lista1);
      break;
    }
  }

  printf("Preencher lista 2\n");
  while(TRUE){
    printf("0 - Adicionar elemento\n9 - Continuar\n");
    menu=menuEscolheOpcao();
    if(menu==0){
      menuAdicionarNaLista(lista2,sllInsertAsLast);
    }else if(menu==9){
      printf("Lista 2\n");
      menuExibirElementos(lista2);
      break;
    }
  }

  lista3 = NULL;
  sllRemoveElementosRepitidos(lista1,lista2,alunoCmp);
  printf("Lista 3\n");
  menuExibirElementos(lista3);
  sllCleanList(lista3);

}

void menuTestarFuncoesEntradaLista(){
  SLList * lista1;
  int menu=-1;
  lista1=sllCreate();
  if(lista1!=NULL){
    printf("Preencher lista 1\n");
    while(TRUE){
      printf("0 - Adicionar elemento\n9 - Continuar\n");
      menu=menuEscolheOpcao();
      if(menu==0){
        printf("Digite um número maior ou igual a 0: ");
        int aux;
        int * num;
        num=(int *)malloc(sizeof(int));
        *num=menuEscolheOpcao();
        if(num>=0){
          sllInsertAsLast(lista1,(void *)num);
        }else{
          printf("Falha - O número digitado é menor que 0");
        }
        
      }else if(menu==9){
        printf("Lista 1\n");
        menuExibirElementos(lista1);
        break;
      }
      printf("\n");
    }

    void * aux;
    aux=sllRetornaMaior(lista1,cmpInterioMaior);

    printf("Lista 1\n");
    printf("Maior = %d\n", *(int *)aux);

  }
}

//**********************************************************************************//




//Funções para de navegação do menu

//**********************************************************************************

int menuCriarLista(SLList ** lista){
  if(*(lista)==NULL){
    *(lista)=sllCreate();
    if(*(lista)!=NULL){
      return TRUE;
    }
  }
    
  return FALSE;
}
 
int menuAdicionarNaLista(SLList * lista, int (sllInsert(SLList * l,void * data) ) ){
  Aluno * aux;
  aux=menuCriarAluno();
  if(aux!=NULL){
    if(sllInsert(lista,aux)){
      return TRUE;
    }
  }
  return FALSE;
}

int menuAdicionarNaListaUsandoChave(SLList * lista, int (sllInsert (SLList * l,void * key,int (*cmp)(void *, void *), void * data))){
  Aluno * aux;
  aux=menuCriarAluno();
  printf("\nCrie a chave para para poder posicionar o aluno\n");
  void * chave;
  chave=menuDefinirChave();
  if(aux!=NULL && chave!=NULL){
    if(sllInsert(lista,chave,alunoCmp,aux)){
      return TRUE;
    }
  }
  return FALSE;
}

int menuEncontrarElemento(SLList * lista){
  
  void * aux=NULL;
  void * chave=NULL;

  chave = menuDefinirChave();
  if(chave!=NULL){
    aux=sllQuery(lista,chave,alunoCmp);
    if(aux!=NULL){
      return TRUE;
    }
  }

  return FALSE;
}

int menuRemoverElemento(SLList * lista){
  void * aux=NULL;
  void * chave=NULL;

  chave = menuDefinirChave();
  if(chave!=NULL){
    aux=sllRemoveSpec(lista,chave,alunoCmp);
    if(aux!=NULL){
      return TRUE;
    }
  }

  return FALSE;
}

//**********************************************************************************//



//Funções de Exibição

//**********************************************************************************

void menuExibirElementos(SLList * lista){
  void * auxAluno;
  auxAluno=sllGetFirst(lista);
  if(auxAluno!=NULL){
    int tam=sllNElms(lista);
    printf("\n\nTamanho da Lista %d\n",tam);
    char * auxNome;
    auxNome=alunoGetNome(auxAluno);
    printf("Elemento %d - %s",0,auxNome);
    auxAluno=sllGetNext(lista);
    for(int i=1;auxAluno!=NULL;i++){
      auxNome=alunoGetNome(auxAluno);
      printf("Elemento %d - %s",i,auxNome);
      auxAluno=sllGetNext(lista);
      
    }
  }else{
    printf("\nSem elementos na coleção\n");
  }
}
//**********************************************************************************//



//Criação de Variaveis

//**********************************************************************************
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

int menuEscolheOpcao(){
  char aux[100];
  fgets(aux,100,stdin);
  int num=0;
  num = strtol(aux,NULL,10);
  if(num>=0){
    if(aux[0]==*"0"){
      return num;
    }else if(num>0){
      return num;
    }
  }

  return -1;
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
      return nome;
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

