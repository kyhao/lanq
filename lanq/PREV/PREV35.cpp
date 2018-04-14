#include<iostream>
#include<string>
using namespace std;

string str;
int p;

int cal(){
	int t[2] = {0, 0}, c = 0;
	for( ; p < str.size(); p++){
		if(str[p] == 'x' )t[c]++;
		if(str[p] == '|'){
			t[0] = t[0]>t[1]?t[0]:t[1];
			c = 1;
			t[1] = 0;
		}
		if(str[p] == ')'){
			return t[0]>t[1]?t[0]:t[1];
		}
		if(str[p] == '('){
			p++;
			t[c] += cal();
		}
	}
	return t[0]>t[1]?t[0]:t[1];
}

int main(){
	cin >> str;
	p = 0;
	cout << cal();
	return 0;
}
