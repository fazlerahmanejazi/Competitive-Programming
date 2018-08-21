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
    lli n, x1, x2, x ;
    vpii data ;
    cin>> n >> x1 >> x2 ;
    for(int i=1 ; i<=n ; i++) cin>> x, data.pb(mp(x, i)) ;
    sort(all(data)) ;
    reverse(all(data)) ;
    for(int i=0 ; i<n ; i++)
      if(data[i].fi*(i+1)>=x1)
        {
          for(int j=i+1 ; j<n ; j++)
            if(data[j].fi*(j-i)>=x2)
              {
                cout<< "Yes" << endl ;
                cout<< i+1 << " " << j-i << endl ;
                for(int k=0 ; k<=i ; k++) cout<< data[k].se << " " ;
                cout<< endl ;
                for(int k=i+1 ; k<=j ; k++) cout<< data[k].se << " " ;
                return 0 ;
              }
          break ;
        }
    for(int i=0 ; i<n ; i++)
      if(data[i].fi*(i+1)>=x2)
        {
          for(int j=i+1 ; j<n ; j++)
            if(data[j].fi*(j-i)>=x1)
              {
                cout<< "Yes" << endl ;
                cout<< j-i << " " << i+1 << endl ;
                for(int k=i+1 ; k<=j ; k++) cout<< data[k].se << " " ;
                cout<< endl ;
                for(int k=0 ; k<=i ; k++) cout<< data[k].se << " " ;
                return 0 ;
              }
          break ;
        }
    cout<< "No" ;
  }
