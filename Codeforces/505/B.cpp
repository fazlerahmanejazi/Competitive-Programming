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

lli n, x, y ;
set<lli> p ;
vector<pair<lli, lli>> a ;

void calc(lli x)
  {
    for(lli i=2 ; i*i<=x ; i++)
      if(!(x%i))
        {
          p.insert(i) ;
          while(!(x%i)) x/=i ;
        }
    if(x!=1) p.insert(x) ;
  }

bool check(lli x)
  {
    for(int i=0 ; i<n ; i++) if(a[i].fi%x && a[i].se%x) return false ;
    return true ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=0 ; i<n ; i++) cin>> x >> y, a.pb(mp(x, y)) ;
    calc(a[0].fi) ; calc(a[0].se) ;
    for(auto i:p) if(check(i)) return cout<< i, 0 ;
    cout<< -1 ;
  }
