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
    vector<County> leftVector;
    vector<County> rightVector;
    vector<County> outputVector;

    for(int i = left; i <= mid; i++)
    {
        leftVector.push_back(counties[i]);
    }
    for(int i = mid + 1; i <= right; i++)
    {
        rightVector.push_back(counties[i]);
    }

    vector<County>::iterator itLeft = leftVector.begin();
    vector<County>::iterator itRight = rightVector.begin();

    while(itLeft != leftVector.end() && itRight != rightVector.end())
    {
        switch (switchCode){
        case 0:
            if((*itLeft).age65AndOlder > (*itRight).age65AndOlder)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
        case 1:
            if((*itLeft).age18AndUnder > (*itRight).age18AndUnder)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
        case 2:
            if((*itLeft).educationBatchelorsOrHigher > (*itRight).educationBatchelorsOrHigher)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
        case 3:
            if((*itLeft).educationHighSchoolOrHigher > (*itRight).educationHighSchoolOrHigher)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
        case 4:
            if((*itLeft).ethnicAmericanIndianAndAlaskaNative > (*itRight).ethnicAmericanIndianAndAlaskaNative)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
        case 5:
            if((*itLeft).ethnicAsian > (*itRight).ethnicAsian)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
        case 6:
            if((*itLeft).ethnicBlack > (*itRight).ethnicBlack)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
        case 7:
            if((*itLeft).ethnicHispanic > (*itRight).ethnicHispanic)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
        case 8:
            if((*itLeft).ethnicWhite > (*itRight).ethnicWhite)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
        case 9:
            if((*itLeft).percentFemale > (*itRight).percentFemale)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
        case 10:
            if((*itLeft).kidsBeyondOneMile > (*itRight).kidsBeyondOneMile)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
        case 11:
            if((*itLeft).kidsBeyondHalfMile > (*itRight).kidsBeyondHalfMile)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
        case 12:
            if((*itLeft).kidsBeyondTenMile > (*itRight).kidsBeyondTenMile)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
        case 13:
            if((*itLeft).kidsBeyondTwentyMile > (*itRight).kidsBeyondTwentyMile)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
        case 14:
            if((*itLeft).lowIncomeBeyondOneMile > (*itRight).lowIncomeBeyondOneMile)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
        case 15:
            if((*itLeft).lowIncomeBeyondHalfMile > (*itRight).lowIncomeBeyondHalfMile)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
        case 16:
            if((*itLeft).lowIncomeBeyondTenMile > (*itRight).lowIncomeBeyondTenMile)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
        case 17:
            if((*itLeft).lowIncomeBeyondTwentyMile > (*itRight).lowIncomeBeyondTwentyMile)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
        case 18:
            if((*itLeft).popBeyondOneMile > (*itRight).popBeyondOneMile)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
        case 19:
            if((*itLeft).popBeyondHalfMile > (*itRight).popBeyondHalfMile)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
        case 20:
            if((*itLeft).popBeyondTenMile > (*itRight).popBeyondTenMile)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
        case 21:
            if((*itLeft).popBeyondTwentyMile > (*itRight).popBeyondTwentyMile)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
        case 22:
            if((*itLeft).seniorsBeyondOneMile > (*itRight).seniorsBeyondOneMile)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
        case 23:
            if((*itLeft).seniorsBeyondHalfMile > (*itRight).seniorsBeyondHalfMile)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
        case 24:
            if((*itLeft).seniorsBeyondTenMile > (*itRight).seniorsBeyondTenMile)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
        case 25:
            if((*itLeft).seniorsBeyondTwentyMile > (*itRight).seniorsBeyondTwentyMile)
            {
                outputVector.push_back((*itRight));
                itRight++;
            }
            else
            {
                outputVector.push_back((*itLeft));
                itLeft++;
            }
            break;
    };
};
    while(itLeft != leftVector.end())
    {
        outputVector.push_back((*itLeft));
        itLeft++;
    }
    while(itRight != rightVector.end())
    {
        outputVector.push_back((*itRight));
        itRight++;
    }
    vector<County>::iterator itOut = outputVector.begin();
    for(int i = left; i <= right; i++)
    {
        counties[i] = *itOut;
        itOut++;
    }
};
void Merge::MergeSort(vector<County>& counties, int start, int end, string toSortBy)
{
    int switchCode = Merge::stringLookup[toSortBy];

    if(start >= end)
    {
        return;
    }

    int mid = start + (end - start)/2;
    Merge::MergeSort(counties, start, mid, toSortBy);
    Merge::MergeSort(counties, mid + 1, end, toSortBy);
    Merge::mergeVectors(counties, start, mid, end, switchCode);

    

};