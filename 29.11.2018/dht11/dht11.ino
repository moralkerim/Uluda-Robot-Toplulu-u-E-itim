#include <DHT.h>
#include <DHT_U.h>

DHT dht11(3,DHT11);

void setup() {
  // put your setup code here, to run once:
dht11.begin();
pinMode(3,INPUT);
Serial.begin(9600);
}

void loop() {
  float t=dht11.readTemperature();
  float nem=dht11.readHumidity();
  Serial.print("Sıcaklık:");
  Serial.print(t);
  Serial.print("||");
  Serial.print("Nem:");
  Serial.println(nem);
  delay(1000);

}
