#include <iostream>
#include <map>
#include <sstream>
#include <vector>

std::string wordsToNumerical(const std::string &words) {
    // Define a map to map words to their numerical values
    std::map<std::string, int> wordMap = {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
    };

    // Tokenize the input string by spaces
    std::istringstream iss(words);
    std::string token;
    std::vector<std::string> tokens;
    while (iss >> token) {
        tokens.push_back(token);
    }

    // Convert words to numerical figures
    std::string result;
    for (const auto &word : tokens) {
        auto it = wordMap.find(word);
        if (it != wordMap.end()) {
            result += std::to_string(it->second);
        } else {
            // If the word is not found in the map, keep it as is
            std::cout << "word: " << word << std::endl;
            result += word;
        }
        result += " ";
    }

    return result;
}

int main() {
    std::string words = "one two three four five";
    std::cout << "Words: " << words << std::endl;
    std::cout << "Numerical: " << wordsToNumerical(words) << std::endl;
    return 0;
}
