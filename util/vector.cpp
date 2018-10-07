#include "vector.hpp"
#include <math.h>
#include <random>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>

using namespace std;

NVector MatrixMulti(NVector matrix1, NVector matrix2)
{
    int N = matrix1.Row;
    int M = matrix2.Col;
    int K = matrix2.Row;
    NVector MatrixResult(N, M);
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

    return MatrixResult;
}

NVector elementWise(NVector input, double afunc(double))
{
    int N = input.Row;
    int M = input.Col;
    NVector result(N, M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            result.matrix[i][j] = afunc(input.matrix[i][j]);
        }
    }
    return result;
}

NVector elementWiseMulti(NVector input1, NVector input2)
{
    int N = input1.Row;
    int M = input1.Col;
    NVector result(N, M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            result.matrix[i][j] = input1.matrix[i][j] * input2.matrix[i][j];
        }
    }
    return result;
}

NVector MatrixTranspose(NVector input1)
{
    int N = input1.Row;
    int M = input1.Col;
    NVector result(M, N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            result.matrix[j][i] = input1.matrix[i][j];
        }
    }
}

double NormalRandom()
{
    random_device rd{};
    mt19937 gen{rd()};
    normal_distribution<> d{0, 1};
    return d(gen);
}

double sigmoid(double z)
{
    return 1.0 / (1.0 + exp(-z));
}

double sigmoid_prime(double z)
{
    return sigmoid(z) * (1 - sigmoid(z));
}
