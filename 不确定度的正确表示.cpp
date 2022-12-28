#include <iostream>
#include<cmath>
using namespace std;
// #define N 5  //һ�����ݸ�����
int N = 0; //һ�����ݸ�����
int zhengshu(double n){ // �ж��м�λ����
    int temp = (int)n;
    int res = 1;
    while(temp >= 10)
    {
        res++;
        temp /= 10;
    }
    return res;
}

double jingque(double original, int n){ // ��С��original��ȷ��С�����nλ
    double res = original;
    int temp = (int)res; // ȡԭ��С������������


    int yidongweishu = n + 1; // С�����ƶ�λ�� = ��ȷλ��+1-����λ��+ǰΪ0��λ��
    //double res = original;
    for (int i = 0; i < yidongweishu; ++i) { // ������λ��Ϊ����ȷλ��+1λ
        res *= 10;
    }
    temp = (int)res; // ������ȷλ��+1λ����������
    int gewei = temp % 10; // ȡ��λ���������������ż
    if (gewei <= 4){ // ����
        temp -= gewei;
    }
    else if (gewei >= 6){ // ����
        temp += (10 - gewei);
    }
    else if (gewei == 5){ // ���ż
        int shiwei = (temp / 10) % 10;
        if (shiwei % 2 == 0){ // ��ż��
            temp -= gewei;
        }
        else{ // ������
            temp += (10 - gewei);
        }
    }
    res = (double)temp;
    for (int i = 0; i < yidongweishu; ++i) { // �õ���ȷ��Ľ��
        res /= 10;
    }
    return res;
}

double jingque2(double original, int n){ // ��С��original��ȷ��С�����nλ
    double res = original;
    int temp = (int)res; // ȡԭ��С������������
    int weiling = 0; // ǰΪ0��λ��
    while (temp == 0) { // ��һλ��0������¼��Ч���֣���������ˣ�ֱ����һλ����0λ�ã������ۼ��ƶ�λ��
        res *= 10;
        weiling++;
        temp = (int)res;
    }
    int zhengshuwei = zhengshu(original); // ȡ����ȷ��������λ
    int yidongweishu = n + 1 - zhengshuwei + weiling; // С�����ƶ�λ�� = ��ȷλ��+1-����λ��+ǰΪ0��λ��
    //double res = original;
    for (int i = 0; i < yidongweishu - weiling; ++i) { // ������λ��Ϊ����ȷλ��+1λ
        res *= 10;
    }
    temp = (int)res; // ������ȷλ��+1λ����������
    int gewei = temp % 10; // ȡ��λ���������������ż
    if (gewei <= 4){ // ����
        temp -= gewei;
    }
    else if (gewei >= 6){ // ����
        temp += (10 - gewei);
    }
    else if (gewei == 5){ // ���ż
        int shiwei = (temp / 10) % 10;
        if (shiwei % 2 == 0){ // ��ż��
            temp -= gewei;
        }
        else{ // ������
            temp += (10 - gewei);
        }
    }
    res = (double)temp;
    for (int i = 0; i < yidongweishu; ++i) { // �õ���ȷ��Ľ��
        res /= 10;
    }
    return res;
}

void duiqi(double &x, double &u){
    double xo = x, uo = u;
    int xxiaoshu = 0;
    int yidongweishu = max(zhengshu(x), zhengshu(u))-1;
    //cout << "�ƶ�λ��Ϊ��" << yidongweishu << endl;

    for (int i = 0; i < yidongweishu; ++i) {
        u /= 10;
        x /= 10;
    }
    //cout << "ʽ��Ϊ��" << x << "��" << u << endl;

    double u2 = u*10;
    int temp = (int)u2; // ȡԭ��u����������
    int uxiaoshu = 1; // uС�������Ҫ������λ��
    while (temp == 0) { // ��һλ��0��uС�����λ��+1
        uxiaoshu++;
        u2 *= 10;
        temp = (int)u2;
    }
    //cout << "uС������м�λ���֣�" << uxiaoshu << endl;

    x = jingque(x,uxiaoshu); //��ȷ��С�����nλ���֣���ȷλ�� = ����λ�� + 1��
    u = jingque(u,uxiaoshu); //��ȷ��С�����nλ����

    //cout << xo << "��" << uo << "����ȷ��ʾΪ��(" << x << "��" << u << ")*(10^" << yidongweishu << ")" << endl;

    double ed = u / x * 100; // ����ֱ�Ӽ���õ�����Բ�ȷ����
    if (ed < 10){ // ���e<10%,����1λ����
        ed = jingque2(ed,1);
    }
    else{ // ���e>=10%,����2λ����
        ed = jingque2(ed,2);
    }

    if (yidongweishu != 0){
        cout << "��ȷ��ʾΪ�� {" << "x = (" << x << "��" << u << ")*(10^" << yidongweishu << ")��λ" << endl;
        cout << "           {" << "E = " << ed << "%" << endl;
    }
    else{
        cout << "��ȷ��ʾΪ�� {" << "x = (" << x << "��" << u << ")��λ" << endl;
        cout << "           {" << "E = " << ed << "%" << endl;
    }
}
int main()
{
    for (int i = 0; i < 10; ++i) {
        double x,u = 0;
        cout << "xƽ��(����ѧ������ ת��Ϊ ��ͨ��������)="; cin >> x; cout << "u(����ѧ������ ת��Ϊ ��ͨ��������)="; cin >> u;
        //cout << "ʽ��Ϊ��" << x << "��" << u << endl;
        duiqi(x,u);
    }

    return 0;
}