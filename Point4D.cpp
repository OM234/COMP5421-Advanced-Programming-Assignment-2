//--------------------------------------------------------------
//Name:         Osman Momoh
//Student ID:   26220150
//Course:       COMP 5421: Advanced Programming
//Date:         5/28/2020, Summer 2020
//--------------------------------------------------------------

#include "Point4D.h"
#include <iostream>
#include <sstream>

//--------------------------------------------------------------
// Non-member variables/objects starts
//--------------------------------------------------------------

double Point4D::tolerance = 1.0E-6; //tolerance

//--------------------------------------------------------------
// Non-member variables/objects ends
//--------------------------------------------------------------

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

//--------------------------------------------------------------
// Multiplication operator overloads start
//--------------------------------------------------------------

Point4D Point4D::operator*=(const Point4D &pointA) { //multiplication compound assignment operator overload

    Point4D temp;

    temp.point[0] = this->point[0] * pointA.point[0] + this->point[1] * pointA.point[3];
    temp.point[1] = this->point[0] * pointA.point[1] + this->point[1] * pointA.point[2];
    temp.point[2] = this->point[3] * pointA.point[1] + this->point[2] * pointA.point[2];
    temp.point[3] = this->point[3] * pointA.point[0] + this->point[2] * pointA.point[3];

    *this = temp;

    return temp;
}

Point4D Point4D::operator*=(double a) { //multiplication compound assignment operator overload

    this->point[0] = this->point[0] * a;
    this->point[1] = this->point[1] * a;
    this->point[2] = this->point[2] * a;
    this->point[3] = this->point[3] * a;

    return *this;
}

Point4D operator*(const Point4D &pointA, const Point4D &pointB) { //binary multiplication operator overload

    Point4D temp = pointA;
    temp *= pointB;
    return temp;
}

Point4D operator*(double a, const Point4D &pointA) { //scalar multiplication operator overload

    Point4D temp = pointA;
    temp *= a;
    return temp;
}

Point4D operator*(const Point4D &pointA, double a) { //scalar multiplication operator overload

    return a * pointA;
}

//--------------------------------------------------------------
// Multiplication operator overloads end
//--------------------------------------------------------------

//--------------------------------------------------------------
// Division operator overloads start
//--------------------------------------------------------------

Point4D Point4D::operator/=(const Point4D &pointA) { //division compound assignment operator overload

    *this *= pointA.inverse();
    return *this;
}

Point4D Point4D::operator/=(double a) { //division compound assignment operator overload

    *this *= 1 / a;
    return *this;
}

Point4D operator/(const Point4D &pointA, const Point4D &pointB) { //binary division operator overload

    return pointA * (pointB.inverse());
}

Point4D operator/(double a, const Point4D &pointA) { //scalar division operator overload

    return a * (pointA.inverse());
}

Point4D operator/(const Point4D &pointA, double a) { //scalar division operator overload

    return pointA * (1 / a);
}

//--------------------------------------------------------------
// Division operator overloads end
//--------------------------------------------------------------

//--------------------------------------------------------------
// Addition operator overloads start
//--------------------------------------------------------------

Point4D Point4D::operator+=(const Point4D &pointA) { //addition compound assignment operator overload

    this->point[0] = this->point[0] + pointA.point[0];
    this->point[1] = this->point[1] + pointA.point[1];
    this->point[2] = this->point[2] + pointA.point[2];
    this->point[3] = this->point[3] + pointA.point[3];

    return *this;
}

Point4D Point4D::operator+=(double a) { //addition compound assignment operator overload

    this->point[0] = this->point[0] + a;
    this->point[1] = this->point[1] + a;
    this->point[2] = this->point[2] + a;
    this->point[3] = this->point[3] + a;

    return *this;
}

Point4D operator+(const Point4D &pointA, const Point4D &pointB) { //binary addition operator overload

    Point4D temp = pointA;
    temp += pointB;
    return temp;
}

Point4D operator+(double a, const Point4D &pointA) { //scalar addition operator overload

    Point4D temp = pointA;
    temp += a;
    return temp;
}

Point4D operator+(const Point4D &pointA, double a) { //scalar addition operator overload

    return a + pointA;
}

//--------------------------------------------------------------
// Addition operator overloads end
//--------------------------------------------------------------

//--------------------------------------------------------------
// Subtraction operator overloads start
//--------------------------------------------------------------

Point4D Point4D::operator-=(const Point4D &pointA) { //subtraction compound assignment operator overload

    this->point[0] = this->point[0] - pointA.point[0];
    this->point[1] = this->point[1] - pointA.point[1];
    this->point[2] = this->point[2] - pointA.point[2];
    this->point[3] = this->point[3] - pointA.point[3];

    return *this;
}

Point4D Point4D::operator-=(double a) { //subtraction compound assignment operator overload

    this->point[0] = this->point[0] - a;
    this->point[1] = this->point[1] - a;
    this->point[2] = this->point[2] - a;
    this->point[3] = this->point[3] - a;

    return *this;
}

Point4D operator-(const Point4D &pointA, const Point4D &pointB) { //binary subtraction operator overload

    Point4D temp = pointA;
    temp -= pointB;
    return temp;
}

Point4D operator-(double a, const Point4D &pointA) { //scalar subtraction operator overload

    Point4D temp = pointA;
    temp -= a;
    temp = -temp;
    return temp;
}

Point4D operator-(const Point4D &pointA, double a) { //scalar subtraction operator overload

    Point4D temp = pointA;
    temp -= a;
    return temp;
}

//--------------------------------------------------------------
// Subtraction operator overloads end
//--------------------------------------------------------------

//--------------------------------------------------------------
// Unary operator overloads start
//--------------------------------------------------------------

Point4D Point4D::operator+() { //unary plus operator overload

    return *this;
}

Point4D Point4D::operator-() { //unary minus operator overload

    return *this * -1;
}

Point4D Point4D::operator++() { //pre-increment operator overload

    *this = 1 + *this;
    return *this;
}

Point4D Point4D::operator++(int) { //post-increment operator overload

    Point4D temp = *this;
    *this = *this + 1;
    return temp;
}

Point4D Point4D::operator--() { // pre-decrement operator overload

    *this = *this - 1;
    return *this;
}

Point4D Point4D::operator--(int) { // post-decrement operator overload

    Point4D temp = *this;
    *this = --*this;
    return temp;
}

//--------------------------------------------------------------
// Unary operator overloads end
//--------------------------------------------------------------

//--------------------------------------------------------------
// Relational operator overloads start
//--------------------------------------------------------------

bool Point4D::operator==(const Point4D &pointA) const { //relational operator equals to overload

    Point4D tempSubtraction;
    double absSubVal;

    tempSubtraction.point[0] = this->point[0] - pointA.point[0];
    tempSubtraction.point[1] = this->point[1] - pointA.point[1];
    tempSubtraction.point[2] = this->point[2] - pointA.point[2];
    tempSubtraction.point[3] = this->point[3] - pointA.point[3];

    absSubVal = tempSubtraction();

    return absSubVal <= tolerance;
}

bool Point4D::operator!=(const Point4D &pointA) const { //relational operator not equals to overload

    return !(*this == pointA);
}

bool Point4D::operator<(const Point4D &pointA) const { //relational operator less than overload

    return ((*this != pointA) && this->operator()() < pointA());
}

bool Point4D::operator>(const Point4D &pointA) const { //relational operator greater than overload

    return (pointA < *this);
}

bool Point4D::operator<=(const Point4D &pointA) const { //relational operator less than or equal to overload

    return !(*this > pointA);
}

bool Point4D::operator>=(const Point4D &pointA) const { //relational operator greater than or equal to overload

    return !(*this < pointA);
}

//--------------------------------------------------------------
// Relational operator overloads end
//--------------------------------------------------------------

//--------------------------------------------------------------
// Miscellaneous operator overloads starts ( [] ; () ; << ; >> )
//--------------------------------------------------------------

double &Point4D::operator[](int index) { //subscript operator overload

    try {
        if (index < 1 || index > 4) {

            throw std::out_of_range("index out of bounds");
        }

    } catch (exception &e) {

        std::cout << e.what() << endl;
    }

    return (this->point[--index]);
}

double Point4D::operator()() const { //operator () overload; absolute value function

    return this->absValue();
}

std::ostream &operator<<(std::ostream &sout, const Point4D &pointA) { //insertion << operator overload

    sout << pointA.toString();
    return sout;
}

std::istream &operator>>(std::istream &is, Point4D &pointA) { //extraction >> operator overload

    is >> pointA.point[0] >> pointA.point[1] >> pointA.point[2] >> pointA.point[3];
    return is;
}

Point4D &Point4D::operator=(const Point4D &) = default; //assignment operator overload

//--------------------------------------------------------------
// Miscellaneous operator overloads ends ( [] ; () ; << ; >> )
//--------------------------------------------------------------

//--------------------------------------------------------------
// Miscellaneous functions start
//--------------------------------------------------------------

Point4D::~Point4D() = default; //default destructor

double Point4D::absValue() const { //absolute value function

    double absVal = std::abs(this->point[0]) + std::abs(this->point[1])
                    + std::abs(this->point[2]) + std::abs(this->point[3]);

    return absVal;
}

Point4D Point4D::inverse() const { //inverse function

    Point4D temp;
    double B = this->point[0] * this->point[2] - this->point[1] * this->point[3];
    B = 1 / B;

    temp.point[0] = this->point[2] * B;
    temp.point[1] = -this->point[1] * B;
    temp.point[2] = this->point[0] * B;
    temp.point[3] = -this->point[3] * B;

    return temp;
}

void Point4D::setTolerance(double tol) {

    tolerance = std::abs(tol);
}

double Point4D::getTolerance() {

    return tolerance;
}

std::string Point4D::toString() const { //toString function

    stringstream strStream;
    strStream << "[" << point[0] << "," << point[1] << "," << point[2] << "," << point[3] << "]";
    return strStream.str();
}

//--------------------------------------------------------------
// Miscellaneous functions ends
//--------------------------------------------------------------