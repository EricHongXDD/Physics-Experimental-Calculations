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

void zhijie(double &h,double &s,double &x,double &b,double &d,double &ed){ // 直接测量不确定度
    cout << "输入数据的个数:" << endl; cin >> N;
    auto sj = new double[N];
    int i;
    double s1=0;
    int ws; // 有效位数
    cout << "输入数据的最小有效位数: " << endl; cin >> ws;
    cout << "输入修正值 Δ仪：" << endl; cin >> x; //一般是仪器修正值；
    double cs = 0; cout << "输入初始读数（保留负号，不要取绝对值）默认是0：" << endl; cin >> cs;
    for(i=0; i<N; i++)
    {
        cout << "请输入第" << i+1 << "组数据: " << endl;
        cin >> sj[i];
        sj[i] -= cs;
        h=h+sj[i];
    }
    h=h/N;
    h = jingque(h,ws);
    //cout << "平均数x = " << h << endl;
    for(i=0; i<N; i++)
    {
        s1 += (sj[i]-h)*(sj[i]-h);
    }
    s1 /= (N-1); s1 = sqrt(s1);
    double fenmu = jingque(s1,2); // 保存分母
    s = s1 / sqrt(N);
    s = jingque(s,2); // Ua计算过程多取1位，即2位有效数字
    double deltyi = x;
    x=x/sqrt(3);    //Ub分量不确定度有时会除根号三，可自行修改；
    x = jingque(x,2); // Ub计算过程多取1位，即2位有效数字
    b=sqrt(s*s+x*x);
    b = jingque(b,2); // Uc计算过程多取1位，即2位有效数字
    d = b * 2;
    d = jingque(d,2); // U结果取1位，若还参与计算（是中间变量），则保留2位有效数字
    //double ed = d / h * 100; // 计算直接计算得到的相对不确定度
    ed = d / h * 100; // 计算直接计算得到的相对不确定度
    if (ed < 10){ // 如果e<10%,则保留1位数字
        ed = jingque(ed,1);
    }
    else{ // 如果e>=10%,则保留2位数字
        ed = jingque(ed,2);
    }

    cout << "平均数x = " << h << endl;
    cout << "A分量Ua = " << "S/√n = " << fenmu << " / " << "√" << N << " = " << s << endl;
    cout << "B分量Ub = " << "Δ仪/√3 = " << deltyi << " / √3 = " << x << endl;
    cout << "合成标准不确定度值Uc = " << "√(Ua^2+Ub^2) = " << b << endl;
    cout << "扩展不确定度值U = " << "2Uc = " << d << " ≈ " << jingque(d,1) << endl;
    cout << "直接计算得到的相对不确定度E = " << "(U/x平均)*100% = (" << d << " / " << h << ") * 100% = " << ed << "%" << endl;
    cout << "x : {" << "x = x平均±U = (" << h << " ± " << jingque(d,1) << ")单位 ☆注意x平均和u末尾尾数是否对齐" << endl;
    cout << "    {" << "E = " << ed << "%" << endl;
}
int main()
{
    double h[10],s[10],x[10],b[10],d[10],ed[10] = {0};
    zhijie(h[1],s[1],x[1],b[1],d[1],ed[1]); // 直接测量得到的不确定度
    //cout << "测试是否保存E = " << ed[1] << endl << ed[2]; // 测试是否保存了数据
    return 0;
}