#ifndef RPGAME_V2_HPP
#define RPGAME_V2_HPP

#include <iostream>

class V2
{
public:
    float x,y;
    V2(float a = 0, float b = 0);
    ~V2();

    float Length();
    float Dot(V2& other);

    V2& operator+=(V2&rhs);
    V2& operator-=(V2&rhs);
    V2 operator-(V2&rhs) const;
    V2 operator+(V2&rhs) const;
    V2 operator*(V2&rhs) const;
    V2 operator/(V2&rhs) const;
    V2 operator-(void) const;
    bool operator!=(V2&rhs);
    bool operator==(V2&rhs);
    bool operator>(V2&rhs);

    friend std::ostream& operator<< (std::ostream& os, const V2& v);
};


#endif
