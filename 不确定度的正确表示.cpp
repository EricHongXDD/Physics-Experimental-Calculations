#include <iostream>
#include<cmath>
using namespace std;
// #define N 5  //一组数据个数；
int N = 0; //一组数据个数；
int zhengshu(double n){ // 判断有几位整数
    int temp = (int)n;
    int res = 1;
    while(temp >= 10)
    {
        res++;
        temp /= 10;
    }
    return res;
}

double jingque(double original, int n){ // 将小数original精确到小数点后n位
    double res = original;
    int temp = (int)res; // 取原先小数的整数部分


    int yidongweishu = n + 1; // 小数点移动位数 = 精确位数+1-整数位数+前为0的位数
    //double res = original;
    for (int i = 0; i < yidongweishu; ++i) { // 让整数位数为：精确位数+1位
        res *= 10;
    }
    temp = (int)res; // 保留精确位数+1位的整数部分
    int gewei = temp % 10; // 取个位数，四舍六入五凑偶
    if (gewei <= 4){ // 四舍
        temp -= gewei;
    }
    else if (gewei >= 6){ // 六入
        temp += (10 - gewei);
    }
    else if (gewei == 5){ // 五凑偶
        int shiwei = (temp / 10) % 10;
        if (shiwei % 2 == 0){ // 是偶数
            temp -= gewei;
        }
        else{ // 是奇数
            temp += (10 - gewei);
        }
    }
    res = (double)temp;
    for (int i = 0; i < yidongweishu; ++i) { // 得到精确后的结果
        res /= 10;
    }
    return res;
}

double jingque2(double original, int n){ // 将小数original精确到小数点后n位
    double res = original;
    int temp = (int)res; // 取原先小数的整数部分
    int weiling = 0; // 前为0的位数
    while (temp == 0) { // 第一位是0，不记录有效数字，继续往后乘，直到第一位不是0位置，并且累计移动位数
        res *= 10;
        weiling++;
        temp = (int)res;
    }
    int zhengshuwei = zhengshu(original); // 取被精确数的整数位
    int yidongweishu = n + 1 - zhengshuwei + weiling; // 小数点移动位数 = 精确位数+1-整数位数+前为0的位数
    //double res = original;
    for (int i = 0; i < yidongweishu - weiling; ++i) { // 让整数位数为：精确位数+1位
        res *= 10;
    }
    temp = (int)res; // 保留精确位数+1位的整数部分
    int gewei = temp % 10; // 取个位数，四舍六入五凑偶
    if (gewei <= 4){ // 四舍
        temp -= gewei;
    }
    else if (gewei >= 6){ // 六入
        temp += (10 - gewei);
    }
    else if (gewei == 5){ // 五凑偶
        int shiwei = (temp / 10) % 10;
        if (shiwei % 2 == 0){ // 是偶数
            temp -= gewei;
        }
        else{ // 是奇数
            temp += (10 - gewei);
        }
    }
    res = (double)temp;
    for (int i = 0; i < yidongweishu; ++i) { // 得到精确后的结果
        res /= 10;
    }
    return res;
}

void duiqi(double &x, double &u){
    double xo = x, uo = u;
    int xxiaoshu = 0;
    int yidongweishu = max(zhengshu(x), zhengshu(u))-1;
    //cout << "移动位数为：" << yidongweishu << endl;

    for (int i = 0; i < yidongweishu; ++i) {
        u /= 10;
        x /= 10;
    }
    //cout << "式子为：" << x << "±" << u << endl;

    double u2 = u*10;
    int temp = (int)u2; // 取原先u的整数部分
    int uxiaoshu = 1; // u小数点后需要保留的位数
    while (temp == 0) { // 第一位是0，u小数点后位数+1
        uxiaoshu++;
        u2 *= 10;
        temp = (int)u2;
    }
    //cout << "u小数点后有几位数字：" << uxiaoshu << endl;

    x = jingque(x,uxiaoshu); //精确到小数点后n位数字（精确位数 = 保留位数 + 1）
    u = jingque(u,uxiaoshu); //精确到小数点后n位数字

    //cout << xo << "±" << uo << "的正确表示为：(" << x << "±" << u << ")*(10^" << yidongweishu << ")" << endl;

    double ed = u / x * 100; // 计算直接计算得到的相对不确定度
    if (ed < 10){ // 如果e<10%,则保留1位数字
        ed = jingque2(ed,1);
    }
    else{ // 如果e>=10%,则保留2位数字
        ed = jingque2(ed,2);
    }

    if (yidongweishu != 0){
        cout << "正确表示为： {" << "x = (" << x << "±" << u << ")*(10^" << yidongweishu << ")单位" << endl;
        cout << "           {" << "E = " << ed << "%" << endl;
    }
    else{
        cout << "正确表示为： {" << "x = (" << x << "±" << u << ")单位" << endl;
        cout << "           {" << "E = " << ed << "%" << endl;
    }
}
int main()
{
    for (int i = 0; i < 10; ++i) {
        double x,u = 0;
        cout << "x平均(将科学计数法 转换为 普通数字输入)="; cin >> x; cout << "u(将科学计数法 转换为 普通数字输入)="; cin >> u;
        //cout << "式子为：" << x << "±" << u << endl;
        duiqi(x,u);
    }

    return 0;
}