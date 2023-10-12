#include <Arduino.h>
#include "Wire.h"
#include "MPU6050.h"

void get_metrics();

MPU6050 sensor;

// valores raw (sin procesar) del acelerómetro y giroscópio en los ejes x, y, z
double ax=0, ay=0, az=0;
int gx=0, gy=0, gz=0;

boolean sensor_ok;

void setup() {
    Serial.begin(9600);

    while (! sensor.begin(MPU6050_SCALE_250DPS, MPU6050_RANGE_2G)) {
        delay(500);
    }
    sensor_ok = true;
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
    Vector normAccel = sensor.readNormalizeAccel();
    Vector normGyro = sensor.readNormalizeGyro();

    // mostrar las lecturas separadas por un [tab]
    Serial.print(normAccel.XAxis); Serial.print("\t");
    Serial.print(normAccel.YAxis); Serial.print("\t");
    Serial.print(normAccel.ZAxis); Serial.print("\t");
    Serial.print(normGyro.XAxis); Serial.print("\t");
    Serial.print(normGyro.YAxis); Serial.print("\t");
    Serial.println(normGyro.ZAxis);
}
