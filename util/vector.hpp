#include <iostream>
#include <random>

double sigmoid(double z);
double sigmoid_prime(double z);
class NVector;
NVector MatrixMulti(NVector matrix1, NVector matrix2);
NVector elementWise(NVector input, double afunc(double));
NVector elementWiseMulti(NVector input1, NVector input2);
NVector elementWiseMinus(NVector input1, NVector input2);
NVector elementWiseScalar(NVector input1, double scalar);
NVector elementWisePlusExpand(NVector input1, NVector input2);
NVector MatrixTranspose(NVector input1);
double Loss(NVector loss);
NVector toVector(int data_y);
double NormalRandom();

#ifndef NVectorC
#define NVectorC

using namespace std;

class NVector
{

  public:
    int Col;
    int Row;
    vector<vector<double>> matrix;
    NVector();
    NVector(int row, int col)
    {
        Col = col;
        Row = row;
        matrix.resize(Row);
        for (int i = 0; i < Row; ++i)
            matrix[i].resize(Col);
        MatrixInit();
    }
    void MatrixInit()
    {
        random_device rd{};
        mt19937 gen{rd()};
        normal_distribution<> d{0, 0.1};

        for (int i = 0; i < Row; i++)
        {
            for (int j = 0; j < Col; j++)
            {
                matrix[i][j] = d(gen);
            }
        }
    }
    // double **MatrixGen()
    // {
    //     double **a = new double *[Row];
    //     for (int i = 0; i < Row; ++i)
    //     {
    //         a[i] = new double[Col];
    //     }

    //     return a;
    // }

    void AssignValue(vector<vector<double>> vector)
    {
        int vrow = vector.size();
        int ncol = vector[0].size();
        assert(vrow == Row);
        assert(ncol == Col);

        for (int i = 0; i < Row; i++)
        {
            for (int j = 0; j < Col; j++)
            {
                matrix[i][j] = vector[i][j];
            }
        }
    }
};

#endif
