#include "compute_stats.h"
#include <algorithm>
#include <numeric>

std::tuple<int, int, double> compute_stats(const std::vector<int>& nums) {
    int minVal = *std::min_element(nums.begin(), nums.end());
    int maxVal= *std::max_element(nums.begin(), nums.end());
    double avg = std::accumulate(nums.begin(), nums.end(), 0.0) / nums.size();
    return {minVal, maxVal, avg};
}