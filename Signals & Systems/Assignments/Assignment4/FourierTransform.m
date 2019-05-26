function output = FourierTransform(signal, t, W)
    output = zeros(size(W));
    for iw = 1:length(W)
        w = W(iw);
        output(iw) = trapz(t,signal.*exp(-1i*w*t));
    end
end