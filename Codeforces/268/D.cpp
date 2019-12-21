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


lli n, a, b, u, v ;
map<lli, lli> idx ;
vlli p(100010) ;

class sat_2{
  public:
    int n, m, tag;
    vector<vector<int>> g, grev;
    vector<bool> val;
    vector<int> st;
    vector<int> comp;

    sat_2(){}
    sat_2(int n) : n(n), m(2 * n), tag(0), g(m + 1), grev(m + 1), val(n + 1) { }

    void add_edge(int u, int v) { //u or v
      auto make_edge = [&](int a, int b) {
        if(a < 0) a = n - a;
        if(b < 0) b = n - b;
        g[a].push_back(b);
        grev[b].push_back(a);
      };
      //cout<< -u << " " << v << endl ;
      //cout<< -v << " " << u << endl ;
      make_edge(-u, v);
      make_edge(-v, u);
    }

    void truth_table(int u, int v, vector<int> t) {
      for(int i = 0; i < 2; i ++) for(int j = 0; j < 2; j ++) {
        if(!t[i * 2 + j])
          add_edge((2 * (i ^ 1) - 1) * u, (2 * (j ^ 1) - 1) * v);
      }
    }

    void dfs(int u, vector<vector<int>> & G, bool first) {
      comp[u] = tag;
      for(int & i : G[u]) if(comp[i] == -1)
        dfs(i, G, first);
      if(first) st.push_back(u);
    }

    bool satisfiable() {
      tag = 0; comp.assign(m + 1, -1);
      for(int i = 1; i <= m; i ++) {
        if(comp[i] == -1)
          dfs(i, g, true);
      }reverse(all(st));

      tag = 0; comp.assign(m + 1, -1);
      for(int & i : st) {
        if(comp[i] != -1) continue;
        tag++;
        dfs(i, grev, false);
      }

      for(int i = 1; i <= n; i ++) {
        if(comp[i] == comp[i + n]) return false;
        val[i] = comp[i] > comp[i + n];
      }
      for(int i=1 ; i<=n ; i++)
        if(val[i] && (idx.find(a-p[i])!=idx.end() || val[idx[a-p[i]]]!=val[i])) return false ;
        else if(!val[i] && (idx.find(b-p[i])!=idx.end() || val[idx[b-p[i]]]!=val[i])) return false ;
      return true;
    }
    void print_solution()
      {
        cout<< "YES" << endl ;
        for(int i=1 ; i<=n ; i++) cout<< val[i] << " " ;
      }
};

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> a >> b ;
    for(int i=1 ; i<=n ; i++) cin>> p[i], idx[p[i]]=i ;
    sat_2 check(n) ;
    bool pos=true ;
    for(int i=1 ; i<=n ; i++)
      {
        u=p[i] ;
        v=a-p[i] ;
        if(idx.find(v)!=idx.end())
          check.truth_table(idx[u], idx[v], {1, 0, 0, 1}) ;
        v=b-p[i] ;
        if(idx.find(v)!=idx.end())
          check.truth_table(idx[u], idx[v], {1, 0, 0, 1}) ;
      }
    if(check.satisfiable()) check.print_solution() ;
    else cout<< "NO" ;
  }
