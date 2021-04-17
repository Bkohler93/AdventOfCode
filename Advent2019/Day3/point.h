#ifndef POINT_H
#define POINT_H

class Point {
private:
	int x;
	int y;

public:
	Point* up;
	Point* down;
	Point* left;
	Point* right;

	int steps_to_points;

	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(y), up(nullptr), down(nullptr), left(nullptr), right(nullptr), steps_to_points(0) {}

	//getters for coords
	const int get_x() {return x;}
	const int get_y() {return y;}

};

#endif