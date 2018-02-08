#include<bits/stdc++.h>
using namespace std;
long long int a[100000];
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << " ";
    err(++it, args...);
}
#define all(a)                      a.begin(), a.end()
#define pb                          push_back
#define ll	                         long long int


int main(){
/*#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
#endif
*/
ll n,k=1,t,r,sum;
cin>>n;

for(ll i=19;k<=10000&&k<=n;i=i+9){
	t=i;sum=0;
	while(t>0){
			r=t%10;
			sum=sum+r;
			t=t/10;
	}
	if(sum==10)
		a[k++]=i;
}

cout<<a[n];
return 0;
}
