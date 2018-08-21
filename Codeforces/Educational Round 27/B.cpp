#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
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
    string s ;
    cin>> s ;
    sort(s.begin(), s.begin()+3) ;
    sort(s.begin()+3, s.end()) ;
    int l=(s[0]-'0')+(s[1]-'0')+(s[2]-'0') ;
    int r=(s[3]-'0')+(s[4]-'0')+(s[5]-'0') ;
    int a, b, c, x, y, z ;
    a=s[0]-'0' ; b=s[1]-'0' ; c=s[2]-'0' ;
    x=(s[3]-'0'); y=(s[4]-'0') ; z=(s[5]-'0') ;
    if(l==r)
      {
        cout<< 0 ;
        return 0 ;
      }
    if(r>l)
      {
        if(9+b+c>=x+y+z || a+b+c>=x+y)
          {
            cout<< 1 ;
            return 0 ;
          }
        else if(9+9+c>=x+y+z || a+b+c>=x || 9+b+c>=x+y)
          {
            cout<< 2 ;
            return 0 ;
          }
        else
          {
            cout<< 3 ;
            return 0 ;
          }
      }
    else
      {
        if(9+y+z>=a+b+c || x+y+z>=a+b)
          {
            cout<< 1 ;
            return 0 ;
          }
        else if(9+9+z>=a+b+c || x+y+z>=a || 9+y+z>=a+b)
          {
            cout<< 2 ;
            return 0 ;
          }
        else
          {
            cout<< 3 ;
            return 0 ;
          }
      }
  }
