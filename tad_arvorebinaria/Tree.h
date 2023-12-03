#ifndef _TREE_H_
#define _TREE_H_


#ifdef _TREE_C_
    #define TRUE 1
    #define FALSE 0
    #include <stdlib.h>
    #include <stdio.h>
    typedef struct _tnode_ {
        void *data;
        struct _tnode_ *left;
        struct _tnode_ *right;
    } TNode;

    TNode * abCreate();
    
    int abInsertLeft(TNode * t,void * data);

    int abInsertRight(TNode * t,void * data);

    int abInsert(TNode * t, void * data);

    int abInsertcheck(TNode * t, int l,int status);

    TNode * abGetLeftNode(TNode * t);

    TNode * abGetRightNode(TNode * t);

    void * abGetNodeData(TNode * t);

    int abNNos (TNode *t);

    int abQuery(TNode * t, void * key, int (*cmp)(void *,void *));

    void * abRemove(TNode ** t, void * key, int (*cmp)(void *,void *));

    void * abRemoveNode(TNode * t);

    int abFree(TNode **t, int (*freeElm)(void *));

    int abInsertV2(TNode *t,void * data);

    void abBuscaNode(TNode * t,TNode ** res,int index, int * indexRes);

#else

    typedef struct _tnode_ TNode;

    extern TNode * abCreate();
    
    extern int abInsertLeft(TNode * t,void * data);

    extern int abInsertRight(TNode * t,void * data);

    extern int abInsert(TNode * t, void * data);

    extern int abInsertcheck(TNode * t, int l,int status);

    extern TNode * abGetLeftNode(TNode * t);

    extern TNode * abGetRightNode(TNode * t);

    extern void * abGetNodeData(TNode * t);

    extern int abNNos (TNode *t);

    extern int abQuery(TNode * t, void * key, int (*cmp)(void *,void *));

    extern void * abRemove(TNode ** t, void * key, int (*cmp)(void *,void *));

    extern int abFree(TNode **t, int (*freeElm)(void *));

    extern int abInsertV2(TNode *t,void * data);

#endif
#endif