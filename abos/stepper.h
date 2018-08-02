/*#ifndef STEPPER_H
#define STEPPER_H
#include <Stepper.h>
class Engine;
extern Engine engine;

class Engine{
  private:
    const int stepsPerRevolution = 3200;
    Stepper zStepper = Stepper(stepsPerRevolution, 3, 2);
  public:
    void moveZStep(int iNum);
};



#endif //STEPPER_H*/
