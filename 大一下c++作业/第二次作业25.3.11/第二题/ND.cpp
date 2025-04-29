#include "ND.h"

ND::ND():n(0),d(0)
{

}

void ND::setN(int i)
{
    n=i;
}
void ND::setD(int i)
{
     d=i;
}

int ND::getN()
{
    return n;
}
int ND::getD()
{
    return d;
}

//操作
void ND::mul(int i,int j)
{
    n=n*i;
    d=d*j;
}
void ND::div(int i,int j)
{
    n=n*j;
    d=d*i;
}
void ND::add(int i,int j)
{
    int t1=0,t2=0,t3=0;
    t1=n*j;
    t2=d*i;
    t3=d*j;
    n=t1+t2;
    d=t3;
}
void ND::sub(int i,int j)
{
    int t1=0,t2=0,t3=0;
    t1=n*j;
    t2=d*i;
    t3=d*j;
    n=t1-t2;
    d=t3;
}
void ND::reduced()
{
    int _n=n,_d=d;
    while(_d!=0)
    {
        int temp=_d;
        _d=_n%_d;
        _n=temp;
    }
    n=n/_n;
    d=d/_n;

}