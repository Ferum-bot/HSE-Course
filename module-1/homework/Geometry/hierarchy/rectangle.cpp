#include "rectangle.h"

Rectangle::Rectangle(const Rectangle& rectangle) = default;

Rectangle::~Rectangle() = default;

Rectangle::Rectangle() {}

Rectangle::Rectangle(const Point& first, const Point& second, const long double& ratio) {
    vertices.push_back(first);
    vertices.push_back(Point(first.getX(), second.getY()));
    vertices.push_back(second);
    vertices.push_back(Point(second.getX(), first.getY()));
}

Point Rectangle::getCenter() const {
    Line l1(vertices[0], vertices[2]);
    Line l2(vertices[1], vertices[3]);
    return l1.getIntersection(l2);
}

std::pair<Line, Line> Rectangle::getDiagonals() const {
    Line l1(vertices[0], vertices[2]);
    Line l2(vertices[1], vertices[3]);
    return {l1, l2};
}

size_t Rectangle::verticesCount() const {
    return 4;
}

bool Rectangle::isConvex() const {
    return true;
}

bool Rectangle::isCongruentTo(const Shape& another) const {
    const Rectangle* current = dynamic_cast<const Rectangle*>(&another);
    if (current == nullptr) {
        return false;
    }
    std::vector<Segment> sidesOfFirstPolygon = {};
    std::vector<Segment> sidesOfSecondPolygon = {};
    size_t size = this->verticesCount();
    for (size_t i = 0; i < size; i++) {
        Segment segFirst(vertices[i], vertices[(i + 1) % size]);
        Segment segSecond(current->vertices[i], current->vertices[(i + 1) % size]);
        sidesOfFirstPolygon.push_back(segFirst);
        sidesOfSecondPolygon.push_back(segSecond);
    }
    for (size_t i = 0; i < size; i++) {
        if (Polygon::isPropotional(sidesOfFirstPolygon, sidesOfSecondPolygon) &&
            Polygon::isAglesEqual(sidesOfFirstPolygon, sidesOfSecondPolygon)) {
            
            long double value = Polygon::getPropotionalCoefficient(sidesOfFirstPolygon, 
                                                                    sidesOfSecondPolygon);
            if (Point::isEqual(value, 1)) {
                 return true;
            }
        }
        Polygon::shiftPolygon(sidesOfSecondPolygon);
    }
    return false;
}

bool Rectangle::isSimilarTo(const Shape& another) const {
    const Rectangle* current = dynamic_cast<const Rectangle*>(&another);
    if (current == nullptr) {
        return false;
    }
    std::vector<Segment> sidesOfFirstPolygon = {};
    std::vector<Segment> sidesOfSecondPolygon = {};
    size_t size = this->verticesCount();
    for (size_t i = 0; i < size; i++) {
        Segment segFirst(vertices[i], vertices[(i + 1) % size]);
        Segment segSecond(current->vertices[i], current->vertices[(i + 1) % size]);
        sidesOfFirstPolygon.push_back(segFirst);
        sidesOfSecondPolygon.push_back(segSecond);
    }
    for (size_t i = 0; i < size; i++) {
        if (Polygon::isPropotional(sidesOfFirstPolygon, sidesOfSecondPolygon)) {
            return true;
        }
        Polygon::shiftPolygon(sidesOfSecondPolygon);
    }
    return false;
}

bool Rectangle::operator == (const Shape& another) const {
    const Rectangle* current = dynamic_cast<const Rectangle*>(&another);
    if (current == nullptr) {
        return false;
    }
    size_t startPosition = 0;
    for (size_t i = 0; i < 4; i++) {
        if (vertices[0] == current->vertices[i]) {
            startPosition = i;
            break;
        }
    }
    for (size_t i = 0; i < 4; i++) {
        if (vertices[i] != current->vertices[(i + startPosition) % 4]) {
            return false;
        }
    }
    return true;
}

bool Rectangle::operator != (const Shape& another) const {
    return !(*this == another);
}