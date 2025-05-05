#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <limits>

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

    int minVal = *std::min_element(numbers.begin(), numbers.end());
    int maxVal= *std::max_element(numbers.begin(), numbers.end());
    double avg = std::accumulate(numbers.begin(), numbers.end(), 0.0) / numbers.size();

    std::cout << "Count : " << numbers.size() << "\n";
    std::cout << "Min: " << minVal << "\n";
    std::cout << "Max: " << maxVal << "\n";
    std::cout << "Average: " << avg << "\n";

    return 0;
}


