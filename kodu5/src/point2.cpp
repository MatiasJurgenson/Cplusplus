#include "../include/point2.h"
#include <cmath>


Point2::Point2(float nx, float ny) : x {nx}, y {ny} {}

float Point2::distanceFrom (Point2 p) {
	// siia kood
	float kaugus = (float)sqrt(pow((p.x - x), 2) + pow((p.y -y), 2));

	return kaugus;
}

// TODO: Operators...

ostream& operator<<(ostream& os, const Point2& p){
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}
