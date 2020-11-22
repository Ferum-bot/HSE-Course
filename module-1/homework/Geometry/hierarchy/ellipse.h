#pragma once

#include "shape.h"

class Ellipse: public Shape {
protected:

    Point firstFocus;
    Point secondFocus;

    long double sumOfDistance;

    long double a;
    long double b;
    long double c;

protected:

    static const long double EPS;
    static const long double PI;

public:


    Ellipse();
    Ellipse(const Point& first, const Point& second, const long double& sumOfDistance);

    Ellipse(const Ellipse& ellipse);

    virtual ~Ellipse();

    virtual Point getFirstFocus() const;
    virtual Point getSecondFocus() const;

    virtual std::pair<Point, Point> focuses() const;
    virtual std::pair<Line, Line> directrices() const;

    virtual long double eccentricity() const;

    virtual Point getCenter() const;

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

};