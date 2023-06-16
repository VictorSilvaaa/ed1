#ifndef _SLLIST_H_
#define _SLLIST_H_
#define TRUE 1
#define FALSE 0
#ifdef _SLLIST_C_
    #include <stdlib.h>
    typedef struct _slnode_{

        struct _slnode_ *next;
        void *data;

    } SLNode;

    typedef struct _sllist_ {

        SLNode *first;
        SLNode *cur;

    } SLList;

    SLList *sllCreate();

    int sllDestroy(SLList *l);

    int sllInsertAsFirst(SLList *l, void *data);

    int sllInsertAsLast(SLList *l, void *data);

    void *sllGetFirst(SLList *l);

    void *sllGetNext(SLList *l);

    void * sllRemoveFirst(SLList *l);

    void * sllRemoveLast(SLList * l);

    void *sllRemoveSpec(SLList *l, void *key, int (*cmp)(void *, void *));

    void *sllQuery(SLList *l, void *key, int (*cmp)(void *, void *));

    int sllCleanList(SLList * l);

    int sllNElms(SLList * l);

    int sllInsertPEsimo (SLList * l, int p, void * data);

    int sllInsertAfterSpec(SLList * l, void * key, int (*cmp)(void *, void *),void * data);

    int sllInsertBeforeSpec(SLList * l, void * key, int (*cmp)(void *, void *), void * data);


    void * sllRetornaMaior(SLList * l, int (*cmp)(void *,void *));



    SLList * sllJuntarListasManual(SLList * l1, SLList * l2);

    SLList * sllJuntarListas(SLList * l1, SLList * l2);

    SLList * sllJuntarListasCondicao(SLList * l1, SLList * l2,int (*cmp)(void *));

    int sllMantemElementosRepitidos(SLList * l1,SLList * l2,int (*cmp)(void *, void *));

    int sllRemoveElementosRepitidos(SLList * l1,SLList * l2,int (*cmp)(void *, void *));

    

#else

    typedef struct _SLList_ SLList; // define um tipo de dado com uma estrutura

    typedef struct _slnode_ SLNode;

    extern SLList *sllCreate();

    extern int sllDestroy(SLList *l);

    extern int sllInsertAsFirst(SLList *l, void *data);

    extern int sllInsertAsLast(SLList *l, void *data);

    extern void *sllGetFirst(SLList *l);

    extern void *sllGetNext(SLList *l);

    extern void *sllRemoveFirst(SLList *l);

    extern void * sllRemoveLast(SLList * l);

    extern void *sllRemoveSpec(SLList *l, void *key, int (*cmp)(void *, void *));

    extern void *sllQuery(SLList *l, void *key, int (*cmp)(void *, void *));

    extern int sllCleanList(SLList * l);

    extern int sllNElms(SLList * l);

    extern int sllInsertPEsimo(SLList * l, int p, void * data);

    extern int sllInsertAfterSpec(SLList * l, void * key, int (*cmp)(void *, void *),void * data);

    extern int sllInsertBeforeSpec(SLList * l, void * key, int (*cmp)(void *, void *), void * data);


    extern void * sllRetornaMaior(SLList * l, int (*cmp)(void *,void *));


    extern SLList * sllJuntarListasManual(SLList * l1, SLList * l2);

    extern SLList * sllJuntarListas(SLList * l1, SLList * l2);

    extern SLList * sllJuntarListasCondicao(SLList * l1, SLList * l2,int (*cmp)(void *));

    extern int sllMantemElementosRepitidos(SLList * l1,SLList * l2,int (*cmp)(void *, void *));

    extern int sllRemoveElementosRepitidos(SLList * l1,SLList * l2,int (*cmp)(void *, void *));

#endif
#endif