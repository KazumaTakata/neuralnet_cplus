#include <iostream>
#include <random>

double sigmoid(double z);
double sigmoid_prime(double z);
class NVector;
NVector MatrixMulti(NVector matrix1, NVector matrix2);
NVector elementWise(NVector input, double afunc(double));
NVector elementWiseMulti(NVector input1, NVector input2);
NVector MatrixTranspose(NVector input1);
double NormalRandom();

#ifndef NVectorC
#define NVectorC

using namespace std;

class NVector
{

  public:
    int Col;
    int Row;
    double **matrix;
    NVector();
    NVector(int row, int col)
    {
        Col = col;
        Row = row;
        matrix = MatrixGen();
        MatrixInit(matrix);
    }
    void MatrixInit(double **matrix)
    {
        for (int i = 0; i < Row; i++)
        {
            for (int j = 0; j < Col; j++)
            {
                matrix[i][j] = NormalRandom();
            }
        }
    }
    double **MatrixGen()
    {
        double **a = new double *[Row];
        for (int i = 0; i < Row; ++i)
        {
            a[i] = new double[Col];
        }

        return a;
    }
};

#endif
