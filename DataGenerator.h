#pragma once
//
// Created by cbaks on 4/26/2023.
//

#ifndef PROJECT3_DATAGENERATOR_H
#define PROJECT3_DATAGENERATOR_H
#include "County.h"

struct DataGenerator {
    ///
    /// \param counties the vector of county pointers
    /// \param iterations how many times to generate additional data; (final size) = (initial size) * (iterations + 1)
    static int RecombinationGeneration(vector<County*>& counties, int iterations);

    static void DeBoxifiedRecGen(vector<County*>& counties, int iterations, int amountToChangeBy);
};


#endif //PROJECT3_DATAGENERATOR_H
