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
    Weight exampleCat(10.0f, Weight::KILO, 20.0f);
    exampleCat.dump();
    Weight empty;
    empty.dump();
#ifdef debug
    exampleCat.setWeight(29, Weight::KILO); //should FAIL
#endif
    exampleCat.convertWeight(exampleCat.weight, Weight::KILO, Weight::POUND);
    exampleCat.dump();

    Weight myWeight( 3.14f, Weight::KILO, 20.0f );
    myWeight.dump();

    cout << boolalpha << "Is myWeight.weight greater than exampleCat.weight? \t" << myWeight.operator<(exampleCat) << endl;
    return 0;
}
//