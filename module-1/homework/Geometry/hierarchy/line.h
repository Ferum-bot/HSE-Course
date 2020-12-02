#pragma once

#include "point.h"
#include "segment.h"

class Line final{
private:

    static const long double PI;
    static const long double EPS;

    long double a;
    long double b;
    long double c;

public:

    Line(const Point& start, const Point& finish);

    Line(const long double& a, const long double& b, const long double& c);

    Line(const Line& line);

    ~Line();

    long double getA() const;
    long double getB() const;
    long double getC() const;

    bool intersectsWithSegment(const Segment& segment) const;
    bool intersectsWithLine(const Line& line) const;
    bool isContain(const Point& point) const;

    Point getIntersection(const Line& line) const;

    long double getAngleFromLine(const Line& line) const;
    long double getLengthToXLine() const;
    long double getDistFromPoint(const Point& point) const;

    Vector getNormalVector() const;

    friend bool operator == (const Line& left, const Line& right);
    friend bool operator != (const Line& left, const Line& right);

public:

    static Line createAxisXLine();

};