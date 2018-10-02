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

map<lli, lli> dp ;

lli solve(lli n)
  {
    if(dp.find(n)!=dp.end()) return dp[n] ;
    lli ans=1 ;
    for(lli i=1 ; i<n ; i++) if(!(n%i)) ans=(((ans*i)%mod)*solve(i))%mod ;
    return dp[n]=ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli n ;
    cin>> n ;
    cout<< solve(n) ;
  }
