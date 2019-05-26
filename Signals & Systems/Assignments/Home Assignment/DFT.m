function [DFT, K]  = DFT(signal, n)
    N = length(n);
    K = 0:N-1;
    DFT = zeros(size(K));
    for i_k = 1:length(K)
        for i_n = 1:N
            DFT(i_k) = DFT(i_k) + signal(i_n) * exp(-1i*(2*pi/N)*K(i_k)*n(i_n));
        end
    end
end