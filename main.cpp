// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Graph.h"
#include "County.h"
#include "MergeSort.h"
#include "Shell.h"
#include <iostream>
//#include  <SFML/Graphics.hpp> // replace quotes with less than and greater than symbols
#include "DataGenerator.h"

vector<County*> load()
{
    fstream inFile("county_demographics.json");
    json demoFile;
    json foodFile;
    //Load Demographics File
    inFile >> demoFile;

    //Load Food Data File
    inFile.close();
    inFile.open("food_access.json");
    inFile >> foodFile;

    vector<County*> counties;
    unordered_map<string, County*> countyMap;
    for (json i : demoFile)
    {
        County* tempCounty = new County();
        tempCounty->loadDemoData(i);
        countyMap[tempCounty->countyName] = tempCounty;
    }
    for (json i : foodFile)
    {
        County* tempCounty = new County();
        tempCounty->loadFoodData(i);

        unordered_map<string, County*>::iterator it = countyMap.find(tempCounty->countyName);
        if (it != countyMap.end())
        {
            (it)->second->loadFoodData(i);
            counties.push_back(it->second);
            countyMap.erase(it);
        }

    }

    return counties;


}
vector<County*> sort(vector<County*> counties, string sortSelection, string foodAccessSelection)
{

    //make more data
    DataGenerator::RecombinationGeneration(counties, 33);

    if (sortSelection == "merge")
    {
        //timing:
        time_t start = time(nullptr);

        Merge::MergeSort(counties, 0, counties.size() - 1, foodAccessSelection);

        //timing:
        time_t end = time(nullptr);
        cout << "Merge sort took " << to_string(end - start) << " to sort through " << to_string(counties.size()) << " data points." << endl;
    }
    else if (sortSelection == "shell")
    {
        //timing:
        time_t start = time(nullptr);

        Shell::Sort(counties, foodAccessSelection);

        //timing:
        time_t end = time(nullptr);
        cout << "Shell sort took " << to_string(end - start) << " to sort through " << to_string(counties.size()) << " data points." << endl;

    }
    return counties;


}


int main()

{
    
    cout << "Food Access vs Demographic Visualizer\n" << endl;
    cout << "Welcome!\n" << endl;

    int exit = 1;

    //program continues running until user exits
    while (exit == 1)
    {

        int demographicSelection;
        string strDemographicSelection;
        int foodAccessSelection;
        string strFoodAccessSelection;
        int sortSelection;
        string strSortSelection;

        //main menu - get input for demographics and sorting algorithm
        cout << "Please select your metrics for comparison:\n" << endl;

        cout << "Demographic (%):" << endl;
        cout << "1. 65+ y/o \n2. 18- y/o \n3. High school+ education \n4. Bachelors degree+ education \n5. Ethnic American Indian and Alaska Native \n6. Ethnic Asian \n7. Black \n8. Hispanic or Latino \n9. Native Hawaiian or Pacific Islander \n10. White \n11. Female" << endl;
        cout << "Enter 0 to exit the program\n";
        cin >> demographicSelection;
        if (demographicSelection == 0)
            break;

        cout << "Food Access (10+ miles from a super market):" << endl;
        cout << "1. Low income population \n2. Children population \n3. Total population \n4. Senior population \n";
        cout << "Enter 0 to exit the program\n";
        cin >> foodAccessSelection;
        if (foodAccessSelection == 0)
            break;

        cout << "Please select the sorting algorithm to use: " << endl;
        cout << "1. Shell sort \n2. Merge sort" << endl;
        cout << "Enter 0 to exit the program\n";
        cin >> sortSelection;
        if (sortSelection == 0)
            break;

        //pull necessary data based on selections
        if (demographicSelection == 1)
        {
            //demographic = 65+ y/o
            strDemographicSelection = "age65AndOlder";
        }
        else if (demographicSelection == 2)
        {
            //demographic = 18- y/o
            strDemographicSelection = "age18AndUnder";

        }
        else if (demographicSelection == 3)
        {
            //demographic = High school+ education
            strDemographicSelection = "educationHighSchoolOrHigher";

        }
        else if (demographicSelection == 4)
        {
            //demographic = Bachelors degree+ education
            strDemographicSelection = "educationBatchelorsOrHigher";

        }
        else if (demographicSelection == 5)
        {
            //demographic = Hispanic or Latino
            strDemographicSelection = "ethnicHispanic";

        }
        else if (demographicSelection == 6)
        {
            //demographic = ethnicAmericanIndianAndAlaskaNative
            strDemographicSelection = "ethnicAmericanIndianAndAlaskaNative";

        }
        else if (demographicSelection == 7)
        {
            //demographic = ethnicAsian
            strDemographicSelection = "ethnicAsian";

        }
        else if (demographicSelection == 8)
        {
            //demographic = ethnicBlack
            strDemographicSelection = "ethnicBlack";

        }
        else if (demographicSelection == 9)
        {
            //demographic = ethnicHawaiianAndPacificIslander
            strDemographicSelection = "ethnicHawaiianAndPacificIslander";

        }
        else if (demographicSelection == 10)
        {
            //demographic = ethnicWhite
            strDemographicSelection = "ethnicWhite";

        }
        else if (demographicSelection == 11)
        {
            //demographic = percentFemale
            strDemographicSelection = "percentFemale";

        }

        if (foodAccessSelection == 1)
        {
            strFoodAccessSelection = "lowIncomeBeyondTenMile";
        }
        else if (foodAccessSelection == 2)
        {
            strFoodAccessSelection = "kidsBeyondTenMile";
        }
        else if (foodAccessSelection == 3)
        {
            strFoodAccessSelection = "popBeyondTenMile";
        }
        else if (foodAccessSelection == 4)
        {
            strFoodAccessSelection = "seniorsBeyondTenMile";
        }

        if (sortSelection == 1)
        {
            strSortSelection = "shell";
        }
        else if (sortSelection == 2)
        {
            strSortSelection = "merge";

        }

        vector<County*> counties = load();
        counties = sort(counties, strSortSelection, strFoodAccessSelection);

        Graph graph;
        graph.run(counties, strDemographicSelection, strFoodAccessSelection);

        int selection;
        cout << "Enter 0 to exit the program or 1 to make a new selection\n";
        cin >> selection;
        graph.close();
        if (selection == 0)
            break;
        else if (selection == 1)
            continue;

    }


    cout << "Thank you for using our Food Access vs Demographic Visualizer!" << endl;
    return 0;

}