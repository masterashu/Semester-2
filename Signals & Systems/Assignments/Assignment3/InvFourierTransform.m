function output = InvFourierTransform(signal, W, time)
   output = zeros(size(time));
   it = 0;
   for t = time
     it = it + 1;
     output(it) = Integrate(signal.*exp(1i*t*W), W);
   end
   output = output/(2*pi);
end
