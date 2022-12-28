#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

int zhengshu(long double n){ // �ж��м�λ����
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
    // ����һ�� map ���ڴ洢��ɫ����ֵ�Ķ�Ӧ��ϵ
    map<string, int> colors = {
            {"��", 0}, {"��", 1}, {"��", 2}, {"��", 3},
            {"��", 4}, {"��", 5}, {"��", 6}, {"��", 7},
            {"��", 8}, {"��", 9}, {"��", 6}
    };

    // ����һ�� map ���ڴ洢��ɫ�ͱ��ʵĶ�Ӧ��ϵ
    map<string, int> multipliers = {
            {"��", 0}, {"��", 1}, {"��", 2}, {"��", 3},
            {"��", 4}, {"��", 5}, {"��", -1}, {"��", -2},  {"��", 6}
    };

    // ����һ�� vector ���ڴ洢�������ɫ
    vector<string> bands;

    int n; cout << "����ɫ������"; cin >> n;
    cout << "�������ɫ�����������ң�\n";

    // ����n����ɫ
    string color;
    for (int i = 0; i < n; ++i) {
        cin >> color;
        bands.push_back(color);
    }


    // ���������ֵ
    long double value = 0;
//    for (int i = bands.size() - 3; i >= 0; i--) {
//        value = value * 10 + colors[bands[i]];
//    }
    for (int i = 0; i <= bands.size() - 3; i++) {
        value = value * 10 + colors[bands[i]];
    }
    int multiplier = multipliers[bands[bands.size() - 2]];
    //value *= pow(10, multiplier);

    // ��ѯ���
    double tolerance;
    if (bands[bands.size() - 1] == "��") {
        tolerance = 1;
    } else if (bands[bands.size() - 1] == "��") {
        tolerance = 2;
    } else if (bands[bands.size() - 1] == "��") {
        tolerance = 0.5;
    } else if (bands[bands.size() - 1] == "��") {
        tolerance = 0.25;
    } else if (bands[bands.size() - 1] == "��") {
        tolerance = 0.1;
    } else if (bands[bands.size() - 1] == "��") {
        tolerance = 5;
    } else if (bands[bands.size() - 1] == "��") {
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

    cout << "��ֵRΪ��" << value << "*" << "(10^" << multiplier << ")��" << endl;
    cout << "�ٷ����EΪ����" << tolerance << "%" << endl;

    return 0;
}
