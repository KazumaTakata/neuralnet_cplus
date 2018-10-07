#include "MyMatrix.hpp"
#include <math.h>

void MatrixMulti(MyMatrix MatrixResult, MyMatrix matrix1, MyMatrix matrix2)
{
    int N = matrix1.Row;
    int M = matrix2.Col;
    int K = matrix2.Row;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            double result = 0;
            for (int k = 0; k < K; k++)
            {
                result += matrix1.matrix[i][k] * matrix2.matrix[k][j];
            }
            MatrixResult.matrix[i][j] = result;
        }
    }
}

MyMatrix elementWise(MyMatrix input)
{
    int N = input.Row;
    int M = input.Col;
    MyMatrix result(N, M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            result.matrix[i][j] = sigmoid(input.matrix[i][j]);
        }
    }
    return result;
}

double sigmoid(double z)
{
    return 1.0 / (1.0 + exp(-z));
}
