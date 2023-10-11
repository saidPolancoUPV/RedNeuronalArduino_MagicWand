#include <Arduino.h>
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

void get_metrics();

MPU6050 sensor;

// valores raw (sin procesar) del acelerómetro y giroscópio en los ejes x, y, z
int ax, ay, az;
int gx, gy, gz;

boolean sensor_ok;

void setup() {
    Serial.begin(9600);
    Wire.begin();
    sensor.initialize();

    if (sensor.testConnection()) sensor_ok = true;
    else sensor_ok = false;
}

void loop() {

    if (sensor_ok) {
        get_metrics();
    } else {
        Serial.println(-1);
    }

    delay(100);
}

void get_metrics() {
    // leer las aceleraciones y velocidades angulares
    sensor.getAcceleration(&ax, &ay, &az);
    sensor.getRotation(&gx, &gy, &gz);

    // mostrar las lecturas separadas por un [tab]
    Serial.print(ax); Serial.print("\t");
    Serial.print(ay); Serial.print("\t");
    Serial.print(az); Serial.print("\t");
    Serial.print(gx); Serial.print("\t");
    Serial.print(gy); Serial.print("\t");
    Serial.println(gz);
}
