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

	//Menu configuration.
	double increase_position_to = 0.1;
	int menu_start_to = 3;
	int menu_end_to = 4;
	//Menu functions.
	double increasePositionTo(const double my_num);
	
public:
	void init();

	void menu();
};

extern MenuClass Menu;

#endif

