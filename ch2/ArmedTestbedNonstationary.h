//
// Created by Scarlatescu, Erik on 7/5/23.
//

#ifndef SUTTONBARTO_ARMEDTESTBEDNONSTATIONARY_H
#define SUTTONBARTO_ARMEDTESTBEDNONSTATIONARY_H

#include "ArmedTestbed.h"

class ArmedTestbedNonstationary: public ArmedTestbed {
public:
    explicit ArmedTestbedNonstationary(int num_arms, int seed=1): ArmedTestbed(num_arms, seed) {}
    double pull_lever(int lever);
};


#endif //SUTTONBARTO_ARMEDTESTBEDNONSTATIONARY_H
