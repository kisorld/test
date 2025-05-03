#include <iostream>
#include<fstream>
#include<string.h>
#include<vector>
#include<algorithm>

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
    score(){}
    void print() const
    {
        cout<<num<<' '<<name<<' '<<s1<<' '<<s2<<' '<<s3<<endl;
    }
    string getNum() const { return num; } // Getter function for num
    string getName() const { return name; } // Getter function for name
    int getS1() const { return s1; } // Getter function for s1
    int getS2() const { return s2; } // Getter function for s2
    int getS3() const { return s3; } // Getter function for s3
    int getSum() const { return s1+s2+s3; } // Getter function for sum

};

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


void SetBinaryFile() // 把成绩写入二进制文件中
{
    ifstream ifs("Data1.dat", ios::out ); // 打开文件，准备写入
    if (!ifs.is_open()) // 如果文件打开失败，输出错误信息并退出程序
    {
        cerr << "Error: Unable to open file for writing." << endl;
        return; // 退出函数
    }

    string in; // 用于存储输入的字符串

    while (getline(ifs, in)) // 从标准输入读取一行字符串，直到文件结束
    {
        MyInput myInput(in); // 创建MyInput对象，将输入字符串分割成单独的字符串
        if (myInput.getSize() != 5) // 如果分割后的字符串数量不等于5，输出错误信息并继续下一行
        {
            cout << "Error: Invalid input format. Expected 5 values." << endl;
            continue;
        }
        score s(myInput.GetInput(0), myInput.GetInput(1), stoi(myInput.GetInput(2)), stoi(myInput.GetInput(3)), stoi(myInput.GetInput(4))); // 创建score对象，传入分割后的字符串和整数值
       
        ofstream ofs("DataBinary.dat", ios::out | ios::binary | ios::app); // 以二进制方式打开文件，准备追加写入
        if (!ofs.is_open()) // 如果文件打开失败，输出错误信息并退出程序
        {
            cerr << "Error: Unable to open file for writing." << endl;
            return;
        }
        ofs.write(reinterpret_cast<const char*>(&s), sizeof(s)); // 将score对象写入文件中
        ofs.close(); // 关闭文件
    }
    ifs.close(); // 关闭文件
    cout << "Data written to file successfully." << endl; // 输出成功信息


}

void Append_Data() // 追加数据
{
    string DataIn; // 用于存储输入的字符串
    cout << "Enter the data to append (comma-separated): "; // 提示用户输入数据
    cin >>DataIn; // 读取用户输入的字符串
    MyInput myInput(DataIn); // 创建MyInput对象，将输入字符串分割成单独的字符串
    if (myInput.getSize()!= 5) // 如果分割后的字符串数量不等于5，输出错误信息并退出函数	
    {
        cout << "Error: Invalid input format. Expected 5 values." << endl;
        return;	
    }
    score s(myInput.GetInput(0), myInput.GetInput(1), stoi(myInput.GetInput(2)), stoi(myInput.GetInput(3)), stoi(myInput.GetInput(4))); // 创建score对象，传入分割后的字符串和整数值
    ofstream ofs("DataBinary.dat", ios::out | ios::binary | ios::app); // 以二进制方式打开文件，准备追加写入
    if (!ofs.is_open()) // 如果文件打开失败，输出错误信息并退出程序
    {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }
    ofs.write(reinterpret_cast<const char*>(&s), sizeof(s)); // 将score对象写入文件中
    ofs.close(); // 关闭文件
    cout << "Data appended to file successfully." << endl; // 输出成功信息
}

void Update_Data() // 更新数据
{
    string DataNum;
    cout << "Enter the student number to update: "; // 提示用户输入要更新的学生学号
    cin >> DataNum; // 读取用户输入的学生学号
    score s; // 创建score对象，用于存储读取的数据
    ifstream ifs("DataBinary.dat", ios::in | ios::binary); // 以二进制方式打开文件，准备读取
    if (!ifs.is_open()) // 如果文件打开失败，输出错误信息并退出程序
    {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    streampos currentPos;
    int Bool = 0; // 用于标记是否找到匹配的学生学号
    while (!ifs.eof()) // 循环读取文件中的数据，直到文件结束
    {
        currentPos = ifs.tellg(); // 获取当前文件指针的位置
        ifs.read(reinterpret_cast<char*>(&s), sizeof(s)); // 读取score对象
        if (s.getNum() == DataNum) // 如果学号匹配，输出学生信息并提示用户输入新的成绩
        {
            Bool = 1; // 设置标记为1，表示找到匹配的学生学号
            cout << "Student found: " << s.getName() << " " << s.getS1() << " " << s.getS2() << " " << s.getS3() << endl; // 输出学生信息
            cout << "Enter new scores (comma-separated): "; // 提示用户输入新的成绩
            string DataScore; // 用于存储输入的字符串
            cin >> DataScore; // 读取用户输入的字符串
            MyInput myInput(DataScore); // 创建MyInput对象，将输入字符串分割成单独的字符串
            if (myInput.getSize() != 3) // 如果分割后的字符串数量不等于3，输出错误信息并退出函数
            {
                cout << "Error: Invalid input format. Expected 3 values." << endl;
                return;
            }
            s = score(s.getNum(), s.getName(), stoi(myInput.GetInput(0)), stoi(myInput.GetInput(1)), stoi(myInput.GetInput(2))); // 更新score对象的成绩
            break; // 跳出循环
        }
	
    }
    if (Bool == 0) // 如果没有找到匹配的学生学号，输出错误信息并退出函数
    {
        cout << "Error: Student not found." << endl;
        ifs.close(); // 关闭文件
        return;
    }
    ifs.close(); // 关闭文件

    ofstream ofs("DataBinary.dat", ios::in|ios::out | ios::binary); // 以二进制方式打开文件，准备写入
    if (!ofs.is_open()) // 如果文件打开失败，输出错误信息并退出程序
    {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }
    ofs.seekp(currentPos); // 将文件指针移动到更新位置的前一个位置
    ofs.write(reinterpret_cast<const char*>(&s), sizeof(s)); // 将更新后的score对象写入文件中
    ofs.close(); // 关闭文件
    cout << "Data updated in file successfully." << endl; // 输出成功信息
}

void Delete_Data() // 删除数据
{
    string DataNum; // 用于存储输入的学生学号
    cout << "Enter the student number to delete: "; // 提示用户输入要删除的学生学号
    cin >> DataNum; // 读取用户输入的学生学号
    score s; // 创建score对象，用于存储读取的数据
    ifstream ifs("DataBinary.dat", ios::in | ios::binary); // 以二进制方式打开文件，准备读取
    if (!ifs.is_open()) // 如果文件打开失败，输出错误信息并退出程序
    {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }
    
    int Bool = 0; // 用于标记是否找到匹配的学生学号
   
    streampos currentPos;
    while (!ifs.eof()) // 循环读取文件中的数据，直到文件结束
    {
        currentPos = ifs.tellg(); // 获取当前文件指针的位置
       
        ifs.read(reinterpret_cast<char*>(&s), sizeof(s)); // 读取score对象
        if (s.getNum() == DataNum) // 如果学号匹配，设置标记为1，表示找到匹配的学生学号
        {
            Bool = 1; // 设置标记为1，表示找到匹配的学生学号
            cout << "Student found: " << s.getName() << " " << s.getS1() << " " << s.getS2() << " " << s.getS3() << endl; // 输出学生信息
            break;; // 跳出循环
        }
    }


    if (Bool == 0) // 如果没有找到匹配的学生学号，输出错误信息并退出函数
    {
        cout << "Error: Student not found." << endl;
        ifs.close(); // 关闭文件
        return;
    }
    ifs.close(); // 关闭文件

    s=score(s.getNum(),s.getName(),0,0,0); // 创建一个空的score对象，用于填充删除后的位置

    ofstream ofs("DataBinary.dat", ios::out | ios::binary | ios::in); // 以二进制方式打开文件，准备写入（覆盖原有内容）
    if (!ofs.is_open()) // 如果文件打开失败，输出错误信息并退出程序
    {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    ofs.seekp(currentPos); // 将文件指针移动到删除位置的前一个位置
    ofs.write(reinterpret_cast<const char*>(&s), sizeof(s)); // 将空的score对象写入文件中，覆盖删除位置的内容
    ofs.close(); // 关闭文件
    cout << "Data deleted from file successfully." << endl; // 输出成功信息
}

void Print_Data() // 打印数据
{
    score s; // 创建score对象，用于存储读取的数据
    ifstream ifs("DataBinary.dat", ios::in | ios::binary); // 以二进制方式打开文件，准备读取
    if (!ifs.is_open()) // 如果文件打开失败，输出错误信息并退出程序	
    {
        cerr << "Error: Unable to open file for reading." << endl;
        return;	
    }
    vector<score> scores; // 创建一个vector，用于存储读取的数据
    while (!ifs.eof()) // 循环读取文件中的数据，直到文件结束
    {
        ifs.read(reinterpret_cast<char*>(&s), sizeof(s)); // 读取score对象
        if(s.getNum()!="") // 如果学号不为空，将score对象添加到vector中
        {
            scores.push_back(s); // 将score对象添加到vector中
        }      	
    }
    ifs.close(); // 关闭文件
    // 对vector中的数据进行排序，按照总成绩降序排列
    sort(scores.begin(), scores.end(), [](const score& a, const score& b) { return a.getSum() > b.getSum(); });
   
    // 输出排序后的成绩
    for (auto s : scores) // 遍历vector中的每个score对象
    {
        s.print(); // 输出score对象的信息
    }

    
}

void Defrag_Data() // 整理数据
{
    score s; // 创建score对象，用于存储读取的数据
    ifstream ifs("DataBinary.dat", ios::in | ios::binary); // 以二进制方式打开文件，准备读取
    if (!ifs.is_open()) // 如果文件打开失败，输出错误信息并退出程序	
    {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }
    vector<score> scores; // 创建一个vector，用于存储读取的数据
    while (!ifs.eof()) // 循环读取文件中的数据，直到文件结束
    {
        ifs.read(reinterpret_cast<char*>(&s), sizeof(s)); // 读取score对象
        if(s.getSum()!=0) // 如果成绩不为空，将score对象添加到vector中	
        {
            scores.push_back(s); // 将score对象添加到vector中	
        }
    }
    ifs.close(); // 关闭文件

    ofstream ofs("DataBinary.dat", ios::out | ios::binary|ios::trunc); // 以二进制方式打开文件，准备写入（覆盖原有内容）
    if (!ofs.is_open()) // 如果文件打开失败，输出错误信息并退出程序
    {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }
    for (const auto& s : scores) // 遍历vector中的每个score对象
    {
        ofs.write(reinterpret_cast<const char*>(&s), sizeof(s)); // 将score对象写入文件中 	
    }
    ofs.close(); // 关闭文件


}

int main()
{
    SetBinaryFile(); // 调用函数，写入数据到二进制文件中
    enum Function 
    {
        AppendData = 1, // 追加数据
        UpdateData = 2, // 更新数据
        DeleteData = 3, // 删除数据
        PrintData = 4, // 打印数据
        DefragData = 5, // 整理数据
        Exit = 0 // 退出程序
    };

    int choice; // 用于存储用户的选择

    while (true) // 无限循环，直到用户选择退出程序
    {
        cout << "Welcome to this score management system " << endl; // 输出提示信息
        cout << "Please select a function:" << endl; // 输出提示信息
        cout << "1. Append data 新增成绩" << endl; // 输出选项1
        cout << "2. Update data 修改成绩" << endl; // 输出选项2	
        cout << "3. Delete data 删除成绩" << endl; // 输出选项3
        cout << "4. Print data  显示成绩" << endl; // 输出选项4
        cout << "5. Defrag data 整理成绩" << endl; // 输出选项5
        cout << "0. Exit programme" << endl; // 输出选项0

        cout << "Enter your choice: "; // 提示用户输入选择
        cin >> choice; // 读取用户的选择

        switch (choice) // 根据用户的选择执行相应的操作
        {
            case AppendData: // 追加数据
                {
                    Append_Data(); //                    
                }
    
                break;
            case UpdateData: // 更新数据
                {
                    Update_Data(); // 
                }
    
                break;
            case DeleteData: // 删除数据
                {
                    Delete_Data(); // 
                }
    
                break;
            case PrintData: // 打印数据
                {
                    Print_Data();
                }
    
                break;
            case DefragData: // 整理数据
                {
                    Defrag_Data();
                }
    
                break;
            case Exit: // 退出程序
                {
                    cout << "Exiting program..." << endl; // 输出提示信息
                }              
                return 0; // 返回0表示程序正常结束
    
        }
        system("pause"); // 暂停程序，等待用户输入
        system("cls"); // 清屏，准备下一轮循环
    }
    return 0; // 返回0表示程序正常结束
}