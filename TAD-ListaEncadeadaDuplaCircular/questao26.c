#include "DLList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int diferencaL1eL2(DLList *l1,DLList *l2, int (*cmp)(void *, void *)){
    DLNode *spec; int  stat = FALSE;
    DLList * l;
    if (l1 != NULL && l2 != NULL ) {
        if (l1->first != NULL) {
            curr1 =	l1->first;
            curr2 = = l2->first;
            curr3 = NULL;
            while(curr1->next != NULL) {
                stat = FALSE; 
                while(curr2->next != NULL && TRUE) {
                    stat = cmp (curr1, curr2);
                }
                if(stat == FALSE){
                    if(l->first==NULL){
                        l->first = curr1;
                    }else{
                        curr3 = l->first;
                        while(curr3->next != NULL){
                            curr3 = curr3->next;
                        }
                        curr3->next = curr1;
                    }
                }     
         
        }
    }
    return l;
