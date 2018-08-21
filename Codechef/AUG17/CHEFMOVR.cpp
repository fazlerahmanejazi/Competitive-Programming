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
    int T ;
    cin>> T ;
    while(T--)
      {
        lli n, d, ans=0, x, y, sum=0 ;
        cin>> n >> d ;
        vlli a(n) ;
        for(int i=0 ; i<n ; i++)
          {
            cin>> a[i] ;
            sum+=a[i] ;
          }
        if(sum%n) cout<< -1 << endl ;
        else
          {
            x=sum/n ;
            for(int i=0 ; i+d<n ; i++)
              {
                y=a[i]-x ;
                a[i+d]+=y ;
                a[i]-=y ;
                ans+=abs(y) ;
              }
            for(int i=0 ; i<n ; i++)
              if(a[i]!=x)
                ans=-1 ;
            cout<< ans << endl ;
          }
      }
  }
