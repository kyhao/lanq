#include<iostream>
using namespace std;

#define MAX_ 101
char garden[MAX_][MAX_];
int N, M;

void dfs(int x, int y) {
	int nx, ny;
	garden[x][y] = '.';
	for(int dx = -1; dx <= 1; dx++) {
		for(int dy = -1; dy <= 1; dy++) {
			nx = x + dx;ny = y + dy;
			if(nx>=0 && ny>=0 && nx<N && ny<M && garden[nx][ny] == 'W')dfs(nx, ny);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		cin >> garden[i];
	}
	int num = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(garden[i][j] == 'W'){
				dfs(i, j);
				num++;
			}
		}
	}
	cout << num;
	return 0;
}
