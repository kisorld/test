#include "MyInput.h"

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