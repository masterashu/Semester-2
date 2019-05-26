function x = func_x(n)
	x = zeros(size(n));
	% x = [1,2,-3,8,-9]
	x(n == 0) = 1;
	x(n == 1) = 2;
	x(n == 2) = -3;
	x(n == 3) = 8;
	x(n == 4) = -9;
end

