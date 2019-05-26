%
% This problem Targets towards reducing noice in 
% a signal. 

T = -10:0.01:10;
y = cos(T) - sin(2.*T);
y = y + rand(size(y));

z1 = NoiseFilter(y, 3, 0.01);
z2 = NoiseFilter(y, 1, 0.01);
z3 = NoiseFilter(y, 0.3, 0.01);

plot(T,y,'c', 'LineWidth',0.5);
hold on;
plot(T,z1,'b','LineWidth',2);
hold on;
plot(T,z2,'k','LineWidth',2);
hold on;
plot(T,z3,'r','LineWidth',2);

