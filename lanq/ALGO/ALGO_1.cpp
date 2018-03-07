#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans[1000] = {0};

bool cmp(int a,int b)
{
    return a > b;
}

int main(){
	int n, m;
	cin >> n;
	vector<int> nlist(n);
	for(int i = 0;i < n;i++){
		cin >> nlist[i];
	}
	cin >> m;
	int l, r, k;
	for(int j = 0;j < m;j++){	
		cin >> l >> r >> k;
		vector<int> buf;
		for(int i = l;i <= r;i++){
			buf.push_back(nlist[ i-1 ]);
		}
		sort(buf.begin(), buf.end(), cmp);
		ans[j] = buf[k-1];
	}
	for(int i = 0; i < m ; i++){
		cout << ans[i] ;
		if(i < (m-1))cout << "\n";
	}
	return 0;
} 
