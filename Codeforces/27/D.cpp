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

      return true;
    }

    void answer(){
      for(int i = 1; i <= n; i ++) cout << (val[i] ? 'i' : 'o') ;
    }
};

bool intersecting(int a1, int b1, int a2, int b2)
  {
    if(a1>b1) swap(a1, b1) ;
    if(a2>b2) swap(a2, b2) ;
    if(a1==a2 || a1==b2 || b1==a2 || b1==b2) return false ;
    if(a1>a2) swap(a1, a2), swap(b1, b2) ;
    if(a2<b1 && b2>b1) return true ;
    return false ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, m, a[200], b[200], x ;
    cin>> n >> m ;
    vi tt({0, 1, 1, 0}) ;
    sat_2 checker(m) ;
    for(int i=1 ; i<=m ; i++) cin>> a[i] >> b[i] ;
    for(int i=1 ; i<=m ; i++)
      for(int j=i+1 ; j<=m ; j++)
        if(intersecting(a[i], b[i], a[j], b[j]))
          checker.truth_table(i, j, tt) ;
    if(checker.satisfiable()) checker.answer() ;
    else cout<< "Impossible" ;
  }
