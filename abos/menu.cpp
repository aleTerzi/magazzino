// 
// 
// 

#include "menu.h"

/* PUBLIC */
void MenuClass::init()
{
	inizializeDictionary();
}

void MenuClass::menu()
{	
	if(!menu_set)
	{
		menuArrowPosition();
		return;
	}
	int button_input = menuArrowPosition();

}


/* PRIVATE */
void MenuClass::inizializeDictionary()
{
	/* Errors set */
	//selection_dictionary[-1.1] = "ERRORE SCONOSCUTO!";
	//selection_dictionary[-1.0] = "ERRORE:";
	
	/* Command sets */
	selection_dictionary[0.0] = "Premi un tasto per iniziare!";
	selection_dictionary[0.1] = "ATTENDI";

	/* Add item */
	selection_dictionary[1] = "Aggiungi un oggetto.";
	selection_dictionary[10] = "Primo spazio libero.";
	selection_dictionary[11] = "Spazio a scelta.";

	/* Remove item */
	selection_dictionary[2] = "Riumuovi un oggetto.";
	selection_dictionary[20] = "Selezione l'oggetto.";

	/* Move axis */
	selection_dictionary[3] = "Muovi.";
	selection_dictionary[30] = "Auto Home";
	// - X
	selection_dictionary[31] = "Muovi asse X.";
	selection_dictionary[310] = "di 10 cm.";
	selection_dictionary[311] = "di 1 cm.";
	selection_dictionary[312] = "di 0.1 cm.";
	// - Y
	selection_dictionary[32] = "Move asse Y.";
	selection_dictionary[320] = "di 10 cm.";
	selection_dictionary[321] = "di 1 cm.";
	selection_dictionary[323] = "di 0.1 cm.";
	// - Z
	selection_dictionary[33] = "Move asse Z.";
	selection_dictionary[330] = "di 10 cm.";
	selection_dictionary[331] = "di 1 cm.";
	selection_dictionary[332] = "di 0.1 cm.";
}

double MenuClass::increasePositionTo(const double my_num)
{
	//return my_num + increase_position_to;
}

double MenuClass::returnEndOfDictionary()
{
	std::map<unsigned int, String>::reverse_iterator my_iterator = selection_dictionary.rbegin();
	return my_iterator->first;
}

double MenuClass::returnBeginOfDictionary()
{
	std::map<unsigned int, String>::iterator my_iterator = selection_dictionary.begin();
	return my_iterator->first;
}

void MenuClass::menuSet()
{
	if(menu_set)
	{
		menu_set = false;
		LCD.setReset();
		LCD.printScreen(0, 0, ">");
	}
}

int MenuClass::menuArrowPosition()
{
	menuWelcomeText();
	int button_input = LCD.readButtonValue();
	if (button_input == LCD.NULL_BUTTON)
		return LCD.NULL_BUTTON;
	if (button_input == LCD.BOTTOM_BUTTON && menu_arrow_start < LCD.LCD_HEIGHT - 1 /* - offset */)
	{
		menu_arrow_start++;
	}
	else if (button_input == LCD.TOP_BUTTON && menu_arrow_start > 0)
	{
		menu_arrow_start--;
	}
	Serial.println(menu_arrow_start);
	LCD.setReset();
	LCD.printScreen(0, menu_arrow_start, ">");
	LCD.setCursor(0, 0);
	return button_input;
}

void MenuClass::menuWelcomeText()
{
	if(!menu_set)
		return;
	LCD.setReset();
	LCD.printScreen(1, 1, "Premi un tasto");
	LCD.printScreen(6, 2, "per iniziare!");
	if(LCD.readButtonValue() != LCD.NULL_BUTTON)
		menuSet();
}

MenuClass Menu;

