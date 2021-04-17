#include "board.h"

int Board::steps_wire_1 = 0;
int Board::steps_wire_2 = 0;

//destructor
Board::~Board() 
{
	//check if wires are already not there
	if (wire_1 == nullptr && wire_2 == nullptr) return;
	
	//traverse wire_1 and delete nodes along the way
	del_wire_1(wire_1);

}

//recursive delete func for wire deletion
void Board::del_wire_1(Point* wire_1_copy)
{
	// traverse until all sides are null
	if (wire_1_copy->right != nullptr) 
	{
		del_wire_1(wire_1_copy->right);
	}

	else if (wire_1_copy->left != nullptr) del_wire_1(wire_1_copy->left);

	else if (wire_1_copy->up != nullptr) del_wire_1(wire_1_copy->up);

	else if (wire_1_copy->down != nullptr) del_wire_1(wire_1_copy->down);

	//base case reached if passed all above, so end recurisve call
	else 
	{
		delete wire_1_copy;
		return;
	}

	//set all pointers to null and delete point
	wire_1_copy->right = nullptr;
	wire_1_copy->left = nullptr;
	wire_1_copy->down = nullptr;
	wire_1_copy->up = nullptr;

	delete wire_1_copy;
}


//fill wire 1 
void Board::fill_wire_1(std::stringstream &wire_1_stream)
{
	//set up coords where wire originates from
	int x = 0;
	int y = 0;

	//iniitialize wire 1 at new point
	wire_1 = new Point(x, y);
	wire_1->steps_to_points = 0;
	//create copy of wire to handle traversing
	Point* copy_wire = wire_1;

	//read from wire_1_stream until stream is empty
	std::string newLength;

	while (std::getline(wire_1_stream, newLength, ','))
	{

		if (newLength[0] == 'R')
		{
			newLength.erase(0, 1);
			for (int i = 0; i < std::stoi(newLength); i++){
				copy_wire->right = new Point(++x, y);
				copy_wire = copy_wire->right;
				steps_wire_1++;
				copy_wire->steps_to_points = steps_wire_1;
	//std::cout << "steps to this point " << copy_wire->steps_to_points << std::endl;

			}
		}	

		else if (newLength[0] == 'U')
		{
			newLength.erase(0,1);
			for (int i = 0; i < std::stoi(newLength); i++)
			{
				copy_wire->up = new Point(x, ++y);
				copy_wire= copy_wire->up;
				steps_wire_1++;
				copy_wire->steps_to_points = steps_wire_1;	
	//std::cout << "steps to this point " << copy_wire->steps_to_points << std::endl;
			}
		}

		else if (newLength[0] == 'D')
		{
			newLength.erase(0, 1);
			for (int i = 0; i < std::stoi(newLength); i++)
			{
				copy_wire->down = new Point(x, --y);
				copy_wire = copy_wire->down;
				steps_wire_1++;
				copy_wire->steps_to_points = steps_wire_1;	
	//std::cout << "steps to this point " << copy_wire->steps_to_points << std::endl;
			}
		}

		else if (newLength[0] == 'L')
		{
			newLength.erase(0, 1);

			for (int i = 0; i < std::stoi(newLength); i++)
			{
				copy_wire->left = new Point(--x, y);
				copy_wire = copy_wire->left;
				steps_wire_1++;
				copy_wire->steps_to_points = steps_wire_1;	
	//std::cout << "steps to this point " << copy_wire->steps_to_points << std::endl;
			}
		}

		else
		{
			std::cout << "misread file, invalid command found.\n";
		}

	}
}

//fill wire 2
void Board::fill_wire_2(std::stringstream &wire_2_stream)
{
	//set up coords where wire originates from
	int x = 0;
	int y = 0;

	//initialize wire 2 at new point
	wire_2 = new Point(x, y);

	//create copy of wire to handle traversin
	Point* copy_wire = wire_2;
	//steps_wire_2++;
	//read from wire 2 stream until stream is empty
	std::string newLength;

	while (std::getline(wire_2_stream, newLength, ','))
	{	
		std::cout << newLength << std::endl;
		if (newLength[0] == 'R')
		{
			newLength.erase(0, 1);

			for (int i = 0; i < std::stoi(newLength); i++)
			{
				copy_wire->right = new Point(++x, y);
				steps_wire_2++;
				//check if matching coords (an intersection of wires)
				if (check_cross(x, y)) min_dist = std::min(min_dist, (std::abs(x) + std::abs(y)));

				copy_wire = copy_wire->right;
			}
		}	

		else if (newLength[0] == 'U')
		{
			newLength.erase(0, 1);


			for (int i = 0; i < std::stoi(newLength); i++)
			{
				copy_wire->up = new Point(x, ++y);
				steps_wire_2++;
				if (check_cross(x, y)) min_dist = std::min(min_dist, (std::abs(x) + std::abs(y)));
				copy_wire= copy_wire->up;
			}
		}

		else if (newLength[0] == 'D')
		{
			newLength.erase(0, 1);

			for (int i = 0; i < std::stoi(newLength); i++)
			{
				copy_wire->down = new Point(x, --y);
				steps_wire_2++;
				if (check_cross(x, y)) min_dist = std::min(min_dist, (std::abs(x) + std::abs(y)));
				copy_wire = copy_wire->down;
			}
		}

		else if (newLength[0] == 'L')
		{
			newLength.erase(0, 1);

			for (int i = 0; i < std::stoi(newLength); i++)
			{
				copy_wire->left = new Point(--x, y);
				steps_wire_2++;
				if (check_cross(x, y)) min_dist = std::min(min_dist, (std::abs(x) + std::abs(y)));
				copy_wire = copy_wire->left;
			}
		}

		else
		{
			std::cout << "misread file, invalid command found.\n";
		}
	}
}


//check if wire 2's new coordinates match coordinates in wire 1
bool Board::check_cross(int x, int y)
{

	//create bool to check if crosed, assume this is false
	bool crossed = false;

	//create copy of wire 1 head to use in traversal when checking for matching coords
	Point* copy_wire1 = wire_1;
	//recursive call to check if coords match
	check_coords_wire_1(copy_wire1, crossed, x, y);

	return crossed;
}

//recursive function to check if wires cross at x,y location
void Board::check_coords_wire_1(Point* &copy_wire1, bool& crossed, int x, int y)
{
	
	//base step
	if ( (copy_wire1 == nullptr) || (copy_wire1->up == nullptr && copy_wire1->down == nullptr && copy_wire1->left == nullptr && copy_wire1->right == nullptr))
		return;
	if (x != 0 && y != 0) 
	{
		//loop through wire 1 coords	
		if (copy_wire1->get_x() == x && copy_wire1->get_y() == y)
		{
			min_steps = check_min(min_steps, (steps_wire_2) + copy_wire1->steps_to_points);
			std::cout << "new min steps of " << min_steps << std::endl;
			crossed = true;
			std::cout << "match" << std::endl;
		}
	}

	//recursive call based on which way wire goes
	if (copy_wire1->up != nullptr) check_coords_wire_1(copy_wire1->up, crossed, x, y);

	else if (copy_wire1->down != nullptr) check_coords_wire_1(copy_wire1->down, crossed, x, y);

	else if (copy_wire1->left != nullptr) check_coords_wire_1(copy_wire1->left, crossed, x, y);

	else if (copy_wire1->right != nullptr) check_coords_wire_1(copy_wire1->right, crossed, x, y);

	else
		std::cout << "Error" << std::endl;

}



//checks minimum value between two integers
int Board::check_min(int min_steps, int test_min_steps){

	return test_min_steps < min_steps ? test_min_steps : min_steps;
}