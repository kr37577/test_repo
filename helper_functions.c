// helper_functions.c
#include "helper_functions.h"
#include <stdio.h>

void print_hello() {
    printf("Hello from updated C helper function!\n"); // Content changed
    printf("This is a new line in print_hello.\n");
}

// Line 1 added before multiply_by_two
// Line 2 added before multiply_by_two
// Line 3 added before multiply_by_two

// This function's content is unchanged, but its line number is shifted
int multiply_by_two(int x) {
    return x * 2;
}