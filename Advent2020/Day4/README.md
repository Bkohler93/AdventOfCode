This is my solution to Advent of Code 2020: Day 4.

The problem consisted of reading in a list of passport fields structured like "cid:2020 pid:22222"
Passport lines were separated by two newline characters.

I decided to make a passport class which would hold the number of fields a passport has as well as 
a dictionary of field:field_values to check requirements for each passport.

'index.html' contains a better description of the exact requirements. Processing the inputs and conducting each part is also found on this webpage.