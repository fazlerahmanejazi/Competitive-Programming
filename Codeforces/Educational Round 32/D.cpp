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
    lli n, k, x, y, curr, ans=0, d[]={1, 0, 1, 2, 9} ;
    cin>> n >> k ;
    for(int i=0 ; i<=k ; i++)
      {
        curr=1 ;
        x=i ; y=n ;
        while(x--) curr*=y, y-- ;
        x=i ; y=1 ;
        while(x--) curr/=y, y++ ;
        curr*=d[i] ;
        ans+=curr ;
      }
    cout<< ans ;
  }
