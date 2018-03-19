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
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, d, l, r, m, x ;
    long long int ways=0, curr, y;
    cin>> n >> d ;
    vi a(n) ;
    for(int i=0 ; i<n ; i++)
      cin>> a[i] ;
    for(int i=2 ; i<n ; i++)
      {
        curr=0 ;
        l=0 ; r=i-2 ;
        while(l<=r)
          {
            m=(l+r)/2 ;
            x=a[i]-a[m] ;
            if(x<=d)
              {
                y=i-m ;
                y=(y*(y-1))/2 ;
                if(curr<y) curr=y ;
                r=m-1 ;
              }
            else l=m+1 ;
          }
        ways+=curr ;
      }
    cout<< ways ;
  }
