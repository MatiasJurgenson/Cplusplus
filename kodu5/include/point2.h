#ifndef POINT2_H
#define POINT2_H


#include <iostream>
using std::ostream;

class Point2 {

public:
	float x{};
	float y{};

	Point2() = default;
	Point2(float nx, float ny);
	float distanceFrom (Point2 p);
	friend ostream& operator<<(ostream& os, const Point2& p);
};
#endif
