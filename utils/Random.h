#ifndef RANDOM
#define RANDOM
#pragma once
#include<random>

template<typename T>
T random(T min, T max) {
    static std::random_device rnd;
    static std::mt19937 gen(rnd());
    if constexpr (std::is_integral_v<T>) {
        std::uniform_int_distribution<T> dist(min, max);
        return dist(gen);
    } else {
        std::uniform_real_distribution<T> dist(min, max);
        return dist(gen);
    }
}

#endif
