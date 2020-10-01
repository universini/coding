#include<iostream>

using namespace std;

class friend_check {
	int a, b;
	
	public:
		friend_check(int x, int y){
			a = x;
			b = y;
		}

		int sum(void){
			return(a+b);
		}
		
		void output(){
			cout << a << " " << b;
		}
		
		friend int product(friend_check);
};

int product(friend_check f){
	f.a = 10;
	f.b = 20;
	return(f.a*f.b);
}

int main(void)
{
	friend_check f(2, 3);
	cout << "sum:" << f.sum() << endl;
	cout << "product:" << product(f) << endl;
	f.output();
}
