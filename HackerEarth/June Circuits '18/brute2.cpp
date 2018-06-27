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

int n, k ;
vi temp ;

map<int, int> cnt ;

int get()
  {
    int res=1, prev=temp[1] ;
    for(int i=2 ; i<=n ; i++)
      if(temp[i]>=prev)
        {
          prev=temp[i] ;
          res++ ;
        }
    return res ;
  }

void solve(int idx)
  {
    if(idx>n)
      {
        cnt[get()]++ ;
        return ;
      }
    for(int i=1 ; i<=k ; i++)
      {
        temp[idx]=i ;
        solve(idx+1) ;
      }
  }


int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> k ;
    temp.resize(n+1) ;
    solve(1) ;
    for(auto i:cnt) cout<< i.se << " " ;
  }
