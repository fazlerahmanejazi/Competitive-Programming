#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using pii = pair<int, int> ;
using vi = vector<int> ;
using vpii = vector<pair<int, int>> ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, sumB, sumC, x ;
    cin>> n ;
    vi b, c ;
    vpii a ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        a.pb(mp(x, i+1)) ;
      }
    sort(all(a)) ;
    sumB=sumC=0 ;
    if(n%2)
      {
        b.pb(a[0].se) ;
        sumB=a[0].fi ;
      }
    for(int i=n-1 ; i-1>=0 ; i-=2)
      {
        if(sumB>sumC)
          {
            b.pb(a[i].se) ;
            sumB+=a[i].fi ;
            c.pb(a[i-1].se) ;
            sumC+=a[i-1].fi ;
          }
        else
          {
            b.pb(a[i-1].se) ;
            sumB+=a[i-1].fi ;
            c.pb(a[i].se) ;
            sumC+=a[i].fi ;
          }
      }
    cout<< b.size() << endl ;
    for(int i=0 ; i<b.size() ; i++)
      cout<< b[i] << " " ;
    cout<< endl ;
    cout<< c.size() << endl ;
    for(int i=0 ; i<c.size() ; i++)
      cout<< c[i] << " " ;
  }
