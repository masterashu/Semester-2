% Section 3
close all;
clear;
n = -5:5;
nStartIndex = n(1);
x = func_x(n);
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

%sgtitle('Task 3');
