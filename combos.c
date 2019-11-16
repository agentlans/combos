#include "combos.h"

// Given a combination, returns which index to increment to get next combination
int index_to_increment(int **combination, int n, int r)
{
	for (int i = 0; i < r; ++i) {
		if ((*combination)[i] == n - r + i) {
			return i - 1;
		}
	}
	return r - 1;
}

// Sets array to the initial combo of [0, n) choose r
void starting_combination(int **combination, int n, int r)
{
	for (int i = 0; i < r; ++i) {
		(*combination)[i] = i;
	}
}

// Sets given combination to the next combination of [0, n) in place.
// Returns true if combinations haven't been exhausted.
bool next_combination(int **combination, int n, int r)
{
	int index = index_to_increment(combination, n, r);
	if (index == -1) {
		// Exhausted all combinations so return the first one
		starting_combination(combination, n, r);
		return false;
	} else {
		/* Increment the value at the index and all places after that
		   (ensures values are increasing after the incremented index). */
		int new_val = ++(*combination)[index];
		for (int i = index+1; i < r; ++i) {
			(*combination)[i] = ++new_val;
		}
		return true;
	}
}

// Prints array of length r
void print_array(int combination[], int r)
{
	for (int i = 0; i < r; ++i) {
		printf("%d ", combination[i]);
	}
	printf("\n");
}

// Returns true if there's an element in permutation from [0, end) that equals x.
bool is_repeat(int **permutation, int end, int x)
{
	for (int i = 0; i <= end; ++i) {
		if ((*permutation)[i] == x) return true;
	}
	return false;
}

/* Increments permutation to next permutation.
Returns true if and only if there's a new permutation to advance to. */
bool next_permutation(int **permutation, int n, int r)
{
	const int max_val = n - 1;
	int index = r - 1;

	while (1) {
		int val = (*permutation)[index];

		// Check if it's repeat. If number already taken by preceding elements then increase value.
		while (is_repeat(permutation, index, val) && val <= max_val) {
			val++;
		}
		if (val > max_val) {
			// Can't increase number at current index so move left.
			index--;
			if (index < 0) {
				starting_combination(permutation, n, r);
				return false;
			}
		} else if (!is_repeat(permutation, index, val)) {
			// If number at index isn't a repeat then we can increment that position
			(*permutation)[index] = val;
			// Set all the numbers to the right of current index.
			for (int i = index+1; i < n; ++i) {
				for (int candidate = 0; candidate < n; ++candidate) {
					if (!is_repeat(permutation, i, candidate)) {
						(*permutation)[i] = candidate;
						break;
					}
				}
			}
			return true;
		}
	}
}

