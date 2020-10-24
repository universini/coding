#include "hike_main.h"

double total_time_taken;

void bridge_crossing_time_compute(input_data *indata)
{
    priority_queue<situation*> q;
    situation *s = new situation;

    /*
     * Populate time taken into ordered set. In the beginning
     * everyone is on left side. Torch is also left side.
     */
    s->is_torch_left = true;
    s->minutes_spent = 0;

    for (auto &x : indata->walking_time)
    {
        s->left_side.insert(x); //sorted
    }

    q.push(s);

    while (!q.empty())
    {
        s = q.top();
        q.pop();

#ifdef DEBUG_HIKE
        cout << "  Situation ifno:" << endl;
        cout << "    Torch position: " << s->is_torch_left << endl;
        cout << "    Minutes spent: " << s->minutes_spent << endl;
		cout << "    Hikers: ";
        for (auto x : s->left_side) cout << x << " "; cout << endl;
#endif

        /*
         * When everyone moved to right side
         */
        if (s->left_side.empty())
        {
            cout << "Time taken in iteration-" <<
                    indata->iteration_num << " is: " <<
                    s->minutes_spent << " minutes" << endl;
            total_time_taken += s->minutes_spent;
            break;
        }

        set<double> st = s->is_torch_left ? s->left_side : s->right_side;

        /* Moving two hikers */
        for (auto it2 = st.begin(); it2 != st.end(); ++it2)
        {
            for (auto it3 = it2; it3 != st.end(); ++it3)
            {
                // skip first index in inner loop
                if (it2 == it3) continue;

                situation *t = s;

                if (t->is_torch_left) // left case
                {
                    // removing hiker moving from left to right
                    t->left_side.erase(*it2);
                    t->left_side.erase(*it3);
                    t->right_side.insert(*it2);
                    t->right_side.insert(*it3);
                }

                t->minutes_spent += MAX(*it2, *it3);

                /*
                 * Now add the time of moved hikers
                 */
                s->minutes_spent = t->minutes_spent;
                t->is_torch_left = !t->is_torch_left;
                break;
            }
        }

        /* Moving one hiker */
        for (auto it1 = st.begin(); it1 != st.end(); ++it1)
        {
            situation *t = s;

            if (t->is_torch_left) // left case
            {
                // removing hiker moving from right to left
                t->right_side.erase(*it1);
                t->left_side.insert(*it1);
            }

            t->minutes_spent += *it1;

            /*
             * Now add the time of moved hikers and reset torch position
             */
            s->minutes_spent = t->minutes_spent;
            t->is_torch_left = !t->is_torch_left;
            break;
        }
    }

    cout << "Time taken in iteration-" <<
            indata->iteration_num << " is: " <<
            s->minutes_spent << " minutes" << endl;
    total_time_taken += s->minutes_spent;

    delete(s);
    return;
}

