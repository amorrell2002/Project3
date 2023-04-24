#include "County_Class/County.h"
#include "Merge_Sort/MergeSort.h"
#include <vector>
#include <map>

int main()
{
    fstream inFile("./data/county_demographics.json");
    json demoFile;
    json foodFile;
    //Load Demographics File
    inFile >> demoFile;

    //Load Food Data File
    inFile.close();
    inFile.open("./data/food_access.json");
    inFile >> foodFile;

    vector<County*> counties;
    unordered_map<string, County*> countyMap;
    for(json i : demoFile)
    {
        County* tempCounty = new County();
        tempCounty->loadDemoData(i);
        countyMap[tempCounty->countyName] = tempCounty;
    }
    for(json i: foodFile)
    {
        County* tempCounty = new County();
        tempCounty->loadFoodData(i);

        unordered_map<string, County*>::iterator it = countyMap.find(tempCounty->countyName);
        if(it != countyMap.end())
        {
            (it)->second->loadFoodData(i);
            counties.push_back(it->second);
            countyMap.erase(it);
        }

    }

    for(County* i: counties)
    {
        cout << i->countyName << " : " << i->age65AndOlder << endl;
    }
    cout << "===============" << endl;
    Merge::MergeSort(counties, 0, counties.size() - 1, "age65AndOlder");
    for(County* i: counties)
    {    
        cout << i->countyName << " : " << i->age65AndOlder << endl;
    }

    return 0;

};