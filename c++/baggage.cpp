#include<iostream>
#include<stack>
#include<vector>

#define USE_INLINE 1

using namespace std;

template <class myBag> // or typename
class baggage_system {
	stack<myBag> container;

	public:	
		void stack_push(myBag& bag){
			container.push(bag);
		}
	
#ifdef USE_INLINE
		myBag stack_pop(){
			myBag bag;
			bag = container.top();
			container.pop();
			return(bag);
		}
#else
		myBag stack_pop();
#endif		

		int stack_is_empty(){
			return(container.empty() ? 1 : 0);
		}
};

#ifndef USE_INLINE
template <class myBag>
myBag baggage_system<myBag>::stack_pop(void){
	myBag bag;
	bag = container.top();
	container.pop();
	return(bag);
}
#endif

int main(void){
	baggage_system< vector<int> > b;
	int i, sum = 0;
	vector<int> v1;
	vector<int> v2;
	
	v1.push_back(30);
	v1.push_back(6);
	v1.push_back(5);
	v1.push_back(22);
	v1.push_back(20);
	v1.push_back(40);

	for (i=0; i<v1.size(); i++){
		sum+=v1[i];
		if (sum <= 40){
			v2.push_back(v1[i]);
		}else{
			b.stack_push(v2);
			v2.clear();
			v2.push_back(v1[i]);
			sum = v1[i];
		}
	}
	
	b.stack_push(v2);

	while(!b.stack_is_empty()){
		v2 = b.stack_pop();
		for(i=0; i<v2.size(); i++)
			cout << v2[i] << " ";
		cout << "\n";
	}

	return(0);
}


