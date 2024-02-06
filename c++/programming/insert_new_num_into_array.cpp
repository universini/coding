#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> myVector = {10, 20, 30, 40, 50};
    
    int newNumber = 25; // The integer you want to insert
    int lowerBound = 20; // Lower bound of the range
    int upperBound = 30; // Upper bound of the range

    auto it = std::find_if(myVector.begin(), myVector.end(), [lowerBound, upperBound](int num) {
        return num > lowerBound; // && num < upperBound;
    });

    myVector.insert(it, newNumber);

    // Print the vector after insertion
    for (int num : myVector) {
        std::cout << num << " ";
    }

    return 0;
}
