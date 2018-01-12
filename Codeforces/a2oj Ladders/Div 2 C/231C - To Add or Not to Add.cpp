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
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, k, ans=1, pos, y, val ;
    long long x, l, r, m ;
    cin>> n >> k ;
    vi a(n+1) ;
    vlli sum(n+1, 0) ;
    for(int i=1 ; i<=n ; i++)
      cin>> a[i] ;
    sort(a.begin()+1, a.end()) ;
    val=a[1] ;
    for(int i=1 ; i<=n ; i++)
      sum[i]+=sum[i-1]+a[i] ;
    for(int i=2 ; i<=n ; i++)
      {
        pos=lower_bound(a.begin()+1, a.end(), a[i]-k)-a.begin() ;
        y=i-pos ;
        l=0, r=y ;
        while(l<=r)
          {
            m=(l+r)/2 ;
            x=sum[i-1]-sum[i-m-1] ;
            x=a[i]*m-x ;
            if(x<=k)
              {
                if(m+1>ans)
                  {
                    ans=m+1 ;
                    val=a[i] ;
                  }
                l=m+1 ;
              }
            else r=m-1 ;
          }
      }
    cout<< ans << " " << val ;
  }
