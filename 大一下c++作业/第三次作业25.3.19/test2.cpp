#include <iostream>
#include <cstring>

using namespace std;

class MyString
{
private:
    char *p;
public:
    MyString():p(NULL)
    {

    }

    MyString(const char *str)
    {
        int len=strlen(str);
        p=new char[len+1];
        strcpy(p,str);
    }

    MyString(const MyString &a)
    {
        int len=strlen(a.p);
        p=new char[len+1];
        strcpy(p,a.p);
    }
    
    ~MyString()
    {
        if(p!=NULL)
        {
            delete []p;
            p=NULL;
        }
    }

    MyString &operator=(const MyString &a)
    {
        int len;
        len=strlen(a.p);
        p=new char[len+1];
        strcpy(p,a.p);
        return *this;
    }

    MyString operator+(const MyString &a)
    {
        int len1=0,len2=0;
        len1=strlen(p);
        len2=strlen(a.p);
        MyString temp;
        temp.p=new char[len1+len2+1];
        strcpy(temp.p,p);
        strcat(temp.p,a.p);
        
        return temp;        


    }
    void SetNewString(const char *str)
    {
        int len=strlen(str);
        p=new char[len+1];
        strcpy(p,str);
    }

    friend ostream& operator<<(ostream& os, const MyString& str);

};

ostream& operator<<(ostream& os, const MyString& str)
{
    os<<str.p;
    return os;
};
int main()
{
   MyString s1("First"), s2("Second");
   MyString s3=s1;
   MyString s4;
   s4=s2;

   s3.SetNewString("long string");
   s4.SetNewString("scut");

   cout<<s1<<"  "<<s3<<endl;   //s1,s3应该显示不一样的内容
   cout<<s2<<"  "<<s4<<endl;   //s2,s4应该显示不一样的内容

   MyString s5=s3+s4;
   cout<<s5<<endl;  //应该显示s3,s4合并在一起的内容

}