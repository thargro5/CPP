#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target, int left, int right) {
    if (left > right) {
        // Element is not in the array
        return -1;
    }

    // Calculate the middle index
    int mid = left + (right - left) / 2; //this checks for overflow 
    //nromal median calculation would be right + left / 2: the reason to add left and subtracct instead is in case of overflow 
    //Adding left to this value gives you the actual index of the middle element
    //2 + (8 - 2)/2 --> 3 + 2= 5 gives the index of the middle value 2 3 4 5 6 7 8 
    //2 + (5 - 2)/2 --> 2 + 3/2 = 3 

    if (arr[mid] == target) {
        // Element found at the middle index
        return mid;
    } else if (arr[mid] > target) {
        // Search in the left subarray
        return binarySearch(arr, target, left, mid - 1);
    } else {
        // Search in the right subarray
        return binarySearch(arr, target, mid + 1, right);
    }
}

void print(int temp){
    if(temp != 1){
        std::cout << "Element found at index: " << temp << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 4, 5, 6, 7, 8, 9, 10};
    int target = 4;
    
    int notHere = 24;
    // target 4 
    int result = binarySearch(arr, target, 0, arr.size() - 1);
    print(result);
    //not in the array 24
    int result2 = binarySearch(arr, notHere, 0, arr.size() - 1);
    print(result2);
    

    return 0;
}
