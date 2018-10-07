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
    NVector *Input;
    NVector *Z;
    NVector *delta_b;
    NVector *delta_W;
    LinearLayer(int idim, int odim) : Weight(idim, odim), Input()
    {
        inputDim = idim;
        outputDim = odim;
    }
    NVector forward(NVector input)
    {
        Input = &input;
        NVector output = MatrixMulti(Weight, input);
        Z = &output;
        NVector output2 = elementWise(output, sigmoid);

        return output2;
    }

    NVector backward(NVector input)
    {
        NVector sp = elementWise(*Z, sigmoid_prime);
        NVector delta = elementWiseMulti(input, sp);
        *delta_b = delta;
        *delta_W = MatrixMulti(delta, MatrixTranspose(*Input));

        NVector nextD = MatrixMulti(MatrixTranspose(Weight), delta);

        return nextD;
    }
};

#endif