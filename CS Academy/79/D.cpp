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

int n, k, q, c, r, x, ans ;
bool check ;
vb rep(100005, 0) ;
map<int, set<int>> G ;
set<int> temp ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> k >> q ;
    for(int i=1 ; i<=k ; i++)
      {
        cin>> c >> r ;
        G[r].insert(r) ;
        rep[r]=true ;
        for(int j=1 ; j<=c-1 ; j++)
          {
            cin>> x ;
            G[r].insert(x) ;
          }
      }
    for(int i=1 ; i<=q ; i++)
      {
        temp.clear() ;
        cin>> c ;
        for(int j=1 ; j<=c ; j++)
          {
            cin>> x ;
            temp.insert(x) ;
          }
        ans=0 ;
        for(auto i:temp)
          if(rep[i])
            {
              check=true ;
              for(auto j:G[i])
                if(temp.find(j)==temp.end())
                  {
                    check=false ;
                    break ;
                  }
              if(check) ans++ ;
            }
        cout<< ans << endl ;
      }
  }
