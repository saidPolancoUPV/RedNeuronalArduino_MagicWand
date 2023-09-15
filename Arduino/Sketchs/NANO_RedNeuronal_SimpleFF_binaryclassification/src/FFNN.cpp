//
// Created by said on 15/09/23.
//

#include <HardwareSerial.h>
#include <math.h>
#include "FFNN.h"


FFNN::FFNN() {

}

float FFNN::dot(float *a, float *b) {
    float suma = 0;
    if (sizeof(a) != sizeof(b)) {
        Serial.println("Error: el tamaño de los vectores no coinciden");
        return -1;
    }

    for (int i=0; i < 2; i++) {
        suma += a[i] * b[i];
    }

    return suma;
}

float FFNN::relu(float z) {
    if (z > 0) return z;

    return 0;
}

float FFNN::sigmoid(float z) {
    return 1.0 / (1.0 + exp(-1 * z));
}

int FFNN::forward(float *x) {
    float output_l1[2];
    float output_l2;

    for(int i=0; i < 2; i++) {
        output_l1[i] = this->relu(this->dot(x, this->W1[i]));
    }

    output_l2 = this->sigmoid(this->dot(output_l1, this->W2[0]));

    if (output_l2 < 0.5) return 0;
    else return 1;
}
