#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>
#define kirmizi_led_pin 8
#define yesil_led_pin 9
#define motor_pin 3

char auth[] = "2bvomIkNZZvE4IREobYlF13pNxpyZmtr"; //blynk uygulamamizin anahtari

int nemPin = A0; //toprak nem sensorunun bilgi aldigi pin
int nem ; // alinan nem degerlerinin atandigi degisken

WidgetLED motor(V1); //sulama icin blynk uygulamasindaki bagli olan cikis pini
WidgetLED toprakNem(A0); //toprak nem sensoru icin blynk uygulamasindaki bagli olan giris pini


void setup()
{
  pinMode(nemPin, INPUT); /*topraktaki nem degerini okumak icin toprak nem sensoru giris olarak ayarlandi*/
  Serial.begin(9600);
  Blynk.begin(auth); //blynk uygulamasi baslatma
  pinMode(motor_pin, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(kirmizi_led_pin, OUTPUT);
  pinMode(yesil_led_pin, OUTPUT);

}

void loop()
{
  nem = analogRead(A0);
  Blynk.run();
  Serial.println(nem);
  
  if (nem >= 0 && nem <= 600) {
    digitalWrite(kirmizi_led_pin, LOW);
    digitalWrite(yesil_led_pin, HIGH);
    digitalWrite(motor_pin, LOW);
 
  }
  else if (nem >= 601 && nem <= 1023) {
    digitalWrite(yesil_led_pin, LOW);
    digitalWrite(kirmizi_led_pin, HIGH);
  }
  else {
    digitalWrite(yesil_led_pin, LOW);
    digitalWrite(kirmizi_led_pin, LOW);
  }

}
