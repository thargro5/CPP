#include <iostream>
#include <queue>
#include <vector>


std::vector<double> findMedian(std::vector<int>& data) {
    std::priority_queue<int> max_heap; // Max-heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap; // Min-heap
    std::vector<double> res;

    for (int num : data) {
        // Add the number to the appropriate heap
        if (max_heap.empty() || num <= max_heap.top()) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }

        // Balance the heaps so that their sizes differ by at most 1
        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

        // Calculate the current median and store it in the result vector
        if (max_heap.size() == min_heap.size()) {
            res.push_back((max_heap.top() + min_heap.top()) / 2.0);
        } else {
            res.push_back(max_heap.top());
        }
    }

    return res;
}

int main() {
    std::vector<int> data_stream = {5, 42, 29, 85, 95, 99, 2, 15};
    std::vector<double> median_stream = findMedian(data_stream);
    for (auto ele : median_stream) {
        std::cout << ele << " ";
    }
    std::cout << std::endl;
    return 0;
}
