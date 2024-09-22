#include <iostream>

int Det(double* a, int c) {
    int d = 1;
        
    for (int k = 0; k < c - 1; k++) {
        for (int i = k + 1; i < c; ++i) {
            if (a[k * c + k] != 0) {
                double f = - a[i * c + k] / a[k * c + k];
                for (int j = 0; j < c; ++j) {
                    a[i * c + j] += a[k * c + j] * f;
                };
            };

        };
    };

    for (int i = 0; i < c; ++i) {
        d *= a[i * c + i];
    };
    delete[] a;
    return d;
};

int main()
{   
    int c;
    std::cout << "Введите размер массива";
    std::cin >> c;
    double* p = new double[c * c];

    for (int i = 0; i < c * c; ++i) {
        std::cin >> p[i];
    };

    std::cout << Det(p, c);

    return 0;
}