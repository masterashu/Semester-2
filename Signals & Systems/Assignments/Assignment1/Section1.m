
% Task 1
n = -30:0.01:30;
subplot(311);
% plot u(n-5) - u(n-10)
plot(n, myUnitStep(n - 5) - myUnitStep(n - 10), 'o');

subplot(312);
% plot u(6-n) - u(3-n)
plot(n, myUnitStep(6 - n) - myUnitStep(3 - n), 'o');

subplot(313);
% plot u(8-n)
plot(n, myUnitStep(8 - n), 'o');

% Task 2
n = -25:25;
% defining constants W and n0
w = 1.24
n0 = 11

subplot(211);
% plot cos(w(n-n0))
plot(n, cos(w.*(n-n0)), 'o');
hold on;
plot(n, cos(w.*(n-n0)), 'k');

subplot(212);
% plot cos(w(n+n0))
plot(n, cos(w.*(n+n0)), 'o');
hold on;
plot(n, cos(w.*(n+n0)), 'k');