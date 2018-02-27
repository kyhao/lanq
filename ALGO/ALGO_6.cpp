#include <iostream>
#include <queue>
using namespace std;

#define INF 10000

struct side{						//边 
	int s;						//边的起点 
	int e;						//边的终点 
	int v;						//边的权值 	
	friend bool operator<(side a, side b){	//用于判断优先队列 
		return a.v > b.v;
	}
};

//kruskal算法应用 
priority_queue<side> e;
int kruskal(int* node_val, bool* node_flag, int n){
	int sum = 0;
	bool iscircle = false;	//圆圈标识位 
	int* tree = new int[n+1];	//用于每个节点归属树的标识。 
	bool a = node_flag[e.top().s], b = node_flag[e.top().e];
	for(int i = 0; i < n-1; ){
		//判断是否成环
		if( a || b ){
			if( !a && b ){
				tree[e.top().s] = tree[e.top().e];iscircle = false;
			}
			if( a && !b ){
				tree[e.top().e] = tree[e.top().s];iscircle = false;
			}
			if( a && b){
				if( tree[e.top().s] == tree[e.top().e]){
					iscircle = true;
				}else{
					for(int i = 0; i < n + 1; i++){
						if(tree[i] == tree[e.top().s])tree[i] = tree[e.top().e];
					}
					iscircle = false;
				}
			}
		}else{
			tree[e.top().s] = i;
			tree[e.top().e] = i;
			iscircle = false;
		}
		//处理成环和不成环结果 
		if(iscircle){		
			e.pop();
		}else{
			cout << e.top().s << " -> " << e.top().e << "\n";
			sum += node_val[e.top().s] + ( e.top().v * 2 ) + node_val[e.top().e];	//起点值+边权值+终点值
			node_flag[e.top().s] = true;		// 标记已选节点
			node_flag[e.top().e] = true;		// 标记已选节点
			e.pop();
			i++;
			//cout << i << "-";
		}
	}
	for(int i = 1; i < n + 1; i++){
		cout << tree[i] << "-";
	}
	delete[] tree;
	return sum;
}

int main(){
	ios::sync_with_stdio(false);
	int n, m, min = INF;
	cin >> n >> m;
	//存储点权值 ,点的标记 
	int* node_val = new int[n+1];
	bool* node_flag = new bool[n+1];	//标记加入的点集，用于判断是否成环 
	for(int i = 1; i <= n; i++){
		cin >> node_val[i];
		node_flag[i] = false;
		if( node_val[i] < min) min = node_val[i];
	}
	//存储边的源点和终端和权值
	//priority_queue<side> e;
	side x;
	for(int i = 0; i < m; i++){
		cin >> x.s >> x.e >> x.v;
		e.push(x);
	}	
	cout << kruskal(node_val, node_flag, n) + min;
	
	return 0;
} 
