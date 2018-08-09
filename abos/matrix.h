// matrix.h

#ifndef _MATRIX_h
#define _MATRIX_h
#include "menu.h"
#include "stepper.h"
#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class MatrixClass
{
	/* REAL SIZE OF MATRIC (cm) */
	const float DEFAULT_HEIGHT = 96;
	const float DEFAULT_WIDTH = 96;
	const float OFFSET_TOP = 10;
	const float OFFSET_BOTTOM = 10;
	const float OFFSET_LEFT = 10;
	const float OFFSET_RIGHT = 10;
	//Usable matrix
	const float HEIGHT = DEFAULT_HEIGHT - OFFSET_LEFT - OFFSET_RIGHT;
	const float WIDTH = DEFAULT_WIDTH - OFFSET_TOP - OFFSET_BOTTOM;

	/* CELL */
	const int N_BOX_FOR_LINE = 7;
	const float BOX_WIDTH = 10;
	const float COLUMNS = 0.75;
	const int N_SPACE_COLUMNS = 11;

	const int N_BOX_FOR_COLUMN = 4;
	const float BOX_HEIGHT = 15;
	const float LINES = 4;
	const int N_SPACES_LINES = 4;
	
	/* VIRTUAL BOXS */	
	bool **matrix;
	void setUpVector();
	void printVector();
	bool sectorIsFree(int x, int y);
	void addAtFirst();

	/*FISIC BOX*/
	float z_coordinate = -1;
	float x_coordinate = -1;
	void virtualToFisic(int z, int y);
	void goToPosition();

 public:
	void init();
	bool useMatrix();
};

extern MatrixClass Matrix;

#endif

