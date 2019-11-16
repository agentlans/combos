#include <stdio.h>
#include "combos.h"

int main()
{
	int n = 6, r = 3;
	int arr[r];

	int *arr_ptr = arr;
	starting_combo(&arr_ptr, n, r);
	do {
		print_array(arr, r);
	} while (next_permutation(&arr_ptr, n, r));

	return 0;
}

