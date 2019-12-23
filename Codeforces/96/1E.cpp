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

class mcbm{
  public:
    int n, m, cost ;
    vector<int> u, v, p, way, ans ;
    vector<vector<int>> a ;

    mcbm(){}
    mcbm(int n, int m) : n(n), m(m), u(n+1, 0), v(m+1, 0),
    p(m+1, 0), way(m+1, 0), ans(n+1), a(n+1, vector<int>(m+1, inf)) { }

    void match()
      {
        for(int i=1 ; i<=n ; ++i)
          {
            p[0]=i ;
            int j0=0 ;
            vector<int> minv(m+1, inf) ;
            vector<char> used(m+1, false) ;
            do
              {
                used[j0]=true ;
                int i0=p[j0], delta=inf, j1 ;
                for(int j=1 ; j<=m ; ++j)
                  if(!used[j])
                    {
                      int cur=a[i0][j]-u[i0]-v[j] ;
                      if(cur<minv[j]) minv[j]=cur, way[j]=j0 ;
                      if(minv[j]<delta) delta=minv[j], j1=j ;
                    }
                for(int j=0 ; j<=m ; ++j)
                  if(used[j]) u[p[j]]+=delta, v[j]-=delta;
                  else minv[j]-=delta ;
                j0=j1;
              } while(p[j0]!=0) ;
            do
              {
                int j1=way[j0] ;
                p[j0]=p[j1] ;
                j0=j1 ;
              } while(j0) ;
          }

        for(int j=1 ; j<=m ; ++j) ans[p[j]]=j ;

        cost=-v[0] ;
      }

		int get_cost() { return cost ; }
		vector<int> get_assignment() { return ans ; }
} ;

int fx(int x)
  {
    int res=0 ;
    while(x) res+=(x%2), x/=2 ;
    return res ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, m, N, M, a[300] ;
    cin>> n >> m ;
    for(int i=1 ; i<=n ; i++) cin>> a[i] ;
    N=n ;
    M=n+m ;
    mcbm f(N, M) ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<i ; j++)
        if(a[i]!=a[j]) f.a[i][j]=fx(a[i]) ;
        else f.a[i][j]=0 ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        f.a[i][j+n]=fx(a[i]) ;
    f.match() ;
    vi temp=f.get_assignment() ;
    map<int, char> var ;
    int lines=0 ;
    for(int i=1 ; i<=n ; i++)
      if(temp[i]>n)
        {
          var[i]=(temp[i]-n-1+'a') ;
          lines+=2 ;
        }
      else
        {
          var[i]=var[temp[i]] ;
          if(a[i]==a[temp[i]]) lines++ ;
          else lines+=2 ;
        }
    cout<< lines << " " << f.get_cost() << endl ;
    for(int i=1 ; i<=n ; i++)
    if(temp[i]>n)
      {
        cout<< var[i] << "=" << a[i] << endl ;
        cout<< "print(" << var[i] << ")" << endl ;
      }
    else
      {
        if(a[i]==a[temp[i]]) cout<< "print(" << var[i] << ")" << endl ;
        else
          {
            cout<< var[i] << "=" << a[i] << endl ;
            cout<< "print(" << var[i] << ")" << endl ;
          }
      }
  }
