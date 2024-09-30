// Source code for Merlin's Forklift
// Copyright BRAINS 2024

// Import arduino.h
#include <arduino.h>

// Global Defines
#define MaxLimit
#define Up
#define Down

// Class Definition
class forkliftController
{
    public:
        void oneStepUp()
        {
            digitalWrite(directionControl1, Up);
            stepsTravelled++; 
            digitalWrite(motor1Control, 1);
            delay(5);
            digitalWrite(motor1Control, 0);
            delay(10);
        }
        void oneStepDown()
        {
            digitalWrite(directionControl1, Down); 
            stepsTravelled--;
            digitalWrite(motor1Control, 1);
            delay(5);
            digitalWrite(motor1Control, 0);
            delay(10);
        }
        void returnToHome()
        {
            if(stepsTravelled>0)
            {
                while (stepsTravelled!=0)
                {
                    oneStepDown();
                }
            }
        }
        void goToTop()
        {
            while (stepsTravelled<MaxLimit)
            {
                oneStepUp();
            }
        }
        forkliftController(int* mot1Arr, int* mot2arr)
        {
            // Initializes all the motor pins
            motor1Control = mot1Arr[0];
            directionControl1 = mot1Arr[1];
            motor2Control = mot2arr[0];
            directionControl2 = mot2arr[1];
            // Set the pins to zero
            digitalWrite(mot1Arr[2], 0);
            digitalWrite(mot1Arr[3], 0);
            digitalWrite(mot1Arr[4], 0);
            digitalWrite(mot2Arr[2], 0);
            digitalWrite(mot2Arr[3], 0);
            digitalWrite(mot2Arr[4], 0);
        }
    private:
        int stepsTravelled = 0;
        int motor1Control;
        int motor2Control;
        int directionControl1;
        int directionControl2;
};