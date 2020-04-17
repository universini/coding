#include<iostream>
#include<string>

using namespace std;

class base_class
{
	public:
		int str_len(string s1)
		{
			return(s1.size());
		}

		int str_cmp(string s1, string s2)
		{
			string::iterator it1, it2;

			for(it1=s1.begin(), it2=s2.begin();
				it1 != s1.end() || it2 != s2.end();
				++it1, ++it2)
			{
				if(*it1 != *it2)
				{
					return(1);
				}
			}

			return(0);
		}

	protected:
		string s1;
};

class derived_class: public base_class
{
};

int main(void)
{
	derived_class c;

	string s = "Sidde";
	cout << c.str_len(s) << "\n";
	return(0);
}
