#include <stdio.h>
#include "helpers.h"

int* fill_nums(char* buf, int* length) {

	int* nums = (int*) malloc(sizeof(int) * 999);

	int len = 0;
	int iter = 0;
	int num_iter = 0;
	char c = 'n';
	while (c) {

		int curr_num = 0;
		int pos = 1;
		c = buf[iter++];
		if (c == ',') {
			iter++;
			continue;
		} else if (c == '-') {
			pos = 0;
		} else curr_num = c - 48;

		c = buf[iter++];

		while (c && (c != ',')) {

			curr_num *= 10;
			curr_num += (c - 48) ;
		
			c = buf[iter++];
		}
		len++;
		nums[num_iter++]  = (pos == 1) ? curr_num : (curr_num*(-1));
	}
	
	*length = len;
	return nums;
}

int calc_ans(int* nums) {

	int iter = 0;
	int output = 0;

	while (nums[iter]) {

		if (nums[iter] == 1) {
			op_one(nums, ++iter);
			iter += 3;
		} else if (nums[iter] == 2) {
			op_two(nums, ++iter);
			iter += 3;
		} else if (nums[iter] == 3) {
			op_three(nums, ++iter, 2);
			iter+= 1;
		} else if (nums[iter] == 4) {
			output = op_four(nums, ++iter);
			iter+= 1;
		}
		else if (nums[iter++] == 99) break;
	}
	return nums[0];
}

void op_one(int* nums, int iter) {
	int n1 = nums[nums[iter++]];
	int n2 = nums[nums[iter++]];
	nums[nums[iter]] = n1 + n2;
}

void op_two(int* nums, int iter) {
	int n1 = nums[nums[iter++]];
	int n2 = nums[nums[iter++]];
	nums[nums[iter]] = n1 * n2;	
}

void op_three(int* nums, int iter, int input) {
	nums[nums[iter]] = input;
}

int op_four(int* nums, int iter) {
	return nums[nums[iter]];
}

void free_nums(int* nums) {
	free(nums);
}

int* copyInput(int* nums, int* length) {

	int* copy = malloc(sizeof(int) * (*length));
	int iter = 0;
	
	for (int i = 0; i < *length; i++) {
		copy[i] = nums[i];
	}

	return copy;
}

int* find_pair(int* nums, int* length) {

	int goal = 19690720;
	int noun = 0;
	int verb = 0;
	int* ans = malloc(sizeof(int) * 2);

	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {
			int* copy = copyInput(nums, length);

			copy[1] = i;
			copy[2] = j;

			if (calc_ans(copy) == goal) {
				ans[0] = i;
				ans[1] = j;

				return ans;
			}
		}
	}
	return ans;
}