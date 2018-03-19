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

int Tx, Ty, n, x, y, h, g, res ;
map<pii, vector<tuple<int, int, int>>> lizard ;

int gcd(int a, int b)
  {
    return b==0 ? a:gcd(b, a%b) ;
  }

pii slope(int x, int y)
  {
    g=abs(gcd(x, y)) ;
    if(!x) y/=abs(y) ;
    else if(!y) x/=abs(x) ;
    else x/=g, y/=g ;
    return mp(x, y) ;
  }

int solve(pii s)
  {
    vi seq ;
    vector<tuple<int, int, int>> a=lizard[s] ;
    sort(all(a)) ;
    int dp[n+1], ans=0, idx ;
    dp[0]=1 ;
    for(int i=1 ; i<=a.size() ; i++)
      {
        x=get<2>(a[i-1]) ;
        idx=lower_bound(seq.begin(), seq.end(), x)-seq.begin() ;
        if(idx==seq.size()) seq.pb(x) ;
        else seq[idx]=x ;
        dp[i]=idx+1 ;
        ans=max(ans, dp[i]) ;
      }
    return ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> Tx >> Ty >> n ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x >> y >> h ;
        x-=Tx ; y-=Ty ;
        lizard[slope(x, y)].pb(mt(abs(x), abs(y), h)) ;
      }
    for(auto i:lizard) res+=solve(i.fi) ;
    cout<< res ;
  }
