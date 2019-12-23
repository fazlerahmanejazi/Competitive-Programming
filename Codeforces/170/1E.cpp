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

template <int xn, int xe> struct mcmf
  {
    int head[xn], next[xe], to[xe], fl[xe], N, E, q[xn], fa[xn], ent[xn], in[xn];
    double dis[xe], co[xe];
    inline void add(int u, int v, int f, double c)
      {
        next[E]=head[u], to[E]=v, fl[E]=f, co[E]=c, head[u]=E++;
        next[E]=head[v], to[E]=u, fl[E]=0, co[E]=-c, head[v]=E++;
      }
    void clear(int n)
      {
        N=n, E=0;
        for (int i=0; i < n; i++)
        head[i]=-1;
      }
    bool spfa()
      {
        for(int i=0; i < N; i++) dis[i]=1e10, in[i]=0;
        dis[0]=0;
        in[0]=1;
        q[0]=0;
        int H=-1, T=0;
        while(H!=T)
          {
            if(++H==xn)
            H=0;
            int u=q[H];
            in[u]=0;
            for(int e=head[u]; ~e; e=next[e])
            if(fl[e] && dis[to[e]]>dis[u]+co[e])
              {
                dis[to[e]]=dis[u]+co[e];
                fa[to[e]]=u;
                ent[to[e]]=e;
                if(!in[to[e]])
                  {
                    if(++T==xn)
                    T=0;
                    in[q[T]=to[e]]=1;
                  }
              }
          }
        return dis[N-1]<5e9;
      }
    std::pair<int, double> operator () ()
      {
        int f=0;
        double r=0;
        while (spfa())
          {
            f++;
            r+=dis[N-1];
            for(int i=N-1; i; i=fa[i])
              {
                fl[ent[i]]--;
                fl[ent[i]^1]++;
              }
          }
        return {f, r};
      }
  };

mcmf<1000, 1000000> f ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, N, E, source, sink ;
    long double x[500], y[500] ;
    cin>> n ;
    f.clear(n+n+2) ;
    for(int i=1 ; i<=n ; i++) cin>> x[i] >> y[i] ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=n ; j++)
        if(y[i]>y[j])
          f.add(i, n+j, 1,  sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]))) ;
    for(int i=1 ; i<=n ; i++) f.add(0, i, 2, 0), f.add(n+i, n+n+1, 1, 0) ;
    auto ans=f() ;
    if(ans.fi==n-1) cout<< fixed << setprecision(12) << ans.se << endl ;
    else cout<< -1 ;
  }
