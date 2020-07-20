Rxyz = [43.2; 65.4; 31.2; 1]
X =  [ 1 0 0 0;
      0 cosd(-17) -sind(-17) 0;
      0 sind(-17) cosd(-17) 0;
      0 0 0 1]
      
M = X*Rxyz
#print(x)
#plot3(46.8105,5.6000,28.4257,".o","LineWidth",2)

plot3(M(1,1),M(2,1),M(3,1),".o","LineWidth",2)
ylabel("y->")
xlabel("x->")
zlabel("z->")
title("Ejercicio 12")
grid("on")