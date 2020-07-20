Y = [ cosd(-34) 0 sind(-34) 5.6;
      0 1 0 3.6;
      -sind(-34) 0 cosd(-34) 5.9;
      0 0 0 1]
X =  [ 1 0 0 0;
      0 cosd(78) -sind(78) 0;
      0 sind(78) cosd(78) 0;
      0 0 0 1]  

M = Y*X
#print(x)
#plot3(46.8105,5.6000,28.4257,".o","LineWidth",2)

plot3(M(1,1),M(2,1),M(3,1),".o","LineWidth",2)
ylabel("y->")
xlabel("x->")
zlabel("z->")
title("Ejercicio 9")
grid("on")