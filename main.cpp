#include <iostream>
#include <math.h>
#include "util/MyMatrix.hpp"
using namespace std;

int main()
{
    MyMatrix mymatrix(3, 4);
    MyMatrix mymatrix2(4, 3);
    MyMatrix mymatrix3(3, 3);

    MatrixMulti(mymatrix3, mymatrix, mymatrix2);

    cout << mymatrix3.matrix[0][0];
}
