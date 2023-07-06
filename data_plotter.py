import matplotlib.pyplot as plt
import numpy as np

if __name__ == "__main__":
    optimal_actions_eg_nonstationary = np.loadtxt("cmake-build-debug/optimal_actions_eg_nonstationary.txt")
    optimal_actions_eg_stationary = np.loadtxt("cmake-build-debug/optimal_actions_eg_stationary.txt")
    optimal_actions_alpha_nonstationary = np.loadtxt("cmake-build-debug/optimal_actions_alpha_nonstationary.txt")
    optimal_actions_alpha_stationary = np.loadtxt("cmake-build-debug/optimal_actions_alpha_stationary.txt")

    plt.plot(optimal_actions_eg_nonstationary, label='E.G. changing')
    plt.plot(optimal_actions_eg_stationary, label="E.G. constant")
    plt.plot(optimal_actions_alpha_nonstationary, label="Alpha changing")
    plt.plot(optimal_actions_alpha_stationary, label="Alpha constant")
    # plt.plot(rewards)

    ax = plt.gca()
    ax.set_ylim([0, 1])
    ax.legend()

    plt.show()
