#include <stdio.h>
#include "cofo.h"

int main(){
    int flag =0, elemento=0 ,maxItens=0;
    while(flag==0){
        int resp;
        struct Cofo* cofo;
        printf("\nDigite numero da opcao que deseja: \n1 - Criar um cofo \n2- inserir no cofo \n3- remover elemento do cofo \n4- Consultar elemento no cofo \n5- Destruir elemento do cofo \n6 - imprimir cofo \n7- fechar programa\n");
        scanf("%d", &resp);
        switch (resp)
        {
        case 1:
        // criar um cofo
            printf("\n\nDigite maxItens: ");
            scanf("%d", &maxItens);
            cofo = criarCofo(maxItens);
            if(cofo != NULL){
                printf("\nCofo criado com sucesso\n");
            };
            break;
        case 2:
        // adicionar elemento num cofo
            if(cofo != NULL){
                printf("\nDigite elemento que deseja adicionar: ");
                scanf("%d", &elemento);
                if(adicionaNumCofo(cofo, elemento)==1){
                    printf("\nElemento adicionado com sucesso\n");
                }else{
                    printf("\nElemento nao adicionado com sucesso\n");
                };
            };
            break;
        case 3:
        // remover elemento do cofo
            printf("\nDigite elemento que deseja remover: ");
            scanf("%d", &elemento);
            int pos = verificaNumCofo(cofo, elemento);
            if(pos != -1){
                if(removerNumCofo(cofo, elemento)==1){
                    printf("\nElemento removido com sucesso\n");
                }else{
                    printf("\nElemento nao removido com sucesso\n");
                };
            }else{
                printf("\nElemento digitado não encontrado no cofo");
            }
            break;
        case 4:
        // consultar elemento no cofo
            printf("\nDigite elemento que deseja consultar: ");
            scanf("%d", &elemento);
            if(verificaNumCofo(cofo, elemento)!= -1){
                printf("\nElemento esta presente no cofo\n");
            }else{
                printf("\nElemento nao está presente no cofo\n");
            };
            break;
        case 5:
        // Destruir elemento do cofo
            if(destruircofo(cofo)!= -1){
                printf("\nCofo destruido com sucesso");
            }else{
                printf("\nCofo nao vazio para destruir\n");
            }
            break;
        case 6:
            imprimeItens(cofo);
            break;
        default:
            printf("fechando.........");
            flag = 1;
            break;
        }
    }

    return 0;
}