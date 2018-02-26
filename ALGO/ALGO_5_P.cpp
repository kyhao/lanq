//ALGO5 使用邻接表
#include <iostream>
using namespace std;

#define NO_WAY 20000
#define MAX 30000
//添加节点 


void add(int** side_list, int index, int& now){
	if( side_list[index][2] == MAX ){
		side_list[index][2] = now;
		return;
	}else{
		add(side_list, side_list[index][2], now);
	}
}

//搜索节点的下一节点和边 
int get_node(int** node, int** side_list, int index, int min_node, const int& v){
	
	node[ side_list[index][0] ][0] = side_list[index][1] + node[v][0];	
	if(side_list[index][2] == MAX){
		return min_node; 
	}else{
		return get_node(node, side_List, side_list[index][2], min_node);
	}
}

//dijkstra算法 
void dijkstra(int** node, int** side_list, int index){
	if( node[index][1] != MAX ){
		get_node(node, side_list, node[index][1], MAX, index);
		dijkstra(node, side_list, x);
	}
}

/*//输出显示邻接表 
void print(int** side_list, int index){
	cout << side_list[index][0] << "|" << side_list[index][1] << "|" << side_list[index][2] << "->";
	if( side_list[index][2] == MAX ){
		cout << "NULL\n";
		return;
	}else{
		print(side_list, side_list[index][2]);
	}
}
*/

int main(){
	int n, m, u, v, l;
	cin >> n >> m;n++;
	int** node = new int*[n];
	int** side_list = new int*[m];
	for(int i = 0; i < n; i++){
		node[i] = new int[2];
		node[i][0] = NO_WAY;
		node[i][1] = MAX;
	}
	node[1][0] = 0;
	for(int i = 0; i < m; i++){
		side_list[i] = new int[3];
		side_list[i][0] = MAX;
		side_list[i][1] = NO_WAY;
		side_list[i][2] = MAX;
	}
	int k = 0;
	for(int i = 0; i < m; i++){
		cin >> u >> v >> l;
		side_list[i][0] = v;
		side_list[i][1] = l;
		if( node[u][1] == MAX){
			node[u][1] = i;
		}else{
			add(side_list, node[u][1], i);
		}
	}
	
	/*//输出显示存储结构 
	for(int i = 1; i < n; i++){
		cout << node[i][0] << "|";
		cout << node[i][1] << " -> ";
		if(node[i][1] == MAX){
			cout << "NULL\n";
			continue;
		}else{
			print(side_list, node[i][1]);
		}		
	}
	*/
	
	return 0;
}
