 tic
x = [1,3,5,-4,6];
h = [3,6,-1,5];
 LinConv = [];
	temp =x.*h';
	[w, l] = size(temp);
	if(w > l)
		temp = temp';
    [w, l] = size(temp);
	end
	for i = 2:(l + w)
		sum = 0;
		if(i <= w)
			for j = 1:i-1
				sum += temp(j,i-j);
			end
		elseif(i <= l+1)
			for j = 1:w
				sum += temp(w+1-j,i-w+j-1);
			end
		else
			for j = 1:l+w+1-i
				sum += temp(w+1-j,i-w+j-1);
			end
		end
		LinConv = [LinConv sum];
	end
  disp(LinConv)
 tt = toc