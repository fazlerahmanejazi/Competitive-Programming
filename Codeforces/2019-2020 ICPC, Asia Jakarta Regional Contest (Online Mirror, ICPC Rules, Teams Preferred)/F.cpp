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

int n, m, u, v, N, ans=-1 ;
vi val(5000), sz(5000) ;
vvi adj(5000) ;

struct tree {
  int n;
  vector<vector<int>> adj;
  tree(int n) : n(n), adj(n) { }
  void add_edge(int src, int dst) {
    adj[src].push_back(dst);
    adj[dst].push_back(src);
  }
  vector<int> centers() {
    vector<int> prev;
    int u = 0;
    for (int k = 0; k < 2; ++k) { // double sweep
      queue<int> que;
      prev.assign(n, -1);
      que.push(prev[u] = u);
      while (!que.empty()) {
        u = que.front(); que.pop();
        for (auto v: adj[u]) {
          if (prev[v] >= 0) continue;
          que.push(v);
          prev[v] = u;
        }
      }
    }
    vector<int> path = {u}; // median on a path
    while (u != prev[u])
      path.push_back(u = prev[u]);
    int m = path.size();
    if (m % 2 == 0) return {path[m/2-1], path[m/2]};
    else            return {path[m/2]};
  }

  vector<vector<int>> layer;
  vector<int> prev;
  int levelize(int r) { // split vertices into levels
    prev.assign(n,-1); prev[r] = n;
    layer = {{r}};
    while (1) {
      vector<int> next;
      for (int u: layer.back()) {
        for (int v: adj[u]) {
          if (prev[v] >= 0) continue;
          prev[v] = u;
          next.push_back(v);
        }
      }
      if (next.empty()) break;
      layer.push_back(next);
    }
    return layer.size();
  }
};

bool isomorphic(tree S, int s, tree T, int t) {
  if (S.n != T.n) return false;
  if (S.levelize(s) != T.levelize(t)) return false;

  vector<vector<int>> longcodeS(S.n+1), longcodeT(T.n+1);
  vector<int> codeS(S.n), codeT(T.n);
  for (int h = S.layer.size()-1; h >= 0; --h) {
    map<vector<int>, int> bucket;
    for (int u: S.layer[h]) {
      sort(all(longcodeS[u]));
      bucket[longcodeS[u]] = 0;
    }
    for (int u: T.layer[h]) {
      sort(all(longcodeT[u]));
      bucket[longcodeT[u]] = 0;
    }
    int id = 0;
    for (auto &p: bucket) p.se = id++;
    for (int u: S.layer[h]) {
      codeS[u] = bucket[longcodeS[u]];
      longcodeS[S.prev[u]].push_back(codeS[u]);
    }
    for (int u: T.layer[h]) {
      codeT[u] = bucket[longcodeT[u]];
      longcodeT[T.prev[u]].push_back(codeT[u]);
    }
  }
  return codeS[s] == codeT[t];
}

bool isomorphic(tree S, tree T) {
  auto x = S.centers(), y = T.centers();
  if (x.size() != y.size()) return false;
  if (isomorphic(S, x[0], T, y[0])) return true;
  return x.size() > 1 && isomorphic(S, x[1], T, y[0]);
}

vi find_centroids(vvi &adj)
    {
      vi centroid, sz(n+1) ;
      function<void (int, int)> dfs=[&](int u, int prev)
        {
          sz[u]=1 ;
          bool is_centroid=true ;
          for(auto v:adj[u])
          if(v!=prev)
            {
              dfs(v, u) ;
              sz[u]+=sz[v];
              if(sz[v]>n/2) is_centroid=false ;
            }
          if(n-sz[u]>n/2) is_centroid=false ;
          if(is_centroid) centroid.pb(u) ;
        } ;
      dfs(1, -1) ;
      return centroid ;
    }

void dfs(int u, int prev, tree &curr)
  {
    val[u]=N++ ;
    for(auto v:adj[u])
      if(v!=prev)
        {
          dfs(v, u, curr) ;
          curr.add_edge(val[u], val[v]) ;
        }
  }

void dfs_sz(int u, int prev)
  {
    sz[u]=1 ;
    for(auto v:adj[u])
      if(v!=prev)
        {
          dfs_sz(v, u) ;
          sz[u]+=sz[v] ;
        }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    vi centroids=find_centroids(adj) ;
    for(auto u:centroids)
      {
        vector<tree> trees ;
        for(int i=1 ; i<=n ; i++) sz[i]=0 ;
        for(auto v:adj[u])
          {
            N=0 ;
            dfs_sz(v, u) ;
            tree curr(sz[v]) ;
            dfs(v, u, curr) ;
            trees.pb(curr) ;
          }
        bool good_point=true ;
        for(int i=1 ; i<trees.size() ; i++) if(!isomorphic(trees[i], trees[i-1])) good_point=false ;
        if(good_point) ans=max(ans, (int)trees.size()) ;
      }
    cout<< ans ;
  }
