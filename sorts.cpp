//
// Created by Lukas on 04.11.2019.
//
#include <functional>

template <typename T>
T * copyArray(const T * from, unsigned int len, unsigned int fromIdx = 0) {
    T * newArray = new T[len];

    for (int i = fromIdx; i <  fromIdx + len; ++i) {
        newArray[i] = from[i];
    }
    return newArray;
}

template <typename T>
T * bubble_sort(const T * array, unsigned int len, unsigned int from = 0,
        std::function<bool(T, T)> comparator = [](T a, T b) -> bool { return a > b; } ) {
    auto newArray = copyArray(array, len, from);

    for (int i = from; i < from + len - 1; ++i) {
        for (int j = from; j < (from + len) - i - 1; ++j) {
            if (comparator(newArray[j + 1], newArray[j])) {
                int tmp = newArray[ j + 1 ];
                newArray[ j + 1 ] = newArray[j];
                newArray[j] = tmp;
            }
        }
    }
    return newArray;
}

template <typename T>
T * selection_sort(const T * array, unsigned int len, unsigned int from = 0,
        std::function<bool(T, T)> comparator = [](T a, T b) -> bool { return a > b; } ) {
    auto newArray = copyArray(array, len, from);


    for (int i = from; i < from + len - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < from + len; j++) {
            if (comparator(newArray[j], newArray[maxIndex])) maxIndex = j;
        }
        int tmp = newArray[i];
        newArray[i] = newArray[maxIndex];
        newArray[maxIndex] = tmp;
    }

    return newArray;
}

template <typename T>
T * insertion_sort(const T * array, unsigned int len, unsigned int from = 0,
                   std::function<bool(T, T)> comparator = [](T a, T b) -> bool { return a > b; } ) {
    auto newArray = copyArray(array, len, from);

    for (int i = from; i < from + len - 1; ++i) {
        int j = i + 1;
        int tmp = newArray[j];
        while ( j > 0 && comparator(tmp, newArray[j - 1])) {
            newArray[j] = newArray[j - 1];
            j--;
        }
        newArray[j] = tmp;
    }
    return newArray;
}