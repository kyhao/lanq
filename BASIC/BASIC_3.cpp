#include <iostream>
using namespace std;

char a[52] = "ZYXWVUTSRQPONMLKJIHGFEDCBABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
	int n, m, j;
	cin >> n >> m;
	for( int i = 0; i < n; i++){
		for( j = 0; j < m; j++ ){
			cout << a[ 25 + i - j ];
		}
		if( (i + 1) < n)cout << "\n";
	}
	return 0;
}
