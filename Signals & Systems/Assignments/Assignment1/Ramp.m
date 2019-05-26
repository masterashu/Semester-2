function ramp = Ramp(t)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
r = t - floor(t + 0.5) - 0.5;
ramp = r.*2;
end

