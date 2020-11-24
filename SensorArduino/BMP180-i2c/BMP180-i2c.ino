#include <SFE_BMP180.h>
#include "DHT.h"
#include <SPI.h>//Libreria de OLED
#include <Wire.h>//Libreria de OLED
#include <Adafruit_GFX.h>//Libreria de OLED
#include <Adafruit_SSD1306.h>//Libreria de OLED
#include <Adafruit_BMP085.h>
#define OLED_RESET 4
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, OLED_RESET);
#define SSD1306_128_64

SFE_BMP180 pressure;
float temperature;
#define ALTITUDE 216.0 // Altitude in Sparta, Greece
#define DHTPIN 22     // what pin we're connected to
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  
  //dht.begin();
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);   //Indicamos el inicio del LCD
  display.clearDisplay();//Impresion primera fila
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.clearDisplay();
  Wire.begin();
  pressure.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

  display.clearDisplay();
  
  float humidity, pressure;
 humidity = dht.readHumidity()+10.0f;
 pressure = readPressureAndTemperature();
 
 delay(2000);
  
 char tempF[6]; 
 char humF[6];
 char pressF[7];
 
 dtostrf(temperature, 5, 1, tempF);
 dtostrf(humidity, 2, 0, humF);
 dtostrf(pressure, 7, 2, pressF);


  
  display.setCursor(0,5);
  display.print("P= ");
  display.print(tempF);
  display.print(" hPa");
  display.print(" T= ");
  display.print(tempF);
  //display.print((char)223);
  display.print(" C");
  display.print(" H= ");
  display.print(humF);
  display.print(" %");
  display.display();
  
  delay(500);
}
float readPressureAndTemperature()
{
  char status;
  double T,P,p0,a;

  status = pressure.startTemperature();
  if (status != 0)
  {
    delay(status);
    status = pressure.getTemperature(T);
    if (status != 0)
    { 
      temperature = T;
      status = pressure.startPressure(3);
      if (status != 0)
      {
        delay(status);
        status = pressure.getPressure(P,T);
        if (status != 0)
        {
          p0 = pressure.sealevel(P,ALTITUDE);       
          return p0;
        }
      }
    }
  }
}
