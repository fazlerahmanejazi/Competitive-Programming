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

int n ;
int days[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
            31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
            31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
            31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
            31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
            31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
            31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
            31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} ;
vi a(24) ;

bool check(int s)
  {
    for(int i=0 ; i<n ; i++)
      if(a[i]!=days[s+i])
        return false ;
    return true ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=0 ; i<n ; i++) cin>> a[i] ;
    for(int i=0 ; i+n<12*8 ; i++)
      if(check(i))
        {
          cout<< "YES" ;
          return 0 ;
        }
    cout<< "NO" ;
  }
