% check 1
t = -1:0.01:1;
FourierCoeff(t.^3, t, 3, -10, 10);

% Therotical
KK = -10:10;
Ak = zeros(1,21);
for Index = 1:21
  k = KK(Index);
  Ak(Index) = Ak(Index) + ((exp(-1*j*2*pi/3))*( ((3*i)/(2*pi*k)) + ((27)/(4 * pi* pi * k * k)) - ((81*j)/(4*(pi*k)^3)) + ((243)/(8*(pi*k)^4))));   
  Ak(Index) =  Ak(Index) + ((exp(1*j*2*pi/3))*( ((3*i)/(2*pi*k)) - ((27)/(4 * pi* pi * k * k)) - ((81*j)/(4*(pi*k)^3)) - ((243)/(8*(pi*k)^4))));   
 end
 
figure;
subplot(2,1,1);
stem(KK, real(Ak));
subplot(2,1,2);
stem(KK, imag(Ak));