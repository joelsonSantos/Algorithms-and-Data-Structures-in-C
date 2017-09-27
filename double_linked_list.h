#ifndef _DOUBLE_LINKED_LIST_
#define _DOUBLE_LINKED_LIST_

typedef struct sList DOUBLE_LINKED_LIST;

void init_list(DOUBLE_LINKED_LIST**);
DOUBLE_LINKED_LIST* create_node();
int full_stack(DOUBLE_LINKED_LIST*);
int exists(DOUBLE_LINKED_LIST**, int);
int is_empty(DOUBLE_LINKED_LIST**);
int search_list(DOUBLE_LINKED_LIST**, int);
void print_list(DOUBLE_LINKED_LIST**);
void add_first(DOUBLE_LINKED_LIST**, int);
void add_last(DOUBLE_LINKED_LIST**, int);
int remove_list(DOUBLE_LINKED_LIST**, int);
int remove_first(DOUBLE_LINKED_LIST**);
int remove_last(DOUBLE_LINKED_LIST**);
int size_list(DOUBLE_LINKED_LIST**);

#endif

