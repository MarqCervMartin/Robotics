#include <LiquidCrystal.h>//Libreria de LCD
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);//Pines para LCD

void setup() {
  // put your setup code here, to run once:
  pinMode(0, OUTPUT);//Inicializa pin 0 como salida
  pinMode(1, OUTPUT);//inicializa pin 1 como salida
  lcd.begin(16,2);   //Indicamos el inicio del LCD
  lcd.setCursor(0,0);//Impresion primera fila
  lcd.print("TemperaturaLM35");//Imprimimos en pantalla 
  delay(2000);//2 segundos retardo
  lcd.clear();//Limpia pantalla
}

void loop() {
  // put your main code here, to run repeatedly:
 float LM35Input=analogRead(A0);//Lectura del sensor LM35 en el pin analogo 0
 //Temperaturas TMP36
 float centigrados=LM35Input*0.488;//temperatura °C
 float faren=centigrados*1.8+32;//Temperatura °F
 lcd.clear();//Limpia pantalla
 lcd.setCursor(0,0);//Seleccionamos impresion arriba
 lcd.print("Temperatura: "); //Impresión
 lcd.setCursor(0,1);//Seleccionamos impresión abajo
 lcd.print(centigrados);//Se manda a imprimir temperatura
 lcd.print("C");//Imprime unidades en LCD
 lcd.print("  ");//Impresión de espacios
 lcd.print(faren);//Se imprime en LCD la variable farenheint
 lcd.print("F");//Imprime las unidades
 if(centigrados>37){//Condicional para encender y apagar led, si es mayor a 37
    digitalWrite(0,LOW);//Apaga led verde, paso bajo
    digitalWrite(1,HIGH);//Enciende led rojo, en paso alto
  }
  else{//caso contrario
    digitalWrite(1,LOW);//Enciende led verde, paso alto
    digitalWrite(0,HIGH);//Apaga led rojo, paso bajo
    }
  delay(1000);//retardo
}
