#include<iostream>
#include<algorithm>
using namespace std;

int a[50001];
int n, min_, max_;
int sum = 0;

void s(int dex){
	if(dex == n)return;
	min_ = a[dex];max_ = a[dex];
	for(int i = dex + 1; i <= n; i++){
		if(a[i] > max_)max_ = a[i];
		if(a[i] < min_)min_ = a[i];
		if( (i - dex) == (max_ - min_) )sum++;
	}
	s(dex + 1);
}

int main(){	
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	s(1);
	cout << sum + n;
	return 0;
}
