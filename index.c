// Luiz Fernando Klein e João Marcos de Assis Soares
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _elStack {
  char element[61];
  struct _elStack *next;
};
typedef struct _elStack ElementStack;

typedef struct {
  ElementStack *top;
} Stack;

void push(Stack *stack, char *element){
  ElementStack *newElement = malloc(sizeof(ElementStack));
  newElement->next = NULL;
  strcpy(newElement->element, element);

  newElement->next = stack->top;
  stack->top = newElement;
}

int isEmpty(Stack *stack){
  return (stack->top == NULL)? 1: 0;
}

void freeStack(Stack *stack){
  if (isEmpty(stack)) {
    printf("!\n");
    return;
  }

  ElementStack *aux = stack->top, *prev;
  while ( aux != NULL ){
    prev = aux;
    aux = aux->next;
    printf("@");
    free(prev);
  }
  printf("\n");
  free(stack);
}

void pop(Stack *stack){

  if (isEmpty(stack)) {
    printf("Vazio\n");
    return;
  }
  
  ElementStack *aux;

  aux = stack->top;
  stack->top = stack->top->next;
  printf("%s\n", aux->element);
  
  free(aux);
}

int main (){
  Stack *stack = malloc(sizeof(Stack));
  stack->top = NULL;

  char element[61];

  while (1) {
    scanf("%s", element);
    
    if (strcmp(element, "B") == 0) {
      pop(stack);
    } else if (strcmp(element, "E") == 0) {
      freeStack(stack);
      break;
    } else {
      push(stack, element);
    }
  }

  return 0;
}
