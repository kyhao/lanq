//dijkstra最短路径 
#include <iostream>
using namespace std;

#define NO_WAY 10001

void dijkstra(int** map, int* val, int node, int node_val, const int& n, int time){
	
	//..
	if(time == n - 2)return;
	int min = 10001, node_1 = node;
	for(int i = 1; i < n; i++){
		if( map[node][i] < NO_WAY ){
			if(node_val + map[node][i] < val[i]){
				val[i] += node_val + map[node][i];
			}
			if(val[i] < min){
				node_1 = i;
				min = val[i];	
			}
		}
	}
	dijkstra(map, val, node_1, min, n, time + 1);
	//...
}

int main(){
	int n, m;
	cin >> n >> m;n++;	//题目中不从0开始。 
	int* val = new int[n];		//记录1点到其他点的值 
	int** map = new int*[n];
	for(int i = 0; i < n; i++){
		map[i] = new int[n];
		val[i] = NO_WAY;
		for(int j = 0; j < n; j++)map[i][j] = NO_WAY;
	}
	int x, y, v;
	for(int i = 0; i < m; i++){
		cin >> x >> y >> v;
		map[x][y] = v;
	}
	
	dijkstra(map, val, 1, 0, n, 0);
	
	for(int i = 0; i < n; i++){
		cout << val[i] << " ";
	}
	return 0;
}
