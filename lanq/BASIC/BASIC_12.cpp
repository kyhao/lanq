// 十六进制转八进制 
// 需要优化 
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int otod(char a){
	//cout << "otod\n";
	switch(a){
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		case 'A': return 10;
		case 'B': return 11;
		case 'C': return 12;
		case 'D': return 13;
		case 'E': return 14;
		case 'F': return 15; 
	};
}

void htoo(const string& in, string& out){
	//cout << "htoo\n";
	string hex = in;
	string oct;
	//不足三位补零
	while(hex.length() % 3){	 
		hex = '0' + hex;
	}	
	
	// 每三位16进制转化为4位8进制 
	for( int start = (hex.length() - 3), end = (hex.length() - 1); end > 0; start -=3, end -= 3){		 
			//三位转十进制 
			int s = 0;	
			s += otod(hex[start]) * 16 * 16;
			s += otod(hex[start + 1]) * 16;
			s += otod(hex[end]);
			//cout << s;
			//根据位运算，得到八进制 
			for( int i = 0; i < 4; i++ ){
				oct = char((s & 7) + '0') + oct;
				s = s >> 3;
			} 
	}
	while(oct[0] == '0' && oct.length() > 1){
		oct = oct.substr(1);
	}
	out = oct;
}

int main(){
	int n;
	string hex, oct;
	vector<string> ans;
	ans.clear();
	cin >> n;
	for( int i = 0; i < n; i++ ){
		cin >> hex;
		htoo(hex, oct);
		ans.push_back(oct);
	} 
	for(int j = 0; j < ans.size(); j++){
		cout << ans[j];
		if( (j + 1) < ans.size() )cout << "\n";
	}
	return 0;
}
