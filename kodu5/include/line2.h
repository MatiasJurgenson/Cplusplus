#ifndef LINE2_H
#define LINE2_H
#include "point2.h"
#include <iostream>
using std::ostream;

class Line2 {

public:
	Point2 p1{};
	Point2 p2{};

	Line2() = default;
	Line2(Point2 np1, Point2 np2);
	float length ();
	friend ostream& operator<<(ostream& os, const Line2& l);
};
#endif
