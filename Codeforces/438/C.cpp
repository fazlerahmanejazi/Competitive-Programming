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
    int n, k, c ;
    bool pos ;
    cin>> n >> k ;
    set<vi> data ;
    vi taken(5, 0) ;
    for(int i=0 ; i<n ; i++)
      {
        for(int j=0 ; j<k ; j++) cin>> taken[j] ;
        data.insert(taken) ;
      }
    pos=true ;
    for(auto x:data) for(int i=0 ; i<k ; i++) if(x[i]) pos=false ;
    if(pos)
      {
        cout<< "YES" ;
        return 0 ;
      }
    for(auto x:data)
      for(auto y:data)
        if(x!=y)
          {
            pos=true ;
            for(int i=0 ; i<k ; i++) if(x[i]+y[i]>1) pos=false ;
            if(pos)
              {
                cout<< "YES" ;
                return 0 ;
              }
          }
    cout<< "NO" ;
  }
