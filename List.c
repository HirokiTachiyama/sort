
#include "List.h"


void  List_add_new_node(List* _list) {
  List* new_node = List_initialize_new_node();
  List* last_node = List_get_last_node(_list);
  last_node->next_node = new_node;
}

List* List_initialize_new_node() {
  List* node = (List*)malloc(sizeof(List));
  node->next_node = NULL;
  node->string = (char*)malloc(sizeof(char) * NUM_CHARACTERS_OF_STRING + 1);
  return node;
}

void  List_set_string_to_last_node(List* _list, char* _string) {
  List* last_node = List_get_last_node(_list);
  strcpy(last_node->string, _string);
}

int List_get_size(List* _list) {
  List* tmp_node = _list;
  int list_size = 0;

  while(tmp_node != NULL) {
	list_size++;
	tmp_node = tmp_node->next_node;
  }

  return list_size;
}

List* List_get_last_node(List* _list) {
  List* current_node = _list;

  while(current_node->next_node != NULL) {
	current_node = current_node->next_node;
  }

  return current_node;
}

void  List_free_all_nodes(List* _list) {
  List* current_node = _list;
  List* next_node = _list->next_node;
  while(1) {
    printf("%s is free\n", current_node->string);    
  	free(current_node->string);
    free(current_node);
    if(next_node == NULL) {
      break;
    }
    current_node = next_node;
    next_node = current_node->next_node;
  }

}

void List_print_all_strings(List* _list) {
  List* current_node = _list;
  while(current_node != NULL) {
	printf("%s\n", current_node->string);
	current_node = current_node->next_node;
  }
}



