#include <iostream>
#include <string>
using namespace std;

string clock[21] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
string x[6] = {"o'clock", "ten", "twenty","thirty", "forty", "fifty"};

void chout(int n){
	if(n <= 20){
		cout << clock[n];
	}else{
		if(n % 10){
			cout << x[n / 10] << " " << clock[n % 10];
		}else{
			cout << x[n / 10];
		}
		
	}
}

int main(){
	int h, m;
	cin >> h >> m;
	chout(h);
	cout << " ";
	if( m == 0 )cout << x[0];
	else chout(m);
	return 0;
}
