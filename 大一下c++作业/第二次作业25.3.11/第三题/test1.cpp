#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <cmath>

// 定义一个结构体来表示二维点
struct Point {
    double x, y;
};

// 计算两个点之间的向量
std::pair<double, double> getVector(const Point& p1, const Point& p2) {
    return {p2.x - p1.x, p2.y - p1.y};
}

// 计算两个向量的点积
double dotProduct(const std::pair<double, double>& v1, const std::pair<double, double>& v2) {
    return v1.first * v2.first + v1.second * v2.second;
}

// 计算向量的模长的平方
double lengthSquared(const std::pair<double, double>& v) {
    return v.first * v.first + v.second * v.second;
}

// 判断四个点是否构成矩形
bool isRectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    // 计算四条边的向量
    auto v1 = getVector(p1, p2);
    auto v2 = getVector(p2, p3);
    auto v3 = getVector(p3, p4);
    auto v4 = getVector(p4, p1);

    // 检查相邻边是否垂直，相对边是否相等
    return dotProduct(v1, v2) == 0 && dotProduct(v2, v3) == 0 && dotProduct(v3, v4) == 0 && dotProduct(v4, v1) == 0 &&
           lengthSquared(v1) == lengthSquared(v3) && lengthSquared(v2) == lengthSquared(v4);
}

// 计算矩形的面积
double calculateRectangleArea(const Point& p1, const Point& p2, const Point& p3) {
    auto v1 = getVector(p1, p2);
    auto v2 = getVector(p2, p3);
    return std::sqrt(lengthSquared(v1)) * std::sqrt(lengthSquared(v2));
}

using namespace std;

int main() {
    string line;
    double show[100];
        int j=0;
    while (getline(cin, line)) {
        istringstream iss(line);
        vector<double> coordinates;
        string token;
        
        while (getline(iss, token, ',')) {
            coordinates.push_back(stod(token));
        }

        // 提取四个点的坐标
        Point p1 = {coordinates[0], coordinates[1]};
        Point p2 = {coordinates[2], coordinates[3]};
        Point p3 = {coordinates[4], coordinates[5]};
        Point p4 = {coordinates[6], coordinates[7]};

        // 判断四个点是否构成矩形
        if (isRectangle(p1, p2, p3, p4)) {
            // 计算矩形的面积
             show[j] = calculateRectangleArea(p1, p2, p3);
            j++;
        } else {
            show[j]=0;
            j++;
        }
    }
    for(int i=0;i<j;i++)
    {
        if(show[i]==0)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<fixed<<setprecision(4)<<fabs(show[i])<<endl;
        }
    }

    return 0;
}