#include<iostream>
using namespace std;

#define INF 1000005

int map[10][10];
bool map_f[10][10];
int dx[4] = {0, 1, 0, -1}; 
int dy[4] = {1, 0, -1, 0};
int sum = 0, sum_2 = 0, ans = INF;
int n, m;
//深度优先+剪枝+回溯 
void get_ans(int x, int y, int temp,int times){
	if( map_f[x][y] || x<0 || x>=n || y<0 || y>=m )return;
	temp += map[x][y];
	if(temp > sum_2)return;
	if(temp == sum_2){
		if(times < ans)ans = times;
		return;
	}
	map_f[x][y] = true;
	for(int i = 0; i < 4; i++){
		get_ans(x+dx[i], y+dy[i], temp, times + 1);
	}
	map_f[x][y] = false;
}

int main(){	
	cin >> m >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> map[i][j];
			sum += map[i][j];
		}
	}
	sum_2 = sum / 2;
	get_ans(0, 0, 0, 1);
	cout << ans;
	return 0;
}
