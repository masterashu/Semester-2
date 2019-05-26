dt = 0.02;
t = -3:dt:7;
X = x1(t);
H = h1(t);
% plot(t,X);
% hold on;
% plot(t,H, 'r');
[y yStartIndex] = LinConv(X, H, t(1), t(1));
plot([t(1)+t(1):dt:t(end)+t(end)] , y);
%hold on;
%plot(t2, trapz(X,H));


