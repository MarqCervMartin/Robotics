Ruvw = [45.3; 34.6; 56.7; 1]

Y = [ cosd(88) 0 sind(88) 0;
      0 1 0 0;
      -sind(88) 0 cosd(88) 0;
      0 0 0 1]
      
x = Y*Ruvw

plot3(x(1,1),x(2,1),x(3,1),".o","LineWidth",2)
ylabel("y->")
xlabel("x->")
zlabel("z->")
title("Ejercicio 6s")
grid("on")