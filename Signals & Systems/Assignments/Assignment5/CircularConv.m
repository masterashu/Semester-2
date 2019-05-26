function output = CircularConv(signal_1, signal_2)
    % CircularConv - Description
    % Recives two Signal and Finds Circular Convolution of the Signal using Matrix Multiplication Method
    N = length(signal_1);
    M = length(signal_2);
    Mat_A = zeros(N,N);
    Col_B = zeros(M,1);

    for ix = 0:N-1
        Mat = zeros(size(1,N));
        for iy = 0:N-1
            Mat(iy+1) = signal_1(mod((iy - ix + N),N)+1);
        end
        Mat_A(:,ix+1) = Mat';
    end
    Col_B = signal_2';
    
    output = (Mat_A * Col_B)';
        
end