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

int n, operationsCnt ;
vpii operations[20] ;

void solve(int op, int l, int r)
  {
    if(l==r) return ;
    if(op>0) solve(op-1, l, (l+r)/2), solve(op-1, (l+r)/2+1, r) ;
    operations[op].pb({l, r}) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    solve(9, 1, n) ;
    for(int i=0 ; i<10 ; i++) if(!operations[i].empty()) operationsCnt++ ;
    cout<< operationsCnt << endl ;
    for(int i=0 ; i<10 ; i++)
      if(!operations[i].empty())
        {
          cout<< operations[i].size() << endl ;
          for(auto j:operations[i]) cout<< j.fi << " " << j.se << endl ;
        }
  }
