#include<iostream>
using namespace std;

int N;
char *str;

void output(){
	int f = 0, e = N - 1, n = 0;
	while( f<=e ){
		bool left = false;
		for(int i = 0; f + i <= e;i++){
			if(str[f+i] < str[e-i]){
				left = true;
				break;
			}else if(str[f+i] > str[e-i]){
				left = false;
				break;
			}
		}
		if(left)cout << str[f++];
		else cout << str[e--];
		n++;
		if(n == 80){
			cout << '\n';
			n = 0;
		}
	}
}

void init(){
	cin >> N;
	str = new char[N];
	for(int i = 0; i < N; i++){
		cin >> str[i];
	}
}

int main(){
	init(); 
	output();
	return 0;
}
