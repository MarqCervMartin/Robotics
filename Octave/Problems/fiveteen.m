Z =  [ cosd(-78) -sind(-78) 0 31.3;
      sind(-78) cosd(-78) 0 51.2;
      0 0 1 98.3;
      0 0 0 1]
Y = [ cosd(120) 0 sind(120) 0;
      0 1 0 0;
      -sind(120) 0 cosd(120) 0;
      0 0 0 1]
M = Z*Y

plot3(M(1,1),M(2,1),M(3,1),".o","LineWidth",2)
ylabel("y->")
xlabel("x->")
zlabel("z->")
title("Ejercicio 15")
grid("on")