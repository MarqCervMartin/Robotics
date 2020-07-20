Z =  [ cosd(-45) -sind(-45) 0 4;
      sind(-45) cosd(-45) 0 6;
      0 0 1 10.5;
      0 0 0 1]    
Y = [ cosd(50) 0 sind(50) 0;
      0 1 0 0;
      -sind(50) 0 cosd(50) 0;
      0 0 0 1]
x = Z*Y
#print(x)
#plot3(46.8105,5.6000,28.4257,".o","LineWidth",2)

plot3(x(1,1),x(2,1),x(3,1),".o","LineWidth",2)
ylabel("y->")
xlabel("x->")
zlabel("z->")
title("Ejercicio 5")
grid("on")