//
// Created by Scarlatescu, Erik on 7/5/23.
//

#include "ArmedTestbed.h"

#include <random>

ArmedTestbed::ArmedTestbed(int num_arms, int seed): generator(seed) {
    for (int i = 0; i < num_arms; i++) {
        means.push_back(this->unit_normal(generator));
    }
}

double ArmedTestbed::pull_lever(int lever) {
    return means[lever] + this->unit_normal(generator);
}

#include <iostream>
int ArmedTestbed::get_max_action() {
    auto max_it = std::max_element(means.begin(), means.end());
    return std::distance(means.begin(), max_it);
}
