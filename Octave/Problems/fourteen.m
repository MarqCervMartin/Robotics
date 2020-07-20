Ruvw = [12.4; 76.6; 90.8; 1]

X =  [ 1 0 0 34.4;
      0 cosd(23) -sind(23) 32.15;
      0 sind(23) cosd(23) 45.06;
      0 0 0 1]
M = X*Ruvw
#print(x)
#plot3(46.8105,5.6000,28.4257,".o","LineWidth",2)

plot3(M(1,1),M(2,1),M(3,1),".o","LineWidth",2)
ylabel("y->")
xlabel("x->")
zlabel("z->")
title("Ejercicio 14")
grid("on")