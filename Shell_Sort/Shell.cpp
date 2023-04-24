//implementation of shell sort based on the short bit of psuedocode from class

#include "Shell.h"

void Shell::Sort(vector<County*>& counties, string toSortBy){
    for(int gap = counties.size() / 2; gap > 0; gap /= 2.2){ //gap starts at half the vector size, and is divided by 2.2 each iteration according to class notes
        //do this pass (for a given gap size):
        for(int i = gap; i < counties.size(); i++){
            //do this for many of the values (but usually not all) in the vector
            int cur = i; //we will follow vector[cur], which will start being at i but will often decrease, but we don't want to modify i here
            while(cur - gap >= 0 && GetStatistic(counties.at(cur), toSortBy) < GetStatistic(counties.at(cur - gap), toSortBy)){  //check if our current value is less than the value we get from going back 'gap' amount in the vector
                //keep doing this as we follow a single value
                //the while condition says that we need to swap, so swap we shall
                County* temp = counties.at(cur - gap);
                counties.at(cur - gap) = counties.at(cur);
                counties.at(cur) = temp;

                //stay with the same value as it moves down towards the start of the vector
                cur = cur-gap;
            }
        }
        if(gap == 2){
            gap = 3;    // 3/2.2 = 1, which is what we want
        }
    }

}

/// @brief Extract a particular statistic from a given county pointer based on the name of the statistic
/// @param county whose statistic to use
/// @param statisticName which statistic to get
/// @return the value of the statistic
float Shell::GetStatistic(County* county, string statisticName){
    if(statisticName == "age65AndOlder"){
        return county->age65AndOlder;
    }else if(statisticName == "age18AndUnder"){
        return county->age18AndUnder;
    }else if(statisticName == "educationBatchelorsOrHigher"){
        return county->educationBatchelorsOrHigher;
    }else if(statisticName == "educationHighSchoolOrHigher"){
        return county->educationHighSchoolOrHigher;
    }else if(statisticName == "ethnicAmericanIndianAndAlaskaNative"){
        return county->ethnicAmericanIndianAndAlaskaNative;
    }else if(statisticName == "ethnicAsian"){
        return county->ethnicAsian;
    }else if(statisticName == "ethnicBlack"){
        return county->ethnicBlack;
    }else if(statisticName == "ethnicHispanic"){
        return county->ethnicHispanic;
    }else if(statisticName == "ethnicWhite"){
        return county->ethnicWhite;
    }else if(statisticName == "percentFemale"){
        return county->percentFemale;
    }else if(statisticName == "kidsBeyondOneMile"){
        return county->kidsBeyondOneMile;
    }else if(statisticName == "kidsBeyondHalfMile"){
        return county->kidsBeyondHalfMile;
    }else if(statisticName == "kidsBeyondTenMile"){
        return county->kidsBeyondTenMile;
    }else if(statisticName == "kidsBeyondTwentyMile"){
        return county->kidsBeyondTwentyMile;
    }else if(statisticName == "lowIncomeBeyondOneMile"){
        return county->lowIncomeBeyondOneMile;
    }else if(statisticName == "lowIncomeBeyondHalfMile"){
        return county->lowIncomeBeyondHalfMile;
    }else if(statisticName == "lowIncomeBeyondTenMile"){
        return county->lowIncomeBeyondTenMile;
    }else if(statisticName == "lowIncomeBeyondTwentyMile"){
        return county->lowIncomeBeyondTwentyMile;
    }else if(statisticName == "popBeyondOneMile"){
        return county->popBeyondOneMile;
    }else if(statisticName == "popBeyondHalfMile"){
        return county->popBeyondHalfMile;
    }else if(statisticName == "popBeyondTenMile"){
        return county->popBeyondTenMile;
    }else if(statisticName == "popBeyondTwentyMile"){
        return county->popBeyondTwentyMile;
    }else if(statisticName == "seniorsBeyondOneMile"){
        return county->seniorsBeyondOneMile;
    }else if(statisticName == "seniorsBeyondHalfMile"){
        return county->seniorsBeyondHalfMile;
    }else if(statisticName == "seniorsBeyondTenMile"){
        return county->seniorsBeyondTenMile;
    }else if(statisticName == "seniorsBeyondTwentyMile"){
        return county->seniorsBeyondTwentyMile;
    }else return -1;
}