// Created by HirokiTachiyama on 2017/11/03.
//

#include "List.h"



//Listの初期化
List* List_initialize() {
    List* top_node = (List*)malloc(sizeof(List));
    top_node->next_node = (List*)malloc(sizeof(List*));
	top_node->str = (char*)malloc(sizeof(char) * NUM_CHARACTERS);
	printf("top node is initialized\n");
	return top_node;
}


//引数のListの最後のノードの次に新たに生成したノードを繋げる
void List_add_new_node (List* _lists) {
  //新しいノードの準備
  List* new_node = (List*)malloc(sizeof(List));
  new_node->next_node = (List*)malloc(sizeof(List*));
  new_node->str = (char*)malloc(sizeof(char) * NUM_CHARACTERS);

  List* last_node_of_lists = List_get_last_node(_lists);
  last_node_of_lists->next_node = new_node;
  printf("new node is added\n");
}

void List_set_string_to_last_node(List* _lists, char* _str) {
  printf("hoge~\n");
  List* last_node = List_get_last_node(_lists);
  printf("hoge~\n");
  strcpy(last_node->str, _str);
  printf("New str:%s was set.\n", last_node->str);
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
  printf("nyoho");
  List* current_node = lists;
  List* next_node = lists->next_node;
  if (next_node == NULL) {
	printf("this is top node\n");
	return current_node;
  }

  while(1) {
	current_node = next_node;
	next_node = next_node->next_node;
	if(next_node == NULL) {
	  printf("last node is retturned\n");
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

