#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "compute_stats.h"

int main() {
    auto start_total = std::chrono::high_resolution_clock::now();

    auto start_read = std::chrono::high_resolution_clock::now();

    std::fstream file("data.txt");
    if (!file) {
        std::cerr << "Failed to open file,\n";
        return 1;
    }

    std::vector<int> numbers;
    numbers.reserve(310); 

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

auto end_read = std::chrono::high_resolution_clock::now();
auto read_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_read - start_read).count();
std::cout << "[Time] FIle Read: " << read_duration << " µs\n";

    if (numbers.empty()) {
        std::cout << "No data.\n";
        return 0;
    }

    auto start_stats = std::chrono::high_resolution_clock::now();

    auto [minVal, maxVal, avg] = compute_stats(numbers);

    auto end_stats = std::chrono::high_resolution_clock::now();
    auto stats_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_stats - start_stats).count();
    std::cout << "[Time] Stat calculation: " << stats_duration << " µs\n";

    std::cout << "Count : " << numbers.size() << "\n";
    std::cout << "Min: " << minVal << "\n";
    std::cout << "Max: " << maxVal << "\n";
    std::cout << "Average: " << avg << "\n";

    auto end_total = std::chrono::high_resolution_clock::now();
    auto total_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_total - start_total).count();
    std::cout << "[Time] Total program: " << total_duration << " µs\n";

    return 0;
}


