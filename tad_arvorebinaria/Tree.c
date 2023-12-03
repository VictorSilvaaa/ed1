

#ifndef _TREE_C_
#define _TREE_C_
#include "Tree.h"
#include "elm.h"

//**********************************************************************************

TNode * abCreate(){
    TNode * t;
    t = (TNode*) malloc(sizeof(TNode));
    if(t!=NULL){
      t->data=NULL;
      t->left=NULL;
      t->right=NULL;
    }
    return t;
}


//**********************************************************************************

int abInsertLeft(TNode * t,void * data){
  int status = FALSE;
  TNode * newNode;
  if(t!=NULL){
    if(t->data==NULL){
      t->data=data;
      return TRUE;
    }else{
      if(t->left!=NULL){
        return abInsertLeft(t->left,data);
      }else{
        newNode = abCreate();
        newNode->data=data;
        t->left=newNode;
        return TRUE;
      }
    }
  }
  return FALSE;
}

//**********************************************************************************

int abInsertRight(TNode * t,void * data){
  int status = FALSE;
  TNode * newNode;
  if(t!=NULL){
    if(t->data==NULL){
      t->data=data;
      return TRUE;
    }else{
      if(t->right!=NULL){
        return abInsertLeft(t->right,data);
      }else{
        newNode = abCreate();
        newNode->data=data;
        t->right=newNode;
        return TRUE;
      }
    }
  }
  return FALSE;
}

//**********************************************************************************

int abInsert(TNode * t, void * data){
  TNode * newNode;
  int l=0, r=0;
  if(t!=NULL){
    if(t->data==NULL){
      t->data=data;
      return TRUE;
    }else {
      l = abNNos(t->left);
      r = abNNos(t->right);
    }

    
    if(l>r){
      if(r==0){
        t->right=abCreate();
      }
      return abInsert(t->right,data);

    }else if(r>=l){
      if(r==0){
        t->left=abCreate();
      }
      
      return abInsert(t->left,data);
      
    }
  }
  return FALSE;
}
//**********************************************************************************
int abInsertV2(TNode *t,void * data){
  TNode * newNode,* auxNode=NULL;
  int * indexRes; int i=0;
  indexRes=&i;
  if(t!=NULL && data!=NULL){

    if(t->data==NULL){
      t->data=data;
      return TRUE;
    }
    abBuscaNode(t,&auxNode,0,indexRes);
    if(auxNode!=NULL){
      newNode=abCreate();
      newNode->data=data;

      if(auxNode->left==NULL){
        auxNode->left=newNode;
      }else if(auxNode->right==NULL){
        auxNode->right=newNode;
      }

      return TRUE;
    }
  }
  return  FALSE;
}
//**********************************************************************************
void abBuscaNode(TNode * t,TNode ** res,int index, int * indexRes){
  if(t!=NULL && index>=0){
    if(*indexRes==0 || index<*indexRes){
      if(t->left==NULL || t->right==NULL){
        *indexRes=index;
        *res=t;
      }else{
        if(t->left!=NULL){
          abBuscaNode(t->left,res,index+1,indexRes);
        }
        if(t->right!=NULL){
          abBuscaNode(t->right,res,index+1,indexRes);
        }
      }
    }
  }
}
TNode * abGetLeftNode(TNode * t){
  if(t!=NULL){
    return t->left;
  }
}

//**********************************************************************************

TNode * abGetRightNode(TNode * t){
  if(t!=NULL){
    return t->right;
  }
}

//**********************************************************************************

void * abGetNodeData(TNode * t){
  if(t!=NULL && t->data!=NULL){
    return t->data;
  }
}

//**********************************************************************************

int abNNos (TNode *t){
    int n;
    if(t!=NULL){
        n = abNNos(t->left);
        n +=1;
        n += abNNos(t->right);
        return n;
    }
    return 0;
}

//**********************************************************************************

void * abRemove(TNode ** t, void * key, int (*cmp)(void *,void *)){
  int status=FALSE;
  void * data=NULL;
  TNode * auxTree;
  auxTree =*t;

  if(key!=NULL){

    if(t!=NULL && *t!=NULL && auxTree->data!=NULL){
      status = cmp(auxTree->data,key);

      if(status == FALSE){
        data = abRemove(&auxTree->left,key,cmp);
        if(data!=NULL){
          status==TRUE;
        }

        if(data == NULL){
          data = abRemove(&auxTree->right,key,cmp);
          if(data!=NULL){
            status==TRUE;
          }
        }
      }

      if(status==TRUE && data==NULL){
        data = abRemoveNode(*t);

        if(data==NULL){
          free(*t);
          *t=NULL;
        }
      }
    }
  }
  return data;
}
//**********************************************************************************

void * abRemoveNode(TNode * t){
  void * data, *aux;
  int status = FALSE;
  data = NULL;
  aux = NULL;
  int l=0,r=0;
  if(t!=NULL){
    l = abNNos(t->left);
    r = abNNos(t->right);

    data=t->data;

    if(l>=r && t->left!=NULL){
      aux = abRemoveNode(t->left);
    }else if(r>l && t->right!=NULL){
      aux = abRemoveNode(t->right);
    }

    if(aux!=NULL){
      t->data=aux;
      if(l==1 && l>=r){
        free(t->left);
        t->left=NULL;
      }else if(r==1 && l==0){
        free(t->right);
        t->right=NULL;
      }
    }

  }
  return data;
}

//**********************************************************************************

int abQuery(TNode * t, void * key, int (*cmp)(void *,void *)){
  int status=FALSE;

  if(key!=NULL){

    if(t!=NULL && t->data!=NULL){

      status = cmp(t->data,key);

      if(status ==FALSE){
        status = abQuery(t->left,key,cmp);

        if(status == FALSE){
          status = abQuery(t->right,key,cmp);
        }
      }
    }
  }
  return status;
}


//**********************************************************************************

int abFree(TNode **t, int (*freeElm)(void *)){
  void * data;

  if(t!=NULL){
    
    abFree(&(*t)->left,freeElm);
    abFree(&(*t)->right,freeElm);

    freeElm((*t)->data);
    TNode ** aux;
    
    free(*t);
    *t=NULL;
    return TRUE;

  }
  return FALSE;
}


//**********************************************************************************
#endif