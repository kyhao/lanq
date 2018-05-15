#include<iostream>
#include<queue>
using namespace std;

#define int64 unsigned __int64

int n;
priority_queue< int64, vector<int64>, greater<int64> > q;

void init(){
	int64 t;
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t;
		q.push(t);
	}
}

void Huffman(){
	int64 ans = 0, t = 0;
	while(q.size() != 1){
		t = q.top();q.pop();
		t += q.top();q.pop();
		q.push(t);
		ans += t;
	}
	cout << ans;
}

int main(){
	init();
	Huffman();
	return 0;
}
