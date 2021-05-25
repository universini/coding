#include "bridge.h"
#include "yaml-cpp/yaml.h"

double total_time_taken;

Bridge *Bridge::inst = NULL;

Bridge *Bridge::get_instance() {
  if (inst == NULL) {
    inst = new Bridge();
  }
  return (inst);
}

static void update_set(set<double> &s, double val, bool add) {
  if (add) {
    s.insert(val);
  } else {
    s.erase(val);
  }
}

void bridge_crossing_time_compute(Data *data_p) {
  Bridge *B = B->get_instance();

  // CLear old times if set any
  B->clear_minutes();
  // Set torch postion to default value which is 0
  B->torch_position = false;
  // Calculate hikers time
  for (auto &x : data_p->hikers_speed) {
    double time = data_p->bridge_len / x;
    B->set_hikers_time(time);
  }

#ifdef DEBUG_HIKE
  cout << endl;
  cout << "  Iteration number: " << data_p->iteration_num << endl;
  cout << "  Hikers count: " << data_p->num_hikers << endl;
  cout << "  Bridge length: " << data_p->bridge_len << endl;
  cout << "  Hiker speed: ";
  for (auto x : data_p->hikers_speed) cout << x << " ";
  cout << "\n";
  cout << "  Walking time: ";
  for (auto x : B->get_hikers_time()) cout << x << " ";
  cout << endl;
#endif

  set<double> lset = B->get_hikers_time();
  set<double> rset = {};
  bool before_last_batch = false;
  double last;

  while (lset.size() != 0) {
    priority_queue<double> PQ;
    int left_count = 0;
    int right_count = 0;
    double min = 0.0;

    // 2 hikers move from left (always lowest moves)
    for (auto it = lset.begin(); it != lset.end(); ++it) {
      if (false == B->torch_position) {
        update_set(rset, *it, true);
        update_set(lset, *it, false);
        if (before_last_batch) {
          update_set(lset, last, true);
          before_last_batch = false;
        }
        PQ.push(*it);
        left_count++;
        if (left_count >= 2) break;
      }
    }

    B->torch_position = true;
    if (!PQ.empty()) B->set_minutes(PQ.top());
    min += PQ.top();
    while (!PQ.empty()) PQ.pop();

    // 1 hiker move from right (always lowest moves)
    for (auto it = rset.begin(); it != rset.end(); ++it) {
      if (true == B->torch_position) {
        if (lset.size()) {
          update_set(lset, *it, true);
          update_set(rset, *it, false);
          PQ.push(*it);
          right_count++;
        }
        if (right_count >= 1) break;
      }
    }

    /* When last 3 elements in the set, it contains
1 lowest and 2 higest values, so send two higer
elements and bring back lower one from the right
side. That would save time since last bacth would
contain 2 lowest values */
    if (lset.size() == 3) {
      before_last_batch = true;
      auto it = lset.begin();
      last = *it;
      lset.erase(*it);
      cout << "Last: " << *it << endl;
    }

    B->torch_position = false;
    if (!PQ.empty()) {
      B->set_minutes(PQ.top());
      min += PQ.top();
    }
    while (!PQ.empty()) PQ.pop();

#ifdef DEBUG_HIKE
    cout << "    Minutes: " << min << endl;
#endif
  }

  // Cleanup old iteration data
  lset.clear();
  rset.clear();
  B->clear_hikers_time();

  cout << "  Time taken to complete bridge " << data_p->iteration_num
       << " is: " << B->get_minutes() << " minutes" << endl;

  // Add time to total time
  total_time_taken += B->get_minutes();
}

static Data *data_p;

int main(void) {
  vector<YAML::Node> configs;
  vector<YAML::Node>::iterator it;
  /*
   * This can be exhanced to accept command line arguments
   */
  configs = YAML::LoadAllFromFile("input.yaml");

  for (auto &x : configs) {
    data_p = new Data;
    YAML::Node config;

    config = x["iteration"];
    /*
     * Here I am just following simple approach oherwise, this can be
     * enhanced to use try/catch/exceptions handing and other checks
     */
    data_p->iteration_num = config["case"].as<unsigned int>();
    data_p->num_hikers = config["num_hikers"].as<unsigned int>();
    data_p->bridge_len = config["bridge_length"].as<double>();
    data_p->hikers_speed = config["walk_speed"].as<vector<double>>();

    /*
     * Hiker speed count should be equal to hiker count. Check
     */
    if (data_p->hikers_speed.size() != data_p->num_hikers) {
      cerr << "ERROR: count mismatch" << endl;
      exit(0);
    }

    /*
     * Now, calculate minimum time taken by each iteration
     */
    bridge_crossing_time_compute(data_p);

    /*
     * Clear old data for next iteration
     */
    data_p->hikers_speed.clear();
    delete (data_p);
  }

  cout << "\nTotal time taken to cross all the bridges is: " << total_time_taken
       << " minutes" << endl
       << endl;
  return (0);
}
