// Copyright (c) 2025. Joseph Wondimagnehu. All rights reserved.
//
// Created by: Joseph Wondimagnehu
// Date: May 22, 2025
/* This program generates and displays
ten random numbers from 0 to 100 with
arrays and then displays the maximum number. */

/* Include the time header to access
time functions. */
#include <time.h>
/* Include the array library for
special arrays. */
#include <array>
/* Include the iostream library for
input and output functionalities. */
#include <iostream>
/* Include the random library
for random generators. */
#include <random>

/* Declare a template for the size of
any array to use it in the parameter. */
template<size_t N>
/* Define a function to get the maximum
number out of a number array. */
int findMaxValue(std::array<int, N> numArray) {
    /* Initialize the current maximum
    number to zero to use it later. */
    int currentMaxValue = 0;

    /* Use a for loop to loop over
    the length of the list. */
    for (int index = 0; index < numArray.size(); index++) {
        /* Check if the indexed number is greater
        than the current maximum number. */
        if (numArray[index] > currentMaxValue) {
            /* Set the current maximum value
            to the indexed number. */
            currentMaxValue = numArray[index];
        }
    }
    // Return the resulting maximum value.
    return currentMaxValue;
}

// Runs the main function.
int main() {
    // Display an empty space to format text.
    std::cout << "\n";
    // Set the constant maximum array size to 10.
    const int MAX_ARRAY_SIZE = 10;
    // Set the constant minimum random number to 0.
    const int MIN_NUM = 0;
    // Set the constant maximum random number to 100.
    const int MAX_NUM = 100;

    /* Initialize an array of
    integers to be used later. */
    std::array<int, MAX_ARRAY_SIZE> arrayOfInt;

    /* Use a for loop to loop over the maximum array
    size to generate the ten random numbers. */
    for (int index = 0; index < MAX_ARRAY_SIZE; index++) {
        // Set a random device to construct the engine.
        std::random_device randomDevice;
        /* Use the mersenne twister
        for high-quality randomizing. */
        std::mt19937 randomGen(randomDevice());
        /* Uniformly distribute the possible integers
        over a distance of the minimum number possible, 0,
        to the maximum number possible, 100. */
        std::uniform_int_distribution<int> intDist(MIN_NUM, MAX_NUM);

        // Set the random number to the generated integer.
        int randomNumber = intDist(randomGen);
        // Populate the array by inserting the random number.
        arrayOfInt[index] = randomNumber;

        /* Display information about the random
        number and its current position. */
        std::cout << randomNumber
        << " added to the array at position "
        << index << ".\n";
    }

    /* Determine the maximum number by assigning
    it to the maximum value function. */
    int maxNumber = findMaxValue(arrayOfInt);
    // Display the maximum number.
    std::cout << "\nThe max value is: "
    << maxNumber << ".\n\n";
}
