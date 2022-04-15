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
    static float globalWeight; //remove later

private:
    bool weightIsKnown = false;
    UnitOfWeight unitOfWeight = POUND; //once set cant change (not initialization though)
    float weight = UNKNOWN_WEIGHT; //can change once set
    float maxWeight = UNKNOWN_WEIGHT; //cant change once set
    bool hasMaxWeight = false;


    //constructors (7)
    Weight() noexcept;
    explicit Weight(float newWeight);
    explicit Weight(UnitOfWeight newUnitOfWeight) noexcept;
    Weight(float newWeight, UnitOfWeight newUnitOfWeight);
    Weight(float newWeight, float newMaxWeight);
    Weight(UnitOfWeight newUnitOfWeight, float newMaxWeight);
    Weight(float newWeight, UnitOfWeight newUnitOfWeight, float newMaxUnitOfWeight);
    //getters and setters
public:
    float getMaxWeight() const;

private:
    //static methods
    static float fromKilogramToPound( float kilogram ) noexcept;
    static float fromSlugToPound( float slug ) noexcept;
    static float fromPoundToKilogram( float pound ) noexcept;
    static float fromPoundToSlug( float pound ) noexcept;
    static float convertWeight( float fromWeight
            ,UnitOfWeight fromUnit
            ,UnitOfWeight toUnit ) noexcept;
    //checks/other methods
    bool validate(float weightToValidate) const noexcept;
    bool isWeightValid(float checkWeight) const;
    //dont really need any fuctions checking for if we have values
    //as we already have bools that do that, adding a function
    //seems a bit redundant


};

