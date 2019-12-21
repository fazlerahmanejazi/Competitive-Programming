#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	string s,z;
	cin>>s;
	z=s;
	char c=s[0];
	int j;
	bool mark[n];
	memset(mark,false,sizeof(mark));
	for(int i=0;i+k<n;i+=k){
		mark[i]=true;
		if(s[i]>=s[i+k]){
			s[i+k]=s[i];
		}
		else{
			j=i+k-1;
			while(j>=0&&j!=i&&s[j]=='9')
			s[j]='0';
			j--;}
			s[j]++;
			s[i+k]=s[i];
	}
	for(int j=0;j<n;j++){
		if(mark[j]==true)
		continue;
		c='0';
		for(int i=j;i<n;i+=k){
			c=max(c,s[i]);
			mark[i]=true;
		}
		for(int i=j;i<n;i+=k){
			s[i]=c;
		}
	}
	cout<<n<<endl;
	cout<<s;
	return 0;
}
