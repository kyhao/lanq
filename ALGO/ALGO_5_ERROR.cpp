//dijkstra Œ¥ÕÍ…∆ 
#include <iostream>
using namespace std;

#define NO_WAY 20000
int arry[20001] = { 0 };

void dijkstra(int** map, int* val, int node, const int size, int t){
	//...
	if(t == size - 1 )return;
	arry[node] = 1;
	int min = NO_WAY;int node_next;
	for(int i = 1; i < size; i++){
		if( map[node][i] < NO_WAY ){
			if( val[node] + map[node][i] < val[i] ){
				val[i] = val[node] + map[node][i];
			}
		}
	}
	for(int i = 2; i < size; i++){
		if( val[i] < min && arry[i] != 1){
			min = val[i];
			node_next = i;
		}
	}
	dijkstra(map, val, node_next, size, t + 1);
	//...
}

int main(){
	int n, m;
	cin >> n >> m;n++;
	int* ans = new int[n];
	int** map = new int*[n];
	for(int i = 0; i < n; i++){
		map[i] = new int[n];
		ans[i] = NO_WAY;
		for(int j = 0; j < n; j++)map[i][j] = NO_WAY;
	}
	ans[1] = 0;
	int x, y, v;
	for(int i = 0; i < m; i++){
		cin >> x >> y >> v;
		map[x][y] = v;
	}
	
	dijkstra(map, ans, 1, n, 0);
	
	for(int i = 2; i < n; i++){
		cout << ans[i];
		if(i + 1 < n)cout << "\n";
	}
	cin >> n;
	return 0;
}
