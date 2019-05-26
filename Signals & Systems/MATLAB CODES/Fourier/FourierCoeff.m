function [K_Vec output] = FourierCoeff(signal_x, t, TimePeriod, K_i, K_f)
% Function to find Fourier Coefficients of a given Periodic Signal
    Time_freq = (t(end) - t(1))/length(t);
    Time_i = t(1);
    Time_f = t(end);
    W = 2*pi/TimePeriod;
    output = zeros(size(1,K_f - K_i));
    K_Vec = K_i : K_f;
    for Kindex = 1:length(K_Vec)
        K = K_Vec(Kindex);
        basis = exp(-1*i * K * W .* t);
        output(Kindex) = 1 / TimePeriod * trapz(t, signal_x .* basis);
    end
    % figure;
    % stem(K_Vec, real(output), 'r');
    % hold on;
    % stem(K_Vec, imag(output), 'b');

    % figure;
    % subplot(2,1,1);
    % stem(K_Vec, real(output), 'r');
    % subplot(2,1,2);
    % stem(K_Vec, imag(output), 'b');
end

