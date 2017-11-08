
#ifndef INC_LIST_H
#define INC_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _List {
    struct _List* next_node;
    char* str;
} List;

#define NUM_CHARACTERS 20 //文字列の最大byte数(改行文字と終端文字含まず)

List* List_initialize();
void List_add_new_node (List* _lists);
void List_set_string_to_last_node(List* _lists, char* _str);
void List_free_all_lists(List* lists);
int  List_get_size(List* lists);
List* List_get_last_node(List* lists);

#endif //INC_LIST_H
