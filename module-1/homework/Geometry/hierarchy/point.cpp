#include "point.h"

const long double Point::PI = 3.1415926;
const long double Point::EPS = 1e-5;
const long double Point::INF = 1e9 + 7;

Point::Point(const Point& point) = default;

Point::~Point() = default;

Point::Point() {}

Point::Point(const long double& x, const long double& y) {
    this->x = x;
    this->y = y;    
}

long double Point::getX() const {
    return x;
}

long double Point::getY() const {
    return y;
}

bool operator == (const Point& left, const Point& right) {
    long double deltaX = abs(left.getX() - right.getX());
    long double deltaY = abs(left.getY() - right.getY());
    return deltaX < Point::EPS && deltaY < Point::EPS;
}

bool operator != (const Point& left, const Point& right) {
    return !(left == right);
}

long double Point::getDist(const Point& first, const Point& second) {
    long double deltaX = first.getX() - second.getX();
    long double deltaY = first.getY() - second.getY();
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}

bool Point::isEqual(const long double& first, const long double& second) {
    return abs(first - second) < Point::EPS;
}

bool Point::isEqualToZero(const long double& value) {
    return abs(value) < Point::EPS;
}

bool Point::leftIsAboveRight(const long double& left, const long double& right) {
    const long double delta = left - right;
    return delta >= Point::EPS;
}

void Point::rotate(const Point& center, const long double& angleDegrees) {
    const long double angle = Point::convertToRadians(angleDegrees);
    const long double newX = (x - center.getX()) * cos(angle) - (y - center.getY()) * sin(angle) + center.getX();
    const long double newY = (x - center.getX()) * sin(angle) + (y - center.getY()) * cos(angle) + center.getY();
    x = newX;
    y = newY;
}

void Point::reflex(const Point& center) {
    long double vectorX = center.getX() - x;
    long double vectorY = center.getY() - y;
    x += 2 * vectorX;
    y += 2 * vectorY;
    return;
}

long double Point::convertToRadians(const long double& angle) {
    return (angle * Point::PI) / 180;
}