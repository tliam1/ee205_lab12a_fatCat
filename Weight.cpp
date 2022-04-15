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
const string Weight::POUND_LABEL = "Pound";
const string Weight::KILO_LABEL = "Kilo";
const string Weight::SLUG_LABEL = "Slug";
float Weight::globalWeight = 0;
float Weight::weight = UNKNOWN_WEIGHT;
//initializing constants end

Weight::Weight() noexcept {
    weight = UNKNOWN_WEIGHT;
    //what is the default MAX WEIGHT??
    maxWeight = UNKNOWN_WEIGHT;
}

Weight::Weight(float newWeight) {
    //@todo validation
    assert(isWeightValid(newWeight));
    weight = newWeight;
    weightIsKnown = true;
    maxWeight = UNKNOWN_WEIGHT;
    //what is the default MAX WEIGHT??
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight) noexcept {
    //@todo validation
    unitOfWeight = newUnitOfWeight;
    weight = UNKNOWN_WEIGHT;
    //what is the default MAX WEIGHT??
    maxWeight = UNKNOWN_WEIGHT;
}

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight) {
    //@todo validation
    assert(isWeightValid(newWeight));
    weight = newWeight;
    weightIsKnown = true;
    unitOfWeight = newUnitOfWeight;
    //what is the default MAX WEIGHT??
    maxWeight = UNKNOWN_WEIGHT;
}

Weight::Weight(float newWeight, float newMaxWeight) {
    //@todo validation
    assert(isWeightValid(newWeight));
    weight = newWeight;
    weightIsKnown = true;
    maxWeight = newMaxWeight;
    hasMaxWeight = true;
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    //@todo validation
    weight = UNKNOWN_WEIGHT;
    maxWeight = newMaxWeight;
    hasMaxWeight = true;
    unitOfWeight = newUnitOfWeight;
}

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    assert(isWeightValid(newWeight));
    weight = newWeight;
    weightIsKnown = true;
    maxWeight = newMaxWeight;
    hasMaxWeight = true;
    unitOfWeight = newUnitOfWeight;
    assert(validate(weight));
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
    switch (toUnit) {
        case POUND:
            fromWeight = fromWeight;
            weight = fromWeight;
            break;
        case KILO:
            weight = fromPoundToKilogram(fromWeight);
            break;
        case SLUG:
            weight = fromPoundToSlug(fromWeight);
            break;
        default:
            assert("ILLEGAL WEIGHT");
            break;
    }

    return globalWeight;
}

float Weight::getMaxWeight() const noexcept{
    if (maxWeight <= 0)
        return UNKNOWN_WEIGHT;
    return maxWeight;
}

bool Weight::validate(float weightToValidate) const noexcept {
    if (isWeightValid(weightToValidate) && getMaxWeight() != UNKNOWN_WEIGHT && weightIsKnown)
        return true;
    cout << "Missing weight condition"<<endl;
    return false;
}

bool Weight::isWeightValid(float checkWeight) const {
    if(checkWeight > 0 && (checkWeight < maxWeight || !hasMaxWeight))
        return true;
    cout << "Missing weight condition"<<endl;
    return false;
}

Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
    return Weight::unitOfWeight;
}

float Weight::getWeight() const noexcept {
    if (!weightIsKnown)
        return UNKNOWN_WEIGHT;
    return weight;
}

