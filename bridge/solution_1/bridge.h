#ifndef BRIDGE_H
#define BRIDGE_H

#include<iostream>
#include<queue>
#include<set>
#include<vector>

using namespace std;

#define DEBUG_HIKE

struct Data {
    unsigned int iteration_num;
   	unsigned int num_hikers;
    double bridge_len;
   	vector<double> hikers_speed;
};

class Bridge { // Singleton
	public:
		static Bridge* get_instance();

		bool torch_position;
		
		// Getters		
		double get_minutes(void){return minutes_spent;}
		set<double> get_hikers_time(){return hikers_time;}

		// Setters		
		void set_minutes(double minutes){minutes_spent += minutes;}
		void set_hikers_time(double t){hikers_time.insert(t);}

		void clear_minutes(){minutes_spent = 0.0;}
		void clear_hikers_time(){hikers_time.clear();}

	private:
		static Bridge *inst;   // The one, single instance
	   	Bridge() : minutes_spent(0) {} // private constructor
   		Bridge(const Bridge&);
   		Bridge& operator=(const Bridge&);

		double minutes_spent;
		set<double> hikers_time;
};

#endif // BRIDGE_H */
