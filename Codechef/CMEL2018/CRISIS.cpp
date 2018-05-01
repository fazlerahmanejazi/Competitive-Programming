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
using pii = pair<lli, lli> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

#define ld long double

bool check(vpii &a, ld x, lli k)
  {
    ld res=0 ;
    vector<ld> b ;
    for(auto i:a) b.pb(i.fi-x*i.se) ;
    sort(all(b)) ;
    reverse(all(b)) ;
    for(int i=0 ; i<k ; i++) res+=b[i] ;
    if(res<0) return false ;
    return true ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli T ;
    cin>> T ;
    while(T--)
      {
        lli n, k, x ;
        ld l=0, r=10010, m ;
        cin>> n >> k ;
        vpii a ;
        for(int i=1 ; i<=n ; i++) cin>> x, a.pb(mp(x*i, i)) ;
        while(abs(l-r)>eps)
          {
            m=(l+r)/2 ;
            if(check(a, m, k)) l=m ;
            else r=m ;
          }
        cout<< fixed << setprecision(15) << l << endl ;
      }
  }
