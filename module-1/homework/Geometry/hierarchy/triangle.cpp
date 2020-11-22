#include "triangle.h"

Triangle::Triangle(const Triangle& triangle) = default;

Triangle::~Triangle() = default;

Triangle::Triangle(const Point& a, const Point& b, const Point& c) {
    vertices.push_back(a);
    vertices.push_back(b);
    vertices.push_back(c);
}

Triangle::Triangle(const std::vector<Point>& vertices): Polygon(vertices) {
    if (this->verticesCount() != 3) {
        throw std::invalid_argument("invalid number of vertices");
    }
}

Circle Triangle::circumscribedCircle() const {
    const long double len = Segment(vertices[0], vertices[1]).getLength();
    const Vector v1(vertices[1], vertices[2]);
    const Vector v2(vertices[2], vertices[0]);
    const long double angle = Vector::getAngle(v1, v2);
    const long double rad = len / 2 * angle;
    
}

Circle Triangle::inscribedCircle() const {

}

bool Triangle::isCongruentTo(const Shape& another) const {
    if (!this->isSimilarTo(another)) {
        return false;
    }
    const Triangle* current = dynamic_cast<const Triangle*>(&another);
    if (current == nullptr) {
        return false;
    }
    std::vector<Segment> sidesOfFirstTriangle = {};
    std::vector<Segment> sidesOfSecondTriangle = {};
    size_t size = this->vertices.size();
    for (size_t i = 0; i < size; i++) {
        const Segment segFirst(vertices[i], vertices[(i + 1) % size]);
        const Segment segSecond(current->vertices[i], current->vertices[(i + 1) % size]);
        sidesOfFirstTriangle.push_back(segFirst);
        sidesOfSecondTriangle.push_back(segSecond);
    }
    for (size_t i = 0; i < size; i++) {
        if (Polygon::isPropotional(sidesOfFirstTriangle, sidesOfSecondTriangle)) {
            const long double coef = Polygon::getPropotionalCoefficient(sidesOfFirstTriangle, sidesOfSecondTriangle);
            if (Point::isEqual(coef, 1)) {
                return true;
            }
        }
        Polygon::shiftPolygon(sidesOfSecondTriangle);
    }
    return false;
}

bool Triangle::isSimilarTo(const Shape& another) const {
    const Triangle* current = dynamic_cast<const Triangle*>(&another);
    if (current == nullptr) {
        return false;
    }
    std::vector<Segment> sidesOfFirstTriangle = {};
    std::vector<Segment> sidesOfSecondTriangle = {};
    size_t size = this->vertices.size();
    for (size_t i = 0; i < size; i++) {
        const Segment segFirst(vertices[i], vertices[(i + 1) % size]);
        const Segment segSecond(current->vertices[i], current->vertices[(i + 1) % size]);
        sidesOfFirstTriangle.push_back(segFirst);
        sidesOfSecondTriangle.push_back(segSecond);
    }
    for (size_t i = 0; i < size; i++) {
        if (Polygon::isAglesEqual(sidesOfFirstTriangle, sidesOfSecondTriangle)) {
            return true;
        }
        Polygon::shiftPolygon(sidesOfSecondTriangle);
    }
    return false;
}

bool Triangle::operator == (const Shape& another) const {
    const Triangle* current = dynamic_cast<const Triangle*>(&another);
    if (current == nullptr) {
        return false;
    }
    size_t size = this->verticesCount();
    size_t startPosition = 0;
    for (size_t i = 0; i < size; i++) {
        if (vertices[0] == current->vertices[i]) {
            startPosition = i;
            break;
        }
    }
    for (size_t i = 0; i < size; i++) {
        if (vertices[i] != current->vertices[(i + startPosition) % size]) {
            return false;
        }
    }
    return true;
}

bool Triangle::operator != (const Shape& another) const {
    return !(*this == another);
}

std::ostream& operator <<(std::ostream& out, const Triangle& triangle) {
    for (size_t i = 0; i < triangle.verticesCount(); i++) {
        out << triangle.vertices[i].getX() << ' ' << triangle.vertices[i].getY() << std::endl;
    }
    return out;
}