#include "vector.h"

const long double Vector::PI = 3.1415926;
const long double Vector::EPS = 1e-5;

Vector::Vector(const Vector& vector) = default;

Vector::~Vector() = default;

Vector::Vector(const long double& x, const long double& y) {
    this->x = x;
    this->y = y;
}

Vector::Vector(const Point& start, const Point& finish) {
    x = finish.getX() - start.getX();
    y = finish.getY() - start.getY();
}

Vector::Vector(const Point& point) {
    x = point.getX();
    y = point.getY();
}

long double Vector::getX() const {
    return x;
}

long double Vector::getY() const {
    return y;
}

bool operator == (const Vector& left, const Vector& right) {
    long double deltaX = abs(right.getX() - left.getX());
    long double deltaY = abs(right.getY() - left.getY());
    return deltaX < Vector::EPS && deltaY < Vector::EPS;
}

bool operator != (const Vector& left, const Vector& right) {
    return !(left == right);
}

long double Vector::dotProduct(const Vector& first, const Vector& second) {
    return first.getX() * second.getX() + first.getY() * second.getY();
}

long double Vector::crossProduct(const Vector& first, const Vector& second) {
    return first.getX() * second.getY() - first.getY() * second.getX();
}

std::pair<Vector, Vector> Vector::getTwoVectorsFromPoints(const Point& first, 
                                        const Point& second, const Point& third) {
    return {Vector(first, second), Vector(second, third)};
}

long double Vector::getLength() const {
    return sqrt(x * x + y * y);
}

long double Vector::getAngle(const Vector& first, const Vector& second) {
    const long double x = Vector::dotProduct(first, second);
    const long double y = Vector::crossProduct(first, second);
    return atan2(y, x);
}

Vector& Vector::operator *= (const long double& value) {
    this->x *= value;
    this->y *= value;
    return (*this);
}

Point Vector::getPoint() const {
    return Point(x, y);
}

Vector operator + (const Point& left, const Vector& right) {
    return Vector(left.getX() + right.getX(), left.getY() + right.getY());
}