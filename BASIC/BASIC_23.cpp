//оƬ���� 
#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int** m = new int*[n];
	for( int i = 0; i < n; i++){
		m[i] = new int[n];
		for( int j = 0; j < n; j++)
			cin >> m[i][j];
	}
	
	
	
	return 0;
} 
