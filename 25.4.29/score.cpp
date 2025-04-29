#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;

class score 
{
    private:
    char num[15];
    char name[15];
    int s1;
    int s2;
    int s3;

    public:
    score(const string &Num,const string &Name,int a1,int a2,int a3) // Constructor to initialize the member variables
    {
        if (Num.length() < sizeof(num)) 
        {
            strcpy(num, Num.c_str());
        } 
        else 
        {
            // 处理字符串过长的情况
            Num.copy(num, sizeof(num) - 1);
            num[sizeof(num) - 1] = '\0';
        }
        if (Name.length() < sizeof(name))
        {
            strcpy(name, Name.c_str());
        } 
        else 
        {
            // 处理字符串过长的情况
            Name.copy(name, sizeof(name) - 1);
            name[sizeof(name) - 1] = '\0'; 
        }
        s1=a1; s2=a2; s3=a3;

    }
    void display() const // Display the member variables
    {
        cout << "num: " << num << endl;
        cout << "name: " << name << endl;
        cout << "s1: " << s1 << endl;
        cout << "s2: " << s2 << endl;
        cout << "s3: " << s3 << endl;
    }
};

int main()
{
    score s1("1234567891234567891234","xiaoming",90,80,70);
    score s2("123456789","xiaohong",95,85,75); 
    s1.display();
    s2.display();
}
    


