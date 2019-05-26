%
% The projectile problem with zero air resistance
% in a gravitational field with constant g.
%
% Written by D. T. Valentine ........ September 2006
% Revised by D. T. Valentine ........ November 2008
% An eight-step structure plan applied in MATLAB:
%
% 1. Definition of the input variables.
%
g = 9.81; % Gravity in m/s/s.
vo = input('What is the launch speed in m/s? ');
tho = input('What is the launch angle in degrees? ');
tho = pi*tho/180; % Conversion of degrees to radians.
%
% 2. Calculate the range and duration of the flight.
%
txmax = (2*vo/g) * sin(tho);
xmax = txmax * vo * cos(tho);
%
% 3. Calculate the sequence of time steps to compute trajectory.
%
dt = txmax/100;
t = 0:dt:txmax;
%
% 4. Compute the trajectory.
%
x = (vo * cos(tho)) .* t;
y = (vo * sin(tho)) .* t -(g/2) .* t.^2;
%
% 5. Compute the speed and angular direction of the projectile.
% Note that vx = dx/dt, vy = dy/dt.
%
vx = vo * cos(tho);
vy = vo * sin(tho) -g .* t;
v = sqrt(vx.*vx + vy.*vy);
th = (180/pi) .* atan2(vy,vx);
%
% 6. Compute the time, horizontal distance at maximum altitude.
%
tymax = (vo/g) * sin(tho);
xymax = xmax/2;
ymax = (vo/2) * tymax * sin(tho);
%
% 7. Display ouput.
%
disp([' Range in m = ',num2str(xmax), ...
' Duration in s = ', num2str(txmax)])
disp(' ')
disp([' Maximum altitude in m = ',num2str(ymax), ...
' Arrival in s = ', num2str(tymax)])
plot(x,y,'k',xmax,y(size(t)),'o',xmax/2,ymax,'o')
title([' Projectile flight path, vo =',num2str(vo), ...
' th =', num2str(180*th/pi)])
xlabel(' x '), ylabel(' y ') % Plot of Figure 1.
figure % Creates a new figure.
plot(v,th,'r')
title(' Projectile speed vs. angle ')
xlabel(' V '), ylabel(' \theta ') % Plot of Figure 2.
%
% 8. Stop.
%