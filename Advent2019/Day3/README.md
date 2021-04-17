

SUMMARY:
This is my program to complete advent of code 2019 day 3. This challenge
consists of finding the shortest intersection's distance to a central point
between two wires. The input I have to work with are a series of instructions on distance and direction (i.e R5 is "move 5 positions from current to the right").

Uses system of points (a wire is positioned on a (class) Board, with the wire running
between (class) Points 

Boards consist of a wire (wire_1 and wire_2), each wire consisting of a string of points.

Each point has four pointers in L/R/U/D directions, as well as a pair of coordinates (int x, y).

Board is filled through input from "inputs.txt."

After filling in first wire, checks are conducted after placing every new point in second wire to see if 
coordinates are matching (if so, set the sum of these coordinates to val of minimum distance).

PART 1: Find the minimum distance from the origin to an intersection between the two wires.

PART 2:
Find the fewest combined steps each wire must take to reach an intersection.

SOLUTION: I filled in wire 1 from the inputs first, using loops to get every coordinate given a direction (R50 meant I included all x coords 0-50).

When filling in wire 2, I checked for intersections and counted the number of steps taken to reach that intersections. Each new point of wire 2 is printed to console to aid in observing runtime.