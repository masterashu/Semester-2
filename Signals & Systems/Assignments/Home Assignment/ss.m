t = -10:0.01:10;
subplot(311);
plot(t, x(4-t));
grid; axis equal
subplot(312);
plot(t, h(t-1));
grid; axis equal
subplot(313);
plot(t, x(4-t).*h(t-1));