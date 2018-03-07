#include <iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	int h, m, s;
	h = t / 3600;
	m = (t % 3600) / 60;
	s = t % 60;
	cout << h << ':' << m << ':' << s;
	return 0;
}
