//
// Created by said on 29/09/23.
//
#include <Arduino.h>
#include "SingleRNA.h"

SingleRNA s = SingleRNA();

float in = 0.00f;

void setup() {
    Serial.begin(9600);
}

void loop() {

    Serial.println(s.forward(in), 8);

    in += 0.01;

    if (in > 3.1416) {
        in = 0.00f;
    }

    delay(10);
}
