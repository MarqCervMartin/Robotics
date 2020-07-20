Ruvw = [13; 6.9; 9; 1]
Y = [ cosd(29) 0 sind(29) 3.4;
      0 1 0 7.15;
      -sind(29) 0 cosd(29) 8.03;
      0 0 0 1]
   
      
x = Y*Ruvw


plot3(x(1,1),x(2,1),x(3,1),".o","LineWidth",2)
ylabel("y->")
xlabel("x->")
zlabel("z->")
title("Ejercicio 4")
grid("on")
