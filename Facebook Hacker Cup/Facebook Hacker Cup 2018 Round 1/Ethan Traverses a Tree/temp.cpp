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

template<class T, int SZ> struct DSU
  {
    T p[SZ+1] ;
    DSU() { for(int i=0 ; i<=SZ ; i++) p[i]=i ; }
    T find(T i)
      {
        if(i!=p[i]) p[i]=find(p[i]) ;
        return p[i] ;
      }
    bool same(T i, T j) { return find(i)==find(j) ; }
    void unionset(T i, T j)
      {
        T x=find(i) ; T y=find(j) ;
        if(x!=y) p[x]=y ;
      }
  } ;

int n, k, C, u, v, x, A[2010], B[2010], L[2010] ;
bool pos ;
vi post, pre, color ;

void postOrder(int u)
  {
    if(!u) return ;
    postOrder(A[u]) ;
    postOrder(B[u]) ;
    post.pb(u) ;
  }

void preOrder(int u)
  {
    if(!u) return ;
    pre.pb(u) ;
    preOrder(A[u]) ;
    preOrder(B[u]) ;
  }

void init()
  {
    post.clear() ; pre.clear() ;
    pos=true ;
    x=1 ;
    color.assign(n+1, 0) ;
    C=n ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        DSU<int, 2010> p ;
        cin>> n >> k ;
        for(int i=1 ; i<=n ; i++) cin>> A[i] >> B[i] ;
        init() ;
        preOrder(1) ;
        postOrder(1) ;
        for(int i=0 ; i<n ; i++) if(!p.same(pre[i], post[i])) p.unionset(pre[i], post[i]), C-- ;
        if(C<k) pos=false ;
        for(int i=1 ; i<=n ; i++)
          if(!color[p.find(i)])
            {
              color[p.find(i)]=x++ ;
              if(x>k) x=1 ;
            }
        if(pos)
          {
            cout<< "Case #" << tc << ": " ;
            for(int i=1 ; i<=n ; i++) cout<< color[p.find(i)] << " " ;
            cout<< endl ;
          }
        else cout<< "Case #" << tc << ": " << "Impossible" << endl ;
      }
  }
