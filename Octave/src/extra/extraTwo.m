Y = [ cosd(-15) 0 sind(-15) 0;
      0 1 0 0;
      -sind(-15) 0 cosd(-15) 0;
      0 0 0 1]
      
Rxyz = [2.5; 4.9; 8.1; 1]
x = Y*Rxyz

plot3(x(1,1),x(2,1),x(3,1),".o","LineWidth",2)
ylabel("y->")
xlabel("x->")
zlabel("z->")
title("Examen 2")
grid("on")
