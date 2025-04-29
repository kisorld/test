#include <iostream>
#include <iomanip>
#include <cmath>
//#include "MyInput.h"
//#include "Qua.h"

using namespace std;

class MyInput
{
    private:
    std::string data[8];

    public:
    MyInput(std::string Input);
    std::string GetdataIndex(int Index);
};

MyInput::MyInput(std::string Input)
{
    int j=0;
    std::string temp="";
    for(int i=0;i<Input.size();i++)
    {
        if(Input[i]==',')
        {
            data[j++]=temp;
            temp="";
        }
        else
        {
            temp=temp+Input[i];
        }
    }
    data[j]=temp;

}
std::string  MyInput::GetdataIndex(int Index)
{
    return data[Index];
}

class Point
{
    public:
    double x;
    double y;
    Point();
};

Point::Point():x(0),y(0)
{
    
}

class Qua
{
    public:
    Point p[4];

    bool isRectangle();
    double countS();
    

};

bool Qua::isRectangle()
{
    double i=(p[1].x-p[0].x)*(p[3].x-p[0].x)+(p[1].y-p[0].y)*(p[3].y-p[0].y);
    double j=(p[2].x-p[1].x)*(p[0].x-p[1].x)+(p[2].y-p[1].y)*(p[0].y-p[1].y);
    double k=(p[3].x-p[2].x)*(p[1].x-p[2].x)+(p[3].y-p[2].y)*(p[1].y-p[2].y);
    if(abs(i)<0.1&&abs(j)<0.1&&abs(k)<0.1)
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




int main()
{   
    string Infor;
    int j=0;
    double show[50];

    while (cin>>Infor)
    {
        MyInput a(Infor);
        Qua num;
        num.p[0].x=stod(a.GetdataIndex(0));
        num.p[0].y=stod(a.GetdataIndex(1));
        num.p[1].x=stod(a.GetdataIndex(2));
        num.p[1].y=stod(a.GetdataIndex(3));
        num.p[2].x=stod(a.GetdataIndex(4));
        num.p[2].y=stod(a.GetdataIndex(5));
        num.p[3].x=stod(a.GetdataIndex(6));
        num.p[3].y=stod(a.GetdataIndex(7));
        
        if(num.isRectangle())
        {
            show[j]=num.countS();
            j++;
        }
        else
        {
            show[j]=0;
            j++;
        }

    }
    for(int i=0;i<j;i++)
    {
        if(show[i]==0)
        {
            cout<<fixed<<setprecision(4)<<0<<endl;
        }
        else
        {
            cout<<fixed<<setprecision(4)<<abs(show[i])<<endl;
        }
    }
    


}