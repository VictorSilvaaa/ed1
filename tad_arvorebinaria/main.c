
#include "Tree.h"
#include "elm.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0


int menuEscolheOpcao();
int menuCriarArvore(TNode ** arvore);

int menuAdicionarNaArvore(TNode * arvore, int (abInsert(TNode * l,void * data) ));
int menuAdicionarNaArvoreSequencia(TNode * arvore, int (abInsert(TNode * l,void * data) ));

int menuEncontrarElemento(TNode * arvore);
void * menuRemoverElemento(TNode ** arvore);

void * menuDefinirChave(void * chave);
void menuApagarChave(void ** chave);

void menuPrintPreOrdem(TNode * arvore, char * lado, int index,char *(*toString)(Elm *));
void menuPrintSimetrico(TNode * arvore, char * lado, int index,char *(*toString)(Elm *));
void menuPrintPosOrdem(TNode * arvore, char * lado, int index,char *(*toString)(Elm *));


void menuPrintSimpPreOrdem(TNode * arvore, char * lado, int index,char *(*toString)(Elm *));
void menuPrintSimpSimetrico(TNode * arvore, char * lado, int index,char *(*toString)(Elm *));
void menuPrintSimpPosOrdem(TNode * arvore, char * lado, int index,char *(*toString)(Elm *));

void menuPrintParenPreOrdem(TNode * arvore,char *(*toString)(Elm *));
void menuPrintParenSimetrico(TNode * arvore,char *(*toString)(Elm *));
void menuPrintParenPosOrdem(TNode * arvore,char *(*toString)(Elm *));

void * menuCriarElm();

int main(){
  void * aux = NULL;
  TNode * arvore = NULL;
  int menu=-1;
  int subMenu=-1;
  int status=TRUE;
  while(TRUE){
    printf("TAD - Árvore\n");
    printf("0 - Criar Árvore\n");
    printf("1 - Adicionar elemento\n");
    printf("2 - Consultar elemento\n");
    printf("3 - Exibir todos os elementos\n");
    printf("4 - Remover itens da Árvore\n");
    printf("5 - Esvaziar e Destruir a Árvore\n");
    printf("6 - Sair\n");

    menu = menuEscolheOpcao();

    if(menu==0){
      if(arvore==NULL){
        status = menuCriarArvore(&arvore);
        if(arvore!=NULL){
          printf("\nÁrvore Criada com sucesso\n");
        }else{
          printf("\nFalha ao tentar criar a arvore\n");
        }
      }else{
        printf("\nJá existe uma arvore\n");
      }
    }
    
    else if(menu==1){
      printf("Escolha a forma de inserir\n");
      printf("0 - Base\n");
      printf("1 - Lado esquerdo\n");
      printf("2 - Lado direito\n");
      printf("3 - Adicionar em Lote\n");

      subMenu = menuEscolheOpcao();

      if(subMenu==0){
        status = menuAdicionarNaArvore(arvore,abInsertV2);
      }else if(subMenu==1){
        status = menuAdicionarNaArvore(arvore,abInsertLeft);
      }else if(subMenu==2){
        status = menuAdicionarNaArvore(arvore,abInsertRight);
      }else if(subMenu==3){
        status = menuAdicionarNaArvoreSequencia(arvore,abInsertV2);
      }

      if(status==TRUE){
        printf("\nAdicionado com sucesso\n");
      }else{
        printf("\nFalha ao tentar adicionar\n");
      }
      subMenu=-1;
    }
    
    else if(menu==2){
      status = menuEncontrarElemento(arvore);

      if(status==TRUE){
        printf("Elemento está na Árvore\n");
      }else{
        printf("Elemento não está na Árvore\n");
      }
    }
    
    else if(menu==3){
      printf("0 - Modo Padrão\n1 - Modo Simplificado\n2 - Parentasses\n");

      subMenu = menuEscolheOpcao();
      if(arvore!=NULL){
        int terMenu=-1;
        if(subMenu==0){
          printf("0 - Pré-Ordem\n1 - Simétrico\n2 - Pos-Ordem\n");
          terMenu = menuEscolheOpcao();

          if(terMenu==0){
            menuPrintPreOrdem(arvore,"Raiz",0,elmToString);
          }else if(terMenu==1){
            menuPrintSimetrico(arvore,"Raiz",0,elmToString);
          }else if(terMenu==2){
            menuPrintPosOrdem(arvore,"Raiz",0,elmToString);
          }

        }else if(subMenu==1){
          printf("0 - Pré-Ordem\n1 - Simétrico\n2 - Pos-Ordem\n");
          terMenu = menuEscolheOpcao();

          if(terMenu==0){
            menuPrintSimpPreOrdem(arvore,"Raiz",0,elmToString);
          }else if(terMenu==1){
            menuPrintSimpSimetrico(arvore,"Raiz",0,elmToString);
          }else if(terMenu==2){
            menuPrintSimpPosOrdem(arvore,"Raiz",0,elmToString);
          }
        }else if(subMenu==2){
        printf("0 - Pré-Ordem\n1 - Simetrico\n2 - Pos-Ordem\n");
          terMenu = menuEscolheOpcao();

          if(terMenu==0){
            menuPrintParenPreOrdem(arvore,elmToString);
          }else if(terMenu==1){
            menuPrintParenSimetrico(arvore,elmToString);
          }else if(terMenu==2){
            menuPrintParenPosOrdem(arvore,elmToString);
          }
        }
      }else{
        printf("\nSem elementos na coleção\n");
      }
    }
    
    else if(menu==4){
      printf("Escolha a forma de remoção de elementos\n");
      printf("0 - Remover um elemento usando uma chave\n");

      subMenu = menuEscolheOpcao();
      void * data=NULL;

      if(subMenu==0){
        data = menuRemoverElemento(&arvore);
      }

      if(data!=NULL){
        elmFree(data);
        printf("\nElemento Removido dá Árvore\n");
      }else{
        printf("\nElemento não Removido dá Árvore\n");
      }
    }
    else if(menu==5){
      status = abFree(&arvore,elmFree);
      if(status==TRUE){
        arvore=NULL;
        printf("Sucesso\n");
      }else{
        printf("Falha\n");
      }
    }
    
    else if(menu==6){
      if(arvore!=NULL){
        abFree(&arvore,elmFree);
        arvore=NULL;
        
      }
      break;
    }

    printf("\n");

  }
}

int menuEscolheOpcao(){
  char aux[100];
  fgets(aux,100,stdin);
  int num=strtol(aux,NULL,10);
  if(num>0){
    return num;
  }else if(num==0 && aux[0]==*"0"){
    return 0;
  }
  return -1;
}

int menuCriarArvore(TNode ** arvore){
  if(*(arvore)==NULL){
    *(arvore)=abCreate();
    if(*(arvore)!=NULL){
      return TRUE;
    }
  }
    
  return FALSE;
}
 
int menuAdicionarNaArvore(TNode * arvore, int (abInsert(TNode * l,void * data) )){
  if(arvore!=NULL){
    void * aux;
    aux=menuCriarElm();
    if(aux!=NULL){
      if(abInsert(arvore,aux)){
        return TRUE;
      }
    }
  }
  return FALSE;
}

int menuIncrementaLetra(char * s){
  if(s!=NULL){
    if(s[0]<126){
      s[0]++;
    }else if(s[0]==126){
      s[0]=33;
    }
  }
}

int menuAdicionarNaArvoreSequencia(TNode * arvore, int (abInsert(TNode * l,void * data))){
  int menu=-1;
  int i, j;
  char * inicio, * fim;
  inicio =(char *)malloc(sizeof(char)*10);
  fim=(char *)malloc(sizeof(char)*10);

  if(arvore!=NULL && inicio!=NULL && fim!=NULL){
    printf("0 - Adicionar Números\n");
    printf("1 - Adicionar Letras\n");
    printf("Qualquer outro botão irá cancelar a operação\n");

    menu = menuEscolheOpcao();

    printf("Digite o inicio da sequência: ");
    fgets(inicio,9,stdin);
    printf("\nDigite o fim da sequência: ");
    fgets(fim,9,stdin);

    if(menu==0){
      i = strtol(inicio,NULL,10);
      j = strtol(fim,NULL,10);
      if(i<=j){
        while(i<=j){
          int size=strlen(fim);
          char auxChar[size+1];
          sprintf(auxChar,"%d",i);
          auxChar[size]=0;
          size--;
          auxChar[size]=10;
          Elm * new;
          new=elmCriar(auxChar);
          if(new!=NULL){
            abInsert(arvore,new);
          }
            
          i++;
        }
        return TRUE;
      }
    }
    
    else if(menu==1){
      
      if(inicio!=NULL && fim!=NULL){
        //Verifica se foi passado apenas uma letra;
        if(strlen(inicio)==1 && strlen(fim)==1){
          //Verifica se o elemento inicial contem um caractere valido
          if(inicio[0]>=33 && inicio[0]<=126){
            //Verifica se o elemento final contem um caractere valido
            if(fim[0]>=33 && fim[0]<=126){
              menuIncrementaLetra(fim);
              //Looop Até o final
              while(inicio[0]!=fim[0]){
                char auxChar[2];
                strcpy(auxChar,inicio);
                Elm * new;
                new=elmCriar(auxChar);
                if(new!=NULL){
                  abInsert(arvore,new);
                }
                menuIncrementaLetra(inicio);
              }
              return TRUE;
            }
          }
        }
      }
      
    }
  }
  return FALSE;
}

int menuEncontrarElemento(TNode * arvore){
  
  int status=FALSE;
  void * chave=NULL;

  chave = menuDefinirChave(chave);
  if(chave!=NULL){
    status=abQuery(arvore,chave,elmCmp);
  }

  return status;
}

void * menuRemoverElemento(TNode ** arvore){
  if(arvore!=NULL && *arvore!=NULL){
    void * chave, * aux=NULL;

    chave = menuDefinirChave(aux);
    
    if(chave!=NULL){
      aux=abRemove(arvore,chave,elmCmp);
      menuApagarChave(&chave);
      chave=NULL;
      if(aux!=NULL){
        return aux;
      }
    }
  }
  

  return NULL;
}

void * menuDefinirChave(void * chave){
  char * auxChar=NULL, * stringPTR;
  int tam;
  auxChar=(char *)malloc(sizeof(char)*100);
  if(auxChar!=NULL){
    printf("Escreva a chave: ");
    fgets(auxChar,100,stdin);
    tam=strlen(auxChar);
    auxChar[tam-1]=auxChar[tam];
    printf("\n");
  }
  return auxChar;
 
}

void menuApagarChave(void ** chave){
  if(chave!=NULL && *chave!=NULL){
    char * aux;
    aux=*chave;
    free(aux);
    chave=NULL;
    aux=NULL;
  }
}

void menuPrintPreOrdem(TNode * arvore, char * lado, int index,char *(*toString)(Elm *)){
  void * aux;
  
  if(arvore!=NULL){
    TNode * l, * r;
    aux=abGetNodeData(arvore);
    char * auxChar, * newEspaco;
    auxChar = toString(aux);
    l = abGetLeftNode(arvore);
    for(int i=0;i<index;i++){
      printf("  ");
    }
    printf("%s (%d) Nome: %s\n",lado,index,auxChar);

    menuPrintPreOrdem(l,"L",index+1,toString);
    r = abGetRightNode(arvore);
    menuPrintPreOrdem(r,"R",index+1,toString);
  }else{
    for(int i=0;i<index;i++){
      printf("  ");
    }
    printf("%s(%d) - NULL\n",lado,index);
  }
  
}

void menuPrintSimetrico(TNode * arvore, char * lado, int index,char *(*toString)(Elm *)){
  void * aux;
  
  if(arvore!=NULL){
    TNode * l, * r;
    aux=abGetNodeData(arvore);
    char * auxChar, * newEspaco;
    auxChar = toString(aux);
    l = abGetLeftNode(arvore);
    menuPrintSimetrico(l,"L",index+1,toString);

    for(int i=0;i<index;i++){
      printf("  ");
    }
    printf("%s (%d) Nome: %s\n",lado,index,auxChar);
    

    r = abGetRightNode(arvore);
    menuPrintSimetrico(r,"R",index+1,toString);
  }else{
    for(int i=0;i<index;i++){
      printf("  ");
    }
    printf("%s(%d) - NULL\n",lado,index);
  }
  
}

void menuPrintPosOrdem(TNode * arvore, char * lado, int index,char *(*toString)(Elm *)){
  void * aux;
  
  if(arvore!=NULL){
    TNode * l, * r;
    l = abGetLeftNode(arvore);
    menuPrintPosOrdem(l,"L",index+1,toString);

    r = abGetRightNode(arvore);
    menuPrintPosOrdem(r,"R",index+1,toString);
    for(int i=0;i<index;i++){
      printf("  ");
    }
    aux=abGetNodeData(arvore);
    char * auxChar;
    auxChar = toString(aux);
    printf("%s (%d) Nome: %s\n",lado,index,auxChar);
  }else{
    for(int i=0;i<index;i++){
      printf("  ");
    }
    printf("%s(%d) - NULL\n",lado,index);
  }
  
}

void menuPrintSimpPreOrdem(TNode * arvore, char * lado, int index,char *(*toString)(Elm *)){
  void * aux;
  
  if(arvore!=NULL){
    TNode * l, * r;
    aux=abGetNodeData(arvore);
    char * auxChar, * newEspaco;
    auxChar = toString(aux);
    printf("%s (%d) Nome: %s\n",lado,index,auxChar);
    l = abGetLeftNode(arvore);

    menuPrintSimpPreOrdem(l,"L",index+1,toString);
    r = abGetRightNode(arvore);
    menuPrintSimpPreOrdem(r,"R",index+1,toString);
  }
  
}

void menuPrintSimpSimetrico(TNode * arvore, char * lado, int index,char *(*toString)(Elm *)){
  void * aux;
  
  if(arvore!=NULL){
    TNode * l, * r;
    aux=abGetNodeData(arvore);
    char * auxChar, * newEspaco;
    auxChar = toString(aux);
    l = abGetLeftNode(arvore);
    menuPrintSimpSimetrico(l,"L",index+1,toString);
    printf("%s (%d) Nome: %s\n",lado,index,auxChar);
    

    r = abGetRightNode(arvore);
    menuPrintSimpSimetrico(r,"R",index+1,toString);
  }
  
}

void menuPrintSimpPosOrdem(TNode * arvore, char * lado, int index,char *(*toString)(Elm *)){
  void * aux;
  
  if(arvore!=NULL){
    TNode * l, * r;
    l = abGetLeftNode(arvore);
    menuPrintSimpPosOrdem(l,"L",index+1,toString);

    r = abGetRightNode(arvore);
    menuPrintSimpPosOrdem(r,"R",index+1,toString);
    aux=abGetNodeData(arvore);
    char * auxChar;
    auxChar = toString(aux);
    printf("%s (%d) Nome: %s\n",lado,index,auxChar);
  }
  
}

void menuPrintParenPreOrdem(TNode * arvore,char *(*toString)(Elm *)){
  void * aux;
  
  if(arvore!=NULL){
    printf("(");
    TNode * l, * r;
    aux=abGetNodeData(arvore);
    char * auxChar, * newEspaco;
    auxChar = toString(aux);
    printf("%s",auxChar);
    l = abGetLeftNode(arvore);
    menuPrintParenPreOrdem(l,toString);
    r = abGetRightNode(arvore);
    menuPrintParenPreOrdem(r,toString);
    printf(")");
  }
  
}

void menuPrintParenSimetrico(TNode * arvore, char *(*toString)(Elm *)){
  void * aux;
  
  
  if(arvore!=NULL){
    printf("(");
    TNode * l, * r;
    aux=abGetNodeData(arvore);
    char * auxChar, * newEspaco;
    auxChar = toString(aux);
    l = abGetLeftNode(arvore);
    menuPrintParenSimetrico(l,toString);
    printf("%s",auxChar);
    

    r = abGetRightNode(arvore);
    menuPrintParenSimetrico(r,toString);
    printf(")");
  }
  
}

void menuPrintParenPosOrdem(TNode * arvore,char *(*toString)(Elm *)){
  void * aux;
  
  if(arvore!=NULL){
    printf("(");
    TNode * l, * r;
    l = abGetLeftNode(arvore);
    menuPrintParenPosOrdem(l,toString);

    r = abGetRightNode(arvore);
    menuPrintParenPosOrdem(r,toString);
    aux=abGetNodeData(arvore);
    char * auxChar;
    auxChar = toString(aux);
    printf("%s",auxChar);
    printf(")");
  }
  
}

void * menuCriarElm(){
  Elm * new=NULL;
  printf("\nDigite uma string:");
  char string[100];
  fgets(string,99,stdin);
  int size=strlen(string);
  new = elmCriar(string);
  return (void *) new;
}