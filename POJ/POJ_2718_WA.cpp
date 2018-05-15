#include <iostream>
#include <stdio.h>
using namespace std;

int N, ans;
int cases[10];
bool f;

void go(int s){
	if(f){
		
	}else{
		for(int i = 0;i<10;i++){
			cout << cases[i];
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> N;
	for(int i = 0; i < N; i++){
		f == false;
		for(int j = 0; ;j++){
			cin >> cases[j];
			if(cases[j] == 0)f = true;
			if(getchar()=='\n'){
				go(j);
				break;
			}
			
		}	
	}
	return 0;
} 
