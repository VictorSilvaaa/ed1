#include "DLList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int separa(DLList *l, void *key, int (*cmp)(void *, void *)){
    DLNode *spec; int  stat = FALSE;
    DLList *l2;
    if (l != NULL) {
        if (l->first != NULL) {
            spec =	l->first;
            stat = cmp (key, spec->data);
            while (spec->next != l->first && stat != TRUE) {
                spec = spec->next;
                stat = cmp (key, spec->data);
            }
            spec->next = l->first;
            if(stat== TRUE){
                l2->first = spec->next;
                curr = l2->first;
                while (curr->next != l2->first) {
                    curr = curr->next;
                }
                curr->next = l2->first;
            }
            }
        }
    }
    return l2;
