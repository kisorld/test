#include <string>
class MyInput
{
    private:
    std::string data[8];

    public:
    MyInput(std::string Input);
    std::string GetdataIndex(int Index);
};