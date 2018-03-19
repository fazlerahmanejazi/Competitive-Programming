#include <bits/stdc++.h>
using namespace std;

int main() {

	 int t;cin>>t;
	 for(int i=1;i<=t;i++){
        int n;cin>>n;
        string s=to_string(n);int mini=100000;
        for(int j=n;j<=100000;j++){
            string s = to_string(j);bool flag=true;
            for(int k=0;k<s.size();k++){
                if(s[k]-48==1 || s[k]-48==3 || s[k]-48==5 || s[k]-48==7 || s[k]-48==9){flag=false;break;}
            }
            if(flag){
                mini=min(mini,j-n);break;
            }
        }
        for(int j=n;j>=1;j--){
            string s = to_string(j);bool flag=true;
            for(int k=0;k<s.size();k++){
                if(s[k]-48==1 || s[k]-48==3 || s[k]-48==5 || s[k]-48==7 || s[k]-48==9){flag=false;break;}
            }
            if(flag){
                mini=min(mini,n-j);break;
            }
        }


	 	 cout<<"Case #"<<i<<": ";
        cout<<mini;

	 	 cout<<endl;
	 }

}
