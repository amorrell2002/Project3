#include "County_Class/County.h"
#include "Merge_Sort/MergeSort.h"
#include "Shell_Sort/Shell.h"
#include <vector>
#include <map>
#include "DataGenerator.h"

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

    //make more data
    DataGenerator::RecombinationGeneration(counties, 33);

    vector<County*> shellCopy;
    for(County* i: counties)
    {
        cout << i->countyName << " : " << i->age65AndOlder << endl;
        shellCopy.push_back(i);
    }
    cout << "===============" << endl;
    cout << "Merge Sort" << endl;

    //timing:
    time_t start = time(nullptr);

    Merge::MergeSort(counties, 0, counties.size() - 1, "age65AndOlder");

    //timing:
    time_t end = time(nullptr);
    cout << "Merge sort took " << to_string(end - start) << " to sort through " << to_string(counties.size()) << " data points." << endl;

    for(County* i: counties)
    {    
        cout << i->countyName << " : " << i->age65AndOlder << endl;
    }

    cout << "===============" << endl;
    cout << "Shell Sort" << endl;

    //timing:
    start = time(nullptr);

    Shell::Sort(shellCopy, "age65AndOlder");

    //timing:
    end = time(nullptr);
    cout << "Merge sort took " << to_string(end - start) << " to sort through " << to_string(counties.size()) << " data points." << endl;

    for(County* i: shellCopy)
    {
        cout << i->countyName << " : " << i->age65AndOlder << endl;
    }

    cout << "Equality check: " << boolToString(vectorEquals(counties, shellCopy)) << endl;

    return 0;

};