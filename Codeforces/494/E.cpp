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

int n, d, k, u, v, x, idx, maxDeg, maxDepth ;
vpii edges ;
queue<tuple<int, int, int>> q ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> d >> k ;
    if(n<d+1 || (n>2 && k==1)) return cout<< "NO", 0 ;
    for(int i=2 ; i<=d ; i++) q.push(mt(i, k-2, min(i-1, d+1-i))), edges.pb(mp(i, i-1)) ;
    edges.pb(mp(d+1, d)) ;
    idx=d+2 ;
    while(idx<=n && !q.empty())
      {
        tie(u, maxDeg, maxDepth)=q.front() ; q.pop() ;
        for(int i=1 ; i<=maxDeg && idx<=n ; i++)
          {
            v=idx ;
            edges.pb(mp(u, v)) ;
            if(maxDepth>1) q.push(mt(v, k-1, maxDepth-1)) ;
            idx++ ;
          }
      }
    if(idx!=n+1) return cout<< "NO", 0 ;
    cout<< "YES" << endl ;
    for(auto i:edges) cout<< i.fi << " " << i.se << endl ;
  }
