//оƬ���� 
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
	
	//Ѱ�ҵ�һ���оƬ��
	int ok = 0, bad = 0;
	for( int i = 0; i < n; i++){			
		for( int j = i + 1; j < n;j++){
			//���ҵ����ֵΪ1��оƬ����ʼȷ��оƬ�Ƿ�û� 
			if( m[i][j] == 1){
				for( int k = 0; k < n; k++){
					if( m[k][j] )ok++;
					else bad++;
				}
				if(ok > bad){
					//��ʱi�Ǻ�оƬ
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
		//�ӵ�һ����оƬ��ʼ����ʽ��ѯ�����Ӷ�n. 
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
