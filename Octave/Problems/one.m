Ruvw = [3.5; 6.4; 9.1; 1] # Column vector[13;5.6;53.2,1]
X =  [ 1 0 0 0;
      0 cosd(85) -sind(85) 0;
      0 sind(85) cosd(85) 0;
      0 0 0 1]  
#Z =  [ cos() -sin() 0 0;
#      sin() cos() 0 0;
#      0 0 1 0;
#      0 0 0 1]    
      
x = X*Ruvw
#print(x)
#plot3(46.8105,5.6000,28.4257,".o","LineWidth",2)

plot3(x(1,1),x(2,1),x(3,1),".o","LineWidth",2)
ylabel("y->")
xlabel("x->")
zlabel("z->")
title("Ejercicio 1")
grid("on")