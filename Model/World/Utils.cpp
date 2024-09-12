//
// Created by tally on 11/09/24.
//

#include "Utils.h"

Utils::Utils()
= default;

int Utils::randomInt(const int min, const int max) {
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(getGenerator());
}

double Utils::randomDouble(const double min, const double max) {
    std::uniform_real_distribution<> distrib(min, max);
    return distrib(getGenerator());
}

std::mt19937& Utils::getGenerator() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return gen;
}