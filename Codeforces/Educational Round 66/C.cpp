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

lli check(lli x, vlli &a, lli k)
  {
    vlli temp ;
    for(auto i:a) temp.pb(abs(x-i)) ;
    sort(all(temp)) ;
    return temp[k] ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        lli n, k, lo, hi, mn, ans ;
        cin>> n >> k ;
        vlli a(n) ;
        for(int i=0 ; i<n ; i++) cin>> a[i] ;
        lo=0 ; hi=a.back() ;
        while(lo<hi-2)
          {
            lli m1=(lo*2+hi)/3 ;
            lli m2=(lo+hi*2)/3 ;
            if(check(m1, a, k)<check(m2, a, k)) hi=m2 ;
            else lo=m1 ;
          }
        mn=check(lo, a, k) ;
        ans=lo ;
        for(int i=lo ; i<=hi ; i++) if(check(i, a, k)<mn) mn=check(i, a, k), ans=i ;
        cout<< ans << endl ;
      }
  }
