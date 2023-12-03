

#ifndef _DLLIST_C_
#define _DLLIST_C_
#include "DLList.h"

//**********************************************************************************

//**********************************************************************************

DLList *dllCreate() {
  DLList *l;
  l = (DLList *)malloc(sizeof(DLList));

  if (l != NULL) {

    l->first = NULL;
    l->cur = NULL;
    return l;
  }
  return NULL;
}

//**********************************************************************************

int dllDestroy(DLList *l) {

  if (l != NULL) {

    if (l->first == NULL) {
      free(l);
      return TRUE;
    }
  }
  return FALSE;
}

//**********************************************************************************

int dllInsertAsFirst(DLList *l, void *data) {
  DLNode *newnode;

  if (l != NULL) {
    newnode = (DLNode *)malloc(sizeof(DLNode));
    if (newnode != NULL) {

      newnode->data = data;
      newnode->prev = NULL;
      newnode->next = l->first;

      if (l->first != NULL) {
        l->first->prev = newnode;
      }

      l->first = newnode;
      return TRUE;
    }
  }
  return FALSE;
}

//**********************************************************************************

int dllInsertAsLast(DLList *l, void *data) {
  DLNode *last = NULL;
  DLNode *newnode;
  if (l != NULL) {
    newnode = (DLNode *)malloc(sizeof(DLNode));

    if (newnode != NULL) {

      newnode->data = data;
      newnode->next = NULL;

      if (l->first != NULL) {

        last = l->first;
        while (last->next != NULL) {
          last = last->next;
        }
      }

      newnode->prev = last;

      if (last != NULL) {
        last->next = newnode;
      } else {
        l->first = newnode;
      }
      return TRUE;
    }
  }
  return FALSE;
}

//**********************************************************************************

void *dllGetFirst(DLList *l) {
  if (l != NULL) {
    if(l->first!=NULL){
      DLNode *first;
      first = l->first;
      l->cur = first;
      return first->data;
    }
  }
  return NULL;
}

//**********************************************************************************

void *dllGetNext(DLList *l) {
  if (l != NULL) {
    if (l->cur != NULL) {
      l->cur = l->cur->next;
      if(l->cur!=NULL){
        return l->cur->data;
      }
    }
  }
  return NULL;
}

//**********************************************************************************

//funcao de inserir um elemento depois do especificado
int dllInsertAfterSpec(DLList *l, void *key, void *data,int (*cmp)(void *, void *)){
  DLNode *spec, *newnode, *next;
  int stat;

  if (l != NULL) {
    if (l->first != NULL) {
      spec = l->first;
      stat = cmp(key, spec->data);
      while (spec->next != NULL && stat != TRUE) {
        spec = spec->next;
        stat = cmp(key, spec->data);
      }
      if (stat == TRUE) {
        newnode = (DLNode *)malloc(sizeof(DLNode));

        if (newnode != NULL) {
          newnode->data = data;
          newnode->prev = spec;
          next = spec->next;
          newnode->next = next;

          if (next != NULL) {
            next->prev = newnode;
          }
          spec->next = newnode;
          return TRUE;
        }
      }
    }
  }
  return FALSE;
}

//**********************************************************************************

//funcao de inserir um elemento antes do especificado
int dllInsertBeforeSpec(DLList *l, void *key, void *data,int (*cmp)(void *, void *)) {
  DLNode *spec, *newnode, *prev;
  int stat;

  if (l != NULL) {
    if (l->first != NULL){
      spec = l->first;
      stat = cmp(key, spec->data);
      while (spec->next != NULL && stat != TRUE) {
        spec = spec->next;
        stat = cmp(key, spec->data);
      }
      if (stat == TRUE) {
        newnode = (DLNode *)malloc(sizeof(DLNode));

        if (newnode != NULL) {
          newnode->data = data;
          newnode->next = spec;
          prev = spec->prev;
          newnode->prev = prev;

          if (prev == NULL) {

            l->first = newnode;

          } else {

            prev->next = newnode;
          }

          spec->prev = newnode;
          return TRUE;
        }
      }
    }
  }
  return FALSE;
}


//**********************************************************************************

//funcao de remove o primeiro

void * dllRemoveFirst(DLList * l){
  DLNode * first, * second;
  void * data;
  if(l!=NULL & l->first!=NULL){
    first=l->first;
    data=first->data;
    l->first=first->next;
    free(first);

    if(l->first!=NULL){
      first=l->first;
      first->prev=NULL;
    }

    return data;

  }
  return NULL;
}

//**********************************************************************************

//funcao de remove o ultimo

void * dllRemoveLast(DLList * l){
  DLNode * last, * lastPrev;
  void * data;
  if(l!=NULL & l->first!=NULL){
    last=l->first;

    while(last->next!=NULL){
      last=last->next;
    }

    data=last->data;

    if(last->prev!=NULL){
      lastPrev=last->prev;
      lastPrev->next=NULL;
    }else{
      l->first=NULL;
    }

    free(last);

    return data;

  }
  return NULL;
}


//**********************************************************************************

//funcao de remocao
void *dllRemoveSpec(DLList *l, void *key, int (*cmp)(void *, void *)) {
  DLNode *prevnode, *nextnode, *spec;
  int stat;
  void *data;
  if (l != NULL) {
    if (l->first != NULL) {
      spec = l->first;
      stat = cmp(key, spec->data);
      while (spec->next != NULL && stat != TRUE) {
        spec = spec->next;
        stat = cmp(key, spec->data);
      }

      if (stat == TRUE) {
        nextnode = spec->next;
        prevnode = spec->prev;
        data = spec->data;

        if (prevnode != NULL) {

          prevnode->next = nextnode;

        } else {
          l->first = nextnode;
        }

        if (nextnode != NULL) {
          nextnode->prev = prevnode;
        }

        free(spec);
        return data;
      }
    }
  }
  return NULL;
}

//**********************************************************************************

//funcao de pesquisa
void *dllQuery(DLList *l, void *key, int (*cmp)(void *, void *)) {
  DLNode *spec;
  int stat;

  if (l != NULL) {
    if (l->first != NULL) {
      spec = l->first;
      stat = cmp(spec->data, key);
      while (spec->next != NULL && stat != TRUE) {
        spec = spec->next;
        stat = cmp(key, spec->data);
      }
    
      if (stat == TRUE){
        return spec->data;
      }
    }
  }
  return NULL;
}

//**********************************************************************************

int dllCleanList(DLList * l){
  DLNode * aux;
  if(l!=NULL){
    if(l->first!=NULL){
      l->cur=l->first;
      aux=l->cur;
      l->cur=aux->next;
      free(aux->data);
      free(aux);

      while(l->cur!=NULL){
        aux=l->cur;
        l->cur=aux->next;
        free(aux->data);
        free(aux);
      }
      l->first=NULL;
      l->cur=NULL;
      return TRUE;
    }
  }
  return FALSE;
}

#endif
