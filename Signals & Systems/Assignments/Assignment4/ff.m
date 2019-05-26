clear all;
close all;
clc;
f=input('Enter frequency');
%T=1/f;
fs1=input('Enter the sampling frequency');
fs2=input('Enter the sampling frequency');
fs3=input('Enter the sampling frequency');
t=0:0.1:100;
t1=0:1:99;

x=sin(2*3.14*f*t);
subplot(4,1,1);
plot(t,x);
xlabel('Time');
ylabel('Amplitude');
title('Continuous sine wave');

y=sin(2*3.14*f*t1/fs1);
subplot(4,1,2);
stem(t1,y);
xlabel('Time');
ylabel('Amplitude');
title('Sampled at 50');

y=sin(2*3.14*f*t1/fs2);
subplot(4,1,3);
stem(t1,y);
xlabel('Time');
ylabel('Amplitude');
title('Sampled at 500');

y=sin(2*3.14*f*t1/fs3);
subplot(4,1,4);
stem(t1,y);
xlabel('Time');
ylabel('Amplitude');
title('Sampled at 5000');