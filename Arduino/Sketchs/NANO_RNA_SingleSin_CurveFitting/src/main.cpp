//
// Created by said on 29/09/23.
//
#include <Arduino.h>

float M1[1][1] = {{-0.5358084}}; // capa 1 - 1 neurona
float M2[3][1] = {
        {1.0464344},
        {0.31964287},
        {-0.20282179}
}; // capa 2 - 3 neurona

float M3[2][3] = { // capa 3 - 2 neuronas
        {-0.78796256, 1.5954595, 0.44938034},
        {1.4331942, -1.6701915, 1.1279454}
};

float dot(float *a, float *b) {
    Serial.println(a[0]);
    Serial.println(b[0]);
}

void setup() {
    Serial.begin(9600);
    dot(M1[0], M3[0]);
}

void loop() {

}
