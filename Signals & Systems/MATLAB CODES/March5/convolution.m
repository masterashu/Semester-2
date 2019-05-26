dt = 0.05;
t = -3:dt:7;
X = x1(t);
H = h1(t);
% plot(t,X);
% hold on;
% plot(t,H, 'r');

t2 = (t(1) - floor(length(t)*dt/2) ) : dt : (t(end) + floor(length(t)*dt/2) );
y = zeros(size(t2));
index = 1;
for i = t2
    % for j = t
    %     y(index) = y(index) + h1(j)*x1(i-j);
    % end
    y(index) = h1(i - t).*(t);
    index = index + 1;
end

plot(t2, y);
%hold on;
%plot(t2, trapz(X,H));


