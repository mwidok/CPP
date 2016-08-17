/*
 * MatrixOperator.cpp
 *
 *  Created on: 08.08.2016
 *      Author: Mathias
 */

#include "MatrixOperator.h"
#include <iostream>
#include "Matrix.h"
#include "Logger.h"
#include <string>
#include <sstream>

using namespace std;

MatrixOperator::MatrixOperator() {

	start();
}

MatrixOperator::~MatrixOperator() {


}

/*
*Check if the dimensions of the two matrices  correspond to each other in order to add or subtract them.
*/

bool MatrixOperator::dimCheck(const Matrix& mat1, const Matrix& mat2)
{
	return (mat1.getRows()==mat2.getRows() && mat1.getCol()==mat2.getCol());
}

/*
*Check if the dimensions concerning the columns of the first matrix and the rows of the second matrix equal, in order to being able to multiply the matrices.
*/

bool MatrixOperator::dimMultCheck(const Matrix& mat1, const Matrix& mat2)
{
	return (mat1.getCol()==mat2.getRows());
}

/*
*Check if the matrix is a vector - in mathematical sense.
*/

bool MatrixOperator::isVector(const Matrix& mat)
{
	return (mat.getRows()==1 || mat.getCol()==1);
}

/*
*This method starts the whole procedure of interaction with the user.
*/

void MatrixOperator::start()
{
	Logger* p_log = new Logger("matrix_log.txt");
	Matrix matrix1 = *(produceMatrix());

	cout << "Please enter the operation you would like to perform." << endl;
	cout << "Press 0 for matrix addition" << endl << "Press 1 for matrix subtraction" << endl << "Press 2 for scalar multiplication"
		<< endl << "Press 3 for matrix multiplication" << endl << "Press 4 for receiving a length of a vector" << endl;
	int number;
	Matrix nmat, matrix3;
	while(1)
	{
	cin >> number;
		switch (number)
		{
			case 0: cout << "Please type in the second matrix: " << endl;

				nmat = *(produceMatrix());
				while(!(dimCheck(matrix1, nmat)))
				{
				cout << "The dimensions of the matrices don't apply to the matrix addition rules! Try again submitting the second matrix: " << endl;
				nmat = *(produceMatrix());
				}
				matrix1 += nmat;
				output(matrix1);
				p_log->log(matrixToString(matrix1));
				break;

			case 1: cout << "Please type in the second matrix: " << endl;
				nmat = *(produceMatrix());
				while(!(dimCheck(matrix1, nmat)))
				{
				cout << "The dimensions of the matrices don't apply to the matrix subtraction rules! Try again submitting the second matrix: " << endl;
				nmat = *(produceMatrix());
				}
				matrix1 -= nmat;
				output(matrix1);
				p_log->log(matrixToString(matrix1));
				break;

			case 2: cout << "Please type in the scalar value: ";
				double scalar;
				cin >> scalar;
				matrix1.scalarMult(scalar);
				output(matrix1);
				p_log->log(matrixToString(matrix1));
				break;

			case 3: cout << "Please type in the second matrix: ";
				nmat = *(produceMatrix());
				while(!(dimMultCheck(matrix1, nmat)))
				{
				cout << "The dimensions of the matrices don't apply to the matrix multiplication rules! Try again submitting the second matrix: " << endl;
				nmat = *(produceMatrix());
				}
				matrix3 = *(matrix1 * nmat);
				output(matrix3);
				p_log->log(matrixToString(matrix3));
				break;

			case 4:
				while(!(isVector(matrix1)))
				{
				cout << "Your typed in structure is not a vector. Please do it again." << endl;
				matrix1 = *(produceMatrix());
				}
				cout << "The length of your vector is: " << matrix1.getMagnitude() << endl;
				output(matrix1);
				break;
		}
	}
	delete p_log;
}

/*
*Displays a matrix on the console.
*/

void MatrixOperator::output(const Matrix& mat)
{

	for(int i=1; i < mat.getRows()+1; i++)
	{
		for(int j=1; j < mat.getCol()+1; j++)
		{

		cout << mat.getElement(i,j) << "  ";
		}
		cout << endl;
	}


}

/*
*Receives the user input, constructs a matrix and logs it into a logfile.
*/

Matrix* MatrixOperator::produceMatrix()
{
	cout << "Please enter your matrix dimensions: " << endl;
	int rows, columns;
	cout << "Rows: " << endl;
	cin >> rows;
	cout << "Columns: " << endl;
	cin >> columns;
	Matrix* p_matrix = new Matrix(rows, columns);
	return p_matrix;

}

/*
*Converts a matrix into a well-formatted string for better display.
*/

string MatrixOperator::matrixToString(const Matrix& matrix){
	string mat = "{";
	ostringstream stream;
	for(int i=1; i < matrix.getRows()+1; i++)
	{
		mat += "(";
		for(int j=1; j < matrix.getCol()+1; j++)
		{
		stream << matrix.getElement(i,j);
		string valueStr(stream.str());
		mat += valueStr;
			if(j<=matrix.getCol()+1)
			{
				mat += ", ";
			}
		}
		mat += ")";
	}
	mat += "}";
	return mat;

}
