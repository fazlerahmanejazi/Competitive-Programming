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

int n, Q, M, u, v ;
vi val, p, a ;

int getBit(int x, int i) { return x&(1<<i) ;}

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
    if(x!=y) p[x]=y ;
  }

void solve(int idx, vi a)
  {
    if(idx<0)
      {
        for(int i=1 ; i<a.size() ; i++) unionset(a[i], a[i-1]) ;
        return ;
      }
    vi b, c ;
    for(int i=0 ; i<a.size() ; i++)
      if(getBit(val[a[i]], idx)) b.pb(a[i]) ;
      else c.pb(a[i]) ;
    if(getBit(M, idx))
      {
        for(int i=1 ; i<b.size() ; i++) unionset(b[i], b[i-1]) ;
        for(int i=1 ; i<c.size() ; i++) unionset(c[i], c[i-1]) ;
        solve(idx-1, a) ;
      }
    else
      {
        if(!b.empty()) solve(idx-1, b) ;
        if(!c.empty()) solve(idx-1, c) ;
      }

  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> M >> Q ;
    val.resize(n+1) ;
    p.resize(n+1) ;
    for(int i=1 ; i<=n ; i++) cin>> val[i], p[i]=i, a.pb(i) ;
    solve(30, a) ;
    for(int i=1 ; i<=Q ; i++)
      {
        cin>> u >> v ;
        if(same(u, v)) cout<< "YES" << endl ;
        else cout<< "NO" << endl ;
      }
  }
