
%�������ű���a(��չϵ��)��b(��������)
syms a b;
c = [a b]';
file = load('PCP10.txt');
[m,n] = size(file);
result = [];
for ii=1:m
    A = file(ii,:);
    %ԭʼ���� A
    %A = [174, 179, 183, 189, 207, 234, 220.5, 256, 270, 285];
    %n = length(A);

    %��ԭʼ���� A ���ۼӵõ����� B
    B = cumsum(A);

%������ B �����ھ�ֵ����
    for i = 2:n
        C(i) = (B(i) + B(i - 1))/2; 
    end
    C(1) = [];

%�������ݾ��� 
    B = [-C;ones(1,n-1)];
    Y = A; Y(1) = []; Y = Y';

%ʹ����С���˷�������� a(��չϵ��)��b(��������)
    c = inv(B*B')*B*Y;
    c = c';
    a = c(1); 
    b = c(2);
    out = [a b];
    result = [result; out];
end