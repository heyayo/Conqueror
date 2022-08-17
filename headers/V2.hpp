#ifndef RPGAME_V2_HPP
#define RPGAME_V2_HPP

#include <iostream>

class V2
{
public:
    int x,y;
    V2(int a = 0, int b = 0);
    ~V2();

    int Length();

    V2& operator+=(V2&rhs);
    V2& operator-=(V2&rhs);
    V2 operator-(V2&rhs) const;
    V2 operator+(V2&rhs);
    V2 operator-(void) const;
    bool operator!=(V2&rhs);
    bool operator==(V2&rhs);

    friend std::ostream& operator<< (std::ostream& os, const V2& v);
};


#endif
