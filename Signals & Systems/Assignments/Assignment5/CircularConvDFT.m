function [output, X1, X2, K] = CircularConvDFT(signal_1, signal_2, n)
% CircularConvDFT - Description
% Recives two Signal and Finds Circular Convolution of the Signal using the DFT Method
    N = length(n);
    [X1, ~] = DFT(signal_1, n);
    [X2, K] = DFT(signal_2, n);

    X3 = X1.*X2;

    [output, ~] = IDFT(X3,K);
end