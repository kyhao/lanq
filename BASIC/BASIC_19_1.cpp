//BASIC_19 优化后题型 
#include <iostream>
#include <string>
using namespace std;

bool ishuiwen(const string& str){
	for(int i = 0; i < str.length()/2; i++){
		if( str[i] != str[str.length() - 1 - i] )return false;
	}
	return true;
}

//输出所需的次数 str：输入字符串 lon：长度 x：起始匹配位置 times：移动次数 
void f(string &str, const int &lon, int x, int times){
	//若 x 到达中点或者已经是回型数时停止 
	if( x == lon/2 | ishuiwen(str) ){
		//cout << str << " ->> ";
		cout << times;
		return;
	}
	char temp; int c = 0;	//temp：临时存储变量  c: 每一次的步骤和 
	for(int i = lon - 1 - x; i > x; i--){//从后向前寻找相同元素，移至对称位置 
		if( str[x] == str[i] ){
			temp = str[i];
			str.erase(i, 1);
			str.insert( lon - 1 - x, 1, temp);
			//cout << str << " >> " << c <<"\n";
			break;
		}
		c++;	//每一次步骤加一 
	}
	//若未寻找到相同元素，则该元素为单，若字符串为偶数则一定不成立。
	//若为奇数，则该数一定位于中心，取该数后的串进行移动。可以判别双‘成单数’。 
	if( str[x] != str[lon - 1 -x] ){
		if( lon % 2 == 0 ){
			cout << "Impossible"; return;
		}
		c = lon/2 - x;
		string str1 = str.substr(x + 1, lon - x*2 - 1 );	//取该成单数 的后面字符串 
		f(str1, lon - x*2 - 1, 0, times + c);
	}else{
		f(str, lon, x + 1, times + c);
	}		
}

int main(){
	
	int n;
	string str;
	cin >> n >> str;
	f(str, n, 0, 0);
	
	return 0;
}
