#include<bits/stdc++.h>
using namespace std;

struct node{
	int x;
	int y;
	int v;
};

node field[400];

int M, N, K, P, step;

bool cmp(node x, node y){
	return x.v > y.v;
}

void cal(int i, int x, int y){
	if(step > K)return;
	step += abs(field[i].x - x) + abs(field[i].y - y);
	cal(++i, field[i].x, field[i].y);
}

int main(){
	cin >> M >> N >> K;
	int x = 0;
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			cin >> field[x].v;
			field[x].x = i;
			field[x].y = j;
			x++;
		}
	}
	step = 0;
	sort(field, field + (M*N), cmp);
	cal(0, 0, 0);
	cout << P;

	return 0;
}
