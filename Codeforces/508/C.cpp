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
    lli n, x, y, t=0, ans[2] ;
    ans[0]=ans[1]=0 ;
    cin>> n ;
    priority_queue<lli> p[2] ;
    for(int i=0 ; i<n ; i++) cin>> x, p[0].push(x) ;
    for(int i=0 ; i<n ; i++) cin>> x, p[1].push(x) ;
    n*=2 ;
    while(n--)
      {
        if(!p[t].empty() && !p[1-t].empty())
          {
            x=p[t].top() ; p[t].pop() ;
            y=p[1-t].top() ; p[1-t].pop() ;
            if(x>=y) ans[t]+=x, p[1-t].push(y) ;
            else p[t].push(x) ;
          }
        else if(!p[t].empty())
          {
            x=p[t].top() ; p[t].pop() ;
            ans[t]+=x ;
          }
        else p[1-t].pop() ;
        t=1-t ;
      }
    cout<< ans[0]-ans[1] ;
  }
