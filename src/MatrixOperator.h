/*
 * MatrixOperator.h

*
*This class handles the matrix calculations according to the user inputs.
*/

#ifndef MATRIXOPERATOR_H_
#define MATRIXOPERATOR_H_
#include "Matrix.h"
#include "Logger.h"

class MatrixOperator {
private:
			Matrix nmat;
			bool dimCheck(const Matrix& mat1, const Matrix& mat2);
			bool dimMultCheck(const Matrix& mat1, const Matrix& mat2);
			bool isVector(const Matrix& mat);
			Matrix* produceMatrix();
			void output(const Matrix& mat);
			void start();

public:
	MatrixOperator();
	virtual ~MatrixOperator();
	string matrixToString(const Matrix& matrix);
};

#endif
