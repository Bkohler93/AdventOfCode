#ifndef HELPERS_H
#define HELPERS_H

#include <stdlib.h>
#include <stdio.h>

int* fill_nums(char* buf, int* length);
int calc_ans(int* nums);
void op_one(int* nums, int iter);
void op_two(int* nums, int iter);
void op_three(int* nums, int iter, int input);
int op_four(int* nums, int iter);
void free_nums(int* nums);
int* copyInput(int* nums, int* length);
int* find_pair(int* nums, int* length);

#endif