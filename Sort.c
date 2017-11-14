
#include "Sort.h"
#include "List.h"

//文字列をASCIIで比較し、-1, 0, 1を返す。小さい順にソート。
int Sort_compare_strings(const void *a, const void *b) {
	return strcmp((char*) a, (char*)b);
}

void Sort_sort(char _strings[][NUM_CHARACTERS_OF_STRING + 1], int _num_strings) {
  //stdlib.h ライブラリ関数 qsort
  //void qsort(void *base, size_t num, size_t size, int (*compare)(const void*, const void*))
  //引数：ソート対象(配列), 要素数, 要素のサイズ, ソートに使用する関数
  qsort(_strings, _num_strings, NUM_CHARACTERS_OF_STRING + 1, Sort_compare_strings);
  
}
