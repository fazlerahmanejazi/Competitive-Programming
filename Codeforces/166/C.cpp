#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using lli = long long int ;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, k, idx=0 ;
    cin>> n >> k ;
    vi ans(n+1, 0) ;
    if(3*k>n) return cout<< -1, 0 ;
    for(int i=1 ; i<=k ; i++) ans[2*i-1]=ans[2*i]=i ;
    for(int i=2*k+1 ; i<=n ; i++) ans[i]=idx+1, idx=(idx+1)%k ;
    for(int i=1 ; i<=n ; i++) cout<< ans[i] << " " ;
  }
