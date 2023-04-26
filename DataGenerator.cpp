//
// Created by cbaks on 4/26/2023.
//

#include "DataGenerator.h"

void DataGenerator::RecombinationGeneration(vector<County*>& counties, int iterations = 35) {
    int initSize = counties.size(); //save the original
    for (int i = 0; i < iterations; ++i) {
        for (int j = 0; j < initSize; ++j) {
            int demographicsIndex = j-1;
            int foodAccessIndex = j+i;
            if(demographicsIndex < 0){
                //can't have a negative index, so go to the last element from the original vector
                demographicsIndex = initSize-1;
            }
            if(foodAccessIndex >= initSize){
                //can't go beyond what data we started with
                foodAccessIndex -= initSize;
            }

            //create a new, fake county
            counties.push_back(new County);
            County* added = counties.at(counties.size()-1);

            //set the variables for the county we just added
            added->countyName = "faux_" + to_string(i) + "_" + to_string(j);
            added->stateName = "faux_" + to_string(i) + "_" + to_string(j);

            //demographics
            added->age65AndOlder = counties.at(demographicsIndex)->age65AndOlder;
            added->age18AndUnder = counties.at(demographicsIndex)->age18AndUnder;
            added->educationBatchelorsOrHigher = counties.at(demographicsIndex)->educationBatchelorsOrHigher;
            added->educationHighSchoolOrHigher = counties.at(demographicsIndex)->educationHighSchoolOrHigher;
            added->ethnicAmericanIndianAndAlaskaNative = counties.at(demographicsIndex)->ethnicAmericanIndianAndAlaskaNative;
            added->ethnicAsian = counties.at(demographicsIndex)->ethnicAsian;
            added->ethnicBlack = counties.at(demographicsIndex)->ethnicBlack;
            added->ethnicHispanic = counties.at(demographicsIndex)->ethnicHispanic;
            added->ethnicWhite = counties.at(demographicsIndex)->ethnicWhite;
            added->percentFemale = counties.at(demographicsIndex)->percentFemale;

            //food access
            added->kidsBeyondTenMile = counties.at(foodAccessIndex)->kidsBeyondTenMile;
            added->lowIncomeBeyondTenMile = counties.at(foodAccessIndex)->lowIncomeBeyondTenMile;
            added->popBeyondTenMile = counties.at(foodAccessIndex)->popBeyondTenMile;
            added->seniorsBeyondTenMile = counties.at(foodAccessIndex)->seniorsBeyondTenMile;



        }
    }
}
