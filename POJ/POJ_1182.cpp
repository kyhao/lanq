//use iostream:time out limited
//use stdio AC
//#include<iostream>
//using namespace std;
#include<stdio.h> 

int N, K, D, X, Y;
int ans = 0;
int par[150000];
int _rank[150000];

int find(int x){
	if(par[x] == x){
		return x;
	}else{
		return par[x] = find(par[x]);
	}
}

void unite(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y)return;
	//·ÀÖ¹ÍË»¯ 
	if(_rank[x] < _rank[y]){
		par[x] = y;
	}else{
		par[y] = x;
		if(_rank[x] == _rank[y]) _rank[x]++;
	}
}

bool same(int x, int y){
	return find(x) == find(y);
}

void init(int n){

	for(int i = 0; i < n; i++){
		par[i] = i;
		_rank[i] = 0;
	}
}

int main(){
	//ios::sync_with_stdio(false);
	//cin >> N >> K;
	scanf("%d %d", &N, &K);
	init(N*3);
	int t, x, y;
	for(int i = 0; i < K; i++){
		//cin >> D >> X >> Y;
		scanf("%d %d %d", &D, &X, &Y);
		t = D; x = X - 1; y = Y - 1;
		
		if(x < 0 || N <= x || y < 0 || N <= y){
			ans++;
			continue;
		}
		if(t == 1){
			if(same(x, y + N) || same(x, y + 2 * N)){
				ans++;
			}
			else {
				unite(x, y);
				unite(x + N, y + N);
				unite(x + N * 2, y + N * 2);
			}
		}else{
			if(same(x, y) || same(x, y + 2 * N)) {
				ans++;
			}else{
				unite(x, y + N);
				unite(x + N, y + 2 * N);
				unite(x + 2 * N, y);
			}
		}
	}
	
	//cout << ans;
	printf("%d", ans);
	return 0;
}
