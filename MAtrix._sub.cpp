#include <iostream>

int **sub_matrix(int **mat1, int **mat2, int size)
{
	int **mat3 = new int *[size];
	for (int a = 0; a < size; a++)
	{
		mat3[a] = new int[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			mat3[i][j] = 0;
			for (int p = 0; p < size; p++)
			{
				mat3[i][j] += mat1[i][p] *mat2[p][j];
			}
		}
	}
	return mat3;

}
int **init_matrix(int size)
{
	int **mat1 = new int *[size];
	for (int a = 0; a < size; a++)
	{
		mat1[a] = new int[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			mat1[i][j] = rand() % 10 + 1;
		}
	}
	return mat1;

}

void print_matrix(int **matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Delet_matrix(int **matr1, int size)
{

	for (int i = 0; i < size; i++)
	{
		delete[] matr1[i];
	}
	delete[] matr1;

}

int main()
{
	int size = 2;
	int **mat1 = init_matrix(size);
	int **mat2 = init_matrix(size);
	int **mat3 = sub_matrix(mat1, mat2, size);
	
    print_matrix(mat1, size);
	std::cout << std::endl;
	print_matrix(mat2, size);
	std::cout << std::endl;
	print_matrix(mat3, size);

	Delet_matrix(mat1, size);
	Delet_matrix(mat2, size);
	Delet_matrix(mat3, size);

}

// more effectiv
/*
int **mul_matrix_el(int **first, int **second, int **third, int size)
{
    int i, j, k, b;
    for (i = 0; i < size; ++i)
    {
        for (k = 0; k < size; ++k)
        {
            b = first[i][k];
            for (j = 0; j < size; ++j)
            {
                third[i][j] += b * second[k][j];
            }
        }
    }
    return third;
}*/