#pragma once

#include <vector>
#include <map>
#include "./County_Class/County.h"

struct Merge{
    static map<string, int> stringLookup;
    static void MergeSort(vector<County>& counties, int start, int end, string toSortBy);
    static void mergeVectors(vector<County>& counties, int left, int mid, int right, int switchCode);
};