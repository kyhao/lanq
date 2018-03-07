#include <iostream>
using namespace std;

#define MAX 21
#define UP 1
#define DOWN 0

int k;
int cal[MAX][MAX];

void Init(){
	for(int i = 1; i <= k; i++)cal[i][k] = 1;
}

int swing(bool dir){
	
	if(dir){
		swing(DOWN);
	}else{
		swing(UP);
	}
	
}

int main(){	
	cin >> k;	
	Init();
	cout << swing(UP) + swing(DOWN);
	return 0;
}
