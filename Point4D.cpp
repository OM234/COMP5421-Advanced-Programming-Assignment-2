//
// Created by Oz on 5/26/2020.
//

#include "Point4D.h"
#include <array> //TODO: remove
#include <iostream> //TODO: remove
#include <sstream>

using namespace std; //TODO: remove

Point4D result;
double Point4D::tolerance = 1.0E-6;

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

Point4D::Point4D(const Point4D &aPoint) = default; // copy constructor
//    this->point[0] = aPoint.point[0];
//    this->point[1] = aPoint.point[1];
//    this->point[2] = aPoint.point[2];
//    this->point[3] = aPoint.point[3];


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

Point4D &operator*(const Point4D &pointA, const Point4D &pointB) {

    result.point[0] = pointA.point[0] * pointB.point[0] + pointA.point[1] * pointB.point[3];
    result.point[1] = pointA.point[0] * pointB.point[1] + pointA.point[1] * pointB.point[2];
    result.point[2] = pointA.point[3] * pointB.point[1] + pointA.point[2] * pointB.point[2];
    result.point[3] = pointA.point[3] * pointB.point[0] + pointA.point[2] * pointB.point[3];

    return result;
}

Point4D &operator*(double a, const Point4D &aPoint) {

    result.point[0] = a * aPoint.point[0];
    result.point[1] = a * aPoint.point[1];
    result.point[2] = a * aPoint.point[2];
    result.point[3] = a * aPoint.point[3];

    return result;
}

Point4D &operator*(const Point4D &aPoint, double a) {
    return a * aPoint;
}

Point4D &operator+(const Point4D &pointA, const Point4D &pointB){
    result.point[0] = pointA.point[0] + pointB.point[0];
    result.point[1] = pointA.point[1] + pointB.point[1];
    result.point[2] = pointA.point[2] + pointB.point[2];
    result.point[3] = pointA.point[3] + pointB.point[3];

    return result;
}

Point4D &operator+(double a, const Point4D& pointA){ //scalar addition operator overload
    result.point[0] = pointA.point[0] + a;
    result.point[1] = pointA.point[1] + a;
    result.point[2] = pointA.point[2] + a;
    result.point[3] = pointA.point[3] + a;

    return result;
}

Point4D &operator+(const Point4D& pointA, double a) { //scalar addition operator overload
    return a + pointA;
}

Point4D &operator-(const Point4D & pointA, const Point4D& pointB) { //binary subtraction operator overload

    result.point[0] = pointA.point[0] - pointB.point[0];
    result.point[1] = pointA.point[1] - pointB.point[1];
    result.point[2] = pointA.point[2] - pointB.point[2];
    result.point[3] = pointA.point[3] - pointB.point[3];

    return result;
}

Point4D &operator-(double a, const Point4D & pointA) { //scalar subtraction operator overload

    result.point[0] = a - pointA.point[0];
    result.point[1] = a - pointA.point[1];
    result.point[2] = a - pointA.point[2];
    result.point[3] = a - pointA.point[3];

    return result;
}
Point4D &operator-(const Point4D & pointA, double a) { //scalar subtraction operator overload
    result.point[0] = pointA.point[0] - a;
    result.point[1] = pointA.point[1] - a;
    result.point[2] = pointA.point[2] - a;
    result.point[3] = pointA.point[3] - a;

    return result;
}

bool Point4D::operator==(const Point4D &aPoint) {
    Point4D tempSubtraction;
    double absSubVal;

    tempSubtraction.point[0] = this->point[0] - aPoint.point[0];
    tempSubtraction.point[1] = this->point[1] - aPoint.point[1];
    tempSubtraction.point[2] = this->point[2] - aPoint.point[2];
    tempSubtraction.point[3] = this->point[3] - aPoint.point[3];

    absSubVal = std::abs(tempSubtraction.point[0]) + std::abs(tempSubtraction.point[1])
                + std::abs(tempSubtraction.point[2]) + std::abs(tempSubtraction.point[3]);

    return absSubVal <= tolerance;
}

Point4D &Point4D::operator=(const Point4D &) = default; //assignment operator overload

Point4D &Point4D::operator+() { //unary plus operator overload
    return *this;
}

Point4D &Point4D::operator-() { //unary minus operator overload

    *this = *this * -1;
    return *this;
}

Point4D &Point4D::operator++() { //pre-increment operator overload

}

void Point4D::setTolerance(double tol) {
    tolerance = std::abs(tol);
}

double Point4D::getTolerance() {
    return tolerance;
}

//
//const array<double, 4> Point4D::getPoint() const {
//    return point;
//}

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
    Point4D m2(4, 6, 8, 10);
    //cout<<"hello" <<endl;
    Point4D m3 = m1 - 5.45;
    cout<< m3;
}