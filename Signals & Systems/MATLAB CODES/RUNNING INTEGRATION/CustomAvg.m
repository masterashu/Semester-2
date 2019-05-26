function output = CustomAvg(A, N, divSize)
    output = zeros(size(A));
    k = floor(N/0.01);
    for i = 1:floor(length(A)*divSize/N)-1
        temp = sum(A(1+(i-1)*k:1+i*k))/k;
        output(1+(i-1)*k:1+i*k) = temp;
    end
end