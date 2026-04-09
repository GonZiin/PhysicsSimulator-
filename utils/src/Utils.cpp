//
// Created by Gomes on 09/04/2026.
//

#include "../include/Utils.h"

double Utils::generateRandomNumber(int min, int max) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(rng);
}
