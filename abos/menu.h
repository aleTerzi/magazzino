// menu.h

#ifndef _MENU_h
#define _MENU_h

/* LIBRARIES */
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

	//Creation of dictionary
	void inizializeDictionary();

	//Return first position of dictionary.
	double returnEndOfDictionary();

	//Return last position of dictionary.
	double returnBeginOfDictionary();

	/* MENU CONFIGURATION */

	//Default values that must interact with other classes.
	const int OUTPUT_WITH_ACTION[14] = {
		10, 11, 20,
		30, 310, 311,
		312, 320, 321,
		322, 330, 331,
		332, 4,
	};

	//Position of arrow.
	int menu_arrow_start = 0;

	//Offset of arrow.
	int menu_arrow_offset = 0;

	//Decide if print menu.
	bool menu_set = true;

	//Where to start print the menu.
	int menu_position = 1;

	//Selected value (OUTPUT_WITH_ACTION) to make an interaction with other class.
	int output_selection = -1;

	//Enable the interaction (of "output_selection") with other class.
	bool menu_search = false;

	/* MENU FUNCTIONS */

	//Arrow's initialization.
	void menuSet();

	//Print welcome text before start using menu.
	void menuWelcomeText();

	//Arrow's movement
	int menuArrowPosition();

	//Move arrow to sub-branch.
	void menuGoToSon();

	//Move arrow to a parent branch.
	void menuGoToParent();

	//Move arrow to main branch.
	void menuGoToHome();

	//Find if there is a valid output and return it, else return -1.
	void outputSelection();

public:

	//Init class.
	void init();

	//Menu navigation.
	void menu();

	//Return "menu_position" outside the class.
	int outputMenu();

	//Return "menu_position" outside the class and (waiting) text is printed on L.C.D.
	int outputMenuWithText();

	//Reset "menu_position" to -1.
	void clearOutputSelection();

	//Is "menuGoToParent()" but public.
	void setMenuToHome();

	//Is "menuGoToParent()" but public.
	void setMenuToParent();

	//Return "menu_search".
	bool statusMenu();
};

extern MenuClass Menu;

#endif
