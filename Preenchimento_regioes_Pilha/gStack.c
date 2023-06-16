#include "gStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

Stack *stkCreate(int max) {
  Stack *s;

  if (max > 0) {
    s = (Stack *)malloc(sizeof(Stack));

    if (s != NULL) {
      s->items = (void **)malloc(sizeof(void *) * max);
      s->maxItems = max;
      s->top = -1;

      return s;
    }
  }

  return NULL;
};

int stkPush(Stack *s, void *elm) {
  if (s != NULL && s->top < s->maxItems - 1) {
    s->top++;
    s->items[s->top] = elm;

    return TRUE;
  }

  return FALSE;
};

void *stkPop(Stack *s) {
  if (s != NULL && s->top >= 0) {
    void *aux = s->items[s->top];
    s->top--;

    return aux;
  }

  return NULL;
};

void *stkTop(Stack *s) {
  if (s != NULL && s->top >= 0) {
    void *aux = s->items[s->top];
    return aux;
  }

  return NULL;
};

int stkIsEmpty(Stack *s) {
  if (s != NULL && s->top < 0) {
    return TRUE;
  }
  return FALSE;
};

int stkDestroy(Stack *s) {
  if (s != NULL && s->top < 0) {
    free(s->items);
    free(s);

    return TRUE;
  }

  return FALSE;
};