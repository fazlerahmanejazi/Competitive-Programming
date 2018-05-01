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

lli N=100020 ;

lli n, q, l, r, x, y, z, pos ;
vlli a(N), p(N), ans(N), f(40, -1) ;
vector<vpii> Q(N) ;

void pre()
  {
    p[0]=1 ;
    for(int i=1 ; i<100010 ; i++) p[i]=p[i-1]*2%mod ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    pre() ;
    cin>> n >> q ;
    for(int i=1 ; i<=n ; i++) cin>> a[i] ;
    for(int i=0 ; i<q ; i++)
      {
        cin>> l >> r ;
        Q[l].pb(mp(r, i)) ;
      }
    for(int i=1 ; i<=n ; i++)
      {
        x=a[i] ;
        pos=-1 ;
        for(int j=19 ; j>=0 ; j--)
          {
            if(1<<j & x)
              {
                if(f[j]==-1)
                  {
                    pos=j ;
                    break ;
                  }
                else x^=f[j] ;
              }
          }
        if(pos==-1) ++z ;
        else f[pos]=x ;
        for(auto e:Q[i])
          {
            y=e.fi ;
            for(int j=19 ; j>=0 ; j--)
              {
                if(1<<j & y)
                  {
                    if(f[j]==-1) break ;
                    y^=f[j] ;
                  }
              }
            ans[e.se]=(y==0?p[z]:0) ;
          }
      }
    for(int i=0 ; i<q ; i++) cout<< ans[i] << endl ;
  }
