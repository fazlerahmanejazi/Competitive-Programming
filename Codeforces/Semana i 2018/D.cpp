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

bool cmp(pair<int, long double> p, pair<int, long double> q)
  {
    return (p.fi+(q.fi*p.se))<(q.fi+(p.fi*q.se)) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, w, x ;
    long double y, r=1, ans=0 ;
    cin>> n >> w ;
    vector<pair<int, long double>> a ;
    for(int i=0 ; i<n ; i++) cin>> x >> y, a.pb(mp(x, y)) ;
    sort(all(a), cmp) ;
    ans=a[0].fi ;
    r*=a[0].se ;
    for(int i=1 ; i<n ; i++) ans+=r*a[i].fi, r*=a[i].se ;
    ans*=w ;
    cout<< fixed << setprecision(9) << ans << endl ;
  }
