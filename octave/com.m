#Ques 1:-
a = 10;
b = 2.5e23;
c = 2+3i;
d = exp((j*2*pi)/3);

#Ques 2:-
aVec = [3.14 15 9 26];
bVec = [2.71; 8; 28; 182];
cVec = [5:-.2:-5];
dVec = logspace(0,1,101);
eVec = "Hello";

#Ques 3:-
aMat = 2*ones(9);
bMat = diag([1,2,3,4,5,4,3,2,1]);
cMat = reshape([1:100],10,10);
dMat = nan(3,4);
eMat = [13, -1, 5;-22,10,-87];
fMat = randi([-3 3],5,3);

#Question 4:-
x = (1/(1+exp(-(a-15)/6)));
y = (a^0.5 + b^(1/21))^pi;
z = (log(real((c+d)*(c-d))*sin((a*pi)/3)))/(c*conj(c));

#Question 5:-
xVec = (1/(2*pi*(2.5)^2)^.5)*exp(-(cVec).^2/(2*(2.5)^2)^2);
yVec = (((aVec').^2) + (bVec).^2).^0.2;
zVec = log10(1./dVec);
xMat = (aVec*bVec)*aMat^2;

#Question 6
xMat = (aVec*bVec)*aMat^2;
yMat = bVec*aVec;
zMat = det(cMat)*(aMat*bMat)';

#Question 7

cSum = sum(cMat);
eMean = mean(eMat')';
eMat(1,:) = [1 1 1];
cSub = cMat(2:9,2:9);
lin = [1:20];
for i = 1:20
	if mod(i,2) == 0
		lin(i) = lin(i)*-1;
	endif
endfor
r = rand(1,5);
for i = 1:5
	if r(i) < 0.5
		r(i) = 0;
	endif
endfor

#Question 8
figure
t=linspace(0,2*pi);
y=sin(t);
plot(t,y)
hold on
y1=cos(t);
plot(t,y1,'--r')
title('sin & cos function');
xlabel('time(x)');
ylabel('function values');
legend('y=sin(x)','y1=cos(x)');
legend('sin(x)','cos(x)');
xlim([0 2*pi]);
ylim([-1.4 1.4]);







