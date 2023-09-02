#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void count_space_words(string& s, int& spaces, int& words)
{
    stringstream ss(s);
    string word;

    while (ss >> word)
    {
        words += 1;
    }

    spaces = words - 1;
}

int main(void)
{
    string s = "hello mister sidde gowda";
    int words = 0;
    int spaces = 0;

    count_space_words(s, spaces, words);

    cout << "words: " << words << endl;
    cout << "spaces: " << spaces << endl;

    return 0;
}