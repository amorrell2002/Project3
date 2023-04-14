#include "County.h"

County::County(json& fileDemographics, json& fileFoodData)
{
   
    
    countyName = fileDemographics["County"];
    stateName = fileFoodData["State"];
    age65AndOlder = fileDemographics["Age"]["Percent 65 and Older"];
    age18AndUnder = fileDemographics["Age"]["Percent Under 18 Years"];
    ageUnder5 = fileDemographics["Age"]["Percent Under 5 Years"];
    educationBatchelorsOrHigher = fileDemographics["Education"]["Bachelor's Degree or Higher"];
    educationHighSchoolOrHigher = fileDemographics["Education"]["High School or Higher"];
    nonemployerEstablishments = fileDemographics["Employment"]["Nonemployer Establishments"];
    ethnicAmericanIndianAndAlaskaNative = fileDemographics["Ethnicities"]["American Indian and Alaska Native Alone"];
    ethnicAsian = fileDemographics["Ethnicities"]["Asian Alone"];
    ethnicBlack = fileDemographics["Ethnicities"]["Black Alone"];
    ethnicHispanic = fileDemographics["Ethnicities"]["Hispanic or Latino"];
    ethnicHawaiianAndPacificIslander = fileDemographics["Ethnicities"]["Native Hawaiian and Other Pacific Islander Alone"];
    ethnicTwoOrMoreRaces = fileDemographics["Ethnicities"]["Two or More Races"];
    ethnicWhite = fileDemographics["Ethnicities"]["White Alone"];
    ethnicWhiteNotHispanic = fileDemographics["Ethnicities"]["White Alone\t not Hispanic or Latino"];
    homeownershipRate = fileDemographics["Housing"]["Homeownership Rate"];
    households = fileDemographics["Housing"]["Households"];
    medianValueOfOwnerOccupiedUnits = fileDemographics["Housing"]["Median Value of Owner-Occupied Units"];
    personsPerHousehold = fileDemographics["Housing"]["Persons per Household"];
    medianHouseholdIncome = fileDemographics["Income"]["Median Houseold Income"];
    perCapitaIncome = fileDemographics["Income"]["Per Capita Income"];
    forignBorn;
    landArea;
    langNotEnglishSpokenAtHome;
    livingInSameHouseMoreThanOneYear;
    manufacturersShipments;
    meanTravelTimeToWork;
    percentFemale;
    veterans;
    population2020;
    population2010;
    populationPerSquareMile;
    accomodationAndFoodServiceSales;
    retailSales;
    firmsTotal;
    firmsWomenOwned;
    firmsMenOwned;
    firmsMinorityOwned;
    firmsNonMinorityOwned;
    firmsVeteranOwned;
    firmsNonVeteranOwned;
    residingInGroupQuarter;
    totalHousingUnits;
    vehicleAccessOneMile;
    vehicleAccessHalfMile;
    vehicleAccessTenMile;
    vehicleAccessTwentyMile;
    kidsBeyondOneMile;
    kidsBeyondHalfMile;
    kidsBeyondTenMile;
    kidsBeyondTwentyMile;
    lowIncomeBeyondOneMile;
    lowIncomeBeyondHalfMile;
    lowIncomeBeyondTenMile;
    lowIncomeBeyondTwentyMile;
    popBeyondOneMile;
    popBeyondHalfMile;
    popBeyondTenMile;
    popBeyondTwentyMile;
    seniorsBeyondOneMile;
    seniorsBeyondHalfMile;
    seniorsBeyondTenMile;
    seniorsBeyondTwentyMile;

};