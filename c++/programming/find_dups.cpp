#include<iostream>
#include<map>
#include<vector>

using namespace std;

void find_dup(vector<int>& v)
{
    map<int, int> m;

    for(auto x : v)
    {
        if (m[x] == 1)
            cout << x << " ";
        m[x]++;
    }
}

int main(void)
{
    vector<int> v{10,20,30,30,40,50,50,60};
    find_dup(v);
    cout << endl;
    return 0;
}
