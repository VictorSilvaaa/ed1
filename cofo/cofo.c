#include <stdio.h>
#include <stdlib.h>

struct Cofo{
    int numItens;
    int maxItens;
    int *item;
};

struct Cofo *criarCofo( int maxItens){
    struct Cofo *c;
    if ( maxItens >0 ){
        c = (struct Cofo *) malloc ( sizeof (struct Cofo));
        if ( c != NULL ){
            c->item = (int *) malloc (sizeof (int) * maxItens);
            if (c->item != NULL){
                c->numItens=0;
                c->maxItens = maxItens;
                return c;
            }
            free(c);
        }
    }
    return NULL;
}
int adicionaNumCofo(struct Cofo* c, int num){
    if(c!=NULL){
        if(c->numItens < c->maxItens){
            c->item[c->numItens] = num;
            c->numItens++;
            return 1;
        }
    }
    return 0;
}
int verificaNumCofo(struct Cofo* c, int num){
    for(int i=0; i<c->numItens; i++){
        if(c->item[i] == num){
            return i;
        }
    }
    return -1;
}
int removerNumCofo(struct Cofo* c, int num){
    if(c!= NULL){
        int pos = verificaNumCofo(c, num);
        if(pos >-1){
            for(int i=pos; i<c->numItens-1 ;i++){
                c->item[i] = c->item[i+1];
            }
            c->numItens--;
            return 1;
        }
    }
    return 0;
}
int destruircofo(struct Cofo* c){
    if(c!=NULL){
        if(c->numItens==0){
            free(c->item);
            free(c);
            return 1;
        }
    }
    return 0;
}
void imprimeItens(struct Cofo* c){
    printf("{");
    printf("%d", c->item[0]);
    for(int i=1; i< c->numItens; i++){
        printf(", %d", c->item[i]);
    }
    printf(" }\n");
}


