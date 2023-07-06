//
// Created by Scarlatescu, Erik on 7/5/23.
//

#include "ArmedTestbedNonstationary.h"

double ArmedTestbedNonstationary::pull_lever(int lever) {
    double reward = ArmedTestbed::pull_lever(lever);
    // make reward means drift
    for (double & mean : means) {
        mean += 0.01 * unit_normal(generator);
    }
    return reward;
}
