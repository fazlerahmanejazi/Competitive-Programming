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

int ans ;
string s ;

bool check(string s)
  {
    for(int i=1 ; i<s.length() ; i++) if(s[i]==s[i-1]) return false ;
    return true ;
  }

void brute(int idx, string s)
  {
    if(idx==s.length())
      {
        if(check(s)) ans++ ;
        return ;
      }
    if(s[idx]=='c')
      for(int i=0 ; i<26 ; i++)
        {
          s[idx]=i+'a' ;
          brute(idx+1, s) ;
        }
    else
      for(int i=0 ; i<10 ; i++)
        {
          s[idx]=i+'0' ;
          brute(idx+1, s) ;
        }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> s ;
    brute(0, s) ;
    cout<< ans ;
  }
