let inputButton = document.querySelector('#input-button');
let processPartOneButton = document.querySelector('#part-one-button');
let processPartTwoButton = document.querySelector('#part-two-button');
let partOneAnswer = document.querySelector('#part-one-answer');
let partTwoAnswer = document.querySelector('#part-two-answer');
var passports = [];
var inputsProcessed = false;
var partOneAns = 0;
var partTwoAns = 0;

function Passport() {
    this.eachField = {};
    this.numFields = 0;
}


/* accepts in new property in form "cid:2020"
 * and stores a new key/value into Passport.eachField{}
*/
Passport.prototype.processProperty = function (property) {
    let propFields = property.split(':');
    this.eachField[propFields[0]] = propFields[1];
}


Passport.prototype.hasEightFields = function() {
    return (this.numFields === 8);
}

Passport.prototype.hasSevenNoCid = function() {

    return (this.numFields === 7 && !this.eachField.hasOwnProperty('cid'));
}

Passport.prototype.correctNumFields = function() {
    return (this.hasEightFields() || this.hasSevenNoCid());
}

Passport.prototype.validated = function() {

    if (!this.correctNumFields()) return false;

    if (this.invalidBirthYear()) return false;
    if (this.invalidIssueYear()) return false;
    if (this.invalidExpYear()) return false;
    if (this.invalidHeight()) return false;
    if (this.invalidHairColor()) return false;
    if (this.invalidEyeColor()) return false;
    if (this.invalidPassportId()) return false;
    
    return true;
}

Passport.prototype.invalidBirthYear = function() {
    let birthYear = +this.eachField['byr'];

    if (birthYear < 1920 || birthYear > 2002) return true;

    return false;
}

Passport.prototype.invalidIssueYear = function() {
    let issueYear = +this.eachField['iyr'];

    if (issueYear < 2010 || issueYear > 2020) return true;

    return false;
}

Passport.prototype.invalidExpYear = function() {
    let expYear = +this.eachField['eyr'];

    if (expYear < 2020 || expYear > 2030) return true;

    return false;
}

Passport.prototype.invalidHeight = function() {
    let cmRegExp = /cm$/;
    let inRegExp = /in$/;
    let heightField = this.eachField['hgt'];
    let heightLength = heightField.length - 2;
    
    if (cmRegExp.test(heightField)) {
        let heightCm = +heightField.slice(0,heightLength);
        return (invalidHeightCm(heightCm));
    }

    else if (inRegExp.test(heightField)) {
        let heightIn = +heightField.slice(0, heightLength);
        return (invalidHeightIn(heightIn));
    }

    return true;
}

Passport.prototype.invalidHairColor = function() {
    let hairColor = this.eachField['hcl'];

    let validHairColorRegExp = /^#([0-9|(a-f)]{6})$/;
    return !(validHairColorRegExp.test(hairColor));

}

Passport.prototype.invalidEyeColor = function() {
    let eyeColor = this.eachField['ecl'];

    let validEyeColorRegExp = /^(amb)|(blu)|(brn)|(gry)|(grn)|(hzl)|(oth)$/;
    return !(validEyeColorRegExp.test(eyeColor));
}

Passport.prototype.invalidPassportId = function() {
    let passID = this.eachField['pid'];

    let validPassportIdRegExp = /^[0-9]{9}$/;
    return !(validPassportIdRegExp.test(passID));
}


function invalidHeightCm(heightCm) {
    return (heightCm < 150 || heightCm > 193);
}

function invalidHeightIn(heightIn) {
    return (heightIn < 59 || heightIn > 76);
}

inputButton.onclick = processInput;
function processInput() {

    var passportLineArray = getInputLines();
    
    fillPassportArray(passportLineArray);
}

function getInputLines() {

    var inputText = document.querySelector('.input-field').value;

    let textLines = inputText.split('\n\n');

    return textLines;
}

function fillPassportArray(passportLineArray) {

    let separateLinesRegEx = /\n|\s/;
    
    for (let passportLine of passportLineArray) {
        
        let fields = passportLine.split(separateLinesRegEx);

        let newPassport = new Passport();
        
        for (let field of fields) {
            newPassport.numFields++;
            newPassport.processProperty(field);
        }

        passports.push(newPassport);
    }
    alert('Passports created, ready to do Part One and Two.');
    inputsProcessed = true;
}




processPartOneButton.onclick = () => {
    
    inputsProcessed ? processPartOne() : alert('Process inputs before doing part one.');
}

function processPartOne() {

    for (let passport of passports) {
        if (passport.correctNumFields()) {
            partOneAns++;
        }
    }

    displayPartOneAns();
}


function displayPartOneAns() {
    console.log(partOneAns);
    partOneAnswer.value = partOneAns;
}

function hasEightFields(passport) {
    return (passport.numFields === 8);
}




processPartTwoButton.onclick = () => {

    inputsProcessed ? processPartTwo() : alert('Process inputs before doing part two.');
}

function processPartTwo() {

    for (let passport of passports) {
        if (passport.validated()) partTwoAns++;
    }

    displayPartTwoAns();
}

function displayPartTwoAns() {
    console.log(partTwoAns);
    partTwoAnswer.value = partTwoAns;
}