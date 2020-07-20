Ruvw = [35.3; 32.1; 40; 1]

Y = [ cosd(79) 0 sind(79) 33.2;
      0 1 0 9.3;
      -sind(79) 0 cosd(79) 17.4;
      0 0 0 1]
      
      
x = Y*Ruvw

plot3(x(1,1),x(2,1),x(3,1),".o","LineWidth",2)
ylabel("y->")
xlabel("x->")
zlabel("z->")
title("Ejercicio 7")
grid("on")