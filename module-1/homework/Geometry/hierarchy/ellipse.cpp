#include "ellipse.h"

const long double Ellipse::PI = 3.1415926;
const long double Ellipse::EPS = 1e-2;

Ellipse::Ellipse(const Ellipse& ellipse) = default;

Ellipse::~Ellipse() = default;

Ellipse::Ellipse() {}

Ellipse::Ellipse(const Point& first, const Point& second, const long double& sumOfDistance) {
    firstFocus = first;
    secondFocus = second;
    this->sumOfDistance = sumOfDistance;
    c = Vector(first, second).getLength();
    a = sumOfDistance;
    b = a * sqrt(1 - c / a * c / a);
}

Point Ellipse::getFirstFocus() const {
    return firstFocus;
}

Point Ellipse::getSecondFocus() const {
    return secondFocus;
}

std::pair<Point, Point> Ellipse::focuses() const {
    return {firstFocus, secondFocus};
}

bool Ellipse::operator == (const Shape& another) const {
    const Ellipse* current = dynamic_cast<const Ellipse*>(&another);
    if (current == nullptr) {
        return false;
    }
    if (!Point::isEqual(sumOfDistance, current->sumOfDistance)) {
        return false;
    }
    if (current->firstFocus == firstFocus && current->secondFocus == secondFocus) {
        return true;
    }
    if (current->firstFocus == secondFocus && current->secondFocus == firstFocus) {
        return true;
    }
    return false;
}

bool Ellipse::operator != (const Shape& another) const {
    return !(*this == another);
}

std::pair<Line, Line> Ellipse::directrices() const  {
    return {Line(this->eccentricity(), 0, -a), Line(this->eccentricity(), 0, a)};
}

long double Ellipse::eccentricity() const {
    return c/a;
}

Point Ellipse::getCenter() const {
    const long double x = (firstFocus.getX() + secondFocus.getX()) / 2;
    const long double y = (firstFocus.getY() + secondFocus.getY()) / 2;
    return Point(x, y);
}

long double Ellipse::perimeter() const {
    long double value1 = Ellipse::PI * a * b + (a - b) * (a - b);
    value1 /= (a + b);
    return 2 * value1;
}

long double Ellipse::area() const {
    return Ellipse::PI * a * b / 4;
}

bool Ellipse::isCongruentTo(const Shape& another) const {
    const Ellipse* current = dynamic_cast<const Ellipse*>(&another);
    if (current == nullptr) {
        return false;
    }
    return Point::isEqual(a, current->a) && Point::isEqual(b, current->b) 
                && Point::isEqual(c, current->c);
}

bool Ellipse::isSimilarTo(const Shape& another) const {
    const Ellipse* current = dynamic_cast<const Ellipse*>(&another);
    if (current == nullptr) {
        return false;
    }
    return Point::isEqual(a / b, current->a / current->b);
}

bool Ellipse::containsPoint(const Point& point) const {
    const long double dist1 = Vector(point, firstFocus).getLength();
    const long double dist2 = Vector(point, secondFocus).getLength();
    return Point::leftIsAboveRight(sumOfDistance, dist1 + dist2);
}

void Ellipse::rotate(const Point& center, const long double& angle) {
    firstFocus.rotate(center, angle);
    secondFocus.rotate(center, angle);
}

void Ellipse::reflex(const Point& center) {
    firstFocus.reflex(center);
    secondFocus.reflex(center);
}

void Ellipse::reflex(const Line& axis) {
    const Line axisXLine = Line::createAxisXLine();
    long double angle = axis.getAngleFromLine(axisXLine);
    firstFocus.rotate(Point(0, 0), angle);
    secondFocus.rotate(Point(0, 0), angle);
    firstFocus = Point(firstFocus.getX(), -firstFocus.getY());
    secondFocus = Point(secondFocus.getX(), -secondFocus.getY());
    firstFocus.rotate(Point(0, 0), -angle);
    secondFocus.rotate(Point(0, 0), -angle);
}

void Ellipse::scale(const Point& center, const long double& coefficient) {
    Vector v1(center, firstFocus);
    Vector v2(center, secondFocus);
    v1 *= coefficient;
    v2 *= coefficient;
    firstFocus = Point(center.getX() + v1.getX(), center.getY() + v1.getY());
    secondFocus = Point(center.getX() + v2.getX(), center.getY() + v2.getY());
}