#include <bits/stdc++.h>

using namespace std;
#define go_baby_go ios::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define pp pop_back
#define f first
#define se second
#define ll long long
const int size=1e5+7;
const int mod=1e9+7;
string s[200];
char check(int x,int y,int l,int r){
	char c=s[x][y];
	for(int i=x;i<l;i++){
		for(int j=y;j<r;j++)
			if(s[i][j]!=c)
				return 'z';
	}
	return c;
}
int main()
{
	go_baby_go
	int n,m,i,j,k;
	char c1,c2,c3;
	cin>>n>>m;
	if(n<3 && m<3){
		cout<<"NO";
		return 0;
	}
	for(i=0;i<n;i++)
		cin>>s[i];
	if(n%3==0){
		k=n/3;
		c1=check(0,0,k,m);
		c2=check(k,0,2*k,m);
		c3=check(2*k,0,3*k,m);
		if(c1!='z' && c2!='z' && c3!='z')
		{
			if(c1!=c2 && c2!=c3 && c1!=c3){
				cout<<"YES";
				return 0;
			}
		}
	}
	if(m%3==0){
		k=m/3;
		c1=check(0,0,n,k);
		c2=check(0,k,n,2*k);
		c3=check(0,2*k,n,3*k);
		if(c1!='z' && c2!='z' && c3!='z')
		{
			if(c1!=c2 && c2!=c3 && c1!=c3){
				cout<<"YES";
				return 0;
			}
		}
	}
	cout<<"NO";
	return 0;
} 
