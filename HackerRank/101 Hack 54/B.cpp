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

lli n, q, w, v, p, t, u, idx ;
vlli stop ;

ld getTime(ld lim, lli idx)
  {
    ld res=INF, curr ;
    lli l=0, r=1e9, m ;
    while(l<=r)
      {
        m=(l+r)/2 ;
        curr=m*w+((1.0*stop[idx])/(1.0*v)) ;
        if(curr>=lim) r=m-1, res=min(res, curr) ;
        else l=m+1 ;
      }
    return res ;
  }

ld solve()
  {
    vector<ld> ans ;
    ld res, curr, busTime, personTime, y ;
    if(u>=v)
      {
        res=t+(1.0*(stop[n-1]-p)/(1.0*u)) ;
        return res ;
      }
    res=t+(1.0*(stop[n-1]-p)/(1.0*u)) ;
    ans.pb(res) ;
    idx=upper_bound(all(stop), p)-stop.begin() ;
    personTime=(1.0*abs(stop[idx]-p))/(1.0*u)+t ;
    busTime=getTime(personTime, idx) ;
    if(personTime<=busTime)
      {
        res=busTime+((1.0*(stop[n-1]-stop[idx]))/(1.0*v)) ;
        ans.pb(res) ;
      }
    idx-- ;
    if(idx>=0)
      {
        personTime=(1.0*abs(stop[idx]-p))/(1.0*u)+t ;
        busTime=getTime(personTime, idx) ;
        if(personTime<=busTime)
          {
            res=busTime+((1.0*(stop[n-1]-stop[idx]))/(1.0*v)) ;
            ans.pb(res) ;
          }
      }
    sort(all(ans)) ;
    return ans[0] ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    stop.resize(n) ;
    for(int i=0 ; i<n ; i++) cin>> stop[i] ;
    cin>> w >> v >> q ;
    for(int i=0 ; i<q ; i++)
      {
        cin>> p >> t >> u ;
        ld res=solve() ;
        cout<< fixed << setprecision(9) << res << endl ;
      }
  }
