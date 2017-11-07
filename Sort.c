
#include "Sort.h"


//文字列をASCIIで比較し、-1, 0, 1を返す。小さい順にソート。
int compare_strings(const void *a, const void *b) {
	return strcmp((char*) a, (char*)b);
}

List* main_hoge(List* lists) {

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
