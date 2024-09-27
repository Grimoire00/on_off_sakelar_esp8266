#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

Servo servo;

char auth[] = "i1sCURNZe1q-MV3RPDuRUqO8M22_fRLH"; //  your auth code 
char ssid[] = "DFD_Sby";  // ssid name 
char pass[] = "D3lta12345"; // ssid password 


void setup()
{
  Serial.begin(9600);
  servo.attach(D4);
  Blynk.begin(auth, ssid, pass);
 }
 void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V0)
{
int value = param.asInt();  // Membaca nilai dari Blynk (0 atau 1)

  if (value == 0) {
    servo.write(30);  // Jika nilai 0, servo ke 45 derajat
    Serial.println("Servo diatur ke 45 derajat");
  } else {
    servo.write(140);  // Jika nilai 1, servo ke 90 derajat
    Serial.println("Servo diatur ke 90 derajat");
  }
}
