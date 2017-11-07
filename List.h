
#ifndef INC_LIST_H
#define INC_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _List List;

struct _List {
    List* next_node;
    char* str;
};

#define NUM_CHARACTERS 20 //文字列の最大byte数(改行文字と終端文字含まず)

List* List_initialize();
void List_add_node (List* _lists);
void List_set_str(char* _str, List* _lists);
void List_free_all_lists(List* lists);

#endif //INC_LIST_H
