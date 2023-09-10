#include "../include/line2.h"
#include "../include/point2.h"

Line2::Line2(Point2 np1, Point2 np2) : p1 {np1}, p2 {np2} {}

float Line2::length() {
    return p1.distanceFrom(p2);
}

// TODO: Operators...

ostream& operator<<(ostream& os, const Line2& l){
    os << "(" << l.p1 << " - " << l.p2 << ")";
    return os;
}