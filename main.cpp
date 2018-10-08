#include <iostream>
#include <math.h>
#include "util/vector.hpp"
#include "layer/linear.hpp"
#include "loader/mnist.hpp"
using namespace std;

int main()
{
    Mnist mnist;
    vector<vector<double>> train = mnist.readTrainingFile("./train-images-idx3-ubyte");
    vector<double> ydata = mnist.readLabelFile("./train-labels-idx1-ubyte");
    vector<vector<double>> normalizeddata = mnist.inputNormalization(train);
    int count = 0;
    double avgloss = 0;
    LinearLayer linearLayer(28 * 28, 100);
    LinearLayer linearLayer2(100, 10);
    for (int i = 0; i < 60000; i++)
    {
        count += 1;

        vector<double> input_x = normalizeddata[i];
        double input_y = ydata[i];
        NVector vector_y = toVector(input_y);

        NVector inputdata(1, 784);
        vector<vector<double>> images(1);
        images[0].resize(784);
        images[0] = input_x;

        inputdata.AssignValue(images);

        NVector output = linearLayer.forward(inputdata);
        NVector output2 = linearLayer2.forward(output);

        NVector cost = elementWiseMinus(output2, vector_y);
        avgloss += Loss(cost);
        if (count % 100 == 0)
        {
            cout << avgloss / 100 << endl;
            avgloss = 0;
        }

        NVector cost2 = linearLayer2.backward(cost);
        NVector cost3 = linearLayer.backward(cost2);

        linearLayer.update();
        linearLayer2.update();
    }
}
