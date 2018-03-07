#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;
int index = 0;	
stack<int> num;
stack<int> syp;
int temp;

int cal(){
	if(str.empty())return 0;
	bool isnum = false;
 	for(;;index++){
 		if(str[index] == ')')break;
		if( str[index] <= '9' && str[index] >= '0' ){
			if(isnum){
				temp = num.top() * 10 + str[index];
				num.pop();
				num.push(temp);
			}
			else{
				num.push( str[index] - '0' );
				isnum = true;
			}
		}else{
			if( str[index] == '('){
				num.push(cal());
			}
		}
	}
}

int main(){
	cin >> str;
	//cout << cal();
	return 0;
}
