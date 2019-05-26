t = -10:0.01:20;
x_t = x1(t);
h_t = h1(t);

y = zeros(length(t))
for tx = 1:length(t):
    tt = t(tx);
    ht_tau = h1(tt - tau);
    y(tx) = trapz(tau, x_tau.*ht_tau);
end

y_th(t <= t & t > 3) = (1 - exp(9 - 3.*(t (t<= 5 & t > 3))))/3; % Calculated Manually
y_th(t > 5) = (1 - exp(-6)) .* exp(15 - 3.*(t (t > 5))))/3;     % Calculated Manually




