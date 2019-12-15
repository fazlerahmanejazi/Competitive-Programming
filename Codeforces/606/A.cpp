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
    vlli temp, years ;
    for(lli i=1 ; i<=inf ; i=i*10+1) years.pb(i), temp.pb(i) ;
    for(lli i=2 ; i<=9 ; i++) for(auto j:temp) years.pb(j*i) ;
    sort(all(years)) ;
    lli t, n ;
    cin>> t ;
    while(t--)
      {
        cin>> n ;
        cout<< upper_bound(all(years), n)-years.begin() << endl ;
      }
  }
