
%建立符号变量a(发展系数)和b(灰作用量)
syms a b;
c = [a b]';
file = load('PCP10.txt');
[m,n] = size(file);
result = [];
for ii=1:m
    A = file(ii,:);
    %原始数列 A
    %A = [174, 179, 183, 189, 207, 234, 220.5, 256, 270, 285];
    %n = length(A);

    %对原始数列 A 做累加得到数列 B
    B = cumsum(A);

%对数列 B 做紧邻均值生成
    for i = 2:n
        C(i) = (B(i) + B(i - 1))/2; 
    end
    C(1) = [];

%构造数据矩阵 
    B = [-C;ones(1,n-1)];
    Y = A; Y(1) = []; Y = Y';

%使用最小二乘法计算参数 a(发展系数)和b(灰作用量)
    c = inv(B*B')*B*Y;
    c = c';
    a = c(1); 
    b = c(2);
    out = [a b];
    result = [result; out];
end