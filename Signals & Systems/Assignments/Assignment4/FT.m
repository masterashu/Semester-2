function output = FT(signal, time, W)
    output = zeros(size(W));
    for iw = 1:length(W)
        w = W(iw);
        output(iw) = Integrate(signal.*exp(-1i*w*time),time);
    end
end