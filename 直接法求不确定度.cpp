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

void zhijie(double &h,double &s,double &x,double &b,double &d,double &ed){ // ֱ�Ӳ�����ȷ����
    cout << "�������ݵĸ���:" << endl; cin >> N;
    auto sj = new double[N];
    int i;
    double s1=0;
    int ws; // ��Чλ��
    cout << "�������ݵ���С��Чλ��: " << endl; cin >> ws;
    cout << "��������ֵ ���ǣ�" << endl; cin >> x; //һ������������ֵ��
    double cs = 0; cout << "�����ʼ�������������ţ���Ҫȡ����ֵ��Ĭ����0��" << endl; cin >> cs;
    for(i=0; i<N; i++)
    {
        cout << "�������" << i+1 << "������: " << endl;
        cin >> sj[i];
        sj[i] -= cs;
        h=h+sj[i];
    }
    h=h/N;
    h = jingque(h,ws);
    //cout << "ƽ����x = " << h << endl;
    for(i=0; i<N; i++)
    {
        s1 += (sj[i]-h)*(sj[i]-h);
    }
    s1 /= (N-1); s1 = sqrt(s1);
    double fenmu = jingque(s1,2); // �����ĸ
    s = s1 / sqrt(N);
    s = jingque(s,2); // Ua������̶�ȡ1λ����2λ��Ч����
    double deltyi = x;
    x=x/sqrt(3);    //Ub������ȷ������ʱ������������������޸ģ�
    x = jingque(x,2); // Ub������̶�ȡ1λ����2λ��Ч����
    b=sqrt(s*s+x*x);
    b = jingque(b,2); // Uc������̶�ȡ1λ����2λ��Ч����
    d = b * 2;
    d = jingque(d,2); // U���ȡ1λ������������㣨���м������������2λ��Ч����
    //double ed = d / h * 100; // ����ֱ�Ӽ���õ�����Բ�ȷ����
    ed = d / h * 100; // ����ֱ�Ӽ���õ�����Բ�ȷ����
    if (ed < 10){ // ���e<10%,����1λ����
        ed = jingque(ed,1);
    }
    else{ // ���e>=10%,����2λ����
        ed = jingque(ed,2);
    }

    cout << "ƽ����x = " << h << endl;
    cout << "A����Ua = " << "S/��n = " << fenmu << " / " << "��" << N << " = " << s << endl;
    cout << "B����Ub = " << "����/��3 = " << deltyi << " / ��3 = " << x << endl;
    cout << "�ϳɱ�׼��ȷ����ֵUc = " << "��(Ua^2+Ub^2) = " << b << endl;
    cout << "��չ��ȷ����ֵU = " << "2Uc = " << d << " �� " << jingque(d,1) << endl;
    cout << "ֱ�Ӽ���õ�����Բ�ȷ����E = " << "(U/xƽ��)*100% = (" << d << " / " << h << ") * 100% = " << ed << "%" << endl;
    cout << "x : {" << "x = xƽ����U = (" << h << " �� " << jingque(d,1) << ")��λ ��ע��xƽ����uĩββ���Ƿ����" << endl;
    cout << "    {" << "E = " << ed << "%" << endl;
}
int main()
{
    double h[10],s[10],x[10],b[10],d[10],ed[10] = {0};
    zhijie(h[1],s[1],x[1],b[1],d[1],ed[1]); // ֱ�Ӳ����õ��Ĳ�ȷ����
    //cout << "�����Ƿ񱣴�E = " << ed[1] << endl << ed[2]; // �����Ƿ񱣴�������
    return 0;
}