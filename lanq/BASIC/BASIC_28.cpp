#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a, int b)   
{  
    return a > b;  
}

int main(){
	int n;
	cin >> n;
	int temp;
	vector<int> set;
	vector<int> node;
	for(int i = 0; i < n; i++){
		cin >> temp;
		set.push_back(temp);
	}
	int a, b;
	for(;set.size() > 1;){
		sort( set.begin(), set.end(), cmp);
		a = set[set.size()-1];
		b = set[set.size()-2];
		set.pop_back();
		set.pop_back();
		set.push_back(a + b);
		node.push_back(a + b);
	}
	
	int sum = 0;
	for(int i = 0; i < node.size(); i++ ){
		sum += node[i];
	}
	
	cout << sum;
	
	return 0;
} 
