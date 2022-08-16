#include "V2.hpp"
#include "Maths.hpp"

V2::V2(int a, int b) : x(a), y(b) {}
V2::~V2() {}

V2& V2::operator+=(V2& rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

int V2::Length()
{
    return Maths::Root(x*x + y*y);
}

bool V2::operator==(V2 &rhs)
{
    return (x == rhs.x && y == rhs.y);
}

V2& V2::operator-=(V2 &rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

V2 V2::operator-(V2 &rhs) const
{
    return V2(x - rhs.x, y - rhs.y);
}

V2 V2::operator+(V2 &rhs)
{
    return V2(x+rhs.x,y-rhs.y);
}

bool V2::operator!=(V2 & rhs)
{
    return (x != rhs.x && y != rhs.y);
}

V2 V2::operator-(void) const
{
    return V2(-x,-y);
}
