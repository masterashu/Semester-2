function output = NoiseFilter(A, N, divSize)
    output = zeros(size(A));
    k = floor(N/divSize);
    for i = 1:length(A)-k-1
        temp = sum(A(i:i+k))/k;
        output(i:i+k) = temp;
    end
end
