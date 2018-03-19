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

lli n, T, idx, l, r, m, t, res, a ;
vector<tuple<lli, lli, lli>> data ;

bool check(lli x)
  {
    vlli temp ;
    lli ans=0 ;
    for(int i=0 ; i<n ; i++)
      {
        tie(a, t, idx)=data[i] ;
        if(a>=x) temp.pb(t) ;
      }
    sort(all(temp)) ;
    if(temp.size()<x) return false ;
    for(int i=0 ; i<x ; i++) ans+=temp[i] ;
    if(ans<=T) return true ;
    return false ;
  }

void construct(lli x)
  {
    vpii temp ;
    for(int i=0 ; i<n ; i++)
      {
        tie(a, t, idx)=data[i] ;
        if(a>=x) temp.pb(mp(t, idx)) ;
      }
    sort(all(temp)) ;
    for(int i=0 ; i<x ; i++) cout<< temp[i].se << " " ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> T ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> a >> t ;
        data.pb(mt(a, t, i)) ;
      }
    l=0 ; r=n ;
    while(l<=r)
      {
        m=(l+r)/2 ;
        if(check(m)) l=m+1, res=max(res, m) ;
        else r=m-1 ;
      }
    cout<< res << endl << res << endl ;
    construct(res) ;
  }
