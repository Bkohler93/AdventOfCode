#include <string>
#include <iostream>


//take in a string of ints, make sure
// there are two values that are the same
// and that no value is larger than its previous
bool check(std::string val)
{
	bool correct = false;

	int j = 1;
	int val_length = val.length();

	for (int i = 0; i < (val_length - 1); i++)
	{
		//check for adjacent chars
		if (val[i] == val[j])
			correct = true;

		//if decreasing, aka i'th char is greater than j'th char
		//set correct to false and break out of loop
		else if (val[i] > val[j])
		{
			correct = false;
			return correct;
		}
		j++;
	}

	return correct;
}



//set range of problem and check for valid passwords
int main()
{

	//initialize counter
	int count = 0;

	//set range
	int min = 147981;
	int max = 691423;

	//loop all numbers min through max
	for (int i = min; i <= max; i++)
	{
		if (check(std::to_string(i)))
			count++;
	}
	std::cout << "Out of " << max - min << " possible answers ";
	std::cout << "There are " << count << " valid passwords.\n";

	return 0;
}