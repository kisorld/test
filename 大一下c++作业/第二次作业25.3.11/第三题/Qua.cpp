#include "Qua.h"


bool Qua::isRectangle()
{
    double i=(p[1].x-p[0].x)*(p[3].x-p[0].x)+(p[1].y-p[0].y)*(p[3].y-p[0].y);
    double j=(p[2].x-p[1].x)*(p[0].x-p[1].x)+(p[2].y-p[1].y)*(p[0].y-p[1].y);
    double k=(p[3].x-p[2].x)*(p[1].x-p[2].x)+(p[3].y-p[2].y)*(p[1].y-p[2].y);
    if(i==0&&j==0&&k==0)
        return true;
    return false;
}

double Qua::countS()
{
    double d1=(p[1].x-p[0].x)*(p[1].x-p[0].x)+(p[1].y-p[0].y)*(p[1].y-p[0].y);
    double d2=(p[3].x-p[0].x)*(p[3].x-p[0].x)+(p[3].y-p[0].y)*(p[3].y-p[0].y);
    double d3=sqrt(d1);
    double d4=sqrt(d2);
    return d3*d4;
}
