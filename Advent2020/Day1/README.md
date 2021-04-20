Type "make" while in working directory, then "./run" to run the program (requires g++ compiler).

If you don't have g++ compiler but do have a cpp compiler, then use your compiler of choice, compiling with "[compiler] *.cpp -o run"


This is my solution to the Day 1 challenege of Advent of Code 2020.

I decided to utilize std::map to drop the time complexity from O(n^2) for part 1 and O(n^3) for part 2 to O(n) for part 1 and O(n^2) for part 2. I created keys to be the integer needed for the key+value to equal the final sum required. This way when the program comes across a number needed to complete the summation, that number is already found as a key in the map.

SUMMARY:
Take in an input of integers
PART 1: find two entries that add up to 2020 and then multiply them together to get the final answer
PART 2: find three entries that add up to 2020 and then multiply them together to get the final answer