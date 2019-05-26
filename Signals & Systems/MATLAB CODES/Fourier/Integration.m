function output = Integration(x, y)
    output = 0;
    for i = 1:length(y)-1
        output = output + (y(i) + y(i+1))*(x(i+1) - x(i))/2;
    end
end