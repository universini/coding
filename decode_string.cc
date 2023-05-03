#include <iostream>
#include <string>

std::string encode_str(const std::string& str)
{
    int len = str.length();
    int count = 0;
    char c = ' ';
    std::string result = "";

    for (int i = 0; i < len; i++)
    {
        if (c != str[i])
        {
            c = str[i];
        }

        if (str[i + 1] == c)
        {
            count++;
            continue;
        }

        result += std::to_string(count) + str[i];
    }

    return result;
}

int main(void)
{
    std::string s("aaaaaaaaaaaaaaaaaaabbcdddddeffff");

    std::cout << "encoded string: " << encode_str(s) << std::endl;
    return 0;
}
