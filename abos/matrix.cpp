// 
// 
// 

#include "matrix.h"

void MatrixClass::init()
{
	setUpVector();
	printVector();
}

/* PRIVATE */
void MatrixClass::setUpVector()
{
	matrix = new bool*[N_BOX_FOR_COLUMN];
	for (auto i = 0; i < N_BOX_FOR_COLUMN; i++)
		matrix[i] = new bool[N_BOX_FOR_LINE];
	for (auto y = 0; y < N_BOX_FOR_LINE; y++)
		for (auto x = 0; x < N_BOX_FOR_COLUMN; x++)
			matrix[x][y] = false;	
}

void MatrixClass::printVector()
{
	for (auto y = 0; y < N_BOX_FOR_LINE; y++)
	{
		for (auto x = 0; x < N_BOX_FOR_COLUMN; x++)
		{
			Serial.print(matrix[x][y]);
			Serial.print(" ");
		}
		Serial.println("");
	}		
}



MatrixClass Matrix;

