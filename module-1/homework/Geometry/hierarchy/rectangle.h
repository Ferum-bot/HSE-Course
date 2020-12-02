#pragma once

#include "polygon.h"

class Rectangle: public Polygon {
public:

    Rectangle();
    Rectangle(const Point& first, const Point& second, const long double& ratio);

    Rectangle(const Rectangle& rectangle);

    virtual ~Rectangle();

    virtual Point getCenter() const;

    virtual std::pair<Line, Line> getDiagonals() const;

public:

    virtual size_t verticesCount() const override;

    virtual bool isConvex() const override;

public:

    virtual bool isCongruentTo(const Shape& another) const override;
    virtual bool isSimilarTo(const Shape& another) const override;

    virtual bool operator == (const Shape& another) const override;
    virtual bool operator != (const Shape& another) const override;

};