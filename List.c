// Created by HirokiTachiyama on 2017/11/03.
//

#include "List.h"



//Listの初期化
//先頭ノードは文字列格納には使用しない。
List* List_initialize() {
    List* top_node = (List*)malloc(sizeof(List));
    top_node->next_node = NULL;
    top_node->str = NULL;
	return top_node;
}


//引数のListの最後のノードの後ろに新たに生成したノードを繋げる
void List_add_new_node (List* _lists) {
  List* last_node = List_get_last_node(_lists);
  List* new_node = (List*)malloc(sizeof(List));

  last_node->next_node = new_node;
}

void List_set_string_to_last_node(List* _lists, char* _str) {

  printf("%d\n", NUM_CHARACTERS);
  printf("New List was added3.\n");
  //strcpy(new_node->str, _str);
  printf("New List was added3.\n");
  
}

int List_get_size(List* lists) {
  int size = 0;
  List* tmp = lists;

  while(tmp != NULL) {
	tmp = lists->next_node;
	size++;
  }

  return size;
}

List* List_get_last_node(List* lists) {
  List* current_node = lists;
  List* next_node = lists->next_node;
  if (next_node == NULL) {
	return current_node;
  }

  while(1) {
	current_node = next_node;
	next_node = next_node->next_node;
	if(next_node == NULL) {
	  return current_node;
	}
  }
}

//Listのメモリ解放 プログラム終了前に呼び出すこと(もしくは忘れずfreeすること)
void List_free_all_lists(List* lists) {

    List* current_node = lists;
    while(current_node != NULL) {
        current_node = current_node->next_node;
        free(current_node);
    }

}

