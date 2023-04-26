//
// Created by cbaks on 4/26/2023.
//

#ifndef PROJECT3_DATAGENERATOR_H
#define PROJECT3_DATAGENERATOR_H
#include "County_Class/County.h"

class DataGenerator {
    ///
    /// \param counties
    /// \param iterations how many times to generate additional data; (final size) = (initial size) * (iterations + 1)
    static void RecombinationGeneration(vector<County*>& counties, int iterations);
};


#endif //PROJECT3_DATAGENERATOR_H
