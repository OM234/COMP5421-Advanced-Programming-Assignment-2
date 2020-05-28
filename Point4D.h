//
// Created by Oz on 5/26/2020.
//

#ifndef COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_2_POINT4D_H
#define COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_2_POINT4D_H

#include<array>

using namespace std;

class Point4D {

private:
    array<double, 4> point;
    static double tolerance;

public:
    Point4D();  //default constructor
    Point4D(double); // 1 parameter constructor
    Point4D(double, double); // 2 parameter constructor
    Point4D(double, double, double); // 3 parameter constructor
    Point4D(double, double, double, double); // 4 parameter constructor
    Point4D(const Point4D &); //copy constructor
    Point4D &inverse() const;
    Point4D &operator*=(const Point4D &); //multiplication compound assignment operator overload
    Point4D &operator*=(double); //multiplication compound assignment operator overload
    Point4D &operator/=(const Point4D &); //division compound assignment operator overload
    Point4D &operator/=(double); //division compound assignment operator overload
    Point4D &operator+=(const Point4D &); //addition compound assignment operator overload
    Point4D &operator+=(double); //addition compound assignment operator overload
    Point4D &operator-=(const Point4D &); //subtraction compound assignment operator overload
    bool operator==(const Point4D &);
    Point4D &operator=(const Point4D &); //assignment operator overload
    Point4D &operator+(); //unary plus operator overload
    Point4D &operator-();//unary minus operator overload
    Point4D &operator++(); //pre-increment operator overload
    Point4D &operator++(int); //post-increment operator overload
    static void setTolerance(double tol);

    static double getTolerance();

    //const std::array<double, 4> getPoint() const;
    std::string toString() const;
};

std::ostream &operator<<(std::ostream &, const Point4D &); //<< operator overload
Point4D &operator*(const Point4D &, const Point4D &); //binary multiplication operator overload
Point4D &operator*(double, const Point4D &); //scalar multiplication operator overload
Point4D &operator*(const Point4D &, double); //scalar multiplication operator overload
Point4D &operator/(const Point4D &, const Point4D &); //binary division operator overload
Point4D &operator/(double, const Point4D &); //scalar division operator overload
Point4D &operator/(const Point4D &, double); //scalar division operator overload
Point4D &operator+(const Point4D &, const Point4D &); //binary addition operator overload
Point4D &operator+(double, const Point4D &); //scalar addition operator overload
Point4D &operator+(const Point4D &, double); //scalar addition operator overload
Point4D &operator-(const Point4D &, const Point4D&); //binary subtraction operator overload
Point4D &operator-(double, const Point4D &); //scalar subtraction operator overload
Point4D &operator-(const Point4D &, double); //scalar subtraction operator overload

#endif //COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_2_POINT4D_H
