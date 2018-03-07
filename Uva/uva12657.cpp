#include<iostream>
using namespace std;

#define MAX 100002
int left[MAX];
int right[MAX];
bool inv;	//true zhengxiang;false fanxiang

void link(int n1, int n2) {	
	left[n2] = n1; right[n1] = n2;
}

int main() {
	ios::sync_with_stdio(false);
	int n, m, mode, n1, n2;
	while(cin >> n >> m) {
		//
		inv = true;
		for(int i = 0; i <= n + 1; i++) {
			left[i] = i - 1;
			right[i] = i + 1;
		}
		//
		for(int i = 1; i <= m; i++){
			cin >> mode >> n1 >> n2;
			if(mode == 4) {
				inv = !inv;
			}else {
				if(mode == 3)
				int lx, rx, ly, ry;
				link(n1, n2);
			}			  	
		}
		//
		int sum = 0, p = 0;
		for(int i = 0; i <= n; i++) {
			if(i%2)sum += right[p];
			p = right[i];
		}
		
	}
	return 0;
}
