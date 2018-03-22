#include<iostream>
using namespace std;

int a, b, c;

int gcd(int x, int y){
	if(x == 0) return y;
	return gcd( y % x, x);
}

int main(){
	ios::sync_with_stdio(false);
	cin >> a >> b >> c;
	int x = a*b/gcd(a, b);
	cout << x*c/gcd(x, c);	
	return 0;
} 
