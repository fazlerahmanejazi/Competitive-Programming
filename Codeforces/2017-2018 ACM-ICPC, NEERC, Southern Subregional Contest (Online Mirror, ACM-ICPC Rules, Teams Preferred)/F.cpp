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

int n, ans ;
string x ;
set<string> user ;
map<string, bool> taken ;

void dfs(string s, int idx)
  {
    if(s.length()>20) return ;
    if(taken[s]) return ;
    taken[s]=true ;
    int l=s.length() ;
    string r="" ;
    for(int i=0 ; i<idx ; i++) r+=s[i] ;
    for(int i=idx ; i<l ; i++)
      {
        if(s[i]=='u')
          {
            string x=r ;
            x+="oo" ;
            for(int j=i+1 ; j<l ; j++) x+=s[j] ;
            dfs(x, i) ;
          }
        else if(s[i]=='h')
          {
            string x=r ;
            x+="kh" ;
            for(int j=i+1 ; j<l ; j++) x+=s[j] ;
            dfs(x, i) ;
          }
        else if(i+1<l && s[i]=='o' && s[i+1]=='o')
          {
            string x=r ;
            x+="u" ;
            for(int j=i+2 ; j<l ; j++) x+=s[j] ;
            dfs(x, i) ;
          }
        else if(i+1<l && s[i]=='k' && s[i+1]=='h')
          {
            string x=r ;
            x+="h" ;
            for(int j=i+2 ; j<l ; j++) x+=s[j] ;
            dfs(x, i) ;
          }
        r+=s[i] ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        user.insert(x) ;
      }
    ans=0 ;
    for(auto x:user)
      if(!taken[x])
        {
          ans++ ;
          dfs(x, 0) ;
        }
    cout<< ans ;
  }
