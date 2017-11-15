
/*
 * kadai12-1.c
 * コンソールから入力された文字列をソートし、結果をファイルに出力するプログラム
 * 
 */

#include "kadai2-1.h"

int main(int argc, char* argv[]) {
  List* top_node;
  char tmp_string[NUM_CHARACTERS_OF_STRING + 1];
  int i;
  int input_times;
	bool top_node_is_unused;
	FILE* fp;

	//出力ファイル名取得
	if(argc == 1) {
		fprintf(stderr, "ファイル名が入力されていません。\n");
		exit(1);
	} else {
		printf("Output file name is %s\n", argv[1]);
		if( (fp = fopen(argv[1], "a")) == NULL) {
			printf("出力ファイルを開けませんでした。");
			exit(1);
		}
	}


	//コンソール入力の文字列取得、リストへの格納
  top_node = List_initialize_new_node();
  top_node_is_unused = true;
  input_times = 0;
  while (1) { //改行文字のみが入力されるまでループ
		input_times++;
		printf("%d個目の文字列を入力して下さい。： ", input_times);
		fgets(tmp_string, NUM_CHARACTERS_OF_STRING + 1, stdin); //第二引数は最大入力byte数 + 1(終端文字分)	

		if(strcmp(tmp_string, "\n") == 0) { //入力終了(改行文字のみ入力された)		
		  break;
		} else { //入力有、リストへの入力文字の格納

		  if(top_node_is_unused) {
				//初回の文字列格納時はtop_nodeへ行うため、新規ノード追加は行わない
					top_node_is_unused = false; //次回以降の格納時にはelse節を実行
	  	} else {
				List_add_new_node_to_last_of_list(top_node); //新規ノードの追加
	  	}

			//マルチバイト判定
			i = 0;
			while(tmp_string[i] != '\0') {				
				if(tmp_string[i] & 0x80) {
					fprintf(stderr, "半角英数字以外が入力されたため、プログラムを終了します。\n");
					List_free_all_nodes(top_node);
					fclose(fp);
					exit(1);
				}				
				i++;
			}

			//改行文字の除去
		  for(i = 0; i < NUM_CHARACTERS_OF_STRING; i++) {
				if(tmp_string[i] == '\n') {
				  tmp_string[i] = '\0';
			  	break;
				}
	  	}

			//最大byteまで入力された場合、標準入力に残った'\n'を吐き出す
		  if(strlen(tmp_string) == NUM_CHARACTERS_OF_STRING) {
				getchar();
	  	}

			//ノードの追加、文字列の格納
	 		List* last_node = List_get_last_node(top_node);
	  	strcpy(last_node->string, tmp_string);
		}
  }//コンソールからの文字入力、リストへの格納のwhile 終了

	//ソートの為に、リストから配列に文字列をコピー
  List* tmp_node = top_node;
  int num_strings = List_get_size(top_node);
	char strings[num_strings][NUM_CHARACTERS_OF_STRING + 1];
  for(i = 0; i < num_strings; i++) {
		strcpy(strings[i], tmp_node->string);
		tmp_node = tmp_node->next_node;
  }

	//文字列ソート
  Sort_sort(strings, num_strings);

	//ファイル書き込み
	for(i=0; i<num_strings; i++) {
		fputs(strings[i], fp);
		fputs("\n", fp);
	}

	//出力ファイルクローズ、メモリ解放
	fclose(fp);
  List_free_all_nodes(top_node);
  return 0;
}
