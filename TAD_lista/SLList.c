

#ifndef _SLLIST_C_
#define _SLLIST_C_
#include "SLList.h"


//**********************************************************************************

//Função para criar uma lista

//**********************************************************************************

SLList *sllCreate() {
  SLList *l;
  l = (SLList *)malloc(sizeof(SLList));

  if (l != NULL) {

    l->first = NULL;
    l->cur = NULL;
    return l;
  }
  return NULL;
}


//**********************************************************************************

//Função para destruir uma lista

//**********************************************************************************

int sllDestroy(SLList *l) {

  if (l != NULL) {

    if (l->first == NULL) {
      free(l);
      return TRUE;
    }
  }
  return FALSE;
}


//**********************************************************************************

//Função para inserir elemento como o primeiro

//**********************************************************************************

int sllInsertAsFirst(SLList *l, void * data) {
  SLNode *newnode;

  if (l != NULL) {
    newnode = (SLNode *)malloc(sizeof(SLNode));
    if (newnode != NULL) {
      newnode->data = data;
      newnode->next = l->first;
      l->first = newnode;

      return TRUE;
    }
  }
  return FALSE;
}

//**********************************************************************************

//função para inserir elemento como o ultimo elemento

//**********************************************************************************
int sllInsertAsLast(SLList *l, void *data) {
  SLNode *last = NULL, *newnode;
  if (l != NULL) {
    newnode = (SLNode *)malloc(sizeof(SLNode));
    if (newnode != NULL) {

      newnode->data = data;
      newnode->next = NULL;
      if(l->first == NULL){
        l->first = newnode;
      }else{
        last = l->first;
        while(last->next!=NULL){
          last=last->next;
        }
        last->next=newnode;
      }
      return TRUE;
    }
  }
  return FALSE;
}


//**********************************************************************************

//Função para obter o primeiro elemento

//**********************************************************************************

void *sllGetFirst(SLList *l) {
  if (l != NULL) {
    if(l->first!=NULL){
      SLNode *first;
      first = l->first;
      l->cur = first;
      return first->data;
    }
  }
  return NULL;
}


//**********************************************************************************

//Função para obter o próximo elemento

//**********************************************************************************

void *sllGetNext(SLList *l) {
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

//Função para remover o primeiro elemento

//**********************************************************************************
void * sllRemoveFirst(SLList *l){
  SLNode * first;
  void * data;
  if(l!=NULL){
    first=l->first;
    data=first->data;
    l->first=first->next;
    free(first);
    return data;
  }
  return NULL;
}

//**********************************************************************************

//Função para remover o último elemento

//**********************************************************************************

void * sllRemoveLast(SLList * l){
  SLNode * last, * prevLast=NULL;
  void * data;
  if(l!=NULL && l->first!=NULL){
    last=l->first;
    while(last->next!=NULL){
      prevLast=last;
      last=last->next;
    }

    data=last->data;
    free(last);

    if(prevLast!=NULL){
      prevLast->next=NULL;
    }
    return data;
  }
  return NULL;
}

//**********************************************************************************

//função de remoção de um elemento especifico

//**********************************************************************************
void *sllRemoveSpec(SLList *l, void *key, int (*cmp)(void *, void *)) {
  SLNode *prevnode, *nextnode, *spec;
  int stat;
  void *data;
  if (l != NULL) {
    if (l->first != NULL) {
      spec = l->first;
      stat = cmp(key, spec->data);
      prevnode = NULL;
      while (spec->next != NULL && stat != TRUE) {
        prevnode = spec;
        spec = spec->next;
        stat = cmp(key, spec->data);
      }

      if (stat == TRUE) {
        nextnode = spec->next;
        data = spec->data;

        if (prevnode != NULL) {
          prevnode->next = nextnode;

        } else {
          l->first = nextnode;
        }

        free(spec);
        return data;
      }
    }
  }
  return NULL;
}

//**********************************************************************************

//função de pesquisa

//**********************************************************************************
void *sllQuery(SLList *l, void *key, int (*cmp)(void *, void *)) {
  SLNode *spec;
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

//função para limpar a lista

//**********************************************************************************

int sllCleanList(SLList * l){
  SLNode * aux;
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


//**********************************************************************************

//Verificar numero de elementos da lista

//**********************************************************************************


int sllNElms(SLList * l){
  SLNode * last;
  int n=0;
  if(l!=NULL){
    if(l->first!=NULL){
      last = l->first;
      n++;
      while(last->next!=NULL){
        last=last->next;
        n++;
      }
      return n;
    }
  }
  return -1;
}


//**********************************************************************************

//Obter o último elemento da lista

//**********************************************************************************

void * sllGetLast(SLList * l){
  SLNode * last;
  void * data;
  if(l!=NULL){
    if(l->first!=NULL){
      last = l->first;
      while(last->next!=NULL){
        last=last->next;
      }
      data = last->data;
      return data;
    }
  }
  return NULL;
}


//**********************************************************************************

//Inserir elemento na posição p da lista

//**********************************************************************************

int sllInsertPEsimo (SLList * l, int p, void * data){
	SLNode * spec, * newnode; int i=0;
	if(l != NULL && l->first != NULL && p>=0){
		spec = l->first;
		while(i<p && spec->next != NULL){
			spec = spec->next;
			i++;
		}
		if(i==p){
			newnode = (SLNode *) malloc (sizeof(SLNode));
			if(newnode != NULL){
				newnode->data = data;
				newnode->next = spec->next;
				spec->next = newnode;
				return TRUE;
			}
		}
	}return FALSE;
}


//**********************************************************************************

//Inserir antes de um elemento específico da lista

//**********************************************************************************
int sllInsertAfterSpec(SLList * l, void * key, int (*cmp)(void *, void *),void * data){
	SLNode * spec, * newnode;
	if(l!=NULL && l->first !=NULL){
		spec = l->first;
		int stat = cmp(key,spec->data);
		while(stat != TRUE && spec->next != NULL){
			spec = spec->next;
			stat = cmp (key, spec->data);
		}
		if(stat == TRUE){
			newnode = (SLNode *)malloc(sizeof(SLNode));
			if(newnode != NULL){
				newnode->data = data;
				newnode->next = spec->next;
				spec->next = newnode;
				return TRUE;
			}
		}
	} return FALSE; 
}


//**********************************************************************************

//Inserir depois de um elemento específico da lista

//**********************************************************************************
int sllInsertBeforeSpec(SLList * l, void * key, int (*cmp)(void *, void *), void * data){
	SLNode * spec, * newnode, * prev; int stat;
	if(l != NULL && l->first != NULL){
		spec = l->first; prev = NULL;
		stat = cmp(spec->data,key);
		while (spec->next != NULL && stat != TRUE){
			prev = spec;
			spec = spec->next;
			stat = cmp(spec->data, key);
		}
		if(stat == TRUE){
			newnode = (SLNode *)malloc(sizeof(SLNode));
			if (newnode != NULL){
				newnode->data = data;
				newnode->next = spec;
				if(prev != NULL){
					prev->next = newnode;
				} else{
					l->first = newnode;
				} 
        return TRUE;
			}
		}
	}return FALSE;
}



//**********************************************************************************

//Respostas de Questões

//**********************************************************************************

void * sllRetornaMaior(SLList * l, int (*cmp)(void *,void *)){
  if(l!=NULL && l->first !=NULL){
    SLNode * aux, * next;
    void * maior;
    int status=FALSE;
    aux=l->first;
    maior=aux->data;
    while(aux->next!=NULL){
      aux=aux->next;
      status = cmp(aux->data,maior);
      if(status==TRUE){
        maior=aux->data;
      }
    }
    return maior;
  }
  return NULL;
}

int sllContaAparicoes(SLList * l, void * key, int (*cmp)(void *, void *)){
  int cont=0;
  int status=FALSE;
  if(l!=NULL){
    SLNode * aux;
    aux=l->first;
    while(aux!=NULL){
      status = cmp(aux->data,key);
      if(status==TRUE){
        cont++;
      }
      aux=aux->next;
    }
  }
  return cont;
}

int sllAdicionaNumeros(SLList * l, int * nums, int tam){
  SLNode * last;
  if(l!=NULL && nums !=NULL && tam>0){
    if(l->first!=NULL){
      last=l->first;
      while(last->next!=NULL){
        last=last->next;
      }
    }
    for(int i=0;i<tam;i++){
      SLNode * newnode;
      newnode=(SLNode *)malloc(sizeof(SLNode));
      if(newnode!=NULL){
        newnode->data=&nums[i];
        if(last!=NULL){
          last->next=newnode;
          last=last->next;
        }else{
          l->first=newnode;
          last=l->first;
        }
      }
    }
    return TRUE;
  }
  return FALSE;
}

int sllAdicionaPares(SLList * l, int * nums, int tam){
  SLNode * last;
  if(l!=NULL && nums !=NULL && tam>0){
    if(l->first!=NULL){
      last=l->first;
      while(last->next!=NULL){
        last=last->next;
      }
    }
    for(int i=0;i<tam;i++){
      if(nums[i]%2==0){
        SLNode * newnode;
        newnode=(SLNode *)malloc(sizeof(SLNode));
        if(newnode!=NULL){
          newnode->data=&nums[i];
          if(last!=NULL){
            last->next=newnode;
            last=last->next;
          }else{
            l->first=newnode;
            last=l->first;
          }
        }
      }
    }
    return TRUE;
  }
  return FALSE;
}

int sllAdicionaImpares(SLList * l, int * nums, int tam){
  SLNode * last;
  if(l!=NULL && nums !=NULL && tam>0){
    if(l->first!=NULL){
      last=l->first;
      while(last->next!=NULL){
        last=last->next;
      }
    }
    for(int i=0;i<tam;i++){
      if(nums[i]%2>0){
        SLNode * newnode;
        newnode=(SLNode *)malloc(sizeof(SLNode));
        if(newnode!=NULL){
          newnode->data=&nums[i];
          if(last!=NULL){
            last->next=newnode;
            last=last->next;
          }else{
            l->first=newnode;
            last=l->first;
          }
        }
      }
    }
    return TRUE;
  }
  return FALSE;
}

SLList * sllConectarListas(SLList * l1, SLList * l2){
  if(l1!=NULL && l2!=NULL){
    SLNode * node1, * node2, * aux;
    node1=l1->first;
    node2=l2->first;
    if(node1!=NULL || node2!=NULL){
      SLList * novaLista;
      novaLista=(SLList *)malloc(sizeof(SLList));
      if(novaLista!=NULL){
        aux=novaLista->first;
        if(node1!=NULL){
          novaLista->first=node1;
          while(node1->next!=NULL){
            node1=node1->next;
          }
        }else{
          novaLista->first=node2;
        }

        if(novaLista->first==l1->first){
          while(aux->next!=NULL){
            aux=aux->next;
          }

          aux->next=l2->first;
        }

        if(novaLista->first!=NULL){
          return novaLista;
        }

      }
    }
  }
  return NULL;
}

int sllAdicionarNode(SLNode * nodeAdd, SLList * l){

  if(nodeAdd!=NULL && l!=NULL){
    if(l->first==NULL){
      l->first=nodeAdd;
      l->cur=l->first;
      return TRUE;
    }else if(l->cur==NULL ){
      l->cur=l->first;
      while(l->cur->next!=NULL){
        l->cur=l->cur->next;
      }
    }
    
    l->cur->next=nodeAdd;
    l->cur=l->cur->next;
    return TRUE;
  }
  return FALSE;
}

SLList * sllJuntarListasManual(SLList * l1, SLList * l2){
  SLList * novaLista;
  SLNode * node1,* node2, *aux;
  if(l1!=NULL && l2!= NULL && l1->first!=NULL && l2->first!=NULL){
    novaLista=(SLList *)malloc(sizeof(SLList));
    if(novaLista!=NULL){
      node1=l1->first;
      node2=l2->first;
      if(node1!=NULL){
        novaLista->first=node1;
        node1=node1->next;
      } else if(node2!=NULL){
        novaLista->first=node2;
        node2=node2->next;
      }
      aux=novaLista->first;
      while(node1!=NULL || node2 !=NULL){
        if(node2!=NULL){
          aux->next=node2;
          aux=aux->next;
          node2=node2->next; 
        }

        if(node1!=NULL){
          aux->next=node1;
          aux=aux->next;
          node1=node1->next;
        }
      }

      if(novaLista->first!=NULL){
        return novaLista;
      }
    }
  }
  return NULL;
}

SLList * sllJuntarListas(SLList * l1, SLList * l2){
  SLList * novaLista;
  SLNode * node1,* node2, *aux;
  if(l1!=NULL && l2!= NULL && l1->first!=NULL && l2->first!=NULL){
    novaLista=sllCreate();
    if(novaLista!=NULL){
      node1=l1->first;
      node2=l2->first;
      if(node1!=NULL){
        sllAdicionarNode(node1,novaLista);
        node1=node1->next;
      } else if(node2!=NULL){
        sllAdicionarNode(node2,novaLista);
        node2=node2->next;
        
      }
      
      while(node1!=NULL || node2 !=NULL){
        if(node2!=NULL){
          sllAdicionarNode(node2,novaLista);
          node2=node2->next;
        }

        if(node1!=NULL){
          sllAdicionarNode(node1,novaLista);
          node1=node1->next;
        }

      }

      if(novaLista->first!=NULL){
        novaLista->cur=NULL;
        return novaLista;
      }
    }
  }
  return NULL;
}

SLList * sllJuntarListasCondicao(SLList * l1, SLList * l2,int (*cmp)(void *)){
  SLList * novaLista;
  SLNode * node1,* node2, *aux;
  int status=FALSE;
  if(l1!=NULL && l2!= NULL){
    novaLista=sllCreate();
    if(novaLista!=NULL){
      node1=l1->first;
      node2=l2->first;
      status=cmp(node1->data);
      if(node1!=NULL){
        status=cmp(node1->data);
        if(status==TRUE){
          sllAdicionarNode(node1,novaLista);
          
        }
        node1=node1->next;
      }else{
        if(node2!=NULL){
          status=cmp(node2->data);
          if(status==TRUE){
            sllAdicionarNode(node2,novaLista);
          }
          node2=node2->next;
        }
        
        
      }
      
      while(node1!=NULL || node2 !=NULL){
        
        if(node2!=NULL){
          status=cmp(node2->data);
          if(status==TRUE){
            sllAdicionarNode(node2,novaLista);
          }
          node2=node2->next;
        }

        

        if(node1!=NULL){
          status=cmp(node1->data);
          if(status==TRUE){
            sllAdicionarNode(node1,novaLista);
            
          }
          node1=node1->next;
        }
        novaLista->cur->next=NULL;

      }

      if(novaLista->first!=NULL){
        return novaLista;
      }
    }
  }
  return NULL;
}

int sllMantemElmsContidoNasDuasListas(SLList * l1,SLList * l2,int (*cmp)(void *, void *)){
  SLNode * node1, * node2, * node1prev=NULL;
  int status;
  if(l1!=NULL && l2!=NULL){
    if(l1->first!=NULL){
      node1=l1->first;
      while(node1!=NULL){
        status=FALSE;
        node2=l2->first;
        while(node2!=NULL && status==FALSE){
          status=cmp(node1->data,node2->data);
          node2=node2->next;
        }
        
        if(status==FALSE){
          if(node1==l1->first){
            l1->first=node1->next;
            free(node1);
            node1=NULL;
          }else{
            node1prev->next=node1->next;
            free(node1);
            node1=node1prev;
          }
        }

        node1prev=node1;

        if(node1!=NULL){
          node1=node1->next;
        }else {
          node1=l1->first;
        }

        
        
      }

      return TRUE;    
    }
    

  }


  return FALSE;
}

int sllRemoveElmsContidoNasDuasListas(SLList * l1,SLList * l2,int (*cmp)(void *, void *)){
  SLNode * node1, * node2, * node1prev=NULL;
  int status;
  if(l1!=NULL && l2!=NULL){
    if(l1->first!=NULL){
      node1=l1->first;
      while(node1!=NULL){
        status=FALSE;
        node2=l2->first;
        while(node2!=NULL && status==FALSE){
          status=cmp(node1->data,node2->data);
          node2=node2->next;
        }
        
        if(status==TRUE){
          if(node1==l1->first){
            l1->first=node1->next;
            free(node1);
            node1=NULL;
          }else{
            node1prev->next=node1->next;
            free(node1);
            node1=node1prev;
          }
        }

        node1prev=node1;

        if(node1!=NULL){
          node1=node1->next;
        }else {
          node1=l1->first;
        }

        
        
      }

      return TRUE;    
    }
    

  }


  return FALSE;
}

int sllRemoverElmsRepetidos(SLList * l1, int (*cmp)(void *, void *)){
  int status=FALSE;
  SLNode * aux=NULL, * curNode, * nextNode, *prevNode=NULL;

  if(l1!=NULL && l1->first!=NULL){
    curNode = l1->first;
    while(curNode!=NULL){
      aux=l1->first;
      while(aux!=NULL){
        status =cmp(curNode, aux);
        if(status==TRUE){
          break;
        }
        aux=aux->next;
      }

      nextNode=curNode->next;
      if(status==TRUE){
        if(prevNode==NULL){
          l1->first=nextNode;
        }else{
          prevNode->next=nextNode;
        }

        free(curNode);
      }else{
        prevNode=curNode;
      }
      
      curNode=nextNode;
    }
    return TRUE;
  }
  return FALSE;
}


int sllMantemElmsRepetidos(SLList * l1, int (*cmp)(void *, void *)){
  int status=FALSE, cont=0;
  SLNode * aux=NULL, * curNode, * nextNode, *prevNode;

  if(l1!=NULL && l1->first!=NULL){
    curNode = l1->first;
    while(curNode!=NULL){
      aux=l1->first;
      while(aux!=NULL){
        status =cmp(curNode, aux);
        if(status==TRUE){
          break;
        }
        aux=aux->next;
      }

      nextNode=curNode->next;
      if(status==FALSE){
        if(prevNode==NULL){
          l1->first=nextNode;
        }else{
          prevNode->next=nextNode;
        }

        free(curNode);
      }else{
        prevNode=curNode;
      }
      
      curNode=nextNode;
    }
    return TRUE;
  }
  return FALSE;
}

int sllRemoveElementosRepitidos(SLList * l1,SLList * l2,int (*cmp)(void *, void *)){
  int status=FALSE;
  SLNode * aux=NULL, * curNode, * nextNode, *prevNode=NULL;

  if(l1!=NULL && l1->first!=NULL){
    curNode = l1->first;
    while(curNode!=NULL){
      aux=l1->first;
      while(aux!=NULL){
        status =cmp(curNode, aux);
        if(status==TRUE){
          break;
        }
        aux=aux->next;
      }

      nextNode=curNode->next;
      if(status==TRUE){
        if(prevNode==NULL){
          l1->first=nextNode;
        }else{
          prevNode->next=nextNode;
        }

        free(curNode);
      }else{
        prevNode=curNode;
      }
      
      curNode=nextNode;
    }
    return TRUE;
  }
  return FALSE;
}




#endif