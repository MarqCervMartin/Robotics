#include "LiquidCrystal.h" //libreria para el lcd
//Definicion de entradas para lcd
LiquidCrystal LCD(9, 8, 5, 4, 3, 2);
//el valor de la tensión de salida del sensor cuando la corriente = 0
double AcsOffset=2.5;
//El valor de la sensibilidad del sensor
double Sensibilidad=0.096;
double actual=0;
double tension=0;

void setup() {
  // put your setup code here, to run once:
  // Inicializamos LCD
  LCD.begin(16,2);

}

void loop() {
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
  LCD.print("Actual=");
  LCD.print(actual);
  LCD.print(" Amp");
  //medir frecuencia hertz y rpm
  //muestra en segundo determinar el cambio  * 60  =rpm
  
  delay(500);

}
