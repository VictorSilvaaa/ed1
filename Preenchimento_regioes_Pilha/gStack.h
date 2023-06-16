#ifndef _STACK_H_
#define _STACK_H_

typedef struct _stack_{
    int maxItems;
    int top;
    void **items;
} Stack;

Stack *stkCreate(int max);

int stkPush(Stack *s, void *elm);

void *stkPop(Stack *s);

void *stkTop(Stack *s);

int stkIsEmpty(Stack *s);

int stkDestroy(Stack *s);

int defineIAsTop(Stack *s, int i);

#endif
