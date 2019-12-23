const int INF = 1e9;

class min_cost_flow{
  public:
    int N, K, s, t;
    vector<vector<int>> adj, capacity;
    vector<vector<long double>> cost ;

    min_cost_flow(int N, int K, int s, int t) : N(N), K(K), s(s), t(t),
    adj(N, vector<int>()), cost(N, vector<long double>(N, 0)), capacity(N, vector<int>(N, 0)) { }

    void addedge(int u, int v, int _cap, double _cost) {
        adj[u].push_back(v); adj[v].push_back(u);
        cost[u][v] = _cost; cost[v][u] = -_cost;
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
  }

};
