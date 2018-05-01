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
        int n, x, y, d, m, bestD=inf, bestM=-inf, ans=-1 ;
        cin>> n >> x >> y ;
        for(int i=1 ; i<=n ; i++)
          {
            cin>> d >> m ;
            if(d<=x && m>=y)
              {
                if(d<bestD)
                  {
                    ans=i ;
                    bestD=d ;
                    bestM=m ;
                  }
                else if(d==bestD && m>bestM)
                  {
                    ans=i ;
                    bestD=d ;
                    bestM=m ;
                  }
              }
          }
        cout<< ans << endl ;
      }
  }
