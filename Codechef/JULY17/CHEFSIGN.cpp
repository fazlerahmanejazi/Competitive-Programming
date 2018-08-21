#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod (lli)1000000007
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
    int T, ans, curr, maxm ;
    string s ;
    cin>> T ;
    while(T--)
      {
        cin>> s ;
        maxm=-1 ;
        ans=0 ;
        curr=0 ;
        for(int i=0 ; i<s.length() ; i++)
          if(s[i]=='<')
            {
              curr++ ;
              maxm=max(curr, maxm) ;
            }
          else if(s[i]=='>')
            curr=0 ;
        ans=max(maxm, ans) ;
        maxm=-1 ;
        curr=0 ;
        for(int i=0 ; i<s.length() ; i++)
          if(s[i]=='>')
            {
              curr++ ;
              maxm=max(curr, maxm) ;
            }
          else if(s[i]=='<')
            curr=0 ;
        ans=max(ans, maxm) ;
        cout<< ans+1 << endl ;
      }
  }
