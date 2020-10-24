#include "hike_main.h"
#include "yaml-cpp/yaml.h"

int main(int argc, char *argv[])
{
	vector<YAML::Node> configs;
	vector<YAML::Node>::iterator it;
	input_data *indata = new input_data;

	/*
	 * This can be exhanced to accept command line arguments
	 */
	configs = YAML::LoadAllFromFile("input.yaml");

#ifndef DEBUG_HIKE
		cout << "Input data received:\n";
#endif

	for (auto &x : configs)
	{
		YAML::Node config;

		config = x["iteration"];
		/*
		 * Here I am just following simple approach oherwise, this can be
		 * enhanced to use try/catch/exceptions handing and other checks
		 */
		indata->iteration_num = config["case"].as<unsigned int>();
		indata->hikers_count = config["num_hikers"].as<unsigned int>();
		indata->bridge_len = config["bridge_length"].as<double>();
		indata->hiker_speed = config["walk_speed"].as<vector<double>>();

		/*
		 * Hiker speed count should be equal to hiker count. Check
		 */
		if (indata->hiker_speed.size() != indata->hikers_count)
		{
			cerr << "ERROR: count mismatch" << endl;
			exit(0);
		}

		/*
		 * Now, calculate the time taken by each hiker using the bridge length
		 */
		for (auto &y : indata->hiker_speed)
		{
			indata->walking_time.push_back(indata->bridge_len/y);
		}

#ifdef DEBUG_HIKE
		cout << "  Iteration number: " << indata->iteration_num << endl;
		cout << "  Hikers count: " << indata->hikers_count << endl;
		cout << "  Bridge length: " << indata->bridge_len << endl;
		cout << "  Hiker speed: ";
		for (auto x : indata->hiker_speed) cout << x << " ";
		cout << "\n";
		cout << "  Walking time: ";
		for (auto x : indata->walking_time) cout << x << " ";
		cout << endl;
#endif

		/*
		 * Now, calculate minimum time taken by each iteration
		 */
		bridge_crossing_time_compute(indata);

		/*
		 * Clear old data for next iteration
		 */
		indata->hiker_speed.clear();
		indata->walking_time.clear();
	}

    cout << "\nTotal time taken to cross all the bridges is: " <<
                           total_time_taken << " minutes\n" << endl;
	delete(indata);

	return(0);
}
