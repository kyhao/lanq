//BASIC_19 �Ż������� 
#include <iostream>
#include <string>
using namespace std;

bool ishuiwen(const string& str){
	for(int i = 0; i < str.length()/2; i++){
		if( str[i] != str[str.length() - 1 - i] )return false;
	}
	return true;
}

//�������Ĵ��� str�������ַ��� lon������ x����ʼƥ��λ�� times���ƶ����� 
void f(string &str, const int &lon, int x, int times){
	//�� x �����е�����Ѿ��ǻ�����ʱֹͣ 
	if( x == lon/2 | ishuiwen(str) ){
		//cout << str << " ->> ";
		cout << times;
		return;
	}
	char temp; int c = 0;	//temp����ʱ�洢����  c: ÿһ�εĲ���� 
	for(int i = lon - 1 - x; i > x; i--){//�Ӻ���ǰѰ����ͬԪ�أ������Գ�λ�� 
		if( str[x] == str[i] ){
			temp = str[i];
			str.erase(i, 1);
			str.insert( lon - 1 - x, 1, temp);
			//cout << str << " >> " << c <<"\n";
			break;
		}
		c++;	//ÿһ�β����һ 
	}
	//��δѰ�ҵ���ͬԪ�أ����Ԫ��Ϊ�������ַ���Ϊż����һ����������
	//��Ϊ�����������һ��λ�����ģ�ȡ������Ĵ������ƶ��������б�˫���ɵ������� 
	if( str[x] != str[lon - 1 -x] ){
		if( lon % 2 == 0 ){
			cout << "Impossible"; return;
		}
		c = lon/2 - x;
		string str1 = str.substr(x + 1, lon - x*2 - 1 );	//ȡ�óɵ��� �ĺ����ַ��� 
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
