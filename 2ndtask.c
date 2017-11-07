
/*
 *
 * コンソールから入力された文字列をソートし、結果をファイルに出力するプログラム
 *
 */
#include "2ndtask.h"
#include "List.h"

int main(int args, char* argv[]) {

    printf("%d, %s, %s\n", args, argv[0], argv[1]);

    List* lists = List_initialize();

	printf("address: %p\n", lists);

    List_add_node("hoge", lists);
    List_add_node("fuga", lists);

    List* tmp_node = lists;

    while(tmp_node != NULL) {
        tmp_node = tmp_node->next_node;
    }




    return 0;
}
