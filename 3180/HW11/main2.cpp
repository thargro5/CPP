#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

std::vector<int> targetIndices(const std::vector<int>& nums, int target) {
    std::vector<int> sortedIndices(nums.size());
    std::iota(sortedIndices.begin(), sortedIndices.end(), 0);

    // Sort indices based on corresponding values in nums
    std::sort(sortedIndices.begin(), sortedIndices.end(), [&nums](int a, int b) {
        return nums[a] < nums[b];
    });

    std::vector<int> result;
    for (int index : sortedIndices) {
        if (nums[index] == target) {
            result.push_back(index);
        }
    }

    return result;
}

int main() {
    // Example usage
    std::vector<int> nums = {1, 2, 5, 2, 3};
    int target = 2;

    std::vector<int> result = targetIndices(nums, target);

    // Output the result
    std::cout << "Output: [";
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
