#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    // Example of unordered_set
    unordered_set<int> myset = {2, 1, 4, 3, 5, 6, 4};
    for (auto it = myset.begin(); it != myset.end(); ++it) {
        cout << *it << " ";
    }
    // Output: 1 2 3 4 5 6

    // Example of unordered_map
    unordered_map<string, int> mymap = {{"apple", 2}, {"banana", 3}, {"orange", 4}};
    mymap["apple"] = 5;
    for (auto it = mymap.begin(); it != mymap.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }
    // Output: apple: 5
    //         banana: 3
    //         orange: 4

    return 0;
}
