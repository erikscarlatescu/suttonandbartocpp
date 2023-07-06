//
// Created by Scarlatescu, Erik on 7/5/23.
//

#ifndef SUTTONBARTO_EPSILONGREEDYAGENT_H
#define SUTTONBARTO_EPSILONGREEDYAGENT_H

#include "ArmedTestbed.h"

#include <functional>

typedef std::function<void(std::vector<double>&, std::vector<int>&, double, int)> update_q_type;

class EpsilonGreedyAgent {
private:
    double epsilon;
    ArmedTestbed armed_testbed;
    update_q_type update_q_fn;

    std::default_random_engine generator;

    std::vector<double> action_probs;

    std::vector<double> q_estimates;
    std::vector<int> num_samples;
public:
    explicit EpsilonGreedyAgent(ArmedTestbed& armed_testbed, update_q_type update_q_fn, double epsilon=0.05, int seed=1);

    int choose_action();

    inline void update_q_function(double reward, int action) {
        this->update_q_fn(q_estimates, num_samples, reward, action);
    }
};


#endif //SUTTONBARTO_EPSILONGREEDYAGENT_H
