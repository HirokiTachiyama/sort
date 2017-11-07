
#include "sort_strings.h"

#define NUM_STRINGS 10 //文字列は最大10個
#define NUM_CHARACTERS 20 //文字列は最大20byte(改行文字と終端文字含まず)

//文字列をASCIIで比較し、-1, 0, 1を返す。小さい順にソート。
int compare_strings(const void *a, const void *b) {
	return strcmp((char*) a, (char*)b);
}


int main_hoge(void) {

	char input_strings[NUM_STRINGS][NUM_CHARACTERS + 1];//文字列＋終端文字
	char tmp_string[NUM_CHARACTERS + 1];//文字列＋終端文字
	int i;
	int j;

	i = 0;
	while (i < 10) { //文字列が10個入力されたら終了
		j = 0;
		printf("%d個目の文字列を入力して下さい。： ", i + 1);
		fgets(tmp_string, NUM_CHARACTERS + 1, stdin); //fgetsの第二引数は最大入力byte数 + 1(終端文字分)
		if(strcmp(tmp_string, "\n") == 0) { //改行文字のみの場合入力終了
			break;
		}

		for(j = 0; j < NUM_CHARACTERS; j++) { //改行文字の除去
			if(tmp_string[j] == '\n') {
			  tmp_string[j] = '\0';
			  break;
			}
		}
		if(strlen(tmp_string) == NUM_CHARACTERS) { //最大byteまで入力された場合、標準入力に残った'\n'を吐き出す
		  getchar();
		}
		strcpy(input_strings[i], tmp_string);
		i++;
	}
	printf("\n");

	//stdlib.h ライブラリ関数 qsort
	//void qsort(void *base, size_t num, size_t size, int (*compare)(const void*, const void*))
	//引数：ソート対象(配列), 要素数, 要素のサイズ, ソートに使用する関数
	//qsort(input_strings, NUM_STRINGS, NUM_CHARACTERS, compare_strings);
	//要素数は、入力された文字列の数であるiとする
	qsort(input_strings, i, NUM_CHARACTERS + 1, compare_strings);

	printf("ソート結果\n");
	for(j = 0; j < i; j++) {
		printf("%d:%s\n", j + 1, input_strings[j]);
	}

	return 0;
}
