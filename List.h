
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



List* List_initialize();
void List_add_node (char* _str, List* _lists);
void List_free_all_lists(List* lists);

#endif //INC_LIST_H
