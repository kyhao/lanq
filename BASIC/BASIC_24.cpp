#include <iostream>
using namespace std;

int main(){
	int v1, v2, t, s, l, x;
	cin >> v1 >> v2 >> t >> s >> l;
	int s1 = 0, s2 = 0;
	int q = 0;
	for( x = 0; s1 < l && s2 < l; x++ ){		
		if( q == 0 ){
			s1 += v1;
		}else {
			q--;
			//cout << " >1< ";
		}
		s2 += v2;
		if( (s1 - s2) >= t && q == 0)q = s;
		//cout << s1 << " " << s2 << "\n";
	}
	if( s1 == s2 && s1 == l){
		cout << 'D';
	}else if(s1 == l){
		cout << 'R';
	}else if(s2 == l){
		cout << 'T';
	}
	cout << '\n' << x;
	return 0;
}
