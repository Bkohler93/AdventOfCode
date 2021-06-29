#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

int main(int argc, char** argv) {
	
	int size = 1000;
	FILE* input = fopen("info.txt", "r");
	
	char* buf = malloc(sizeof(char) * size);
	fgets(buf, size, input);

	if (feof(input)) {
		puts("Stored all contents of file");
	}
	
	int* length = malloc(sizeof(int));
	int* nums = fill_nums(buf, length);

	int* nv = find_pair(nums, length);

	int two_ans = 100 * nv[0] + nv[1];
	nums[1] = 12;
	nums[2] = 2;
	int ans = calc_ans(nums);

	printf("== Part 1 Ans: %d\n", ans);
	printf("== Part 2 Ans: %d\n", two_ans);

	free_nums(nums);
	free(buf);
	return 0;
}