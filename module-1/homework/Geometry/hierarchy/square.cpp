#include "square.h"

Square::Square() {}

Square::Square(const Square& square) = default;

Square::~Square() = default;

Square::Square(const Point& first, const Point& second): Rectangle(first, second, 1) {}

bool Square::isCongruentTo(const Shape& another) const {
    const Square* current = dynamic_cast<const Square*>(&another);
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

bool Square::isSimilarTo(const Shape& another) const {
    const Square* current = dynamic_cast<const Square*>(&another);
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

bool Square::operator == (const Shape& another) const {
    const Square* current = dynamic_cast<const Square*>(&another);
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

bool Square::operator != (const Shape& another) const {
    return !(*this == another);
}

Circle Square::getCircumscribedCircle() const {
    const long double rad = Vector(vertices[0], vertices[2]).getLength() / 2;
    const long double x = (vertices[0].getX() + vertices[2].getX()) / 2;
    const long double y = (vertices[0].getY() + vertices[2].getY()) / 2;
    return Circle(Point(x, y), rad);
}

Circle Square::getInscribedCircle() const {
    const long double rad = Vector(vertices[0], vertices[1]).getLength() / 2;
    const long double x = (vertices[0].getX() + vertices[2].getX()) / 2;
    const long double y = (vertices[0].getY() + vertices[2].getY()) / 2;
    return Circle(Point(x, y), rad);
}