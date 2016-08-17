/*
 * Matrix.cpp
 *
 *  Created on: 08.08.2016
 *      Author: Mathias
 */

#include "Matrix.h"
#include <vector>
#include "math.h"

using namespace std;

Matrix::Matrix(){
	ROWS = COL = 0;
}

Matrix::Matrix(int rows, int columns) {
	ROWS = rows;
	COL = columns;
	generate(ROWS, COL);

}

Matrix::Matrix(vector<vector<double> > n_mat, int rows, int columns)
 {
	m_matrix = n_mat;
	ROWS = rows;
	COL = columns;
}

Matrix::~Matrix() {

}
/*
 * This method reads the user input and thus generates the matrix with a vector.
 */
void Matrix::generate(int rows, int columns)
{
	m_matrix.resize(columns, vector<double>(rows));
	double input;
	for(int i=1; i < rows+1; i++)
	{

		for(int j=1; j < columns+1; j++)
		{
		cout << "Please enter element: (" << i << "," << j << ")" << endl;
		cin >> input;
		//m_matrix.at(i).at(j) = input;
		m_matrix[i][j] = input;
		}
	}

}

/*
*Returns the element at position (i,j)
*/
double Matrix::getElement(int row, int column) const
{
	return m_matrix.at(row).at(column);
}

/*
*Overloaded operator +, to add two matrices directly.
*/

void Matrix::operator+=(const Matrix& matrix_2)
{
	//vector<vector<double> > n_mat(COL, vector<double>(ROWS,0));
	for(int i=1; i < ROWS+1; i++)
	{
		for(int j=1; j < COL+1; j++)
		{

		m_matrix.at(i).at(j) += matrix_2.getElement(i,j);
		}
	}
	//return Matrix(n_mat, ROWS, COL);

}

/*
*Overloaded operator -, to subtract two matrices directly.
*/

void Matrix::operator-=(const Matrix& matrix_2)
{
	//vector<vector<double> > n_mat(ROWS, vector<double>(COL));
	for(int i=1; i < ROWS+1; i++)
	{
		for(int j=1; j < COL+1; j++)
		{

		m_matrix.at(i).at(j) -= matrix_2.getElement(i,j);
		}
	}
	//return Matrix(n_mat, ROWS, COL);

}

/*
*Overloaded operator *, to multiply two matrices directly.
*/

Matrix* Matrix::operator*(const Matrix& matrix_2)
{
	vector<vector<double> > n_mat(ROWS, vector<double>(matrix_2.getCol()));
	for(int i=1; i < ROWS+1; i++)
	{
		int k = 1;
		while(k <= matrix_2.getCol())
		{
			double elementsum = 0;
			for(int j=1; j < COL+1; j++)
			{

			elementsum += getElement(i,j) * matrix_2.getElement(j,i+k-1);

			}
			(n_mat).at(i).at(k)=elementsum;
			++k;
		}
	}
	Matrix* matnew = new Matrix(n_mat, ROWS, matrix_2.getCol());
	return matnew;

}

/*
*Multiplication of a matrix with a scalar.
*/

void Matrix::scalarMult(double scalar)
{
	//vector<vector<double> > n_mat(ROWS, vector<double>(COL));
	for(int i=1; i < ROWS+1; i++)
	{
		for(int j=1; j < COL+1; j++)
		{

		m_matrix.at(i).at(j) *= scalar;
		}
	}
	//return Matrix(n_mat, ROWS, COL);
}

/*
*Returns the amount of rows the matrix consists of.
*/

int Matrix::getRows() const
{
	return ROWS;
}

/*
*Return the amount of columns the matrix consists of.
*/

int Matrix::getCol() const
{
	return COL;
}

/*
*Returns the magnitude, if the matrix is a vector in mathematical sense.
*/

double Matrix::getMagnitude()
{

	double sum = 0;
	for(int i=1; i < ROWS+1; i++)
	{
		for(int j=1; j < COL+1; j++)
		{

		sum += pow(getElement(i,j),2);
		}
	}
	return sqrt(sum);

}
