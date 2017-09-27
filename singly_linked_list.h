#ifndef _SINGLY_LINKED_LIST_
#define _SINGLY_LINKED_LIST_

typedef struct sList SINGLY_LIST;

void init_list(SINGLY_LIST**);
SINGLY_LIST* create_node();
int full_stack(SINGLY_LIST*);
int exists(SINGLY_LIST**, int);
int is_empty(SINGLY_LIST**);
int search_list(SINGLY_LIST**, int);
void print_list(SINGLY_LIST**);
void add_first(SINGLY_LIST**, int);
void add_last(SINGLY_LIST**, int);
int remove_list(SINGLY_LIST**, int);
int remove_first(SINGLY_LIST**);
int remove_last(SINGLY_LIST**);
int size_list(SINGLY_LIST**);

#endif
