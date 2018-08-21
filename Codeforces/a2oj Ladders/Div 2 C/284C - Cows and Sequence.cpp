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
    int n, t, x, s, e, m=1 ;
    vi d ;
    e=0 ;
    double avg=0 ;
    cin>> n ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> t ;
        if(t==1)
          {
            cin>> s >> x ;
            if(s==m) e+=x ;
            else d[s-1]-=x ;
            avg=avg+(double)(s*x)/m ;
          }
        else if(t==2)
          {
            cin>> x ;
            d.pb(x-e) ;
            e=x ;
            m++ ;
            avg=(double)(avg*(m-1)+(double)x)/m ;
          }
        else if(t==3)
          {
            x=e ;
            e=e-d[m-2] ;
            m-- ;
            d.pop_back() ;
            avg=(double)(avg*(m+1)-(double)x)/m ;
          }
        cout<< fixed << setprecision(12) << avg << endl ;
      }
  }
