#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

int zhengshu(long double n){ // 判断有几位整数
    int temp = (int)n;
    int res = 1;
    while(temp >= 10)
    {
        res++;
        temp /= 10;
    }
    return res;
}

int main() {
    // 创建一个 map 用于存储颜色和数值的对应关系
    map<string, int> colors = {
            {"黑", 0}, {"棕", 1}, {"红", 2}, {"橙", 3},
            {"黄", 4}, {"绿", 5}, {"兰", 6}, {"紫", 7},
            {"灰", 8}, {"白", 9}, {"蓝", 6}
    };

    // 创建一个 map 用于存储颜色和倍率的对应关系
    map<string, int> multipliers = {
            {"黑", 0}, {"棕", 1}, {"红", 2}, {"橙", 3},
            {"黄", 4}, {"绿", 5}, {"金", -1}, {"银", -2},  {"蓝", 6}
    };

    // 创建一个 vector 用于存储输入的颜色
    vector<string> bands;

    int n; cout << "输入色环个数"; cin >> n;
    cout << "输入电阻色环（从左至右）\n";

    // 输入n个颜色
    string color;
    for (int i = 0; i < n; ++i) {
        cin >> color;
        bands.push_back(color);
    }


    // 计算电阻阻值
    long double value = 0;
//    for (int i = bands.size() - 3; i >= 0; i--) {
//        value = value * 10 + colors[bands[i]];
//    }
    for (int i = 0; i <= bands.size() - 3; i++) {
        value = value * 10 + colors[bands[i]];
    }
    int multiplier = multipliers[bands[bands.size() - 2]];
    //value *= pow(10, multiplier);

    // 查询误差
    double tolerance;
    if (bands[bands.size() - 1] == "棕") {
        tolerance = 1;
    } else if (bands[bands.size() - 1] == "红") {
        tolerance = 2;
    } else if (bands[bands.size() - 1] == "绿") {
        tolerance = 0.5;
    } else if (bands[bands.size() - 1] == "兰") {
        tolerance = 0.25;
    } else if (bands[bands.size() - 1] == "紫") {
        tolerance = 0.1;
    } else if (bands[bands.size() - 1] == "金") {
        tolerance = 5;
    } else if (bands[bands.size() - 1] == "银") {
        tolerance = 10;
    } else{
        tolerance = 100;
        cout << "tolerance color error" << endl;
    }

    //cout << value << endl;

//    value *= 100;
//    long double temp = value;
//    int num = zhengshu(value)-1;
//    for (int i = 0; i < num; ++i) {
//        temp /= 10;
//    }

    cout << "阻值R为：" << value << "*" << "(10^" << multiplier << ")Ω" << endl;
    cout << "百分误差E为：±" << tolerance << "%" << endl;

    return 0;
}
