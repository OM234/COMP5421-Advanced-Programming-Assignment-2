//
// Created by Oz on 5/26/2020.
//

#ifndef COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_2_POINT4D_H
#define COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_2_POINT4D_H

#include<array>

using namespace std;

class Point4D {

public:  //TODO: Change to private
    array<double, 4> point;

public:
    Point4D();  //default constructor
    Point4D(double); // 1 parameter constructor
    Point4D(double, double); // 2 parameter constructor
    Point4D(double, double, double); // 3 parameter constructor
    Point4D(double, double, double, double); // 4 parameter constructor
    Point4D(const Point4D &); //copy constructor
    Point4D &inverse() const;
    Point4D &operator*(const Point4D&);
    std::string toString() const;
};

std::ostream &operator<<(std::ostream &, const Point4D &); //<< operator overload


#endif //COMP5421_ADVANCED_PROGRAMMING_ASSIGNMENT_2_POINT4D_H
