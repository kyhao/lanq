#include <iostream>
#include <queue>
using namespace std;

#define INF 10000

struct side{						//�� 
	int s;						//�ߵ���� 
	int e;						//�ߵ��յ� 
	int v;						//�ߵ�Ȩֵ 	
	friend bool operator<(side a, side b){	//�����ж����ȶ��� 
		return a.v > b.v;
	}
};

//kruskal�㷨Ӧ�� 
priority_queue<side> e;
int kruskal(int* node_val, bool* node_flag, int n){
	int sum = 0;
	bool iscircle = false;	//ԲȦ��ʶλ 
	int* tree = new int[n+1];	//����ÿ���ڵ�������ı�ʶ�� 
	bool a = node_flag[e.top().s], b = node_flag[e.top().e];
	for(int i = 0; i < n-1; ){
		//�ж��Ƿ�ɻ�
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
		//����ɻ��Ͳ��ɻ���� 
		if(iscircle){		
			e.pop();
		}else{
			cout << e.top().s << " -> " << e.top().e << "\n";
			sum += node_val[e.top().s] + ( e.top().v * 2 ) + node_val[e.top().e];	//���ֵ+��Ȩֵ+�յ�ֵ
			node_flag[e.top().s] = true;		// �����ѡ�ڵ�
			node_flag[e.top().e] = true;		// �����ѡ�ڵ�
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
	//�洢��Ȩֵ ,��ı�� 
	int* node_val = new int[n+1];
	bool* node_flag = new bool[n+1];	//��Ǽ���ĵ㼯�������ж��Ƿ�ɻ� 
	for(int i = 1; i <= n; i++){
		cin >> node_val[i];
		node_flag[i] = false;
		if( node_val[i] < min) min = node_val[i];
	}
	//�洢�ߵ�Դ����ն˺�Ȩֵ
	//priority_queue<side> e;
	side x;
	for(int i = 0; i < m; i++){
		cin >> x.s >> x.e >> x.v;
		e.push(x);
	}	
	cout << kruskal(node_val, node_flag, n) + min;
	
	return 0;
} 
