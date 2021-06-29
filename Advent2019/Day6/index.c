#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

	int size = 9;
	FILE* input = fopen("inputs.txt", "r");
	
	char buf[size];
	int good_line = 1;
	while(fgets(buf, size, input) != NULL) {
		if (good_line == 1) {
			printf("%s\n", buf);
			
			printf("string length is %lu\n", strlen(buf));
			good_line = 0;
		} else {
			good_line = 1;
		}
	}

	if (feof(input)) {
		puts("Stored all contents of file");
	}

	return 0;
}