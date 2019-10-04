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

int n, m, k, u, v, ans, matching, extra ;
vvi adj ;
vi par, temp ;
vb check ;

bool find_match(int i)
  {
    if(i==-1) return true ;
    for(auto j:adj[i])
      {
        if(check[j]) continue ;
        check[j]=true ;
        if(find_match(par[j]))
          {
            par[j]=i ;
            return true ;
          }
      }
    return false ;
  }

int max_matching(int from, int to)
  {
    int res=0 ;
    for(int i=from ; i<=to ; i++)
      {
        check.assign(n+1, false) ;
        if(find_match(i)) res++ ;
      }
    return res ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> m >> n >> k ;
    adj.resize(m+3) ;
    par.assign(n+1, -1) ;
    for(int i=1 ; i<=k ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
      }
    matching=max_matching(1, m) ;
    temp=par ;
    for(int i=1 ; i<=m ; i++)
      {
        par=temp ;
        adj[m+1]=adj[m+2]=adj[i] ;
        extra=max_matching(m+1, m+2) ;
        ans=max(ans, matching+extra) ;
      }
    cout<< ans ;
  }
