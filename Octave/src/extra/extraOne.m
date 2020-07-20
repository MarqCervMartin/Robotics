X =  [ 1 0 0 0;
      0 cosd(75) -sind(75) 0;
      0 sind(75) cosd(75) 0;
      0 0 0 1] 
      
Ruvw = [3.5; 6.4; 9.1; 1]
x = X*Ruvw

plot3(x(1,1),x(2,1),x(3,1),".o","LineWidth",2)
ylabel("y->")
xlabel("x->")
zlabel("z->")
title("Examen 1")
grid("on")
