#include <iostream>
#include <string>

using namespace std;

string encode_string(const string& str)
{
    string result = "";
    int len = str.length();
    int count = 0;
    char ch = ' ';

    for (int i=0; i<len; i++)
    {
        if (isalpha(str[i]) && str[i] != ch)
        {
            ch = str[i];
            count++;
        }

        if (str[i+1] == ch)
        {
            count++;
            continue;
        }

        cout << "character: " << ch << " count: " << count << endl;
        result += to_string(count) + ch;
        count = 0;
    }

    return result;
}

int main(void)
{
    string str("aaaaaaaaaaaaaaaaaaabbcdddddeffff");
    string res = encode_string(str);

    cout << "encoded string: " << res << endl;
    return 0;
}