//01背包问题 记忆化搜索与动态规划 
#include<iostream>
#include<algorithm>
using namespace std;

#define MAX_N 100
int n, W;
int w[MAX_N], v[MAX_N];

int rec(int i, int j){
	int res;
	if(i == n)return 0;
	if(w[i] > j){
		res = rec(i+1, j);
	}else{
		res = max(rec(i+1, j), rec(i+1, j-w[i]) + v[i]);
	}
	return res;
}

void init(){
	cin >> n >> W;
	for(int i; i < n; i++){
		cin >> w[i] >> v[i];
	}
}

int main(){
	init();
	cout << rec(0, W);
	return 0;
}
