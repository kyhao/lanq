#include<iostream>
#include<algorithm>
using namespace std;

int A[100];
int n;

int main(){
	while(cin >> n){
		for(int i = 0; i < n; i++){
			cin >> A[i];
		}
		sort(A, A+n);
		
	}
	return 0;
} 
