#include <Arduino.h>
#include "FFNN.h"

String strIn;
float x[2];

FFNN a = FFNN();

void setup() {
    Serial.begin(9600);
}

void loop() {
    while (Serial.available()) {
        int count = 0;
        do {
            strIn = Serial.readStringUntil(',');
            if (strIn != "") {
                x[count] = strIn.toFloat();
                count++;
            }
        } while( strIn != "");

        Serial.println(a.forward(x));
    }
}
