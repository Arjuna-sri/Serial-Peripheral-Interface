#include <Wire.h>
#include <BH1750.h>

BH1750 lightMeter;

#define LED_PIN 13  

void setup(){
  Serial.begin(9600);

  Wire.begin();
  lightMeter.begin();

  pinMode(LED_PIN, OUTPUT);

  Serial.println(F("BH1750 Test begin"));
}

void loop() {
  float lux = lightMeter.readLightLevel();

  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx"); 

  if (lux < 100) {
    Serial.println("LED ON");
    digitalWrite(LED_PIN, HIGH); 
  } else {
    Serial.println("LED OFF");
    digitalWrite(LED_PIN, LOW);   
  }

  delay(1000);  // Delay for 1 second
}
