// Incluímos la librería para poder controlar el servo
#include <Servo.h>
#include <Stepper.h> // libreria de motor a pasos
// Declaramos la variable para controlar el servo
Servo servoMotor;

const int stepsPerRevolution = 8;   // Numero de pasos por revolucion = 360 / ( angulo por paso) 
Stepper myStepper(stepsPerRevolution,  9, 10, 11, 12); //instancia del objeto con los parametros de pines de salida.
int stepCount = 0;// numero de pasos que ha dado el motor

void setup() {
  // Iniciamos el servo para que empiece a trabajar con el pin 9
  servoMotor.attach(13);

}

void loop() {
  // put your main code here, to run repeatedly:
  //if (stepCount < stepsPerRevolution) {  
    // step one step:
    myStepper.step(1);//giro negativo en contra de las mancillas,
    //giro positivo en sentido de las manecillas del reloj
    stepCount++;
    delay(500);
    //if(stepCount > 225){
    //  stepCount = 0;
    //}
  //}
  

}
void servMotor(){
  for (int i = 0; i <= 180; i++)
  {
    // Desplazamos al ángulo correspondiente
    servoMotor.write(i);
    // Hacemos una pausa de 25ms
    delay(25);
  }
 
  // Para el sentido negativo
  for (int i = 179; i > 0; i--)
  {
    // Desplazamos al ángulo correspondiente
    servoMotor.write(i);
    // Hacemos una pausa de 25ms
    delay(25);
  }
}
