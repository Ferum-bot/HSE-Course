#include "circle.h"

Circle::Circle(const Circle& circle) = default;

Circle::~Circle() = default;

Circle::Circle(const Point& center, const long double& radius) 
                :Ellipse(center, center, 2 * radius){
    this->center = center;
    this->radius = radius;
}

long double Circle::getRadius() const {
    return radius;
}

Point Circle::getCenter() const {
    return center;
}

long double Circle::perimeter() const {
    return 2 * Ellipse::PI * radius;
}

long double Circle::area() const {
    return Ellipse::PI * radius * radius;
}

bool Circle::isCongruentTo(const Shape& another) const {
    const Circle* current = dynamic_cast<const Circle*>(&another);
    if (current == nullptr) {
        return false;
    }
    return Point::isEqual(radius, this->radius);
}

bool Circle::isSimilarTo(const Shape& another) const {
    const Circle* current = dynamic_cast<const Circle*>(&another);
    if (current == nullptr) {
        return false;
    }
    return true;
}

void Circle::rotate(const Point& center, const long double& angle){
    Ellipse::rotate(center, angle);
    this->center.rotate(center, angle);
}

void Circle::reflex(const Point& center) {
    Ellipse::reflex(center);
    this->center.reflex(center);
}

void Circle::reflex(const Line& axis) {
    Ellipse::reflex(axis);
    const Line axisXLine = Line::createAxisXLine();
    long double angle = axis.getAngleFromLine(axisXLine);
    center.rotate(Point(0, 0), angle);
    center = Point(center.getX(), center.getY());
    center.rotate(Point(0, 0), -angle);
}

void Circle::scale(const Point& center, const long double& coefficient) {
    Ellipse::scale(center, coefficient);
    Vector v1(center, this->center);
    v1 *= coefficient;
    this->center = Point(v1.getX() + center.getX(), v1.getY() + center.getY());
}

bool Circle::operator == (const Shape& another) const {
    const Circle* current = dynamic_cast<const Circle*>(&another);
    if (current == nullptr) {
        return false;
    }
    return center == current->center && Point::isEqual(radius, current->radius);
}

bool Circle::operator != (const Shape& another) const {
    return !(*this == another);
}