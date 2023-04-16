#pragma once

#include <vector>
#include "./County_Class/County.h"
using namespace std;

struct Shell{
    static void Sort(vector<County>& counties, string toSortBy);

    static float GetStatistic(string statisticName);
}