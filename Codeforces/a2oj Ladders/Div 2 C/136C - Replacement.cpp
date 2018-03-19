#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000009
#define endl '\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n ;
    cin>> n ;
    vi a(n) ;
    for(int i=0 ; i<n ; i++)
      cin>> a[i] ;
    sort(a.begin(), a.end()) ;
    if(a[n-1]==1) a[n-1]=2 ;
    else a.insert(a.begin(), 1) ;
    for(int i=0 ; i<n ; i++)
      cout<< a[i] << " " ;
  }
