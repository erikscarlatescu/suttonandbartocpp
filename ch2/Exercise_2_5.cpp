//
// Created by Scarlatescu, Erik on 7/5/23.
//

#include "Exercise_2_5.h"

#include <iostream>

#include "ArmedTestbedNonstationary.h"
#include "EpsilonGreedyAgent.h"

#include <fstream>

template <typename T>
void save_vector(const std::string& filename, const std::vector<T> vector) {
    std::ofstream outfile(filename);
    if (outfile.is_open()) {
        for (auto& element : vector) {
            outfile << element << '\n';
        }
        outfile.close();
        std::cout << "Successfully saved data to file" << std::endl;
    }
    else {
        std::cout << "Unable to save data to file" << std::endl;
    }
}

void update_q_function_sample_average(std::vector<double>& q_estimates, std::vector<int>& num_samples, double reward, int action) {
    q_estimates[action] += 1.0 / (num_samples[action] + 1) * (reward - q_estimates[action]);
    num_samples[action]++;
}

void update_q_function_const_alpha(std::vector<double>& q_estimates, std::vector<int>& num_samples, double reward, int action) {
    q_estimates[action] += 0.1 * (reward - q_estimates[action]);
    num_samples[action]++;
}

void Exercise_2_5::run() {
     int num_runs = 2000;
//    int num_runs = 1;
    int episode_length = 10000;

    std::vector<double> rewards(episode_length, 0.0);
    std::vector<double> optimal_actions(episode_length, 0.0);
    for (int run = 0; run < num_runs; run++) {
//        ArmedTestbed testbed(10, (run+7)*3);
        ArmedTestbedNonstationary testbed(10, (run+7)*3);
        EpsilonGreedyAgent agent_sample_avg(testbed, &update_q_function_sample_average, 0.1, (run+4)*5);
//        EpsilonGreedyAgent agent_sample_avg(testbed, &update_q_function_const_alpha, 0.1, (run+4)*5);

        if ((run-1) % 100 == 0) {
            std::cout << "Beginning run " << run << std::endl;
        }

        for (int i = 0; i < episode_length; i++) {
            int action = agent_sample_avg.choose_action();
            double reward = testbed.pull_lever(action);
            agent_sample_avg.update_q_function(reward, action);
            rewards[i] += reward / (1.0*num_runs);
            optimal_actions[i] += (action == testbed.get_max_action()) / (1.0*num_runs);
        }
    }

    std::cout << "We are done training the bandit" << std::endl;

    save_vector("rewards_out.txt", rewards);
    save_vector("optimal_actions_eg_nonstationary.txt", optimal_actions);
}
