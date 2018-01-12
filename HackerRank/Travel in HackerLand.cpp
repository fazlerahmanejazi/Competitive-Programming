#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
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

int n, m, q, x, u, v, maxCrowd, y ;
vi type, p, ans, rnk ;
vvi test ;
vector<pair<int, pii>> edges, query ;
vpii range ;
vector<set<int>> T ;
set<int>::iterator it ;
bool check ;

void init()
  {
    type.resize(n+1) ;
    edges.resize(m+1) ;
    query.resize(q+1) ;
    range.resize(q+1) ;
    test.resize(m+2) ;
    T.resize(n+1) ;
    ans.assign(q+1, -1) ;
    for(int i=1 ; i<=q ; i++)
      {
        range[i].fi=1 ;
        range[i].se=m+1 ;
      }
  }

int find(int i)
  {
    if(i!=p[i]) p[i]=find(p[i]) ;
    return p[i] ;
  }
bool same(int i, int j)
  {
    return find(i)==find(j) ;
  }

void unionset(int i, int j)
  {
    int x=find(i) ; int y=find(j) ;
    if(x==y) return ;
    int par=y, child=x ;
    if(rnk[x]>rnk[y]) swap(par, child) ;
    int grt=x, lss=y ;
    if(T[y].size()>T[x].size()) swap(grt, lss) ;
    it=T[lss].begin() ;
    while(it!=T[lss].end())
      {
        T[grt].insert(*it) ;
        it++ ;
      }
    if(grt!=par) swap(T[grt], T[lss]) ;
    p[child]=par ;
    if(rnk[child]==rnk[par]) rnk[par]++ ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m >> q ;
    init() ;
    for(int i=1 ; i<=n ; i++)
      cin>> type[i] ;
    for(int i=1 ; i<=m ; i++)
      cin>> edges[i].se.fi >> edges[i].se.se >> edges[i].fi ;
    for(int i=1 ; i<=q ; i++)
      cin>> query[i].se.fi >> query[i].se.se >> query[i].fi ;
    sort(edges.begin()+1, edges.end()) ;
    while(1)
      {
        check=true ;
        for(int i=1 ; i<=n ; i++) p[i]=i ;
        T.clear() ; test.clear() ;
        test.resize(m+2) ; T.resize(n+1) ;
        rnk.assign(n+1, 0) ;
        for(int i=1 ; i<=n ; i++)
          T[i].insert(type[i]) ;
        for(int i=1 ; i<=q ; i++)
          if(range[i].fi!=range[i].se)
            test[(range[i].fi+range[i].se)/2].pb(i) ;
        maxCrowd=0 ;
        for(int i=1 ; i<=m ; i++)
          {
            u=edges[i].se.fi ; v=edges[i].se.se ;
            maxCrowd=max(maxCrowd, edges[i].fi) ;
            unionset(u, v) ;
            for(int j=0 ; j<test[i].size() ; j++)
              {
                x=test[i][j] ;
                check=false ;
                u=query[x].se.fi ; v=query[x].se.se ; y=query[x].fi ;
                if(same(u, v) && T[find(u)].size()>=y)
                  {
                    range[x].se=i ;
                    ans[x]=maxCrowd ;
                  }
                else range[x].fi=i+1 ;
              }
          }
        if(check) break ;
      }
    for(int i=1 ; i<=q ; i++)
      cout<< ans[i] << endl ;
  }
