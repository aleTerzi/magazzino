// menu.h

#ifndef _MENU_h
#define _MENU_h
#include <map>
#include "LCD.h"
#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class MenuClass
{
	/* AGGIUNGERE NELLA DOCUMENTAZIONE DI INSERIRE STL PER ARDUINO*/
	//Dictionary for search in the menu.
	std::map<unsigned int, String> selection_dictionary;
	void inizializeDictionary();	
	double returnEndOfDictionary();
	double returnBeginOfDictionary();

	//Menu configuration.
	const int OUTPUT_WITH_ACTION[14] = {
		10, 11, 20, 
		30, 310, 311, 
		312, 320, 321, 
		322, 330, 331,
		332, 4
	};
	int menu_arrow_start = 0;
	int menu_arrow_offset = 0;
	bool menu_set = true;
	int menu_position = 1;
	int output_selection = -1;
	bool menu_search = false;
	/* MENU FUNCTIONS */

	//Arrow's initialization.
	void menuSet();

	void menuWelcomeText();

	//Arrow's movement
	int menuArrowPosition();
	void menuGoToSon();
	void menuGoToParent();
	void menuGoToHome();

	//Find if there is a valid output and return it else return -1.
	void outputSelection();

public:
	void init();

	void menu();

	int outputMenu();
	int outputMenuWithText();
	void clearOutputSelection();

	//Arrow's movement
	void setMenuToHome();
	void setMenuToParent();
	bool statusMenu();
};

extern MenuClass Menu;

#endif

