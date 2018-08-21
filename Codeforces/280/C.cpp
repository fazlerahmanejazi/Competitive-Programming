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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli n, r, avg, canIncrease, sum=0, need, ans=0, x ;
    cin>> n >> r >> avg ;
    vlli a(n) ;
    avg*=n ;
    vector<pair<lli, lli>> b ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> a[i]>> x ;
        b.pb(mp(x, i)) ;
        sum+=a[i] ;
      }
    sort(all(b)) ;
    for(auto i:b)
      {
        canIncrease=max(r-a[i.se], 0LL) ;
        need=max(avg-sum, 0LL) ;
        x=min(canIncrease, need) ;
        sum+=x ;
        ans+=x*i.fi ;
      }
    cout<< ans ;
  }
