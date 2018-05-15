#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct Stop{
	int d;
	int f;
};

struct cmp{
	bool operator()(const Stop &a, const Stop &b){
		return a.f < b.f;
	}
};

priority_queue<Stop, vector<Stop>, cmp> q; 

int N, L, P, ans;
Stop *stop;


void run(int pos, int fuel){
	if(pos >= N)return;
	if(fuel >= L)return;
	cout << pos << " " << fuel << "\n";
	while(L - stop[pos].d <= fuel){
		q.push(stop[pos++]);
		if(pos >= N)break;
	}
	if(q.size() == 0){
		ans = -1;
		return;
	}
	cout << q.top().f << "\n";
	fuel = q.top().f + fuel;
	q.pop();
	ans++;
	run(pos, fuel);
} 

bool cmp_(Stop a, Stop b){
	return a.d > b.d;
}

void init(){
	cin >> N;
	ans = 0;
	stop = new Stop[N];
	for(int i = 0; i < N; i++){
		cin >> stop[i].d >> stop[i].f;
	}
	sort(stop, stop+N, cmp_);
	cin >> L >> P;
}

int main(){
	init();
	run(0, P);
	cout << ans;
	return 0;
}
