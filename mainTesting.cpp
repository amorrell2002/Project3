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

int main()
{
    fstream inFile("../data/test_demographics.json");
    json demoFile;
    json foodFile;
    //Load Demographics File
    inFile >> demoFile;

    //Load Food Data File
    inFile.close();
    inFile.open("../data/food_access.json");
    inFile >> foodFile;

    vector<County*> counties;
    
    for(json i: demoFile)
    {
        for(json n: foodFile)
        //Match County Names and States
        if(i["County"].get<string>() == n["County"].get<string>())
        {
            if(County::stateMap.at(i["State"].get<string>()) == n["State"].get<string>())
            {
                
                cout << "Loading Data.. (This will take approx. 3 minutes)" << endl;
                counties.push_back(new County(i, n));
                break;
                
            }
            
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

    cout << "Equality check: " << vectorEquals(counties, shellCopy) << endl;

    return 0;

};