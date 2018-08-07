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
	int menu_arrow_start = 0;
	int menu_arrow_offset = 0;
	bool menu_set = true;
	int menu_position = 1;

	/* MENU FUNCTIONS */

	//Arrow's initialization.
	void menuSet();

	void menuWelcomeText();

	//Arrow's movement
	int menuArrowPosition();

	void menuGoToSon();
	void menuGoToParent();
	
public:
	void init();

	void menu();
};

extern MenuClass Menu;

#endif

