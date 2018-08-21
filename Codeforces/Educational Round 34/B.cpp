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

int h1, h2, a1, a2, c ;
vector<string> ans ;

int solve()
  {
    int cnt=1 ;
    while(1)
      {
        if(h2-a1<=0)
          {
            ans.pb("STRIKE") ;
            return cnt ;
          }
        else if(h1-a2<=0)
          {
            ans.pb("HEAL") ;
            h1+=c ;
            h1-=a2 ;
          }
        else
          {
            ans.pb("STRIKE") ;
            h2-=a1 ;
            h1-=a2 ;
          }
        cnt++ ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> h1 >> a1 >> c >> h2 >> a2 ;
    cout<< solve() << endl ;
    for(int i=0 ; i<ans.size() ; i++) cout<< ans[i] << endl ;
  }
