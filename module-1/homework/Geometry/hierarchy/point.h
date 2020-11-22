#pragma once

#include <math.h>
#include <algorithm>


class Point final {
public:

    static const long double PI;
    static const long double EPS;
    static const long double INF;

    long double x;
    long double y;

public:

    Point();
    Point(const long double& x, const long double& y);

    Point(const Point& point);

    ~Point();

    long double getX() const;
    long double getY() const;

    void rotate(const Point& center, const long double& angleDegrees);
    void reflex(const Point& center);

    friend bool operator == (const Point& left, const Point& right);
    friend bool operator != (const Point& left, const Point& right);

public:

    static long double getDist(const Point& first, const Point& second);

    static bool isEqual(const long double& first, const long double& second);
    static bool isEqualToZero(const long double& value);
    static bool leftIsAboveRight(const long double& left, const long double& right);

    static long double convertToRadians(const long double& angle);

};

