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

int n, x, prev, curr=0, idx, maxm=-1 ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    vi a(n) ;
    map<int, int> cnt ;
    for(int i=0 ; i<n ; i++)
      cin>> a[i] ;
    vvi adj(200010) ;
    for(int i=0 ; i<n ; i++)
      {
        auto it=cnt.upper_bound(-a[i]) ;
        if(it!=cnt.end())
          {
            curr=(*it).se ;
            cnt.erase(it) ;
          }
        else curr=cnt.size() ;
        cnt[-a[i]]=curr ;
        adj[curr].pb(a[i]) ;
      }
    for(int i=0 ; i<cnt.size() ; i++)
      {
        for(auto j:adj[i])
          cout<< j << " " ;
        cout<< endl ;
      }
  }
