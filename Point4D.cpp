//
// Created by Oz on 5/26/2020.
//

#include "Point4D.h"
#include <array> //TODO: remove
#include <iostream> //TODO: remove
#include <sstream>

using namespace std; //TODO: remove

Point4D result;

Point4D::Point4D() { //default constructor
    point[0] = point[1] = point[2] = point[3] = 0;
}

Point4D::Point4D(double arg1) { // 1 parameter constructor
    point[0] = arg1;
    point[1] = point[2] = point[3] = 0;
}

Point4D::Point4D(double arg1, double arg2) { // 2 parameter constructor
    point[0] = arg1;
    point[1] = arg2;
    point[2] = point[3] = 0;
}

Point4D::Point4D(double arg1, double arg2, double arg3) { // 3 parameter constructor
    point[0] = arg1;
    point[1] = arg2;
    point[2] = arg3;
    point[3] = 0;
}

Point4D::Point4D(double arg1, double arg2, double arg3, double arg4) { //4 parameter constructor
    point[0] = arg1;
    point[1] = arg2;
    point[2] = arg3;
    point[3] = arg4;
}

Point4D::Point4D(const Point4D& aPoint) {
    this->point[0] = aPoint.point[0];
    this->point[1] = aPoint.point[1];
    this->point[2] = aPoint.point[2];
    this->point[3] = aPoint.point[3];
}

Point4D &Point4D::inverse() const { //inverse function

    //static Point4D inverted; //TODO: Find alternative to static

    double B = this->point[0] * this->point[2] - this->point[1] * this->point[3];
    B = 1 / B;

    result.point[0] = this->point[2] * B;
    result.point[1] = -this->point[1] * B;
    result.point[2] = this->point[0] * B;
    result.point[3] = -this->point[3] * B;

    return result;
}

Point4D& Point4D::operator*(const Point4D& aPoint){

    result.point[0] = this->point[0] * aPoint.point[0] + this->point[1] * aPoint.point[3];
    result.point[1] = this->point[0] * aPoint.point[1] + this->point[1] * aPoint.point[2];
    result.point[2] = this->point[3] * aPoint.point[1] + this->point[2] * aPoint.point[2];
    result.point[3] = this->point[3] * aPoint.point[0] + this->point[2] * aPoint.point[3];

    return result;
}

std::string Point4D::toString() const { //toString function

    stringstream strStream;
    strStream << "[" << point[0] << "," << point[1] << "," << point[2] << "," << point[3] << "]";
    return strStream.str();
}

std::ostream &operator<<(std::ostream &sout, const Point4D &aPoint) {
    sout << aPoint.toString();
    return sout;
}

int main() {

    Point4D m1(2, 3, 4, 5);
    //cout<<"hello" <<endl;

    Point4D m2 = m1.inverse();
    Point4D m3 = m1 * m2;
    cout << m3;
}