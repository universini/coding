#ifndef HIKE_MAIN_HH
#define HIKE_MAIN_HH

#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<algorithm>

#define MAX(a, b)	((a) > (b) ? (a) : (b))

using namespace std;

struct input_data {
    unsigned int iteration_num;
    unsigned int hikers_count;
    double bridge_len;
    vector<double> hiker_speed;
    vector<double> walking_time;
};

class situation {
    public:
        set<double> left_side;
        set<double> right_side;
        bool is_torch_left; // left:true right:false
        double minutes_spent;
};

extern double total_time_taken;

/*
 * externs
 */
extern void bridge_crossing_time_compute(input_data *);

#endif /* HIKE_MAIN_HH */
