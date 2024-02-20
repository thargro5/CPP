#include <iostream>
#include <stdexcept>

class MyVector {
private:
    int* data;
    int capacity;
    int length;

public:
    // Default constructor
    MyVector() : data(nullptr), capacity(0), length(0) {}

    // Constructor with size input
    MyVector(int sz) : data(new int[sz]), capacity(sz), length(0) {}

    // Copy constructor
    MyVector(const MyVector& vin) : data(new int[vin.capacity]), capacity(vin.capacity), length(vin.length) {
        for (int i = 0; i < length; ++i) {
            data[i] = vin.data[i];
        }
    }

    // Destructor
    ~MyVector() {
        delete[] data;
    }

    // Appends to end of array
    void pushBack(int ele) {
        if (length == capacity) {
            int newCapacity = capacity == 0 ? 1 : capacity * 2; //(capacity == 0) checks if capacity is zero if true assigns 1, if false doubles the capacity
            int* newData = new int[newCapacity];
            for (int i = 0; i < length; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        data[length++] = ele;
    }

    // Inserts to i-th position in array
    void insert(int i, int ele) {
        if (i < 0 || i > length) {
            throw std::out_of_range("Index out of range1");
        }

        if (length == capacity) {
             int newCapacity = capacity == 0 ? 1 : capacity * 2;
            int* newData = new int[newCapacity];
            for (int j = 0; j < i; ++j) {
                newData[j] = data[j];
            }
            newData[i] = ele;
            for (int j = i; j < length; ++j) {
                newData[j + 1] = data[j];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
        } else {
            for (int j = length; j > i; --j) {
                data[j] = data[j - 1];
            }
            data[i] = ele;
        }

        ++length;
    }

    // Reads the i-th element
    int at(int i) const {
        if (i < 0 || i >= length) {
            throw std::out_of_range("Index out of range2");
        }
        return data[i];
    }

    // Overloaded [] operator
    int operator[](int i) const {
        return at(i);
    }

    // Deletes the i-th element
    void erase(int i) {
        if (i < 0 || i >= length) {
            throw std::out_of_range("Index out of range3");
        }

        for (int j = i; j < length - 1; ++j) {
            data[j] = data[j + 1];
        }

        --length;
    }

    // Returns the number of elements
    int size() const {
        return length;
    }

    // Returns true if empty else false
    bool empty() const {
        return length == 0;
    }
};

int main() {
    MyVector v1;
    MyVector v2(5);

    for (int i = 0; i < 5; ++i) {
        v2.pushBack(i * 2);
    }

    MyVector v3 = v2;
    v3.pushBack(12);
    v3.erase(4);
  //  v1.insert(9, 1);
   // std::cout << v1.at(1) << " ";
    std::cout << "v2 elements: ";
    for (int i = 0; i < v2.size(); ++i) {
        std::cout << v2[i] << " ";
    }
    std::cout << '\n';
    
    v2.erase(3);//deletes the number 
    
     std::cout << "v2 elements after delete: ";
    for (int i = 0; i < v2.size(); ++i) {
        std::cout << v2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "v3 elements: ";
    for (int i = 0; i < v3.size(); ++i) {
        std::cout << v3.at(i) << " ";
    }
    std::cout << '\n';
    
    v3.insert(5, 9);

    std::cout << "v3 elements after insert: ";
    for (int i = 0; i < v3.size(); ++i) {
        std::cout << v3.at(i) << " ";
    }
    std::cout << '\n';
    
    std::cout<< "V3 size: " <<v3.size() <<'\n';
   
    std::cout << std::endl;

    return 0;
}

