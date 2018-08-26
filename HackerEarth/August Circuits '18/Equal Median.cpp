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
    int T ;
    cin>> T ;
    while(T--)
      {
        int n, ans=0, cntbp=0, cntbg=0, cntag=0, cntap=0 ;
        cin>> n ;
        vi a(n), b(n), c(2*n) ;
        for(int i=0 ; i<n ; i++) cin>> a[i], c[i]=a[i] ;
        for(int i=0 ; i<n ; i++) cin>> b[i], c[i+n]=b[i] ;
        sort(all(c)) ;
        if(c[n]==c[n-1])
          {
            for(int i=0 ; i<n ; i++)
              {
              if(a[i]<c[n]) cntap++ ;
              if(a[i]>c[n]) cntag++ ;
              if(b[i]>c[n]) cntbg++ ;
              if(b[i]<c[n]) cntbp++ ;
              }
            ans=max(ans, cntap-n/2) ;
            ans=max(ans, cntbp-n/2) ;
            ans=max(ans, cntbg-n/2) ;
            ans=max(ans, cntag-n/2) ;
            cout<< ans << endl ;
          }
        else cout<< -1 << endl ;
      }
  }
