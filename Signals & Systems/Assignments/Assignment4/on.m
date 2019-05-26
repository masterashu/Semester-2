f=200; 
 fs=[200,300,400,500]; % sampling frequencies
for i = 1:length(fs)        

 Ts = 1/fs(i); % Sampling Period
 t = 0:1e-4:6/f; % time vector for continous plot
 w = f*2*pi;  
 xa = sin(w*t); % signal in continuous form

 t2=(0:Ts:6/f);  % time vector for sampling
 xb = sin(w*t2); % sampled signal 

 figure
 subplot(311); 
 plot(t,xa) % continous signal plot
 str = ['Signal x(t) = (' num2str(f) ' Hz)', ', Fs = ' num2str(fs(i)) ' Hz']; 
 title(str); 
 ylabel('Amplitude');
 xlabel('Time(s)');

 subplot(312); 

 stem(t2,xb); % sampled signal plot 
 title('Sampled signal'); 
 ylabel('Amplitude') 
 xlabel('Samples'); 

 xr = zeros(length(t));
 Tr = t(2)-t(1);
 for k=1:length(t)
 for p=1:length(xb)
%  xr(k)=xr(k) + xb(p)*sinc(fs(i)*(k-t2(p)));
    xr(k)=xr(k) + xb(p)*sinc( ((k-1)*Tr-(p-1)*Ts)/Ts );

 end
 end
 subplot(313);
 plot(t,xr);
 title('Recovered signal');
 ylabel('Amplitude');
 xlabel('Time(s)');
end

