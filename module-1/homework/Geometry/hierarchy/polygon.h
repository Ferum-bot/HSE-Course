#pragma once

#include "point.h"
#include "line.h"
#include "shape.h"
#include "vector.h"
#include "segment.h"

#include <stdexcept>
#include <iostream>

class Polygon: public Shape {
public:

    Polygon();
    Polygon(const std::vector<Point>& vertices);

    Polygon(const Polygon& polygon);

    virtual ~Polygon();

    virtual size_t verticesCount() const;

    virtual std::vector<Point> getVertices() const;

    virtual bool isConvex() const;

    virtual void moveBy(const long double& deltaX, const long double& deltaY);

    friend std::ostream& operator <<(std::ostream& out, const Polygon& polygon);


public:

    virtual long double perimeter() const override;
    virtual long double area() const override;

    virtual bool isCongruentTo(const Shape& another) const override;
    virtual bool isSimilarTo(const Shape& another) const override;

    virtual bool containsPoint(const Point& point) const override;

    virtual void rotate(const Point& center, const long double& angle) override;
    virtual void reflex(const Point& center) override;
    virtual void reflex(const Line& axis) override;
    virtual void scale(const Point& center, const long double& coefficient) override;

    virtual bool operator == (const Shape& another) const override;
    virtual bool operator != (const Shape& another) const override;

private:

    static bool isCorrectValue(int& type, const long double& value);

protected:

    static bool isEqualToZero(const long double& value);
    static bool isAboveZero(const long double& value);
    static bool isLessZero(const long double& value);

    static bool isPropotional(const std::vector<Segment>& first, const std::vector<Segment>& second);
    static bool isAglesEqual(const std::vector<Segment>& first, const std::vector<Segment>& second);
    static long double getPropotionalCoefficient(const std::vector<Segment>& first, const std::vector<Segment>& second);

    static void shiftPolygon(std::vector<Segment>& polygon);

protected:

    static const long double PI;
    static const long double EPS;
    static const long double INF;

    std::vector<Point> vertices;

};