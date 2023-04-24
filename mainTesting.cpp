#include "County_Class/County.h"
#include "Merge_Sort/MergeSort.h"
#include "Shell_Sort/Shell.h"
#include <vector>
#include <map>

static bool vectorEquals(vector<County*> v1, vector<County*> v2) {
    if (v1.size() != v2.size()) {
        return false;
    } else {
        for (int i = 0; i < v1.size(); i++) {
            if (v1.at(i) != v2.at(i)) {
                return false;
            }
        }
        return true;
    }
}

static string boolToString(bool bVal){
    if(bVal){
        return "true";
    }else{
        return "false";
    }
}

int main()
{
    fstream inFile("./data/county_demographics.json");
    json demoFile;
    json foodFile;
    //Load Demographics File
    inFile >> demoFile;

    //Load Food Data File
    inFile.close();
    inFile.open("../data/food_access.json");
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

    vector<County*> shellCopy;
    for(County* i: counties)
    {
        cout << i->countyName << " : " << i->age65AndOlder << endl;
        shellCopy.push_back(i);
    }
    cout << "===============" << endl;
    cout << "Merge Sort" << endl;
    Merge::MergeSort(counties, 0, counties.size() - 1, "age65AndOlder");
    for(County* i: counties)
    {    
        cout << i->countyName << " : " << i->age65AndOlder << endl;
    }

    cout << "===============" << endl;
    cout << "Shell Sort" << endl;
    Shell::Sort(shellCopy, "age65AndOlder");
    for(County* i: shellCopy)
    {
        cout << i->countyName << " : " << i->age65AndOlder << endl;
    }

    cout << "Equality check: " << boolToString(vectorEquals(counties, shellCopy)) << endl;

    return 0;

};