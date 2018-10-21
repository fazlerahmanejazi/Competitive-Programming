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

int n, u, v, a[100] ;
bool check ;
vb visit ;
vvi adj ;

void dfs(int u)
  {
    visit[u]=true ;
    for(auto v:adj[u]) if(!visit[v]) dfs(v) ;
  }

bool prime(int x)
  {
    for(int i=2 ; i<=sqrt(x) ; i++) if(!(x%i)) return false ;
    return true ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        check=false ;
        adj.clear() ;
        adj.resize(n+1) ;
        visit.assign(n+1, false) ;
        for(int i=1 ; i<=n ; i++) cin>> a[i] ;
        for(int i=1 ; i<=n ; i++)
          for(int j=1 ; j<=n ; j++)
            if(i!=j && __gcd(a[i], a[j])==1)
              adj[i].pb(j) ;
        dfs(1) ;
        for(int i=1 ; i<=n ; i++) if(!visit[i]) check=true ;
        if(check)
          {
            for(int i=50 ; i>=2 ; i--)
              if(prime(i))
                {
                  for(int j=1 ; j<=n ; j++)
                    if(__gcd(i, a[j])==1)
                      {
                        if(j==n) a[1]=i ;
                        else a[j+1]=i ;
                        check=false ;
                        break ;
                      }
                  if(!check) break ;
                }
            cout<< 1 << endl ;
          }
        else cout<< 0 << endl ;
        for(int i=1 ; i<=n ; i++) cout<< a[i] << " " ;
        cout<< endl ;
      }
  }
