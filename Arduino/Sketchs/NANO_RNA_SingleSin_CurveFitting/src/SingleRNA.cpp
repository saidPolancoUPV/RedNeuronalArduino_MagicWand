//
// Created by said on 29/09/23.
//

#include <HardwareSerial.h>
#include "SingleRNA.h"


float SingleRNA::linear(float z) {
    return z;
}

float SingleRNA::relu(float z) {
    if (z > 0) {
        return z;
    } else {
        return 0.0f;
    }
}

float SingleRNA::dot(float *a, float *b, unsigned char lsize) {
    float suma=0;

    for(unsigned char i=0; i < lsize; i++) {
        suma += a[i] * b[i];
    }

    return suma;
}

float SingleRNA::z_fun(float *x, float *w, unsigned char lsize, float b) {
    return this->dot(x, w, lsize) + b;
}

SingleRNA::SingleRNA() {
    ;
}

float SingleRNA::forward(float in) {
    float tmpIn[1][1] = {{-99.99E25}};
    float out1[1][1] = {{-99.99E25}};
    float out2[1][3] = { {-99.99E25, -99.99E25, -99.99E25}};
    float out3[1][2] = { {-99.99E25, -99.99E25}};
    float out4 = -99.99E25;

    tmpIn[0][0] = in;

    // primera capa
    out1[0][0] = this->linear(this->z_fun(tmpIn[0], this->M1[0], 1, this->Bias1[0]));
    // segunda capa
    for (unsigned char i=0; i < 3; i++) {
        out2[0][i] = this->relu(this->z_fun(out1[0], this->M2[i], 1, this->Bias2[i]));
    }
    // tercera capa
    for (unsigned char i=0; i < 2; i++) {
        out3[0][i] = this->relu(this->z_fun(out2[0], this->M3[i], 3, this->Bias3[i]));
    }

    // cuarta capa
    out4 = this->linear(this->z_fun(out3[0], this->M4[0], 2, this->Bias4[0]));

    return out4;
}


