#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

int main(int argc, char** argv) {
	
	int size = 1000;
	FILE* input = fopen("inputs.txt", "r");
	
	char* buf = malloc(sizeof(char) * size);
	fgets(buf, size, input);

	if (feof(input)) {
		puts("Stored all contents of file");
	}
	
	int* length = malloc(sizeof(int));
	int* nums = fill_nums(buf, length);

	
	free_nums(nums);
	free(buf);
	return 0;
}