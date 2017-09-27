#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"

typedef struct sList{
	int info;
	struct sList *next;
}SINGLY_LIST;

void init_list(SINGLY_LIST** list){
   (*list) = NULL;
}

SINGLY_LIST* create_node(){
   SINGLY_LIST* node = (SINGLY_LIST*) malloc(sizeof(SINGLY_LIST));
   return node;
}

int full_stack(SINGLY_LIST* node){
   if(node == NULL){
      return 1;
   }
   return 0;
}

int exists(SINGLY_LIST** list, int element){
  if(is_empty(list)){
    return 0;
  }
  SINGLY_LIST* aux = (*list);
  while(aux != NULL){
	 if(aux->info == element){
	    return 1;
	 }
     aux = aux->next;
  }
  return 0;
}

int is_empty(SINGLY_LIST** list){
	if((*list) == NULL){
	   return 1;
	}
   return 0;
}

int size_list(SINGLY_LIST** list){
   int count = 0;
   if(is_empty(list)){
      return 0;
   }
   SINGLY_LIST* aux = (*list);
   while(aux != NULL){
	 count++;
     aux = aux->next;
   }
   return count;
}

int search_list(SINGLY_LIST** list, int element){
    SINGLY_LIST* aux = (*list);
    while(aux != NULL){
	   if(aux->info == element){
	     return 1;
	   }
	   aux = aux->next;
	}
	return 0;
}

void print_list(SINGLY_LIST** list){
	// se lista vazia
    if(is_empty(list)){
	  printf("\n Empty list!");
	  return;
	}
	SINGLY_LIST* aux = (*list);
	printf("\n######################\n");
	while(aux != NULL){
	  printf(" %d ", aux->info);
	  aux = aux->next;
	}
	printf("\n######################\n");
}

void add_first(SINGLY_LIST** list, int element){
    // cria um novo nó.
    SINGLY_LIST* node = create_node();
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
		return;
	}
	node->next = (*list);
	(*list) = node;
}

void add_last(SINGLY_LIST** list, int element){
    // cria um novo nó.
    SINGLY_LIST* node = create_node();
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
		return;
	}
	SINGLY_LIST* aux = (*list);
	while(aux->next != NULL){
	  aux = aux->next;
	}
	aux->next = node;
}

int remove_list(SINGLY_LIST** list, int element){
   if(is_empty(list)){
      printf("\nThere is no elements in the list");
      return 0;
   }
   SINGLY_LIST* aux = (*list);
   SINGLY_LIST* prev;
   
   if(!exists(list, element)){
	   printf("\n Element does not exist!");
	   return 0;
   }
   
   while(aux->next != NULL && aux->info != element){
	  prev = aux;
	  aux = aux->next;
   }
   prev->next = aux->next;
   free(aux);
   return element;
}

int remove_first(SINGLY_LIST** list){
   if(is_empty(list)){
      printf("\nThere is no elements in the list");
      return -1;
   }
   SINGLY_LIST* rm = (*list);
   int element = rm->info;
   (*list) = (*list)->next;
   free(rm);
   return element;
}

int remove_last(SINGLY_LIST** list){
   SINGLY_LIST* aux = (*list);
   SINGLY_LIST* prev;
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
