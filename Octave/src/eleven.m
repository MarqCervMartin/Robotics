Ruvw = [45.7; 32.5; 78.6; 1]
Z =  [ cosd(23) -sind(23) 0 0;
      sind(23) cosd(23) 0 0;
      0 0 1 0;
      0 0 0 1]
      
M = Z*Ruvw
#print(x)
#plot3(46.8105,5.6000,28.4257,".o","LineWidth",2)

plot3(M(1,1),M(2,1),M(3,1),".o","LineWidth",2)
ylabel("y->")
xlabel("x->")
zlabel("z->")
title("Ejercicio 11")
grid("on")