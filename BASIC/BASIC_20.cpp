#include <iostream>
#include <string>
using namespace std;

string num[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string t[5] = {"shi", "bai", "qian", "wan", "yi"};

int main(){
	int x;
	cin >> x;
	int n = x;
	string ans = num[ n % 10 ];
	n /= 10;
	for(int i = 2; n ; i++){
		
		if( i == 5)ans = t[3] + ans;
		ans = num[ n % 10 ] + " " + ans;
		n /= 10;	
			 
	}
	cout << ans;
	return 0;
}
