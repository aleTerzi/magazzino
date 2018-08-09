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
	if(menu_set)
	{
		menuArrowPosition();
		return;
	}
	menu_search = false;
	const auto button_input = menuArrowPosition();
	auto i = 0;
	auto menu_print = menu_position;
	while (selection_dictionary.find(menu_print) != selection_dictionary.end()  && i < LCD.LCD_HEIGHT)
	{
		//Serial.println(i);
		LCD.printScreenCut(2, i, 2, selection_dictionary[menu_print]);
		menu_print++;
		i++;
		//Serial.println(menu_print);
	}
	menu_arrow_offset = LCD.LCD_HEIGHT - i;
	if (button_input == LCD.RIGHT_BUTTON)
	{
		menuGoToSon();
		outputSelection();
	}		
	else if (button_input == LCD.LEFT_BUTTON)
		menuGoToParent();
	else if (button_input == LCD.CENTER_BUTTON)
		menuGoToHome();
	Serial.println(menu_position);
	if(button_input != LCD.NULL_BUTTON)
		LCD.setReset();
}

int MenuClass::outputMenu()
{
	return output_selection;
}

int MenuClass::outputMenuWithText()
{
	LCD.printScreenAndClear(6, 1, "ATTENDI!");
	return output_selection;
}

void MenuClass::clearOutputSelection()
{
	output_selection = -1;
}

void MenuClass::setMenuToHome()
{
	menuGoToHome();
}

void MenuClass::setMenuToParent()
{
	menuGoToParent();
}

bool MenuClass::statusMenu()
{
	return menu_search;
}



/* PRIVATE */
void MenuClass::inizializeDictionary()
{
	/* Errors set */
	//selection_dictionary[-1.1] = "ERRORE SCONOSCUTO!";
	//selection_dictionary[-1.0] = "ERRORE:";
	
	/* Command sets */
	//selection_dictionary[0.0] = "Premi un tasto per iniziare!";
	//selection_dictionary[0.1] = "ATTENDI";

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
	selection_dictionary[322] = "di 0.1 cm.";
	// - Z
	selection_dictionary[33] = "Move asse Z.";
	selection_dictionary[330] = "di 10 cm.";
	selection_dictionary[331] = "di 1 cm.";
	selection_dictionary[332] = "di 0.1 cm.";
	
	/* Engine Brake */
	selection_dictionary[4] = "Disattiva freno motore.";
}

double MenuClass::returnEndOfDictionary()
{
	//Puntatori a mappa/dizionario dalla fine.
	std::map<unsigned int, String>::reverse_iterator my_iterator = selection_dictionary.rbegin(); 
	return my_iterator->first;
}

double MenuClass::returnBeginOfDictionary()
{
	//Puntatori a mappa/dizionario dall'inizio.
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
	{
		//menu_set è falso quando si è entrati nel menu.
		if(!menu_set) 
		{
			LCD.printScreen(0, menu_arrow_start, ">");
			LCD.setCursor(0, 0);
		}
		return LCD.NULL_BUTTON;
	}
	
	//If to set the arrow only in the full display lines.
	if (button_input == LCD.BOTTOM_BUTTON && menu_arrow_start < LCD.LCD_HEIGHT - menu_arrow_offset - 1)
	{
		menu_arrow_start++;
	}
	else if (button_input == LCD.TOP_BUTTON && menu_arrow_start > 0)
	{
		menu_arrow_start--;
	}
	//Serial.println(menu_arrow_start);
	/*
	 if(button_input != LCD.NULL_BUTTON)
		LCD.setReset();
	*/
	LCD.printScreen(0, menu_arrow_start, ">");
	LCD.setCursor(0, 0);
	//Serial.print("Arrow: ");
	//Serial.println(menu_arrow_start);
	return button_input;
}

void MenuClass::menuWelcomeText()
{
	if(!menu_set)
		return;
	LCD.setReset();
	LCD.printScreen(1, 1, "Premi un tasto");
	LCD.printScreen(6, 2, "per iniziare!");
	delay(100);
	if(LCD.readButtonValue() != LCD.NULL_BUTTON)
		menuSet();
}

void MenuClass::menuGoToSon()
{
	if(selection_dictionary.find((menu_position + menu_arrow_start) * 10) == selection_dictionary.end())
	{
		menu_search = true;
		return;
	}		
	menu_position = (menu_position  + menu_arrow_start) * 10;
	menu_arrow_start = 0;
}

void MenuClass::menuGoToParent()
{
	if(float(menu_position / 10) <= 0)
		return;
	menu_position /= 10;
	
	if(menu_position > 10)
	{
		while (menu_position % 10 != 0)
			menu_position--;
	}else
	{
		menu_position = 1;
	}
	//Serial.print(menu_position);
	menu_arrow_start = 0;
	output_selection = -1;
}

void MenuClass::menuGoToHome()
{
	menu_position = 1;
	menu_arrow_start = 0;
	output_selection = -1;
}

void MenuClass::outputSelection()
{
	const int USE_ME = menu_position + menu_arrow_start;
	const int SIZE_OUTPUT_WITH_ACTION = (sizeof(OUTPUT_WITH_ACTION) / sizeof(*OUTPUT_WITH_ACTION));
	for (auto i = 0; i < SIZE_OUTPUT_WITH_ACTION; i++)
	{
		Serial.println(i);
		if (OUTPUT_WITH_ACTION[i] == USE_ME)
		{
			output_selection = USE_ME;
			return;
		}
	}
	output_selection = -1;
}

MenuClass Menu;

