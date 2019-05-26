function h = func_h(n)
    h = zeros(size(n));
    % h = [3,2,1,2,3]
    h(n == 0) = 3;
    h(n == 1) = 2;
    h(n == 2) = 1;
    h(n == 3) = 2;
    h(n == 4) = 3;    
end