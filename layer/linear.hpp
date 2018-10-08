#ifndef LinearC
#define LinearC

#include "../util/vector.hpp"

class LinearLayer;

class LinearLayer
{
  public:
    int inputDim;
    int outputDim;
    NVector Weight;
    NVector bias;
    NVector Input;
    NVector Z;
    NVector delta_b;
    NVector delta_W;
    LinearLayer(int idim, int odim) : Weight(idim, odim),
                                      bias(1, odim),
                                      Input(1, idim),
                                      Z(1, odim),
                                      delta_b(1, odim),
                                      delta_W(idim, odim)
    {
        inputDim = idim;
        outputDim = odim;
    }
    NVector forward(NVector input)
    {
        this->Input = input;
        NVector output = elementWisePlusExpand(MatrixMulti(input, this->Weight), this->bias);
        this->Z = output;
        NVector output2 = elementWise(output, sigmoid);
        return output2;
    }

    NVector backward(NVector input)
    {
        NVector sp = elementWise(this->Z, sigmoid_prime);
        NVector delta = elementWiseMulti(input, sp);
        this->delta_b = delta;
        this->delta_W = MatrixMulti(MatrixTranspose(this->Input), delta);

        NVector nextD = MatrixMulti(delta, MatrixTranspose(this->Weight));

        return nextD;
    }

    void update()
    {
        this->Weight = elementWiseMinus(this->Weight, elementWiseScalar(this->delta_W, 0.1));
        this->bias = elementWiseMinus(this->bias, elementWiseScalar(this->delta_b, 0.1));
    }
};

#endif