// menu.h

#ifndef _MENU_h
#define _MENU_h
#include <map>
#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class MenuClass
{
	std::map<float, String> selection_dictionary;
 public:
	void init();
};

extern MenuClass Menu;

#endif

