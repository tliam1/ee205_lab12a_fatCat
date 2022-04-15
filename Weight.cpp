///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 1.0
///
/// @author Liam Tapper <tliam@hawaii.edu>
/// @date   12_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "Weight.h"
//initializing constants
const float Weight::UNKNOWN_WEIGHT = -1;
const float Weight::POUND_IN_A_KILO =  1.0f/2.20462f; //(kilo/lbs)
const float Weight::POUND_IN_A_SLUG = 1.0f/32.172f;//(slug/lbs)
float Weight::globalWeight = 0;
//initializing constants end

Weight::Weight() noexcept {
    weight = UNKNOWN_WEIGHT;
    //what is the default MAX WEIGHT??
}

Weight::Weight(float newWeight) {
    //@todo validation
    weight = newWeight;
    //what is the default MAX WEIGHT??
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight) noexcept {
    //@todo validation
    unitOfWeight = newUnitOfWeight;
    weight = UNKNOWN_WEIGHT;
    //what is the default MAX WEIGHT??
}

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight) {
    //@todo validation
    weight = newWeight;
    unitOfWeight = newUnitOfWeight;
    //what is the default MAX WEIGHT??
}

Weight::Weight(float newWeight, float newMaxWeight) {
    //@todo validation
    weight = newWeight;
    maxWeight = newMaxWeight;
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    //@todo validation
    weight = UNKNOWN_WEIGHT;
    maxWeight = newMaxWeight;
    unitOfWeight = newUnitOfWeight;
}

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    //@todo validation
    weight = newWeight;
    maxWeight = newMaxWeight;
    unitOfWeight = newUnitOfWeight;
}




float Weight::fromKilogramToPound(float kilogram) noexcept {
    globalWeight = kilogram / POUND_IN_A_KILO;
    return globalWeight; //pointless with a global. will need to change later
}

float Weight::fromSlugToPound(float slug) noexcept {
    globalWeight = slug / POUND_IN_A_SLUG;
    return globalWeight;
}

float Weight::fromPoundToKilogram(float pound) noexcept {
    globalWeight = pound * POUND_IN_A_KILO;
    return globalWeight;
}

float Weight::fromPoundToSlug(float pound) noexcept {
    globalWeight = pound * POUND_IN_A_SLUG;
    return globalWeight;
}

float Weight::convertWeight(float fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) noexcept {
    //we need to do validation first (weight > 0 and < max weight)
    switch (fromUnit) {
        case POUND:
            fromWeight = fromWeight; //no conversion (default is lbs)
            break;
        case KILO:
            fromKilogramToPound(fromWeight);
            break;
        case SLUG:
            fromSlugToPound(fromWeight);
            break;
        default:
            assert("ILLEGAL WEIGHT");
            break;
    }
    //pointless operations if they are the same
    if (fromUnit != toUnit) {
        switch (toUnit) {
            case POUND:
                fromWeight = fromWeight;
                break;
            case KILO:
                fromPoundToKilogram(fromWeight);
                break;
            case SLUG:
                fromPoundToSlug(fromWeight);
                break;
            default:
                assert("ILLEGAL WEIGHT");
                break;
        }
    }

    return globalWeight;
}

