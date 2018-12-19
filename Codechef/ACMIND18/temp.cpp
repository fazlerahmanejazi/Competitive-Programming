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
string s, r ;
vb taken ;
bool globalDone ;
set<string> temp ;
vector<string> words, curr, ans ;

void check(vector<string> &prev)
  {
    vector<string> curr ;
    for(int i=prev.size()-1 ; i>=0 ; i--) curr.pb(prev[i]) ;
    while(curr.size()<4) curr.pb("####") ;
    bool all=true ;
    for(int i=0 ; i<n ; i++)
      if(!taken[i])
        {
          bool now=false ;
          for(int k=0 ; k<4 ; k++)
            {
              bool pos=true ;
              for(int j=0 ; j<4 ; j++) if(words[i][j]!=curr[j][0] && curr[j][0]!='#') pos=false ;
              if(pos)
                {
                  for(int j=0 ; j<4 ; j++) curr[j][0]=words[i][j] ;
                  now=true ;
                  break ;
                }
            }
          if(!now) all=false ;
        }
    if(all && !globalDone)
      {
        ans=curr ;
        for(int i=0 ; i<4 ; i++)
          for(int j=0 ; j<4 ; j++)
            if(ans[i][j]=='#')
              ans[i][j]='a' ;
        globalDone=true ;
      }
  }

void solve(int idx)
  {
    if(idx>4) return ;
    if(globalDone) return ;
    check(curr) ;
    solve(idx+1) ;
    for(int i=0 ; i<n ; i++)
      if(!taken[i])
        {
          curr.pb(words[i]) ;
          solve(idx+1) ;
          curr.pop_back() ;
        }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        temp.clear() ;
        words.clear() ;
        curr.clear() ;
        ans.clear() ;
        globalDone=false ;
        ans.pb("grid") ;
        ans.pb("snot") ;
        ans.pb("poss") ;
        ans.pb("ible") ;
        cin>> n ;
        for(int i=0 ; i<n ; i++)
          {
            cin>> s ;
            r=s ;
            reverse(all(r)) ;
            if(temp.find(s)==temp.end() && temp.find(r)==temp.end())
              {
                if(s<r) temp.insert(s) ;
                else temp.insert(r) ;
              }
          }
        reverse(all(words)) ;
        for(auto i:temp) words.pb(i) ;
        n=words.size() ;
        taken.assign(words.size(), false) ;
        solve(0) ;
        for(int i=0 ; i<4 ; i++)
          {
            for(int j=0 ; j<4 ; j++) cout<< ans[i][j] ;
            cout<< endl ;
          }
        cout<< endl ;
      }
  }
