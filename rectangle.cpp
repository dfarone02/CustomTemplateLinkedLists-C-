//Daniel Farone
//CSCI 3110-001
//Project #3
//Due: 02/24/22
//This file defines the functions for the Rectangle class that were given prototypes
//in the "Rectangle.h" file but were not defined
#include "rectangle.h"

bool Rectangle::operator<(const Rectangle &rhs)
{
    return area < rhs.area;
}

bool Rectangle::operator<=(const Rectangle &rhs)
{
    return area <= rhs.area;
}

bool Rectangle::operator>(const Rectangle &rhs)
{
    return area > rhs.area;
}

bool Rectangle::operator>=(const Rectangle &rhs)
{
    return area >= rhs.area;
}

bool Rectangle::operator==(const Rectangle &rhs)
{
    return area == rhs.area;
}

bool Rectangle::operator!=(const Rectangle &rhs)
{
    return area != rhs.area;
}
