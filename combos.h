#ifndef _COMBOS
#define _COMBOS

#include <stdbool.h>

void starting_combination(int **combination, int n, int r);
bool next_combination(int **combination, int n, int r);
bool next_permutation(int **permutation, int n, int r);
void print_array(int combination[], int r);

#endif

