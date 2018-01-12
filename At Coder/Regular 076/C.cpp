#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
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
    lli n, m, ans=1 ;
    cin>> n >> m ;
    if(abs(n-m)>1)
      {
        cout<< 0 ;
        return 0 ;
      }
    if(n<m) swap(n, m) ;
    for(int i=1 ; i<=n ; i++)
      ans=(ans*i)%mod ;
    for(int i=1 ; i<=m ; i++)
      ans=(ans*i)%mod ;
    if(n==m) ans=(ans*2)%mod ;
    cout<< ans ;
  }
