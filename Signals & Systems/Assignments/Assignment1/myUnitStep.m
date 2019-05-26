function Output = myUnitStep(t)
%UNIT_STEP_FUNCTION a function defined as y(x) = 1 for all x >= 0
a = zeros(size(t));
a(t>=0) = 1;
Output = a;
end
