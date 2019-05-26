% Part - 1

close all;
clear;

T = -10:0.01:25;
% Saving function sin(x)
y = sin(T);

% Defining Size
N = 3;
y1 = CustomAvg(y, 3, 0.01);

subplot(211);
plot(T,y,'r');
hold on;
plot(T,y1,'b');

% Part - 2
z = sin(T);
z1 = CustomAvg2(z, 3, 0.01);

subplot(212);
plot(T,z,'r');
hold on;
plot(T,z1,'b');

