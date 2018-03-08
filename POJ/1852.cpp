#include<iostream>
using namespace std;

int main() {
	int k;
	ios::sync_with_stdio(false);
	cin >> k;
	int l, n, m;
	while(k--) {
		cin >> l >> n;
		int min = 2000000;
		int max = 0;
		int max_min = 0; 
		for(int i = 0; i < n; i++) {
			cin >> m;
			min = 2000000;
			if( m - 0 < min ) min = m - 0;
			if( l - m < min ) min = l - m;
			if( min > max_min ) max_min = min;
			if( m - 0 > max ) max = m - 0;
			if( l - m > max ) max = l - m;
		}
		cout <<  max_min << " " << max << "\n";
	}
	return 0;
} 
