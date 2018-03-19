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
    int n, q, t, p, v, maxM=-1, type ;
    cin>> n >> q ;
    vi firstQuery(n, 0), secondQuery(n, 0), time(n), price(n) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> t ;
        time[i]=t ;
      }
    for(int i=0 ; i<n ; i++)
      {
        cin>> p ;
        price[i]=p ;
      }
    for(int i=0 ; i<n ; i++)
      {
        maxM=max(maxM, price[i]) ;
        firstQuery[i]=maxM ;
      }
    maxM=-1 ;
    for(int i=n-1 ; i>=0 ; i--)
      {
        maxM=max(maxM, price[i]) ;
        secondQuery[i]=maxM ;
      }
    while(q--)
      {
        cin>> type >> v ;
        if(type==1)
          {
            t=lower_bound(all(firstQuery), v)-firstQuery.begin() ;
            if(t<n) cout<< time[t] << endl ;
            else cout<< -1 << endl ;
          }
        else
          {
            t=lower_bound(all(time), v)-time.begin() ;
            if(t<n) cout<< secondQuery[t] << endl ;
            else cout<< -1 << endl ;
          }
      }
  }
