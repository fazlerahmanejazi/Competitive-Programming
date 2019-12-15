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

map<int, int> cnt ;
set<int> found ;
int n ;

void solve(int x)
  {
    cout<< x << " " ;
    cnt[x]++ ;
    if(x==1) return ;
    if(x%2) solve(x-1) ;
    else solve(x/2) ;
  }


void count(int x)
    {
      if(x>n) return ;
      if(found.find(x)!=found.end()) return ;
      else found.insert(x) ;
      if(x%2) count(2*x) ;
      else count(2*x), count(x+1) ;
    }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    /*for(int i=1 ; i<=n ; i++)
      {
        cout<< i << "--" ;
        solve(i) ;
        cout<< endl ;
      }
    map<int, int> cnt2 ;
    for(auto i:cnt) if(i.fi%2) cout<< i.fi << " " << i.se << endl ;
    cout<< endl ;
    for(auto i:cnt) if(i.fi%2==0) cout<< i.fi << " " << i.se << endl ;
    cout<< endl ;
    for(auto i:cnt) cout<< i.fi << " " << i.se << endl ;*/
    for(int i=1 ; i<=n ; i++)
      {
        found.clear() ;
        count(i) ;
        cout<< found.size() << " " ;
      }
  }
