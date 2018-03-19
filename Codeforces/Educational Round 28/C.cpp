#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
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
    lli n, d1, d2, d3, tot=0, curr, l, r, sum, L, R, seg[4], best=0 ;
    bool pos=false ;
    cin>> n ;
    vlli a(n+1, 0) ;
    for(int i=1 ; i<=n ; i++)
       cin>> a[i] ;
    d1=d2=d3=0 ;
    for(int i=0 ; i<=n ; i++)
      {
        tot+=a[i] ;
        curr=sum=0 ;
        l=r=i+1 ; L=R=i ;
        for(int j=i+1 ; j<=n ; j++)
          {
            curr+=a[j] ;
            if(curr>sum) sum=curr, R=j, L=l ;
            if(curr<0) curr=0, l=j+1, r=j+1 ;
          }
        seg[0]=tot ; seg[1]=0 ; seg[2]=sum ; seg[3]=0 ;
        for(int j=i+1 ; j<L ; j++) seg[1]+=a[j] ;
        for(int j=R+1 ; j<=n ; j++) seg[3]+=a[j] ;
        if(seg[0]-seg[1]+seg[2]-seg[3]>best)
          {
            best=seg[0]-seg[1]+seg[2]-seg[3] ;
            d1=i ;
            d2=max(L-1, 0LL) ;
            d3=R ;
          }
      }
    cout<< d1 << " " << d2 << " " << d3 ;
  }
