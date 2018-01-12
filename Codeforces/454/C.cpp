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

int n, cnt, ans ;
bool check ;
string s ;
char c ;
set<char> letter ;

void update2()
  {
    set<char> temp ;
    char x ;
    for(int i=0 ; i<s.length() ; i++)
      {
        x=s[i] ;
        if(letter.find(x)!=letter.end()) temp.insert(x) ;
      }
    letter=temp ;
  }

void update1()
  {
    char x ;
    for(int i=0 ; i<s.length() ; i++)
      {
        x=s[i] ;
        letter.erase(x) ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    for(int i=0 ; i<26 ; i++) letter.insert((char)(i+'a')) ;
    cin>> n ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> c >> s ;
        if(c=='.') update1() ;
        else if(c=='!' && !check) update2() ;
        else if(c=='?' && !check) letter.erase(s[0]) ;
        else if(check) ans++ ;
        if(letter.size()==1) check=true ;
      }
    cout<< ans ;
  }
