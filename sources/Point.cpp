//
// Created by shani on 16/05/2023.
//

#include <cmath>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include "Point.hpp"
using namespace std;

double Point::distance(const Point& other) const {
    double dx = this->_x - other._x;
    double dy = this->_y - other._y;

    return sqrt((dx * dx) + (dy * dy));
}

string Point::print() const{
    stringstream ss;
    ss << "(" << this->_x << ", " << this->_y << ")";
    return ss.str();
}

Point Point::moveTowards(const Point& curr, const Point& dest, const double range) {
    if(range < 0){
        throw invalid_argument("range must be a non-negative number");
    }

    double distanceCurrToDest = curr.distance(dest);

    // if the destination point is in the range so return dest point
    if(distanceCurrToDest <= range){
        return dest;
    }
    else{
        // the range is too small from dest point
        // find the closet point to dest point that in range
        double dx = dest._x - curr._x;
        double dy = dest._y - curr._y;
        double scale = range / distanceCurrToDest;

        double closetX = curr._x + (dx * scale);
        double closetY = curr._y + (dy * scale);
        return Point(closetX, closetY);
    }
}
