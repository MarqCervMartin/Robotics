#include "LiquidCrystal.h"  //libreria para el lcd                                      
#include <Servo.h>                    // Incluir la librería Servo
Servo servo1;                         // Crear un objeto tipo Servo llamado servo1
int angulo = 0 ;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);   //LCD parametros: (rs, enable, d4, d5, d6, d7)
const int trigPin = 12; //trigger pin del sensor
const int echoPin = 11;  //echopin pin del sensor
const int GreenTen = 9; //se prende a los 10cm o más
const int RedTwo = 8; //se prende a los 2cm o menos

long duration; //duracion
float distanceCm;  //distancia
float liquid; //lcd
int motorPin1 = 10;
int motorPin2 = 13;
                                                                                                          
void setup() { // Inicio y configuraciones
  //inicio configuracion lcd
  lcd.begin(16,2);
  //trigger de salida y echo de entrada                                                   
  pinMode(trigPin, OUTPUT);
  //echoPin en modo entrada
  pinMode(echoPin, INPUT);
  //leds Modo-Salida
  pinMode(GreenTen, OUTPUT);
  //led rojo en modo salida
  pinMode(RedTwo, OUTPUT);
  //imprimir en primera fila del lcd
  lcd.setCursor(0,0);
  //imprimir letrero distancia
  lcd.print("  Distancia    ");
  //configurar para imprimir en segunda fila
  lcd.setCursor(0,1);
  //imprimir medicion
  lcd.print("  Medicion  ");
  //esperar 2 segundos
  servo1.attach(10) ;             // Conectar servo1 al pin 9
  //pin motor 1 salida
  pinMode(motorPin1, OUTPUT);
  //pin motor 2 salida
  pinMode(motorPin2, OUTPUT);
  delay(2000);
  //limpiar lcd
  lcd.clear();

}

void loop() {   // loop del script
  //Escribimos en bajo el trigPin
  digitalWrite(trigPin, LOW);
  //esperar 2 microsegundos
  delayMicroseconds(2);
  //Escribimos en alto el pin trigPin despues de 2 microsegundos
  digitalWrite(trigPin, HIGH);
  //esperar 10 microsegundos del trigger
  delayMicroseconds(10);
  //escribir paso bajo a triggerpin
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  //ecuacion de distancia con velocidad del sonido
  distanceCm= (duration*0.034/2)*0.1;
  //lcd en primera linea                                                                               
  lcd.setCursor(0,0);
  //impresión en lcd                                             
  lcd.print("Sensores");
  //esperar 10 microsegundos
  delay(10);
  //impresión segunda fila de lcd
  lcd.setCursor(0,1);
  //imprimir distancia
  lcd.print("D = ");
  //imprimimos variable de distancia
  lcd.print(distanceCm);
  //imprimimos unidades
  lcd.print(" Cm ");
  //Condición de leds 
  //si la distancia es mayor a 10
  if(distanceCm >=10){
      //entonces prendemos en paso alto el led verde
      digitalWrite(GreenTen, HIGH);
      //apagamos en paso bajo el led rojo
      digitalWrite(RedTwo, LOW);
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
      /*for(angulo  = 0; angulo  <= 180; angulo  += 1){   //incrementa angulo 1 grado
        servo1.write(angulo);
        delay(25);
      }*/
  }else{
    //si la distancia es menor a dos centimetros
    if(distanceCm <=2){
        //entonces en paso alto prendemos el led rojo
        digitalWrite(RedTwo, HIGH);
        //en paso bajo apagamos el led verde
        digitalWrite(GreenTen, LOW);
        /*for(angulo  = 180; angulo  >=0; angulo  -=1 ){    //decrementa angulo 1 grado
          servo1.write( angulo );
          delay(25);
        }*/
        digitalWrite(motorPin2, HIGH);
        digitalWrite(motorPin1, LOW);
    }else{
        //si esta entre 2 y 10 se apaga con paso bajo led verde
        digitalWrite(GreenTen, LOW);
        //tambien se apaga en paso bajo el led rojo
        digitalWrite(RedTwo, LOW);
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin1, LOW);
    }
  }

  //delay de 10 microsegundos
  delay(10);
}
