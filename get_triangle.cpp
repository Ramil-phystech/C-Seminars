#include <iostream>
#include <algorithm>

void get_triangle(int n) {
    for (int i = 0; i < 2 * n - 1; ++i) {
        for (int j = 0; j <= std::min(i, std::abs(2 * n - 1 - i - 1)); ++j) {
            std::cout << "*";
        }
        if (i < 2 * n - 2)
            std::cout << std::endl;
    }
};

int main()
{
    int c;
    std::cin >> c;
    get_triangle(c);
}