#include <iostream>
#include <chrono>
#include <iomanip>


long long mult_count = 0;


unsigned long long rpower(unsigned long long x, int n) {
    if (n == 0) return 1;
    mult_count++;
    return x * rpower(x, n - 1);
}


unsigned long long brpower(unsigned long long x, int n) {
    if (n == 0) return 1;
    if (n % 2 == 1) {
        unsigned long long y = brpower(x, (n - 1) / 2);
        mult_count += 2;
        return x * y * y;
    } else {
        unsigned long long y = brpower(x, n / 2);
        mult_count += 1;
        return y * y;
    }
}


template <typename F>
double time_us(F f, int x, int n, int reps, long long &mults) {
    mult_count = 0;
    volatile unsigned long long sink = 0;
    auto begin = std::chrono::steady_clock::now();
    for (int i = 0; i < reps; i++) sink = f(x, n);
    auto end = std::chrono::steady_clock::now();
    mults = mult_count / reps;
    return std::chrono::duration<double, std::micro>(end - begin).count() / reps;
}


int main() {
    const int x = 3;


    std::cout << "3^10: rpower = " << rpower(x, 10)
              << ", brpower = " << brpower(x, 10) << "\n\n";


    std::cout << std::left << std::setw(10) << "n"
              << std::setw(16) << "rpower mults"
              << std::setw(18) << "rpower time(us)"
              << std::setw(16) << "brpower mults"
              << std::setw(18) << "brpower time(us)" << "\n";


    int sizes[] = {10, 100, 1000, 5000, 10000, 20000};
    for (int n : sizes) {
        long long rm, bm;
        double rt = time_us(rpower, x, n, 1000, rm);
        double bt = time_us(brpower, x, n, 1000, bm);
        std::cout << std::left << std::setw(10) << n
                  << std::setw(16) << rm
                  << std::setw(18) << std::fixed << std::setprecision(3) << rt
                  << std::setw(16) << bm
                  << std::setw(18) << bt << "\n";
    }
    return 0;
}
