function output = Integrate(y, x)
    output = 0;
    for x_i = 1: length(x) - 1
        output = output + (y(x_i) + y(x_i + 1))*(x(x_i + 1) - x(x_i)) / 2; 
    end
 end 