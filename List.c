// Created by HirokiTachiyama on 2017/11/03.
//

#include "List.h"


//Listの初期化
//先頭ノードは文字列格納には使用しない。
List* List_initialize() {
    List* top_node = (List*)malloc(sizeof(List*));
	List*
    top_node->next_node = NULL;
    top_node->str = NULL;
    return  top_node;
}


//引数のListの最後のノードの後ろに新たに生成したノードを繋げる
void List_add_node (char* List* _lists) {

    List* tmp_node = NULL;
    List* last_node = NULL;

    //listsの次ののー
    tmp_node = _lists->next_node;
    while(tmp_node != NULL){
        tmp_node = tmp_node->next_node;
		if(tmp_node->next_node == NULL) {
		  last_node->next_node = tmp_node;
		}
    }
    last_node = tmp_node;
	printf("New List was added.\n");

    List* new_node = (List*)malloc(sizeof(List));
	printf("%d\n", sizeof(*new_node));
	last_node->next_node = new_node;
	printf("New List was added3.\n");
    new_node->next_node = NULL;
	printf("New List was added3.\n");
    strcpy(new_node->str, _str);
	printf("New List was added3.\n");

}
//Listのメモリ解放 プログラム終了前に呼び出すこと(もしくは忘れずfreeすること)
void List_free_all_lists(List* lists) {

    List* current_node = lists;
    while(current_node != NULL) {
        current_node = current_node->next_node;
        free(current_node);
    }

}

