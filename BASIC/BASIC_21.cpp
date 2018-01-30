#include <iostream>
using namespace std;

void An(int n, int start){	
	cout << "sin(" << start ;
	if( start == n){
		cout << ')';
		return;
	}
	if( start % 2){
		cout << '-';
	}else{
		cout << '+';
	}	
	An(n, start + 1);
	cout << ')';
}

void Sn(int n, int y){
	if(n == 0)return;
	if(n > 1)cout << '(';	
	Sn(n - 1, y + 1);
	if(n > 1)cout << ')';
	An(n, 1);
	cout << '+' << y;
}

int main(){
	int n;
	cin >> n;
	//An(n, 1);
	Sn(n, 1);
	return 0;
}
