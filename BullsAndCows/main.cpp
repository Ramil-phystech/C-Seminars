#include <iostream>
#include <ctime>
#include "functions.h"



bool flag = true;
int main() {
    while (flag) {
        srand(time(0));
        std::vector<int> secretNumber = genSecretNumber();
        std::vector<std::vector<int>> all_combinations = generate_all_combinations();
        std::vector<std::vector<int>> true_comb = generate_all_combinations();
        std::vector<int> computerGuess;

        std::cout << "Welcome to Bulls and Cows game!" << std::endl;
        std::cout << "Enter the number for Computer: " << std::endl;
        std::vector<int> secretNumberForComp = getUserNumber_forComp();

        std::cout << "Try to guess the 4-digit number." << std::endl;

        int bulls = 0;
        int cows = 0;

        int bulls_comp = 0;
        int cows_comp = 0;

        do {
            std::vector<int> userNumber = getUserNumber();
            bulls = countBulls(secretNumber, userNumber);
            cows = countCows(secretNumber, userNumber);

            if (bulls == 4) {
                std::cout << "You guessed the number!" << std::endl;
            } else {
                std::cout << "Bulls: " << bulls << ", Cows: " << cows << std::endl;
                std::cout << "Computer Number: ";
                computerGuess = true_comb.front();
                std::vector<std::vector<int>> filt_comb;

                for (int i: computerGuess) {
                    std::cout << i;
                }

                bulls_comp = countBulls(secretNumberForComp, computerGuess);
                cows_comp = countCows(secretNumberForComp, computerGuess);

                for(const std::vector<int>& number: true_comb) {
                    if ((bulls_comp == countBulls(number, computerGuess)) &&
                        (cows_comp == countCows(number, computerGuess))) {
                        filt_comb.push_back(number);
                        }
                }

                true_comb = filt_comb;

                std::cout << std::endl;
                std::cout << " Bulls Comp: " << bulls_comp << ", Cows Comp: " << cows_comp << std::endl;
                std::cout << std::endl;
            }
        } while (bulls != 4 and bulls_comp != 4);
        if (bulls_comp == 4) {
            std::cout << "You lose! The computer won!" << std::endl;
            std::cout << "Your secret number: ";
            for (int i: secretNumber) {
                std::cout << i;
            }
        }
        std::cout << std::endl;
        std::cout << "Do you want to continue the game?(0/1)" << std::endl;

        int c;
        std::cin >> c;

        switch (c) {
            case 1:
                std::cout << "OK!" << std::endl;
                flag = true;
                break;
            case 0:
                std::cout << "Goodbye!" << std::endl;
                flag = false;
                break;
        }
    }
    return 0;
}
