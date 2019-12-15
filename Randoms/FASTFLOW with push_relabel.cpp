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

template<typename flow_t = long long>
struct PushRelabel {
  struct Edge {
      int to, rev;
      flow_t f, c;
  };
  vector<vector<Edge> > g;
  vector<flow_t> ec;
  vector<Edge*> cur;
  vector<vector<int> > hs;
  vector<int> H;
  PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}
  void add_edge(int s, int t, flow_t cap, flow_t rcap=0) {
      if (s == t) return;
      Edge a = {t, (int)g[t].size(), 0, cap};
      Edge b = {s, (int)g[s].size(), 0, rcap};
      g[s].push_back(a);
      g[t].push_back(b);
  }
  void add_flow(Edge& e, flow_t f) {
      Edge &back = g[e.to][e.rev];
      if (!ec[e.to] && f)
          hs[H[e.to]].push_back(e.to);
      e.f += f; e.c -= f;
      ec[e.to] += f;
      back.f -= f; back.c += f;
      ec[back.to] -= f;
  }
  flow_t max_flow(int s, int t) {
      int v = g.size();
      H[s] = v;
      ec[t] = 1;
      vector<int> co(2*v);
      co[0] = v-1;
      for(int i=0;i<v;++i) cur[i] = g[i].data();
      for(auto &e:g[s]) add_flow(e, e.c);
      if(hs[0].size())
      for (int hi = 0;hi>=0;) {
          int u = hs[hi].back();
          hs[hi].pop_back();
          while (ec[u] > 0) // discharge u
              if (cur[u] == g[u].data() + g[u].size()) {
                  H[u] = 1e9;
                  for(auto &e:g[u])
                      if (e.c && H[u] > H[e.to]+1)
                          H[u] = H[e.to]+1, cur[u] = &e;
                  if (++co[H[u]], !--co[hi] && hi < v)
                      for(int i=0;i<v;++i)
                          if (hi < H[i] && H[i] < v){
                              --co[H[i]];
                              H[i] = v + 1;
                          }
                  hi = H[u];
              } else if (cur[u]->c && H[u] == H[cur[u]->to]+1)
                  add_flow(*cur[u], min(ec[u], cur[u]->c));
              else ++cur[u];
          while (hi>=0 && hs[hi].empty()) --hi;
      }
      return -ec[s];
  }
};


int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, m, u, v, w ;
    cin>> n >> m ;
    PushRelabel<> fl(n+1) ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>> u >> v >> w ;
        fl.add_edge(u, v, w, w) ;
      }
    cout<< fl.max_flow(1, n) ;
  }
