function LinConv = LinConv2(x, h)
	LinConv = [];
	temp =x.*h';
	[w, l] = size(temp);
	if(w > l)
		temp = temp';
    [w, l] = size(temp);
	end
  temp = [zeros(w,w-1) temp zeros(w,w-1)];
	for i = 1:(l + w - 1)
		sum = 0;
		for j = 1:w
			sum = sum + temp(w-j+1,i+j-1);
		end
		LinConv = [LinConv sum];
	end
end



