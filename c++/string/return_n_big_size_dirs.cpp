#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct row {
    string name;
    uint32_t size;
    vector<string> dirs;
};

vector<string> return_n_dirs(vector<row>& rows, int n)
{
    unordered_map<string, int> dir_map;
    vector<string> result;

    for (const auto& row : rows)
    {
        for (const auto& dir : row.dirs)
        {
            // cout << dir << ":" << row.size << endl;
            dir_map[dir] += row.size;
        }
    }

    // for (auto& map: dir_map)
    // {
    //     cout << map.first << ":" << map.second << endl;
    // }

    vector<pair<string, int>> vec(dir_map.begin(), dir_map.end());
    sort(vec.begin(), vec.end(),
        [](const pair<string, int>& a, const pair<string, int>& b) {
        // sort in descending order by size
        return a.second > b.second;
    });

    // for (auto& v: vec)
    // {
    //     cout << v.first << ":" << v.second << endl;
    // }

    for (int i=0; i < n; ++i)
    {
        result.push_back(vec[i].first);
    }

    return result;
}

int main()
{
    vector<row> rows{
                        {"file1", 200, {"dir1", "dir2", "dir3"}},
                        {"file2", 100, {"dir2", "dir3"}},
                        {"file3", 150, {"dir1", "dir3"}},
                        {"file4", 200, {"dir3"}},
                        {"file5", 100, {}}
                    };

    vector<string> dirs = return_n_dirs(rows, 2);

    for (const auto& dir: dirs)
        cout << dir << endl;

    return 0;
}
