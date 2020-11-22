#pragma once

#include "ellipse.h"

class Circle : public Ellipse {
private:

    Point center;

    long double radius;

public:

    Circle(const Point& center, const long double& radius);

    Circle(const Circle& circle);

    ~Circle();

    long double getRadius() const;

public:

    virtual Point getCenter() const override;

public:

    virtual long double perimeter() const override;
    virtual long double area() const override;

    virtual bool isCongruentTo(const Shape& another) const override;
    virtual bool isSimilarTo(const Shape& another) const override;

    virtual void rotate(const Point& center, const long double& angle) override;
    virtual void reflex(const Point& center) override;
    virtual void reflex(const Line& axis) override;
    virtual void scale(const Point& center, const long double& coefficient) override;

    virtual bool operator == (const Shape& another) const override;
    virtual bool operator != (const Shape& another) const override;
};