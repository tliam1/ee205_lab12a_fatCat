///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 1.0
///
/// @author Liam Tapper <tliam@hawaii.edu>
/// @date   12_Apr_2022
///////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <cassert>
using namespace std;
class Weight {
//testing push

public:
    typedef enum { POUND, KILO, SLUG } UnitOfWeight ;
    static const float UNKNOWN_WEIGHT;
    static const float POUND_IN_A_KILO;
    static const float POUND_IN_A_SLUG;
    static const string POUND_LABEL;
    static const string KILO_LABEL;
    static const string SLUG_LABEL;
    UnitOfWeight unitOfWeight = POUND;
    static float globalWeight;
    float maxWeight;
private:



    //constructors

    //static methods
    static float fromKilogramToPound( float kilogram ) noexcept;
    static float fromSlugToPound( float slug ) noexcept;
    static float fromPoundToKilogram( float pound ) noexcept;
    static float fromPoundToSlug( float pound ) noexcept;
    static float convertWeight( float fromWeight
            ,UnitOfWeight fromUnit
            ,UnitOfWeight toUnit ) noexcept;
    bool validate() const noexcept;



};

