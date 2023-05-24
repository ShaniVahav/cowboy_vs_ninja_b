//
// Created by shani on 16/05/2023.
//

#ifndef COWBOY_VS_NINJA_A_POINT_H
#define COWBOY_VS_NINJA_A_POINT_H

/// Class that represents a place of an character on the board

class Point {
public:
    explicit Point(double x = 0, double y = 0) : _x(x), _y(y) {}

    // get another point and return the distance from the other point to this point
    double distance (const Point& other) const;

    // print the point
    std::string print() const;

    // get current point, destination point and range.
    // return the point which closet to the destination point and in range
    static Point moveTowards(const Point& curr, const Point& dest, double range);

    double get_x() const {return this->_x;}

    double get_y() const {return this->_y;}

private:
    double _x;
    double _y;
};


#endif //COWBOY_VS_NINJA_A_POINT_H
