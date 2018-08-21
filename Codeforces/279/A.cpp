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
    int n, x, l ;
    map<int, vi> cnt ;
    cin>> n ;
    for(int i=0 ; i<n ; i++) cin>> x, cnt[x-1].pb(i+1) ;
    l=min({cnt[0].size(), cnt[1].size(), cnt[2].size()}) ;
    cout<< l << endl ;
    for(int i=0 ; i<l ; i++) cout<< cnt[0][i] << " " << cnt[1][i] << " " << cnt[2][i] << endl ;
  }
