#include <iostream>
#include <math.h>
#include "util/vector.hpp"
#include "layer/linear.hpp"
using namespace std;

int main()
{
    LinearLayer linearLayer(4, 5);
    NVector input(5, 1);
    NVector output = linearLayer.forward(input);
}
