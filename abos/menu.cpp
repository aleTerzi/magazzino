// 
// 
// 

#include "menu.h"

/* PUBLIC */
void MenuClass::init()
{
	inizializeDictionary();
	menu_start_to = 3;
	menu_end_to = returnEndOfDictionary();
	MENU_MAX_END = returnEndOfDictionary();
}

void MenuClass::menu()
{	
	double position = menu_start_to;
	//int offset = 0;
	int counter = 0;
	bool scrool_text = true;
	LCD.setReset();
	LCD.printScreen(0, 0, ">");
	LCD.setCursor(2, 0);
	for(auto i = selection_dictionary.begin(); i != selection_dictionary.end(); ++i)
	{
		if(counter < LCD.LCD_HEIGHT && (position > MENU_START || position+1 == increasePositionTo(position)) && position < MENU_MAX_END)
		{	
			if (scrool_text)
			{
				LCD.autoScroolLeft(2, counter, 2, selection_dictionary[position]);
				scrool_text = false;
			}
			else {
				Serial.println(selection_dictionary[position]);
				LCD.printScreenCut(2, counter, 2, selection_dictionary[position]);
			}
			Serial.println(position);
			counter++;			
		}
		position = increasePositionTo(position);
	}
}


/* PRIVATE */
void MenuClass::inizializeDictionary()
{
	/* Errors set */
	selection_dictionary[-1.1] = "ERRORE SCONOSCUTO!";
	selection_dictionary[-1.0] = "ERRORE:";
	
	/* Command sets */
	selection_dictionary[0.0] = "Premi un tasto per iniziare!";
	selection_dictionary[0.1] = "ATTENDI";

	/* Add item */
	selection_dictionary[1.0] = "Aggiungi un oggetto.";
	selection_dictionary[1.1] = "Primo spazio libero.";
	selection_dictionary[1.2] = "Spazio a scelta.";

	/* Remove item */
	selection_dictionary[2.0] = "Riumuovi un oggetto.";
	selection_dictionary[2.1] = "Selezione l'oggetto.";

	/* Move axis */
	selection_dictionary[3.0] = "Muovi.";
	selection_dictionary[3.1] = "Auto Home";
	// - X
	selection_dictionary[3.20] = "Muovi asse X.";
	selection_dictionary[3.21] = "di 10 cm.";
	selection_dictionary[3.22] = "di 1 cm.";
	selection_dictionary[3.23] = "di 0.1 cm.";
	// - Y
	selection_dictionary[3.30] = "Move asse Y.";
	selection_dictionary[3.31] = "di 10 cm.";
	selection_dictionary[3.32] = "di 1 cm.";
	selection_dictionary[3.33] = "di 0.1 cm.";
	// - Z
	selection_dictionary[3.40] = "Move asse Z.";
	selection_dictionary[3.41] = "di 10 cm.";
	selection_dictionary[3.42] = "di 1 cm.";
	selection_dictionary[3.43] = "di 0.1 cm.";
}

double MenuClass::increasePositionTo(const double my_num)
{
	return my_num + increase_position_to;
}

double MenuClass::returnEndOfDictionary()
{
	std::map<double, String>::reverse_iterator my_iterator = selection_dictionary.rbegin();
	return my_iterator->first;
}

double MenuClass::returnBeginOfDictionary()
{
	std::map<double, String>::iterator my_iterator = selection_dictionary.begin();
	return my_iterator->first;
}



MenuClass Menu;

