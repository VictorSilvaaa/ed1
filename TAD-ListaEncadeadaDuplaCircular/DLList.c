

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
  DLNode *newnode,*last;

  if (l != NULL) {
    newnode = (DLNode *)malloc(sizeof(DLNode));
    if (newnode != NULL) {

      newnode->data=data;
      if(l->first==NULL){
        newnode->next=newnode;
        newnode->prev=newnode;
      }else{

        last=l->first;
        last=last->prev;
        
        if(last!=l->first){

          newnode->prev=last;
          newnode->next=l->first;
          last->next=newnode;
          l->first->prev=newnode;
        }else{
          newnode->next=last;
          newnode->prev=last;
          last->next=newnode;
          last->prev=newnode;
        }

      }
      l->first=newnode;
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

      newnode->data=data;
      if(l->first==NULL){
        newnode->next=newnode;
        newnode->prev=newnode;
        l->first=newnode;
      }else{

        last=l->first;
        last=last->prev;
        
        if(last!=l->first){

          newnode->prev=last;
          newnode->next=l->first;
          last->next=newnode;
          l->first->prev=newnode;
        }else{
          newnode->next=last;
          newnode->prev=last;
          last->next=newnode;
          last->prev=newnode;
        }

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

//funcao de remove o primeiro

void * dllRemoveFirst(DLList * l){
  DLNode * first, * second, * last;
  void * data;
  if(l!=NULL & l->first!=NULL){
    first=l->first;
    second=first->next;
    last=first->prev;
    data=first->data;

    if(last !=l->first && second!=l->first){
      last->next=second;
      second->prev=last;
      l->first=second;
    }else{
      l->first=NULL;
    }
    free(first);

    return data;

  }
  return NULL;
}

//**********************************************************************************

//funcao de remove o ultimo

void * dllRemoveLast(DLList * l){
  DLNode * last, * lastPrev, * first;
  void * data;
  if(l!=NULL & l->first!=NULL){
    first=l->first;
    last=first->prev;
    lastPrev=last->prev;
    data=last->data;

    if(last!=first && lastPrev!=first){
      lastPrev->next=last->next;
      first->prev=lastPrev;
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
      while (spec->next != NULL && stat != TRUE && spec->next!=l->first) {
        spec = spec->next;
        stat = cmp(key, spec->data);
      }

      if (stat == TRUE) {
        data=spec->data;
        nextnode=spec->next;
        prevnode=spec->prev;

        if(nextnode!=l->first && prevnode != l->first){
          nextnode->prev=prevnode;
          prevnode->next=nextnode;
          l->first=nextnode;
        }else{
          l->first=NULL;
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
      while (spec->next != NULL && stat != TRUE && spec->next!=l->first) {
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
