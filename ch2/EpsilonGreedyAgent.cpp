//
// Created by Scarlatescu, Erik on 7/5/23.
//

#include "EpsilonGreedyAgent.h"

#include <cfloat>
#include <utility>

EpsilonGreedyAgent::EpsilonGreedyAgent(ArmedTestbed &armed_testbed, update_q_type update_q_fn, double epsilon, int seed): epsilon(epsilon), armed_testbed(armed_testbed), generator(seed),
                                                                                                                 update_q_fn(std::move(update_q_fn)) {
    action_probs = std::vector<double>(armed_testbed.num_arms(), 0.0);

    num_samples = std::vector<int>(armed_testbed.num_arms(), 0);
    q_estimates = std::vector<double>(armed_testbed.num_arms(), 0.0);
}

int EpsilonGreedyAgent::choose_action() {
    auto max_it = std::max_element(q_estimates.begin(), q_estimates.end());

    double max_val = *max_it;
    std::vector<int> ties;
    for (int i = 0; i < q_estimates.size(); i++) {
        if (q_estimates[i] == max_val) {
            ties.push_back(i);
        }
    }

    std::fill(action_probs.begin(), action_probs.end(), epsilon / (armed_testbed.num_arms() - ties.size()));

    for (int tie : ties) {
        action_probs[tie] = (1.0 - epsilon) / ties.size();
    }

    std::discrete_distribution<std::size_t> d(action_probs.begin(), action_probs.end());
    return d(generator);
}
