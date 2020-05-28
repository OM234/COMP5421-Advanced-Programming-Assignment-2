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

//--------------------------------------------------------------
// Constructor overloads start
//--------------------------------------------------------------

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

//--------------------------------------------------------------
// Constructor overloads end
//--------------------------------------------------------------

Point4D &Point4D::inverse() const { //inverse function

    double B = this->point[0] * this->point[2] - this->point[1] * this->point[3];
    B = 1 / B;

    result1.point[0] = this->point[2] * B;
    result1.point[1] = -this->point[1] * B;
    result1.point[2] = this->point[0] * B;
    result1.point[3] = -this->point[3] * B;

    return result1;
}

//--------------------------------------------------------------
// Multiplication operator overloads start
//--------------------------------------------------------------

Point4D &Point4D::operator*=(const Point4D &pointA) { //multiplication compound assignment operator overload

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

//--------------------------------------------------------------
// Multiplication operator overloads end
//--------------------------------------------------------------

//--------------------------------------------------------------
// Division operator overloads start
//--------------------------------------------------------------

Point4D &Point4D::operator/=(const Point4D &pointA) { //division compound assignment operator overload

    *this *= pointA.inverse();

    return *this;
}

Point4D &Point4D::operator/=(double a) { //division compound assignment operator overload

    *this *= 1 / a;

    return *this;
}

Point4D &
operator/(const Point4D &pointA, const Point4D &pointB) { //binary division operator overload TODO: Does this work?

    return pointA * (pointB.inverse());
}

Point4D &operator/(double a, const Point4D &pointA) { //scalar division operator overload

    return a * (pointA.inverse());
}

Point4D &operator/(const Point4D &pointA, double a) { //scalar division operator overload

    return pointA * (1 / a);
}

//--------------------------------------------------------------
// Division operator overloads end
//--------------------------------------------------------------

//--------------------------------------------------------------
// Addition operator overloads start
//--------------------------------------------------------------

Point4D &Point4D::operator+=(const Point4D &pointA) { //addition compound assignment operator overload

    this->point[0] = this->point[0] + pointA.point[0];
    this->point[1] = this->point[1] + pointA.point[1];
    this->point[2] = this->point[2] + pointA.point[2];
    this->point[3] = this->point[3] + pointA.point[3];

    return *this;
}

Point4D &Point4D::operator+=(double a) { //addition compound assignment operator overload

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

    result1 = pointA;
    result1 += a;
    return result1;
}

Point4D &operator+(const Point4D &pointA, double a) { //scalar addition operator overload

    return a + pointA;
}

//--------------------------------------------------------------
// Addition operator overloads end
//--------------------------------------------------------------

//--------------------------------------------------------------
// Subtraction operator overloads start
//--------------------------------------------------------------

Point4D &Point4D::operator-=(const Point4D &pointA) { //subtraction compound assignment operator overload

    this->point[0] = this->point[0] - pointA.point[0];
    this->point[1] = this->point[1] - pointA.point[1];
    this->point[2] = this->point[2] - pointA.point[2];
    this->point[3] = this->point[3] - pointA.point[3];

    return *this;
}

Point4D &Point4D::operator-=(double a) { //subtraction compound assignment operator overload

    this->point[0] = this->point[0] - a;
    this->point[1] = this->point[1] - a;
    this->point[2] = this->point[2] - a;
    this->point[3] = this->point[3] - a;

    return *this;
}

Point4D &operator-(const Point4D &pointA, const Point4D &pointB) { //binary subtraction operator overload

    Point4D temp = pointA;
    temp -= pointB;
    result1 = temp;
    return result1;
}

Point4D &operator-(double a, const Point4D &pointA) { //scalar subtraction operator overload

    Point4D temp = pointA;
    temp -= a;
    temp = -temp;
    result1 = temp;
    return result1;
}

Point4D &operator-(const Point4D &pointA, double a) { //scalar subtraction operator overload

    Point4D temp = pointA;
    temp -= a;
    result1 = temp;
    return result1;
}

//--------------------------------------------------------------
// Subtraction operator overloads end
//--------------------------------------------------------------

Point4D &Point4D::operator=(const Point4D &) = default; //assignment operator overload

//--------------------------------------------------------------
// Unary operator overloads start
//--------------------------------------------------------------

Point4D &Point4D::operator+() { //unary plus operator overload

    return *this;
}

Point4D &Point4D::operator-() { //unary minus operator overload

    //result2 = *this;
    *this = *this * -1;
    return *this;
    //return result2;
}

Point4D &Point4D::operator++() { //pre-increment operator overload

    return 1 + *this;
}

Point4D &Point4D::operator++(int) { //post-increment operator overload

    result2 = *this;
    *this = *this + 1;
    return result2;
}

Point4D &Point4D::operator--() { // pre-decrement operator overload

    return *this - 1;
}

Point4D &Point4D::operator--(int) { // post-decrement operator overload

    result2 = *this;
    *this = --*this;
    return result2;
}

//--------------------------------------------------------------
// Unary operator overloads end
//--------------------------------------------------------------

//--------------------------------------------------------------
// Relational operator overloads start
//--------------------------------------------------------------

bool Point4D::operator==(const Point4D &pointA) const{ //relational operator equals to overload

    Point4D tempSubtraction;
    double absSubVal;

    tempSubtraction.point[0] = this->point[0] - pointA.point[0];
    tempSubtraction.point[1] = this->point[1] - pointA.point[1];
    tempSubtraction.point[2] = this->point[2] - pointA.point[2];
    tempSubtraction.point[3] = this->point[3] - pointA.point[3];

//    absSubVal = std::abs(tempSubtraction.point[0]) + std::abs(tempSubtraction.point[1])
//                + std::abs(tempSubtraction.point[2]) + std::abs(tempSubtraction.point[3]);
    absSubVal = absoluteVal(tempSubtraction);
    return absSubVal <= tolerance;
}

bool Point4D::operator!=(const Point4D &pointA) const{ //relational operator not equals to overload

    return !(*this == pointA);
}

bool Point4D::operator<(const Point4D &pointA) const{ //relational operator less than overload

    return ((*this != pointA) && (absoluteVal(*this) < absoluteVal(pointA)));
}

bool Point4D::operator>(const Point4D &pointA) const{ //relational operator greater than overload

    return(pointA < *this);
}

bool Point4D::operator<=(const Point4D& pointA) const { //relational operator less than or equal to overload

    return!(*this > pointA);
}

bool Point4D::operator>=(const Point4D& pointA) const { //relational operator greater than or equal to overload

    return!(*this < pointA);
}

//--------------------------------------------------------------
// Relational operator overloads end
//--------------------------------------------------------------

double Point4D::absoluteVal(const Point4D &pointA) const { //absolute value function

    double absVal = std::abs(pointA.point[0]) + std::abs(pointA.point[1])
                    + std::abs(pointA.point[2]) + std::abs(pointA.point[3]);

    return absVal;
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
    cout << ((m3+0.001)>=m1);
}