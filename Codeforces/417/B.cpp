#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000009
#define endl '\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int n, m, last=-1 ;
int l[20], r[20] ;
bool check[20] ;
long long int ans=INF, curr, x, y ;

void solve(long long int curr, int idx, int pos)
  {
    if(idx==last)
      {
        if(pos==1)
          {
            x=abs(r[idx]-pos)+curr ;
            ans=min(x, ans) ;
            return ;
          }
        else
          {
            y=abs(l[idx]-pos)+curr ;
            ans=min(y, ans) ;
            return ;
          }
      }
    if(!l[idx] && !r[idx]) solve(curr+1, idx+1, pos) ;
    if(pos==1)
      {
        x=abs(2*(r[idx]-pos))+curr+1 ;
        solve(x, idx+1, 1) ;
        y=m+1+curr+1 ;
        solve(y, idx+1, m+2) ;
      }
    else if(pos==m+2)
      {
        x=abs(2*(l[idx]-pos))+curr+1 ;
        solve(x, idx+1, m+2) ;
        y=m+1+curr+1 ;
        solve(y, idx+1, 1) ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    string s ;
    memset(check, false, sizeof check) ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> s ;
        s='*'+s ;
        l[n-i+1]=0 ;
        r[n-i+1]=0 ;
        for(int j=1 ; j<=m+2 ; j++)
          if(s[j]=='1')
            {
              l[n-i+1]=j ;
              last=max(n-i+1, last) ;
              break ;
            }
        for(int j=m+2 ; j>=1 ; j--)
          if(s[j]=='1')
            {
              r[n-i+1]=j ;
              break ;
            }
      }
    if(last!=-1)
      {
        solve(0, 1, 1) ;
        cout<< ans ;
      }
    else cout<< 0 ;
  }
