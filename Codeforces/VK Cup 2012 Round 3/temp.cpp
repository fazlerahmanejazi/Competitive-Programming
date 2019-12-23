#include <bits/stdc++.h>
using namespace std ;

//#define inf 0x3f3f3f3f
//#define INF 1000111000111000111LL
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

const int INF = 1e9;
class min_cost_flow{
  public:
    int N, K, s, t;
    vector<vector<int>> adj, capacity;
    vector<vector<long double>> cost ;

    min_cost_flow(int N, int K, int s, int t) : N(N), K(K), s(s), t(t),
    adj(N, vector<int>()), cost(N, vector<long double>(N, 0)), capacity(N, vector<int>(N, 0)) { }

    void addedge(int u, int v, int _cap, double _cost) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u][v] = _cost;
        cost[v][u] = -_cost;
        capacity[u][v] = _cap;
    }

    void shortest_paths(int n, int v0, vector<long double>& d, vector<int>& p) {
        d.assign(n, INF);
        d[v0] = 0;
        vector<bool> inq(n, false);
        queue<int> q;
        q.push(v0);
        p.assign(n, -1);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inq[u] = false;
            for (int v : adj[u]) {
                if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                    d[v] = d[u] + cost[u][v];
                    p[v] = u;
                    if (!inq[v]) {
                        inq[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
  void solve() {
      int flow = 0;
      double cost = 0;
      vector<long double> d;
      vector<int> p;
      while (flow < K) {
          shortest_paths(N, s, d, p);
          if (d[t] == INF)
              break;

          // find max flow on that path
          int f = K - flow;
          int cur = t;
          while (cur != s) {
              f = min(f, capacity[p[cur]][cur]);
              cur = p[cur];
          }

          // apply flow
          flow += f;
          cost += f * d[t];
          cur = t;
          while (cur != s) {
              capacity[p[cur]][cur] -= f;
              capacity[cur][p[cur]] += f;
              cur = p[cur];
          }
      }
      if(flow==K) cout<< fixed << setprecision(12) << cost ;
      else cout<< -1 ;
  }

};

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, N, E, source, sink ;
    long double x[500], y[500] ;
    cin>> n ;
    min_cost_flow f(n+n+2, n-1, 0, n+n+1) ;
    for(int i=1 ; i<=n ; i++) cin>> x[i] >> y[i] ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=n ; j++)
        if(y[i]>y[j])
          f.addedge(i, n+j, 1,  sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]))) ;
    for(int i=1 ; i<=n ; i++) f.addedge(0, i, 2, 0), f.addedge(n+i, n+n+1, 1, 0) ;
    f.solve() ;
  }
