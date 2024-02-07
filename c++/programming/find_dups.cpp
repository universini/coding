#include<iostream>
#include<map>
#include<set>
#include<vector>

using namespace std;

void find_dup(const vector<int>& v)
{
    map<int, int> m;

    for(auto x : v)
    {
        if (m[x] == 1)
            cout << x << " ";
        m[x]++;
    }
}

void print_dup(const vector<int>& v)
{
    set<int> s;

    for(auto x : v)
    {
        if (s.find(x) != s.end())
            cout << x << " ";
        else
            s.insert(x);
    }
}

int main(void)
{
    vector<int> v{10,20,30,30,40,50,50,60};
    find_dup(v);
    cout << endl;
    print_dup(v);
    cout << endl;
    return 0;
}
