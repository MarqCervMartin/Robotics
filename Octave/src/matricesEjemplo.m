b = [-2; 7; 3; 1] # Column vector
A = [ 1 0 0 6;
      0 1 0 -3;
      0 0 1 8;
      0 0 0 1]
x = A * b     # Solve the system Ax = b
plot3(4,4,11,".b","LineWidth",2)