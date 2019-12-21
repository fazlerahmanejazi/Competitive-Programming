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
    lli n, curr=0 ;
    cin>> n ;
    if(n<=3) return cout<< "NO", 0 ;
    cout<< "YES" << endl ;
    if(n%2)
      {
        cout<< 5 << " - " << 3 << " = " << 2 << endl ;
        cout<< 1 << " + " << 2 << " = " << 3 << endl ;
        cout<< 3 << " * " << 2 << " = " << 6 << endl ;
        cout<< 4 << " * " << 6 << " = " << 24 << endl ;
        for(int i=6 ; i<=n ; i+=2)
          {
            cout<< i+1 << " - " << i << " = " << 1 << endl ;
            cout<< 24 << " * " << 1 << " = " << 24 << endl ;
          }
      }
    else
      {
        cout<< 1 << " * " << 2 << " = " << 2 << endl ;
        cout<< 2 << " * " << 3 << " = " << 6 << endl ;
        cout<< 6 << " * " << 4 << " = " << 24 << endl ;
        for(int i=5 ; i<=n ; i+=2)
          {
            cout<< i+1 << " - " << i << " = " << 1 << endl ;
            cout<< 24 << " * " << 1 << " = " << 24 << endl ;
          }
      }
  }
