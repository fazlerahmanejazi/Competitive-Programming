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

#define ld long double

lli n, m, r, k, X[100005], Y[100005], c, x, y, mx=1, ans ;
ld d ;
priority_queue<tuple<lli, lli, lli>> pq ;
map<pii, bool> taken ;

lli make(lli Z[], lli p)
  {
    lli res=0 ;
    c=min(r, p-r+1) ;
    for(int i=1 ; i<=p ; i++) Z[i]=c ;
    for(lli i=1 ; i<=c ; i++)
      {
        Z[i]=min(Z[i], i) ;
        Z[p-i+1]=min(Z[p-i+1], i) ;
      }
    for(int i=1 ; i<=p ; i++) res=max(res, Z[i]) ;
    return res ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m >> r >> k ;
    mx*=make(X, n) ; mx*=make(Y, m) ;
    x=(n+1)/2 ; y=(m+1)/2 ;
    d=(n-r+1)*(m-r+1) ;
    pq.push(mt(mx, x, y)) ;
    taken[mp(x, y)]=true ;
    while(k--)
      {
        tie(mx, x, y)=pq.top() ; pq.pop() ;
        ans+=mx ;
        if(x+1<=n && !taken[mp(x+1, y)]) pq.push(mt(mx-abs(X[x+1]-X[x])*Y[y], x+1, y)), taken[mp(x+1, y)]=true ;
        if(y+1<=m && !taken[mp(x, y+1)]) pq.push(mt(mx-abs(Y[y+1]-Y[y])*X[x], x, y+1)), taken[mp(x, y+1)]=true ;
        if(x-1>=1 && !taken[mp(x-1, y)]) pq.push(mt(mx-abs(X[x-1]-X[x])*Y[y], x-1, y)), taken[mp(x-1, y)]=true ;
        if(y-1>=1 && !taken[mp(x, y-1)]) pq.push(mt(mx-abs(Y[y-1]-Y[y])*X[x], x, y-1)), taken[mp(x, y-1)]=true ;
      }
    cout<< fixed << setprecision(9) << ans/d ;
  }
