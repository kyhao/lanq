#include<iostream>
using namespace std;

int main() {
	int k;
	cin >> k;
	int l, n, m;
	while(k--) {
		cin >> l >> n;
		int min = 200000;
		int max = 0;
		for(int i = 0; i < n; i++) {
			cin >> m;
			if( m - 0 < min ) min = m - 0;
			if( l - m < min ) min = l - m;
			if( m - 0 > max ) max = m - 0;
			if( l - m > max ) max = l - m;
		}
		cout  << min << " " << max;
	}
	return 0;
} 
