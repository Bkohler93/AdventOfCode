TO RUN: requires cpp compiler - type "g++ [or similar] main.cpp -o run" then enter "./run" to test part 1
        type "g++ [or similar] mainpt2.cpp -o run" then enter "./run" to test part 2

This is the AdventofCode 2019 Day 4 challenege. Consists of finding how many passwords are valid given the criteria from the problem statment.

PROBLEM SUMMARY:

PART ONE
Find the number of valid passwords between the range 147981-691423 that follow the set of rules outlined below
1) Value is within the range given
2) Two adjacent digits are the same (like 22 in 122345)
3) Going from left to right, the digits never decrease: only increase or stay the same

PART TWO
Using the same criteria, find the number of valid passwords, with one challenege
1) The two adjacent matching digits cannot be part of a larger group of matching digits
example: 123444 would be false because 444 there is an extra 4
        111122 would be true because there are still two pairs of two ones.