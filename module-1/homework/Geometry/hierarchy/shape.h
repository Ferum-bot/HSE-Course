#pragma once

#include <vector>

#include "point.h"
#include "line.h"

class Shape {
public:

    virtual ~Shape();

    virtual long double perimeter() const = 0;
    virtual long double area() const = 0;

    virtual bool isCongruentTo(const Shape& another) const = 0;
    virtual bool isSimilarTo(const Shape& another) const = 0;

    virtual bool containsPoint(const Point& point) const = 0;

    virtual void rotate(const Point& center, const long double& angle) = 0;
    virtual void reflex(const Point& center) = 0;
    virtual void reflex(const Line& axis) = 0;
    virtual void scale(const Point& center, const long double& coefficient) = 0;

    virtual bool operator == (const Shape& another) const = 0;
    virtual bool operator != (const Shape& another) const = 0;

};