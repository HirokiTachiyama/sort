#include <stdio.h>
#include "List.h"

int main(void) {

  List* lists = List_initialize();
  List_set_string_to_last_node(lists, "hoge");

  List_add_new_node(lists);

  List_set_string_to_last_node(lists, "fuga");



  return 0;
}
