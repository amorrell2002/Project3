#pragma once

#include <vector>
#include "County.h"
using namespace std;

struct Shell {
    static void Sort(vector<County*>& counties, string toSortBy);

    static float GetStatistic(County* county, string statisticName);
};