//
// Created by Andrei Kiryieuski on 14/11/2023.
//

//TODO: Add const and/or constexpr to the following program
#include <iostream>

// gets height from user and returns it
double getTowerHeight() {
    std::cout << "Enter the height of the tower in meters: ";
    double towerHeight{};
    std::cin >> towerHeight;
    return towerHeight;
}

// Returns height from ground after "seconds" seconds
constexpr double calculateHeight(double towerHeight, int seconds) {
    constexpr double gravity{9.8};

    // Using formula: [ s = u * t + (a * t^2) / 2 ], here u(initial velocity) = 0
    const double distanceFallen{(gravity * (seconds * seconds)) / 2.0};
    const double currentHeight{towerHeight - distanceFallen};

    return currentHeight;
}

// Prints height every second till ball has reached the ground
void printHeight(double height, int seconds) {
    if (height > 0.0)
        std::cout << "At " << seconds << " seconds, the ball is at height: " << height << " meters\n";
    else
        std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

void calculateAndPrintHeight(double towerHeight, int seconds) {
    const double height{calculateHeight(towerHeight, seconds)};
    printHeight(height, seconds);
}

void runQ3() {
    const double towerHeight{getTowerHeight()};

    calculateAndPrintHeight(towerHeight, 0);
    calculateAndPrintHeight(towerHeight, 1);
    calculateAndPrintHeight(towerHeight, 2);
    calculateAndPrintHeight(towerHeight, 3);
    calculateAndPrintHeight(towerHeight, 4);
    calculateAndPrintHeight(towerHeight, 5);
}