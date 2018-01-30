//lanqiao85%
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

void change(double &a, double &b){
	if( b >= a ){
		return;
	}else{
		double t = b;
		b = a;
		a = t;
	}
}

int main(){
	double x[4], y[4], area = 0.00;
	cin >> x[0] >> y[0] >> x[1] >> y[1];
	cin >> x[2] >> y[2] >> x[3] >> y[3];
	
	change(x[0], x[1]);
	change(y[0], y[1]);
	change(x[2], x[3]);
	change(y[2], y[3]);
	
	//�ж����޽��� 
	bool f = (x[2] <= x[0] && x[0] <= x[3]) || ( x[2] <= x[1] && x[1] <= x[3] );//x�н��� 
	bool f1 = (y[2] <= y[0] && y[0] <= y[3]) || ( y[2] <= y[1] && y[1] <= y[3] );//y�н���
	bool f2 = (x[0] <= x[2] && x[2] <= x[1]) || ( x[0] <= x[3] && x[3] <= x[1] );//x�н��� 
	bool f3 = (y[0] <= y[2] && y[2] <= y[1]) || ( y[0] <= y[3] && y[3] <= y[1] );//y�н���
	
	if( (f && f1) || (f2 && f3) ){ 
		//�н��� //���� 
		sort(x, x + 4);
		sort(y, y + 4);
		area = ( y[2] - y[1] ) * ( x[2] - x[1] ); 		
	}else{
		//�޽���
		area = 0.00; 
	}
	
	//cout << setiosflags(ios::fixed);
	cout << fixed << setprecision(2) << area;
	
	return 0;
}
