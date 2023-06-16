#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_distance(vector<int> distances,
                 int initial_energy,
                 int plus_energy,
                 int minus_energy)
{
    int max_distance = 0;

    for (int i = 0; i < distances.size(); i++)
    {
        if (initial_energy <= 0) break;

        if (distances[i] == 0)
        {
            initial_energy += plus_energy;
        }
        else
        {
            initial_energy -= minus_energy;
        }

        max_distance += distances[i];
    }

    return max_distance;
}

int main(void)
{
    vector<int> distances{20, 10, 0, 15, 5, 8, 0};
    int initial_energy = 3;
    int plus_energy = 1;
    int minus_energy = 1;

    int distance = max_distance(distances,
                                initial_energy,
                                plus_energy,
                                minus_energy);

    cout << "max distance sinbad travelled: " << distance << endl;

    sort(distances.begin(), distances.end(), greater<int>());
    // resort back in ascending order
    sort(distances.begin(), distances.end(), [](int a, int b)
    {
        return a < b;
    });

    cout << "sorted vector: " << endl;

    for (auto x : distances)
        cout << x << " ";
    cout << endl;
}
