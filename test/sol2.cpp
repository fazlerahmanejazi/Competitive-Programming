#include<bits/stdc++.h>
using namespace std;

int main() {
	int x , d;
	cin>>x>>d;
	vector<int > v;
	int  k=0 ;
	while(x>0){
		if(x&1)
		v.push_back(k) ;
		x/=2;
		k++;

	}
k = v.size() ;
	while(k--) v.push_back( 1) ;

	for(int  i=0 ;  i< v.size() ; i++) {
		cout<<v[i] << " ";
	}
	return 0;
}
