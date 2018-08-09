// matrix.h

#ifndef _MATRIX_h
#define _MATRIX_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class MatrixClass
{
 protected:


 public:
	void init();
};

extern MatrixClass Matrix;

#endif

