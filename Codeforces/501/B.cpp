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

int n, x, idx ;
string s, r ;
vi ans ;

void perform(int l, int r)
  {
    for(int i=r ; i>l ; i--) ans.pb(i), swap(s[i-1], s[i]) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> s >> r ;
    for(int i=0 ; i<n ; i++)
      if(s[i]!=r[i])
        {
          idx=-1 ;
          for(int j=i ; j<n ; j++)
            if(s[j]==r[i])
              {
                idx=j ;
                break ;
              }
          if(idx==-1) return cout<< -1, 0 ;
          perform(i, idx) ;
        }
    cout<< ans.size() << endl ;
    for(auto i:ans) cout<< i << " " ;
  }
