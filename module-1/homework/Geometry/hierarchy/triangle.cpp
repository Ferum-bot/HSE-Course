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
    Vector normalVector1 = Line(vertices[1], vertices[2]).getNormalVector();
    Vector normalVector2 = Line(vertices[2], vertices[0]).getNormalVector();
    normalVector1 *= 100;
    normalVector2 *= 100;
    const Point medianPoint1 = Point::getMedianPoint(vertices[1], vertices[2]);
    const Point medianPoint2 = Point::getMedianPoint(vertices[2], vertices[0]);
    const Point pairForMedianPoint1 = (medianPoint1 + normalVector1).getPoint();
    const Point pairForMedianPoint2 = (medianPoint2 + normalVector2).getPoint();
    const Line line1(medianPoint1, pairForMedianPoint1);
    const Line line2(medianPoint2, pairForMedianPoint2);
    const Point center = line1.getIntersection(line2);
    return Circle(center, rad);
}

Circle Triangle::inscribedCircle() const {
    const long double semiperimeter = this->perimeter() / 2;
    const long double rad = this->area() / semiperimeter;
    const Vector v1(vertices[1], vertices[2]);
    const Vector v2(vertices[2], vertices[0]);
    const Vector v3(vertices[0], vertices[1]);
    long double angle = Vector::getAngle(v1, v2);
    Point medianPoint = Point::getMedianPoint(vertices[2], vertices[0]);
    medianPoint.rotate(Point(0, 0), angle / 2);
    const Line l1(vertices[1], medianPoint);
    medianPoint = Point::getMedianPoint(vertices[0], vertices[1]);
    angle = Vector::getAngle(v2, v3);
    medianPoint.rotate(Point(0, 0), angle);
    const Line l2(vertices[0],  medianPoint);
    const Point center = l1.getIntersection(l2);
    return Circle(center, rad);

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
            const long double coef = Polygon::getPropotionalCoefficient(sidesOfFirstTriangle, 
                                                                        sidesOfSecondTriangle);
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