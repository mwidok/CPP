/*
 * Matrix.h

 *
 *  This class contains the matrix as a vector with the overloaded operators to compute matrices with each other directly.
 *
 */

#ifndef MATRIX_H_
#define MATRIX_H_
#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
		int ROWS;
		int COL;
		vector < vector<double> > m_matrix;
		void generate(int rows, int columns);
public:
		Matrix();
		Matrix(int rows, int columns);
		Matrix(vector<vector<double> > n_mat, int rows, int columns);
		void operator+=(const Matrix& matrix_2);
		void operator-=(const Matrix& matrix_2);
		Matrix* operator*(const Matrix& matrix_2);
		void scalarMult(double scalar);
		double getElement(int row, int column) const;
		double getMagnitude();
		int getRows() const;
		int getCol() const;
		virtual ~Matrix();
};

#endif
