function output = Reconstruction(t, Ak, K, T)
    W = 2*pi/T;
    y = zeros(size(t));
    for ik = length(K)
        k = K(ik);
        y1 = Ak(ik)*exp(-1i*W*k.*t);
        y = y + y1;
    output = y;
end