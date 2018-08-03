// 
// 
// 

#include "menu.h"

/* PUBLIC */
void MenuClass::init()
{
	inizializeDictionary();

}

/* PRIVATE */
void MenuClass::inizializeDictionary()
{
	/* Errors set */
	selection_dictionary[-1.1] = "ERRORE:";
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
	selection_dictionary[3.2] = "Muovi asse X.";
	selection_dictionary[3.21] = "di 10 cm.";
	selection_dictionary[3.22] = "di 1 cm.";
	selection_dictionary[3.23] = "di 0.1 cm.";
	// - Y
	selection_dictionary[3.3] = "Move asse Y.";
	selection_dictionary[3.31] = "di 10 cm.";
	selection_dictionary[3.32] = "di 1 cm.";
	selection_dictionary[3.33] = "di 0.1 cm.";
	// - Z
	selection_dictionary[3.4] = "Move asse Z.";
	selection_dictionary[3.41] = "di 10 cm.";
	selection_dictionary[3.42] = "di 1 cm.";
	selection_dictionary[3.43] = "di 0.1 cm.";
}

MenuClass Menu;

