#include <stdio.h>
#include <stdlib.h>
#include "circular_singly_linked_list.h"

typedef struct sList{
	int info;
	struct sList *next;
}DOUBLE_LIST;

void init_list(DOUBLE_LIST** list){
   (*list) = NULL;
}

DOUBLE_LIST* create_node(){
   DOUBLE_LIST* node = (DOUBLE_LIST*) malloc(sizeof(DOUBLE_LIST));
   return node;
}

int full_stack(DOUBLE_LIST* node){
   if(node == NULL){
      return 1;
   }
   return 0;
}

int exists(DOUBLE_LIST** list, int element){
  if(is_empty(list)){
    return 0;
  }
  DOUBLE_LIST* aux = (*list)->next;
  do{
	 if(aux->info == element){
	    return 1;
	 }
     aux = aux->next;
  }while(aux != (*list)->next);
  return 0;
}

int is_empty(DOUBLE_LIST** list){
	if((*list) == NULL){
	   return 1;
	}
   return 0;
}

int size_list(DOUBLE_LIST** list){
   int count = 0;
   if(is_empty(list)){
      return 0;
   }
   DOUBLE_LIST* aux = (*list)->next;
   do{
	 count++;
     aux = aux->next;
   }while(aux != (*list)->next);
   return count;
}

int search_list(DOUBLE_LIST** list, int element){
    DOUBLE_LIST* aux = (*list)->next;
    do{
	   if(aux->info == element){
	     return 1;
	   }
	   aux = aux->next;
	}while(aux != (*list)->next);
	return 0;
}

void print_list(DOUBLE_LIST** list){
	// se lista vazia
    if(is_empty(list)){
	  printf("\n Empty list!");
	  return;
	}
	DOUBLE_LIST* aux = (*list)->next;
	printf("\n######################\n");
	do{
	  printf(" %d ", aux->info);
	  aux = aux->next;
	}while(aux != (*list)->next);
	printf("\n######################\n");
}

void add_last(DOUBLE_LIST** list, int element){
    // cria um novo nó.
    DOUBLE_LIST* node = create_node();
    // verifica se a memória está cheia.
    if(full_stack(node)){
	   printf("\nError: full memory!");
	   return;
	}
    node->info = element;
    node->next = NULL;
      
    // se lista vazia
    if(is_empty(list)){
		(*list) = node;
		node->next = (*list); // circula
		return;
	}
	node->next = (*list)->next;
	(*list)->next = node;
	(*list) = node;
}

int remove_first(DOUBLE_LIST** list){
   if(is_empty(list)){
      printf("\nThere is no elements in the list");
      return -1;
   }
   DOUBLE_LIST* rm = (*list)->next;
   int element = rm->info;
   if(rm->next == (*list)){
     (*list) = NULL;
   }else{
     (*list)->next = rm->next;
   }
   free(rm);
   return element;
}

int remove_last(DOUBLE_LIST** list){
   DOUBLE_LIST* aux = (*list);
   DOUBLE_LIST* prev;
   int element;
   if(is_empty(list)){
      printf("\nThere is no elements in the list");
      return -1;
   }
   if(aux->next == (*list)){
	 element = remove_first(list);
     return element;
   }
   
   do{
	 prev = aux;
	 aux = aux->next;
   }while(aux->next != (*list)->next);
   element = aux->info;
   prev->next = (*list)->next; 
   free(aux);
   return element;
}
