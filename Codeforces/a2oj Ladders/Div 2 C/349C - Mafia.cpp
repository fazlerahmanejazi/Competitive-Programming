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
    int n ;
    long long int x, ans, sum=0 ;
    cin>> n ;
    vi a(n) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> a[i] ;
        sum+=a[i] ;
      }
    sort(all(a)) ;
    /*ans=a[n-1] ;
    while(1)
      {
        x=ans*(n)-sum ;
        if(x>=ans)
          {
            cout<< ans ;
            return 0 ;
          }
        ans++ ;
      }*/
    x=ceil((double)sum/(n-1)) ;
    cout<< max(x, (long long int)a[n-1]) ;
  }
