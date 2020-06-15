#include<iostream>
#include<unordered_map>
#include<string>
#include<sstream>

using namespace std;

void print_freq(const string& str)
{
	unordered_map<string, int> um;
	stringstream s(str);
	string w;

	while (s >> w)
		um[w]++;

	for (auto& x:um)
		cout << x.first << ": " << x.second << "\n";
}

int main(void)
{
	string s="sidde gowda sidde gowda nidagatta sidde";
	print_freq(s);
	return(0);
}

