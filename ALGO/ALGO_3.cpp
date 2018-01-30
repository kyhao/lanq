#include <iostream>
using namespace std;

int main(){
	int K, L;
	cin >> K >> L;
	int *N = new int[L];
	N[L - 1] = 1;
	for(int i = 0; i < L - 1; i++){
		N[i] = 0;
	}
	
	cout << N[0] << N[1];
	return 0;
}
