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
    long long int T, n, x ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        long long int tot=0, ans, curr=-inf ;
        vi h(n+10), left(n+10, 0), right(n+10, 0), maxHeight(n+10) ;
        for(int i=1 ; i<=n ; i++)
          {
            cin>> h[i] ;
            tot+=h[i] ;
          }
        for(int i=1 ; i<=n ; i++)
          if(h[i]>left[i-1]) left[i]=left[i-1]+1 ;
          else left[i]=h[i] ;
        for(int i=n ; i>=1 ; i--)
          if(h[i]>right[i+1]) right[i]=right[i+1]+1 ;
          else right[i]=h[i] ;
        for(int i=1 ; i<=n ; i++)
          maxHeight[i]=min(left[i], right[i]) ;
        for(int i=1 ; i<=n ; i++)
          if(maxHeight[i]>curr)
            curr=maxHeight[i] ;
        ans=tot-(curr*curr) ;
        cout<< ans << endl ;
      }
  }
