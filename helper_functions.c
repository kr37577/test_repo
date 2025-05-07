// helper_functions.c
#include "helper_functions.h"
#include <stdio.h>

// helper_functions.c (変更箇所のみ抜粋)
void print_hello() {
    printf("Hello from updated C helper function!\n"); // 1つ目のprintfは残す
    // ★削除: printf("This is a new line in print_hello.\n");
}

// Line 1 added before multiply_by_two
// Line 2 added before multiply_by_two
// Line 3 added before multiply_by_two

// This function's content is unchanged, but its line number is shifted
int multiply_by_two(int x) {
    if (x > 1000) { // ★追加: 条件式
        printf("Input is very large!\n"); // ★追加: 呼び出し
    }
    if (x < 0) return 0; // ★追加: 条件式 (早期リターン)
    return x * 2;
}