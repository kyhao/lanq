#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int>** city = new vector<int>*[n];
	vector<int> k[n];
	for(int i = 0; i < n; i++){
		city[i] = &k[i];
	}
	int p, q, d;
	for(int i = 0; i < n;i++){
		cin >> p >> q >> d;
		*city[p].push_back();
	}
	return 0; 
}
