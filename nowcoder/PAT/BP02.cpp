#include<bits/stdc++.h>
using namespace std;

int buf[1000001];

int main(){
	ios::sync_with_stdio(false);
	buf[0] = 7;buf[1] = 11;
	for(int i = 2; i < 1000001; i++){
		buf[i] = (buf[i-1] % 3 + buf[i-2] % 3) % 3;
	}
	int n;
	while(cin >> n){
		if(buf[n] == 0)cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
