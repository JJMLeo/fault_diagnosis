function test()
disp('this program solves for the roots of a quadratic equation');
a=input('enter the A;');
b=input('enter the B;');
c=input('enter the C;');
d=b^2-4*a*c;
x1=(-b+sqrt(d))/(2*a);
x2=(-b-sqrt(d))/(2*a);
fprintf('x1=%f\n',x1);
fprintf('x2=%f\n',x2);