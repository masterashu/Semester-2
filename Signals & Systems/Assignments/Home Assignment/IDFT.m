function [IDFT, n] = IDFT(signal, K)
    n = 0:length(K)-1;
    N = length(n);
    IDFT = zeros(size(n));
    for i_n = 1:N
        for i_k = 1:length(K)
            IDFT(i_n) = IDFT(i_n) + signal(i_k) * exp(1i*(2*pi/N)*K(i_k)*n(i_n));
        end
    end
    IDFT = IDFT./N;
end