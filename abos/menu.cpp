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
	selection_dictionary[-1.1] = "ERRORE SCONOSCUTO!";
	selection_dictionary[-1.0] = "ERRORE:";
	
	/* Command sets */
	selection_dictionary[0.0] = "Premi un tasto per iniziare!";
	selection_dictionary[0.0] = "ATTENDI";

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
	//return my_num + increase_position_to;
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

