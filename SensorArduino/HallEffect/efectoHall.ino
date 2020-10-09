#include "TimerOne.h"
#include "LiquidCrystal.h" //libreria para el lcd

//Definicion de entradas para lcd
LiquidCrystal LCD(9, 8, 5, 4, 3, 2);
//el valor de la tensión de salida del sensor cuando la corriente = 0
double AcsOffset=2.5;
//El valor de la sensibilidad del sensor
double Sensibilidad=0.096;
double actual=0;//valor de corriente
double tension=0;//valor de tension
int rpm;//variable de rmp
volatile byte pulsos;//pulsos para periodo
unsigned long timeold;//medimos tiempo
unsigned int pulsos_por_vuelta = 20;//variable de pulsos
float hertz = 0;//variable de hertz
void setup() {
  // put your setup code here, to run once:
  // Inicializamos LCD
  LCD.begin(16,2);//iniciamos LCD
  //pinMode(1,INPUT);
  attachInterrupt(0,contador,RISING); //interrupcion para pulsos
  pulsos = 0;//inicializamos variables
  rpm = 0;//rpm en cero vueltas
  timeold = 0;//tiempo en cero
}


void loop() {
  unsigned int time=0,RPM=0;
  // put your main code here, to run repeatedly:
  // Definir el valor leído por el sensor en el pin A0
  double LeerValor=analogRead(A0);
  // Convierta este valor a un voltaje entre 0 y 5V
  tension=(LeerValor*5.0/1023);
  // Definir la fórmula de cálculo actual
  actual=(tension-AcsOffset)/Sensibilidad;
  // Mueva el cursor en la pantalla LCD
  LCD.setCursor(0,0);
  // Imprime el valor actual en la pantalla LCD
  LCD.print("I=");
  LCD.print(actual);
  LCD.print("Amp");
  //medir frecuencia hertz y rpm
  //muestra en segundo determinar el cambio  * 60  =rpm
  
  if(millis() - timeold >= 1000){//medimos los milisegundos
    detachInterrupt(0);//des-interrupcion de para contar ciclos
    rpm = (60 * 1000 / pulsos_por_vuelta)/(millis()-timeold)*pulsos;//ecuacion rpm
    timeold = millis();//tiempo viejo
    pulsos = 0;//pulsos en cero
    hertz = rpm * 0.01667;
    LCD.setCursor(0,1);//impresion en segunda fila
    LCD.print("RPM:");
    LCD.print(rpm,DEC);//impresion de rpm entero
    LCD.print(" H:");
    LCD.print(hertz);
    attachInterrupt(0,contador,RISING);//iterrupcion 
  }
   
  

}
void contador()//contador de pulsos
{
  pulsos++;//incremento de variables
}
