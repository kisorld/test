#include <iostream>
#include <string>

using namespace std;


class ND
{
    private:
    int n;
    int d;

    public:

    ND();
    void setN(int i);
    void setD(int i);

    int getN();
    int getD();

    //操作
    void mul(int i,int j);
    void div(int i,int j);
    void add(int i,int j);
    void sub(int i,int j);
    void reduced();
    void exchange();

    ND operator+(ND &a)
    {
        ND temp;
        if(a.d!=0)
    {
        int t1=0,t2=0,t3=0;
        t1=n*a.d;
        t2=d*a.n;
        t3=d*a.d;
        temp.n=t1+t2;
        temp.d=t3;
        return temp;
    }

    }
    ND operator-(ND &a)
    {
        ND temp;
        if(a.d!=0)
    {
        int t1=0,t2=0,t3=0;
        t1=n*a.d;
        t2=d*a.n;
        t3=d*a.d;
        temp.n=t1-t2;
        temp.d=t3;
        return temp;
    }

    }
    ND operator*(ND &a)
    {
        ND temp;
        if(a.d!=0)
        {
            temp.n=n*a.n;
            temp.d=d*a.d;
        }
        return temp;
    }
    ND operator/(ND &a)
    {
        ND temp;
        if(a.d!=0)
        {
            temp.n=n*a.d;
            temp.d=d*a.n;
        }
        return temp;
    }

};
ND::ND():n(0),d(1)
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
    if(j!=0)
    {
        n=n*i;
        d=d*j;
    }
}
void ND::div(int i,int j)
{
    if(j!=0)
    {
        n=n*j;
        d=d*i;
    }
    
}
void ND::add(int i,int j)
{
    if(j!=0)
    {
        int t1=0,t2=0,t3=0;
        t1=n*j;
        t2=d*i;
        t3=d*j;
        n=t1+t2;
        d=t3;
    }
    
}
void ND::sub(int i,int j)
{
    if(j!=0)
    {
        int t1=0,t2=0,t3=0;
        t1=n*j;
        t2=d*i;
        t3=d*j;
        n=t1-t2;
        d=t3;
    }
    
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
void ND::exchange()
{
    n=-n;
    d=-d;
}


class MyInput
{
    private:
    std::string data[10];

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






int main()
{
    string infor;
    string input;

    cin>>infor;
    MyInput a(infor);
    ND number;
    ND ab;

    int N=0,D=0;
    N=stoi(a.GetdataIndex(0));
    D=stoi(a.GetdataIndex(1));
    

    number.setN(N);
    number.setD(D);
    while(cin>>input)
    {
        MyInput b(input);
        int i=stoi(b.GetdataIndex(1));
        int j=stoi(b.GetdataIndex(2));
      

        int tN=number.getN();
        int tD=number.getD();


       
        ab.setN(i);
        ab.setD(j);



        if(b.GetdataIndex(0)=="mul")
        {
            number=number*ab;
            
        }
        else if(b.GetdataIndex(0)=="div")
        {
            number=number/ab;
            
        }
        else if(b.GetdataIndex(0)=="add")
        {
            number=number + ab;
           
        }
        else if(b.GetdataIndex(0)=="sub")
        {
            number=number-ab;
           
        };

        if(number.getD()==0)
        {
            number.setN(tN);
            number.setD(tD);
        }
        number.reduced();
    }

   
    
    if(number.getD()==1)
    {
        cout<<number.getN();
    }
    else if(number.getD()<0)
    {
        number.exchange();
        cout<<number.getN()<<"/"<<number.getD();
    }
    else
    {
        cout<<number.getN()<<"/"<<number.getD();
    }
    
}