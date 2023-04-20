#include "County_Class/County.h"
#include "Merge_Sort/MergeSort.h"
#include <vector>
#include <map>

int main()
{
    fstream inFile("./data/test_demographics.json");
    json demoFile;
    json foodFile;
    //Load Demographics File
    inFile >> demoFile;

    //Load Food Data File
    inFile.close();
    inFile.open("./data/food_access.json");
    inFile >> foodFile;

    vector<County> counties;
    
    for(json i: demoFile)
    {
        for(json n: foodFile)
        //Match County Names and States
        if(i["County"].get<string>() == n["County"].get<string>())
        {
            if(County::stateMap.at(i["State"].get<string>()) == n["State"].get<string>())
            {
                
                cout << "Loading Data.. (This will take approx. 3 minutes)" << endl;
                counties.push_back(County(i, n));
                break;
                
            }
            
        }
    }
    for(County i: counties)
    {
        cout << i.countyName << " : " << i.age65AndOlder << endl;
    }
    cout << "===============" << endl;
    Merge::MergeSort(counties, 0, counties.size() - 1, "age65AndOlder");
    for(County i: counties)
    {    
        cout << i.countyName << " : " << i.age65AndOlder << endl;
    }



};