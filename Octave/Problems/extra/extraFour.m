I = [1 0 0 3.4
     0 1 0 7.15
     0 0 1 8.03
     0 0 0 1]
Y = [ cosd(19) 0 sind(19) 0;
      0 1 0 0;
      -sind(19) 0 cosd(19) 0;
      0 0 0 1]
      
Ruvw = [13; 6.9; 9.7; 1]
     
x = I*Y*Ruvw

plot3(x(1,1),x(2,1),x(3,1),".o","LineWidth",2)
ylabel("y->")
xlabel("x->")
zlabel("z->")
title("Examen 4")
grid("on")