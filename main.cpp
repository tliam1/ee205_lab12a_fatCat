///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author Liam Tapper <tliam@hawaii.edu>
/// @date   12_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Weight.h"

//#define debug

int main() {
    std::cout << "Hello, World!" << std::endl;
    Weight exampleCat;
    exampleCat = Weight(10.0f, Weight::KILO, 50.0f);
    cout << "CatWeight is: " << exampleCat.getWeight() << " " << exampleCat.getWeightUnit() << endl;
#ifdef debug
    exampleCat.setWeight(29, Weight::KILO); //should FAIL
#endif
    exampleCat.convertWeight(exampleCat.weight, Weight::KILO, Weight::POUND);
    cout << "CatWeight is: " << exampleCat.getWeight() << " " << exampleCat.getWeightUnit() << endl;
    return 0;
}
