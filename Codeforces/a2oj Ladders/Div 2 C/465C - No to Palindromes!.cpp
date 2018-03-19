#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define mod 1000000007
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

string s, ans ;
int n, k ;

int check(string s)
  {
    for(int i=0 ; i<n ; i++)
      if(i+2<n && s[i]==s[i+2]) return i+2 ;
      else if(i+1<n && s[i]==s[i+1]) return i+1 ;
    return -1 ;
  }

string next(string s)
  {
    for(int i=n-1 ; i>=0 ; i--)
      {
        while(s[i]-'a'+1<k)
          {
            s[i]=s[i]+1 ;
            for(int j=i+1 ; j<n ; j++)
              s[j]='a' ;
            int x=check(s) ;
            if(x==-1)
              return s ;
            i=x ;
          }
      }
    return "" ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> k ;
    cin>> s ;
    ans=next(s) ;
    if(ans!="") cout<< ans ;
    else cout<< "NO" ;
  }
