#ifndef INC_LIST_H
#define INC_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CHARACTERS_OF_STRING 20 //文字+終端文字(改行は含まない)

typedef struct _List {
  struct _List* next_node;
  char* string;
} List;
List* List_initialize_new_node();
void  List_add_new_node(List*);
void  List_set_string_to_last_node(List* , char*);
int   List_get_size(List*);
List* List_get_last_node(List*);
void  List_free_all_nodes(List*);
void List_print_all_strings(List*);

#endif


