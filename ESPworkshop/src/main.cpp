/*
Project: SensorPlatform4 - GreenHouse5
Github: https://github.com/44440-f23/greenhouse5
Team: Braeden, Luke, Daniel, Kevin

Main Device: firebeetle 2 esp32 e
Expansion Device: Gravity: IO Shield for FireBeetle 2 (ESP32-E/M0)
*/
#include <ArduinoJson.h>
#include <Arduino.h>
#include "moisture.h"
#include "humidityAndTemp.h"
#include "light.h"
#include "soilTemp.h"

#define BASE_STATION_ID 0
StaticJsonDocument<200> doc;

void setup() {
  Serial.begin(9600);
  doc["id"] = 5;

  // sensors is owned by temperature.h
  sensors.begin();
  // Wire is owned by humidity.h
  Wire.begin();
}

void loop() {    
  doc["soilM"] = getMoisture();
  doc["soilT"] = getSoilTemp();
  doc["temp"] = getTemp();
  doc["humidity"] = getHumidity();
  doc["lightS"] = getLight();
  serializeJsonPretty(doc, Serial);
  delay(2000);
}
