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


struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

vb isprime ;
vlli prime ;

void seive()
  {
    isprime.assign(100010, true) ;
    for(int i=2 ; i*i<=100000 ; i++)
      if(isprime[i])
        for(int j=i*i ; j<=100000 ; j+=i)
          isprime[j]=false ;
    prime.pb(2) ;
    for(int i=3 ; i<=100000 ; i+=2) if(isprime[i]) prime.pb(i) ;
  }


int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    seive() ;
    lli n, m, u, v, w, a[110], x[110], y[110], k1, k2, p, q, ans=0 ;
    cin>> n >> m ;
    for(int i=1 ; i<=n ; i++) cin>> a[i] ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>> k1 >> k2 ;
        if(k1%2) swap(k1, k2) ;
        x[i]=k1 ;
        y[i]=k2 ;
      }
    for(auto z:prime)
      {
        Dinic f(n+3, n+1, n+2) ;
        for(int i=1 ; i<=m ; i++)
          {
            k1=x[i] ;
            k2=y[i] ;
            p=a[k1] ;
            q=a[k2] ;
            int cntp=0, cntq=0 ;
            while(p%z==0) cntp++, p/=z ;
            while(q%z==0) cntq++, q/=z ;
            f.add_edge(k1, k2, min(cntp, cntq)) ;
          }
        for(int i=2 ; i<=n ; i+=2)
          {
            int cnt=0 ;
            while(a[i]%z==0) a[i]/=z, cnt++ ;
            f.add_edge(n+1, i, cnt) ;
          }
        for(int i=1 ; i<=n ; i+=2)
          {
            int cnt=0 ;
            while(a[i]%z==0) a[i]/=z, cnt++ ;
            f.add_edge(i, n+2, cnt) ;
          }
        ans+=f.flow() ;
      }
    Dinic f(n+3, n+1, n+2) ;
    for(int i=1 ; i<=m ; i++) if(a[x[i]]==a[y[i]] && a[x[i]]!=1) f.add_edge(x[i], y[i], 1) ;
    for(int i=2 ; i<=n ; i+=2) if(a[i]!=1) f.add_edge(n+1, i, 1) ;
    for(int i=1 ; i<=n ; i+=2) if(a[i]!=1) f.add_edge(i, n+2, 1) ;
    ans+=f.flow() ;
    cout<< ans ;

  }
