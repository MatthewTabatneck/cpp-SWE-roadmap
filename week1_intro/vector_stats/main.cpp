#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <limits>
#include <tuple>

std::tuple<int, int, double> compute_stats(const std::vector<int>& nums) {
    int minVal = *std::min_element(nums.begin(), nums.end());
    int maxVal= *std::max_element(nums.begin(), nums.end());
    double avg = std::accumulate(nums.begin(), nums.end(), 0.0) / nums.size();
    return {minVal, maxVal, avg};
}

int main() {
    std::fstream file("data.txt");
    if (!file) {
        std::cerr << "Failed to open file,\n";
        return 1;
    }

    std::vector<int> numbers;
    int num;
    while (file >> num) {
        numbers.push_back(num);
    }

    if (numbers.empty()) {
        std::cout << "No data.\n";
        return 0;
    }

    auto [minVal, maxVal, avg] = compute_stats(numbers);

    std::cout << "Count : " << numbers.size() << "\n";
    std::cout << "Min: " << minVal << "\n";
    std::cout << "Max: " << maxVal << "\n";
    std::cout << "Average: " << avg << "\n";

    return 0;
}


