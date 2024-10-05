#include "functions.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<int> genSecretNumber() {
    std::vector<int> secretNumber;
    for (int i = 0; i < 4; i++) {
        int num = rand() % 10;
        while ((i == 0 and num == 0) or std::find(secretNumber.begin(), secretNumber.end(), num)  != secretNumber.end()) {
            num = rand() % 10;
        }
        secretNumber.push_back(num);
    }
    return secretNumber;
}

std::vector<int> getUserNumber_forComp() {
    std::string input;
    std::vector<int> userNumber_forComp;
    bool validInput = false;

    do {
        std::cout << "Enter 4-digit number: ";
        std::cin >> input;
        if (!isValidInput_forComp(input)) {
            std::cout << "Invalid input. enter a 4 digit number with different digits." << std::endl;
        } else {
            validInput = true;
            for (char& c : input) {
                userNumber_forComp.push_back(c - '0');
            }
        }
    } while (!validInput);
    return userNumber_forComp;
}

std::vector<int> getUserNumber() {
    std::string input;
    std::vector<int> userNumber;
    bool validInput = false;

    do {
        std::cout << "Enter 4-digit number: ";
        std::cin >> input;
        if (!isValidInput(input)) {
            std::cout << "Invalid input. Enter a 4-digit number digits." << std::endl;
        } else {
            validInput = true;
            for (char& c : input) {
                userNumber.push_back(c - '0');
            }
        }
    } while (!validInput);
    return userNumber;
}

int countBulls(const std::vector<int>& secretNumber, const std::vector<int> &userNumber) {
    int bulls = 0;
    for (int i = 0; i < 4; i++) {
        if (secretNumber[i] == userNumber[i]) {
            bulls++;
        }
    }
    return bulls;
}

int countCows(const std::vector<int> &secretNumber, const std::vector<int>& userNumber) {
    int cows = 0;
    for (int i = 0; i < secretNumber.size(); i++) {
        if (std::find(userNumber.begin(), userNumber.end(), secretNumber[i]) != userNumber.end()) {
            cows++;
        }
    }
    return cows - countBulls(secretNumber, userNumber);
}

std::vector<int> CompGuess() {
    return genSecretNumber();
}


bool isValidInput(const std::string &input) {
    if (input.length() != 4) {
        return false;
    }
    for (char c : input) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool isValidInput_forComp(const std::string &input) {
    if (input.length() != 4) {
        return false;
    }
    if(!isUnique(input)) {
        return false;
    }
    for (int i = 0; i < input.size(); ++i) {
        if (!isdigit(input[i])) {
            return false;
        }
    }
    return true;
}

bool isUnique(std::string str)
{
    for(size_t i = 0; i < (str.length() - 1); i++) {
        if(str.find(&str[i], i + 1, 1) != std::string::npos) {
            return false;
        }
    }
    return true;
}

std::vector<std::vector<int>> generate_all_combinations() {
    std::vector<std::vector<int>> all_combinations;

    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            for(int k = 0; k < 10; k++)
                for(int l = 0; l < 10; l++) {
                    std::vector<int> curr_comb = {i, j, k, l};
                    all_combinations.push_back(curr_comb);
    }

    return all_combinations;
}