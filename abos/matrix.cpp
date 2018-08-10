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
			inputWithSelection();
			return true;
		}
		if (go_here == 20)
		{
			outputWithSelection();
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

bool MatrixClass::sectorIsTake(int x, int y)
{
	if (matrix[x][y] == true)
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

void MatrixClass::manualInterface(String my_text)
{
	float button_input = LCD.readButtonValue();
	z_coordinate = 0;
	x_coordinate = 0;
	LCD.setReset();
	LCD.printScreenAndClear(1, 2, my_text);
	LCD.printScreen(my_text.length() + 1, 0, "Ri");
	LCD.printScreen(my_text.length() + 4, 0, "Co");
	LCD.printScreen(my_text.length() + 1, 2, int(x_coordinate));
	LCD.printScreen(my_text.length() + 4, 2, int(z_coordinate));
	while (button_input != LCD.LEFT_BUTTON && button_input != LCD.CENTER_BUTTON)
	{
		if (button_input == LCD.TOP_BUTTON)
		{
			nextSlotFreeWithOffset(true);
			LCD.setReset();
			LCD.printScreenAndClear(1, 2, my_text);
			LCD.printScreen(my_text.length() + 1, 0, "Ri");
			LCD.printScreen(my_text.length() + 4, 0, "Co");
			LCD.printScreen(my_text.length() + 1, 2, int(x_coordinate));
			LCD.printScreen(my_text.length() + 4, 2, int(z_coordinate));
		}
		else if (button_input == LCD.BOTTOM_BUTTON)
		{
			nextSlotFreeWithOffset(false);
			LCD.setReset();
			LCD.printScreenAndClear(1, 2, my_text);
			LCD.printScreen(my_text.length() + 1, 0, "Ri");
			LCD.printScreen(my_text.length() + 4, 0, "Co");
			LCD.printScreen(my_text.length() + 1, 2, int(x_coordinate));
			LCD.printScreen(my_text.length() + 4, 2, int(z_coordinate));
		}
		else if (button_input == LCD.RIGHT_BUTTON && x_coordinate >= 0 && z_coordinate >= 0)
		{
			matrix[int(x_coordinate)][int(z_coordinate)] = free;
			virtualToFisic(z_coordinate, x_coordinate);
			goToPosition();
			LCD.setReset();
			Menu.setMenuToHome();
			return;
		}		
		button_input = LCD.readButtonValue();
	}
	LCD.setReset();
	if (button_input == LCD.CENTER_BUTTON)
		Menu.setMenuToHome();
	if (button_input == LCD.LEFT_BUTTON)
		Menu.setMenuToParent();
}

void MatrixClass::inputWithSelection()
{
	manualInterface("Inserisci: ");
}

void MatrixClass::outputWithSelection()
{
	manualInterface("Rimuovi: ");
}

void MatrixClass::nextSlotFreeWithOffset(bool direction)
{
	if(direction)
	{
		if (x_coordinate < N_BOX_FOR_COLUMN - 1)
			x_coordinate += 1;
		else if (z_coordinate < N_BOX_FOR_LINE - 1)
		{
			x_coordinate = 0;
			z_coordinate += 1;
		}
		else
		{
			x_coordinate = 0;
			z_coordinate = 0;
		}
	}
	else
	{
		if (x_coordinate > 0)
			x_coordinate -= 1;
		else if (z_coordinate > 0)
		{
			x_coordinate = N_BOX_FOR_COLUMN - 1;
			z_coordinate -= 1;
		}
	}
	
}

MatrixClass Matrix;

