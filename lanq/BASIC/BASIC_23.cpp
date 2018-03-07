//芯片测试 
#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	vector<int> ans;
	cin >> n;
	int** m = new int*[n];
	for( int i = 0; i < n; i++){
		m[i] = new int[n];
		for( int j = 0; j < n; j++)
			cin >> m[i][j];
	}
	
	//寻找第一块好芯片。
	int ok = 0, bad = 0;
	for( int i = 0; i < n; i++){			
		for( int j = i + 1; j < n;j++){
			//若找到测得值为1的芯片，则开始确认芯片是否好坏 
			if( m[i][j] == 1){
				for( int k = 0; k < n; k++){
					if( m[k][j] )ok++;
					else bad++;
				}
				if(ok > bad){
					//此时i是好芯片
					ok = 1;
					break; 
				} 
			}
			ok = 0, bad = 0;
		}
		if( ok == 1){
			ans.push_back(i); 
			break;
		}
	} 
	
	for( int i = ans[0]; i < n - 1; ){
		//从第一个好芯片开始，链式查询。复杂度n. 
		for(int j = i + 1; j < n; j++){
			if( m[i][j] == 1 ){
				i = j;
				ans.push_back(j);
			}
		}
	}
	
	for( int i = 0; i < ans.size(); i++){
		cout << (ans[i] + 1);
		if( (i+1) < ans.size() )cout << " ";
	}
	
	return 0;
} 
