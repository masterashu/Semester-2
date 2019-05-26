function output = Reconstruction(t, Ak, K, T)
    W = 2*pi/T;
    y = zeros(size(t));
    for ik = K
        y = y + Ak(ik)*exp(-1i*W*ik.*t);
    output = y;
end