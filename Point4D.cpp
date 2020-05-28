//
// Created by Oz on 5/26/2020.
//

#include "Point4D.h"
#include <array> //TODO: remove
#include <iostream> //TODO: remove
#include <sstream>

using namespace std; //TODO: remove

Point4D result1;
Point4D result2;
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

Point4D::Point4D(const Point4D &pointA) = default; // copy constructor

Point4D &Point4D::inverse() const { //inverse function

    double B = this->point[0] * this->point[2] - this->point[1] * this->point[3];
    B = 1 / B;

    result1.point[0] = this->point[2] * B;
    result1.point[1] = -this->point[1] * B;
    result1.point[2] = this->point[0] * B;
    result1.point[3] = -this->point[3] * B;

    return result1;
}
Point4D &Point4D::operator*=(const Point4D & pointA) { //multiplication compound assignment operator overload

    Point4D temp;

    temp.point[0] = this->point[0] * pointA.point[0] + this->point[1] * pointA.point[3];
    temp.point[1] = this->point[0] * pointA.point[1] + this->point[1] * pointA.point[2];
    temp.point[2] = this->point[3] * pointA.point[1] + this->point[2] * pointA.point[2];
    temp.point[3] = this->point[3] * pointA.point[0] + this->point[2] * pointA.point[3];

    *this = temp;

    return temp;
}

Point4D &Point4D::operator*=(double a) { //multiplication compound assignment operator overload

    this->point[0] = this->point[0] * a;
    this->point[1] = this->point[1] * a;
    this->point[2] = this->point[2] * a;
    this->point[3] = this->point[3] * a;

    return *this;
}

Point4D &operator*(const Point4D &pointA, const Point4D &pointB) { //binary multiplication operator overload

    Point4D temp = pointA;
    temp *= pointB;
    result1 = temp;

    return result1;
}

Point4D &operator*(double a, const Point4D &pointA) { //scalar multiplication operator overload

    result1 = pointA;
    result1 *= a;
    return result1;
}

Point4D &operator*(const Point4D &pointA, double a) { //scalar multiplication operator overload

    return a * pointA;
}

Point4D &Point4D::operator/=(const Point4D & pointA) { //division compound assignment operator overload

    *this *= pointA.inverse();

    return *this;
}

Point4D &Point4D::operator/=(double a) { //division compound assignment operator overload

    *this *= 1/a;

    return *this;
}

Point4D &operator/(const Point4D & pointA, const Point4D & pointB) { //binary division operator overload TODO: Does this work?

    return pointA * (pointB.inverse());
}

Point4D &operator/(double a , const Point4D & pointA) { //scalar division operator overload

    return a * (pointA.inverse());
}
Point4D &operator/(const Point4D & pointA, double a) { //scalar division operator overload

    return pointA * (1/a);
}

Point4D &Point4D::operator+=(const Point4D & pointA){ //addition compound assignment operator overload

    this->point[0] = this->point[0] + pointA.point[0];
    this->point[1] = this->point[1] + pointA.point[1];
    this->point[2] = this->point[2] + pointA.point[2];
    this->point[3] = this->point[3] + pointA.point[3];

    return *this;
}

Point4D &Point4D::operator+=(double a){ //addition compound assignment operator overload

    this->point[0] = this->point[0] + a;
    this->point[1] = this->point[1] + a;
    this->point[2] = this->point[2] + a;
    this->point[3] = this->point[3] + a;

    return *this;
}

Point4D &operator+(const Point4D &pointA, const Point4D &pointB) { //binary addition operator overload

    result1 = pointA;
    result1 += pointB;
    return result1;
}

Point4D &operator+(double a, const Point4D &pointA) { //scalar addition operator overload

//    Point4D temp{a,a,a,a};
//    temp += pointA;
//    result1 = temp;
//    result1.point[0] = pointA.point[0] + a;
//    result1.point[1] = pointA.point[1] + a;
//    result1.point[2] = pointA.point[2] + a;
//    result1.point[3] = pointA.point[3] + a;
    result1 = pointA;
    result1 += a;
    return result1;
}

Point4D &operator+(const Point4D &pointA, double a) { //scalar addition operator overload

    return a + pointA;
}

Point4D &Point4D::operator-=(const Point4D & pointA) { //subtraction compound assignment operator overload

    this->point[0] = this->point[0] - pointA.point[0];
    this->point[1] = this->point[1] - pointA.point[1];
    this->point[2] = this->point[2] - pointA.point[2];
    this->point[3] = this->point[3] - pointA.point[3];

    return *this;
}

Point4D &operator-(const Point4D &pointA, const Point4D &pointB) { //binary subtraction operator overload

//    result1.point[0] = pointA.point[0] - pointB.point[0];
//    result1.point[1] = pointA.point[1] - pointB.point[1];
//    result1.point[2] = pointA.point[2] - pointB.point[2];
//    result1.point[3] = pointA.point[3] - pointB.point[3];
    Point4D temp = pointA;
    temp -= pointB;
    result1 = temp;
    return result1;
}

Point4D &operator-(double a, const Point4D &pointA) { //scalar subtraction operator overload

    Point4D temp{a, a, a ,a};
    temp -= pointA;
    result1 = temp;
    return result1;
}

Point4D &operator-(const Point4D &pointA, double a) { //scalar subtraction operator overload

    Point4D temp1 = {a,a,a,a}; //right hand side operand
    Point4D temp2 = pointA; // left hand side operand
    temp2 -= temp1;
    result1 = temp2;
//    result1.point[0] = pointA.point[0] - a;
//    result1.point[1] = pointA.point[1] - a;
//    result1.point[2] = pointA.point[2] - a;
//    result1.point[3] = pointA.point[3] - a;

    return result1;
}

bool Point4D::operator==(const Point4D &pointA) {

    Point4D tempSubtraction;
    double absSubVal;

    tempSubtraction.point[0] = this->point[0] - pointA.point[0];
    tempSubtraction.point[1] = this->point[1] - pointA.point[1];
    tempSubtraction.point[2] = this->point[2] - pointA.point[2];
    tempSubtraction.point[3] = this->point[3] - pointA.point[3];

    absSubVal = std::abs(tempSubtraction.point[0]) + std::abs(tempSubtraction.point[1])
                + std::abs(tempSubtraction.point[2]) + std::abs(tempSubtraction.point[3]);

    return absSubVal <= tolerance;
}

Point4D &Point4D::operator=(const Point4D &) = default; //assignment operator overload

Point4D &Point4D::operator+() { //unary plus operator overload

    return *this;
}

Point4D &Point4D::operator-() { //unary minus operator overload

    result2 = *this;
    *this = *this * -1;
    return result2;
}

Point4D &Point4D::operator++() { //pre-increment operator overload

    return 1 + *this;
}

Point4D &Point4D::operator++(int) { //post-increment operator overload

    result2 = *this;
    *this = *this + 1;
    return result2;
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

std::ostream &operator<<(std::ostream &sout, const Point4D &pointA) {

    sout << pointA.toString();
    return sout;
}

int main() {

    Point4D m1(2, 3, 4, 5);
    Point4D m2 = m1.inverse();
    Point4D m3 = m1;
    m3 = m1 + 5;
    cout << m3;
}