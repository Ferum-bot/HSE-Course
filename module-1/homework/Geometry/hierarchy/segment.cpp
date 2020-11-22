#include "segment.h"

const long double Segment::EPS = 1e-5;

Segment::Segment(const Segment& segment) = default;

Segment::~Segment() = default;

Segment::Segment(const Point& _first, const Point& _second):
first(_first), second(_second) {}

Point Segment::getFirstPoint() const {
    return first;
}

Point Segment::getSecondPoint() const {
    return second;
}

bool operator == (const Segment& left, const Segment& right) {
    bool result = left.first == right.first && left.second == right.second;
    result |= left.first == right.second && left.second == right.first;
    return result;
}

bool operator != (const Segment& left, const Segment& right) {
    return !(left == right);
}

long double Segment::getMaxX() const {
    if (Point::leftIsAboveRight(first.getX(), second.getX())) {
        return first.getX();
    }
    return second.getX();
}

long double Segment::getMaxY() const {
    if (Point::leftIsAboveRight(first.getY(), second.getY())) {
        return first.getY();
    }
    return second.getY();
}

long double Segment::getMinX() const {
    if (Point::leftIsAboveRight(first.getX(), second.getX())) {
        return second.getX();
    }
    return first.getX();
}

long double Segment::getMinY() const {
    if (Point::leftIsAboveRight(first.getY(), second.getY())) {
        return second.getY();
    }
    return first.getY();
}

long double Segment::getLength() const {
    long double deltaX = first.getX() - second.getX();
    long double deltaY = first.getY() - second.getY();
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}

Vector Segment::getVector() const {
    return Vector(first, second);
}

bool Segment::containPoint(const Point& point) const {
    const long double a = first.y - second.y;
    const long double b = second.x - first.x;
    const long double c = first.x * second.y - second.x * first.y;
    if (a * point.x + b * point.y + c < Point::EPS) {
        if (Point::leftIsAboveRight(point.getX(), this->getMinX()) &&
            Point::leftIsAboveRight(this->getMaxX(), point.getX()) &&
            Point::leftIsAboveRight(point.getY(), this->getMinY()) &&
            Point::leftIsAboveRight(this->getMaxY(), point.getY())) {
        
            return true;

        }
    }
    return false;
}