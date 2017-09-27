#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list.h"

typedef struct sList{
	int info;
	struct sList *next;
	struct sList *prev;
}DOUBLE_LINKED_LIST;

void init_list(DOUBLE_LINKED_LIST** list){
   (*list) = NULL;
}

DOUBLE_LINKED_LIST* create_node(){
   DOUBLE_LINKED_LIST* node = (DOUBLE_LINKED_LIST*) malloc(sizeof(DOUBLE_LINKED_LIST));
   return node;
}

int full_stack(DOUBLE_LINKED_LIST* node){
   if(node == NULL){
      return 1;
   }
   return 0;
}

int exists(DOUBLE_LINKED_LIST** list, int element){
  if(is_empty(list)){
    return 0;
  }
  DOUBLE_LINKED_LIST* aux = (*list);
  while(aux != NULL){
	 if(aux->info == element){
	    return 1;
	 }
     aux = aux->next;
  }
  return 0;
}

int is_empty(DOUBLE_LINKED_LIST** list){
	if((*list) == NULL){
	   return 1;
	}
   return 0;
}

int size_list(DOUBLE_LINKED_LIST** list){
   int count = 0;
   if(is_empty(list)){
      return 0;
   }
   DOUBLE_LINKED_LIST* aux = (*list);
   while(aux != NULL){
	 count++;
     aux = aux->next;
   }
   return count;
}

int search_list(DOUBLE_LINKED_LIST** list, int element){
    DOUBLE_LINKED_LIST* aux = (*list);
    while(aux != NULL){
	   if(aux->info == element){
	     return 1;
	   }
	   aux = aux->next;
	}
	return 0;
}

void print_list(DOUBLE_LINKED_LIST** list){
	// se lista vazia
    if(is_empty(list)){
	  printf("\n Empty list!");
	  return;
	}
	DOUBLE_LINKED_LIST* aux = (*list);
	printf("\n######################\n");
	while(aux != NULL){
	  printf(" %d ", aux->info);
	  aux = aux->next;
	}
	printf("\n######################\n");
}

void add_first(DOUBLE_LINKED_LIST** list, int element){
    // cria um novo nó.
    DOUBLE_LINKED_LIST* node = create_node();
    // verifica se a memória está cheia.
    if(full_stack(node)){
	   printf("\nError: full memory!");
	   return;
	}
    node->info = element;
    node->next = NULL;
    node->prev = NULL; 
      
    // se lista vazia
    if(is_empty(list)){
		(*list) = node;
		return;
	}
	node->next = (*list);
	(*list)->prev = node;
	(*list) = node;
}

void add_last(DOUBLE_LINKED_LIST** list, int element){
    // cria um novo nó.
    DOUBLE_LINKED_LIST* node = create_node();
    // verifica se a memória está cheia.
    if(full_stack(node)){
	   printf("\nError: full memory!");
	   return;
	}
    node->info = element;
    node->next = NULL;
    node->prev = NULL;
  
    // se lista vazia
    if(is_empty(list)){
		(*list) = node;
		return;
	}
	DOUBLE_LINKED_LIST* aux = (*list);
	while(aux->next != NULL){
	  aux = aux->next;
	}
	aux->next = node;
	node->prev = aux;
}

int remove_list(DOUBLE_LINKED_LIST** list, int element){
   if(is_empty(list)){
      printf("\nThere is no elements in the list");
      return 0;
   }
   DOUBLE_LINKED_LIST* aux = (*list);
   DOUBLE_LINKED_LIST* prev;
   
   if(!exists(list, element)){
	   printf("\n Element does not exist!");
	   return 0;
   }
   
   while(aux->next != NULL && aux->info != element){
	  prev = aux;
	  aux = aux->next;
   }
   prev->next = aux->next;
   aux->next->prev = prev;
   free(aux);
   return element;
}

int remove_first(DOUBLE_LINKED_LIST** list){
   if(is_empty(list)){
      printf("\nThere is no elements in the list");
      return -1;
   }
   DOUBLE_LINKED_LIST* rm = (*list);
   int element = rm->info;
   (*list) = (*list)->next;
   free(rm);
   return element;
}

int remove_last(DOUBLE_LINKED_LIST** list){
   DOUBLE_LINKED_LIST* aux = (*list);
   DOUBLE_LINKED_LIST* prev;
   int element;
   if(is_empty(list)){
      printf("\nThere is no elements in the list");
      return -1;
   }
   if(aux->next == NULL){
	 element = remove_first(list);
     return element;
   }
   while(aux->next != NULL){
	  prev = aux;
	  aux = aux->next;
   }
   element = aux->info;
   prev->next = NULL; 
   free(aux);
   return element;
}
