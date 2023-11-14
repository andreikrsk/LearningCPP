//
// Created by Andrei Kiryieuski on 14/11/2023.
//
#include <iostream>

consteval int greater(int x, int y) // function is now consteval
{
    return (x > y ? x : y);
}

void evalConstevalFun() {
    constexpr int g{greater(5, 6)};              // ok: will evaluate at compile-time
    std::cout << g << '\n';

    std::cout << greater(5, 6) << " is greater!\n"; // ok: will evaluate at compile-time

    int x{5}; // not constexpr
    std::cout << greater(x, 6) << " is greater!\n"; // error: consteval functions must evaluate at compile-time
}
//C++20 introduces the keyword consteval, which is used to indicate that a function must evaluate at compile-time,
// otherwise a compile error will result. Such functions are called immediate functions.