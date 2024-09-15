//
// Created by louismmassin on 9/13/24.
//

#include "UtilityFunctions.h"


namespace UtilityFunctions {
    bool randomEvent(float probability) {
        static random_device generator;
        static uniform_real_distribution<float> distribution(0.0f,1.0f);
        float randomResult = distribution(generator);
        if(randomResult < probability) {
            return true;
        }
        return false;
    }

    int randomInt(int range) {
        static random_device generator;
        uniform_int_distribution<int> distribution(0,range -1);
        int randomResult = distribution(generator);
        return randomResult;
    }
}
