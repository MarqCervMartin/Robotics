// Incluímos la librería para poder controlar el servo
#include <Servo.h>// Declaramos la variable para controlar el servo
#include <Stepper.h>//declaramos libreria para motor  a pasos

Servo servoMotor;
int potenciometro1 = 1;


int motor1=11;
int pot1=A0;
int val=0;

const int stepsRevolution = 200; //definimos los pasos para una vuelta completa
Stepper Motor(stepsRevolution, 7, 9, 8, 10);//pines
int pot2=A2;
int valPot2;

void setup() {
  // put your setup code here, to run once:
  // Iniciamos el servo para que empiece a trabajar con el pin 13
  servoMotor.attach(13);
  pinMode(motor1,OUTPUT);
  pinMode(pot1,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  int leerServo = analogRead(potenciometro1);
  leerServo = map(leerServo, 0, 1023, 0, 180);
  servoMotor.write(leerServo);
  
  val=analogRead(pot1);//leer entrada analogica A0
  analogWrite(motor1,val);///DC PWM Modulacion por ancho de pulso.

  int val2 = analogRead(pot2);
  valPot2 = map(val2, 0, 1023, 0, 100);//conversion
  if(valPot2 >=51){
    Motor.setSpeed(5);//velocidad del rpm
    Motor.step(5);//cantidad a pasos
  }
  if(valPot2 <= 50){
    Motor.setSpeed(5);
    Motor.step(-5);
  }
}
