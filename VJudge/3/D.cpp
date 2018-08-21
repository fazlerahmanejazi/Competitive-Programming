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
    lli n, k, x ;
    vlli g ;
    cin>> n >> k ;
    for(lli i=1 ; i<=sqrt(n) ; i++)
      if(n%i==0)
        g.pb(i), g.pb(n/i) ;
    sort(all(g)) ;
    reverse(all(g)) ;
    for(int i=0 ; i<g.size() && k<=sqrt(2*(1e10)); i++)
      {
        x=g[i] ;
        if(k*(k+1)<=2*(n/x))
          {
            for(lli j=1 ; j<=k-1 ; j++)
              cout<< j*x << " " ;
            cout<< n-(x*((k-1)*k)/2) ;
            return 0 ;
          }
      }
    cout<< -1 ;
  }
