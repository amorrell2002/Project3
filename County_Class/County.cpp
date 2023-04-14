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
    forignBorn = fileDemographics["Miscellaneous"]["Foreign Born"];
    landArea = fileDemographics["Miscellaneous"]["Land Area"];
    langNotEnglishSpokenAtHome = fileDemographics["Miscellaneous"]["Language Other than English at Home"];
    livingInSameHouseMoreThanOneYear = fileDemographics["Miscellaneous"]["Living in Same House +1 Years"];
    manufacturersShipments = fileDemographics["Miscellaneous"]["Manufacturers Shipments"];
    meanTravelTimeToWork =  fileDemographics["Miscellaneous"]["Mean Travel Time to Work"];
    percentFemale = fileDemographics["Miscellaneous"]["Percent Female"];
    veterans = fileDemographics["Miscellaneous"]["Veterans"];
    population2020 = fileDemographics["Population"]["2020 Population"];
    population2010 = fileDemographics["Population"]["2010 Population"];
    populationPerSquareMile = fileDemographics["Population"]["Population per Square Mile"];
    accomodationAndFoodServiceSales = fileDemographics["Sales"]["Accommodation and Food Services Sales"];
    retailSales = fileDemographics["Sales"]["Retail Sales"];
    firmsTotal = fileDemographics["Employment"]["Firms"]["Total"];
    firmsWomenOwned = fileDemographics["Employment"]["Firms"]["Women-Owned"];
    firmsMenOwned = fileDemographics["Employment"]["Firms"]["Men-Owned"];
    firmsMinorityOwned = fileDemographics["Employment"]["Firms"]["Minority-Owned"];
    firmsNonMinorityOwned = fileDemographics["Employment"]["Firms"]["Nonminority-Owned"];
    firmsVeteranOwned = fileDemographics["Employment"]["Firms"]["Veteran-Owned"];
    firmsNonVeteranOwned = fileDemographics["Employment"]["Firms"]["Nonveteran-Owned"];
    residingInGroupQuarter = fileFoodData["Housing Data"]["Residing in Group Quarters"];
    totalHousingUnits = fileFoodData["Housing Data"]["Total Housing Units"];
    vehicleAccessOneMile = fileFoodData["Vehicle Access"]["1 Mile"];
    vehicleAccessHalfMile = fileFoodData["Vehicle Access"]["1/2 Mile"];
    vehicleAccessTenMile = fileFoodData["Vehicle Access"]["10 Miles"];
    vehicleAccessTwentyMile = fileFoodData["Vehicle Access"]["20 Miles"];
    kidsBeyondOneMile = fileFoodData["Low Access Numbers"]["Children"]["1 Mile"];
    kidsBeyondHalfMile = fileFoodData["Low Access Numbers"]["Children"]["1/2 Mile"];
    kidsBeyondTenMile = fileFoodData["Low Access Numbers"]["Children"]["10 Miles"];
    kidsBeyondTwentyMile = fileFoodData["Low Access Numbers"]["Children"]["20 Miles"];
    lowIncomeBeyondOneMile = fileFoodData["Low Access Numbers"]["Low Income People"]["1 Mile"];
    lowIncomeBeyondHalfMile = fileFoodData["Low Access Numbers"]["Low Income People"]["1/2 Mile"];
    lowIncomeBeyondTenMile = fileFoodData["Low Access Numbers"]["Low Income People"]["10 Miles"];
    lowIncomeBeyondTwentyMile = fileFoodData["Low Access Numbers"]["Low Income People"]["20 Miles"];
    popBeyondOneMile = fileFoodData["Low Access Numbers"]["People"]["1 Mile"];
    popBeyondHalfMile = fileFoodData["Low Access Numbers"]["People"]["1/2 Mile"];
    popBeyondTenMile = fileFoodData["Low Access Numbers"]["People"]["10 Miles"];
    popBeyondTwentyMile = fileFoodData["Low Access Numbers"]["People"]["20 Miles"];
    seniorsBeyondOneMile = fileFoodData["Low Access Numbers"]["Seniors"]["1 Mile"];
    seniorsBeyondHalfMile = fileFoodData["Low Access Numbers"]["Seniors"]["1/2 Mile"];
    seniorsBeyondTenMile = fileFoodData["Low Access Numbers"]["Seniors"]["10 Miles"];
    seniorsBeyondTwentyMile = fileFoodData["Low Access Numbers"]["Seniors"]["20 Miles"];

};

const map<string, string> County::stateMap = {
        {"AL", "Alabama"},
        {"AK", "Alaska"},
        {"AZ", "Arizona"},
        {"AR", "Arkansas"},
        {"CA", "California"},
        {"CO", "Colorado"},
        {"CT", "Connecticut"},
        {"DE", "Delaware"},
        {"FL", "Florida"},
        {"GA", "Georgia"},
        {"HI", "Hawaii"},
        {"ID", "Idaho"},
        {"IL", "Illinois"},
        {"IN", "Indiana"},
        {"IA", "Iowa"},
        {"KS", "Kansas"},
        {"KY", "Kentucky"},
        {"LA", "Louisiana"},
        {"ME", "Maine"},
        {"MD", "Maryland"},
        {"MA", "Massachusetts"},
        {"MI", "Michigan"},
        {"MN", "Minnesota"},
        {"MS", "Mississippi"},
        {"MO", "Missouri"},
        {"MT", "Montana"},
        {"NE", "Nebraska"},
        {"NV", "Nevada"},
        {"NH", "New Hampshire"},
        {"NJ", "New Jersey"},
        {"NM", "New Mexico"},
        {"NY", "New York"},
        {"NC", "North Carolina"},
        {"ND", "North Dakota"},
        {"OH", "Ohio"},
        {"OK", "Oklahoma"},
        {"OR", "Oregon"},
        {"PA", "Pennsylvania"},
        {"RI", "Rhode Island"},
        {"SC", "South Carolina"},
        {"SD", "South Dakota"},
        {"TN", "Tennessee"},
        {"TX", "Texas"},
        {"UT", "Utah"},
        {"VT", "Vermont"},
        {"VA", "Virginia"},
        {"WA", "Washington"},
        {"WV", "West Virginia"},
        {"WI", "Wisconsin"},
        {"WY", "Wyoming"},
        {"DC", "District of Columbia"}
    };