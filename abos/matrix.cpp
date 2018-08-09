// 
// 
// 

#include "matrix.h"
void MatrixClass::init()
{
	setUpVector();
	printVector();
}

bool MatrixClass::useMatrix()
{
	if(Menu.statusMenu())
	{
		Stepper.engineOn();
		const int go_here = Menu.outputMenu();
		if (go_here == 10)
		{
			Menu.outputMenuWithText();
			addAtFirst();
			return true;
		}
		if (go_here == 11)
		{
			Serial.println("2");
			return true;
		}
		if (go_here == 20)
		{
			Serial.println("3");
			return true;
		}
	}
	return false;
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

bool MatrixClass::sectorIsFree(int x, int y)
{
	if (matrix[x][y] == false)
		return true;
	return false;
}

void MatrixClass::addAtFirst()
{
	int x = -1;
	int y = -1;
	for (auto a = 0; a < N_BOX_FOR_LINE; a++)
	{
		for (auto b = 0; b < N_BOX_FOR_COLUMN; b++)
		{
			if(sectorIsFree(b, a))
			{
				x = b;
				y = a;
				break;
			}
		}
		if (x != -1)
			break;
	}
	if(x == -1)
		return;
	virtualToFisic(y, x);
	goToPosition();
	matrix[x][y] = true;
}

void MatrixClass::virtualToFisic(int z, int y)
{
	z_coordinate = z * LINES + z * BOX_HEIGHT;
	x_coordinate = y * COLUMNS + y * BOX_WIDTH * 2;
	Serial.println(z_coordinate);
	Serial.println(x_coordinate);
}

void MatrixClass::goToPosition()
{
	Stepper.autoHome();
	delay(100);
	Stepper.moveZ(z_coordinate);
	delay(100);
	Stepper.moveX(x_coordinate);
	delay(100);
	Stepper.moveY(5); //<-- PUT HERE TRUE SPACE.
	delay(100);
	Stepper.moveZ(2);
	delay(100);
	Stepper.moveY(-5); //<-- PUT HERE TRUE SPACE.
	delay(100);
	Stepper.autoHome();
	z_coordinate = -1;
	x_coordinate = -1;
	printVector();
}




MatrixClass Matrix;

