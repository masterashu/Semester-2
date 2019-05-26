function [add SI] = add(a, b, aSI, bSI) % Signals and their Starting Indexes
% Function to add two arrays of diffrent length by considering remaining elements as zero
	SI = min(aSI, bSI); % Starting Index of convoluted signal
	endIndex  = max(aSI + length(a), bSI + length(b));
	k = endIndex - SI;
	add = zeros(1,k);
	add(aSI-SI+1:aSI-SI+length(a)) = add(aSI-SI+1:aSI-SI+length(a)) + a;
	add(bSI-SI+1:bSI-SI+length(b)) = add(bSI-SI+1:bSI-SI+length(b)) + b;
end