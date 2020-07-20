Rxyz = [2.5; 4; 8; 1] # Column vector[13;5.6;53.2,1]
Y = [ cosd(15) 0 sind(15) 0;
      0 1 0 0;
      -sind(15) 0 cosd(15) 0;
      0 0 0 1]
#Z =  [ cos() -sin() 0 0;
#      sin() cos() 0 0;
#      0 0 1 0;
#      0 0 0 1]    
      
x = Y*Rxyz
#print(x)
#plot3(46.8105,5.6000,28.4257,".o","LineWidth",2)

plot3(x(1,1),x(2,1),x(3,1),".o","LineWidth",2)
ylabel("y->")
xlabel("x->")
zlabel("z->")
title("Ejercicio 2")
grid("on")