#include<iostream>
using namespace std;

bool f[201];
int n, m, s, id_d, id_c;
int _min = 200000;

int main(){
	int t, i = 0;
	cin >> n;
	cin >> s;f[100] = true;
	while(cin >> m){
		if(m < _min) _min = m;
		t = 100+m-s;
		if(f[t]){
			id_c = m;continue;
		}
		f[t] = true;
		i++;
	}
	int start = 100+_min-s;
	for(int j = 0; j < i; j++){
		if(f[j + start] == false){
			id_d = j + _min;break;
		}
	}
	cout << id_d << " " << id_c;
	return 0;
} 
