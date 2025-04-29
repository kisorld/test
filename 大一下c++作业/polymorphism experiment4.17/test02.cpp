#include<iostream>
#include<string>
#include<vector>
#include<cmath>
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
    double area=0;
	virtual double Area()=0;
	virtual bool IsShape()=0;
    void setName(string name)
    {
        m_name=name;
    }
    virtual ~CShape()
    {

    }
    string getName()
    {
        return m_name;
    }

};


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
    
};
int CCircle::CirCount=1;


class CTriangle:public CShape//三角形类
{
private:
    double m_a,m_b,m_c;

public:
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
    void setLength(double a,double b,double c)
    {
        m_a=a;m_b=b;m_c=c;
    }
};

class CRectangle:public CShape
{
private:
    double m_w,m_l;

public:
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
    void setWL(int w,int l)
    {
        m_l=l;
        m_w=w;
    }
    

};

int main()
{
    string Input,name;
    vector<CShape*>vec;

   
    while (cin>>Input)
    {
        MyInput a(Input);
        


        if(a.GetInput(0)=="Circle")
        {
           
            
            if(a.getSize()==2)
            {
                double num=stod(a.GetInput(1));
                vec.push_back(new CCircle(num));
                if(vec.back()->IsShape())
                {
                    vec.back()->Area();
                    vec.back()->setName("Circle"+to_string(CCircle(0).CirCount));
                    CCircle(0).CirCount++;
                }
                else 
                {
                    vec.pop_back();
                }
            }
            
            
        }
    }

    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]->getName()<<" "<<vec[i]->area<<endl;

    }
    
}
