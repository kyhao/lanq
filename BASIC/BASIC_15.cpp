#include <iostream>
#include <string>
using namespace std;

int main(){
	int f = 0;
	string str1, str2;
	cin >> str1 >> str2;
	if( str1.length() != str2.length() ){
		f = 1;
	}else{
		f = 2;
		for( int i = 0; i < str1.length(); i++){
			if( str1[i] != str2[i] ){
				if( (str1[i] - str2[i]) == 32 || (str2[i] - str1[i]) == 32){
					f = 3;
				}else{
					f = 4;
					break;
				}
			}			
		}
	}
	cout << f;
	return 0;
}
