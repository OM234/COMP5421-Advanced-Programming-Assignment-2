//--------------------------------------------------------------
//Name:         Osman Momoh
//Student ID:   26220150
//Course:       COMP 5421: Advanced Programming
//Date:         5/28/2020, Summer 2020
//--------------------------------------------------------------

#ifndef COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_2_POINT4D_H
#define COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_2_POINT4D_H

#include<array>

using namespace std;

class Point4D {

private:
    array<double, 4> point; //a point is an array of 4 doubles
    static double tolerance; //for equality checking

public:
    virtual ~Point4D(); //destructor

    Point4D();  //default constructor
    Point4D(double); // 1 parameter constructor
    Point4D(double, double); // 2 parameter constructor
    Point4D(double, double, double); // 3 parameter constructor
    Point4D(double, double, double, double); // 4 parameter constructor
    Point4D(const Point4D &); //copy constructor, default

    Point4D inverse() const; //inverse function

    Point4D operator*=(const Point4D &); //multiplication compound assignment operator overload
    Point4D operator*=(double); //multiplication compound assignment operator overload
    Point4D operator/=(const Point4D &); //division compound assignment operator overload
    Point4D operator/=(double); //division compound assignment operator overload
    Point4D operator+=(const Point4D &); //addition compound assignment operator overload
    Point4D operator+=(double); //addition compound assignment operator overload
    Point4D operator-=(const Point4D &); //subtraction compound assignment operator overload
    Point4D operator-=(double); //subtraction compound assignment operator overload

    Point4D operator+(); //unary plus operator overload
    Point4D operator-();//unary minus operator overload
    Point4D operator++(); //pre-increment operator overload
    Point4D operator++(int); //post-increment operator overload
    Point4D operator--(); // pre-decrement operator overload
    Point4D operator--(int); // post-decrement operator overload

    bool operator==(const Point4D &) const; //relational operator equals to overload
    bool operator!=(const Point4D &) const; //relational operator not equals to overload
    bool operator<(const Point4D &) const; //relational operator less than overload
    bool operator>(const Point4D &) const; //relational operator greater than overload
    bool operator<=(const Point4D &) const; //relational operator less than or equal to overload
    bool operator>=(const Point4D &) const; //relational operator greater than or equal to overload

    double &operator[](int index); //subscript operator overload
    Point4D &operator=(const Point4D &); //assignment operator, default
    double operator()() const; //operator () overload; absolute value function
    friend std::istream &operator>>(std::istream &is, Point4D &); //extraction >> operator overload

    double absValue() const; //absolute value function
    static void setTolerance(double tol); //set tolerance
    static double getTolerance(); //get tolerance
    std::string toString() const; //string representation of Point4D
};

std::ostream &operator<<(std::ostream &, const Point4D &); //insertion << operator overload
std::istream &operator>>(std::istream &is, const Point4D &); //extraction >> operator overload

Point4D operator*(const Point4D &, const Point4D &); //binary multiplication operator overload
Point4D operator*(double, const Point4D &); //scalar multiplication operator overload
Point4D operator*(const Point4D &, double); //scalar multiplication operator overload

Point4D operator/(const Point4D &, const Point4D &); //binary division operator overload
Point4D operator/(double, const Point4D &); //scalar division operator overload
Point4D operator/(const Point4D &, double); //scalar division operator overload

Point4D operator+(const Point4D &, const Point4D &); //binary addition operator overload
Point4D operator+(double, const Point4D &); //scalar addition operator overload
Point4D operator+(const Point4D &, double); //scalar addition operator overload

Point4D operator-(const Point4D &, const Point4D &); //binary subtraction operator overload
Point4D operator-(double, const Point4D &); //scalar subtraction operator overload
Point4D operator-(const Point4D &, double); //scalar subtraction operator overload

#endif //COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_2_POINT4D_H
