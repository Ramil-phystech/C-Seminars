#include <vector>
#include <string>

std::vector<int> genSecretNumber();
std::vector<int> getUserNumber();
std::vector<int> getUserNumber_forComp();
int countBulls(const std::vector<int>& secretNumber, const std::vector<int>& userNumber);
int countCows(const std::vector<int>& secretNumber, const std::vector<int>& userNumber);
std::vector<int> CompGuess();
std::vector<std::vector<int>> generate_all_combinations();
bool isValidInput(const std::string &input);
bool isValidInput_forComp(const std::string &input);
bool isUnique(std::string str);