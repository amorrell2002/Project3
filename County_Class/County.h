#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "./nlohmann/json.hpp"
using namespace std;
using json = nlohmann::json;


using namespace std;
struct County{
    //County Demographic Data
    string countyName;
    string stateName;
    float age65AndOlder;
    float age18AndUnder;
    float ageUnder18;
    float ageUnder5;
    float educationBatchelorsOrHigher;
    float educationHighSchoolOrHigher;
    int nonemployerEstablishments;
    float ethnicAmericanIndianAndAlaskaNative;
    float ethnicAsian;
    float ethnicBlack;
    float ethnicHispanic;
    float ethnicHawaiianAndPacificIslander;
    float ethnicTwoOrMoreRaces;
    float ethnicWhite;
    float ethnicWhiteNotHispanic;
    float homeownershipRate;
    int households;
    int medianValueOfOwnerOccupiedUnits;
    float personsPerHousehold;
    int medianHouseholdIncome;
    int perCapitaIncome;
    float forignBorn;
    float landArea;
    float langNotEnglishSpokenAtHome;
    float livingInSameHouseMoreThanOneYear;
    int manufacturersShipments;
    float meanTravelTimeToWork;
    float percentFemale;
    int veterans;
    int population2020;
    int population2010;
    int populationPerSquareMile;
    int accomodationAndFoodServiceSales;
    int retailSales;
    int firmsTotal;
    int firmsWomenOwned;
    int firmsMenOwned;
    int firmsMinorityOwned;
    int firmsNonMinorityOwned;
    int firmsVeteranOwned;
    int firmsNonVeteranOwned;

    //Food Avalibility Data
    float residingInGroupQuarter;
    int totalHousingUnits;
    float vehicleAccessOneMile;
    float vehicleAccessHalfMile;
    float vehicleAccessTenMile;
    float vehicleAccessTwentyMile;
    float kidsBeyondOneMile;
    float kidsBeyondHalfMile;
    float kidsBeyondTenMile;
    float kidsBeyondTwentyMile;
    float lowIncomeBeyondOneMile;
    float lowIncomeBeyondHalfMile;
    float lowIncomeBeyondTenMile;
    float lowIncomeBeyondTwentyMile;
    float popBeyondOneMile;
    float popBeyondHalfMile;
    float popBeyondTenMile;
    float popBeyondTwentyMile;
    float seniorsBeyondOneMile;
    float seniorsBeyondHalfMile;
    float seniorsBeyondTenMile;
    float seniorsBeyondTwentyMile;

    County(json& fileDemographics, json& fileFoodData);
    static const map<string, string> stateMap;

};
