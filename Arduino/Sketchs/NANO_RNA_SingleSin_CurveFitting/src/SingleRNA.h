//
// Created by said on 29/09/23.
//

#ifndef NANO_RNA_SINGLESIN_CURVEFITTING_SINGLERNA_H
#define NANO_RNA_SINGLESIN_CURVEFITTING_SINGLERNA_H


class SingleRNA {
    private:
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
        float M4[1][2] = {
                {1.3534938, -1.4600034}
        };  // capa 4 - 1 neurona

        float Bias1[1] = {0.4221617};
        float Bias2[3] = {0.44382837, 0.41102475, 0.17832378};
        float Bias3[2] = {0.11961418, -0.1008855};
        float Bias4[1] = {0.11395541};

        float linear(float);
        float relu(float);
        float dot(float*, float*, unsigned char);
        float z_fun(float*, float*, unsigned char, float);
    public:
        SingleRNA();

        float forward(float);


};


#endif //NANO_RNA_SINGLESIN_CURVEFITTING_SINGLERNA_H
