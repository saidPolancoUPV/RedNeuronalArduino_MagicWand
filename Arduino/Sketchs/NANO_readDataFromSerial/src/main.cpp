#include <Arduino.h>
String a;
float x[2];

void setup() {
    Serial.begin(9600);
    Serial.println("Ready");
}

void loop() {
    while(Serial.available()) {
        int count = 0;
        do {
            a = Serial.readStringUntil(',');
            if (a != "") {
                x[count] = a.toFloat();
                count++;
            }
        } while(a != "");

        Serial.print(x[0]);
        Serial.print(",");
        Serial.println(x[1]);
    }
}
