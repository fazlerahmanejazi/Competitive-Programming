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
    ios_base::sync_with_stdio (false) ;
    lli n, k, d, c, remain, x ;
    cin>> n >> k ;
    x=n/2 ;
    x=x/(k+1) ;
    remain=x*(k+1) ;
    d=remain/(k+1) ;
    c=remain-d ;
    remain=n-remain ;
    cout<< d << " " << c << " " << remain ;
  }
