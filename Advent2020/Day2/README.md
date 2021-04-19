## About
This is my solution to the Advent of Code 2020 Day 2 Challenge. In this problem I had to check how many passwords are valid from a large (1000 lines) input. There are two parts to this problem, and each part follows different rules for how to check if a password is valid. All passwords are in lower case and only contain letters. An example line from the input file is shown below, as well as the rules to checking if a password is valid:

"1-13 r: gqdrspndr"

### PART ONE RULES:
The first characters represent a range of numbers to which the following letter will appear in a password. In the example above the password will be valid if there are [1,13] r's.

### PART TWO RULES:
The first characters represent indices. The first index will be where the following letter must be found, and the second index will be where the following letter must not be found. The problem states that these numbers are literal, meaning '1' is the first index of a string. In the example above string[0] must contain 'r' and string[12] must not contain an 'r'

## How to run
Use 'make' to compile and create an executable if you have the correct tools. 
Otherwise use a cpp compiler as such: '[g++] *.cpp -o run'.

Use ./run to execute the program.


Entire problem statement can be found at [AdventOfCode](https://adventofcode.com/2020/day/2).