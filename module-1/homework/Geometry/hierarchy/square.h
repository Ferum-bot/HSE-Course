#pragma once

#include "rectangle.h"
#include "circle.h"

class Square final: public Rectangle {
public:

    Square();
    Square(const Point& first, const Point& second);

    Square(const Square& square);

    ~Square();

    Circle getCircumscribedCircle() const;
    Circle getInscribedCircle() const;

public:

    virtual bool isCongruentTo(const Shape& another) const override;
    virtual bool isSimilarTo(const Shape& another) const override;

    virtual bool operator == (const Shape& another) const override;
    virtual bool operator != (const Shape& another) const override;

};