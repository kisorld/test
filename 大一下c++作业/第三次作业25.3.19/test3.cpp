#include <iostream>
#include <cstring>
class MyString {
private:
char* data;
size_t length;
public:
// 默认构造函数
MyString () : data (nullptr), length (0) {}
// 带参数的构造函数
MyString (const char* str) {
if (str == nullptr) {
length = 0;
data = new char [1];
data [0] = '\0';
} else {
length = strlen (str);
data = new char [length + 1];
strcpy (data, str);
}
}
// 拷贝构造函数
MyString (const MyString& other) {
length = other.length;
data = new char [length + 1];
strcpy (data, other.data);
}
// 析构函数
~MyString () {
delete [] data;
}
// 重载 + 运算符
MyString operator+(const MyString& other) const {
size_t newLength = length + other.length;
char* newData = new char [newLength + 1];
strcpy (newData, data);
strcat (newData, other.data);
MyString result (newData);
delete [] newData;
return result;
}
// 重载赋值运算符
MyString& operator=(const MyString& other) {
if (this != &other) {
delete [] data;
length = other.length;
data = new char [length + 1];
strcpy (data, other.data);
}
return *this;
}
// 输出字符串
void print () const {
std::cout << data << std::endl;
}
};
int main() {
MyString s3("Hello ");
MyString s4("World");
MyString s5 = s3 + s4;
s5.print();
return 0;
}