function x = func1(n)
    x = zeros(size(n));
    x(n == -3) = -3;
    x(n == -2) = -2;
    x(n == -1) = 0;
    x(n == 0) = 1;
    x(n == 1) = 2;
    x(n == 2) = 3;
    
end