I = [1 0 0 4.8
     0 1 0 6.3
     0 0 1 -9.2
     0 0 0 1]
     
Ruvw = [3.4; -5.7; 9; 1]

x = I*Ruvw

plot3(x(1,1),x(2,1),x(3,1),".o","LineWidth",2)
ylabel("y->")
xlabel("x->")
zlabel("z->")
title("Examen 3")
grid("on")
