#include <bits/stdc++.h>
using namespace std ;using lli = long long int ;using pii = pair<int, int> ;using vi = vector<int> ;using vb = vector<bool> ;using vvi = vector<vector<int>> ;using vlli = vector<long long int> ;using vpii = vector<pair<int, int>> ;int n ;lli temp ;bool check ;vlli a ;lli dp[200005][2] ;map<pair<int, int>, bool> done ;lli dfs(int x, int type) { lli temp ; if(x>n || x<=0) return 0 ; if(done[make_pair(x,type)]) { dp[x][type]=-1 ; return dp[x][type] ; } if(dp[x][type]) return dp[x][type] ; done[make_pair(x,type)]=true ; if(type) { temp=dfs(x-a[x], 1-type) ; if(temp<0) dp[x][type]=temp ; else dp[x][type]=a[x]+temp ; } else { temp=dfs(x+a[x], 1-type) ; ; if(temp<0) dp[x][type]=temp ; else dp[x][type]=a[x]+temp ; } return dp[x][type] ; }int main() { ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ; cin>> n ; a.resize(n+1) ; memset(dp, 0, sizeof dp) ; for(int i=2 ; i<=n ; i++) cin>> a[i] ; for(int i=1 ; i<=n-1 ; i++) { done.clear() ; dp[1][0]=i ; done[make_pair(1,0)]=true ; temp=dfs(i+1, 1) ; if(temp<0) cout<< -1 << endl ; else cout<< dp[1][0]+temp << endl ; } }
