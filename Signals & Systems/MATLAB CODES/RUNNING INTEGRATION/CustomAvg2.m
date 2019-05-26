function output = CustomAvg2(A, N, divSize)
    output = zeros(size(A));
    k = floor(N/divSize);
    k2 = floor(1/divSize);
    for i = 1:floor(length(A)*divSize)-N-1
        temp = sum(A((i-1)*k2+1:1+(i-1)*k2+k))/k;
        output((i-1)*k2+1:i*k2+k) = temp;
    end
end
