#include "gStack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 7
#define TRUE 0
#define FALSE 1
#include <time.h>

typedef struct {
  int x;
  int y;
} Point;

void imprimirMatriz(int* matriz, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int indice = i * n + j; // Calcula o índice correspondente no vetor
            printf("%d ", matriz[indice]);
        }
        printf("\n");
    }
}

int preencherRegiao(int* matriz, int n, int numAlvo, Point* pontoInicial) {
  int numInicial = matriz[pontoInicial->y*n + pontoInicial->x];
  Stack* stack = stkCreate(MAX_SIZE);
  if(stack!=NULL){
     stkPush(stack, (void*)pontoInicial);

    while (!stkIsEmpty(stack)){
      Point* ponto = (Point*)stkPop(stack);
      matriz[ponto->y*n + ponto->x] = numAlvo;
      //acima
      if ((ponto->y)-1>= 0 && matriz[((ponto->y)-1)*n + ponto->x] == numInicial) {
        Point vizinhoAcima = {.y = (ponto->y)-1 , .x= ponto->x};
        stkPush(stack, (void*) &vizinhoAcima);
      }
      //Abaixo
      if ((ponto->y)+1< n && matriz[((ponto->y)+1)*n + ponto->x] == numInicial) {
        Point vizinhoAbaixo = {.y = (ponto->y)+1 , .x=  ponto->x};
        stkPush(stack, (void*) &vizinhoAbaixo);
      }
      //esquerda
      if (ponto->x-1>= 0 && matriz[(ponto->y)*n + (ponto->x)-1] == numInicial) {
        Point vizinhoEsquerda = {.y =ponto->y , .x= (ponto->x)-1};
        stkPush(stack, (void*) &vizinhoEsquerda);
      }
      //direita
      if (ponto->x+1 < n && matriz[(ponto->y)*n + (ponto->x)+1] == numInicial) {
        Point vizinhoDireita = {.y =ponto->y , .x= (ponto->x)+1};
        stkPush(stack, (void*) &vizinhoDireita);
      }
    }
    return 1;
  }else{
    printf("Pilha nao criada");
    return 0;
  }
  
}



int main(void) {
  srand(time(NULL));
  int *matriz = (int*) malloc(sizeof(int)*MAX_SIZE*MAX_SIZE);
  for(int i=0; i<MAX_SIZE; i++){
    for(int j=0; j<MAX_SIZE; j++){
      matriz[i*MAX_SIZE+j] = rand() % 10;
    }
  }
  //forçando aparecer um exemplo bom para demonstrar
  matriz[2] = 3;
  matriz[1*MAX_SIZE + 2] = 3;
  matriz[2*MAX_SIZE + 2] = 3;
  matriz[1*MAX_SIZE + 1] = 3;
  matriz[1*MAX_SIZE + 3] = 3;

  imprimirMatriz(matriz, MAX_SIZE);
  printf("\n=================\n");

  Point pontoInicial;
  int numAlvo;
  printf("Digite a posicao x e y: ");
  scanf("%d %d", &pontoInicial.x, &pontoInicial.y);
  printf("\nDigite valor que vai ser colocado: ");
  scanf("%d", &numAlvo);

  printf("%d", preencherRegiao(matriz, MAX_SIZE, numAlvo, &pontoInicial));
  printf("\n=================\n");
  imprimirMatriz(matriz, MAX_SIZE);

  return 0;
}