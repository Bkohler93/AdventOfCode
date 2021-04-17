#include <string>
#include <iostream>
#include <map>


//one function to make sure there are no decreasing values
bool not_decreasing(std::string val)
{
	//second iterator
	int j = 1;

	//find length of val
	int len = val.length();

	//find if first value is larger than afollowing val (this means its decreasing)
	for (int i = 0; i < len - 1; i++) {
		if (val[i] > val[j++])
			return false;
	}

	//passed for loop, success
	return true;
}

//one function to be sure matching numbers are only in pairs
bool check_pair(std::string val)
{
	//map to store chars and amount of times they appear in val
	std::map<char, int> myMap;

	//store length of val
	int len = val.length();

	//loop through val storing chars into map
	for (int i = 0; i < len; i++)
	{
		myMap[val[i]]++;
	}

	for (auto it : myMap)
	{
		if (it.second == 2)
			return true;
	}

	return false;
}



int main() {
	
	//initialize counter
	int count = 0;

	//set range
	int min = 147981;
	int max = 691423;

	//loop all numbers min through max
	for (int i = min; i <= max; i++)
	{
		if (not_decreasing(std::to_string(i)) && check_pair(std::to_string(i)))
			count++;
	}

	std::cout << "Out of " << max - min << " possible answers ";
	std::cout << "There are " << count << " valid passwords.\n";

	return 0;

}