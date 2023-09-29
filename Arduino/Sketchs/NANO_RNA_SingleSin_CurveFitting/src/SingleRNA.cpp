//
// Created by said on 29/09/23.
//

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

float SingleRNA::dot(float *a, float *b) {
    return 0;
}

float SingleRNA::z_fun(float *x, float *w, float b) {
    return this->dot(x, w) + b;
}


