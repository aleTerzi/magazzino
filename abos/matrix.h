// matrix.h

#ifndef _MATRIX_h
#define _MATRIX_h

/* LIBRARIES */
#include "menu.h"
#include "stepper.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class MatrixClass
{
    /* REAL SIZE OF MATRIX (cm) */
    const float DEFAULT_HEIGHT = 96;
    const float DEFAULT_WIDTH = 96;
    const float OFFSET_TOP = 10;
    const float OFFSET_BOTTOM = 10;
    const float OFFSET_LEFT = 10;
    const float OFFSET_RIGHT = 10;

    // Usable matrix
    const float HEIGHT = DEFAULT_HEIGHT - OFFSET_LEFT - OFFSET_RIGHT;
    const float WIDTH = DEFAULT_WIDTH - OFFSET_TOP - OFFSET_BOTTOM;

    /* CELL WIDTH DATA */
    const int N_BOX_FOR_LINE = 7;
    const float BOX_WIDTH = 10;
    const float COLUMNS = 0.75;
    const int N_SPACE_COLUMNS = 11;

    /* CELL HEIGHT DATA */
    const int N_BOX_FOR_COLUMN = 4;
    const float BOX_HEIGHT = 15;
    const float LINES = 4;
    const int N_SPACES_LINES = 4;

    /* VIRTUAL BOXS */

    //Virtual matrix
    bool** matrix;

    //Load matrix
    void setUpVector();

    //Print Matrix.
    void printVector();

    /*
       Check if a position in the matrix is​empty and return a value.
       TRUE --> is empty.
       FALSE --> is full.
    */
    bool sectorIsFree(int x, int y);

    /*
       Check if a position in the matrix is ​​full and return a value.
       TRUE --> is full.
       FALSE --> is empty;
    */
    bool sectorIsTake(int x, int y);

    //Put the load in the first free sector.
    void addAtFirst();

    //Find the next free or full space after a given offset.
    void nextSlotFreeWithOffset(bool direction);

    /* FISIC BOX */

    //Selected coordinate for a virtual or a physical slot.
    float z_coordinate = -1;
    float x_coordinate = -1;

    //Convert virtual coordinate to a physical to position.
    void virtualToFisic(int z, int y);

    //Move steppers to a physical position.
    void goToPosition();

    //Take a position given manual.
    void manualInterface(String my_text);

    //Add item to warehouse with a custom position.
    void inputWithSelection();

    //Remove a warehouse item.
    void outputWithSelection();

  public:
    //Init class.
    void init();

    //Interaction with class.
    bool useMatrix();
};

extern MatrixClass Matrix;

#endif
