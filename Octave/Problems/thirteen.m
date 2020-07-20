Z =  [ cosd(-2) -sind(-2) 0 78.4;
      sind(-2) cosd(-2) 0 67.8;
      0 0 1 97.8;
      0 0 0 1]
X =  [ 1 0 0 0;
      0 cosd(27) -sind(27) 0;
      0 sind(27) cosd(27) 0;
      0 0 0 1]
      
M = Z*X

plot3(M(1,1),M(2,1),M(3,1),".o","LineWidth",2)
ylabel("y->")
xlabel("x->")
zlabel("z->")
title("Ejercicio 13")
grid("on")