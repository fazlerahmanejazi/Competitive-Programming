#include <bits/stdc++.h>
using namespace std ;

int m ;
string s ;
bool dp[12][12][1000] ;
bool possible ;
vector<int> ans ;

void solve(int diff, int last, int step)
  {
    if(possible) return ;
    if(dp[diff][last][step]) return ;
    dp[diff][last][step]=true ;
    if(step==m)
      {
        possible=true ;
        cout<< "YES" << endl ;
        for(int i=0 ; i<ans.size() ; i++)
          cout<< ans[i] << " " ;
        return ;
      }
    for(int i=1 ; i<=10 ; i++)
      if(s[i-1]=='1' && i>diff && i!=last)
        {
          ans.push_back(i) ;
          solve(i-diff, i, step+1) ;
          ans.pop_back() ;
        }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    cin>> s ;
    cin>> m ;
    memset(dp, 0, sizeof dp) ;
    possible=false ;
    solve(0, 0, 0) ;
    if(!possible) cout<< "NO" ;
  }
