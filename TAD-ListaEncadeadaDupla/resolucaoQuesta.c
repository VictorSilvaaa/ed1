#include "DLList.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int separarLista(Dllist **lista){
    DLList** l1, **l2;
    if(lista!=NULL){
        if(lista->first!=NULL){
            DLNode* curr, *currl1, *currl2;
            curr = lista->first;
            int cont;
            while(curr->next!=NULL){
                if(cont%2==0){
                    currl1 = l1->first;
                    while(currl1->next != NULL) {
                        currl1 = currl1->next;
                    }
                    //insere novo elemento no final da lista
                    currl1->next = curr;
                }else{
                    currl2 = l2->first;
                    while(currl2->next != NULL) {
                        currl2 = currl2->next;
                    }
                    //insere novo elemento no final da lista
                    currl2->next = curr;
                }
                cont++;
            }
        }
    }
}