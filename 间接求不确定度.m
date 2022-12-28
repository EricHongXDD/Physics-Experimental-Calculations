clc;clear;close all
canshunum=input('请输入有几个间接参数：');

if canshunum == 1
    syms x1;
    y=input('请输入函数表达式,间接参数用x1，x2，x3，x4表示：y = ');
    u1=input('输入x1的不确定度u1（要保留2位小数的形式,注意单位换算）：');
    x1p=input('输入x1的平均值x1p：');
    yp = matlabFunction(y);
    yp = yp(x1p);
    X = sprintf('y平均 = %s = %f',y,yp); %X = sprintf('Un = √(%s * Ux1^2)',z);
    disp(X)
    y = log(y);
    z=diff(y,x1,1);
    X = sprintf('求出ln(y)对x1的偏导函数为:%s',z); %没有数值解时手算
    disp(X)
    f = matlabFunction(z);
    if z ~= fix(z)  %求代入平均值和不确定度的过程
        a1 = f(x1p)*u1*100;
        X = sprintf('E = %s * Ux1 * 100%%，其中：x1平均=%f  Ux1=%f = %f%% ≈（自己保留1位有效数字）',z,x1p,u1,a1); %X = sprintf('Un = √(%s * Ux1^2)',z);
        disp(X)
        a1=input('输入保留2位有效数字的E（不加百分号）：');
        U = a1*yp/100;
        X = sprintf('U = E * y平均 = %f ≈（自己保留1位有效数字）',U); %X = sprintf('Un = √(%s * Ux1^2)',z);
        disp(X)
    else
        a1 = fix(z)*u1*100;
        X = sprintf('E = %s * Ux1 * 100%%，（其中：x1平均=%f  Ux1=%f） = %f%% ≈（自己保留1位有效数字）',z,x1p,u1,a1);
        disp(X)
    end

elseif canshunum == 2
    syms x1 x2;
    y=input('请输入函数表达式,间接参数用x1，x2，x3，x4表示：y = ');
    u1=input('输入x1的不确定度u1（要保留2位小数的形式,注意单位换算）：');
    x1p=input('输入x1的平均值x1p：');
    u2=input('输入x2的不确定度u2（要保留2位小数的形式,注意单位换算）：');
    x2p=input('输入x2的平均值x2p：');
    yp = matlabFunction(y);
    yp = yp(x1p,x2p);
    X = sprintf('y平均 = %s = %f',y,yp); %X = sprintf('Un = √(%s * Ux1^2)',z);
    disp(X)
    y = log(y);

    z1=diff(y,x1,1);
    X = sprintf('求出ln(y)对x1的偏导函数为:%s',z1); %没有数值解时手算
    disp(X)
    f1 = matlabFunction(z1);
   
    z2=diff(y,x2,1);
    X = sprintf('求出ln(y)对x2的偏导函数为:%s',z2); %没有数值解时手算
    disp(X)
    f2 = matlabFunction(z2);

    %求代入平均值和不确定度的过程
    a1 = f1(x1p)*u1;
    a2 = f2(x2p)*u2;

    res = sqrt(a1^2+a2^2)*100;
    X = sprintf('E = √(%s^2 * Ux1^2  +  %s^2 * Ux2^2) = %f%% ≈（自己保留1位有效数字）',z1,z2,res);
    disp(X)

    a1=input('输入保留2位有效数字的E（不加百分号）：');
    U = a1*yp/100;
    X = sprintf('U = E * y平均 = %f ≈（自己保留1位有效数字）',U); %X = sprintf('Un = √(%s * Ux1^2)',z);
    disp(X)

    elseif canshunum == 3
    syms x1 x2 x3;
    y=input('请输入函数表达式,间接参数用x1，x2，x3，x4表示：y = ');
    u1=input('输入x1的不确定度u1（要保留2位小数的形式,注意单位换算）：');
    x1p=input('输入x1的平均值x1p：');
    u2=input('输入x2的不确定度u2（要保留2位小数的形式,注意单位换算）：');
    x2p=input('输入x2的平均值x2p：');
    u3=input('输入x3的不确定度u3（要保留2位小数的形式,注意单位换算）：');
    x3p=input('输入x3的平均值x3p：');
    yp = matlabFunction(y);
    yp = yp(x1p,x2p,x3p);
    X = sprintf('y平均 = %s = %f',y,yp); %X = sprintf('Un = √(%s * Ux1^2)',z);
    disp(X)
    y = log(y);

    z1=diff(y,x1,1);
    X = sprintf('求出ln(y)对x1的偏导函数为:%s',z1); %没有数值解时手算
    disp(X)
    f1 = matlabFunction(z1);
   
    z2=diff(y,x2,1);
    X = sprintf('求出ln(y)对x2的偏导函数为:%s',z2); %没有数值解时手算
    disp(X)
    f2 = matlabFunction(z2);

    z3=diff(y,x3,1);  
    X = sprintf('求出ln(y)对x3的偏导函数为:%s',z3); %没有数值解时手算
    disp(X)
    f3 = matlabFunction(z3);

    %求代入平均值和不确定度的过程
    a1 = f1(x1p)*u1;
    a2 = f2(x2p)*u2;
    a3 = f3(x3p)*u3;

    res = sqrt(a1^2+a2^2+a3^2)*100;
    X = sprintf('E = √(%s^2 * Ux1^2  +  %s^2 * Ux2^2  +  %s^2 * Ux3^2) = %f%% ≈（自己保留1位有效数字）',z1,z2,z3,res);
    disp(X)

    a1=input('输入保留2位有效数字的E（不加百分号）：');
    U = a1*yp/100;
    X = sprintf('U = E * y平均 = %f ≈（自己保留1位有效数字）',U); %X = sprintf('Un = √(%s * Ux1^2)',z);
    disp(X)

    elseif canshunum == 4
    syms x1 x2 x3 x4;
    y=input('请输入函数表达式,间接参数用x1，x2，x3，x4表示：y = ');
    u1=input('输入x1的不确定度u1（要保留2位小数的形式,注意单位换算）：');
    x1p=input('输入x1的平均值x1p：');
    u2=input('输入x2的不确定度u2（要保留2位小数的形式,注意单位换算）：');
    x2p=input('输入x2的平均值x2p：');
    u3=input('输入x3的不确定度u3（要保留2位小数的形式,注意单位换算）：');
    x3p=input('输入x3的平均值x3p：');
    u4=input('输入x3的不确定度u4（要保留2位小数的形式,注意单位换算）：');
    x4p=input('输入x3的平均值x4p：');
    yp = matlabFunction(y);
    yp = yp(x1p,x2p,x3p,x4p);
    X = sprintf('y平均 = %s = %f',y,yp); %X = sprintf('Un = √(%s * Ux1^2)',z);
    disp(X)
    y = log(y);

    z1=diff(y,x1,1);
    X = sprintf('求出ln(y)对x1的偏导函数为:%s',z1); %没有数值解时手算
    disp(X)
    f1 = matlabFunction(z1);
   
    z2=diff(y,x2,1);
    X = sprintf('求出ln(y)对x2的偏导函数为:%s',z2); %没有数值解时手算
    disp(X)
    f2 = matlabFunction(z2);

    z3=diff(y,x3,1);  
    X = sprintf('求出ln(y)对x3的偏导函数为:%s',z3); %没有数值解时手算
    disp(X)
    f3 = matlabFunction(z3);

    z4=diff(y,x4,1);  
    X = sprintf('求出ln(y)对x4的偏导函数为:%s',z4); %没有数值解时手算
    disp(X)
    f4 = matlabFunction(z4);

    %求代入平均值和不确定度的过程
    a1 = f1(x1p)*u1;
    a2 = f2(x2p)*u2;
    a3 = f3(x3p)*u3;
    a4 = f4(x4p)*u4;

    res = sqrt(a1^2+a2^2+a3^2+a4^2)*100;
    X = sprintf('E = √(%s^2 * Ux1^2  +  %s^2 * Ux2^2  +  %s^2 * Ux3^2  +  %s^2 * Ux4^2) = %f%% ≈（自己保留1位有效数字）',z1,z2,z3,z4,res);
    disp(X)

    a1=input('输入保留2位有效数字的E（不加百分号）：');
    U = a1*yp/100;
    X = sprintf('U = E * y平均 = %f ≈（自己保留1位有效数字）',U); %X = sprintf('Un = √(%s * Ux1^2)',z);
    disp(X)
end
