//采用递归法，暴力枚举，需优化 
#include <iostream>
#include <string>
using namespace std;

bool ishuiwen(const string& str){
	for(int i = 0; i < str.length()/2; i++){
		if( str[i] != str[str.length() - 1 - i] )return false;
	}
	return true;
}

void f(string str, int x, int times){
	
	//...
	char temp;
	for(int i = x, c = 0; i < str.length(); i++, c++){
		
		if( x == str.length() )return;
		if( ishuiwen(str) ){
			cout << str << "-->";
			cout << times << "\n";
			return;
		}
		
		temp = str[i];
		str.erase(i, 1);
		str.insert(x, 1, temp);
						
		f(str, x + 1, times + c);
	}
	//...
	
}

int main(){
	//int n;
	string str;
	//cin >> n >> str;
	cin >> str; 
	//cout << ishuiwen(str);
	f(str, 0, 0);
	
	return 0;
}
