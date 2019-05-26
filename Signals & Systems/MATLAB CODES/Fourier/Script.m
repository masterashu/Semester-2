t = -1:0.01:1;
T = 3;
[kvec ak] = FourierCoeff(sin(t), t, T, -50, 50);
plot(t, t);
hold on;
plot(t, real(Reconstruction(t, ak, kvec, T)))
hold on;
plot(t, imag(Reconstruction(t, ak, kvec, T)))