#include <bits/stdc++.h>
using namespace std;
 
int main() {
	freopen("protecting-memes.in", "r", stdin);
	int t;
	cin>>t;
	while(t--) {
		int n,m;
		cin>>n>>m;
		string p,r,s;
		cin>>p>>r>>s;
		string ans=s;
		int i=n-1,j=m-1;
		int a[m];
		while(j>=0) {
			if(p[i]==r[j]){
				ans[i]='0';
				a[j]=i;
				i--;
				j--;
			}
			else i--;
		}
		i=0,j=0;
		while(j<m) {
			if(ans[i]=='1'){
				i++;
			}
			else {
				if(p[i]==r[j]) {
					if(s[i]=='0') {
						i++;
						j++;
					}
					else if(a[j]>i) {
						ans[i]='1';
						i++;
					}
					else {
						i++;
						j++;
					}
				}
				else {
					ans[i]=s[i];
					i++;
				}
			}
		}
		while(i<n) {
			ans[i]=s[i];
			i++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
