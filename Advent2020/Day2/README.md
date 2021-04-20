## About
This is my solution to the Advent of Code 2020 Day 3 Challenege. This problem asks me to parse text containing all periods '.' and pound signs '#'.
The input is shaped as as grid, and is asking how many '#' I will land on if I start at the top-left '.' and move across the grid with a given slope.
The full problem statement can be found at [AdventOfCode](https://adventofcode.com/2020/day/3), and the full input can be found in "inputs.txt". 
The input is one large column of periods and pound signs, and when the current position is going to move too far to the right, it wraps
back to the start of the column and continues to move from there. An example of the grid is down below:

..#..#....#.
.#.....#....
#...#..#..#.
..#..#...#..
.#.#....#...

### Part One Rules:
1. Use a slope of right 3, down 1
2. Return the number of '#' hit

### Part Two Rules:
1. Do the same as Part One except with slopes of...
    a. right 1, down 1
    b. right 3, down 1.
    c. right 5, down 1.
    d. right 5, down 1.
    e. right 1, down 2.
2. Return the product of each of the slopes' number of '#' landed on.


### Thought Process:
- parse text from file, store into vector of strings in Grid class
- count number of hits using different slopes given
    - when cursor is going to reach end of a string, move y up 1 unit, x over (x-slope - length - currIndex)