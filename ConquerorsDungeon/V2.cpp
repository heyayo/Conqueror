#include "V2.hpp"
#include "Maths.hpp"

V2::V2(float a, float b) : x(a), y(b) {}
V2::~V2() {}

V2& V2::operator+=(V2& rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

float V2::Length()
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

V2 V2::operator+(V2 &rhs) const
{
    return V2(x+rhs.x,y-rhs.y);
}

bool V2::operator!=(V2 & rhs)
{
    return (x != rhs.x && y != rhs.y);
}

bool V2::operator>(V2 &rhs)
{
    return (x > rhs.x && y > rhs.y);
}

V2 V2::operator-(void) const
{
    return V2(-x,-y);
}

std::ostream &operator<<(std::ostream& os, const V2 &v)
{
    os << "[ " << v.x << " , " << v.y << " ]";
    return os;
}

V2 V2::operator/(V2 &rhs) const
{
    return V2(x/rhs.x,y/rhs.y);
}

float V2::Dot(V2 &other)
{
    return (x*other.x) + (y*other.y);
}

V2 V2::operator*(V2 &rhs) const
{
    return V2(x*rhs.x,y*rhs.y);
}

