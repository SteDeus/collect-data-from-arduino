#include <dht_nonblocking.h>

#define DHT_SENSOR_TYPE DHT_TYPE_11
#define DHT_SENSOR_PIN 8

DHT_nonblocking dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

void setup() {
  Serial.begin(9600);
}

void loop() {
  float temperature;
  float humidity;

  if (dht_sensor.measure(&temperature, &humidity)) {
    Serial.print("T = ");
    Serial.print(temperature, 1);
    Serial.print(" deg. C, H = ");
    Serial.print(humidity, 1);
    Serial.println("%");

    // Invia i dati al PC tramite la comunicazione seriale
    Serial.print("DATA,");
    Serial.print(temperature, 1);
    Serial.print(",");
    Serial.print(humidity, 1);
    Serial.println();

    delay(5000); // Attendi 5 secondi prima di inviare nuovi dati
  }
}
