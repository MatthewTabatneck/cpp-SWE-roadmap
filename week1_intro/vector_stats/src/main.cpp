#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "compute_stats.h"

int main() {
    // Timer for entire program
    auto start_total = std::chrono::high_resolution_clock::now();
    
    // Timer for reading the file
    auto start_read = std::chrono::high_resolution_clock::now();

    // Opens file and detects success
    std::fstream file("data.txt");
    if (!file) {
        std::cerr << "Failed to open file,\n";
        return 1;
    }

    // Initiates vector to store values from file and sets a known size
    std::vector<int> numbers;
    numbers.reserve(310); 

    // getline reads line-by-line to store each value individually as a string inside the temp var called line.
    // The loop will then check if the temp var is not empty, if so the string is converted to int and pushed into
    // the vector numbers. The catches throw error messages if there is a invalid number or if the parser is reaching out of range.
    std::string line;
    while (std::getline(file, line)) {
        try {
            if (!line.empty()) {
                numbers.push_back(std::stoi(line));
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid number: \"" << line << "\"\n";
        } catch ( const std::out_of_range& e) {
            std::cerr << "Number out of range: \"" << line << "\"\n";
        }
    }

    // Ends and prints file read timer
    auto end_read = std::chrono::high_resolution_clock::now();
    auto read_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_read - start_read).count();
    std::cout << "[Time] FIle Read: " << read_duration << " µs\n";

    // Checks and prints if the read file is empty
    if (numbers.empty()) {
        std::cout << "No data.\n";
        return 0;
    }

    // Starts a timer for calculations
    auto start_stats = std::chrono::high_resolution_clock::now();

    // calls a tuple in compute.cpp to calculate min, max, and avg
    auto [minVal, maxVal, avg] = compute_stats(numbers);

    // Ends calculation timer
    auto end_stats = std::chrono::high_resolution_clock::now();
    auto stats_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_stats - start_stats).count();
    std::cout << "[Time] Stat calculation: " << stats_duration << " µs\n";

    // Prints out calculated values
    std::cout << "Count : " << numbers.size() << "\n";
    std::cout << "Min: " << minVal << "\n";
    std::cout << "Max: " << maxVal << "\n";
    std::cout << "Average: " << avg << "\n";

    // Ends total runtime timer
    auto end_total = std::chrono::high_resolution_clock::now();
    auto total_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_total - start_total).count();
    std::cout << "[Time] Total program: " << total_duration << " µs\n";

    return 0;
}


