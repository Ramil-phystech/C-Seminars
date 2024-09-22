#include <iostream>
#include <locale.h>


void HanoiTowers(int n, int i, int k) {
    if (n == 1) {
        std::cout << "Переместить диск 1 со стержня " << i << " на стержень " << k << std::endl;
        return;
    }
    int temp = 6 - i - k;
    HanoiTowers(n - 1, i, temp);
    std::cout << "Переместить диск " << n << " со стержня " << i << " на стержень " << k << std::endl;
    HanoiTowers(n - 1, temp, k);
};

int main()
{
    setlocale(LC_ALL, "Russian");
    int n, q;
    std::cout << "Введите высоту башни" << std::endl;
    std::cin >> n;

    std::cout << "Введите номер стержня, на который требуется переложить башню(2/3)" << std::endl;
    std::cin >> q;

    HanoiTowers(n, 1, q);

    return 0;
}
