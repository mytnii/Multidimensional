#include<iostream>
using namespace std;

void deleteMatrix(int** matrix, int row);
void FillRandMatrix(int** matrix, int row, int column);
void printMatrix(int** matrix, int row, int column);
void insertColMatrix(int**& matrix, int row, int& column, int index);
void eraseColMatrix(int**& matrix, int row, int& column, int index);
void columnShiftRight(int**& matrix, int row, int column, int& index, int num);
void columnShiftLeft(int**& matrix, int row, int column, int& index, int num);
void rowShiftUp(int**& matrix, int row, int column, int& index, int num);
void rowShiftDown(int**&matrix, int row, int column, int& index, int num);
void shiftMatrix(int**& matrix, int row, int column, int& index, int num, int shift);

int main()
{
	srand(time(NULL));

	int row,
		index,
		column;

	cout << "Enter row: ";
	cin >> row;

	cout << "Enter column: ";
	cin >> column;

	cout << "Enter index: ";
	cin >> index;


	int** matrix = new int* [row];

	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[column];
	}

	FillRandMatrix(matrix, row, column);
	printMatrix(matrix, row, column);

	insertColMatrix(matrix, row, column, index);
	printMatrix(matrix, row, column);

	eraseColMatrix(matrix, row, column, index);
	printMatrix(matrix, row, column);

	int shift,
		index2,
		num;

	cout << "What to shift" << endl;
	cout << "1  - row" << endl;
	cout << "0 -  column" << endl;
	cout << endl;
	cin >> shift;
	cout << endl;
	cout << "Enter index" << endl;
	cout << endl;
	cin >> index2;
	cout << "Push once: ";
	cin >> num;

	shiftMatrix(matrix, row, column, index2, num, shift);

	deleteMatrix(matrix, row);

	return 0;
}


void deleteMatrix(int** matrix, int row)
{
	for (int i = 0; i < row; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

void FillRandMatrix(int** matrix, int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			matrix[i][j] = rand() % 20;
		}
	}
}

void printMatrix(int** matrix, int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void insertColMatrix(int**& matrix, int row, int& column, int index)
{
	int** matrix2 = new int*[row];

	for (int i = 0; i < row; i++)
	{
		matrix2[i] = new int[column + 1];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < index; j++)
		{
			matrix2[i][j] = matrix[i][j];
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = index + 1; j < column + 1; j++)
		{
			matrix2[i][j] = matrix[i][j - 1];
		}
	}

	deleteMatrix(matrix, row);

	for (int i = 0; i < row; i++)
	{
		matrix2[i][index] = i;
	}

	column++;

	matrix = matrix2;
}

void eraseColMatrix(int**& matrix, int row, int& column, int index)
{
	int** matrix2 = new int* [row];

	for (int i = 0; i < row; i++)
	{
		matrix2[i] = new int[column - 1];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < index; j++)
		{
			matrix2[i][j] = matrix[i][j];
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = index; j < column - 1; j++)
		{
			matrix2[i][j] = matrix[i][j + 1];
		}
	}

	deleteMatrix(matrix, row);

	column--;

	matrix = matrix2;
}

void columnShiftRight(int**& matrix, int row, int column, int& index, int num)
{

	for (int i = 0; i < num; i++)
	{

		int** matrix2 = new int* [row];

		for (int j = 0; j < row; j++)
		{
			matrix2[j] = new int[column];
		}

		for (int j = 0; j < row; j++)
		{
			for (int l = 0; l < index; l++)
			{
				matrix2[j][l] = matrix[j][l];
			}
		}

		for (int j = 0; j < row; j++)
		{
			for (int l = index + 2; l < column; l++)
			{
				matrix2[j][l] = matrix[j][l];
			}
		}

		for (int j = 0; j < row; j++)
		{
			matrix2[j][index] = matrix[j][index + 1];
			matrix2[j][index + 1] = matrix[j][index];
		}

		deleteMatrix(matrix, row);

		matrix = matrix2;

		printMatrix(matrix, row, column);

		index++;
	}
}

void columnShiftLeft(int**& matrix, int row, int column, int& index, int num)
{

	for (int i = 0; i < num; i++)
	{

		int** matrix2 = new int* [row];

		for (int j = 0; j < row; j++)
		{
			matrix2[j] = new int[column];
		}

		for (int j = 0; j < row; j++)
		{
			for (int l = 0; l < index - 1; l++)
			{
				matrix2[j][l] = matrix[j][l];
			}
		}

		for (int j = 0; j < row; j++)
		{
			for (int l = index + 1; l < column; l++)
			{
				matrix2[j][l] = matrix[j][l];
			}
		}

		for (int j = 0; j < row; j++)
		{
			matrix2[j][index - 1] = matrix[j][index];
			matrix2[j][index ] = matrix[j][index - 1];
		}

		deleteMatrix(matrix, row);

		matrix = matrix2;

		printMatrix(matrix, row, column);

		index--;
	}
}

void rowShiftUp(int**& matrix, int row, int column, int& index, int num)
{

	for (int i = 0; i < num; i++)
	{

		int** matrix2 = new int* [row];

		for (int j = 0; j < row; j++)
		{
			matrix2[j] = new int[column];
		}

		for (int j = 0; j < index - 1; j++)
		{
			for (int l = 0; l < column; l++)
			{
				matrix2[j][l] = matrix[j][l];
			}
		}

		for (int j = index + 1; j < row; j++)
		{
			for (int l = 0; l < column; l++)
			{
				matrix2[j][l] = matrix[j][l];
			}
		}

		for (int j = 0; j < row; j++)
		{
			matrix2[index - 1][j] = matrix[index][j];
			matrix2[index][j] = matrix[index - 1][j];
		}

		deleteMatrix(matrix, row);

		matrix = matrix2;

		printMatrix(matrix, row, column);

		index--;
	}
}

void rowShiftDown(int**& matrix, int row, int column, int& index, int num)
{

	for (int i = 0; i < num; i++)
	{

		int** matrix2 = new int* [row];

		for (int j = 0; j < row; j++)
		{
			matrix2[j] = new int[column];
		}

		for (int j = 0; j < index + 2; j++)
		{
			for (int l = 0; l < column; l++)
			{
				matrix2[j][l] = matrix[j][l];
			}
		}

		for (int j = index - 1; j < row; j++)
		{
			for (int l = 0; l < column; l++)
			{
				matrix2[j][l] = matrix[j][l];
			}
		}

		for (int j = 0; j < row; j++)
		{
			matrix2[index + 1][j] = matrix[index][j];
			matrix2[index][j] = matrix[index + 1][j];
		}

		deleteMatrix(matrix, row);

		matrix = matrix2;

		printMatrix(matrix, row, column);

		index++;
	}
}

void shiftMatrix(int**& matrix, int row, int column, int& index, int num, int shift)
{
	int direction;

	if (shift == 0)
	{

		cout << "Which way to shift?" << endl;
		cout << "0 - In the right" << endl;
		cout << "1 - In the left" << endl;
		cout << endl;
		cin >> direction;
		cout << endl;
		if (direction == 0)
		{
			printMatrix(matrix, row, column);
			columnShiftRight(matrix, row, column, index, num);
		}

		if (direction == 1)
		{
			printMatrix(matrix, row, column);
			columnShiftLeft(matrix, row, column, index, num);
		}

	}

	if (shift == 1)
	{
		cout << "Which way to shift?" << endl;
		cout << "0 - In the up" << endl;
		cout << "1 - In the down" << endl;
		cout << endl;
		cin >> direction;
		cout << endl;

		if (direction == 0)
		{
			printMatrix(matrix, row, column);
			rowShiftUp(matrix, row, column, index, num);
		}

		if (direction == 1)
		{
			printMatrix(matrix, row, column);
			rowShiftDown(matrix, row, column, index, num);
		}
	}
}
