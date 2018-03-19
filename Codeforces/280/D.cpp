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

lli n, x, y, l, r, m, s, ans, a ;

lli check(lli m)
  {
    a=m/x+m/y ;
    if(a>=s) return true ;
    return false ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> x >> y ;
    swap(x, y) ;
    while(n--)
      {
        cin>> s ;
        l=0 ; ans=r=1e18 ;
        while(l<=r)
          {
            m=(l+r)/2 ;
            if(check(m)) r=m-1, ans=min(ans, m) ;
            else l=m+1 ;
          }
        if(!(ans%x) && !(ans%y)) cout<< "Both" << endl ;
        else if(!(ans%x)) cout<< "Vanya" << endl ;
        else cout<< "Vova" << endl ;
      }
  }
