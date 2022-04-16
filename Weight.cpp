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
float Weight::weight = UNKNOWN_WEIGHT; //do I need to convert max weight??
//initializing constants end

Weight::Weight() noexcept {
    weight = UNKNOWN_WEIGHT;
    //what is the default MAX WEIGHT??
    maxWeight = UNKNOWN_WEIGHT;
}

Weight::Weight(float newWeight) : Weight(){
    //@todo validation
    assert(isWeightValid(newWeight));
    weight = newWeight;
    weightIsKnown = true;
    maxWeight = UNKNOWN_WEIGHT;
    //what is the default MAX WEIGHT??
}

Weight::Weight(UnitOfWeight newUnitOfWeight) noexcept : Weight(){
    //@todo validation
    unitOfWeight = newUnitOfWeight;
    weight = UNKNOWN_WEIGHT;
    //what is the default MAX WEIGHT??
    maxWeight = UNKNOWN_WEIGHT;
}

Weight::Weight(float newWeight, UnitOfWeight newUnitOfWeight): Weight(){
    //@todo validation
    assert(isWeightValid(newWeight));
    weight = newWeight;
    weightIsKnown = true;
    unitOfWeight = newUnitOfWeight;
    //what is the default MAX WEIGHT??
    maxWeight = UNKNOWN_WEIGHT;
}

Weight::Weight(float newWeight, float newMaxWeight) : Weight() {
    //@todo validation
    assert(isWeightValid(newWeight));
    weight = newWeight;
    weightIsKnown = true;
    if (newMaxWeight > 0)
        maxWeight = newMaxWeight;
    hasMaxWeight = true;
}

Weight::Weight(UnitOfWeight newUnitOfWeight, float newMaxWeight) : Weight() {
    //@todo validation
    weight = UNKNOWN_WEIGHT;
    if (newMaxWeight > 0)
        maxWeight = newMaxWeight;
    hasMaxWeight = true;
    unitOfWeight = newUnitOfWeight;
}

Weight::Weight(float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight) : Weight() {
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
            weight = fromWeight;
            break;
        case KILO:
            weight = fromKilogramToPound(fromWeight);
            maxWeight = fromKilogramToPound(maxWeight);
            break;
        case SLUG:
            weight = fromSlugToPound(fromWeight);
            maxWeight = fromSlugToPound(maxWeight);
            break;
        default:
            cout << "Illegal unit" << endl;
            assert(false);
            break;
    }
    switch (toUnit) {
        case POUND:
            weight = weight;
        #ifdef DEBUG
            cout << weight << endl;
        #endif
            unitOfWeight = POUND;
            break;
        case KILO:
            weight = fromPoundToKilogram(fromWeight);
            maxWeight = fromPoundToKilogram(maxWeight);
            cout << weight << endl;
            unitOfWeight = KILO;
            break;
        case SLUG:
            weight = fromPoundToSlug(fromWeight);
            maxWeight = fromPoundToSlug(maxWeight);
            unitOfWeight = SLUG;
        #ifdef DEBUG
            cout << weight << endl;
        #endif
            break;
        default:
            cout << "Illegal unit" << endl;
            assert(false);
            break;
    }
    isWeightValid(weight);
    return globalWeight;
}

float Weight::getMaxWeight() const noexcept{
    if (maxWeight <= 0)
        return UNKNOWN_WEIGHT;
    return maxWeight;
}

bool Weight::validate(float weightToValidate) const noexcept {
    if (isWeightValid(weightToValidate) && getMaxWeight() > 0 && weightIsKnown)
        return true;
    cout << "Missing weight condition"<<endl;
    return false;
}

bool Weight::isWeightValid(float checkWeight) const {
    if(checkWeight > 0 && (checkWeight <= maxWeight || !hasMaxWeight))
        return true;
    cout << "Missing weight condition"<<endl;
    return false;
}

Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
    return Weight::unitOfWeight;
}

float Weight::getWeight(UnitOfWeight newUnitOfWeight) noexcept {
    if (!weightIsKnown)
        return UNKNOWN_WEIGHT;

    convertWeight(weight, unitOfWeight, newUnitOfWeight);
    return weight;
}

void Weight::setWeight(float newWeight) {
    assert(isWeightValid(newWeight));
    Weight::weight = newWeight;
}

void Weight::setWeight(float newWeight, Weight::UnitOfWeight weightUnits) {
    assert(isWeightValid(newWeight));
    Weight::weight = newWeight;
    Weight::unitOfWeight = weightUnits;
}

void Weight::dump() const {
    cout << "==============================================" << endl;
    cout << "Weight\t" << "this\t" << this << endl;
    cout << boolalpha <<"Weight\t" << "isKnown\t" << weightIsKnown << endl;
    cout << "Weight\t" << "weight\t" << weight << endl;
    switch (unitOfWeight) {
        case 0:
            cout << "Weight\t" << "unitOfWeight\t" << POUND_LABEL << endl;
            break;
        case 1:
            cout << "Weight\t" << "unitOfWeight\t" << KILO_LABEL << endl;
            break;
        case 2:
            cout << "Weight\t" << "unitOfWeight\t" << SLUG_LABEL << endl;
            break;
        default:
            cout << "Weight\t" << "unitOfWeight\t" << "UNKNOWN_UNIT" << endl;
            break;
    }
    cout << boolalpha << "Weight\t" << "hasMax\t" << hasMaxWeight << endl;
    cout << "Weight\t" << "maxWeight\t" << maxWeight << endl;
    cout << "==============================================" << endl;
}

bool Weight::operator==(Weight& rhs_Weight){
    float lhs_weight = (weightIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.weightIsKnown) ?
                       rhs_Weight.getWeight(Weight::POUND) : 0;
    return (lhs_weight == rhs_weight);
}

bool Weight::operator+=(float rhs_addToWeight) {
    if (weight != UNKNOWN_WEIGHT && weight + rhs_addToWeight <= maxWeight){
        weight += rhs_addToWeight;
        return true;
    }

    return false; //can assert this. I'd rather not assert here because it becomes a lil messy
}

bool Weight::operator<(Weight& rhs_Weight) {
    float lhs_weight = (weightIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.weightIsKnown) ?
                       rhs_Weight.getWeight(Weight::POUND) : 0;
    return (lhs_weight > rhs_weight);
}

//