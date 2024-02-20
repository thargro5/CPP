// From Goodrich, Tamassia, and Mount
// Homework
/*
Write a short C++ program that takes two arguments of type STL vec-
tor<double>, a and b, and returns the element-by-element product of a
and b. That is, it returns a vector c of the same length such that c[i] =
a[i] · b[i].
*/
#include <iostream>
#include <vector>
std::vector<double> vecProduct(const std::vector<double>& v1, const
std::vector<double>& v2) {

//vec product is designed above to hold two vectors 
  if (v1.size() !=  v2.size()) {
        std::cout << "Vectors must be of the same length." << std::endl;
        return {};//this exits the program if the vectors are different 
    }
// Return empty vector if v1 and v2 are of different sizes;
//add a third vector to hold the product of the 2 vectors 
std::vector<double> v3;
    v3.reserve(v1.size()); //this puts reserves memory for the elements inserted into the vector in this case creating a vector v3 the size of v1
  for (size_t i = 0; i < v1.size(); ++i) {
        v3.push_back(v1[i] * v2[i]);//inserts the product of v1 and v2 into v3 vector, looping through the enitre vector of v1:v2 
    }

    return v3;

}

// Overload << operator to print std::vector
std::ostream& operator <<(std::ostream& os, const std::vector<double>& v) {
for (int i = 0; i < v.size(); i++) {
	os << v.at(i) << " ";
	}
	os << std::endl;
	return os;
}
// Test
int main() {
// Test 1
std::vector<double> v1{1.0, 2.0, 3.0};
std::vector<double> v2{4.0, 5.0, 6.0};
std::vector<double> v3 = vecProduct(v1, v2);
std::cout << v3; // Should print 4, 10, 18
// Test 2
std::vector<double> v4{42.0};
std::cout << vecProduct(v1, v4); // Should print empty vector
}