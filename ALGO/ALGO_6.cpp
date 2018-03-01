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
	//for(int j = 0; j < n+1; j++){
	//	tree[j] = -1;
	//}
	for(int i = 0; i < n-1; ){
		//�ж��Ƿ�ɻ�
		//cout << "flag1: " << node_flag[e.top().s] << " " << node_flag[e.top().e] << "\n";
		if( node_flag[e.top().s] || node_flag[e.top().e] ){
			
			if( !node_flag[e.top().s] && node_flag[e.top().e] ){
				tree[e.top().s] = tree[e.top().e];iscircle = false;
			}else
			if( node_flag[e.top().s] && !node_flag[e.top().e] ){
				tree[e.top().e] = tree[e.top().s];iscircle = false;
			}else
			if( node_flag[e.top().s] && node_flag[e.top().e]){
				if( tree[e.top().s] == tree[e.top().e]){
					iscircle = true;
				}else{
					int t1 = tree[e.top().s];
					for(int k1 = 0; k1 < n + 1; k1++){
						if(tree[k1] == t1)tree[k1] = tree[e.top().e];
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
			//cout << "NO: " << e.top().s << " -> " << e.top().e << " " << e.top().v << "\n";	
			e.pop();
		}else{
			cout << "OK: " << e.top().s << " -> " << e.top().e << " " << e.top().v << "\n";
			sum += node_val[e.top().s] + ( e.top().v * 2 ) + node_val[e.top().e];	//���ֵ+��Ȩֵ*2+�յ�ֵ
			node_flag[e.top().s] = true;		// �����ѡ�ڵ�
			node_flag[e.top().e] = true;		// �����ѡ�ڵ�
			//cout << "flag2: " << node_flag[e.top().s] << " " << node_flag[e.top().e] << "\n";
			e.pop();
			i++;
		}
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
