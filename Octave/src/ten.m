Ruvw = [12.4; 32.1; 9.8; 1]

Z =  [ cosd(54) -sind(54) 0 8.6;
      sind(54) cosd(54) 0 13.97;
      0 0 1 65.8;
      0 0 0 1]
M = Z*Ruvw
#print(x)
#plot3(46.8105,5.6000,28.4257,".o","LineWidth",2)

plot3(M(1,1),M(2,1),M(3,1),".o","LineWidth",2)
ylabel("y->")
xlabel("x->")
zlabel("z->")
title("Ejercicio 10")
grid("on")