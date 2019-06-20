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
    lli n, d, idx ;
    cin>> n ;
    idx=n ;
    vector<pair<lli, lli>> a(n) ;
    for(int i=0 ; i<n ; i++) cin>> a[i].fi, a[i].se=i+1 ;
    if(n==2) return cout<< 1, 0 ;
    sort(all(a)) ;
    set<lli> temp ;

    temp.clear() ;
    temp.insert(a[2].fi-a[1].fi) ;
    for(int i=3 ; i<n ; i++) temp.insert(a[i].fi-a[i-1].fi) ;
    if(temp.size()<=1) return cout<< a[0].se, 0 ;

    temp.clear() ;
    temp.insert(a[2].fi-a[0].fi) ;
    for(int i=3 ; i<n ; i++) temp.insert(a[i].fi-a[i-1].fi) ;
    if(temp.size()<=1) return cout<< a[1].se, 0 ;

    d=a[1].fi-a[0].fi ;
    for(int i=2 ; i<n ; i++)
      if(a[i].fi-a[i-1].fi!=d)
        {
          idx=i ;
          break ;
        }

    temp.clear() ;
    for(int i=1 ; i<idx ; i++) temp.insert(a[i].fi-a[i-1].fi) ;
    if(idx+1<n && idx-1>=0) temp.insert(a[idx+1].fi-a[idx-1].fi) ;
    for(int i=idx+2 ; i<n ; i++) temp.insert(a[i].fi-a[i-1].fi) ;
    if(temp.size()<=1) return cout<< a[idx].se, 0 ;

    cout<< -1 ;

  }
