#include<iostream>
#include<algorithm>
using namespace std;

int R, n, s, m;
int *army;

void mark(){
	int i = 0, ans = 0;
	while(i < n){
		s = army[i];
		while( i<n && army[i] <= s+R) i++;
		m = army[ i-1 ];
		while( i<n && army[i] <= m+R) i++;
		ans++;
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	while(1){
		cin >> R >> n;
		if( R == -1 && n == -1 )break;
		army = new int[n];
		for(int i = 0; i < n; i++){
			cin >> army[i];
		}
		sort(army, army + n);
		mark();
		delete[] army;
	}
	
	return 0;
}
