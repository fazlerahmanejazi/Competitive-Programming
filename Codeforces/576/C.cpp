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
    lli n, I, l, r, m, distinct, K, N, curr, res, ans=INF, cnt ;
    cin>> n >> I ;
    I*=8 ;
    vlli a(n), greater(n, 0), smaller(n, 0), idx(n, 0) ;
    for(int i=0 ; i<n ; i++) cin>> a[i] ;
    sort(all(a)) ;
    cnt=1 ;
    for(int i=1 ; i<n ; i++)
      if(a[i-1]<a[i]) smaller[i]=smaller[i-1]+cnt, cnt=1 ;
      else smaller[i]=smaller[i-1], cnt++ ;
    cnt=1 ;
    for(int i=n-2 ; i>=0 ; i--)
      if(a[i+1]>a[i]) greater[i]=greater[i+1]+cnt, cnt=1 ;
      else greater[i]=greater[i+1], cnt++ ;
    idx[0]=1 ;
    for(int i=1 ; i<n ; i++)
      {
        idx[i]=idx[i-1] ;
        if(a[i]>a[i-1]) idx[i]++ ;
      }
    for(int i=0 ; i<n ; i++)
      {
        l=i ; r=n-1 ;
        res=i ;
        while(l<=r)
          {
            m=(l+r)/2 ;
            distinct=idx[m]-idx[i]+1 ;
            K=ceil(1.0*log2(distinct*1.0)) ;
            //N=smaller[i]+greater[m] ;
            curr=n*K ;
            if(curr<=I)
              l=m+1, res=m ;
            else r=m-1 ;
          }
        if(smaller[i]+greater[res]<ans)
          ans=smaller[i]+greater[res] ;
      }
    cout<< ans ;
  }
