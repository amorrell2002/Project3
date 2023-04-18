#include "MergeSort.h"

map<string, int> Merge::stringLookup =  {
        {"age65AndOlder", 0},
        {"age18AndUnder", 1},
        {"educationBatchelorsOrHigher", 2},
        {"educationHighSchoolOrHigher", 3},
        {"ethnicAmericanIndianAndAlaskaNative", 4},
        {"ethnicAsian", 5},
        {"ethnicBlack", 6},
        {"ethnicHispanic", 7},
        {"ethnicWhite", 8},
        {"percentFemale", 9},
        {"kidsBeyondOneMile", 10},
        {"kidsBeyondHalfMile", 11},
        {"kidsBeyondTenMile", 12},
        {"kidsBeyondTwentyMile", 13},
        {"lowIncomeBeyondOneMile", 14},
        {"lowIncomeBeyondHalfMile", 15},
        {"lowIncomeBeyondTenMile", 16},
        {"lowIncomeBeyondTwentyMile", 17},
        {"popBeyondOneMile", 18},
        {"popBeyondHalfMile", 19},
        {"popBeyondTenMile", 20},
        {"popBeyondTwentyMile", 21},
        {"seniorsBeyondOneMile", 22},
        {"seniorsBeyondHalfMile", 23},
        {"seniorsBeyondTenMile", 24},
        {"seniorsBeyondTwentyMile", 25}
    };


void Merge::mergeVectors(vector<County>& counties, int left, int mid, int right, int switchCode)
{
    int leftSize = mid - left + 1;
    int rightSize = mid - right;
    vector<County> leftVector;
    vector<County> rightVector;
    vector<County> outputVector;
    vector<County>::iterator itLeft = leftVector.begin();
    vector<County>::iterator itRight = rightVector.begin();

    for(int i = left; i < leftSize; i++)
    {
        leftVector.push_back(counties[i]);
    }
    for(int i = mid; i < rightSize; i++)
    {
        rightVector.push_back(counties[i]);
    }

    while(itLeft != leftVector.end() && itRight != rightVector.end())
    {
        switch (switchCode){
        case 0:
            if((*itLeft).age65AndOlder > (*itRight).age65AndOlder)
            {
                outputVector.push_back((*itRight));
                outputVector.push_back((*itLeft));
            }
            else
            {
                outputVector.push_back((*itLeft));
                outputVector.push_back((*itRight));
            }
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
    }
    }
    while(itLeft != leftVector.end())
    {
        outputVector.push_back((*itLeft));
    }
    while(itRight != rightVector.end())
    {
        outputVector.push_back((*itRight));
    }
    counties = outputVector;
};

void Merge::MergeSort(vector<County>& counties, int start, int end, string toSortBy)
{
    int switchCode = Merge::stringLookup[toSortBy];

    if(start > end)
    {
        return;
    }

    int mid = start + (start+end)/2;
    Merge::MergeSort(counties, start, mid, toSortBy);
    Merge::MergeSort(counties, mid + 1, end, toSortBy);
    Merge::mergeVectors(counties, start, mid, end, switchCode);

    

};