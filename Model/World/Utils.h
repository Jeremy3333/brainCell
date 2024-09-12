//
// Created by tally on 11/09/24.
//

#ifndef UTILS_H
#define UTILS_H

#include <random>

class Utils {
public:
    Utils();
    static int randomInt(int min, int max);
    static double randomDouble(double min, double max);
private:
    static std::mt19937& getGenerator();
};



#endif //UTILS_H
