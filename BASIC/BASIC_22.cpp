#include <iostream>
using namespace std;

void fj(int n){
	if(n < 0)return;
	fj(n - 1);
	cout << char(n + 'A');
	fj(n - 1);
	
}

int main(){
	int n;
	cin >> n;
	fj(n - 1);
	return 0;
}
