class MyMatrix
{

  public:
    int Col;
    int Row;
    double **matrix;

    MyMatrix(int row, int col)
    {
        Col = col;
        Row = row;
        matrix = MatrixGen();
        MatrixInit(matrix, 1);
    }
    void MatrixInit(double **matrix, double value)
    {
        for (int i = 0; i < Row; i++)
        {
            for (int j = 0; j < Col; j++)
            {
                matrix[i][j] = value;
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
