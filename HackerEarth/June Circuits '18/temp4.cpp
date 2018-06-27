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

lli n, m, u, v, x, w, idx, curr ;
vector<vpii> adj ;
vvi par ;
vlli dist, h, newDist ;


void init()
  {
    adj.resize(n+1) ; h.assign(n+1, 0) ;
    par.assign(n+1, vi(22, 0)) ;
    dist.resize(n+1) ;
    newDist.resize(n+1) ;
  }

void dfs(int u, int p, lli D)
  {
    par[u][0]=p ;
    dist[u]=D ;
    for(int i=1 ; i<=31-__builtin_clz(n) ; i ++) par[u][i]=par[par[u][i-1]][i-1] ;
    for(auto v:adj[u])
      if(v.fi!=p)
        {
          h[v.fi]=h[u]+1 ;
          dfs(v.fi, u, D+v.se) ;
        }
}

int anc(int x, int d)
  {
    if(!d) return x ;
    for(int i=31-__builtin_clz(d) ; i>=0 ; i--) if(d&(1<<i)) x=par[x][i] ;
    return x ;
  }

int lca(int x, int y)
  {
    if(h[x]>h[y]) x=anc(x, h[x]-h[y]) ;
    else if(h[y]>h[x]) y=anc(y, h[y]-h[x]) ;
    if(x==y) return x ;
    for(int i=31-__builtin_clz(h[x]) ; i>=0 ; i--) if(par[x][i]!=par[y][i]) x=par[x][i], y=par[y][i] ;
    return par[x][0] ;
  }

lli get(int u, int v)
  {
    lli res=dist[u]+dist[v]-2*dist[lca(u, v)] ;
    return res ;
  }


int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    init() ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v >> w ;
        adj[u].pb(mp(v, w)) ;
        adj[v].pb(mp(u, w)) ;
      }
    dfs(1, 0, 0) ;
    lli dp[n+1]; dp[0] = 0;

    vector<pair<int, int> > v; // start pos, best-k
    v.push_back(make_pair(0, 0));

    for (int x=1; x <= n; x++) {
        // Find the value of dp[x]
        int k = (--lower_bound(v.begin(), v.end(), make_pair(x+1, 0)))->second;
        dp[x] = dp[k] + get(k, x);

        // Update the segments
        for (int i = v.size()-1; i >= 0; i--) {
            int y = v[i].first, oldk = v[i].second;
            // Case 1
            if (y > x && dp[x] + get(x, y) < dp[oldk] + get(oldk, y))
                v.pop_back();
            // Case 2
            else {
                int lo = y+1, hi = n+1;
                while(lo < hi) {
                    int mid = (lo+hi)/2;
                    if (dp[x] + get(x, mid) <= dp[oldk] + get(oldk, mid))
                        hi = mid;
                    else
                        lo = mid+1;
                }
                if (hi != n+1) v.push_back(make_pair(hi, x));
                break;
            }
        }
        if (v.size() == 0)
            v.push_back(make_pair(0, x));
        cout<< dp[x] << " " ;
    }
  }
