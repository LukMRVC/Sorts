#include <iostream>
#include <functional>
#include <thread>
#include "sorts.cpp"
#include <ctime>
#include <cstdlib>

int main() {
    std::cout << "Hello, World!" << std::endl;
    srand(time(nullptr));
    const int N = 10;
    int * arr = new int[N];
    for (int i = 0; i < N; ++i)
        arr[i] = rand() % 100;

    for (int i = 0; i < N; ++i)
        std::cout << arr[i] << "\t";

    std::cout << std::endl;

    auto sorted1 = bubble_sort(arr, N);
    for (int i = 0; i < N; ++i)
        std::cout << sorted1[i] << "\t";

    std::cout << std::endl;

    auto sorted2 = insertion_sort(arr, N);
    for (int i = 0; i < N; ++i)
        std::cout << sorted2[i] << "\t";

    std::cout << std::endl;

    auto sorted3 = selection_sort(arr, N);
    for (int i = 0; i < N; ++i)
        std::cout << sorted3[i] << "\t";

    std::cout << std::endl;

    delete sorted1;
    sorted1 = nullptr;

    delete sorted2;
    sorted2 = nullptr;

    delete sorted3;
    sorted3 = nullptr;
    return 0;
}