#include "../include/circle2.h"
#include "../include/point2.h"

#include <cmath>
#define M_PI 3.14159265358979323846 

Circle2::Circle2(Point2 np1, float nr) : p1 {np1}, r {nr} {
    if (r < 0) {
        r = 0;
    }
}

float Circle2::circumference () { //tagastab ringi ümbermõõdu
    return (float)M_PI * 2 * r;
}

float Circle2::area() { //tagastab ringi pindala
    return (float)M_PI * (float)pow(r, 2);
}

// tagastab true, kui antud punkt on ringjoone peal või sees, vastasel juhul false (kasuta punkti distanceFrom meetodit)
bool Circle2::contains (Point2 p) { 
    if (p1.distanceFrom(p) <= r) {
        return true;
    }
    return false;
}

//tagastab true, kui antud lõik on ringjoone sees (sh tipud joone peal), vastasel juhul false (kasuta distanceFrom meetodit)
bool Circle2::contains (Line2 l) {
    if (p1.distanceFrom(l.p1) <= r && p1.distanceFrom(l.p2) <= r) {
        return true;
    }
    return false;
}

//korrutab ringi raadiuse antud väärtusega
void Circle2::scale (float factor) { //vaata kas raadius posittven muidu 0
        if (factor < 0) {
            r = 0;
        } else {
            r *= factor;
        }

}

// TODO: Operators...

ostream& operator<<(ostream& os, const Circle2& c){
    os << "(" << c.p1 << ", " << c.r << ")";
    return os;
}
