#include "County.h"

int main()
{
    fstream inFile("./county_demographics.json");
    json file;
    inFile >> file;
    for(json i: file)
    {
        cout << i["County"].get<string>() << endl;
    }

};