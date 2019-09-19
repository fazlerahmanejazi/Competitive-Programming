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

bool present(set<int> &x, int y)
  {
    return x.find(y)!=x.end() ;
  }


int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        int n, m, u, v, ansSize ;
        cin>> n >> m ;
        ansSize=n ;
        n*=3 ;
        vpii edges ;
        vi indSet, matching ;
        set<int> endpoints ;
        for(int i=1 ; i<=m ; i++)
          {
            cin>> u >> v ;
            if(present(endpoints, u) || present(endpoints, v)) continue ;
            matching.pb(i) ;
            endpoints.insert(u) ;
            endpoints.insert(v) ;
          }
        for(int i=1 ; i<=n ; i++) if(!present(endpoints, i)) indSet.pb(i) ;
        if(matching.size()>indSet.size())
          {
            cout<< "Matching" << endl ;
            for(int i=0 ; i<ansSize ; i++) cout<< matching[i] << " " ;
          }
        else
          {
            cout<< "IndSet" << endl ;
            for(int i=0 ; i<ansSize ; i++) cout<< indSet[i] << " " ;
          }
        cout<< endl ;
      }
  }
