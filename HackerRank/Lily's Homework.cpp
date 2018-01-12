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

int n, ans, x, res ;
vpii a, b, c ;
vvi adj ;
vb visit ;

void dfs(int u)
  {
    visit[u]=true ;
    ans++ ;
    adj[ans].pb(c[u].fi) ;
    if(!visit[c[u].se])
      dfs(c[u].se) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    a.resize(n+1) ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> x ;
        a[i]=mp(x, i) ;
      }
    adj.resize(n+1) ;
    sort(a.begin()+1, a.end()) ;
    visit.assign(n+1, false) ;
    for(int i=1 ; i<=n ; i++)
      {
        if(!visit[i])
          {
            ans++ ;
            dfs(i) ;
          }
      }
    cout<< ans << endl ;
    for(int i=1 ; i<=ans ; i++)
      {
        cout<< adj[i].size() << " " ;
        for(int j=0 ; j<adj[i].size() ; j++)
          cout<< adj[i][j] << " " ;
        cout<< endl ;
      }
  }
