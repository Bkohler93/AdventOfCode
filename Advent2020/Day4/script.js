const fs = require('fs')    //readfile function defined in fs module



var lines = fs.readFileSync('inputs.txt', 'utf8').split('\n');

var rowRegExp = /[FB]/g;
var colRegExp = /[RL]/g;
var lengthLines = lines.length;

const findSeatId = (line) => {

    let rowChars = line.match(rowRegExp);
    let lowRow = 0;
    let highRow = 127;

    //iterate to find row
    rowChars.forEach(letter => {
        if (letter === 'F') {
            highRow = Math.floor(highRow - (highRow-lowRow)/2);
            // highRow -= Math.ceil((highRow - lowRow)/2);
        }
        else {
            lowRow = Math.ceil(lowRow + (highRow - lowRow)/2);
            // lowRow += Math.ceil((highRow - lowRow)/2);
        }
    })

    let colChars = line.match(colRegExp);
    let lowSeat = 0;
    let highSeat = 7;
    colChars.forEach(letter => {
        if (letter === 'L') {
            highSeat = Math.floor(highSeat - (highSeat - lowSeat)/2);
            // highSeat -= Math.ceil((highSeat - lowSeat)/2);
        }
        else {
            lowSeat = Math.ceil(lowSeat + (highSeat - lowSeat)/2);
            // lowSeat += Math.ceil((highSeat - lowSeat)/2);
        }
    })
    return (lowRow * 8 + lowSeat);
};

let ans = [];
for (let i = 0; i < lengthLines; i++) {
    ans.push(findSeatId(lines[i]));
}

let solution = Math.max(...ans);

console.log(`solution is ${solution}`);


for (let i = 0; i <  822; i++) {
    if (!ans.includes(i)) console.log(i);
}