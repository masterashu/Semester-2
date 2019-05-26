tic
x = [1,3,5,-4,6];
y = [3,6,-1,5];
l = length(x) + length(y) - 1;
X = zeros(l,l);
xe = zeros(1,l);
xe(1:length(x)) = x;

for i = 1:length(x)
  X(i,1:i) = fliplr(xe(1:i));
end
xe = fliplr(xe);
for i = length(x)+1:l
  X(i,1:i) = xe(l-i+1:l);
end
H = zeros(1,l);
H(1:length(y)) = y;
H=H';
(X*H)'
tt = toc