//
// Created by said on 15/09/23.
//

#ifndef NANO_REDNEURONAL_SIMPLEFF_BINARYCLASSIFICATION_FFNN_H
#define NANO_REDNEURONAL_SIMPLEFF_BINARYCLASSIFICATION_FFNN_H


class FFNN {
    private:
        float W1[2][2] = {
                {-1.3566418,  0.8290571},
                {0.5052472,  1.1291589}
        };
        float W2[1][2] = {
                {0.5337429, -1.0138276}
        };
        float sigmoid(float);
        float relu(float);
        float dot(float[], float[]);
    public:
        int forward(float[]);
        FFNN();

};


#endif //NANO_REDNEURONAL_SIMPLEFF_BINARYCLASSIFICATION_FFNN_H
