//K好数 L位K进制 
#include <iostream>
using namespace std;

#define BASE 1000000007 

bool check(int *n, int l){
	for(int i = 1; i < l - 1; i++){
		if( ( n[i]-n[i-1] ) == 1 || ( n[i]-n[i-1] ) == -1 )return 0;
	}
	return 1;
}

// L位 K进制 
int main(){
	int K, L;
	cin >> K >> L;
	int count = 0;
	
	int* n = new int[L];
	for(int i = 0; i < L; i++)n[i] = 0; 
	n[ L - 1 ] = 1;
	
	for(int j = 0; j < L;){		
		n[j]++;
		if( check(n, L) ){
			count++;
		}
		if(n[j] == K){
			n[j] = 0;
			j++;
		}		
	}
	
	cout << count;
	
	delete n;
	return 0;
}
