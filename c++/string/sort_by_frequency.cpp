#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

string frequencySort(string s) {
    // Create a frequency map for characters in the string
    unordered_map<char, int> frequencyMap;
    for (char c : s) {
        frequencyMap[c]++;
    }

    // Create a vector of pairs to store characters and their frequencies
    vector<pair<char, int>> charFrequencyVector;
    for (const auto& entry : frequencyMap) {
        charFrequencyVector.push_back(entry);
    }

    // Sort the vector based on character frequency in descending order
    sort(charFrequencyVector.begin(), charFrequencyVector.end(), 
         [](const pair<char, int>& a, const pair<char, int>& b) {
             return a.second > b.second; 
         });

    // Construct the result string based on sorted characters and their frequencies
    string result;
    for (const auto& entry : charFrequencyVector) {
        result += string(entry.second, entry.first);
    }

    return result;
}

int main() {
    string input = "tree";
    cout << "Original string: " << input << endl;
    cout << "Sorted by frequency: " << frequencySort(input) << endl;

    return 0;
}
