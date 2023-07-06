//
// Created by Scarlatescu, Erik on 7/5/23.
//

#ifndef SUTTONBARTO_ARMEDTESTBED_H
#define SUTTONBARTO_ARMEDTESTBED_H

#include <vector>
#include <random>

class ArmedTestbed {
protected:
    std::vector<double> means;
    std::default_random_engine generator;
    std::normal_distribution<double> unit_normal;
public:
    explicit ArmedTestbed(int num_arms, int seed=1);
    virtual ~ArmedTestbed() = default;

    virtual double pull_lever(int lever);

    inline int num_arms() { return means.size(); }

    int get_max_action();

    inline double get_action_reward(int action) { return means[action]; }
};

#endif //SUTTONBARTO_ARMEDTESTBED_H
