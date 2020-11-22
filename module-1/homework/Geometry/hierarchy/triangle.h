#pragma once

#include "polygon.h"
#include "circle.h"

class Triangle final : public Polygon {
public:

    Triangle(const Point& a, const Point& b, const Point& c);
    Triangle(const std::vector<Point>& vertices);

    Triangle(const Triangle& triangle);

    virtual ~Triangle();

    Circle circumscribedCircle() const;
    Circle inscribedCircle() const;

    friend std::ostream& operator <<(std::ostream& out, const Triangle& triangle);

public:

    virtual bool isCongruentTo(const Shape& another) const override;
    virtual bool isSimilarTo(const Shape& another) const override;

    virtual bool operator == (const Shape& another) const override;
    virtual bool operator != (const Shape& another) const override;

};