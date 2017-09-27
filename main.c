#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"

/*compilar assim: 
 * gcc singly_linked_list.c -c
 * gcc singly_linked_list.o main.c -o main 
*/


int main(){
  SINGLY_LIST* list;
  init_list(&list);
  printf("\nInsere no início");  
  add_first(&list, 10);
  print_list(&list);
  printf("\nInsere no início");
  add_first(&list, 12);
  print_list(&list);
  printf("\nInsere no início");
  add_first(&list, 11);
  print_list(&list);
  printf("\nInsere no fim");
  add_last(&list, 9);
  print_list(&list);
  printf("\nInsere no fim");
  add_last(&list, 8);
  print_list(&list);
  printf("\nSize list %d: ", size_list(&list));
  printf("Remove no fim");
  remove_last(&list);
  print_list(&list);
  printf("\nSize list %d: ", size_list(&list));
  printf("\nRemove no início");
  remove_first(&list);
  print_list(&list);
  printf("\nRemove o 10");
  remove_list(&list, 10);
  print_list(&list);
  printf("\nSize list %d: ", size_list(&list));
  printf("\nPesquisa o 12");
  if(search_list(&list, 12)){
    printf("\n %d existe na lista \n", 12);
  }else{
    printf("\n elemento inexistente! \n");
  }
  printf("\nPesquisa o 200");
  if(search_list(&list, 200)){
    printf("\n %d existe na lista \n", 200);
  }else{
    printf("\n elemento inexistente! \n");
  }
 return 0;	
}
