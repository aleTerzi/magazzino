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
	std::map<double, String> selection_dictionary;
	void inizializeDictionary();	
	double returnEndOfDictionary();
	double returnBeginOfDictionary();

	//Menu configuration.
	double increase_position_to = 0.1;
	const double MENU_START = 1;
	double MENU_MAX_END;
	double menu_start_to;
	double menu_end_to;
	
	//Menu functions.
	double increasePositionTo(const double my_num);
	
public:
	void init();

	void menu();
};

extern MenuClass Menu;

#endif

