#include "LiquidCrystal.h"  //libreria para el lcd                                      
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);   //LCD parametros: (rs, enable, d4, d5, d6, d7)
const int trigPin = 12; //trigger pin del sensor
const int echoPin = 11;  //echopin pin del sensor
const int GreenTen = 9; //se prende a los 10cm o más
const int RedTwo = 8; //se prende a los 2cm o menos

long duration; //duracion
float distanceCm;  //distancia
float liquid; //lcd
                                                                                                            
void setup() { // Inicio y configuraciones
  lcd.begin(16,2);
  //trigger de salida y echo de entrada                                                   
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //leds Modo-Salida
  pinMode(GreenTen, OUTPUT);
  pinMode(RedTwo, OUTPUT);
  lcd.setCursor(0,0);
  lcd.print("  Distancia    ");
  lcd.setCursor(0,1);
  lcd.print("  Medicion  ");
  delay(2000);
  lcd.clear();
  
}

void loop() {   // loop del script
  //Escribimos en bajo el trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  //Escribimos en alto el pin trigPin despues de 2 microsegundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  //ecuacion de distancia con velocidad del sonido
  distanceCm= (duration*0.034/2)*0.1;
  //lcd en primera linea                                                                               
  lcd.setCursor(0,0);
  //impresión en lcd                                             
  lcd.print("Sensores");
  delay(10);
  //impresión segunda fila de lcd
  lcd.setCursor(0,1);
  lcd.print("D = ");
  lcd.print(distanceCm);
  lcd.print(" Cm ");
  //Condición de leds 
  if(distanceCm >=10){
      digitalWrite(GreenTen, HIGH);
      digitalWrite(RedTwo, LOW);
  }else{
    if(distanceCm <=2){
        digitalWrite(RedTwo, HIGH);
        digitalWrite(GreenTen, LOW);
    }else{
        digitalWrite(GreenTen, LOW);
        digitalWrite(RedTwo, LOW);
    }
  }
  delay(10);
}
