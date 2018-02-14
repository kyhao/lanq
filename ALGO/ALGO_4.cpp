#include<iostream>
#include<vector>
using namespace std;

struct Node{
	int index;
	Node* firstchild;
	Node* rightbro;
};

int main(){
	int n;
	cin >> n;
	int* val = new int[n + 1];
	for(int i = 1; i <= n; i++){
		cin >> val[i];
	} 
	
	return 0;
}
