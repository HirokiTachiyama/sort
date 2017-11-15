
/*
 * List.c
 * 文字列格納用リストAPI
 *
 * 使い方
 * 1. List_initialize_new_nodeで先頭ノードを用意
 * 2. List_set_string_to_last_nodeで先頭ノードに文字列を格納
 * 3. 以降は、List_add_new_node_to_last_of_listでノード追加、
 *            List_set_string_to_last_nodeで文字列格納が可能
 * 4. List_free_all_nodesでリストのメモリ解放
 * 以上
 *
 * ・List_print_all_stringsはデバッグで使用したが、
 *   提出コードでは使用していない
 */

#include "List.h"



//新規ノードの初期化
//List型変数のメモリ動的確保を行い、そのポインタを返す
List* List_initialize_new_node() {
  List* node = (List*)malloc(sizeof(List));

  node->next_node = NULL;
  node->string = (char*)malloc(sizeof(char) * NUM_CHARACTERS_OF_STRING + 1);

  return node;
}

//引数のリストの末尾に新規ノードを繋げる
void List_add_new_node_to_last_of_list(List* _list) {
  List* new_node = List_initialize_new_node();
  List* last_node = List_get_last_node(_list);

  last_node->next_node = new_node;

}

//引数のリストの末尾のノードに文字列を格納する
void List_set_string_to_last_node(List* _list, char* _string) {
  List* last_node = List_get_last_node(_list);

  strcpy(last_node->string, _string);

}

//引数のリストのノードの総計を返す
int List_get_size(List* _list) {
  List* tmp_node = _list;
  int list_size = 0;

  while(tmp_node != NULL) {
	list_size++;
	tmp_node = tmp_node->next_node;
  }

  return list_size;
}

//リストの最後のノードのポインタを返す
List* List_get_last_node(List* _list) {
  List* current_node = _list;

  while(current_node->next_node != NULL) {
	current_node = current_node->next_node;
  }

  return current_node;
}

//先頭ノードから順次、メモリを解放する
void  List_free_all_nodes(List* _list) {
  List* current_node = _list;
  List* next_node = _list->next_node;

  while(1) {
  	free(current_node->string);
    free(current_node);
    if(next_node == NULL) {
      break;
    }
    current_node = next_node;
    next_node = current_node->next_node;
  }

}

//全ノードの文字列を表示する
void List_print_all_strings(List* _list) {
  List* current_node = _list;

  while(current_node != NULL) {
	printf("%s\n", current_node->string);
	current_node = current_node->next_node;
  }

}
