#include <iostream>
using namespace std;

int main(){
	int n, sum;
	cin >> n;
	sum = n * (n-1) * (n-2);
	if( n % 2 ){
		
	}else{
		sum = sum / 2;
	}
	cout << sum;
	return 0;
}
