# MERLIN
Source code for MERLIN
Function Docs -
(forklift.h):
to initialise the body, you must provide 2 arrays of 5 values, with the values in this order - 
0 - Control pin for the motor
1 - Direction pin of the motor
2 to 4 - The three microstepping pins, in any order
in addition, you must change the define statement for MaxLimit to the maximum limit of the forklift and the Up and Down defiitions to the directiosn the motors spin in practice