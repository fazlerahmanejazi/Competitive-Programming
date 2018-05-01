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

lli root(lli x)
  {
    lli l=0, r=1e9+1, m ;
    while(l<r-1)
      {
        m=(l+r)/2 ;
        if(m*m>x) r=m ;
        else l=m ;
      }
    return l ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli T ;
    cin>> T ;
    while(T--)
      {
        lli n, m, L=0, r ;
        cin>> n ;
        L=m=root(n) ;
        lli cnt[L+10] ;
        memset(cnt, 0, sizeof cnt) ;
        cnt[m]+=m ;
        r=n-m*m ;
        for(int i=L ; i>=1 ; i--) cnt[i]+=r/i, r-=i*(r/i) ;
        for(int i=1 ; i<=L ; i++)
          {
            cout<< 'X' ;
            for(int j=1 ; j<=cnt[i] ; j++)  cout<< 'D' ;
          }
        cout<< endl ;
      }
  }
