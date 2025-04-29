#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<iomanip>

using namespace std;

class MyInput
{
private:
     
    vector<string> data;

    
public:
   
	MyInput(string in)  // 把输入的字符串按逗号分成单独的字符串
	{
		
		string temp="";
		for(int i=0;i<in.size();i++)
		{
			if( in[i] == ',' )
			{
                data.push_back(temp);
				
				temp = "";
              
			}
			else
				temp = temp + in[i];
		}
        data.push_back(temp);
       
	}
    
	string GetInput(int index)
	{
      
		return  data[index];
	}	
    int getSize()
    {
        return data.size();
    }
    
};


class CShape
{
private:
	string m_name;
    
public:
    double area;
	virtual double Area()=0;
	virtual bool IsShape()=0;
    void setName(string name)
    {
        m_name=name;
    }
    string getName()
    {
        return m_name;
    }
    virtual ~CShape()=0;
    
};
CShape::~CShape()
{

}


class CCircle:public CShape//圆类
{
private:
    double R;

public:
    static int CirCount;
    CCircle(double r):R(r){}
    bool IsShape()
    {
        if(R>0)
            return true;

        return false;
    }
    double Area()
    {
        if(IsShape())
        {
            area=R*R*3.1416;
            return area;
        }
           
        else 
            return 0;
    }
    void setR(double r)
    {
        R=r;
    }
    ~CCircle(){};
};
int CCircle::CirCount=1;

class CTriangle:public CShape//三角形类
{
private:
    double m_a,m_b,m_c;

public:
    static int TriCount;
    CTriangle(double a,double b,double c):m_a(a),m_b(b),m_c(c){}
    bool IsShape()
    {
        if(m_a>0&&m_b>0&&m_c>0)
        {
            if((m_a+m_b)>m_c&&(m_a+m_c)>m_b&&(m_c+m_b)>m_a)
                return true;
        }
        return false;
    }
    double Area()
    {
        if(IsShape())
        {
            double P=(m_a+m_b+m_c)/2;
            area=sqrt(P*(P-m_a)*(P-m_b)*(P-m_c));
            return area;
        }
        else 
            return 0;
        
    }
    ~CTriangle(){};
   
};
int CTriangle::TriCount=1;

class CRectangle:public CShape
{
private:
    double m_w,m_l;

public:
    static int RecCount; 
    CRectangle(double w,double l):m_l(l),m_w(w){}
    bool IsShape()
    {
        if(m_l>0&&m_w>0)
        {
            return true;
        }
        else 
            return false;
    }
    double Area()
    {
        if(IsShape())
        {
            area=m_l*m_w;
            return area;
        }
        else 
            return 0;
    }
    ~CRectangle(){};
    
    

};
int CRectangle::RecCount=1;

int main()
{
    string Input,name;
    vector<CShape *>vec;

    while (cin>>Input)
    {
        MyInput a(Input);
        


        if(a.GetInput(0)=="Circle")
        {
            if(a.getSize()>=2)
            {
                double num=stod(a.GetInput(1));
                vec.push_back(new CCircle(num));
                if(vec.back()->IsShape())
                {
                    vec.back()->Area();
                    vec.back()->setName("Circle"+to_string(CCircle::CirCount));
                    CCircle::CirCount++;
                }
                else 
                {
                    delete vec.back();
                    vec.pop_back();
                }
            }
            
            
        }
        if(a.GetInput(0)=="Triangle")
        {
            if(a.getSize()>=4)
            {
                
                vec.push_back(new CTriangle(stod(a.GetInput(1)),stod(a.GetInput(2)),stod(a.GetInput(3))));
                if(vec.back()->IsShape())
                {
                    vec.back()->Area();
                    vec.back()->setName("Triangle"+to_string(CTriangle::TriCount));
                    CTriangle::TriCount++;
                }
                else 
                {
                    delete vec.back();
                    vec.pop_back();
                }
            }
            
        }

        if(a.GetInput(0)=="Rectangle")
        {
            if(a.getSize()>=3)
            {
                
                vec.push_back(new CRectangle(stod(a.GetInput(1)),stod(a.GetInput(2))));
                if(vec.back()->IsShape())
                {
                    vec.back()->Area();
                    vec.back()->setName("Rectangle"+to_string(CRectangle::RecCount));
                    CRectangle::RecCount++;
                }
                else 
                {
                    delete vec.back();
                    vec.pop_back();
                }
            }
        }

    }

    int n = vec.size();
    // 冒泡排序
    for (int i = 0; i < n - 1; ++i)
     {
        for (int j = 0; j < n - i - 1; ++j) 
        {
            if (vec[j]->area > vec[j + 1]->area)
            {
                CShape *temp =vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }

   

    if(vec.size()%2==1)
    {
        cout<<fixed<<setprecision(2)<<vec[(vec.size()/2)]->area<<endl;
    }
    if(vec.size()%2==0)
    {
       double a=vec[vec.size()/2]->area;
       double b=vec[vec.size()/2-1]->area;
       double c=(a+b)/2.0;
       cout<<fixed<<setprecision(2)<<c<<endl;

    }
    cout<<vec.back()->getName()<<endl;

   




    
    for(auto i:vec)
    {
        delete i;
    }
    
}