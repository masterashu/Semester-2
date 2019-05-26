close all;
clear;
% Section 1
x1 = [3, 1, 4, 16, 2];
x2 = [3, -1, 3, -1];
h = [2, -1, -4, 1, -3];
% Signal addition using User-Defined add() function
% U
y1 = LinConv(add(x1, x2, 0, 0), h, 0, 0);
[y2a, y2aStartIndex] = LinConv(x1, h, 0, 0);
[y2b, y2bStartIndex] = LinConv(x2, h, 0, 0);
y2 = add(y2a, y2b, y2aStartIndex, y2bStartIndex);
% Using Inbuilt Function
Y1 = conv(add(x1, x2, 0, 0), h);
Y2 = add(LinConv(x1, h, 0, 0), LinConv(x2, h, 0, 0), 0, 0);
subplot(3,2,1);
stem([0:length(x1)-1], x1, 'b');
title('Signal X1[n]'); xlabel('n'); ylabel('X1[n]');
axis([-1,length(x1),min(x1)-1,max(x1)+1]); grid;

subplot(3,2,2);
stem([0:length(x2)-1], x2, 'b');
title('Signal X2[n]'); xlabel('n'); ylabel('X2[n]');
axis([-1,length(x2),min(x2)-1,max(x2)+1]); grid;

subplot(3,2,3);
stem([0:length(h)-1], h, 'b');
title('Signal H[n]'); xlabel('n'); ylabel('H[n]');
axis([-1,length(h),min(h)-1,max(h)+1]); grid;

subplot(3,2,4);
stem([0:length(y1)-1], y1, 'b');
title('Signal Y1[n]'); xlabel('n'); ylabel('Y1[n]');
axis([-1,length(y1),min(y1)-1,max(y1)+1]); grid;

subplot(3,2,5);
stem([0:length(y2)-1], y2, 'b');
title('Signal Y2[n]'); xlabel('n'); ylabel('Y2[n]');
axis([-1,length(y2),min(y2)-1,max(y2)+1]); grid;
%sgtitle('Section 1');
wt = waitforbuttonpress;

% Section 2
close all;
clear;

n = 0:5;
x = func1(n - 3); % Defining X[n-3]
h = [3, 1, 1, 3, 1, 1];
y = LinConv(x,h, 0, 0);
subplot(3,1,1);
stem([0:length(x)-1], x, 'b');
title('Signal X[n]'); xlabel('n'); ylabel('X[n]');
axis([-1,length(x),min(x)-1,max(x)+1]); grid;

subplot(3,1,2);
stem([0:length(h)-1], h, 'b');
title('Signal H[n]'); xlabel('n'); ylabel('H[n]');
axis([-1,length(h),min(h)-1,max(h)+1]); grid;

subplot(3,1,3);
stem([0:length(y)-1], y, 'b');
title('Signal Y[n]'); xlabel('n'); ylabel('Y[n]');
axis([-1,length(y),min(y)-1,max(y)+1]); grid;
sgtitle('Section 2');
wt = waitforbuttonpress;

% Section 3
close all;
clear;
n = -5:5;
nStartIndex = n(1);
% Defining x as x[n] 
x = func_x(n);
% Defining h as h[n] 
h = func_h(n);
% Defining x1 as x[1-n] 
x1 = func_x(1 - n);
% Defining h1 as h[1-n] 
h1 = func_h(1 - n);

[y1, y1StartIndex] = LinConv(x, h1, nStartIndex, nStartIndex);
[y2, y2StartIndex] = LinConv(x1, h, nStartIndex, nStartIndex);

subplot(2,2,1);
stem([nStartIndex:nStartIndex + length(x) - 1], x, 'b');
title('Signal X[n]'); xlabel('n'); ylabel('X[n]');
axis([nStartIndex-1,nStartIndex+length(x),min(x)-1,max(x)+1]); grid;

subplot(2,2,2);
stem([nStartIndex:nStartIndex + length(h) - 1], h, 'b');
title('Signal H[n]'); xlabel('n'); ylabel('H[n]');
axis([nStartIndex-1,nStartIndex+length(h),min(h)-1,max(h)+1]); grid;

subplot(2,2,3);
stem([y1StartIndex:y1StartIndex + length(y1) - 1], y1, 'b');
title('Signal Y1[n]'); xlabel('n'); ylabel('Y1[n]');
axis([y1StartIndex-1,y1StartIndex+length(y1),min(y1)-1,max(y1)+1]); grid;

subplot(2,2,4);
stem([y2StartIndex:y2StartIndex + length(y2) - 1], y2, 'b');
title('Signal Y2[n]'); xlabel('n'); ylabel('Y2[n]');
axis([y2StartIndex-1,y2StartIndex+length(y2),min(y2)-1,max(y2)+1]); grid;
sgtitle('Section 3');

wt = waitforbuttonpress;
close all;



