#pragma once

#include "point.h"
#include "vector.h"

class Segment final {
private:

    static const long double EPS;

    Point first;
    Point second;

public:

    Segment(const Point& first, const Point& second);

    Segment(const Segment& segment);

    ~Segment();

    Point getFirstPoint() const;
    Point getSecondPoint() const;

    long double getMaxX() const;
    long double getMaxY() const;
    long double getMinX() const;
    long double getMinY() const;

    long double getLength() const;

    Vector getVector() const;

    bool containPoint(const Point& point) const;

    friend bool operator == (const Segment& left, const Segment& right);
    friend bool operator != (const Segment& left, const Segment& right);

};