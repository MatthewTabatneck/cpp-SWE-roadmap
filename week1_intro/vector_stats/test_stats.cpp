#include <iostream>
#include <vector>
#include <cassert>
#include "compute_stats.h"

void test_basic_stats() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    auto [minVal, maxVal, avg] = compute_stats(data);
    assert(minVal == 1);
    assert(maxVal == 5);
    assert(avg == 3.0);
}

void test_negative_numbers() {
    std::vector<int> data = {-10, -5, 0, 5, 10};
    auto [minVal, maxVal, avg] = compute_stats(data);
    assert(minVal == -10);
    assert(maxVal == 10);
    assert(avg == 0.0);
}

int main() {
    test_basic_stats();
    test_negative_numbers();
    std::cout << "All tests passed!\\n";
    return 0;
}